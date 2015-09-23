#!/bin/bash
#    File Name: mywho.sh
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Wed 23 Sep 2015 10:57:34 PM CST

declare -u _RET
declare -l _ret
_ret=$(whoami)
_RET=$_ret
ret=${_RET:0:1}${_ret:1}

echo $ret
