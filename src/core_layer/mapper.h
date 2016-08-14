////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////
#ifndef MAPPER_H
#define MAPPER_H

#include <iostream> 
#include <tuple>


namespace hpx {
    namespace flow {
        class count { 
          public: 
            int operator()(int value ) 
            { 
              return value; 
            } 
        }; 

        class word_count_tuple { 
          public: 

        }; 
        class hpxflow{
            template <typename T>
            hpxflow &mapper(T fn);
            template <typename F>
            hpxflow &mapperSet(F fn);
        };

    }

}

#endif

