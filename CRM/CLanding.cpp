// CLanding.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CLanding.h"
#include "CRegisterForm.h"
#include "CLoginForm.h"
// CLanding dialog

IMPLEMENT_DYNAMIC(CLanding, CDialogEx)

CLanding::CLanding(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LANDING, pParent)
{

}

CLanding::~CLanding()
{
}

void CLanding::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLanding, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CLanding::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLanding::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLanding message handlers


BOOL CLanding::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

// Register Button Clicked 
void CLanding::OnBnClickedButton2()
{
	CRegisterForm dlg;
	if (dlg.DoModal() == IDOK)
	{

	}

	// TODO: Add your control notification handler code here

}

// Log In Button Clicked
void CLanding::OnBnClickedButton1()
{
	CLoginForm dlg;
	if (dlg.DoModal() == IDOK)
	{
		CLanding::OnOK();
	}
	// TODO: Add your control notification handler code here
}
