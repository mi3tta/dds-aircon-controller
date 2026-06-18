#include <iostream>
#include "aircon_controller_test.hpp"

AirconControllerTestNode::AirconControllerTestNode() : SRNode("aircon_controller_test_node") {
    current_frame.id(0x304);
    current_frame.data().resize(64);
    current_frame.data()[0] = 17;
    current_temp_pub_ = this->create_publisher<SRCANFrame>("/gateway/from/can_0");

    this->create_timer(std::chrono::milliseconds(1000), [this](){publish_temp_data();});
}

AirconControllerTestNode::~AirconControllerTestNode() {}

void AirconControllerTestNode::publish_temp_data()
{
    std::cout << "current " << static_cast<int>(current_frame.data()[0]) << std::endl;

    current_temp_pub_.publish(current_frame);

    if (current_frame.data()[0] < 24) {
        current_frame.data()[0] += 1;
    } else {
        std::cout << " test temps reached, stop test" << std::endl;
    }
}