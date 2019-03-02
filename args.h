#ifndef ARGS_H
#define ARGS_H

using namespace std;

enum Queue {NOQ, INQ, KOUQ};

typedef struct Args {
  int N;
  int B;
  float p;
  Queue queue;
  int K;
  char* outputfile;
  int T;
} Args;

extern Args args;

void parse_args(Args* args, int argc, char* argv[]);

#endif
