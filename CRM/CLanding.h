#pragma once
#include "afxdialogex.h"


// CLanding dialog

class CLanding : public CDialogEx
{
	DECLARE_DYNAMIC(CLanding)

public:
	CLanding(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CLanding();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LANDING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
