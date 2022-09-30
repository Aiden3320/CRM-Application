
// CRMDlg.h : header file
//

#pragma once


#include "CUserProfile.h"
#include "CInventoryManage.h"
#include "CInventoryPurchase.h"
#include "CFeedbackForm.h"
// CCRMDlg dialog
class CCRMDlg : public CDialogEx
{
// Construction
public:
	CCRMDlg(CWnd* pParent = nullptr);	// standard constructor
public:

	CInventoryManage* inventoryManage;
	CInventoryPurchase* inventoryPurchase;
	CUserProfile* profile;
	CFeedbackForm* feedback;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_displayText;
	afx_msg void OnMenuViewprofile();
	afx_msg void OnMenuInventoryManage();
	afx_msg void OnBnClickedLogout();
	afx_msg void OnMenuBuyinventory();
	virtual void OnOK();
	afx_msg void OnMenuGivefeedback();
	int CloseOpenDialog();
};
