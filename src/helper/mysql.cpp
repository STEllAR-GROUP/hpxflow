#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <mysql/mysql.h>
#pragma comment (lib,"libmysql")
#pragma comment (lib,"mysqlclient")

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

struct Window {
   int  a;
   int  b;
   int  c;
   int  d;
   int  e;
};

void insert(vector<Window> element, MYSQL *conn) {


   for(int j = 0; j < (sizeof(element)/sizeof(element[0])); j++) {
      std::string insert_test = "insert into test(one, two, three, four, five) values(" + to_string(element[j].a) + ", " + to_string(element[j].b) +", " + to_string(element[j].c) +", " + to_string(element[j].d) + ", " + to_string(element[j].e) + ")";
      mysql_query(conn, insert_test.c_str());
   }
}

MYSQL_RES *retrieve_rows(MYSQL *conn) {
     if (mysql_query(conn, "SELECT * FROM test"))  {
      finish_with_error(conn);
     }
  
     MYSQL_RES *result = mysql_store_result(conn);
     
     if (result == NULL)  {
         finish_with_error(conn);
     }

     return result;
}

int main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;//hello

   char *server = "localhost";
   char *user = "root";
   char *password = ""; /* set me first */
   char *database = "test2";

   conn = mysql_init(NULL);

   vector<Window> vec_window;
   for(int i = 0; i < 2; i++) {
      Window window;
      window.a = i+1;
      window.b = i+2;
      window.c = i+3;
      window.d = i+4;
      window.e = i+5;
      vec_window.push_back(window);

   }

   if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   insert(vec_window, conn);
   
   ////////////////////////////
   MYSQL_RES *result = retrieve_rows(conn);
   
   int num_fields = mysql_num_fields(result);

   while ((row =  mysql_fetch_row(result)))  { 
      for(int i = 0; i < num_fields; i++) { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
          printf("\n"); 
   }

   ///////////////////////////
   mysql_close(conn);
   return 1;
}