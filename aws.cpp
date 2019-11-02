#include "aws.h"

AWSIoT aws_iot;

AWSIoT::AWSIoT() {
    net = WiFiClientSecure();
    client = MQTTClient(512);
}

void AWSIoT::ConnectToAWS() {
    // Setup AWS IoT certificates
    net.setCACert(AWS_CERT_CA);
    net.setCertificate(AWS_CERT_CRT);
    net.setPrivateKey(AWS_CERT_PRIVATE);

    // Connect MQTT on the AWS IoT endpoint
    client.begin(AWS_IOT_ENDPOINT, 8883, net);

    //  Connect to AWS IoT enpoint
    int retries = 0;
    console_log("aws - connecting to AWS IoT...");
    while (!client.connect(DEVICE_NAME) && retries < AWS_MAX_RECONNECT_TRIES) {
        console_log(".");
        delay(100);
        retries++;
    }

    // Confirm AWS IoT connection
    if(!client.connected()){
        console_log("aws - timeout");
        return;
    }

    // Client setup successfully
    console_log("aws - connected to AWS IoT");
}

void AWSIoT::sendToAWS(tiltHydrometer* tilt) {
    json payload = json::object { {
        "state", json::object {
            { "reported", tilt->to_json() }
        }
    } };

    // Publish Tilt payload to AWS IoT topic
    console_log("aws - publishing to AWS..." + (String)payload.dump().c_str());
    client.publish(AWS_IOT_TOPIC, (String)payload.dump().c_str());
}
