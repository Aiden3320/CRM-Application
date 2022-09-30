#pragma once
#include <afxcmn.h>
class CFeedBackListView :
    public CListCtrl
{
public:
    CList<CString> feedbacks;
    void AddData(int row, int col, CString str);

public:
    int init();
    CString GetFeedbackByIndex(int nIndex);
    int DeleteFeedback(int nIndex);
    CString GetDateByIndex(int nIndex);
};


