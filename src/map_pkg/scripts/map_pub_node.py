#!/usr/bin/env python3
#coding=utf8
import rospy
from nav_msgs.msg import OccupancyGrid


if __name__ == '__main__':
    rospy.init_node('map_pub_node')

    pub = rospy.Publisher("/map",OccupancyGrid,queue_size=10)
    rate = rospy.Rate(1)
    
    msg = OccupancyGrid()
    msg.header.frame_id = "map"
    msg.header.stamp = rospy.Time.now()
    msg.info.origin.position.x = 2
    msg.info.origin.position.y = 1
    msg.info.resolution = .5
    msg.info.width = 4
    msg.info.height = 2

    msg.data = [100,100,100,-1,0,0,0,0]
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()