
#include <stdio.h>
#include <mysql/mysql.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    MYSQL * conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn,"localhost","root","********","db_books",0,NULL,0))
    {
        printf("Can not connect db_books! \n");
    } else{
        printf("connect success! \n");
    }
    if (mysql_query(conn,"select * from tb_book"))
    {
        printf("query db_books faild! \n");
    } else{
        printf("query db_books success!\n");
    }
    printf("Hello, World!\n");
    return 0;
}