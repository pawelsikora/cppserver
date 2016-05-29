class Server
{
	public:
		int port;
		int ipaddr;
		char root[256];

		Server(){
			port = 2000;
		}

		int Open(){
			return 0;
		}
		

		int Request(int fd){
			return 0;
		}


		void Close(int fd){
		}

};
