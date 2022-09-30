#include "pch.h"
#include "CInventory.h"
CInventory::CInventory()
{

}
CInventory::CInventory(CString name, int cost, int count)
{
	this->name = name;
	this->cost = cost;
	this->count = count;
}

CString CInventory::toStrong()
{
	// TODO: Add your implementation code here.
	CString res;
	res.Format(L"%s,%d,%d", name, cost, count);
	return res;
}


int CInventory::fromString(CString scr)
{
	// Convert Inventory to Strng 
	int nTokenPos = 0;
	CString strToken = scr.Tokenize(_T(","), nTokenPos);
	name = strToken;
	strToken = scr.Tokenize(_T(","), nTokenPos);
	cost = _wtoi(strToken);
	strToken = scr.Tokenize(_T(","), nTokenPos);
	count = _wtoi(strToken);
	// TODO: Add your implementation code here.
	return 0;
}
