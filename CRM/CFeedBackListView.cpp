#include "pch.h"
#include "CFeedBackListView.h"
#include "CRM.h"
void CFeedBackListView::AddData(int row, int col, CString str)
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
	if (col == 3)
		feedbacks.AddTail(str);
}


int CFeedBackListView::init()
{

	InsertColumn(0, L"Name");
	SetColumnWidth(0, 100);

	InsertColumn(1, L"Email");
	SetColumnWidth(1, 100);

	InsertColumn(2, L"Date");
	SetColumnWidth(2, 100);

	InsertColumn(3, L"Feedback");
	SetColumnWidth(3, 100);

	SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
		LVS_EX_FULLROWSELECT);
	// TODO: Add your implementation code here.
	return 0;
}


CString CFeedBackListView::GetFeedbackByIndex(int nIndex)
{
	// TODO: Add your implementation code here.
	return feedbacks.GetAt(feedbacks.FindIndex(nIndex));
}


int CFeedBackListView::DeleteFeedback(int nIndex)
{
	// TODO: Add your implementation code here.
	feedbacks.RemoveAt(feedbacks.FindIndex(nIndex));
	return DeleteItem(nIndex);
//	return 0;
}


CString CFeedBackListView::GetDateByIndex(int nIndex)
{
	return GetItemText(nIndex, 2);

	// TODO: Add your implementation code here.
	//return CString();
}
