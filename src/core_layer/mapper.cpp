////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////


/**
 * @file mapper.cpp
 * @author Aalekh Nigam
 * @brief This file contains functions for helping mapper functions over hpx
*/

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
#include "../dataflow/window.h"
#include "../helper/buffer.h"


/**
 * @brief Applies mapper function, for a given lambda expression over each tuple elements.
 * returns fluent interface onject, used to apply mapper over each tuple<> values
 * @param fn
*/

template <typename T>
hpx::flow::mapper &hpx::flow::mapper::mapperSingle(T fn) {
    // std::vector<std::tuple<int, int, int, int>> window_intermediate;
    // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    // hpx::flow::window obj();
    // obj.window_intermediate.clear();
    for_loop(par, 0, obj.fixed_window.size(), 
        [&](int j) {
            for_loop(par, 0, obj.fixed_window[j].size(), 
                [&](int k) {
                    obj.window_intermediate.push_back(fn(obj.fixed_window[j][k]));
            });
    });

    // obj.fixedWindow();
    return *this;
}

/**
 * @brief Applies mapper function, for a given lambda expression over vector of tuples.
 * returns fluent interface object, used to apply mapper over each vector<tuple<>> values
 * @param fn
*/

template <typename T>
hpx::flow::mapper &hpx::flow::mapper::mapperSet(T fn) {
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
