# tbridge
Tilt Hydrometer automation using an TTGO ESP32 OLED microcontroller to submit metrics to AWS IoT, CloudWatch, and Grafana

* Tilt to tbridge
* tbdrige to AWS IoT
* IoT to CloudWatch
* CloudWatch to Grafana

## ESP32 Dev Setup
* Get USB-UART driver from Silicon Labs:
    - https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers
* Setup IDE. For Sublime Text 3:
    - install Deviot and platformio
    - install AWS_IOT
    - install ESP8266_SSD1306
    - install MQTT
* Setup dev config:
- platformio.ini
    [env:esp32dev]
    platform = espressif32
    board = esp32dev
    framework = arduino
    monitor_speed = 115200
    upload_speed = 921600
    build_flags = -D_GLIBCXX_USE_C99

    board_upload.maximum_size = 4194304
    board_build.partitions = no_ota.csv

    [platformio]
    src_dir = /Users/joe/Seafile/Code/arduino/TTGO OLED Test
* Setup partition table:
- ~/.platformio/no_ota.csv:

    # Name,   Type, SubType, Offset,  Size, Flags
    # Note: if you have increased the bootloader size, make sure to update the offsets to avoid overlap
    nvs,      data, nvs,     ,        0x6000,
    phy_init, data, phy,     ,        0x1000,
    factory,  app,  factory, ,        4M,

## tbridge Setup

* Buy ESP32:
    - https://www.aliexpress.com/item/32822105291.html
    - https://smile.amazon.com/LORA32-Display-Bluetooth-Development-Antenna/dp/B07C5GV243
* Create AWS Account and deploy lambda-iot.yaml CloudFormation Stack
* Add thing and put name, endpoint, key, and certificate into config_aws_certs.h
* Set wifi password in config_wifi_password.h
* Compile and apply firmware
