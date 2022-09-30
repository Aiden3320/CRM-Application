#pragma once
#include "afxdialogex.h"
#include "CInventoryListView.h"

// CInventoryPurchase dialog

class CInventoryPurchase : public CDialogEx
{
	DECLARE_DYNAMIC(CInventoryPurchase)

public:
	CInventoryPurchase(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInventoryPurchase();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVENTORYPURCHASE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CInventoryListView m_InventoryList;
	CInventoryListView m_inventoryBasket;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedInventorybuy();
	int m_totalCost;
	afx_msg void OnBnClickedInventorypurchase();
};
