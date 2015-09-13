#!/bin/bash

read m
if [ $m -lt 100 ] ; then
    ans=0
elif [ $m -le 5000 ] ; then
    ans=$((m / 100))
elif [ $m -le 30000 ] ; then
    ans=$((m / 1000 + 50))
elif [ $m -le 70000 ] ; then
    ans=$(((m / 1000 - 30) / 5 + 80))
else
    ans=89
fi
printf "%02d\n" $ans
