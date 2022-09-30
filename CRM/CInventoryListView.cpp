#include "pch.h"
#include "CInventoryListView.h"
#include "CRM.h"
CInventoryListView::CInventoryListView()
{

}
void CInventoryListView::AddData(int row, int col, CString str)
{
	CT2A t(str);

	LVITEM lv;
	lv.iItem = row;
	lv.iSubItem = col;
	lv.pszText = (LPWSTR)(LPCWSTR)str;
	lv.mask = LVIF_TEXT;
	if (col == 0)
		InsertItem(&lv);
	else
		SetItem(&lv);
}
void CInventoryListView::SetData(int row, int col, CString str)
{
	CT2A t(str);

	LVITEM lv;
	lv.iItem = row;
	lv.iSubItem = col;
	lv.pszText = (LPWSTR)(LPCWSTR)str;
	lv.mask = LVIF_TEXT;
	SetItem(&lv);
}

int CInventoryListView::AddInventory(CInventory& item)
{
	int nIndex = FindInventory(item);
	if (nIndex >= 0) {
		//Already exist
		CInventory newOne = item;
		newOne.count = _wtoi(GetItemText(nIndex, 2)) + item.count;
		ModifyInventory(item, newOne);
		return 0;
	}

	int row = GetItemCount();
	AddData(row, 0, item.name);
	CString temp;
	temp.Format(L"%d", item.cost);
	AddData(row, 1, temp);
	temp.Format(L"%d", item.count);
	AddData(row, 2, temp);
	return 0;
}

int CInventoryListView::getCurrentInventory(CInventory &cur)
{
	// TODO: Add your implementation code here.
	int row = GetSelectionMark();
	if (row < 0) return 0;
	cur.name = GetItemText(row, 0);
	cur.cost = _wtoi(GetItemText(row, 1));
	cur.count = _wtoi(GetItemText(row, 2));
	return 1;
}


int CInventoryListView::ModifyInventory(const CInventory& oldOne,const CInventory& newOne)
{
	// TODO: Add your implementation code here.
	int nIndex = FindInventory(oldOne);
	if (nIndex < 0) return 0;

	if (newOne.count == 0) {
		DeleteItem(nIndex);
		return 0;
	}

	SetData(nIndex, 0, newOne.name);
	CString temp;
	temp.Format(L"%d", newOne.cost);
	SetData(nIndex, 1, temp);
	temp.Format(L"%d", newOne.count);
	SetData(nIndex, 2, temp);
	return 0;
}


int CInventoryListView::RemoveInventory(const CInventory& curOne)
{
	// TODO: Add your implementation code here.
	int nIndex = FindInventory(curOne);
	if (nIndex < 0) return 0;
	DeleteItem(nIndex);
	return 0;
}


int CInventoryListView::init()
{


	InsertColumn(0, L"Name");
	SetColumnWidth(0, 80);

	InsertColumn(1, L"Cost");
	SetColumnWidth(1, 80);

	InsertColumn(2, L"Quantity");
	SetColumnWidth(2, 80);

	SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
		LVS_EX_FULLROWSELECT);
	// TODO: Add your implementation code here.
	return 0;
}


int CInventoryListView::FindInventory(const CInventory& cur)
{
	// TODO: Add your implementation code here.
	LVFINDINFO info;
	int nIndex;

	info.flags = LVFI_PARTIAL | LVFI_STRING;
	info.psz = cur.name;
	return FindItem(&info);
}

int CInventoryListView::GetInventoryByIndex(CInventory& cur, int index)
{

	if (index < 0) return 0;
	cur.name = GetItemText(index, 0);
	cur.cost = _wtoi(GetItemText(index, 1));
	cur.count = _wtoi(GetItemText(index, 2));
	return 1;
}

int CInventoryListView::GetInventoryCountByName(const CString& str)
{
	LVFINDINFO info;
	int nIndex;

	info.flags = LVFI_PARTIAL | LVFI_STRING;
	info.psz = str;
	nIndex = FindItem(&info);
	if (nIndex < 0) return 0;
		
	// TODO: Add your implementation code here.
	return _wtoi(GetItemText(nIndex, 2));
}
