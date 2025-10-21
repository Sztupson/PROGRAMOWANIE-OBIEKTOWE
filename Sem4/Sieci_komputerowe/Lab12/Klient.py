import socket
import select
import sys

SERVER_IP = "127.0.0.1"
SERVER_PORT = 12345
NICKNAME = input("Podaj swój nickname: ")

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_socket.setblocking(False)

client_socket.sendto(b"\0" + NICKNAME.encode("utf-8"), (SERVER_IP, SERVER_PORT))

print("Dołączono do czatu. Wpisz wiadomość lub CTRL+C aby wyjść.")

try:
    while True:
        readable, _, _ = select.select([client_socket, sys.stdin], [], [])

        for r in readable:
            if r == sys.stdin:
                line = input()
                if line.strip() == "":
                    continue
                client_socket.sendto(b"\1" + line.encode("utf-8"), (SERVER_IP, SERVER_PORT))
            elif r == client_socket:
                data, _ = client_socket.recvfrom(1024)
                print(data.decode("utf-8"))
except KeyboardInterrupt:
    print("\nRozłączanie...")
    client_socket.sendto(b"", (SERVER_IP, SERVER_PORT))
    client_socket.close()
