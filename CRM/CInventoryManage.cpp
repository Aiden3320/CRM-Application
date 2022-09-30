// CInventoryManage.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CInventoryManage.h"
#include "CInventoryForm.h"
#include "CInventory.h"
// CInventoryManage dialog

IMPLEMENT_DYNAMIC(CInventoryManage, CDialogEx)

CInventoryManage::CInventoryManage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVENTORYMANAGE, pParent)
{

}

CInventoryManage::~CInventoryManage()
{
}

void CInventoryManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_InventoryList);
}


BEGIN_MESSAGE_MAP(CInventoryManage, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CInventoryManage::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_ADD_INVENTORY, &CInventoryManage::OnBnClickedAddInventory)
	ON_BN_CLICKED(IDC_MODIFYINVENTORY, &CInventoryManage::OnBnClickedModifyinventory)
	ON_BN_CLICKED(IDC_REMOVEINVENTORY, &CInventoryManage::OnBnClickedRemoveinventory)
END_MESSAGE_MAP()


// CInventoryManage message handlers


void CInventoryManage::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

BOOL CInventoryManage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	//Set List Ctrl Propety
	m_InventoryList.init();
	inventoryAction.LoadToList(m_InventoryList);
	//
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

//Add Inventory
void CInventoryManage::OnBnClickedAddInventory()
{
	CInventoryForm mdlg;
	if (mdlg.DoModal() == IDOK)
	{
		
		if (inventoryAction.AddInventory(CInventory(mdlg.m_name, mdlg.m_cost, mdlg.m_count)) == 1)
		{
			//Success
			m_InventoryList.AddInventory(CInventory(mdlg.m_name, mdlg.m_cost, mdlg.m_count));
		}
	}
	// TODO: Add your control notification handler code here
}

//Modify Inventory
void CInventoryManage::OnBnClickedModifyinventory()
{
	CInventory cur;
	if (m_InventoryList.getCurrentInventory(cur) == true)
	{
		CInventoryForm mdlg;
		mdlg.setCurrentInventory(cur);
		if (mdlg.DoModal() == IDOK)
		{
			// Update Database
			CInventory newOne = CInventory(mdlg.m_name, mdlg.m_cost, mdlg.m_count);
			if (inventoryAction.ModifyInventory(cur, newOne ) == 1)
			{
				//Success
				m_InventoryList.ModifyInventory(cur, newOne);
			}
		}
	}
	// TODO: Add your control notification handler code here
}


void CInventoryManage::OnBnClickedRemoveinventory()
{
	CInventory cur;
	if (m_InventoryList.getCurrentInventory(cur) == true)
	{
		if (MessageBox(L"Are you really gonna delete the current Inventory", L"Warning", MB_OKCANCEL| MB_ICONWARNING) == IDOK)
		{
			if (inventoryAction.RemoveInventory(cur) == 1)
			{
				// Success
				m_InventoryList.RemoveInventory(cur);
			}
		}
	}
	// TODO: Add your control notification handler code here
}
