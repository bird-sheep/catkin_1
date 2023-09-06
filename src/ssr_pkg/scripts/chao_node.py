#!/usr/bin/env python
#coding=utf8

import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry

if __name__ == '__main__':
    rospy.init_node('chao_node')
    rospy.loginfo('chao_node started')

    pub = rospy.Publisher("kaihei",Carry,queue_size=10)
    rate = rospy.Rate(2)

    while not rospy.is_shutdown():
        msg = Carry()
        msg.grade = "白银"
        msg.star = 100
        msg.data = "chao is here"
        pub.publish(msg)
        rate.sleep()
    