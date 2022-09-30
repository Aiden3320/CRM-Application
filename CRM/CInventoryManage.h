#pragma once
#include "afxdialogex.h"

#include "CInventoryListView.h"

// CInventoryManage dialog

class CInventoryManage : public CDialogEx
{
	DECLARE_DYNAMIC(CInventoryManage)

public:
	CInventoryManage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInventoryManage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVENTORYMANAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CInventoryListView m_InventoryList;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddInventory();
	afx_msg void OnBnClickedModifyinventory();
	afx_msg void OnBnClickedRemoveinventory();
};
