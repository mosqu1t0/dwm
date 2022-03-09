#!/bin/bash
killall trayer
if [ $? != 0 ];
then
trayer --edge top --widthtype percent --width 12 --heighttype percent --height 40 --transparent true --alpha 30 --tint 0x002c323b &
fi
