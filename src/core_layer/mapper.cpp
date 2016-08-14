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
hpx::flow::hpxflow &hpx::flow::hpxflow::mapperAll(T fn) {
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