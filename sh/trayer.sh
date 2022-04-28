#!/bin/bash
killall trayer
if [ $? != 0 ];
then
    trayer --edge right --align center --SetDockType true --SetPartialStrut true --expand true --transparent true --width 14
fi
