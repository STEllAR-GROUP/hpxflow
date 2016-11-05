////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef REDUCE_H
#define REDUCE_H

#include <iostream>


namespace hpx {
    namespace flow { 
        class reduce{
            public:
                reduce() {}
            // std::vector<std::tuple<int, int, int, int>> window_intermediate;
            // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
            template <typename T>
            reduce &reduceSingle(T fn);

            template <typename T>
            reduce &reduceSet(T fn);
        };
    }

}



#endif