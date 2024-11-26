#!/bin/bash

while true; do
    echo "Process Control:"
    echo "1) List top 5 processes by CPU usage"
    echo "2) List top 5 processes by memory usage"
    echo "3) Show process tree"
    echo "4) Show process name by PID"
    echo "5) Show process PID(s) by name"
    echo "6) Kill process by PID"
    echo "7) Kill process by name"
    echo "q) Exit"
    echo -n "Choice: "
    read -r choice

    case $choice in
        1)
            echo "Top 5 processes by CPU usage:"
            ps aux --sort=-%cpu | head -n 6
            echo
            ;;
        2)
            echo "Top 5 processes by memory usage:"
            ps aux --sort=-%mem | head -n 6
            echo
            ;;
        3)
            echo "Process tree:"
            pstree -p
            echo
            ;;
        4)
            echo -n "Enter PID: "
            read -r pid
            if ps -p "$pid" > /dev/null 2>&1; then
                echo "Process name: $(ps -p "$pid" -o comm=)"
            else
                echo "Invalid PID or process not found."
            fi
            echo
            ;;
        5)
            echo -n "Enter process name: "
            read -r name
            pids=$(pgrep "$name")
            if [ -n "$pids" ]; then
                echo "Process PID(s): $pids"
            else
                echo "No processes found with name: $name"
            fi
            echo
            ;;
        6)
            echo -n "Enter PID to kill: "
            read -r pid
            if kill "$pid" > /dev/null 2>&1; then
                echo "Process $pid killed successfully."
            else
                echo "Failed to kill process $pid. Check permissions or PID validity."
            fi
            echo
            ;;
        7)
            echo -n "Enter process name to kill: "
            read -r name
            if pkill "$name" > /dev/null 2>&1; then
                echo "Processes with name '$name' killed successfully."
            else
                echo "Failed to kill processes with name '$name'. Check permissions or name validity."
            fi
            echo
            ;;
        q)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid choice. Please try again."
            echo
            ;;
    esac
done
