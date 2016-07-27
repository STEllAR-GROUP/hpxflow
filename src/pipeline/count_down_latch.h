//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Given Program is inspired from a CodeProject Tutorial, hence follows tutorial's origianal licence
// and credit norms, licence of the original tutorial is included inside hpxflow src/pipeline directory.
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOW_COUNTDOWNLATCH_H
#define HPXFLOWCOUNTDOWNLATCH_H

#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

namespace hpx{

    namespace flow{

        template< class TypeVal >
            class AtomicCounter
            {
            public:
                AtomicCounter( TypeVal val ) : m_typeVal( val ) 
                {
                }

                AtomicCounter() : m_typeVal(0)
                {
                }

                AtomicCounter(const AtomicCounter& cpy) : m_typeVal(cpy.m_typeVal){}

                const AtomicCounter& operator=(const AtomicCounter& other){}

                virtual ~AtomicCounter(){}

                const TypeVal& getCount() const{}

                const TypeVal& setCount( const TypeVal &val ) {}

                const TypeVal& increment() {}

                const TypeVal& decrement() {}

                const TypeVal& increment(const TypeVal& t) {}

                const TypeVal& decrement(const TypeVal& t) {}


            private:
                mutable boost::mutex m_atomicMutex;
                TypeVal m_typeVal;
            };

                   class CountDownLatch
            {
            public:
                CountDownLatch( int count ): m_cdlCount( count ) 
                {
                }

                CountDownLatch(const CountDownLatch& cpy){}

                const CountDownLatch& operator=(const CountDownLatch& other){}

                virtual ~CountDownLatch() {}
                void wait() {}
                void wait( uint64_t timeoutMicros ) {}
                void countDown() {}

                int getCount(){}


            private:
                boost::mutex m_cdlMutex;
                boost::condition_variable m_cdlCondition;
                AtomicCounter< int >  m_cdlCount;           
            };
    }
}
#endif