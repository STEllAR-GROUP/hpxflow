////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <regex>
#include <map>
#include <array>

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

		// Summation of two values
		template<typename T>
		T const& summation(T &s, T &c) {
			return s+c;
		}

		// concatenating two arrray's 
		template<typename T>
		std::vector<T> concat_array(T &s, T&c) {
			// std::array<T, (sizeof(s)/sizeof(*s)) + (sizeof(c)/sizeof(*c))> result;
			std::vector<T> result;
			for(int i = 0; i < (sizeof(s)/sizeof(*s)); i++) {
				result.push_back(s[i]);
				// result[i] = s[i];
			}
			for (int j = (sizeof(s)/sizeof(*s)), k = 0; k < (sizeof(c)/sizeof(*c)); j++, k++) {
				result.push_back(c[j]);
				// result[j] = c[i];
			}
			return result;
		}		

		// Maps each single elements of array as word count
		template<typename T, typename X>
		std::vector<std::map<std::string, int>> mp_arr_map(T &t, X &x) {
			std::vector<std::map<std::string, int>> result;
			std::map<std::string, int> a;
			for(int i=0; i < (sizeof(t)/sizeof(*t)); i++){
				a(t[i], 1);
				result.push_back(a);
			}
			return result;
		}

		template<typename T, typename X>
		T const& regex_filter(T &t, X &x) {
			if(std::regex_match(t, std::regex(x))) {
				return t;
			}
		}

		// Add's all values in a key-value pair
		template<typename Y>
		long double const& add_values(Y &y) {
			long double sum = 0;
			std::map<std::string, int>::iterator it;
			for(int i = 0; i < y.size(); i++){
				for (auto it=y[i].begin(); it!=y[i].end(); ++it) {
					sum = sum + it->second;
				}
			}
		}

	}

}

#endif