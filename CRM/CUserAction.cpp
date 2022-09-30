#include "pch.h"
#include "CUserAction.h"
#include "CRM.h"
#include <mysql.h>
CUserAction::CUserAction()
{
}
CUserAction::~CUserAction()
{
	sql.clear();
	sql.close();

}

BOOL CUserAction::UserLogin(CString emailAddress,
	CString password)
{
	//Check Admin 
	
	if (emailAddress.Compare(L"root") == 0 && password.Compare(L"root") == 0)
	{
		MessageBox(NULL, L"Login Success with Admin", L"Success", MB_OK);
		curUser.setAdmin();
		return true;
	}
	//User Login Action
	CString que;
	
	que.Format(L"SELECT * FROM CUSTOMER WHERE email = '%s' AND password = '%s'",emailAddress, password);
	CT2A t(que);
	//Check if there is user with email and password
	sql.clear();
	if (sql.query(t.m_psz))
	{
		//Check if there is any user with email and password
		if (sql.getResult()->row_count > 0)
		{
			//Set User Data
			curUser.setCurrentUser(sql.getResult());
			MessageBox(NULL, L"Login Success", L"Success", MB_OK);
			return true;
		}
			
		else 
			MessageBox(NULL, L"Email Address or Password is Incorrect!", L"Failed", MB_OK);
	}
	else
	{
		//Display Error
		MessageBox(NULL, CString(sql.getError()), L"Success", MB_OK);
	}
	//Clear SQL query
	sql.clear();
	return false;
}

bool CUserAction::UserLogOut()
{
	//Clear User Data
	curUser.empty();
	// TODO: Add your implementation code here.
	return true;
}

BOOL CUserAction::UserRegister(CString emailAddress,
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
	CString pZipcode) {
	CString que;
	que.Format(L"INSERT INTO CUSTOMER VALUE('%s','%s','%s','%s','%s','%s',0,'','%s','%s','%s','%s','%s','%s','%s')", 
		emailAddress, 
		firstName, 
		lastName, 
		phoneNumber, 
		address, 
		password,
		pName,
		pNumber,
		pExpdate,
		pSeccode,
		pStreetaddress,
		pState,
		pZipcode);
	CT2A ascii(que);
	//convert CString to const char *
	if (sql.query(ascii.m_psz))
	{
		MessageBox(NULL, L"Register Success",L"Success",MB_OK);
		//UserLogin(emailAddress, password);
	}
	else {
		MessageBox(NULL,CString(sql.getError()), L"Error", MB_OK);
	}
	sql.clear();
//	insert into customer value ('a','a','a','a','a','a')
	return true;
};


const char *  CUserAction::convert(CString str)
{
	CT2A ascii(str);
	// TODO: Add your implementation code here.
	return ascii.m_psz;
}


int CUserAction::UserPurchaseInventory(const CInventoryList&data)
{
	CInventoryList newList = data;
	CString newInventory = newList.toString();
	CString que;
	que.Format(L"UPDATE CUSTOMER as a SET a.inventory='%s' WHERE email='%s'", newInventory, curUser.email);
	CT2A ascii(que);
	sql.clear();
	//convert CString to const char *
	if (sql.query(ascii.m_psz))
	{
		MessageBox(NULL, L"Purchase Inventory Success", L"Success", MB_OK);
		curUser.list = newList;
	}
	else {
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	sql.clear();
	// TODO: Add your implementation code here.
	return 0;
}



int CUserAction::SubmitFeedbaack(CString feedback)
{
	// TODO: Add your implementation code here.

	CString que;
	//CString t = CTime::GetCurrentTime().Format("%Y-%M-%d %H:%M:%S");
	CString t = CTime::GetCurrentTime().Format("%y-%m-%d %H:%M:%S");
	que.Format(L"INSERT INTO FEEDBACK VALUE('%s','%s','%s','%s')", curUser.email,curUser.getFullName(),t,feedback);
	CT2A ascii(que);
	sql.clear();
	//convert CString to const char *
	if (sql.query(ascii.m_psz))
	{
		MessageBox(NULL, L"Feedback Submited! Thank you", L"Success", MB_OK);
	}
	else {
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	sql.clear();
	return 0;
}


int CUserAction::UserUpdate(CString email,CString password, CUser newUser)
{
	CString que;
	que.Format(L"UPDATE CUSTOMER SET FirstName='%s', LastName='%s', PhoneNumber='%s',Address='%s',pName='%s',pCardNumber='%s',pExpDate='%s',pSecurityCode='%s', pStreetAddress='%s', pState='%s',pZipCode='%s' WHERE email='%s'", 
		newUser.firstName,
		newUser.lastName,
		newUser.phoneNumber,
		newUser.address,
		newUser.pay.pName,
		newUser.pay.pNumber,
		newUser.pay.pExpDate,
		newUser.pay.pSecurityCode,
		newUser.pay.pStreetAddress,
		newUser.pay.pState,
		newUser.pay.pZipCode, email);
	CT2A ascii(que);
	sql.clear();
	//convert CString to const char *
	if (sql.query(ascii.m_psz))
	{
		MessageBox(NULL, L"Update Profile Success", L"Success", MB_OK);
		curUser = newUser;
	}
	else {
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	sql.clear();
	// TODO: Add your implementation code here.
	return 0;
}
