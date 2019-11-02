#include "wifi_connect.h"

// void start_mdns_service() {
//     //initialize mDNS service
//     if (MDNS.begin(DEVICE_NAME)) {
//         console_log("wifi - mDNS success, hostname set to: " + (String)DEVICE_NAME);
//     } else {
//         console_log("wifi - mDNS hostname not set!");
//         return;
//     }
// }

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
    console_log("wifi - MAC address: " + WiFi.macAddress());
    // start_mdns_service();
}
