/*
Instantiates the class then calls spin
*/
#include "aircon_controller.hpp"

int main(int argc, char* argv[]) {
    AirconControllerNode node;
    // Spin up the node
    node.spin();
    return 0;
}