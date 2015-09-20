#!/usr/bin/env python
#    -*-coding: utf-8-*-     
#    File Name: soundcmd.py
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Sun 06 Sep 2015 07:38:19 PM CST

import sys
import math
import time
import os

def parser():
    speed = 10
    base = 30
    length = 20
    
    argv = sys.argv[1:]
    if argv:
        if '-s' in argv:
            speed_s = argv[argv.index('-s') + 1]
            speed = int(speed_s)
        if '-b' in argv:
            base_s =  argv[argv.index('-b') + 1]
            base = int(base_s)
        if '-l' in argv:
            length_s = argv[argv.index('-l') + 1]
            length = int(length_s)

    return speed, base, length

def printline(y, base):
    y = int(y) 
    ya = -base
    yb = base
    
    line = [' '] * (base * 2 + 1)
    line[base] = '|'
    if y < 0:
        for i in range(y-ya, -ya):
            line[i] = '-'
    elif y > 0:
        for i in range(-ya+1, y-ya+1):
            line[i] = '+'
    
    print reduce(lambda a, b: a+b, line)
    num = (y + base) * 50 / base

    return num if num > 50 else 50 + num
    #return num if num > 50 else 50
    #return num


def main(timer, base, length):
    soundcmd = 'amixer -q sset PCM %d%%'
    xa = 0; xb = math.pi * 2 * 2; step = math.pi / length
    x = 0

    while x < xb:
        y = math.sin(x) * base
        num = printline(y, base)
        #os.system(soundcmd % num)
        x += step
        time.sleep(timer)

if __name__ == '__main__':
    
    speed, base, length = parser()
    
    while True:
        main(1.0/speed, base, length)
