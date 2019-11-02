#ifndef aws_h
#define aws_h

#include <config.h>
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <json11/json11.hpp>
#include "tilt/tiltHydrometer.h"
#include "log.h"

using json = json11::Json;

class AWSIoT {
public:
    explicit AWSIoT();
    WiFiClientSecure net;
    MQTTClient client;
    void ConnectToAWS();
    void sendToAWS(tiltHydrometer* tilt);
};

extern AWSIoT aws_iot;

#endif
