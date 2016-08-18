#ifndef BUFFER_H
#define BUFFER_H

#include "queue.h"                                                               
#include <iostream>                                                              
#include <atomic>                                                                
#include <thread>                                                                
#include <vector>  

template <typename T>

class Buffer {
public:

    Queue<T> q; 
    int no_of_threads_consumer;
    int no_of_threads_producer;
 
public:
    Buffer(int no_consumer, int no_producer)
    {
        no_of_threads_consumer = no_consumer;
        no_of_threads_producer = no_producer;
    }

    void insert(std::vector<std::tuple<int, int, int, int>> , Queue<int>&, int );

    template <typename F, typename Args>
    void consumer_exec(Queue<int>& , int , F fn, Args... );
    // template <typename F>
    void producers(std::vector<std::tuple<int, int, int, int>>);
    template <typename F, typename Args>
    void consumer( F, Args... );

};

#endif;
