////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////
#include <iostream> 
#include <tuple>


namespace hpx {
	namespace flow {
		class count { 
		  public: 
		    int operator()(int ) 
		    { 
		    } 
		}; 

		class word_count_tuple { 
		  public: 
		    std::tuple<auto, auto> operator()(auto ) {} 
		}; 

		template< typename F > 
		void map( F , auto ) {} 
	}

}