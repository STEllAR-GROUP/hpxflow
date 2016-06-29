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

		template< typename F > 
		void reducer( F f, auto values ) 
		{ 
			// Working
			hpx::parallel::sort_by_key();
		} 
	}

}