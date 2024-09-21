// agv_robot_info_main.cpp
#include <ros/ros.h>
#include "agv_robot_info_class.cpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;

    AGVRobotInfo agv_robot_info(nh);

    agv_robot_info.setRobotDescription("Mir100");
    agv_robot_info.setSerialNumber("567A359");
    agv_robot_info.setIPAddress("169.254.5.180");
    agv_robot_info.setFirmwareVersion("3.5.8");
    agv_robot_info.setMaximumPayload(100);  // 100 Kg

    ros::Rate loop_rate(1);  // 1 Hz loop rate

    while (ros::ok()) {
        agv_robot_info.publish_data();

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
