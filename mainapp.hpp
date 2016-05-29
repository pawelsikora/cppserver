#include <string.h>
#include <stdlib.h>

using namespace std;


const struct option long_options[] = {
{ "help"	, 0, NULL, 'h' },
{ "rootdir"	, 1, NULL, 'r' },
{ "port"	, 1, NULL, 'p' },
{ "daemon"	, 1, NULL, 'd' },
{ "chroot"	, 1, NULL, 'c' },
{  NULL		, 0, NULL,  0  }
};

class mainApp
{
	
	public:

		int print_arguments(int argc, char **argv)
		{
			for(int i = 1; i < argc; i++)
				cout << argv[i] << endl;
			return 0;
		}
		
		void parse_args(int argc, char **argv){
			char c;

			while ((c = getopt_long(argc,argv, "hdp:r:c:l:", long_options, NULL)) != -1)
				switch(c)
				{
					case 'h':
						system("clear");
						cout << "Here is a place for info page!" << endl;
						exit(1);
						break;
					case 'r':
						cout << "Root directory: " << optarg << endl;
						break;
					case 'p':
						cout << "Number of port: " << optarg << endl;
						break;
					case 'c':
						cout << "Config file:  " << optarg << endl;
						break;
					case 'l':
						cout << "Using logfile! File: " << optarg << endl;
						break;
					case 'd':
						cout << "Creating daemon instance: " << endl;
						break;
					case '?':
					
					default:
						break;
						exit(1);
				}
		}


};

