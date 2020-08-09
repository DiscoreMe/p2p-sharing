#include <iostream>

#include "windows.h"
#include "client.h"
#include "server.h"
#include "protocol.h"

int main() {

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	setlocale(LC_ALL, "Russian");
	

	char msg[60];
	char testmsg[50] = "Hello, world\0";

	std::cout << "\n[input]\n";

	/*int status = protocol::MsgPack(6, testmsg, msg);
	std::cout << "Status " << 6 << "\nMessage: " << testmsg << std::endl;

	std::cout << "\nEncoded msg: " << msg << std::endl;

	std::cout << "\n[output]\n";

	protocol::Message out = protocol::MsgUnPack(msg);
	std::cout << "Status " << out.type << "\nMessage: " << out.msg << std::endl;*/

	std::cout << 0x1 << std::endl;

	exit(0);
	int i;
	std::cout << "Select number [1 - server; 2 - client] :";
	std::cin >> i;
	if (i == 2) {
		status = initClient();
	} 
	else {
		status = initServer();
	}

	system("pause");

	return 0;
}