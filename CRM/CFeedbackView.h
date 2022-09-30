#pragma once
#include "afxdialogex.h"
#include "CFeedBackListView.h"

// CFeedbackView dialog

class CFeedbackView : public CDialogEx
{
	DECLARE_DYNAMIC(CFeedbackView)

public:
	CFeedbackView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFeedbackView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FEEDBACKVIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CFeedBackListView m_feedbacklist;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CString m_detail;
	afx_msg void OnHdnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedDeletefeedback();
};
