#!/bin/bash
#    File Name: movefile.sh
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Sun 20 Sep 2015 05:42:24 PM CST

workdir="/srv/documents/bakconfig/jiang"
workdir=${1:-$workdir}

cd $workdir
for item in `ls -a`
do
	if [ ${#item} -gt 2 ] && [ ${item:0:1} = '.' ]
	then
		echo mv  $item ${item:1}.
		mv $item ${item:1}.
	fi
done

