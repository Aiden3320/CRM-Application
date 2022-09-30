#pragma once
#include "afxdialogex.h"
#include "CInventoryManage.h"
#include "CFeedbackView.h"
#include "CUserManageDlg.h"
// CAdminDlg dialog

class CAdminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAdminDlg();
public:
	CInventoryManage* inventory;
	CFeedbackView* feedback;
	CUserManageDlg* usermanage;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMINDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuInventorymanager();
	afx_msg void OnBnClickedLogout();
	afx_msg void OnMenuFeedbacks();
	afx_msg void OnMenuManageusers();
	int CloseOpenDialog();
};
