// CPaymentMethodForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CPaymentMethodForm.h"


// CPaymentMethodForm dialog

IMPLEMENT_DYNAMIC(CPaymentMethodForm, CDialogEx)

CPaymentMethodForm::CPaymentMethodForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAYMENTMETHODFORM, pParent)
{

}

CPaymentMethodForm::~CPaymentMethodForm()
{
}

void CPaymentMethodForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT8, pay.pNumber);
	DDX_Text(pDX, IDC_EDIT9, pay.pName);
	DDX_Text(pDX, IDC_EDIT11, pay.pSecurityCode);
	DDX_Text(pDX, IDC_EDIT13, pay.pState);
	DDX_Text(pDX, IDC_EDIT12, pay.pStreetAddress);
	DDX_Text(pDX, IDC_EDIT14, pay.pZipCode);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_expdate);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_expdatectrl);
}


BEGIN_MESSAGE_MAP(CPaymentMethodForm, CDialogEx)
END_MESSAGE_MAP()


// CPaymentMethodForm message handlers


void CPaymentMethodForm::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(true);
	pay.pExpDate = m_expdate.Format(L"%Y-%m-%d");
	CDialogEx::OnOK();
}


BOOL CPaymentMethodForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_expdatectrl.SetFormat(L"yyyy-MM-dd");
	m_expdate.ParseDateTime(pay.pExpDate);
	UpdateData(false);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
