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
#include <vector>
#include <string>
#include <utility>
#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_algorithm.hpp>

#include <boost/range/functions.hpp>
#include <mysql/mysql.h>

// #include <hpx/parallel/algorithms/for_each.hpp>
#include "mapper.h"
#include "../dataflow/window.h"
#include "../helper/buffer.h"
#include "../helper/hpxmysql.h"

namespace hpx {
    namespace flow {
        class mapper{
            public:
                mapper();
                ~mapper();
                template <typename T>
                mapper &mapperSingle(T fn);
                template <typename F>
                mapper &mapperSet(F fn);
        };


/**
 * @brief Applies mapper function, for a given lambda expression over each tuple elements.
 * returns fluent interface onject, used to apply mapper over each tuple<> values
 * @param fn
*/
        template <typename T>
hpx::flow::mapper &hpx::flow::mapper::mapperSingle(T fn) {
    using hpx::parallel::for_each;
    using hpx::parallel::par;

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;//hello

    char *server = "localhost";
    char *user = "root";
    char *password = ""; /* set me first */
    char *database = "test2";

    conn = mysql_init(NULL);

    std::tuple<int, int, int, int, int> vec_window{1, 2, 3, 4, 5};

  //  if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) {
   //   fprintf(stderr, "%s\n", mysql_error(conn));
   //   exit(1);
   // }

    int arr[5];
    std::vector<std::tuple<int, int, int, int, int>> element;

    //MYSQL_RES *result = retrieve_rows(conn);
    //delete_mysql(conn);
    //int num_fields = mysql_num_fields(result);

    //while ((row =  mysql_fetch_row(result)))  {
     // for(int i = 0; i < num_fields; i++) {
      //    arr[i] = std::stoi(row[i]) + 100;
      //}
      //std::tuple<int, int, int, int, int> inter {arr[0], arr[1], arr[2], arr[3], arr[4]};
      //element.push_back(inter);
   // }
   ///////////////////////

    for_loop(par, 0, element.size(),
        [&](int k) {
    //        insert_mysql(fn(element[k]), conn);
    });

    return *this;
}

/**
 * @brief Applies mapper function, for a given lambda expression over vector of tuples.
 * returns fluent interface object, used to apply mapper over each vector<tuple<>> values
 * @param fn
*/

template <typename T>
hpx::flow::mapper &hpx::flow::mapper::mapperSet(T fn) {
    // std::vector<std::tuple<int, int, int, int>> window_intermediate;
    // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
    // using hpx::parallel::for_each;
    // using hpx::parallel::par;
    // hpx::flow::window obj();
    // obj.window_intermediate.clear();
    // for_loop(par, 0, obj.fixed_window.size(),
    //     [&](int j) {
    //         obj.window_intermediate.push_back(fn(obj.fixed_window[j]));
    // });
    // obj.fixedWindow();
    return *this;
}



hpx::flow::mapper::mapper(void){}

hpx::flow::mapper::~mapper(void){}
}}

#endif

