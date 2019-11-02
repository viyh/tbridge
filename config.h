#ifndef config_h
#define config_h

// Set board specific parmas for TTGO ESP32 OLED
#define OLED_ADDRESS 0x3c
#define OLED_SDA 4
#define OLED_SCL 15
#define OLED_RST 16
#define LED 2

#define BLE_SCAN_TIME 5

// The name of the device. This MUST match up with the name defined in the AWS console
#define DEVICE_NAME "tbridge1"

// The MQTT topic that this device should publish to
#define AWS_IOT_TOPIC "brewing/" DEVICE_NAME

// How many times we should attempt to connect to AWS
#define AWS_MAX_RECONNECT_TRIES 10

#include "config_aws_certs.h"
#include "config_wifi_password.h"

#endif
