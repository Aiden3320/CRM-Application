#pragma once
#include "afxdialogex.h"


// CFeedbackForm dialog

class CFeedbackForm : public CDialogEx
{
	DECLARE_DYNAMIC(CFeedbackForm)

public:
	CFeedbackForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFeedbackForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIVEFEEDBACK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_feedback;
	virtual BOOL OnInitDialog();
	CEdit m_feedbackcontrol;
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedGivefeedback();
};
