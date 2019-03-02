#include <cstdlib>
#include "simulation.h"
#include "args.h"

int main(int argc, char* argv[]){
  srand(100);
  parse_args(&args, argc, argv);
  simulation();
}
