#ifndef FILTER_H
#define FILTER_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include "fileoperations.h"

#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_algorithm.hpp>

#include <boost/range/functions.hpp>

// template <typename F, typename... Args>
// hpxflow &filter(int index, F fn, Args... args){

//     using hpx::parallel::for_each;
//     using hpx::parallel::par;
//     // for_each(par, boost::begin(buffer_pair_intermediate), boost::end(buffer_pair_intermediate),
//     for_each(par, buffer_pair_intermediate.begin(), buffer_pair_intermediate.end(),
//         [&index, &fn, &args..., this](pair<string, string> value){
//             if(index == 1){
//                 if(!fn(value.first, args...)){
//                     // .erase(buffer_pair_intermediate.begin() + i);
//                     buffer_pair_intermediate.erase(std::remove(buffer_pair_intermediate.begin(), buffer_pair_intermediate.end(), value), buffer_pair_intermediate.end());

//                 }
//             }else if(index == 2){
//                 if(!fn(value.second, args...)){
//                     // buffer_pair_intermediate.erase(buffer_pair_intermediate.begin() + i);
//                     buffer_pair_intermediate.erase(std::remove(buffer_pair_intermediate.begin(), buffer_pair_intermediate.end(), value), buffer_pair_intermediate.end());

//                 }
//             }

//     });
//     // return *this;
// }

#endif
