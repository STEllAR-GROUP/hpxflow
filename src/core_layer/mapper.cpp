////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////


#include <iostream> 
#include <tuple>
#include <vector>
#include <string>
#include <utility>
#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_algorithm.hpp>

#include <boost/range/functions.hpp>
// #include <hpx/parallel/algorithms/for_each.hpp>
#include "mapper.h"
#include "../algorithm/fileoperations.h"

std::vector<std::vector<std::tuple<int, int, int, int>>> fixedWindow(){
    std::vector<std::tuple<int, int, int, int>> intermediate;
    std::vector<std::vector<std::tuple<int, int, int, int>>> output;
    std::vector<int> ifpresent;
    std::vector<std::tuple<int, int, int, int>> window_intermediate;
    std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
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

template <typename T>
hpx::flow::hpxflow &hpx::flow::hpxflow::mapper(T fn) {
    std::vector<std::tuple<int, int, int, int>> window_intermediate;
    std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    window_intermediate.clear();
    for_loop(par, 0, fixed_window.size(), 
        [&](int j) {
            for_loop(par, 0, fixed_window[j].size(), 
                [&](int k) {
                    window_intermediate.push_back(fn(fixed_window[j][k]));
            });
    });

    fixedWindow();
    return *this;
}

template <typename T>
hpx::flow::hpxflow &hpx::flow::hpxflow::mapperSet(T fn) {
    std::vector<std::tuple<int, int, int, int>> window_intermediate;
    std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    window_intermediate.clear();
    for_loop(par, 0, fixed_window.size(), 
        [&](int j) {
            window_intermediate.push_back(fn(fixed_window[j]));     
    });
    fixedWindow();
    return *this;
}
