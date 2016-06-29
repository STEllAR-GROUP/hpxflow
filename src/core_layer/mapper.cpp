////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////


#include <iostream> 
#include <tuple>
#include <hpx/parallel/algorithms/for_each.hpp>

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
		    std::tuple<auto, auto> operator()(auto value ) 
		    { 
		      std::make_tuple(value, "1");
		    } 
		}; 

		template< typename F > 
		void map( F f, auto values ) 
		{ 
			hpx::parallel::for_each(
			hpx::parallel::par,
			std::begin(values), std::end(values),
			[&](auto value) {
				f(value);
			});	
		} 
	}

}

