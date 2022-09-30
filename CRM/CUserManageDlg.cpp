// CUserManageDlg.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CUserManageDlg.h"


// CUserManageDlg dialog

IMPLEMENT_DYNAMIC(CUserManageDlg, CDialogEx)

CUserManageDlg::CUserManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMINUSERMANAGE, pParent)
{

}

CUserManageDlg::~CUserManageDlg()
{
}

void CUserManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_userlist);
}


BEGIN_MESSAGE_MAP(CUserManageDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CUserManageDlg::OnLbnUserSelChange)
	ON_BN_CLICKED(IDC_DELETEUSER, &CUserManageDlg::OnBnClickedDeleteuser)
END_MESSAGE_MAP()


// CUserManageDlg message handlers


BOOL CUserManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	adminAction.LoadUsers(m_userlist);

	userprofile = new CUserProfile();
	userprofile->Create(IDD_ProfileView, this);

	CRect rect;
	userprofile->GetWindowRect(rect);
	//rect.bottom = rect.top + dy;

	// Set User Profile Dialog's position

	userprofile->MoveWindow(rect.left+120,rect.top,800,500);
	// Disable User Profile Dialogs' Back Button
	userprofile->GetDlgItem(IDCANCEL)->EnableWindow(0);
	userprofile->GetDlgItem(IDCANCEL)->ShowWindow(SW_HIDE);
	userprofile->ShowWindow(SW_SHOW);

	UpdateData(false);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

//Change User Selection
void CUserManageDlg::OnLbnUserSelChange()
{
	UpdateData(true);
	int nIndex = m_userlist.GetCurSel();
	if (nIndex < 0) return;
	CString useremail;
	//Get Current Selected Email Address
	m_userlist.GetText(nIndex, useremail);
	CUser selUser;
	//Load Current Selected User Info with email address
	adminAction.LoadUserByEmail(useremail, selUser);
	userprofile->init(selUser);
	userprofile->UpdateData(false);
	// TODO: Add your control notification handler code here
}

//Delete User
void CUserManageDlg::OnBnClickedDeleteuser()
{
	UpdateData(true);
	int nIndex = m_userlist.GetCurSel();
	if (nIndex < 0) return;
	if (MessageBox(L"Are you really gonna delete this user?", L"Warnning", MB_YESNO | MB_ICONWARNING) == IDYES)
	{
		CString useremail;
		m_userlist.GetText(nIndex, useremail);
		if (adminAction.DeleteUserByEmail(useremail) == true)
		{
			//Clear User profile
			userprofile->init(CUser());
			userprofile->UpdateData(false);

			//Delete in the List Box
			m_userlist.DeleteString(nIndex);
		}
	}
	// TODO: Add your control notification handler code here
}


void CUserManageDlg::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogEx::PostNcDestroy();
}


void CUserManageDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (userprofile) userprofile->DestroyWindow();
	CDialogEx::OnCancel();
}
