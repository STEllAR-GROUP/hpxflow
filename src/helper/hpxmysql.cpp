#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include <mysql/mysql.h>

#include "hpxmysql.h"

#pragma comment (lib,"libmysql")
#pragma comment (lib,"mysqlclient")

void hpx::flow::hpxmysql::finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

void hpx::flow::hpxmysql::insert(std::tuple<int, int, int, int, int> element, MYSQL *conn) {

      std::string insert_test = "insert into test(one, two, three, four, five) values(" + to_string(std::get<0>(element)) + ", " + to_string(std::get<1>(element)) +", " + to_string(std::get<2>(element)) +", " + to_string(std::get<3>(element)) + ", " + to_string(std::get<4>(element)) + ")";
      std::cout << mysql_query(conn, insert_test.c_str()) << std::endl;
}

void hpx::flow::hpxmysql::delete(MYSQL *conn) {

    std::string delete_test = "delete from test";
    mysql_query(conn, delete_test.c_str());
}

MYSQL_RES *hpx::flow::hpxmysql::retrieve_rows(MYSQL *conn) {
     if (mysql_query(conn, "SELECT * FROM test"))  {
      finish_with_error(conn);
     }
  
     MYSQL_RES *result = mysql_store_result(conn);
     
     if (result == NULL)  {
         finish_with_error(conn);
     }

     return result;
}