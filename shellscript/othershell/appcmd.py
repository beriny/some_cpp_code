#!/usr/bin/env python
#    -*-coding: utf-8-*-     
#    File Name: appcmd.py
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Sat 05 Sep 2015 09:28:41 PM CST

import sys, os

def parser():
    argv = sys.argv[1:]
    
    filelist = []
    dirlist = []
    if not argv: return []
    if argv[0] == '-f':
        filelist = argv[1:]
    elif argv[0] == '-d':
        dirlist = argv[1:]
    else:
        filelist = argv

    for item in dirlist:
        for filename in os.listdir(item):
            filelist.append(os.path.join(item, filename))

    result = []
    for item in filelist:
        if os.path.isfile(item):
            result.append(item)

    return result

def getcmd(filename):
    if filename[-8:] != '.desktop': return
    for line in open(filename):
        if line[:5] == 'Name=':
            name = line[5:].strip()
            print "[%s] cmd is " % name, 
        elif line[:5] == 'Exec=':
            cmd = line[5:].strip()
            print "[%s]" % cmd
        
    print 

def main():
    filelist = parser()
    for item in filelist:
        #print getcmd(item)
        getcmd(item)

if __name__ == '__main__':
    main()
