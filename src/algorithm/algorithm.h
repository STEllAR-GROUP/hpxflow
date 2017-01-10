////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef ALGORITHM_H
#define ALGORITHM_H

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

namespace hpx
{
  namespace flow
  {


    class Algorithm
    {

    public:
      std::string strm_;
      std::string buffer;
      std::string data;
    public:
      Algorithm (std::string strm)
      {
	std::ifstream infile;
	infile.open (strm);
	std::getline (infile, strm_);
      }

      template < typename T > Algorithm & dymcFunc (T);

        template < typename T > bool equal (const T &, const T &);

      // Checks for the greater value, for ex: s > c
        template < typename T > bool grt (const T &, const T &);

      // Checks for the greater value, for ex: s < c
        template < typename T > bool lst (const T &, const T &);

      // Checks for the greater value, for ex: s >= c
        template < typename T > bool grt_equal (const T &, const T &);

      // Checks for the greater value, for ex: s =< c
        template < typename T > bool lst_equal (const T &, const T &);

      // Summation of two values
        template < typename T > T const &summation (T &, T &);

    };



  }
}


#endif
