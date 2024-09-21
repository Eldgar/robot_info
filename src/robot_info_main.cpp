// robot_info_main.cpp
#include <ros/ros.h>
#include "robot_info_class.cpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "robot_info_node");
    ros::NodeHandle nh;

    RobotInfo robot_info(nh);

    robot_info.setRobotDescription("Mir100");
    robot_info.setSerialNumber("567A359");
    robot_info.setIPAddress("169.254.5.180");
    robot_info.setFirmwareVersion("3.5.8");

    ros::Rate loop_rate(1);

    while (ros::ok()) {
        robot_info.publish_data();

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
