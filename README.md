# Minitalk without bonus

## Overview
Minitalk is a simple client-server communication program written in C. The client sends a string to the server using UNIX signals, and the server receives and prints the string. The communication is achieved using only two signals: SIGUSR1 and SIGUSR2. This project demonstrates the use of signal handling and inter-process communication (IPC) in Unix-like systems.

## How to Compile
Run the Makefile to compile both the client and server:
```sh
make all
```
This will generate two executables: client and server.

## Usage
1. Start the server:
   ```sh
   ./server
   ```
   The server will print its Process ID (PID). For example:
   ```sh
   PID: 12345
   ```
2. Run the client in a new terminal tab or window:
   ```sh
   ./client <server_pid> <yuor_message>
   ```
   #### Where:
  - <server_pid> is the PID of the running server.
  - <your_message> is the string you want to send to the server.
    #### For example:
    ```sh
    ./client 12345 "Hello, server!"
    ```
