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
            // template <typename T, typename V, typename L>
            // std::tuple<T, V> operator()(L value ) 
            // { 
            //   std::make_tuple(value, "1");
            // } 
        }; 

        template <typename T>
        hpxflow &map(T fn);
    }

}


