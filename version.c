#include <stdlib.h>
#include <stdio.h>
#include <my_global.h>
#include <mysql.h>


int amin(int argc, char **argv){
	printf("MySQL client version: %s\n", mysql_get_client_info());

MYSQL *con = mysql_init(NULL)//initiate null connection object

if(con == NULL){//if connection object not initiated, exit
	fprintf(stderr, "%s\n", mysql_error(con));
	exit(1);
}

//if connection to the db fails, exit
//mysql_rael_connect paremeters: connection handle, host, uname, pwd, dbname, port#, unix socket, client flag
if(mysql_real_connect(con, "localhost", "root", "rootpwd", NULL, 0, NULL, 0) == NULL){
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

if(mysql_query(con, "CREATE DATABASE testdb")){
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

mysql_close(con);//close connection
exit(0);//normal exit
}