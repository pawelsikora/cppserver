#include <string.h>

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

			while ((c = getopt_long(argc,argv, "hp:r:c:l:d:", long_options, NULL)) != -1)
				switch(c)
				{
					case 'h':
						cout << "HELP!" << endl;
						//system("clear");
						//print_info(argv[0]);
						//exit(0);
						break;
					case 'r':
						//strcpy(configuration.root, optarg);
						break;
					case 'p':
						//strcpy(configuration.port.name, optarg);
						break;
					case 'c':
						//setChroot = atoi(optarg);
						break;
					case 'l':
						//if(((strcpy(configuration.logfile, optarg)) == NULL))
						//	die("Error alocating memory: LOGFILE", LOG_USER);
						//strcpy(configuration.logfile, optarg);
						break;
					case 'd':
						//configuration.setDaemon.val = atoi(optarg);
						break;
					case '?':
						//fprintf(stderr, "Wrong arguments!\n");
						//exit(EXIT_FAILURE);
					default:
						break;
						//exit(EXIT_FAILURE);
				}
		}


};

