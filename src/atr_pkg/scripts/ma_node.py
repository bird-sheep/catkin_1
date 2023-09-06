#!/usr/bin/env python3
#coding=utf8

import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry

def callback(data):
    rospy.logwarn(data.grade)
    rospy.logwarn(str(data.star) +"星")
    rospy.loginfo(rospy.get_caller_id() + 'I heard {}'.format(data.data))

def yaocall(data):
    rospy.logwarn(data.data)
if __name__ == '__main__':
    rospy.init_node('ma_node')
    rospy.loginfo('ma_node started')
    
    rospy.Subscriber("kaihei",Carry,callback)
    rospy.Subscriber("daiwo",String,yaocall)
    rospy.spin()