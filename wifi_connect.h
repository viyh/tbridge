#ifndef wifi_connect_h
#define wifi_connect_h

#include <config.h>
#include <WiFi.h>
#include "log.h"
#include <SSD1306Wire.h>
#include "KeyInWifi/KeyInWifi.hpp"
// #include "ESPmDNS.h"

extern void ConnectToWiFi(SSD1306Wire& display);
// void start_mdns_service();

#endif
