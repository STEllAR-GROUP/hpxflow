// ////////////////////////////////////////////////////////////////////////////////
// //  Copyright (c) 2016 Aalekh Nigam
// //
// //  Distributed under the Boost Software License, Version 1.0. (See accompanying
// //  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// ////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include "hpxflowblockingqueue.h"
// #include "hpxflowcountdownlatch.h"

// using namespace std;

// namespace hpx{

// 	namespace flow{

// 			class pipeline{
// 				// hpx::flow::BlockingQueue in;
// 				// hpx::flow::BlockingQueue out;
// 				hpx::flow::CountDownLatch

// 				bool done;
				
// 				public:
					
// 					virtual void initializeStep() = 0;
					
// 					virtual void intermediateStep() = 0;
					
// 					virtual void terminateStep() = 0;

// 					void run(){
// 					   try{ 

// 					   	initializeStep();
					   
// 					   	while(!done) { 
					   	
// 					   		intermediateStep();
					   
// 					   	}
// 					   	terminateStep();
					   
// 						} catch(exception e) {
// 							cout << "Exception: " << e << endl;
// 						}
// 					}
// 			};

// 			class linearPipeline{
// 				std::vector<pipeline> stages;
// 				std::vector<BlockingQueue> queues;

// 				int numstages;

// 				CountDownLatch s;

// 				virtual vector<pipeline> getPipelineStages(vector<string> args) = 0;

// 				virtual vector<BlockingQueue> getQueues(vector<string> args) = 0;

// 				linearPipeline(vector<string> args) {
// 					stages = getPipelineStages(args);
// 					queues = getQueues(args);
// 				   	numstages = stages.size();
// 				   	CountDownLatch s(numstages);

// 				   	BlockingQueue in = 0;
// 					BlockingQueue out = queues[0];

// 					for (int i = 0; i != numstages; i++) { 

// 						in = out;
// 						if (i < numstages-2) 
// 							out = queues[i+1]; 
// 						else 
// 							out = 0;
// 			   		}
// 			   	}
// 			   	void start(){ 
// 			   		// Need to work on this
// 			   	}
// 			};
// 	}
// }