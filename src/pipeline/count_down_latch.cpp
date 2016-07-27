//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Given Program is inspired from a CodeProject Tutorial, hence follows tutorial's origianal licence
// and credit norms, licence of the original tutorial is included inside hpxflow src/pipeline directory.
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOWCOUNTDOWNLATCH_H
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

                AtomicCounter(const AtomicCounter& cpy) : m_typeVal(cpy.m_typeVal)
                {   
                    boost::mutex::scoped_lock scoped_lock(cpy.m_atomicMutex);
                    m_typeVal = cpy.m_typeVal;
                }

                const AtomicCounter& operator=(const AtomicCounter& other)
                {
                   if (this == &other)
                      return *this;
                   boost::mutex::scoped_lock lock1(&m_atomicMutex < &other.m_atomicMutex ? m_atomicMutex : other.m_atomicMutex);
                   boost::mutex::scoped_lock lock2(&m_atomicMutex > &other.m_atomicMutex ? m_atomicMutex : other.m_atomicMutex);
                   m_typeVal = other.m_typeVal;
                   return *this;
                }

                virtual ~AtomicCounter() 
                {
                }

                const TypeVal& getCount() const
                { 
                    boost::mutex::scoped_lock lock( m_atomicMutex ); 
                    return m_typeVal; 
                }

                const TypeVal& setCount( const TypeVal &val ) 
                { 
                    boost::mutex::scoped_lock lock( m_atomicMutex ); 
                    m_typeVal = val; 
                    return m_typeVal; 
                }

                const TypeVal& increment() 
                { 
                    boost::mutex::scoped_lock lock( m_atomicMutex ); 
                    m_typeVal++ ; 
                    return m_typeVal; 
                }

                const TypeVal& decrement() 
                { 
                    boost::mutex::scoped_lock lock( m_atomicMutex ); 
                    m_typeVal-- ; 
                    return m_typeVal; 
                }

                const TypeVal& increment(const TypeVal& t) 
                { 
                    boost::mutex::scoped_lock lock( m_atomicMutex ); 
                    m_typeVal+=t ; 
                    return m_typeVal; 
                }

                const TypeVal& decrement(const TypeVal& t) 
                { 
                    boost::mutex::scoped_lock lock( m_atomicMutex ); 
                    m_typeVal-=t ; 
                    return m_typeVal; 
                }


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

                CountDownLatch(const CountDownLatch& cpy)
                {
                    boost::unique_lock<boost::mutex>(const_cast<boost::mutex&>(cpy.m_cdlMutex));
                    m_cdlCount = cpy.m_cdlCount;
                }

                const CountDownLatch& operator=(const CountDownLatch& other)
                {
                   if (this == &other)
                      return *this;
                   boost::mutex::scoped_lock lock1(const_cast<boost::mutex&>(&m_cdlMutex < &other.m_cdlMutex ? m_cdlMutex : other.m_cdlMutex));
                   boost::mutex::scoped_lock lock2(const_cast<boost::mutex&>(&m_cdlMutex > &other.m_cdlMutex ? m_cdlMutex : other.m_cdlMutex));
                   m_cdlCount = other.m_cdlCount;
                   return *this;
                }

                virtual ~CountDownLatch() 
                {
                }
                void wait() 
                { 
                    boost::mutex::scoped_lock lock( m_cdlMutex ); 
                    if( m_cdlCount.getCount() > 0 ) 
                    { 
                        m_cdlCondition.wait( lock ); 
                    } 
                }
                void wait( uint64_t timeoutMicros ) 
                { 
                    boost::mutex::scoped_lock lock( m_cdlMutex ); 
                    if( m_cdlCount.getCount() > 0 ) 
                    {
                        boost::posix_time::time_duration td = boost::posix_time::milliseconds( timeoutMicros ); 
                        m_cdlCondition.timed_wait( lock, td ); 
                    } 
                }
                void countDown() 
                {  
                    boost::mutex::scoped_lock lock( m_cdlMutex ); 
                    if( m_cdlCount.decrement() == 0 ) 
                    { 
                        m_cdlCondition.notify_all(); 
                    } 
                }

                int getCount()
                {
                    return m_cdlCount.getCount();
                }


            private:
                boost::mutex m_cdlMutex;
                boost::condition_variable m_cdlCondition;
                AtomicCounter< int >  m_cdlCount;           
            };

    }
}

#endif
