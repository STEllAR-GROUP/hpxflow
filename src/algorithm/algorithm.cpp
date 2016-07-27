////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include <regex>
#include <map>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>


using namespace std;

namespace hpx
{
	namespace flow{


		class Test{

			std::string strm_;
			std::string buffer;
			std::string data;
		public:
			Test(std::string strm) {
				ifstream infile; 
				infile.open(strm);
				std::getline(infile, strm_);
			}

			template <typename T>
			Test &map(T fn) {
				buffer = fn(strm_);
			}

			template <typename T>
			Test &reduce(T fn) {
				fn(buffer);
			}	

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

		};

		
		
	}
}

