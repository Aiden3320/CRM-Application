#include  "pch.h"
#include	"mysqlwrapper.h"
std::string str_replace( std::string &String1, std::string &String2, std::string &String3 )
{
    std::string::size_type  Pos( String1.find( String2 ) );

    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }

    return String1;
}

MySqlWrapper::MySqlWrapper()
{
	m_connection = NULL; 
	m_result = NULL;
	m_flg = false;
}

MySqlWrapper::~MySqlWrapper()
{
}

bool MySqlWrapper::init()
{
	try{
		if( !mysql_init(&m_mysql) ){
			return false;
		}

		unsigned int timeout = MYSQL_TIMEOUT;
		if( mysql_options(&m_mysql, MYSQL_OPT_CONNECT_TIMEOUT, (unsigned int*)&timeout) != 0 ){
			return false;
		}

	}catch(...)
	{
		return false;
	}

	return true;
}

bool MySqlWrapper::connect(const char *host, const char *user, const char *password, const char *dbname, int port)
{
	if( isConnect() ){
		return false;
	}

	try{
		m_connection = mysql_real_connect(&m_mysql, host, user, password, dbname, port, NULL, 0);
		if( !isConnect() ){
			return false;
		}
	}catch(...)
	{
		return false;
	}

	return true;
}

bool MySqlWrapper::isConnect()
{
	if( m_connection == NULL ){
		return false;
	}

	return true;
}

bool MySqlWrapper::close()
{
	try{

		if( isConnect() ){
			mysql_close(m_connection);
		}

	}catch(...)
	{
		return false;
	}

	m_connection = NULL;
	return true;
}

bool MySqlWrapper::query(const char *pQuery)
{
	if( !isConnect() ){
		return false;
	}

	if( m_flg ){
		return false;
	}

	try{

		if( mysql_query(m_connection, pQuery) != 0 ){
			return false;
		}

	}catch(...)
	{
		return false;
	}

	try{
		m_result = mysql_store_result(m_connection);
	}catch(...)
	{
		return false;
	}

	m_flg = true;
	return true;
}

MYSQL_RES *MySqlWrapper::getResult()
{
	return m_result;
}

MYSQL_ROW MySqlWrapper::getRow()
{
	return mysql_fetch_row( getResult() );
}

bool MySqlWrapper::clear()
{
	m_flg = false;

	if( m_result == NULL ){
		return true;
	}

	try{
		mysql_free_result(m_result);
		m_result = NULL;
	}
	catch(...)
	{
		return false;
	}
		
	return true;
}

const char * MySqlWrapper::getError()
{
	return mysql_error(&m_mysql);
}

//=========================================================
//	nMode:
//		LOCK_MODE_READ
//		LOCK_MODE_WRITE
//---------------------------------------------------------*/
bool MySqlWrapper::lock(char *pTable, int nMode)
{
	std::string	str;
	if( nMode == LOCK_MODE_WRITE ){

		str = "LOCK TABLES ";
		str += pTable;
		str += " WRITE;";

	}else if( nMode == LOCK_MODE_READ ){

		str = "LOCK TABLES ";
		str += pTable;
		str += " READ;";

	}else{
		return false;
	}

	bool b = query( str.c_str() );
	if( !b ){
		unLock();
		return false;
	}
	
	clear();
	return true;
}

bool MySqlWrapper::unLock()
{
	if( !query("UNLOCK TABLES;") ){
		return false;
	}
	
	clear();
	return true;
}

long long MySqlWrapper::getLastID()
{
	std::string	str;
	str = "SELECT LAST_INSERT_ID();";
	bool b = query( str.c_str() );
	if( !b ){
		return -1;
	}

	long long nId = 0;
	MYSQL_ROW row;
	try
	{
		while( (row = mysql_fetch_row( getResult() )) != NULL ){
			nId = atol(row[0]);
		}
	}catch(...){
		return -1;
	}

	if( nId == 0 ){
		return -1;
	}

	clear();

	return nId;
}

long long MySqlWrapper::getRowCount()
{
	if( !isConnect() ){
		return -1;
	}
	if( !m_flg ){
		return -1;
	}
	if( m_result == NULL ){
		return -1;
	}

	long long rows = 0;
	try{
		rows = mysql_num_rows(m_result);
	}catch(...)
	{
		return -1;
	}

	return rows;
}

void MySqlWrapper::convertEscape(std::string &str)
{
	std::string	tmp = str;
	std::string replace1 = "\\";
	std::string replace1_2 = "\\\\";
	std::string replace2 = "'";
	std::string replace2_2 = "\\'";
	str_replace(str, replace1 , replace1_2  );
	str_replace(str, replace2 , replace2_2  );
	return;
}

bool MySqlWrapper::allive_check()
{
	try
	{
		if( mysql_ping(&m_mysql) != 0 ){
			return false;
		}
	}
	catch(...)
	{
		return false;
	}

	return true;
}

