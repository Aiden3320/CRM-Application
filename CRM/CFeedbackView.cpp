// CFeedbackView.cpp : implementation file
//

#include "pch.h"
#include "CRM.h"
#include "afxdialogex.h"
#include "CFeedbackView.h"


// CFeedbackView dialog

IMPLEMENT_DYNAMIC(CFeedbackView, CDialogEx)

CFeedbackView::CFeedbackView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FEEDBACKVIEW, pParent)
	, m_detail(_T(""))
{

}

CFeedbackView::~CFeedbackView()
{
}

void CFeedbackView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_feedbacklist);
	DDX_Text(pDX, IDC_EDIT2, m_detail);
}


BEGIN_MESSAGE_MAP(CFeedbackView, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CFeedbackView::OnLvnItemchangedList1)
	ON_NOTIFY(HDN_ITEMCHANGED, 0, &CFeedbackView::OnHdnItemchangedList1)
	ON_BN_CLICKED(IDC_DELETEFEEDBACK, &CFeedbackView::OnBnClickedDeletefeedback)
END_MESSAGE_MAP()


// CFeedbackView message handlers


BOOL CFeedbackView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	//Feedback list init
	m_feedbacklist.init();
	adminAction.LoadFeedbackList(m_feedbacklist);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CFeedbackView::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if ((pNMListView->uChanged & LVIF_STATE)
		&& (pNMListView->uNewState & LVIS_SELECTED))
	{
		// do stuff
		UpdateData(true);


		//		int nIndex = m_feedbacklist.GetSelectionMark();
		int nIndex = pNMListView->iItem;
		if (nIndex >= 0)// Selected 
		{
			m_detail = m_feedbacklist.GetFeedbackByIndex(nIndex);
			UpdateData(false);
		}
	}
	*pResult = 0;
}


void CFeedbackView::OnHdnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);

	// TODO: Add your control notification handler code here
	*pResult = 0;
}

//Delete Feedbaks
void CFeedbackView::OnBnClickedDeletefeedback()
{
	int nIndex = m_feedbacklist.GetSelectionMark();
	
	if (nIndex < 0) return;

	if (MessageBox(L"Are you really gonna delete this feedback", L"Warnning", MB_ICONWARNING | MB_YESNO) == IDYES)
	{
		// Get Current Feedback
		CString feedback = m_feedbacklist.GetFeedbackByIndex(nIndex);
		// Get Current Feedback's submited time
		CString stime = m_feedbacklist.GetDateByIndex(nIndex);
		if (adminAction.DeleteFeedback(stime,feedback) == true)
		{
			//Delete Feedback in DB Success
			m_feedbacklist.DeleteFeedback(nIndex);
			m_detail = CString("");
			UpdateData(false);
		}
	}
}
	// TODO: Add your control notification handler code here

