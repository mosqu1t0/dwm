#!/bin/bash
killall trayer
if [ $? != 0 ];
then
trayer --edge right --widthtype percent --width 13 --heighttype percent --height 40 --transparent true --alpha 30 --tint 0x002c323b &
fi
