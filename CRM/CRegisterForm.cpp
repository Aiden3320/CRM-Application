// CRegisterForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CRegisterForm.h"

// CRegisterForm dialog

IMPLEMENT_DYNAMIC(CRegisterForm, CDialogEx)

CRegisterForm::CRegisterForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REGISTRATION, pParent)
	, m_EmailAddress(_T(""))
	, m_PhoneNumber(_T(""))
	, m_FirstName(_T(""))
	, m_LastName(_T(""))
	, m_Address(_T(""))
	, m_Password(_T(""))
	, m_Password2(_T(""))
	, m_creditcardname(_T(""))
	, m_nameoncard(_T(""))
	, m_securitycode(_T(""))
	, m_streetaddress(_T(""))
	, m_state(_T(""))
	, m_zipcode(_T(""))
	, m_expirationdate(COleDateTime::GetCurrentTime())
{
}

CRegisterForm::~CRegisterForm()
{
}

void CRegisterForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EmailAddress);
	DDX_Text(pDX, IDC_EDIT2, m_PhoneNumber);
	DDX_Text(pDX, IDC_EDIT3, m_FirstName);
	DDX_Text(pDX, IDC_EDIT4, m_LastName);
	DDX_Text(pDX, IDC_EDIT5, m_Address);
	DDX_Text(pDX, IDC_EDIT6, m_Password);
	DDX_Text(pDX, IDC_EDIT7, m_Password2);
	DDX_Text(pDX, IDC_EDIT8, m_creditcardname);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_expirationdatectrl);
	DDX_Text(pDX, IDC_EDIT9, m_nameoncard);
	DDX_Text(pDX, IDC_EDIT11, m_securitycode);
	DDX_Text(pDX, IDC_EDIT12, m_streetaddress);
	DDX_Text(pDX, IDC_EDIT13, m_state);
	DDX_Text(pDX, IDC_EDIT14, m_zipcode);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_expirationdate);
}


BEGIN_MESSAGE_MAP(CRegisterForm, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRegisterForm::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT8, &CRegisterForm::OnEnChangeEdit8)
END_MESSAGE_MAP()


// CRegisterForm message handlers

//Button On
void CRegisterForm::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if (!CheckValidation()) return;


	CDialogEx::OnOK();
}

//Check Input Validation
int CRegisterForm::CheckValidation()
{
	UpdateData(true);
	if (m_EmailAddress.IsEmpty()){
		MessageBox(L"Email Address is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_PhoneNumber.IsEmpty()) { 
		MessageBox(L"Phone Number is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_FirstName.IsEmpty()) {
		MessageBox(L"First Name is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_LastName.IsEmpty()) {
		MessageBox(L"Last Name is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_Address.IsEmpty()) {
		MessageBox(L"Address is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_PhoneNumber.IsEmpty()) {
		MessageBox(L"Phone Number is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_Password.IsEmpty()) {
		MessageBox(L"Password is required", L"Format Error", MB_OK);
		return 0;
	}
	if (m_Password2.IsEmpty()) {
		MessageBox(L"Confirm Password is required", L"Format Error", MB_OK|MB_ICONWARNING);
		return 0;
	}
	if (m_Password != m_Password2) {
		MessageBox(L"Password does not match", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	if (m_nameoncard.IsEmpty()){
		MessageBox(L"Name on Card is required", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	if (m_creditcardname.IsEmpty()) {
		MessageBox(L"Credit Card Number is required", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	if (m_securitycode.IsEmpty()) {
		MessageBox(L"Security Code is required", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	if (m_streetaddress.IsEmpty()) {
		MessageBox(L"Street Address is required", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	if (m_state.IsEmpty()) {
		MessageBox(L"State is required", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	if (m_zipcode.IsEmpty()) {
		MessageBox(L"Zip Code is required", L"Format Error", MB_OK | MB_ICONWARNING);
		return 0;
	}
	userAction.UserRegister(m_EmailAddress, m_PhoneNumber, m_FirstName, m_LastName, m_Address, m_Password
	,m_nameoncard,m_creditcardname,m_expirationdate.Format(L"%Y-%m-%d"), m_securitycode, m_streetaddress, m_state, m_zipcode);
	return 1;
	// TODO: Add your implementation code here.
}


void CRegisterForm::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


BOOL CRegisterForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_expirationdatectrl.SetFormat(L"yyyy-MM-dd");
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
