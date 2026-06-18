# dds-aircon-controller

Temperature Sensor → CAN Frame → DDS Controller → Fan Speed Command

Controller subscribes to cabin temperature data that is received from a simulated CAN gateway. It then determines the appropriate fan speed based on chosen temperature thresholds and publishes fan control commands back to the CAN network.

There is a separate test node which simulates temperature changes to validate controller behaviour.
