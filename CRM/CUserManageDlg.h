#pragma once
#include "afxdialogex.h"

#include "CUserProfile.h"
// CUserManageDlg dialog

class CUserManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUserManageDlg)

public:
	CUserManageDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserManageDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMINUSERMANAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_userlist;
	CUserProfile* userprofile;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnUserSelChange();
	afx_msg void OnBnClickedDeleteuser();
	virtual void PostNcDestroy();
	virtual void OnCancel();
};
