/*
Aircon controller node
Version: V1.0
Date: 18/03/2026
Author: Mietta Paipetis

*/

#pragma once

#include "sr_node.hpp"
#include "std_types.hpp"

class AirconControllerNode : public SRNode {
public:
    AirconControllerNode();
    ~AirconControllerNode() override;
private:
    // state data
    float current_temp_{0.0f};

    //fan state
    static constexpr float off = 0.0f; 
    static constexpr float medium = 50.0f;
    static constexpr float full = 100.0f;
    float fan_state_{0.0};
    SRUint8 fan_speeder_{0};

    // publisher handles
    SRNode::PublisherHandle<SRUint8> fan_speed_{};

    // callback functions
    void receive_cabin_temp_frame(SRCANFrame frame);
    void publish_fan_speed();
};