////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <thread>
#include <mutex>
#include <iostream>
#include <queue>
#include <functional>


using std::thread;
using namespace std;
using std::mutex;
using std::cout;
using std::endl;
using std::queue;
using std::ref;

namespace hpx{

    namespace flow{

        template <typename T>
        class BlockingQueue {
        private:
            mutex mutex_;
            queue<T> queue_;
        public:
            bool pop() {
                this->mutex_.lock();
                T value;
                if( !this->queue_.empty() )
                {
                    value = this->queue_.front();  // undefined behavior if queue_ is empty
                                                   // may segfault, may throw, etc.
                    this->queue_.pop();
                }
                this->mutex_.unlock();
                return value;
            }

            void push(T value) {
                this->mutex_.lock();
                this->queue_.push(value);
                this->mutex_.unlock();
            }

            bool empty() {
                this->mutex_.lock();
                bool check = this->queue_.empty();
                this->mutex_.unlock();
                return check;
            }
        };

        template<typename T>
        void fillWorkQueue(BlockingQueue<T>& workQueue, T value) {
                workQueue.push(value);
        }

        template<typename T>
        void doWork(BlockingQueue<T>& workQueue) {
            while(!workQueue.empty()) {
                workQueue.pop();
            }   
        }
    }
}
    