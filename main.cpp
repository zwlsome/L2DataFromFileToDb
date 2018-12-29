#include <stdio.h>
#include "mysql/my_global.h"
#include "mysql/mysql.h"

int main()
{
	MYSQL* tpSql = mysql_init(NULL);

	if(NULL == tpSql)
	{
		printf("Failed to mysql_init()");
		return -1;
	}

	if(NULL == mysql_real_connect(tpSql, "192.168.1.12", "root", "abc123", "QT2", 3306, NULL, 0))
	{
		mysql_close(tpSql);
		printf("Failed to mysql_real_connect(): Error=%s\r\n", mysql_error(tpSql));
		return -1;
	}

	getc();

	printf("Connect ok\r\nClosed\r\n");
	mysql_close(tpSql);

	return 0;
}

