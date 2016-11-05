////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPXMYSQL_H
#define HPXMYSQL_H

#include <iostream>
#include <tuple>

#include <mysql/mysql.h>

#pragma comment (lib,"libmysql")
#pragma comment (lib,"mysqlclient")

namespace hpx {
    namespace flow { 
        class hpxmysql{

            void finish_with_error(MYSQL *);

            void insert(std::tuple<int, int, int, int, int>, MYSQL *);

            void delete(MYSQL *);

            MYSQL_RES *retrieve_rows(MYSQL *);
        };
    }

}



#endif
