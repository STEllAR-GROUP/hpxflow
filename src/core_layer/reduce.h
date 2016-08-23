////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef REDUCE_H
#define REDUCE_H

#include <iostream> 
#include <tuple>
#include <vector>
#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_algorithm.hpp>
#include <hpx/include/parallel_sort.hpp>
#include "../dataflow/window.h"
#include "../helper/buffer.h"

namespace hpx {
    namespace flow { 
        class reduce{

            template <typename T>
            reduce &reduceSingle(T fn);

            template <typename T>
            reduce &reduceSet(T fn);
        };
    }

}



#endif
