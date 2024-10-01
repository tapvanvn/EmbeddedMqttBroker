#include"AckConnectMqttMessage.h"

AckConnectMqttMessage::AckConnectMqttMessage(uint8_t ackFlags, uint8_t connectReturnCode):MqttMessage(CONNECTACK,RESERVERTO0){
    this->ackFlags = ackFlags;
    this->connectReturnCode = connectReturnCode;
}

std::string AckConnectMqttMessage::buildMqttPacket(){
    std::string ackPacket;
    
    ackPacket.append(1,(char)getTypeAndFlags());
    ackPacket.append(1,(char)2);
    ackPacket.append(1,(char)ackFlags);
    ackPacket.append(1,(char)connectReturnCode);
    
    return ackPacket;
}