
import socket
import time
HOST = socket.gethostbyname(socket.gethostname())
PORT = 8090  # The port used by the server

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print(f"before connection... port is {PORT}, host is {HOST}")
try:
    s.connect((HOST, PORT))
except:
    print("error connection refused try to start the server first")
    exit(1)
print("connection ok")
while True:
    data = input("enter data to send, send 'exit' or ctrl +c to close connection\n")
    s.sendall(bytes(data,"utf-8"))
    if(data=="exit"):
        break
s.close()


