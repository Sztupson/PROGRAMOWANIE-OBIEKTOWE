import socket

users = {}  # (ip, port) -> nickname

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(("0.0.0.0", 12345))

print("Serwer nasłuchuje na porcie 12345...")

while True:
    data, addr = server_socket.recvfrom(1024)

    if not data:
        # Rozłączenie klienta
        if addr in users:
            print(f"Rozłączono: {users[addr]}")
            del users[addr]
        continue

    prefix = data[0:1]
    content = data[1:].decode("utf-8")

    if prefix == b"\0":
        # Rejestracja nickname
        users[addr] = content
        print(f"Zarejestrowano {addr} jako {content}")
    elif prefix == b"\1":
        if addr not in users:
            continue  # Nieznany użytkownik – ignoruj

        nickname = users[addr]
        message = f"{nickname}: {content}".encode("utf-8")

        # Rozsyłamy wiadomość do wszystkich klientów, oprócz nadawcy
        for client_addr in users:
            if client_addr != addr:
                server_socket.sendto(message, client_addr)
    else:
        print(f"Odrzucono pakiet od {addr}")
