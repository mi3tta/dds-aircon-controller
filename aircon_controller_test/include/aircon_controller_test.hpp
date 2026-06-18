/*
Aircon controller node
Version: V1.0
Date: 22/03/2026
Author: Mietta Paipetis

*/

#pragma once

#include "sr_node.hpp"
#include "std_types.hpp"

class AirconControllerTestNode : public SRNode {
public:
    AirconControllerTestNode();
    ~AirconControllerTestNode() override;
private:
    SRCANFrame current_frame;

    // publisher handles
    SRNode::PublisherHandle<SRCANFrame> current_temp_pub_{};

    // callback functions
    void publish_temp_data();
};