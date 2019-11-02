#include <SSD1306Wire.h>
#include "tilt/tiltHydrometer.h"
#include "tilt/tiltScanner.h"
#include "wifi_connect.h"
#include "aws.h"
#include "log.h"
#include "config.h"

uint16_t loopCount = 0;

// init OLED
SSD1306Wire display(OLED_ADDRESS, OLED_SDA, OLED_SCL);

// convert json to simple String object
// String to_string(const json &j) {
//     if (j.type() == json::value_t::string) {
//         return String(j.get<std::string>().c_str());
//     }
//     return j.dump().c_str();
// }

void display_string(int x, int y, String msg) {
    display.drawString(x, y, msg);
    display.display();
}

void progress_bar(int start, int end) {
    for(uint8_t i = start; i<=end; i++) {
        display.drawProgressBar(0, 0, 127, 10, i);
        display.display();
        delay(10);
    }
}

void setup() {
    Serial.begin(115200);
    console_log("init - serial begin");

    console_log("init - set pinmode");
    pinMode(LED, OUTPUT);
    pinMode(OLED_RST, OUTPUT);

    console_log("init - display init");
    digitalWrite(OLED_RST, 1);
    display.init();
    // display.flipScreenVertically();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.clear();
    progress_bar(0, 10);

    console_log("init - connect to wifi");
    display_string(63, 40, "Connecting to wifi...");
    ConnectToWiFi(display);
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    progress_bar(10, 20);

    display.clear();
    progress_bar(20, 30);
    console_log("init - set clock to NTP");
    display_string(63, 40, "Setting time to NTP...");
    set_clock();
    progress_bar(30, 40);

    console_log("init - connect to AWS");
    display.clear();
    progress_bar(40, 50);
    display_string(63, 40, "Connecting to AWS...");
    aws_iot.ConnectToAWS();
    progress_bar(50, 60);

    // Initialize the BLE scanner
    console_log("init - tilt_scanner");
    display.clear();
    progress_bar(60, 70);
    display_string(63, 40, "Initializing tilt scanner...");
    tilt_scanner.init();
    progress_bar(70, 80);

    console_log("init - init complete");
    display.clear();
    progress_bar(80, 90);
    display_string(63, 40, "Initialization complete.");
    display_string(63, 58, "\nWaiting for Tilt data...");
    progress_bar(90, 100);

    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
}

void main_display(tiltHydrometer *tilt) {
    display.clear();
    display_string(0, 0, "Tilt: " + (String)tilt->color_name().c_str());
    display_string(0, 20, "SG: " + (String)tilt->converted_gravity().c_str());
    display_string(0, 40, "Temp: " + (String)tilt->temp);
    display_string(118, 16, ".");
}

void loop() {
    int tilt_count = 0;

    console_log((String)"loop - start [" + loopCount + "] - free heap: " + (String)(ESP.getFreeHeap() / 1024) + " kB");
    display_string(120, 16, ".");

    tilt_scanner.scan();
    tilt_scanner.wait_until_scan_complete();

    for(uint8_t i = 0;i<TILT_COLORS;i++) {
        if(tilt_scanner.tilt(i)->is_loaded()) {
            tiltHydrometer *tilt = tilt_scanner.tilt(i);
            console_log("loop - tilt found: " + (String)tilt->color_name().c_str());
            main_display(tilt);
            display_string(122, 16, ".");
            aws_iot.sendToAWS(tilt);
            delay(10000);
            tilt_count++;
        }
    }

    aws_iot.client.loop();
    loopCount++;
}
