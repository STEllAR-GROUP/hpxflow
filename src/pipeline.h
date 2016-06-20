////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPX_FLOW_PIPELINE_H
#define HPX_FLOW_PIPELINE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "blocking_queue.h"
#include "count_down_latch.h"

using namespace std;

namespace hpx{

	namespace flow{

			class pipeline{
				hpx::flow::BlockingQueue in;
				hpx::flow::BlockingQueue out;
				hpx::flow::CountDownLatch

				bool done;
				
				public:
					
					virtual void initializeStep() = 0;
					
					virtual void intermediateStep() = 0;
					
					virtual void terminateStep() = 0;

					void run(){}
			};

			class linearPipeline{
				std::vector<pipeline> stages;
				std::vector<BlockingQueue> queues;

				int numstages;

				CountDownLatch s;

				virtual vector<pipeline> getPipelineStages(vector<string> args) = 0;

				virtual vector<BlockingQueue> getQueues(vector<string> args) = 0;

				linearPipeline(vector<string> args) {}
			   	void start(){ 
			   		// Need to work on this
			   	}
			};
	}
}

#endif
