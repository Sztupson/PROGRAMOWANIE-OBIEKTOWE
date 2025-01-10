#!/bin/bash

while true; 
do
    echo    "Process Control: 
    1) List top 5 processes by CPU usage
    2) List top 5 processes by memory usage 
    3) Show process tree
    4) Show process name by PID
    5) Show process PID(s) by name
    6) Kill process by PID
    7) Kill process by name
    q) Exit"
    echo -n "Choice: "
    read -r Choice

case $Choice in
    "1" ) echo "Top 5 processes by CPU usage: "
                ps aux --sort=-%cpu | head -n 5;;
    "2" ) echo "Top 5 processes by memory usage: "
                ps aux --sort=-%mem | head -n 5;;
    "3" ) echo "Show process tree: "
                pstree;;
    "4" ) echo "Show process name by PID: "
                echo -n "Enter PID: "
                read -r pid
                if ps -p "$pid" > /dev/null 2>&1; then
                    echo "Process name: $(ps -p "$pid" -o comm=)"
                else
                    echo "Invalid PID or process not found."
                fi;;

                #ps -eo pid,comm --sort=pid;; # sortowanie wg PID od najmniejszego do najwiekszego
    "5" ) echo "Show process PIDs by name: "
                echo -n "Enter process name: "
                read -r name
                pids=$(pgrep "$name")
                if [ -n "$pids" ]; then
                    echo "Process PID(s): $pids"
                else
                    echo "No processes found with name: $name"
                fi
                ;;
    "6" ) echo "Kill process by PID: "
                echo -n "Enter PID to kill: "
                read -r pid
                if kill "$pid" > /dev/null 2>&1; then
                echo "Process $pid killed."
                else
                echo "Failed to kill process $pid."
                fi
                ;;
    "7" ) echo -n "Enter process name to kill: "
                read -r name
                if pkill "$name" > /dev/null 2>&1; then
                    echo "Processes with name '$name' killed successfully."
                else
                    echo "Failed to kill processes with name '$name'. Check permissions or name validity."
                fi
                ;;
    "q" ) echo "Leaving"
                break;;
    * ) echo "Wrong input."
esac
done