#include <iostream>
#include <cstdlib>
#include <getopt.h>
#include "mainapp.hpp"
#include "server.hpp"

using namespace std;



int main(int argc, char *argv[])
{
	Server myServer;			
	mainApp myApp;

	myApp.parse_args(argc, argv);
	myApp.print_arguments(argc, argv);

	return 0;
}

