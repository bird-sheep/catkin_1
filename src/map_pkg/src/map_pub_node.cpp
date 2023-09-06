#include "ros/ros.h"
#include "nav_msgs/OccupancyGrid.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "map_pub_node");
    ros::NodeHandle nh;
    ros::Publisher map_pub = nh.advertise<nav_msgs::OccupancyGrid>("/map", 10);
    nav_msgs::OccupancyGrid map_msg;
    map_msg.header.frame_id = "map";
    map_msg.header.stamp = ros::Time::now();
    map_msg.info.origin.position.x = 2;
    map_msg.info.origin.position.y = 1;
    map_msg.info.resolution = 1;
    map_msg.info.width = 4;
    map_msg.info.height = 2;

    map_msg.data.resize(4*2);
    map_msg.data = {100,100,0,-1,0,0,0,0};

    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        map_pub.publish(map_msg);
        loop_rate.sleep();
    }

    return 0;
}
