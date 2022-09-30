#pragma once
#include <mysql.h>
#include "CInventoryList.h"
#include "CPaymentMethod.h"
#define ROLE_ADMIN 1
#define ROLE_CUSTOMER 2
class CUser
{
public:
	CUser();
public:
	CString email;
	CString password;
	CString firstName;
	CString lastName;
	CString phoneNumber;
	CString address;
	CInventoryList list;
	CPaymentMethod pay;
	int role;
	
public:
	BOOL setCurrentUser(MYSQL_RES*);
	CString getFullName();
	BOOL empty();
	int setAdmin();
	int getRole();
};

