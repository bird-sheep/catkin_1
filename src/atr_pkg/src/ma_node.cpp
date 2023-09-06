#include <ros/ros.h>
#include <std_msgs/String.h>
#include <qq_msgs/Carry.h>

void chao_callback(const qq_msgs::Carry msg)
{
    ROS_WARN(msg.grade.c_str());
    ROS_WARN("%d 星", msg.star);
    ROS_INFO(msg.data.c_str());
}
void yao_callback(const std_msgs::String msg)
{
    ROS_WARN(msg.data.c_str());
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "ma_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("kaihei", 10,chao_callback);
    ros::Subscriber sub2 = nh.subscribe("daiwo", 10,yao_callback);
    ros::spin();
    // while (ros::ok())
    // { 
    //     ros::spinOnce();
    // }
    return 0;
}
