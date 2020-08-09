#include "protocol.h"
#include <string>

protocol::Message protocol::MsgUnPack(char* msg) {
	protocol::Message message{};
	
	message.type = msg[0];
	message.msg_size = msg[1];
	
	char* out = new char[msg[1]];

	for (int i = 0; i < msg[1]; i++) {
		out[i] = msg[i + 2];
	}

	out[msg[1]] = '\0';

	message.msg = out;

	return message;
}

int protocol::MsgPack(int type, char* msg, char* out) {
	int len = strlen(msg);

	out[0] = type;
	out[1] = len;

	for (int i = 0; i < len; i++) {
		out[i+2] = msg[i];
	}

	out[len + 2] = '\0';
	return 0;
}

