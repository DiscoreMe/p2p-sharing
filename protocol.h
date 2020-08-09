namespace protocol {

struct Message {
	short int type;
	int msg_size;
	char* msg;
};

Message MsgUnPack(char* msg);
int MsgPack(int type, char* msg, char* out);

}; // protocol