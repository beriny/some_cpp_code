#!/bin/python
#    -*-coding: utf-8-*-     
#    File Name: test.py
#       Author: huangjinqiang
#        Email: ligelaige@gmail.com
# Created Time: Wed 24 Sep 2014 01:33:03 PM CST

import datetime
#start = datetime.datetime.now().strftime('%c')

import sys, socket

def GetHostByAddr(ip):
    try:
        result = socket.gethostbyaddr(ip)
        print 'Primary hostname:'
        print " %s" % result[0]

        print '\nAddresses:'
        for item in result[2]:
            print " %s" % item
    except socket.herror, e:
        print "Could't look up name:", e

def main():
    argv = sys.argv[1:]
    for arg in argv:
        GetHostByAddr(str(arg))

if __name__ == '__main__':
    main()
