#!/bin/bash
killall trayer
if [ $? != 0 ];
then
    trayer --edge top --align right --SetDockType true --SetPartialStrut true --expand true --transparent true --width 6 --height 29
fi
