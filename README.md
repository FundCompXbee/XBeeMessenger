#XBeeMessenger
CSE 20212 Final Project

##Members
Aaron Crawfis
Conrad Bailey
Madeline Kusters
Jorge Diaz-Ortiz

Final project for Fundamentals of Computing II Spring 2016.

This project recreates an internet chatroom circa 1999, using a custom wireless network instead of the internet.

##Wireless
Xbees are used to connect clients to the server, utilizing a simple serial interface.

##Server
A raspberry pi is used as the server. An XBee connects to the pi's serial port and transmits messages to and from the client.

##Client
Another XBee is connected to an arduino, which is connected to the client computer. The client uses a Qt GUI and serial library to communicate with the server.

##Message & Command Protocals

##JSON Messages
