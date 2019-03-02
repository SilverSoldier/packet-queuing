#include <cstdlib>
#include <string>
#include <iostream>
#include "args.h"

Args args = {8, 10, 0.5, INQ, 3, "output.txt", 10000 };

void parse_args(Args* args, int argc, char* argv[]){
  // Checking number of arguments
  if(argc < 7) {
	// cout << "Wrong number." << endl;
	// cerr << "Usage: " << argv[0] << " -N <> -B <> -p <> -queue NOQ|INQ|KOUQ <> -K <> -out <> -T" << endl;
	// exit(1);
  }
  for(int i = 1; i < argc; i += 2){
	string arg_oi = string(argv[i]);
	if(arg_oi == "-N"){
	  args->N = atoi(argv[i+1]);
	} else if(arg_oi == "-B"){
	  args->B = atoi(argv[i+1]);
	} else if(arg_oi == "-p") {
	  args->p = atoi(argv[i+1]);
	} else if(arg_oi == "-queue") {
	  string queue_arg = string(argv[i+1]);
	  if(queue_arg == "NOQ")
		args->queue = NOQ;
	  else if(queue_arg == "INQ")
		args->queue = INQ;
	  else if(queue_arg == "KOUQ")
		args->queue = KOUQ;
	  else {
		 cerr << "Usage: " << argv[0] << " -N <> -B <> -p <> -queue NOQ|INQ|KOUQ <> -K <> -out <> -T" << endl;
		exit(1);
	  }
	} else if(arg_oi == "-K") {
	  args->K = atoi(argv[i+1]);
	} else if(arg_oi == "-out") {
	  args->outputfile = argv[i+1];
	} else if(arg_oi == "-T") {
	  args->T = atoi(argv[i+1]);
	} else {
	  // cout << "Trouble with: " << arg_oi << endl;
		 cerr << "Usage: " << argv[0] << " -N <> -B <> -p <> -queue NOQ|INQ|KOUQ <> -K <> -out <> -T" << endl;
	  exit(1);
	}
  }
}
