////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////


#include <iostream> 
#include <tuple>

#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_algorithm.hpp>

#include <boost/range/functions.hpp>
// #include <hpx/parallel/algorithms/for_each.hpp>
#include "mapper.h"

template <typename T>
hpxflow &hpx::flow::word_count_tuple::map(T fn){
    using hpx::parallel::for_each;
    using hpx::parallel::par;
    buffer_test.clear();
    for_each(par, buffer_intermediate.begin(), buffer_intermediate.end(),
        [&](tuple<int, int, int, int> value){
        buffer_test.push_back(fn(std::get<0>(value), std::get<1>(value), std::get<2>(value), std::get<3>(value)));
    });

    buffer_intermediate.clear();
    buffer_intermediate = buffer_test;
    return *this;
}


