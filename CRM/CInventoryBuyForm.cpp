// CInventoryBuyForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CInventoryBuyForm.h"


// CInventoryBuyForm dialog

IMPLEMENT_DYNAMIC(CInventoryBuyForm, CDialogEx)

CInventoryBuyForm::CInventoryBuyForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVENTORYBUYFORM, pParent)
	, m_cost(0)
	, m_count(1)
	, m_total(0)
{

}

CInventoryBuyForm::~CInventoryBuyForm()
{
}

void CInventoryBuyForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_cost);
	DDX_Text(pDX, IDC_EDIT2, m_count);
	DDX_Text(pDX, IDC_EDIT3, m_total);
}


BEGIN_MESSAGE_MAP(CInventoryBuyForm, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInventoryBuyForm::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CInventoryBuyForm::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CInventoryBuyForm message handlers


BOOL CInventoryBuyForm::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(true);
	return CDialogEx::DestroyWindow();
}


void CInventoryBuyForm::OnBnClickedOk()
{

	//Check if inventory is enhough
	if (m_maxCount < m_count)
	{
		MessageBox(L"Inventory is not enhough", L"Error", MB_OK);
		return;
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CInventoryBuyForm::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(true);
	m_total = m_cost * m_count;
	UpdateData(false);
	// TODO:  Add your control notification handler code here
}
