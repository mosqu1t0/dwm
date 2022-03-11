#!/bin/bash
killall trayer
if [ $? != 0 ];
then
trayer --edge bottom --widthtype percent --width 10 --align center --heighttype percent --height 40 --transparent true --alpha 30 --iconspacing 10&
fi
