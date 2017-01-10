////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef REDUCE_H
#define REDUCE_H

#include <iostream>
#include <mysql/mysql.h>
#include <hpx/include/parallel_algorithm.hpp>

#include "../helper/hpxmysql.h"
#include "../config.hpp"


namespace hpx
{
  namespace flow
  {
    class reduce
    {
    public:
      reduce ()
      {
      }
      // std::vector<std::tuple<int, int, int, int>> window_intermediate;
      // std::vector<std::vector<std::tuple<int, int, int, int>>> fixed_window;
      template < typename T > reduce & reduceSingle (T fn);

        template < typename T > reduce & reduceSet (T fn);
    };

	/**
 * @brief Applies reducer function, for a given lambda expression over each tuple elements. (vector of tuple is sorted)
 * returns fluent interface onject, used to apply reducer over each tuple<> values
 * @param fn
*/

      template < typename T >
      hpx::flow::reduce & hpx::flow::reduce::reduceSingle (T fn)
    {
      using hpx::parallel::for_each;
      using hpx::parallel::par;

      MYSQL *conn;
      MYSQL_RES *res;
      MYSQL_ROW row;

        std::string server = SERVER;
        std::string user = USER;
        std::string password = PASSWORD;	/* set me first */
        std::string database = DATABASE;

        conn = mysql_init (NULL);

        std::tuple < int, int, int, int, int >vec_window
      {
      1, 2, 3, 4, 5};

      if (!mysql_real_connect
	  (conn, server.c_str (), user.c_str (), password.c_str (),
	   database.c_str (), 0, NULL, 0))
	{
	  fprintf (stderr, "%s\n", mysql_error (conn));
	  exit (1);
	}

      int arr[5];
      std::vector < std::tuple < int, int, int, int, int >>element;

      MYSQL_RES *result = hpx::flow::hpxmysql::retrieve_rows (conn);

      hpx::flow::hpxmysql::delete_mysql (conn);

      int num_fields = mysql_num_fields (result);

      while ((row = mysql_fetch_row (result)))
	{
	  for (int i = 0; i < num_fields; i++)
	    {
	      arr[i] = std::stoi (row[i]) + 100;
	    }
	  std::tuple < int, int, int, int, int >inter
	  {
	  arr[0], arr[1], arr[2], arr[3], arr[4]};
	  element.push_back (inter);
	}
      ///////////////////////

      for_loop (par, 0, element.size (),[&](int k)
		{
		hpx::flow::hpxmysql::insert_mysql (fn (element[k]), conn);});

      return *this;
    }

/**
 * @brief Applies reducer function, for a given lambda expression over vector(tuple) elements. (vector of tuple is sorted)
 * returns fluent interface onject, used to apply reducer over vector<tuple<>> values
 * @param fn
*/

    template < typename T >
      hpx::flow::reduce & hpx::flow::reduce::reduceSet (T fn)
    {
      // using hpx::parallel::for_each;
      // using hpx::parallel::par;
      // hpx::flow::window obj();
      // obj.sortBuffer();
      // obj.window_intermediate.clear();
      // for_each(par, 0, obj.fixed_window.size(),
      //     [&](int i){
      //          obj.window_intermediate.push_back(fn(obj.fixed_window[i]));     
      // });
      // obj.fixedWindow();
      return *this;
    }


  }

}



#endif
