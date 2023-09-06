#include "ros/ros.h"
#include "multyply_pkg/multiply.h"

bool multiply(multyply_pkg::multiply::Request &req, multyply_pkg::multiply::Response &res)
{
    res.c = req.a *req.b;
    return true; 
}
int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("multiply", multiply);
    ROS_INFO("Ready to multiply");
    ros::spin();
    return 0;
}
