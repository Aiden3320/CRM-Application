// CInventoryForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CInventoryForm.h"


// CInventoryForm dialog

IMPLEMENT_DYNAMIC(CInventoryForm, CDialogEx)

CInventoryForm::CInventoryForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVENTORYINFO, pParent)
	, m_name(_T(""))
	, m_cost(0)
	, m_count(0)
{

}

CInventoryForm::~CInventoryForm()
{
}

void CInventoryForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_cost);
	DDX_Text(pDX, IDC_EDIT3, m_count);
}


BEGIN_MESSAGE_MAP(CInventoryForm, CDialogEx)
END_MESSAGE_MAP()


// CInventoryForm message handlers


BOOL CInventoryForm::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(true);
	return CDialogEx::DestroyWindow();
}


int CInventoryForm::setCurrentInventory(CInventory cur)
{
	// TODO: Add your implementation code here.
	m_name = cur.name;
	m_cost = cur.cost;
	m_count = cur.count;
	return 0;
}
