#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "tf/tf.h"
#include "geometry_msgs/Twist.h"

ros::Publisher vel_pub;

void imu_callback(const sensor_msgs::Imu msg)
{
    if(msg.orientation_covariance[0] == -1)
        return;
    tf::Quaternion quaternion(
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w
    );
    double roll, pitch, yaw;
    tf::Matrix3x3(quaternion).getRPY(roll, pitch, yaw);
    roll = roll * 180 / M_PI;
    pitch = pitch * 180 / M_PI;
    yaw = yaw * 180 / M_PI;
    ROS_INFO("roll:%f, pitch:%f, yaw:%f", roll, pitch, yaw);

    double target_yao = 90;
    double diff = target_yao - yaw;
    geometry_msgs::Twist vel_cmd;
    vel_cmd.angular.z = diff *0.01;
    vel_pub.publish(vel_cmd);   
    
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "imu_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/imu/data", 1000, imu_callback);
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
    ros::spin();
    return 0;
}
