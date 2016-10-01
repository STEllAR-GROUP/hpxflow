#include <iostream>
#include <cstdio>
#include <cstdlib>

// For MySQL Connection
#include <mysql.h>

using namespace std;

// Defining Constant Variables
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "test"

int windowing(){
    
}

int connect()
{
    MYSQL *connect;
    connect = mysql_init(NULL);

    if (!connect)
    {
        cout << "Mysql Initialization Failed";
        return 1;
    }

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);

    if (connect)
    {
        cout << "Connection Succeeded\n";
    }
    else
    {
        cout << "Connection Failed\n";
    }

    MYSQL_RES *res_set;
    MYSQL_ROW row;

    // Replace MySQL query with your query

    mysql_query (connect,"show tables");

    unsigned int i=0;

    res_set=mysql_store_result(connect);

    unsigned int numrows = mysql_num_rows(res_set);
    
    cout << " Tables in " << DATABASE << " database " << endl;

    while (((row=mysql_fetch_row(res_set)) !=NULL))
    {
        cout << row[i] << endl;
    }

    mysql_close (connect);

    return 0;
}

function makeRecoverySQL($table, $id)
{
    // get the record          
    $selectSQL = "SELECT * FROM `" . $table . "` WHERE `id` = " . $id . ';';

    $result = mysql_query($selectSQL, $YourDbHandle);
    $row = mysql_fetch_assoc($result); 

    $insertSQL = "INSERT INTO `" . $table . "` SET ";
    foreach ($row as $field => $value) {
        $insertSQL .= " `" . $field . "` = '" . $value . "', ";
    }
    $insertSQL = trim($insertSQL, ", ");

    return $insertSQL;
}


