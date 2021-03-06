#include "queue.h"
#include "buffer.h"
#include <iostream>
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

template < typename T > void
Buffer::insert (std::vector < std::tuple < int, int, int, int >>inter,
		Queue < int >&q, int n)
{
  int k = n * inter.size () / no_of_threads_producer;
  int l = (n + 1) * inter.size () / no_of_threads_producer;
  for (int j = k - 1; j < l; j++)
    {
      q.push (inter[j]);
    }
}

template < typename F, Args ... args > void
Buffer::consumer_exec (Queue < int >&q, int n, F fn, Args ... args)
{
  int size = size_queue ();
  std::vector < int >ele;
  for (int i = 0; i < size / n; i++)
    {
      ele.push_back (q.pop ());
    }
  for (int j = 0; j < ele.size (); j++)
    {
    fn (ele[j], args ...)}
}

    // template <typename F>
void
Buffer::producers (std::vector < std::tuple < int, int, int,
		   int >>intermediate)
{
  std::vector < std::thread > producer;
  for (int i = 1; i < no_of_threads_producer; ++i)
    producer.
      push_back (std::
		 thread (std::bind (&insert, intermediate, std::ref (q), i)));

for (auto & pd:producer)	// Basically wait's for thread to finish !!
    pd.join ();
}

template < typename F, Args ... args > void
Buffer::consumer (F fn, Args ... args)
{
  std::vector < std::thread > consumer;
  for (int i = 1; i < no_of_threads_consumer; ++i)
    consumers.
      push_back (std::
		 thread (std::
			 bind (&consumer_exec, std::ref (q), i, F fn,
			       Args ... args)));

for (auto & cn:consumers)	// Basically wait's for thread to finish !!
    cn.join ();
}

// };
