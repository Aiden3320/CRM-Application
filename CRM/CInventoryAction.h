#pragma once
#include "CInventory.h"
#include "CInventoryListView.h"
class CInventoryAction
{

public:
	int LoadToList(CInventoryListView& listctrl);
	int AddInventory(const CInventory& item);
	int ModifyInventory(const CInventory& oldOne, const CInventory& newOne);
	int RemoveInventory(const CInventory& curOne);
};

