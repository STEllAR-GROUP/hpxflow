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

#include "algorithm.h"
 
/**
 * @brief Wrapper for dynamic function execution.
 *
 */

template <typename T>
hpx::flow::Algorithm &hpx::flow::Algorithm::dymcFunc(T fn) {
    fn(buffer);
}   

/**
 * @brief Comparator operator between two data types
 */

template<typename T>
bool hpx::flow::Algorithm::equal(const T &s, const T &c) {
    return s == c;
}

/**
 * Checks for the greater value, for ex: s > c
 */

template<typename T>
bool hpx::flow::Algorithm::grt(const T &s, const T &c) {
    return s > c;
}

/**
 * @brief Checks for the greater value, for ex: s < c
 */

template<typename T>
bool hpx::flow::Algorithm::lst(const T &s, const T &c) {
    return s < c;
}

/**
 * @brief Checks for the greater value, for ex: s >= c
 */

template<typename T>
bool hpx::flow::Algorithm::grt_equal(const T &s, const T &c) {
    return s >= c;
}

/**
 * @brief Checks for the greater value, for ex: s =< c
 */

template<typename T>
bool hpx::flow::Algorithm::lst_equal(const T &s, const T &c) {
    return s <= c;
}

/**
 * @brief Summation of two values
 */

template<typename T>
T const& hpx::flow::Algorithm::summation(T &s, T &c) {
    return s+c;
}

