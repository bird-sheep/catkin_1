#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>

ros::Publisher pub;
int count = 0;
void lidar_info(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    float dist = msg->ranges[180];
    ROS_INFO("前方的距离为: [%f]", dist);

    if(count>0)
        {count--;
        return ;}
    else{

    geometry_msgs::Twist twist;
    if(dist < 1.5)
    {
        count = 20;
        twist.angular.z = 0.5;
    }
    else
        twist.linear.x = 0.1;
    
    pub.publish(twist);
    }

}
int main(int argc, char  *argv[])
{

    setlocale(LC_ALL, "");
    ros::init(argc, argv,"lidar_node");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/scan", 10, lidar_info);
    pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::spin();
    return 0;
}
