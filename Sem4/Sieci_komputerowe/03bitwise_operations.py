addr =  "255.255.255.255/4"
addr = addr.split('/')

ip = addr[0]
mask = int(addr[1])

ip = ip.split('.')

ip = (int(ip[0]) << 24) | (int(ip[1]) << 16) | (int(ip[2]) << 8) | (int(ip[3]))

# print("{0:b}".format(ip))
print(format(ip, '032b'))

first = (ip >> 24)
second = (ip >> 16) & 0xFF
third = (ip >> 8) & 0xFF
last = (ip & 0xFF)
print(first, second, third, last)

ip_mask = int(mask * "1" + (32 - mask) * "0" , 2)

print("{0:b}".format(ip_mask))

