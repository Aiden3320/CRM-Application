#include "pch.h"
#include "CRM.h"
#include "CInventoryAction.h"
#include "CInventory.h"
int CInventoryAction::LoadToList(CInventoryListView& listctrl)
{
	//Load Inventory from database

	CString que;
	que.Format(L"SELECT * FROM INVENTORY");
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
			//Set User Dat

			MessageBox(NULL, L"Load Inventory Success", L"Success", MB_OK);
			return true;
		}

		else
			MessageBox(NULL, L"No Inventory", L"Failed", MB_OK);
	}
	else
	{
		//Display Error
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	//Clear SQL query
	sql.clear();
	return false;


	return 1;
}

int CInventoryAction::AddInventory(const CInventory& item)
{
	CString que;

	que.Format(L"INSERT INTO INVENTORY VALUE('%s','%d','%d')", item.name, item.cost, item.count);
	CT2A t(que);
	//Check if there is user with email and password
	sql.clear();
	if (sql.query(t.m_psz))
	{
		sql.clear();
		//MessageBox(NULL, L"Add Inventory Success", L"Success", MB_OK);
		return true;
	}
	else
	{
		//Display Error
		sql.clear();
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	//Clear SQL query

		// TODO: Add your implementation code here.
	return 0;
}
int CInventoryAction::ModifyInventory(const CInventory& oldOne, const CInventory& newOne)
{
	CString que;
	sql.clear();
	que.Format(L"UPDATE INVENTORY SET name='%s', cost='%d', count='%d' WHERE name='%s'", newOne.name,newOne.cost,newOne.count,oldOne.name);
	CT2A t(que);
	if (sql.query(t.m_psz))
	{
		sql.clear();
		//MessageBox(NULL, L"Modify Inventory Success", L"Success", MB_OK);
		return true;
	}
	else
	{
		//Display Error
		sql.clear();
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	return false;
}

int CInventoryAction::RemoveInventory(const CInventory& curOne)
{
	// TODO: Add your implementation code here.
	CString que;
	sql.clear();
	que.Format(L"DELETE FROM INVENTORY WHERE name='%s'", curOne.name);
	CT2A t(que);
	if (sql.query(t.m_psz))
	{
		sql.clear();
		//MessageBox(NULL, L"Delete Inventory Success", L"Success", MB_OK);
		return true;
	}
	else
	{
		//Display Error
		sql.clear();
		MessageBox(NULL, CString(sql.getError()), L"Error", MB_OK);
	}
	return false;
	return 0;
}



