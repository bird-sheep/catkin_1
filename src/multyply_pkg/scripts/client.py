#!/usr/bin/env python3
import sys
import rospy
from multyply_pkg.srv import *

def usage():
    return "%s [x y]"%sys.argv[0]

def client_func(x, y):
    rospy.wait_for_service('multiply')
    try:
        times = rospy.ServiceProxy('multiply', multiply)
        resp = times(x, y)
        return resp.c
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
    
if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
    else:
        print(usage())
        sys.exit(1)
    
    print("Requesting %s*%s"%(x, y))
    print("%s * %s = %s"%(x, y, client_func(x, y)))