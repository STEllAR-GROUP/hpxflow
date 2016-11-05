////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////
#ifndef MAPPER_H
#define MAPPER_H

#include <iostream> 
#include <tuple>

#include <mysql/mysql.h>

namespace hpx {
    namespace flow {
        class mapper{
            public:
                template <typename T>
                mapper &mapperSingle(T fn);
                template <typename F>
                mapper &mapperSet(F fn);
        };

    }

}

#endif

