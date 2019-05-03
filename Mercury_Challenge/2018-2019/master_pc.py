#pip3 install keyboard
import socket #Import Socket Library
import ipaddress #https://docs.python.org/3/library/ipaddress.html
import keyboard
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#Create a socket instance with two parameters, IPv4 and UDP protocol
ip = raw_input("Enter Ip adress")
print(ip)
robot_ip = ipaddress.ip_address(unicode(ip))
robot_port = input("Enter Port")

#connecting to the server
sock.connect((robot_ip,robot_port))


#TODO send when key release

if keyboard.is_pressed('w'):
    message = "119"
    sock.send(message)
    
if keyboard.is_pressed('a'):
    message = "97"
    sock.send(message)
    
if keyboard.is_pressed('s'):
    message = "116"
    sock.send(message)
    
if keyboard.is_pressed('d'):
    message = "100"
    sock.send(message)






sock.close()


