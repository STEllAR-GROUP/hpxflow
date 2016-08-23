////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include "window.h"
// #include <hpxflow_window.h>


void hpx::flow::window::sortBuffer(){
    sort(window_intermediate.begin(), window_intermediate.end(),
        [](const std::tuple<int, int, int, int>& a,
        const std::tuple<int,int, int, int>& b) -> bool
        {
            return std::get<2>(a) > std::get<2>(b);
        });
}

std::vector<std::vector<std::tuple<int, int, int, int>>> hpx::flow::window::fixedWindow(){
    std::vector<std::tuple<int, int, int, int>> intermediate;
    std::vector<std::vector<std::tuple<int, int, int, int>>> output;
    std::vector<int> ifpresent;
    int ele;
    for (int i = 0; i < 100; i++) {
        ele = std::get<2>(window_intermediate[i]);
        intermediate.push_back(window_intermediate[i]);
        if(!(std::find(ifpresent.begin(), ifpresent.end(), ele) != ifpresent.end())) {
            ifpresent.push_back(ele);
            for(int n = i+1; n < 100; n++){
                if(ele == std::get<2>(window_intermediate[n])) {
                    intermediate.push_back(window_intermediate[n]);
                }
            }
            output.push_back(intermediate);
            intermediate.clear();
        }
    }
    return output;
}

int hpx::flow::window::windowSize(){
    return fixed_window.size();
}

