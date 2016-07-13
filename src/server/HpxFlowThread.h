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

#endif;