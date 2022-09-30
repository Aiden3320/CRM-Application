#pragma once
#include "afxdialogex.h"


// CRegisterForm dialog

class CRegisterForm : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterForm)

public:
	CRegisterForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRegisterForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTRATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_EmailAddress;
	CString m_PhoneNumber;
	CString m_FirstName;
	CString m_LastName;
	CString m_Address;
	CString m_Password;
	CString m_Password2;
	afx_msg void OnBnClickedOk();
	int CheckValidation();
	afx_msg void OnEnChangeEdit8();
	CString m_creditcardname;
	CDateTimeCtrl m_expirationdatectrl;
	CString m_nameoncard;
	CString m_securitycode;
	CString m_streetaddress;
	CString m_state;
	CString m_zipcode;
	virtual BOOL OnInitDialog();
	COleDateTime m_expirationdate;
};
