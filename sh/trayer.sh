#!/bin/bash
killall trayer
if [ $? != 0 ];
then
    trayer --edge bottom --align right --SetDockType true --SetPartialStrut true --expand true --transparent true --width 6 --height 29
fi
