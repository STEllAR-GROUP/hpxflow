////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#ifndef HPX_FLOW_ALGORITHM_H
#define HPX_FLOW_ALGORITHM_H

namespace hpx
{
	namespace flow{

		// Compares two data's for equality 
		template<typename T>
		bool equal(const T &s, const T &c) {
			return s == c;
		}

		// Checks for the greater value, for ex: s > c
		template<typename T>
		bool grt(const T &s, const T &c) {
			return s > c;
		}

		// Checks for the greater value, for ex: s < c
		template<typename T>
		bool lst(const T &s, const T &c) {
			return s < c;
		}

		// Checks for the greater value, for ex: s >= c
		template<typename T>
		bool grt_equal(const T &s, const T &c) {
			return s >= c;
		}

		// Checks for the greater value, for ex: s =< c
		template<typename T>
		bool lst_equal(const T &s, const T &c) {
			return s <= c;
		}

		template<typename T>
		T const& summation(T &s, T &c) {
			return s+c;
		}

	}

}

#endif