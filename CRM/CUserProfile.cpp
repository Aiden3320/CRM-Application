// CUserProfile.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CUserProfile.h"
#include "CUser.h"
#include "CInventoryList.h"
#include "CPaymentMethodForm.h"
#include "CPurchaseHistoryForm.h"
// CUserProfile dialog

IMPLEMENT_DYNAMIC(CUserProfile, CDialogEx)

CUserProfile::CUserProfile(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ProfileView, pParent)
	, m_changPassword(FALSE)
	, m_oldPassword(_T(""))
	, m_password(_T(""))
	, m_password2(_T(""))
{

}

CUserProfile::~CUserProfile()
{
}

void CUserProfile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user.email);
	DDX_Text(pDX, IDC_EDIT2, user.phoneNumber);
	DDX_Text(pDX, IDC_EDIT3, user.firstName);
	DDX_Text(pDX, IDC_EDIT4, user.lastName);
	DDX_Text(pDX, IDC_EDIT5, user.address);

	DDX_Check(pDX, IDC_CHECK1, m_changPassword);
	DDX_Text(pDX, IDC_OLDPASSWORD, m_oldPassword);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_PASSWORD2, m_password2);
}


BEGIN_MESSAGE_MAP(CUserProfile, CDialogEx)
	ON_BN_CLICKED(IDC_UPDATEINFORMATION, &CUserProfile::OnBnClickedUpdateinformation)
	ON_BN_CLICKED(IDC_EDITPAYMENTMETHOD, &CUserProfile::OnBnClickedEditpaymentmethod)
	ON_BN_CLICKED(IDC_PURCHASEHISTORY, &CUserProfile::OnBnClickedPurchasehistory)
	ON_BN_CLICKED(IDC_CHANGEPASSWORD, &CUserProfile::OnBnClickedChangepassword)
END_MESSAGE_MAP()


// CUserProfile message handlers


BOOL CUserProfile::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
void CUserProfile::init(CUser cuser)
{
	this->user = cuser;

	UpdateData(false);

}

void CUserProfile::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogEx::PostNcDestroy();
	
}


void CUserProfile::OnBnClickedUpdateinformation()
{
	//Update User Information
	UpdateData(true);
	if (user.email == CString(""))
		return;
	//Formats exp date
	//Update user information
	userAction.UserUpdate(user.email, user.password, user);
	// TODO: Add your control notification handler code here
}


void CUserProfile::OnBnClickedEditpaymentmethod()
{
	CPaymentMethodForm dlg;
	dlg.pay = user.pay;
	if (dlg.DoModal() == IDOK)
	{
		user.pay = dlg.pay;

	}
	// TODO: Add your control notification handler code here
}


void CUserProfile::OnBnClickedPurchasehistory()
{
	CPurchaseHistoryForm dlg;
	dlg.m_InventoryList = user.list;
	dlg.DoModal();
	
	// TODO: Add your control notification handler code here
}

// Change Password
void CUserProfile::OnBnClickedChangepassword()
{
/*	UpdateData(true);
	if (m_changPassword)
	{
		GetDlgItem(IDC_OLDPASSWORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PASSWORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_PASSWORD2)->ShowWindow(SW_HIDE);
	}
	else
	{
		GetDlgItem(IDC_OLDPASSWORD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PASSWORD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_PASSWORD2)->ShowWindow(SW_SHOW);

	}*/
	// TODO: Add your control notification handler code here
}
