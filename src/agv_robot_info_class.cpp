#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo {
public:
    AGVRobotInfo(ros::NodeHandle& nh) : RobotInfo(nh), maximum_payload_(0) {}


    void setMaximumPayload(float payload) {
        maximum_payload_ = payload;
    }

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields msg;
        msg.data_field_01 = "robot_description: " + robot_description_;
        msg.data_field_02 = "serial_number: " + serial_number_;
        msg.data_field_03 = "ip_address: " + ip_address_;
        msg.data_field_04 = "firmware_version: " + firmware_version_;
        msg.data_field_05 = "maximum_payload: " + std::to_string(maximum_payload_) + " Kg";
        info_pub_.publish(msg);
    }

private:
    float maximum_payload_;
};

