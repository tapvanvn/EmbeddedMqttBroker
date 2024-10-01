#ifndef MQTTTOPIC_H
#define MQTTTOPIC_H

#include <string>
class MqttTocpic
{
private:
    std::string topic;
    uint8_t qos;
    std::string payLoad;

public:
    MqttTocpic(){}
    MqttTocpic(std::string topic, std::string payLoad, uint8_t qos = 0){
        this->topic = topic;
        this->payLoad = payLoad;
        this->qos = qos;
    }

    std::string getTopic(){
        return topic;
    }

    uint16_t getTopicLength(){
        return topic.length();
    }

    std::string getPayLoad(){
        return payLoad;
    }

    void setTopic(std::string topic){
        this->topic = topic;
    }

    void setPayLoad(std::string payLoad){
        this->payLoad = payLoad;
    }

    uint8_t getQos(){
        return qos;
    }
    void setQos(uint8_t qos){
        this->qos = qos;
    }

    bool isTopic(MqttTocpic topic){
        return this->topic.compare(topic.getTopic()) == 0;
    }

    /**
     * @brief Get the Topic Length, This is a String topic length +
     *        String payload length.
     * 
     * 
     * @return uint16_t 
     */
    uint16_t getTopicAndPayloadLength(){
        uint16_t length = topic.length()+payLoad.length();
        return length;
    }

    std::string getTopicAndPayLoad(){
        std::string topicAndPayload;
        topicAndPayload.append(topic);
        topicAndPayload.append(payLoad);
        return topicAndPayload;
    }
};



#endif