
// CRM.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CUserAction.h"
#include "CUser.h"
#include "CInventoryAction.h"
#include "CAdminAction.h"
// CCRMApp:
// See CRM.cpp for the implementation of this class
//

class CCRMApp : public CWinApp
{
public:
	CCRMApp();
public:

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	int LandingDlg();

	DECLARE_MESSAGE_MAP()
};
extern CInventoryAction inventoryAction;
extern CAdminAction adminAction;
extern CUserAction userAction;
extern CUser curUser;
extern MySqlWrapper sql;
extern CCRMApp theApp;