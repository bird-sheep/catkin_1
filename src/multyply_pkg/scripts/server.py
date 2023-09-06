#!/usr/bin/env python3
import rospy
from multyply_pkg.srv import multiply,multiplyResponse


def serve_func(req):
    return multiplyResponse(req.a*req.b)
if __name__ == '__main__':
    rospy.init_node('srv_node')
    try:
        multiply_service = rospy.Service('multiply', multiply,serve_func)
        print("ready to multiply two float")
        rospy.spin()
    except rospy.ServiceException as e:
        print("Service call failed: %s" % e)
