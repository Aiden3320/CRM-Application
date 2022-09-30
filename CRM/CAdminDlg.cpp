// CAdminDlg.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CAdminDlg.h"
#include "CInventoryManage.h"

// CAdminDlg dialog

IMPLEMENT_DYNAMIC(CAdminDlg, CDialogEx)

CAdminDlg::CAdminDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMINDIALOG, pParent)
{
	inventory = NULL;
	feedback = NULL;
	usermanage = NULL;

}

CAdminDlg::~CAdminDlg()
{
}

void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialogEx)
	ON_COMMAND(ID_MENU_INVENTORYMANAGER, &CAdminDlg::OnMenuInventorymanager)
	ON_BN_CLICKED(IDC_LOGOUT, &CAdminDlg::OnBnClickedLogout)
	ON_COMMAND(ID_MENU_FEEDBACKS, &CAdminDlg::OnMenuFeedbacks)
	ON_COMMAND(ID_MENU_MANAGEUSERS, &CAdminDlg::OnMenuManageusers)
END_MESSAGE_MAP()


// CAdminDlg message handlers

//Inventory Manage
void CAdminDlg::OnMenuInventorymanager()
{
	// TODO: Add your command handler code here
	CloseOpenDialog();
	inventory = new CInventoryManage;
	inventory->Create(IDD_INVENTORYMANAGE, this);
	inventory->ShowWindow(SW_SHOW);
}

//Log Out
void CAdminDlg::OnBnClickedLogout()
{
	CloseOpenDialog();
	OnOK();
	//Opens LandingDlg again
	theApp.LandingDlg();
	// TODO: Add your control notification handler code here
}

//Feedback
void CAdminDlg::OnMenuFeedbacks()
{
	CloseOpenDialog();
	feedback = new CFeedbackView;
	feedback->Create(IDD_FEEDBACKVIEW, this);
	feedback->ShowWindow(SW_SHOW);
	// TODO: Add your command handler code here
}

//Manage Users
void CAdminDlg::OnMenuManageusers()
{

	CloseOpenDialog();
	usermanage = new CUserManageDlg;
	usermanage->Create(IDD_ADMINUSERMANAGE, this);
	usermanage->ShowWindow(SW_SHOW);
	// TODO: Add your command handler code here
}


//Close opened Dialogs
int CAdminDlg::CloseOpenDialog()
{

	if (inventory)inventory->DestroyWindow();
	if (feedback) feedback->DestroyWindow();
	if (usermanage) usermanage->DestroyWindow();
	// TODO: Add your implementation code here.
	return 0;
}

