// CPurchaseHistoryForm.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CPurchaseHistoryForm.h"


// CPurchaseHistoryForm dialog

IMPLEMENT_DYNAMIC(CPurchaseHistoryForm, CDialogEx)

CPurchaseHistoryForm::CPurchaseHistoryForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PURCHASEHISTORYFORM, pParent)
	, m_total(0)
{

}

CPurchaseHistoryForm::~CPurchaseHistoryForm()
{
}

void CPurchaseHistoryForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_InventoryListView);
	DDX_Text(pDX, IDC_EDIT8, m_total);
}


BEGIN_MESSAGE_MAP(CPurchaseHistoryForm, CDialogEx)
END_MESSAGE_MAP()


// CPurchaseHistoryForm message handlers


BOOL CPurchaseHistoryForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	
	m_InventoryListView.init();
	m_InventoryListView.DeleteAllItems();
	for (int i = 0; i < m_InventoryList.GetCount(); i++)
	{
		CInventory cur = m_InventoryList.GetAt(i);
		m_InventoryListView.AddInventory(cur);
		m_total += cur.cost * cur.count;
	}
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
