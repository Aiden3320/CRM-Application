#pragma once
class CInventory
{
public:
	CString name;
	int cost;
	int count;
public:
	CInventory();
	CInventory(CString name, int cost, int count);
	CString toStrong();
	int fromString(CString scr);
};

