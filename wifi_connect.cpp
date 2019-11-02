#include "wifi_connect.h"

// connect to wifi
void ConnectToWiFi(SSD1306Wire& display) {
    WiFi.begin(wifi_ssid, wifi_password);
    console_log("wifi - connecting to " + (String)wifi_ssid);

    uint8_t i = 0;
    while (WiFi.status() != WL_CONNECTED) {
        console_log(".");
        delay(1000);

        if ((++i % 16) == 0) {
            console_log("wifi - still trying to connect");
            KeyInWifi kiw(display, 0, KeyInWifi::ButtonMode::NORMAL_HIGH);
            console_log("wifi - created kiw");
            kiw.enableDebug(Serial);
            kiw.execute();
        }
    }
    console_log("wifi - IP address: " + WiFi.localIP().toString());
    console_log("wifi - IP address: " + WiFi.macAddress());
}
