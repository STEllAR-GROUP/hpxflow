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

namespace hpx
{
  namespace flow
  {
    class hpxmysql
    {

    public:

      static void finish_with_error (MYSQL * con)
      {
	fprintf (stderr, "%s\n", mysql_error (con));
	mysql_close (con);
	exit (1);
      }

      static void insert_mysql (std::tuple < int, int, int, int, int >element,
				MYSQL * conn)
      {

	std::string insert_test =
	  "insert into test(one, two, three, four, five) values(" +
	  std::to_string (std::get < 0 >
			  (element)) + ", " + std::to_string (std::get < 1 >
							      (element)) +
	  ", " + std::to_string (std::get < 2 >
				 (element)) + ", " +
	  std::to_string (std::get < 3 >
			  (element)) + ", " + std::to_string (std::get < 4 >
							      (element)) +
	  ")";
	std::cout << mysql_query (conn, insert_test.c_str ()) << std::endl;
      }

      static void delete_mysql (MYSQL * conn)
      {

	std::string delete_test = "delete from test";
	mysql_query (conn, delete_test.c_str ());
      }

      static MYSQL_RES *retrieve_rows (MYSQL * conn)
      {
	if (mysql_query (conn, "SELECT * FROM test"))
	  {
	    finish_with_error (conn);
	  }

	MYSQL_RES *result = mysql_store_result (conn);

	if (result == NULL)
	  {
	    finish_with_error (conn);
	  }

	return result;
      }
    };

  }
}



#endif
