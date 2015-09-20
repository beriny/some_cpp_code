#!/bin/bash
#    File Name: getx.sh
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Thu 17 Sep 2015 09:08:04 PM CST

workpath="/usr/share/terminator/terminatorlib"
workpath=${1:-$workpath}

keyword="X-terminal-emulator"
keyword=${2:-$keyword}

cd $workpath
for i in `ls $workpath`
do
	ext=`echo $i | cut -d '.' -f2`
	if [ $ext = 'py' ]
	then
		if grep --color=auto  $keyword $i
		then
			echo $i
		fi
	fi
done

echo $workpath
