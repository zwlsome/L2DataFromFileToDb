#include <stdio.h>
#include <assert.h>
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

	printf("Connect ok\r\n");

	char tCh = getchar();

	char* tpChar = (char*)malloc(1024);
	tpChar += 100000000000;
	*tpChar = 10;

	mysql_close(tpSql);
	printf("Closed\r\n");

	return 0;
}

