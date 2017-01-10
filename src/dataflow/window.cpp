////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

/**
 * @file window.cpp
 * @author Aalekh Nigam
 * @brief This file contains functions for implementing window mechanism as described in dataflow paper.
*/

#include <regex>
#include <map>
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>
#include <set>
#include <tuple>
#include <functional>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>
#include <unordered_map>

#include "window.h"
// #include <hpxflow_window.h>

/**
 * @brief Applies sorting function, for a given vector of tuple elements.
*/

void
hpx::flow::window::sortBuffer ()
{
  sort (window_intermediate.begin (), window_intermediate.end (),
	[](const std::tuple < int, int, int, int >&a,
	   const std::tuple < int, int, int, int >&b)->bool
	{
	return std::get < 2 > (a) > std::get < 2 > (b);}
  );
}

/**
 * @brief Applies fixedWindow function, for a given set of vector of tuple elements.
 * returns used to apply fixed over each tuple<> values and returns vector(vector(tuple)) elements.
*/

std::vector < std::vector < std::tuple < int, int, int, int >>>
hpx::flow::window::fixedWindow ()
{
  std::vector < std::tuple < int, int, int, int >>
    intermediate;
  std::vector < std::vector < std::tuple < int, int, int, int >>>
    output;
  std::vector < int >
    ifpresent;
  int
    ele;
  for (int i = 0; i < 100; i++)
    {
      ele = std::get < 2 > (window_intermediate[i]);
      intermediate.push_back (window_intermediate[i]);
      if (!
	  (std::find (ifpresent.begin (), ifpresent.end (), ele) !=
	   ifpresent.end ()))
	{
	  ifpresent.push_back (ele);
	  for (int n = i + 1; n < 100; n++)
	    {
	      if (ele == std::get < 2 > (window_intermediate[n]))
		{
		  intermediate.push_back (window_intermediate[n]);
		}
	    }
	  output.push_back (intermediate);
	  intermediate.clear ();
	}
    }
  return output;
}

/**
 * @brief Returns window size
 * returns size of window
*/

int
hpx::flow::window::windowSize ()
{
  return fixed_window.size ();
}
