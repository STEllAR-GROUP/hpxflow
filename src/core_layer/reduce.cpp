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
            
            std::vector<std::vector<std::tuple<int, int, int, int>>> fixedWindow(){
                std::vector<std::tuple<int, int, int, int>> intermediate;
                std::vector<std::vector<std::tuple<int, int, int, int>>> output;
                std::vector<int> ifpresent;
   // std::vector<std::tuple<int, int, int, int>> window_intermediate;
   // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
                int ele;
                for (int i = 0; i < 100; i++) {
                    ele = std::get<2>(window_intermediate[i]);
                    intermediate.push_back(window_intermediate[i]);
                    if(!(std::find(ifpresent.begin(), ifpresent.end(), ele) != ifpresent.end())) {
                        ifpresent.push_back(ele);
                        std::cout << "Element is: " << ele << std::endl;
                        for(int n = i+1; n < 100; n++){
                            if(ele == std::get<2>(window_intermediate[n])) {
                                intermediate.push_back(window_intermediate[n]);
                            }
                        }
                        output.push_back(intermediate);
                        intermediate.clear();
                    }
            }
            return output;
        }
               
       void sortBuffer(){
            std::sort(window_intermediate.begin(), window_intermediate.end(),
                [](const std::tuple<int, int, int, int>& a,
                    const std::tuple<int,int, int, int>& b) -> bool
                    {
                        return std::get<2>(a) > std::get<2>(b);
                    });
        }
            template <typename T>
            hpxflow &reduce(T fn) {
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

            template <typename T>
            hpxflow &reduceSet(T fn) {
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
