#pragma once
#include	<mysql.h>
#include	<string>
#define	LOCK_MODE_READ	1
#define	LOCK_MODE_WRITE	2

#define	MYSQL_TIMEOUT 1000000

class MySqlWrapper
{
public:
	MySqlWrapper();
	~MySqlWrapper();

public:
	bool init();
	bool connect(const char *host, const char *user, const char *password, const char *dbname, int port = 3306);
	bool isConnect();
	bool close();
	bool query(const char *pQuery);
	MYSQL_RES* getResult();
	MYSQL_ROW getRow();
	bool clear();

	const char* getError();
	bool lock(char *szTable, int nMode);
	bool unLock();

	long long getLastID();
	long long getRowCount();

	void convertEscape(std::string &str);
	bool allive_check();

private:
	MYSQL m_mysql;
	MYSQL *m_connection;
	MYSQL_RES *m_result;
	MYSQL_ROW m_row;
	bool m_flg;
};

