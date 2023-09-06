#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist



def laser_info(msg):
    global pub , cnt
    rospy.loginfo("前方距离为:{}".format(msg.ranges[180]))
    if cnt > 0:
        cnt -= 1
        return
    twist = Twist()
    
    if msg.ranges[180] < 1.5:
        twist.angular.z = 1.0
        cnt = 50
    else:
        twist.linear.x = 2

    pub.publish(twist)

if __name__ == '__main__':
    rospy.init_node('laser_scan')
    cnt = 50
    sub = rospy.Subscriber('/scan', LaserScan, laser_info)
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    
    rospy.spin()
    