#include <iostream>
#include "aircon_controller.hpp"

// my aircon controller
// want it to take in (so subscribe) a desire temperature, and a current temperature

//check sr_int8 correct I found it in core/dds_types/std_types
//however cat shelter node example used this SRInt32

AirconControllerNode::AirconControllerNode() : SRNode("aircon_controller_node") {
    this->create_subscriber<SRCANFrame>("/gateway/from/can_0", [this](SRCANFrame frame){receive_cabin_temp_frame(frame);});
    fan_speed_ = this->create_publisher<SRCANFrame>("/gateway/to/can_0");
}

AirconControllerNode::~AirconControllerNode() {}


void AirconControllerNode::receive_cabin_temp_frame(SRCANFrame frame) {
    if (frame.id() != 0x304)
        return;
    if (frame.data().empty())
        return;

    int8_t raw_temp = static_cast<int8_t>(frame.data()[0]);
    current_temp_ = static_cast<float>(raw_temp);

    if (current_temp_ < 20.0f) {
        fan_state_ = off;
    } else if (current_temp_ < 25.0f) {
        fan_state_ = medium;
    } else {
        fan_state_ = full;
    }

    publish_fan_speed();
}    


void AirconControllerNode::publish_fan_speed()
{
    fan_speeder_.data(static_cast<uint8_t>(fan_state_));
    std::cout << "Publishing fan speed to can " << static_cast<int>(fan_speeder_.data()) << "%" << std::endl;
    
    fan_speed_.publish(fan_speeder_);
}