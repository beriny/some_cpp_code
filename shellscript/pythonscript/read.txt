#!/usr/bin/env python
#    -*-coding: utf-8-*-     
#    File Name: read.py
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Sun 23 Aug 2015 09:38:04 PM CST

import sys, os

def catfile(filename):
    fhandle = open(filename, 'r')
    for line in fhandle:
        print line,

def main():
    argv = sys.argv[1:]
    for filename in argv:
        if os.path.exists(filename):
            #print filename
            catfile(filename)
        else:
            print "%s isn't exist" % filename


if __name__ == "__main__":
    main()
