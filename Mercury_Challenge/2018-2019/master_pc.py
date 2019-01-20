import socket #Import Socket Library
import ipaddress
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#Create a socket instance with two parameters, IPv4 and UDP protocol

robot_ip = ipaddress.ip_address(input("Enter Ip adress"))
robot_port = input("Enter Port")

#connecting to the server
sock.connect((robot_ip,robot_port))

message = "Hello World"
sock.send(message)


sock.close()


