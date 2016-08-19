/*
   thread.cpp
   Definition of a Java style thread class in C++.
   ------------------------------------------
   Copyright © 2013  [Vic Hargrave - http://vichargrave.com]
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
       http://www.apache.org/licenses/LICENSE-2.0
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


// PS: Initial implementation of the given code has been inspired from this tutorial: http://vichargrave.com/java-style-thread-class-in-c/, and hence author's
// would like to pay due credits to all the work done by the tutorial author. 


#ifndef HPX_FLOW_THREAD_H
#define HPX_FLOW_THREAD_H

#include <pthread.h>

namespace hpx{

	namespace flow{
		
		class HpxFlowThread {
		  public:
		    HpxFlowThread();
		    virtual ~HpxFlowThread();

		    int start();
		    int join();
		    int detach();
		    pthread_t self();
		    
		    virtual void* run() = 0;
		    
		  private:
		    pthread_t  m_tid;
		    int        m_running;
		    int        m_detached;
		};

		template <typename T> class HpxFlowWorker {
		    list<T>          m_queue;
		    pthread_mutex_t  m_mutex;
		    pthread_cond_t   m_condv; 

		  public:
		    wqueue() {}
		    ~wqueue() {}
		    void add(T item) {}
		    T remove() {}
		    int size() {}
		};
	}
}

#endif
