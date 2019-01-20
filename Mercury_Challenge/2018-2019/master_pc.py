import socket #Import Socket Library
import ipaddress
import keyboard
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#Create a socket instance with two parameters, IPv4 and UDP protocol

robot_ip = ipaddress.ip_address(input("Enter Ip adress"))
robot_port = input("Enter Port")

#connecting to the server
sock.connect((robot_ip,robot_port))

if keyboard.is_pressed('w'):
    message = "119"
    sock.send(message)



sock.close()


