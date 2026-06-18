/*
Instantiates the class then calls .spin()
*/
#include "aircon_controller_test.hpp"

int main(int argc, char* argv[]) {
    AirconControllerTestNode node;
    // Spin up the node
    node.spin();
    return 0;
}