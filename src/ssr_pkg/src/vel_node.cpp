#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <cmath>

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "vel_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

    geometry_msgs::Twist msg;
    msg.linear.x = 0.5;
    msg.angular.z = - M_PI;
    ros::Rate rater(10);
    while (ros::ok())
    {
    pub.publish(msg);
    rater.sleep();
    }
    
    return 0;
}
