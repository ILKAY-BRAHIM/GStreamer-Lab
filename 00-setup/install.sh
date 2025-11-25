#!/bin/bash

COLOR_RED="\033[31m"
COLOR_GREEN="\033[32m"
COLOR_YELLOW="\033[33m"
COLOR_BLUE="\033[34m"
COLOR_MAGENTA="\033[35m"
COLOR_CYAN="\033[36m"
COLOR_RESET="\033[0m"

set -e 

echo -e "${COLOR_GREEN}Setting timezone to Africa/Casablanca...${COLOR_RESET}"

ln -fs /usr/share/zoneinfo/Africa/Casablanca /etc/localtime
apt update -y && apt install -y tzdata >/dev/null 2>&1
dpkg-reconfigure -f noninteractive tzdata

echo -e "${COLOR_GREEN}Installing GStreamer...${COLOR_RESET}"

apt update -y 

echo -e "${COLOR_GREEN}Installing GStreamer dependencies...${COLOR_RESET}"

# vist official gstreamer docs https://gstreamer.freedesktop.org/documentation/installing/on-linux.html?gi-language=c
apt-get install libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    libgstreamer-plugins-bad1.0-dev \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav \
    gstreamer1.0-tools \
    gstreamer1.0-x \
    gstreamer1.0-alsa \
    gstreamer1.0-gl \
    gstreamer1.0-gtk3 \
    gstreamer1.0-qt5 \
    gstreamer1.0-pulseaudio -y

echo -e "${COLOR_GREEN}Verifying GStreamer installation...${COLOR_RESET}"

# gst-launch-1.0 videotestsrc ! autovideosink
gst-launch-1.0 --version

echo -e "${COLOR_GREEN}GStreamer installation completed successfully!${COLOR_RESET}"