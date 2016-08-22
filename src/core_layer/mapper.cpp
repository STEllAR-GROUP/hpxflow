////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

// #include <hpx/parallel/algorithms/for_each.hpp>
#include "mapper.h"
#include "../dataflow/window.h"
#include "../helper/buffer.h"

template <typename T>
hpx::flow::hpxflow &hpx::flow::hpxflow::mapper(T fn) {
    // std::vector<std::tuple<int, int, int, int>> window_intermediate;
    // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    hpx::flow::window obj();
    obj.window_intermediate.clear();
    for_loop(par, 0, obj.fixed_window.size(), 
        [&](int j) {
            for_loop(par, 0, obj.fixed_window[j].size(), 
                [&](int k) {
                    obj.window_intermediate.push_back(fn(obj.fixed_window[j][k]));
            });
    });

    obj.fixedWindow();
    return *this;
}

template <typename T>
hpx::flow::hpxflow &hpx::flow::hpxflow::mapperSet(T fn) {
    // std::vector<std::tuple<int, int, int, int>> window_intermediate;
    // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    hpx::flow::window obj();
    obj.window_intermediate.clear();
    for_loop(par, 0, obj.fixed_window.size(), 
        [&](int j) {
            obj.window_intermediate.push_back(fn(obj.fixed_window[j]));     
    });
    obj.fixedWindow();
    return *this;
}

