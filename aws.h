#ifndef aws_h
#define aws_h

#include <config.h>
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <nlohmann/json.hpp>
#include "log.h"

class AWSIoT {
public:
    explicit AWSIoT();
    WiFiClientSecure net;
    MQTTClient client;
    void ConnectToAWS();
    void sendJsonToAWS(const nlohmann::json tilt_raw_data);
};

extern AWSIoT aws_iot;

//extern void ConnectToAWS();
//extern void sendJsonToAWS(const nlohmann::json tilt_raw_data);

#endif
