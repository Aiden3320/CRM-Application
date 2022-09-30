// CFeedbackForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CFeedbackForm.h"


// CFeedbackForm dialog

IMPLEMENT_DYNAMIC(CFeedbackForm, CDialogEx)

CFeedbackForm::CFeedbackForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GIVEFEEDBACK, pParent)
	, m_feedback(_T(""))
{

}

CFeedbackForm::~CFeedbackForm()
{
}

void CFeedbackForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_feedback);
	DDV_MaxChars(pDX, m_feedback, 1000);
	DDX_Control(pDX, IDC_EDIT1, m_feedbackcontrol);
}


BEGIN_MESSAGE_MAP(CFeedbackForm, CDialogEx)
	ON_BN_CLICKED(IDC_BACK, &CFeedbackForm::OnBnClickedBack)
	ON_BN_CLICKED(IDC_GiveFeedback, &CFeedbackForm::OnBnClickedGivefeedback)
END_MESSAGE_MAP()


// CFeedbackForm message handlers


BOOL CFeedbackForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	//GetDlgItem(IDC_EDIT1)->SetFocus();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CFeedbackForm::OnBnClickedBack()
{
	OnCancel();
	// TODO: Add your control notification handler code here
}

//
void CFeedbackForm::OnBnClickedGivefeedback()
{
	UpdateData(true);
	//Submit Feedback
	userAction.SubmitFeedbaack(m_feedback);
	// TODO: Add your control notification handler code here
}
