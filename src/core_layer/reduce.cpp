// ////////////////////////////////////////////////////////////////////////////////
// //  Copyright (c) 2016 Aalekh Nigam
// //
// //  Distributed under the Boost Software License, Version 1.0. (See accompanying
// //  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
// ////////////////////////////////////////////////////////////////////////////////


// #include "reduce.h"

// template <typename T>
// hpx::flow::reduce &hpx::flow::reduce::reduceSingle(T fn) {
//     using hpx::parallel::for_each;
//     using hpx::parallel::par;
//     hpx::flow::window obj();
//     obj.sortBuffer();
//     obj.window_intermediate.clear();
//     for_each(par, 0, obj.fixed_window.size(),
//         [&](int i){
//             for_loop(par, 0, obj.fixed_window[i].size(), 
//                 [&](int j) {
//                     obj.window_intermediate.push_back(fn(obj.fixed_window[i][j]));     
//             });
//     });
//     obj.fixedWindow();
//     return *this;
// } 

// template <typename T>
// hpx::flow::reduce &hpx::flow::reduce::reduceSet(T fn) {
//     using hpx::parallel::for_each;
//     using hpx::parallel::par;
//     hpx::flow::window obj();
//     obj.sortBuffer();
//     obj.window_intermediate.clear();
//     for_each(par, 0, obj.fixed_window.size(),
//         [&](int i){
//              obj.window_intermediate.push_back(fn(obj.fixed_window[i]));     
//     });
//     obj.fixedWindow();
//     return *this;
// }   

