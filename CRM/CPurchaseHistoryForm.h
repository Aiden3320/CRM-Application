#pragma once
#include "afxdialogex.h"
#include "CInventoryList.h"
#include "CInventoryListView.h"

// CPurchaseHistoryForm dialog

class CPurchaseHistoryForm : public CDialogEx
{
	DECLARE_DYNAMIC(CPurchaseHistoryForm)

public:
	CPurchaseHistoryForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPurchaseHistoryForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PURCHASEHISTORYFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CInventoryList m_InventoryList;
	CInventoryListView m_InventoryListView;
	int m_total;
	virtual BOOL OnInitDialog();
};
