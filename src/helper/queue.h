
#ifndef QUEUE
#define QUEUE

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class Queue {
  
 public:

  T pop();

  // void pop(T&);
  void push(const T&);
  // Queue()=default;
  // Queue(const Queue&) = delete;            // disable copying
  // Queue& operator=(const Queue&) = delete; // disable assignment
  
 private:
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
};

#endif