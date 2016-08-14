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
#include <hpx/include/parallel_algorithm.hpp>
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

            std::vector<std::tuple<int, int, int, int>> window_intermediate;
            std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
            template <typename T>
            hpx::flow::hpxflow &hpx::flow::reduce(T fn) {
                using hpx::parallel::for_each;
                using hpx::parallel::par;
                sortBuffer();
                window_intermediate.clear();
                for_each(par, 0, fixed_window.size(),
                    [&](int i){
                        for_loop(par, 0, fixed_window[i].size(), 
                            [&](int j) {
                                window_intermediate.push_back(fn(fixed_window[i][j]));     
                        });
                });
                fixedWindow();
                return *this;
            } 

            hpx::flow::hpxflow &hpx::flow::reduceSet(T fn) {
                using hpx::parallel::for_each;
                using hpx::parallel::par;
                sortBuffer();
                window_intermediate.clear();
                for_each(par, 0, fixed_window.size(),
                    [&](int i){
                         window_intermediate.push_back(fn(fixed_window[i]));     
                });
                fixedWindow();
                return *this;
            }   
        };
    }

}
