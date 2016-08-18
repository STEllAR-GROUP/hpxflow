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
#include "algorithm.h"

template <typename T>
hpx::flow::Algorithm &hpx::flow::Algorithm::map(T fn) {
    buffer = fn(strm_);
}

template <typename T>
hpx::flow::Algorithm &hpx::flow::Algorithm::reduce(T fn) {
    fn(buffer);
}   

template<typename T>
bool hpx::flow::Algorithm::equal(const T &s, const T &c) {
    return s == c;
}

// Checks for the greater value, for ex: s > c
template<typename T>
bool hpx::flow::Algorithm::grt(const T &s, const T &c) {
    return s > c;
}

// Checks for the greater value, for ex: s < c
template<typename T>
bool hpx::flow::Algorithm::lst(const T &s, const T &c) {
    return s < c;
}

// Checks for the greater value, for ex: s >= c
template<typename T>
bool hpx::flow::Algorithm::grt_equal(const T &s, const T &c) {
    return s >= c;
}

// Checks for the greater value, for ex: s =< c
template<typename T>
bool hpx::flow::Algorithm::lst_equal(const T &s, const T &c) {
    return s <= c;
}

// Summation of two values
template<typename T>
T const& hpx::flow::Algorithm::summation(T &s, T &c) {
    return s+c;
}

