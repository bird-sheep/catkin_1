#!/usr/bin/env python3
#coding=utf8

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist


if __name__ == '__main__':
    rospy.init_node('yao_node')
    rospy.loginfo('yao_node started')

    pub = rospy.Publisher("cmd_vel",Twist,queue_size=10)
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        msg = Twist()
        msg.linear.x = 1
        msg.angular.z =3.14
        
        pub.publish(msg)
        rate.sleep()
    