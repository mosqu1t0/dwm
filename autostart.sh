#!/bin/bash

#

/home/mosquito/Software/dwm/sh/dwm_status.sh

# app autostart
feh --bg-fill /home/mosquito/Pictures/wall_secondary.png
picom &
redshift -l 25.28:110.30 &

# java 支持
wmname LG3D
fcitx5 &


# app autostart
alacritty --hold -e signIn &
electron-qq &

