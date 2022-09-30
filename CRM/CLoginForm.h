#pragma once
#include "afxdialogex.h"


// CLoginForm dialog

class CLoginForm : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginForm)

public:
	CLoginForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CLoginForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int CheckValidation();
	CString m_emailAddress;
	CString m_password;
};
