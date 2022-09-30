#pragma once
#include "pch.h"

#include "mysqlwrapper.h"
#include "CInventoryList.h"
#include "CUser.h"
class CUserAction
{
private:

public:
	CUserAction();
	~CUserAction();
	BOOL UserLogin(CString emailAddress,
		CString password);
	BOOL UserRegister(CString emailAddress,
		CString phoneNumber,
		CString firstName,
		CString lastName,
		CString address,
		CString password,
		CString pName,
		CString pNumber,
		CString pExpdate,
		CString pSeccode,
		CString pStreetaddress,
		CString pState,
		CString pZipcode);
	int UserPurchaseInventory(const CInventoryList &);

	const char * convert(CString );
	bool UserLogOut();
	int SubmitFeedbaack(CString );
	int UserUpdate(CString email, CString password, CUser newUser);
};


