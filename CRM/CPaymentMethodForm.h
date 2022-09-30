#pragma once
#include "afxdialogex.h"
#include "CPaymentMethod.h"

// CPaymentMethodForm dialog

class CPaymentMethodForm : public CDialogEx
{
	DECLARE_DYNAMIC(CPaymentMethodForm)

public:
	CPaymentMethodForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPaymentMethodForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAYMENTMETHODFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CPaymentMethod pay;
	CString m_creditcardnumber;
	CEdit m_nameoncard;
	CString m_securitycode;
	CString m_state;
	CString m_streetaddress;
	CString m_zipcode;
	COleDateTime m_expdate;
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	CDateTimeCtrl m_expdatectrl;
};
