////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <tuple>
#include <vector>
#include <hpx/hpx.hpp>
// #include "reduce.h"
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_sort.hpp>

namespace hpx {
    namespace flow {
        class count { 
          public: 
            int operator()(int value ) 
            { 
              return value; 
            } 
        }; 

        class word_reduce_tuple { 
          public: 
            template <typename T, typename V, typename L>
            std::tuple<T, V> operator()(L value ) 
            { 
              std::make_tuple(value, "1");
            } 
        }; 

        class hpxflow{
            std::vector<std::tuple<int, int, int, int>> buffer_intermediate;
            std::vector<std::tuple<int, int, int, int>> buffer_test;
            template <typename T>
            hpxflow &reduce(T fn) {
                //using hpx::parallel::for_each;
                using hpx::parallel::par;
                sort(buffer_intermediate.begin(), buffer_intermediate.end(), [](std::tuple<int, int, int, int> &lhs, std::tuple<int, int, int, int> &rhs ){ return std::get<1>(lhs) < std::get<1>(rhs);});
                buffer_test.clear();
                for_each(par, buffer_intermediate.begin(), buffer_intermediate.end(),
                    [&](std::tuple<int, int, int, int> value){
                    buffer_test.push_back(make_tuple(fn(std::get<0>(value), std::get<1>(value), std::get<2>(value), std::get<3>(value))));
                });
                buffer_intermediate.clear();
                buffer_intermediate = buffer_test;
                return *this;
            }   
        };
    }

}
