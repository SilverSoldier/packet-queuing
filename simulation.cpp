/** Program to simulate the queueing of packets at a router
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include "args.h"
#include "simulation.h"

using namespace std;

/* Average delay of packet = arrival time - transmission completion time over all transmitted packets */
int Packet_delay = 0;
int N_packets = 0;

/* Average utilization of each link - which is itself averaged over all trials
   Thus, it is equivalent to summing up all utilizations and dividing by NT
 */
int Utilization = 0;

int randint(int lower, int upper){
  return lower + rand() % (upper - lower);
}

void simulation_NOQ() {
  // Step 1: Traffic Generation
  vector<int> outputs(args.N);
  // For each input port
  for(int i = 0; i < args.N; i++){
	// Generate packet with packetGenProb
	float roll = (float) rand() / RAND_MAX;
	if(roll < args.p) {
	  // Packet is generated - decide output port randomly between 0 and N-1
	  N_packets++;
	  int output = randint(0, args.N);
	  outputs[output]++;
	}
  }

  // Step 2: Scheduling
  // For each output queue
  for(int i = 0; i < args.N; i++){
	if(outputs[i] != 0){
		// We choose a random index between 0 and size, to choose which among the contending input packets is chosen
	  Utilization += 1;
	}
  }

  // Step 3: Transmission
  // Each packet is arrives in the next slot thus delay.
  Packet_delay += 1;
}	 

void simulation_INQ() {
}

void simulation_KOUQ() {
}
	  
void simulation() {
  switch(args.queue){
  case NOQ:
	for(int i = 0; i < args.T; i++)
	  simulation_NOQ();
	break;
  case INQ:
	for(int i = 0; i < args.T; i++)
	  simulation_INQ();
	break;
  case KOUQ:
	for(int i = 0; i < args.T; i++)
	  simulation_KOUQ();
	break;
  }

  float utilization_avg = (float) Utilization / (args.N * args.T);

  cout << "Utilization avg: " << utilization_avg << endl;
}
	  
