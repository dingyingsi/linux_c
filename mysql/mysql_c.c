
#include <stdio.h>
#include <mysql/mysql.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn,"localhost","root","Xl123456","word",0,NULL,0))
    {
        printf("Can not connect word! \n");
    } else{
        printf("connect success! \n");
    }
    if (mysql_query(conn,"select * from word"))
    {
        printf("query db_books faild! \n");
    } else{
        MYSQL_RES *result = mysql_use_result(conn);
        if (result) {
            int num_fields = mysql_num_fields(result);
            int num_rows = mysql_field_count(conn);
            for (int i = 0; i < num_rows; i++) {
                MYSQL_ROW row = mysql_fetch_row(result);
                if (row == NULL) {
                    break;
                }
                for (int j = 0; j < num_fields; j++) {
                    printf("%s\t", row[j]);
                }
                printf("\n");
            }
        }
        mysql_free_result(result);
    }
    printf("Hello, World!\n");
    return 0;
}