#include "ros/ros.h"
#include "multyply_pkg/multiply.h"
#include <string>
int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<multyply_pkg::multiply>("multiply");

    multyply_pkg::multiply srv;

    srv.request.a = std::stod(argv[1]);
    srv.request.b = std::stod(argv[2]);
    if (client.call(srv))
    {
        ROS_INFO("multiply: %f", srv.response.c);
    }
    else
    {
        ROS_ERROR("Failed to call service multiply");
        return 1;
    }
    
    return 0;
}
