# UDP Client–Server Communication in C (Linux)

## Overview

This project demonstrates a basic implementation of **UDP (User Datagram Protocol) communication** using **C programming on Linux**. It includes a simple **UDP server** and **UDP client** that communicate using socket APIs.

UDP is a **connectionless transport protocol** that sends data as independent packets called **datagrams**. Unlike TCP, it does not guarantee delivery, ordering, or retransmission, making it suitable for **low-latency and real-time communication**.

This project helps understand how UDP communication works at the **application and transport layer using Linux socket APIs**.

---

## Objectives

* Understand UDP communication using sockets
* Implement UDP client and server in C
* Learn how datagrams are sent and received
* Observe UDP packet flow using Linux tools
* Gain hands-on experience with Linux networking APIs

---

## Project Structure

```
udp_practice/
│
├── server.c      → UDP server implementation
├── client.c      → UDP client implementation
└── README.md     → Project documentation
```

---

## System Requirements

* Linux OS (Ubuntu recommended)
* GCC Compiler
* Terminal access
* Basic knowledge of C programming

Optional tools for packet monitoring:

* tcpdump
* Wireshark

---

## UDP Communication Model

```
UDP Client  ---- Datagram ---->  UDP Server
UDP Client  <--- Response -----  UDP Server
```

The client sends a message to the server using a UDP socket, and the server receives the message and sends a response back to the client.

---

## Server Implementation

The UDP server performs the following steps:

1. Create a UDP socket using `socket()`
2. Configure the server address structure
3. Bind the socket to a specific port using `bind()`
4. Wait for incoming messages using `recvfrom()`
5. Print the received message
6. Send a reply to the client using `sendto()`
7. Close the socket

The server listens on **port 9000** and waits for messages from clients.

---

## Client Implementation

The UDP client performs the following steps:

1. Create a UDP socket using `socket()`
2. Configure the server IP address and port
3. Send a message to the server using `sendto()`
4. Wait for the server's response using `recvfrom()`
5. Display the received response
6. Close the socket

The client sends the message **"Hello Server"** to the server.

---

## Important Socket APIs Used

| Function   | Description                           |
| ---------- | ------------------------------------- |
| socket()   | Creates a communication endpoint      |
| bind()     | Assigns a port to the server socket   |
| sendto()   | Sends a UDP datagram to a destination |
| recvfrom() | Receives a UDP datagram               |
| close()    | Closes the socket                     |

---

## Compilation

Compile the server and client programs using GCC.

```
gcc server.c -o server
gcc client.c -o client
```

---

## Running the Program

### Step 1: Start the Server

Open a terminal and run:

```
./server
```

Expected output:

```
Socket created successfully
Server listening on port 9000...
```

---

### Step 2: Run the Client

Open another terminal and run:

```
./client
```

Expected output:

```
Client socket created
Message sent to server
Server reply: Hello Client
```

---

### Server Output

```
Client message: Hello Server
```

This confirms successful UDP communication.

---

## Observing UDP Packets (Optional)

You can observe UDP packets using **tcpdump**.

```
sudo tcpdump -i lo udp port 9000
```

Then run the client again to see the UDP packets captured on the loopback interface.

---

## UDP Packet Flow (Internal Working)

When the client sends a message:

```
Application (Client)
        ↓
sendto() system call
        ↓
UDP Layer
        ↓
IP Layer
        ↓
Network Interface
        ↓
UDP Server
```

On the receiving side:

```
Network Interface
        ↓
IP Layer
        ↓
UDP Layer
        ↓
recvfrom()
        ↓
Application (Server)
```

---

## Key Learning Outcomes

After completing this project, you should understand:

* UDP communication basics
* Connectionless communication model
* Linux socket programming
* Datagram transmission and reception
* Practical debugging using network tools

---

## Possible Enhancements

Future improvements for this project:

* Multi-client UDP server
* Non-blocking sockets using `select()` or `poll()`
* Implement reliable UDP using sequence numbers
* Packet monitoring using Wireshark
* Simulate real-time protocols like RTP over UDP

---

## Conclusion

This project demonstrates a simple yet practical implementation of **UDP communication using C on Linux**. It provides a foundational understanding of **datagram-based networking** and Linux socket programming, which are essential for developing networked applications in embedded and distributed systems.
