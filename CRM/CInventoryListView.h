#pragma once
#include <afxcmn.h>
#include "CInventory.h"
class CInventoryListView :
    public CListCtrl
{
public:

	CInventoryListView();
	void AddData(int row, int col, CString str);
	void SetData(int row, int col, CString str);
	int AddInventory(CInventory&);
	int getCurrentInventory(CInventory& cur);
	int ModifyInventory(const CInventory& oldOne, const CInventory& newOne);
	int RemoveInventory(const CInventory& curOne);
	int FindInventory(const CInventory& cur);
	int GetInventoryByIndex(CInventory& cur, int index);
	int init();
	int GetInventoryCountByName(const CString&);
};

