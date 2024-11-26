#!/bin/bash


check_internet() {
    if timeout 1 ping -c 1 8.8.8.8 &>/dev/null; then
        echo "Internet: OK"
    else
        echo "Internet: Not available"
    fi
}

show_info() {
    case "$1" in
        cpu)
            CPU=$(grep -m1 "model name" /proc/cpuinfo | cut -d':' -f2 | sed 's/^ //')
            echo "CPU: $CPU"
            ;;
        memory)
            MEM_TOTAL=$(free -m | awk '/Mem:/ {print $2}')
            MEM_USED=$(free -m | awk '/Mem:/ {print $3}')
            MEM_PERCENT=$(awk "BEGIN {printf \"%.0f\", ($MEM_USED/$MEM_TOTAL)*100}")
            echo "Memory: $MEM_USED / $MEM_TOTAL MiB ($MEM_PERCENT%)"
            ;;
        load)
            LOAD=$(uptime | awk -F'load average:' '{print $2}' | sed 's/^ //')
            echo "Load: $LOAD"
            ;;
        uptime)
            UPTIME=$(uptime -p | sed 's/up //')
            echo "Uptime: $UPTIME"
            ;;
        kernel)
            KERNEL=$(uname -r)
            echo "Kernel: $KERNEL"
            ;;
        gpu)
            GPU=$(lspci | grep -i "vga" | awk -F': ' '{print $2}')
            echo "GPU: $GPU"
            ;;
        user)
            USER=$(whoami)
            echo "User: $USER"
            ;;
        shell)
            SHELL=$(basename "$SHELL")
            echo "Shell: $SHELL"
            ;;
        processes)
            PROCESSES=$(ps -e --no-headers | wc -l)
            echo "Processes: $PROCESSES"
            ;;
        threads)
            THREADS=$(ps -eL --no-headers | wc -l)
            echo "Threads: $THREADS"
            ;;
        ip)
            IPS=$(ip -4 -o addr show | awk '{print $4}' | tr '\n' ' ')
            echo "IP: $IPS"
            ;;
        dns)
            DNS=$(grep "nameserver" /etc/resolv.conf | awk '{print $2}' | tr '\n' ' ')
            echo "DNS: $DNS"
            ;;
        internet)
            check_internet
            ;;
        *)
            echo "Invalid argument: $1"
            return 1
            ;;
    esac
}

if [[ $# -eq 0 ]]; then
    show_info cpu
    show_info memory
    show_info load
    show_info uptime
    show_info kernel
    show_info gpu
    show_info user
    show_info shell
    show_info processes
    show_info threads
    show_info ip
    show_info dns
    check_internet
else
    for arg in "$@"; do
        show_info "$(echo "$arg" | tr '[:upper:]' '[:lower:]')" || exit 1
    done
fi
exit 0