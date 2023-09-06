#include <ros/ros.h>
#include <std_msgs/String.h>
#include <qq_msgs/Carry.h>

int main(int argc, char  *argv[])
{
    ros::init(argc, argv,"chao_node");
    printf("here is ros\n");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<qq_msgs::Carry>("kaihei",10);

    ros::Rate loop_rate(2);
    while (ros::ok())
    {
        qq_msgs::Carry msg;
        msg.grade = "青铜";
        msg.star = 999;
        msg.data = "国驸马朝2";
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}
