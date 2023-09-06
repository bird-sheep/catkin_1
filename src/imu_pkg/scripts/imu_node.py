#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion
import math
from geometry_msgs.msg import Twist 


def callback(msg):
    if msg.orientation_covariance[0] <0:
        return
    quatertion = [msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w]
    roll, pitch, yaw = euler_from_quaternion(quatertion)
    roll = math.degrees(roll)
    pitch = math.degrees(pitch)
    yaw = math.degrees(yaw)
    if yaw<0:
        yaw = yaw + 360
    print("roll: %f, pitch: %f, yaw: %f" % (roll, pitch, yaw))

    global vel_pub
    target_yaw = 180
    vel_cmd = Twist() 
    vel_cmd.angular.z = (target_yaw - yaw)/10 
    vel_pub.publish(vel_cmd)

    

if __name__ =='__main__':
    rospy.init_node('imu_node')
    rospy.Subscriber('imu/data', Imu, callback,queue_size=10)
    vel_pub =rospy.Publisher('cmd_vel', Twist, queue_size=10)
    rospy.spin()