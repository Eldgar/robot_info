// agv_robot_info_class.cpp
#include "robot_info_class.cpp"
#include "hydraulic_system_monitor.cpp"

class AGVRobotInfo : public RobotInfo {
public:

    AGVRobotInfo(ros::NodeHandle& nh) : RobotInfo(nh), maximum_payload_(0) {}

    void setMaximumPayload(float payload) {
        maximum_payload_ = payload;
    }

    HydraulicSystemMonitor& getHydraulicSystemMonitor() {
        return hydraulic_system_monitor_;
    }

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields msg;
        msg.data_field_01 = "robot_description: " + robot_description_;
        msg.data_field_02 = "serial_number: " + serial_number_;
        msg.data_field_03 = "ip_address: " + ip_address_;
        msg.data_field_04 = "firmware_version: " + firmware_version_;
         msg.data_field_05 = "maximum_payload: " + std::to_string(static_cast<int>(maximum_payload_)) + " Kg";
        msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_system_monitor_.getHydraulicOilTemperature();
        msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_system_monitor_.getHydraulicOilTankFillLevel();
        msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_system_monitor_.getHydraulicOilPressure();
        info_pub_.publish(msg);
    }

private:
    float maximum_payload_;
    HydraulicSystemMonitor hydraulic_system_monitor_;
};
