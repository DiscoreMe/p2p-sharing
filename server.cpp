#include "server.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"Ws2_32.lib")
#include <WinSock2.h>
#include <iostream>

#pragma warning(disable: 4996)

SOCKET connections[100];
int counter = 0;

void ClientHandler(int index) {
    char msg[256];
    while (true) {
        recv(connections[index], msg, sizeof(msg), NULL);
        for (int i = 0; i < counter; i++) {
            if (i == index) {
                continue;
            }
            send(connections[index], msg, sizeof(msg), NULL);
        }
    }
}

int initServer() {
    WSADATA wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        return -1;
    }

    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);

    for (int i = 0; i < 100; i++) {
        SOCKET newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

        if (newConnection == 0) {
            std::cout << "Error connection";
        }
        else {
            std::cout << "Client connected";
            char msg[256] = "Hello. It's my first network program";
            send(newConnection, msg, sizeof(msg), NULL);

            connections[i] = newConnection;
            counter++;
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
        }
    }

    return 0;
}