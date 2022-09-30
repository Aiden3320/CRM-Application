#include "pch.h"
#include "CUser.h"
CUser::CUser()
{

}
BOOL CUser::setCurrentUser(MYSQL_RES * mysql_res)
{
    //Set role to customer
    role = ROLE_CUSTOMER;
    unsigned int num_fields = mysql_num_fields(mysql_res);
    MYSQL_ROW row;
    row = mysql_fetch_row(mysql_res);
    //Set User Data
    email = CString(row[0] ? row[0] : "NULL");
    firstName = CString(row[1] ? row[1] : "NULL");
    lastName = CString(row[2] ? row[2] : "NULL");
    phoneNumber = CString(row[3] ? row[3] : "NULL");
    address = CString(row[4] ? row[4] : "NULL");
    password = CString(row[5] ? row[5] : "NULL");
    CString ilist = CString(row[7] ? row[7] : "");
    list.fromString(ilist);
    pay.pName = CString(row[8] ? row[8] : "NULL");
    pay.pNumber = CString(row[9] ? row[9] : "NULL");
    pay.pExpDate = CString(row[10] ? row[10] : "NULL");
    pay.pSecurityCode = CString(row[11] ? row[11] : "NULL");
    pay.pStreetAddress = CString(row[12] ? row[12] : "NULL");
    pay.pState = CString(row[13] ? row[13] : "NULL");
    pay.pZipCode = CString(row[14] ? row[14] : "NULL");
	return true;
}

CString CUser::getFullName()
{
    CString res = firstName;
    res.AppendChar(' ');
    res += lastName;
    // TODO: Add your implementation code here.
    return res;
}


BOOL CUser::empty()
{
    email = firstName = lastName = phoneNumber = address = password = CString("");
    // TODO: Add your implementation code here.
    return 0;
}


int CUser::setAdmin()
{
    //Set Admin Priviliage
    role = ROLE_ADMIN;
    // TODO: Add your implementation code here.
    return 0;
}


int CUser::getRole()
{
    // TODO: Add your implementation code here.
    return role;
}
