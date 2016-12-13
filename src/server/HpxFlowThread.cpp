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

#include "hpxflowthread.h"

using namespace
  hpx::flow;

static void *
runThread (void *arg)
{
  return ((Thread *) arg)->run ();
}

HpxFlowThread::HpxFlowThread ():m_tid (0), m_running (0), m_detached (0)
{
}

HpxFlowThread::~HpxFlowThread ()
{
  if (m_running == 1 && m_detached == 0)
    {
      pthread_detach (m_tid);
    }
  if (m_running == 1)
    {
      pthread_cancel (m_tid);
    }
}

int
HpxFlowThread::start ()
{
  int result = pthread_create (&m_tid, NULL, runThread, this);
  if (result == 0)
    {
      m_running = 1;
    }
  return result;
}

int
HpxFlowThread::join ()
{
  int result = -1;
  if (m_running == 1)
    {
      result = pthread_join (m_tid, NULL);
      if (result == 0)
	{
	  m_detached = 0;
	}
    }
  return result;
}

int
HpxFlowThread::detach ()
{
  int result = -1;
  if (m_running == 1 && m_detached == 0)
    {
      result = pthread_detach (m_tid);
      if (result == 0)
	{
	  m_detached = 1;
	}
    }
  return result;
}

pthread_t
HpxFlowThread::self ()
{
  return m_tid;
}

HpxFlowWorker::wqueue ()
{

  pthread_mutex_init (&m_mutex, NULL);
  pthread_cond_init (&m_condv, NULL);

}

HpxFlowWorker::~wqueue ()
{

  pthread_mutex_destroy (&m_mutex);
  pthread_cond_destroy (&m_condv);

}

void
HpxFlowWorker::add (T item)
{

  pthread_mutex_lock (&m_mutex);
  m_queue.push_back (item);
  pthread_cond_signal (&m_condv);
  pthread_mutex_unlock (&m_mutex);

}

T
HpxFlowWorker::remove ()
{

  pthread_mutex_lock (&m_mutex);
  while (m_queue.size () == 0)
    {
      pthread_cond_wait (&m_condv, &m_mutex);
    }
  T item = m_queue.front ();
  m_queue.pop_front ();
  pthread_mutex_unlock (&m_mutex);
  return item;

}

int
HpxFlowWorker::size ()
{

  pthread_mutex_lock (&m_mutex);
  int size = m_queue.size ();
  pthread_mutex_unlock (&m_mutex);
  return size;

}
