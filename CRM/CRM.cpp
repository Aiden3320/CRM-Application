
// CRM.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "CRM.h"
#include "CRMDlg.h"
#include "CLanding.h"
#include "mysqlwrapper.h"
#include "CAdminDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCRMApp
#define APPLICATION_INSTANCE_MUTEX_NAME L"{BA49C45E-B29A-4359-A07C-51B65B5571AD}"
BEGIN_MESSAGE_MAP(CCRMApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCRMApp construction

CCRMApp::CCRMApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CCRMApp object
CInventoryAction inventoryAction;
CAdminAction adminAction;
CUserAction userAction;
CUser curUser;
CCRMApp theApp;
MySqlWrapper sql;

// CCRMApp initialization

BOOL CCRMApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	HANDLE hMutexOneInstance(::CreateMutex(NULL, TRUE, APPLICATION_INSTANCE_MUTEX_NAME));
	bool bAlreadyRunning((::GetLastError() == ERROR_ALREADY_EXISTS));
	if (hMutexOneInstance == NULL || bAlreadyRunning)
	{
		if (hMutexOneInstance)
		{
			::ReleaseMutex(hMutexOneInstance);
			::CloseHandle(hMutexOneInstance);
		}

		return FALSE;
		//throw std::exception("The application is already running");
	}

	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	//For test

	const char* server = "localhost";
	const char* user = "root";
	const char* password = "";
	const char* database = "myapp";


	sql.init();

	if (sql.connect(server, user, password, database, 3305) == false) {
		MessageBox(NULL, L"DB Connect error", L"Error", MB_OK);
		return FALSE;
	}
	else
	{
		MessageBox(NULL, L"DB Connect Success", L"Success", MB_OK);
	}

/*	CLanding ldlg;

	m_pMainWnd = &ldlg;
	INT_PTR nResponse = ldlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}
	*/
	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	LandingDlg();
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}





int CCRMApp::LandingDlg()
{
	CLanding ldlg;
	if (ldlg.DoModal() == IDOK)
	{
		if (curUser.role == 1)//Admin
		{
			CAdminDlg dlg;
			dlg.DoModal();
		}
		else if (curUser.role == 2)//Customer
		{
			CCRMDlg dlg;
			dlg.DoModal();
		}
		else;
	}
	// TODO: Add your implementation code here.
	return 0;
}
