#pragma once
#include "afxdialogex.h"
#include "CUser.h"
#include "CInventoryList.h"
#include "CInventoryListView.h"
// CUserProfile dialog

class CUserProfile : public CDialogEx
{
	DECLARE_DYNAMIC(CUserProfile)

public:
	CUserProfile(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserProfile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ProfileView	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	void init(CUser user);
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedUpdateinformation();
	afx_msg void OnBnClickedEditpaymentmethod();
	afx_msg void OnBnClickedPurchasehistory();
	BOOL m_changPassword;
	afx_msg void OnBnClickedChangepassword();
	CString m_oldPassword;
	CString m_password;
	CString m_password2;
};
