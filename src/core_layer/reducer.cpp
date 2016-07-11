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
		    std::tuple<auto, auto> operator()(auto value ) 
		    { 
		      std::make_tuple(value, "1");
		    } 
		}; 

		template <typename T>
		hpxflow &reduce(T fn) {

			sort(buffer_intermediate.begin(), buffer_intermediate.end(), [](tuple<int, int, int, int> &lhs, tuple<int, int, int, int> &rhs ){ return get<1>(lhs) < get<1>(rhs);});
			// for (auto it = std::begin(buffer_intermediate); it!=std::end(buffer_intermediate); ++it){
// 					for(auto &x: buffer_intermediate[it])
// 						fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x));
// 			}

			for(auto &x: buffer_intermediate)
				fn(std::get<0>(x), std::get<1>(x), std::get<2>(x), std::get<3>(x));
		}	

	}

}