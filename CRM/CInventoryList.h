#pragma once
#include "CInventory.h"
class CInventoryList
{
public:
	CList<CInventory> data;
public:
	CInventoryList();
	CInventoryList& operator = (const CInventoryList & A);
	CInventoryList(const CInventoryList&);
	int findByName(const CString& str);
	void AddInventory(const CInventory newOne);
	int fromString(CString src);
	CString toString();
//	friend CInventoryList operator +(const CInventoryList&, const CInventoryList&);
	int GetCount();
	CInventory GetAt(int i);
};

