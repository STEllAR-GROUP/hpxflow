////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>

namespace hpx{
    namespace flow{

        class window{

            std::vector<std::tuple<int, int, int, int>> window_intermediate;
            std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
            std::vector<int> ifpresent;

            window(std::vector<std::tuple<int, int, int, int>> buffer){
                window_intermediate = buffer;
            }
            ~window(){
            }

            void sortBuffer();

            std::vector<std::vector<std::tuple<int, int, int, int>>> fixedWindow();

            int windowSize();
        };
    }
}


// #include <hpxflow_window.h>

// using namespace std;






#endif
