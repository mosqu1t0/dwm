#!/bin/bash

#/home/mosquito/Software/dwm/sh/trayer.sh &
rx_pre=$(cat /proc/net/dev | grep wlan0 | awk -F' ' '{print $2}'
313759)
tx_pre=$(cat /proc/net/dev | grep wlan0 | awk -F' ' '{print $10}'
313759)
while true
do
    battery=$(acpi -b | cut -d',' -f2 | cut -d' ' -f2)
    battery_st=$(acpi -b | cut -d',' -f1 | cut -d' ' -f3)
    vol=$(amixer get Master | grep 'Front Left:' | cut -d'[' -f2 | cut -d']' -f1)
    mute=$(amixer get Master | grep 'Front Left:' | cut -d']' -f2 | cut -d'[' -f2)
    rx_now=$(cat /proc/net/dev | grep wlan0 | awk -F' ' '{print $2}'
313759)
    tx_now=$(cat /proc/net/dev | grep wlan0 | awk -F' ' '{print $10}'
313759)
  
    if [ "$mute" == "on" ]
        then
            mute="墳"
        else
            mute="婢"
    fi

    if [ "$battery_st" == "Charging" ]
        then
            battery_st=""
        elif [  "$battery_st" == "Discharging" ]
        then
            battery_st="ﮤ" 
        elif [  "$battery_st" == "Full" ]
        then
            battery_st=""
        else 
            battery_st=""
    fi

    rx=`expr $rx_now - $rx_pre`
    rx=`expr $rx / 1000`
    tx=`expr $tx_now - $tx_pre`
    tx=`expr $tx / 1000`
   
    rx_pre="$rx_now"
    tx_pre="$tx_now"

    xsetroot -name " :$rx Kbs 祝:$tx Kbs | $battery_st:$battery | $mute:$vol | $(date +"%A %d.%m %H:%M") "
    sleep 0.5
done &
