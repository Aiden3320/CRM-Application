#pragma once
#include "afxdialogex.h"


// CInventoryForm dialog

class CInventoryForm : public CDialogEx
{
	DECLARE_DYNAMIC(CInventoryForm)

public:
	CInventoryForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInventoryForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INVENTORYINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	int m_cost;
	int m_count;
	virtual BOOL DestroyWindow();
	int setCurrentInventory(CInventory);
};
