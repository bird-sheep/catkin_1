#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char  *argv[])
{
    ros::init(argc, argv,"yao_node");
    printf("yao is here\n");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("daiwo",10);

    ros::Rate loop_rate(2);
    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "dai dai wo";
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}
