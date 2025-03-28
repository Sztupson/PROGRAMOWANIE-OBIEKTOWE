addr =  "192.168.48.0/26"
addr = addr.split('/')

ip = addr[0]
mask = int(addr[1])

ip = ip.split('.')
ip = (int(ip[0]) << 24) | (int(ip[1]) << 16) | (int(ip[2]) << 8) | (int(ip[3]))

ip_mask = int(mask * "1" + (32 - mask) * "0" , 2)

net_ip = ip & ip_mask

not_mask = ~ip_mask & 0xFFFFFFFF

broadcast = net_ip | ~ip_mask & 0xFFFFFFFF

host_1 = net_ip + 1

host_last = broadcast -1

host_number = 2**(32 - mask) - 2

# def print_ip():
    
#     first = (ip >> 24)
#     second = (ip >> 16) & 0xFF
#     third = (ip >> 8) & 0xFF
#     last = (ip & 0xFF)

#     print(f"IP: {first, second, third, last}")
#     print("Binarny IP: {0:b}".format(ip, '032b'))
#     print("Binarny adres maski: {0:b}".format(ip_mask, '032b'))
#     print(f"\nIlość hostów w sieci: {host_number}")
#     print("Adres pierwszego hosta w sieci: ", format(host_1, '032b'))
#     print("Adres ostatniego hosta w sieci: ", format(host_last, '032b'))
#     print("Adres rozgłoszeniowy: ", format(broadcast, '032b'))

# print_ip()

def print_ip():
    first = (ip >> 24)
    second = (ip >> 16) & 0xFF
    third = (ip >> 8) & 0xFF
    last = (ip & 0xFF)
    
    ip_address = f"{first}.{second}.{third}.{last}"
    mask_address = f"{(ip_mask >> 24)}.{(ip_mask >> 16) & 0xFF}.{(ip_mask >> 8) & 0xFF}.{ip_mask & 0xFF}"
    host_1_address = f"{(host_1 >> 24)}.{(host_1 >> 16) & 0xFF}.{(host_1 >> 8) & 0xFF}.{host_1 & 0xFF}"
    host_last_address = f"{(host_last >> 24)}.{(host_last >> 16) & 0xFF}.{(host_last >> 8) & 0xFF}.{host_last & 0xFF}"
    broadcast_address = f"{(broadcast >> 24)}.{(broadcast >> 16) & 0xFF}.{(broadcast >> 8) & 0xFF}.{broadcast & 0xFF}"
    
    print(f"IP: {ip_address}")
    print("Binarny IP: {0:032b}".format(ip))
    print(f"Adres maski: {mask_address}")
    print("Binarny adres maski: {0:032b}".format(ip_mask))
    print(f"\nIlość hostów w sieci: {host_number}")
    print(f"Adres pierwszego hosta w sieci: {host_1_address}")
    print(f"Adres ostatniego hosta w sieci: {host_last_address}")
    print(f"Adres rozgłoszeniowy: {broadcast_address}")

print_ip()