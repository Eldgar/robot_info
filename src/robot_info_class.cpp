// robot_info_class.cpp
#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>  // Updated to use the correct message

class RobotInfo {
public:
    RobotInfo(ros::NodeHandle& nh) : nh_(nh) {
        info_pub_ = nh_.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
    }

    void setRobotDescription(const std::string& description) {
        robot_description_ = description;
    }

    void setSerialNumber(const std::string& serial_number) {
        serial_number_ = serial_number;
    }

    void setIPAddress(const std::string& ip_address) {
        ip_address_ = ip_address;
    }

    void setFirmwareVersion(const std::string& firmware_version) {
        firmware_version_ = firmware_version;
    }


    virtual void publish_data() {
        robotinfo_msgs::RobotInfo10Fields msg;
        msg.data_field_01 = "robot_description: " + robot_description_;
        msg.data_field_02 = "serial_number: " + serial_number_;
        msg.data_field_03 = "ip_address: " + ip_address_;
        msg.data_field_04 = "firmware_version: " + firmware_version_;
        info_pub_.publish(msg);
    }

protected:
    ros::NodeHandle nh_;
    ros::Publisher info_pub_;
    std::string robot_description_;
    std::string serial_number_;
    std::string ip_address_;
    std::string firmware_version_;
};
