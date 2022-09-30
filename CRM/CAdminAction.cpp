#include "pch.h"
#include "CRM.h"
#include "CAdminAction.h"
#include "mysqlwrapper.h"
int CAdminAction::LoadFeedbackList(CFeedBackListView& listctrl)
{
	// TODO: Add your implementation code here.
	CString que;
	que.Format(L"SELECT * FROM FEEDBACK");
	CT2A t(que);
	//Check if there is user with email and password
	sql.clear();
	if (sql.query(t.m_psz))
	{
		//Check if there is any inventory
		if (sql.getResult()->row_count > 0)
		{
			MYSQL_RES* mysql_res = sql.getResult();
			//Add data to listctrl
			MYSQL_FIELD* field;
			unsigned int num_fields = mysql_num_fields(mysql_res);
			MYSQL_ROW row;
			int rc = 0;
			for (; (row = mysql_fetch_row(mysql_res)); rc++)
			{
				for (int i = 0; i < num_fields; i++)
				{
					listctrl.AddData(rc, i, CString(row[i]));
				}
			}

			MessageBox(NULL, L"Load Feedback Success", L"Success", MB_OK);
			return true;
		}

		else
			MessageBox(NULL, L"No Feedbacks", L"Failed", MB_OK);
	}
	else
	{
		//Display Error
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	//Clear SQL query
	sql.clear();
	return false;

}


int CAdminAction::DeleteFeedback(CString stime,CString feedback)
{
	CString que;
	que.Format(L"DELETE FROM FEEDBACK WHERE date='%s' AND feedback='%s'",stime ,feedback);
	CT2A t(que);
	//Check if there is user with email and password
	sql.clear();
	if (sql.query(t.m_psz))
	{
		//Delete Feedback Success
		MessageBox(NULL, L"Delete Feedback Success", L"Success", MB_OK);
		return true;

	}
	else
	{
		//Display Error
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	//Clear SQL query
	sql.clear();
	// TODO: Add your implementation code here.
	return 0;
}


int CAdminAction::LoadUsers(CListBox &list)
{
	// TODO: Add your implementation code here.
	CString que;
	que.Format(L"SELECT EMAIL FROM CUSTOMER");
	CT2A t(que);
	
	sql.clear();
	// Load all usrs from customer
	if (sql.query(t.m_psz))
	{
		//Check if there is any user
		if (sql.getResult()->row_count > 0)
		{
			MYSQL_RES* mysql_res = sql.getResult();
			//Add data to list
			MYSQL_FIELD* field;
			unsigned int num_fields = mysql_num_fields(mysql_res);
			MYSQL_ROW row;
			int rc = 0;

			for (; (row = mysql_fetch_row(mysql_res)); rc++)
			{
				list.AddString(CString(row[0]));
			}

			MessageBox(NULL, L"Login Users", L"Success", MB_OK);
			return true;
		}

		else
			MessageBox(NULL, L"No Users", L"Failed", MB_OK);
	}
	else
	{
		//Display Error
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	//Clear SQL query
	sql.clear();
	return false;
	return 0;
}


int CAdminAction::LoadUserByEmail(CString email,CUser & user)
{
	// TODO: Add your implementation code here.
	CString que;
	que.Format(L"SELECT * FROM CUSTOMER WHERE email='%s'",email);
	CT2A t(que);
	//Check if there is user with email 
	sql.clear();
	if (sql.query(t.m_psz))
	{
		//Check if there is user
		if (sql.getResult()->row_count > 0)
		{
			user.setCurrentUser(sql.getResult());
			//MessageBox(NULL, L"Login User", L"Success", MB_OK);
			return true;
		}

		else
			MessageBox(NULL, L"No User", L"Failed", MB_OK);
	}
	else
	{
		//Display Error
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	//Clear SQL query
	sql.clear();
	return false;
	return 0;
}


int CAdminAction::DeleteUserByEmail(CString email)
{
	CString que;
	sql.clear();
	que.Format(L"DELETE FROM CUSTOMER WHERE email='%s'", email);
	CT2A t(que);
	if (sql.query(t.m_psz))
	{
		sql.clear();
		MessageBox(NULL, L"Delete User Success", L"Success", MB_OK);
		return true;
	}
	else
	{
		//Display Error
		sql.clear();
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	return false;
	// TODO: Add your implementation code here.
	return 0;
}
