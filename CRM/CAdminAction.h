#pragma once
#include "pch.h"
#include "CFeedBackListView.h"
class CAdminAction
{
public:

	int LoadFeedbackList(CFeedBackListView& listctrl);
	int DeleteFeedback(CString, CString);
	int LoadUsers(CListBox& list);
	int LoadUserByEmail(CString email, CUser& user);
	int DeleteUserByEmail(CString email);
};

