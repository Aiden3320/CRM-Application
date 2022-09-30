// CLoginForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CLoginForm.h"

// CLoginForm dialog

IMPLEMENT_DYNAMIC(CLoginForm, CDialogEx)

CLoginForm::CLoginForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, m_emailAddress(_T(""))
	, m_password(_T(""))
{

}

CLoginForm::~CLoginForm()
{
}

void CLoginForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_emailAddress);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}


BEGIN_MESSAGE_MAP(CLoginForm, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginForm::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoginForm message handlers

//Log In button
void CLoginForm::OnBnClickedOk()
{
	UpdateData(true);
	if (!CheckValidation()) return;

	//Log in with email and password
	if(!userAction.UserLogin(m_emailAddress, m_password))  return ;
	//Log In Successful 
	
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

//Check Validation for Input Form
int CLoginForm::CheckValidation()
{
	UpdateData(true);
	if (m_emailAddress.IsEmpty()){
		MessageBox(L"EmailAddress Field is required", L"Error", MB_OK);
		return 0;
	}
	if (m_password.IsEmpty()){
		MessageBox(L"Password Field is required", L"Error",MB_OK);
		return 0;
	}
	return 1;
	// TODO: Add your implementation code here.
	return 0;
}
