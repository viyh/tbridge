#include "aws.h"

AWSIoT aws_iot;

AWSIoT::AWSIoT() {
    net = WiFiClientSecure();
    client = MQTTClient(512);
}


void AWSIoT::ConnectToAWS() {
    // Configure WiFiClientSecure to use the AWS certificates we generated
    net.setCACert(AWS_CERT_CA);
    net.setCertificate(AWS_CERT_CRT);
    net.setPrivateKey(AWS_CERT_PRIVATE);

    // Connect to the MQTT broker on the AWS endpoint we defined earlier
    client.begin(AWS_IOT_ENDPOINT, 8883, net);

    // Try to connect to AWS and count how many times we retried.
    int retries = 0;
    console_log("MQTT client - connecting to AWS IOT...");

    while (!client.connect(DEVICE_NAME) && retries < AWS_MAX_RECONNECT_TRIES) {
        console_log(".");
        delay(100);
        retries++;
    }

    // Make sure that we did indeed successfully connect to the MQTT broker
    // If not we just end the function and wait for the next loop.
    if(!client.connected()){
        console_log("MQTT client - timeout");
        return;
    }

    // If we land here, we have successfully connected to AWS!
    // And we can subscribe to topics and send messages.
    console_log("MQTT client - connected to AWS IoT");
}

void AWSIoT::sendJsonToAWS(const nlohmann::json tilt_raw_data) {
    nlohmann::json payload;
    payload["state"]["reported"]["temp_f"] = tilt_raw_data["temp"];
    payload["state"]["reported"]["sg"] = tilt_raw_data["gravity"];
    payload["state"]["reported"]["name"] = tilt_raw_data["color"];

    // Publish the message to AWS
    console_log("MQTT client - publishing to AWS...");
    client.publish(AWS_IOT_TOPIC, payload.dump().c_str());
}
