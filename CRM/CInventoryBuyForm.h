#pragma once
#include "afxdialogex.h"


// CInventoryBuyForm dialog

class CInventoryBuyForm : public CDialogEx
{
	DECLARE_DYNAMIC(CInventoryBuyForm)

public:
	CInventoryBuyForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInventoryBuyForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVENTORYBUYFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_maxCount;
	int m_cost;
	int m_count;
	int m_total;
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit2();
};
