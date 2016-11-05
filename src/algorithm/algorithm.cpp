////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

/**
 * @file algorithm.h
 * @author Aalekh Nigam
 * @brief This file contains some fundamental helper algorithm for the help of library users
*/

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
 
/**
 * @brief Wrapper for dynamic function execution.
 * returns fluent interface onject, used just to execute the function
 * @param fn
 *
*/

template <typename T>
hpx::flow::Algorithm &hpx::flow::Algorithm::dymcFunc(T fn) {
    fn(buffer);
    return *this;
}   

/**
 * @brief Comparator operator between two data types
 * returns the boolean value for denoting if the two are equal
 * @param first_value
 * @param second_value
*/

template<typename T>
bool hpx::flow::Algorithm::equal(const T &first_value, const T &second_value) {
    return first_value == second_value;
}

/**
 * Checks for the greater value, for ex: s > c
 * returns the boolean value for denoting if first value is greater than the second
 * @param first_value
 * @param second_value
*/

template<typename T>
bool hpx::flow::Algorithm::grt(const T &first_value, const T &second_value) {
    return first_value > second_value;
}

/**
 * @brief Checks for the greater value, for ex: s < c
 * returns the boolean value for denoting if first value is smaller than the second
 * @param first_value
 * @param second_value
*/

template<typename T>
bool hpx::flow::Algorithm::lst(const T &first_value, const T &second_value) {
    return first_value < second_value;
}

/**
 * @brief Checks for the greater value, for ex: s >= c
 * returns the boolean value for denoting if first value is greater than or equal to the second
 * @param first_value
 * @param second_value
*/

template<typename T>
bool hpx::flow::Algorithm::grt_equal(const T &first_value, const T &second_value) {
    return first_value >= second_value;
}

/**
 * @brief Checks for the greater value, for ex: s =< c
 * returns the boolean value for denoting if first value is less than or equal to the second
 * @param first_value
 * @param second_value
*/

template<typename T>
bool hpx::flow::Algorithm::lst_equal(const T &first_value, const T &second_value) {
    return first_value <= second_value;
}

/**
 * @brief Summation of two values
 * returns sum of the two parameters
 * @param first_value
 * @param second_value
*/

// template<typename T>
// T const& hpx::flow::Algorithm::summation(const T &first_value, const T &second_value) {
//     return first_value + second_value;
// }

