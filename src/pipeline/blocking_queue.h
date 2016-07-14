////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOWBLOCKINGQUEUE_H
#define HPXFLOWBLOCKINGQUEUE_H

#include <mutex>
#include <iostream>
#include <queue>

using namespace std;

namespace hpx{

    namespace flow{

		template <typename T>
		class BlockingQueue {
		private:
		    mutex mutex_;
		    queue<T> queue_;
		public:
		    bool pop() {}

		    void push(T value) {}

		    bool empty() {}
		};

		template<typename T>
		void fillWorkQueue(BlockingQueue<T>& , T) {}

		template<typename T>
		void doWork(BlockingQueue<T>& ) {}
	}
}		

#endif 