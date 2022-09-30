// CInventoryPurchase.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CInventoryPurchase.h"
#include "CInventoryBuyForm.h"
#include "CInventoryList.h"
// CInventoryPurchase dialog

IMPLEMENT_DYNAMIC(CInventoryPurchase, CDialogEx)

CInventoryPurchase::CInventoryPurchase(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INVENTORYPURCHASE, pParent)
	, m_totalCost(0)
{

}

CInventoryPurchase::~CInventoryPurchase()
{
}

void CInventoryPurchase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_InventoryList);
	DDX_Control(pDX, IDC_LIST2, m_inventoryBasket);
	DDX_Text(pDX, IDC_EDIT1, m_totalCost);
}


BEGIN_MESSAGE_MAP(CInventoryPurchase, CDialogEx)
	ON_BN_CLICKED(IDC_INVENTORYBUY, &CInventoryPurchase::OnBnClickedInventorybuy)
	ON_BN_CLICKED(IDC_INVENTORYPURCHASE, &CInventoryPurchase::OnBnClickedInventorypurchase)
END_MESSAGE_MAP()


// CInventoryPurchase message handlers


BOOL CInventoryPurchase::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_InventoryList.init();
	inventoryAction.LoadToList(m_InventoryList);

	m_inventoryBasket.init();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

//Buy Inventory
void CInventoryPurchase::OnBnClickedInventorybuy()
{
	CInventoryBuyForm dlg;

	CInventory cur;
	//Check if there is any selction
	if (m_InventoryList.getCurrentInventory(cur) == 1)
	{
		dlg.m_cost = cur.cost;
		dlg.m_maxCount = cur.count;
		dlg.m_count = 1;
		dlg.m_total = cur.cost;
		if (dlg.DoModal() == IDOK)
		{
			// Add to check out page
			
			//Add to the Basket
			CInventory newOne = cur;
			newOne.count = dlg.m_count;
			m_inventoryBasket.AddInventory(newOne);
			newOne.count = cur.count - dlg.m_count;
			
			//Reduce the count of the current Inventory remaning
			m_InventoryList.ModifyInventory(cur, newOne);
			
			//Update totalCost

			m_totalCost += dlg.m_cost * dlg.m_count; 
			UpdateData(false);

			
		}
		
	}

	// TODO: Add your control notification handler code here
}

//Purchase all inventories in the basket
void CInventoryPurchase::OnBnClickedInventorypurchase()
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
	int nCount = m_inventoryBasket.GetItemCount();

	int i;
	CInventory cur;
	//userAction.getInventoryList()
	CInventoryList curList = curUser.list;
	for (i = 0; i < nCount; i++)
	{
		m_inventoryBasket.GetInventoryByIndex(cur,i);
		//Update User Profile
		curList.AddInventory(cur);
		//userAction.UserPurchaseInventory(customerInventory);

		//Update Database
		if (m_InventoryList.FindInventory(cur) == -1) //Bought all 
		{
			inventoryAction.RemoveInventory(cur);
		}
		else //Modify inventory
		{
			cur.count = m_InventoryList.GetInventoryCountByName(cur.name);

			//Modifyinventory finds inventory by name of first params
			inventoryAction.ModifyInventory(cur, cur);
		}
	}
	userAction.UserPurchaseInventory(curList);

	m_inventoryBasket.DeleteAllItems();
	m_totalCost = 0;
	UpdateData(false);
}

