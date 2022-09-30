#include "pch.h"
#include "CInventoryList.h"
CInventoryList::CInventoryList()
{

}
CInventoryList::CInventoryList(const CInventoryList& A)
{
	int i;
	for (i = 0; i < A.data.GetCount(); i++)
	{
		AddInventory(A.data.GetAt(A.data.FindIndex(i)));
	}
}

CInventoryList& CInventoryList::operator = (const CInventoryList & A)
{
	data.RemoveAll();
	int i;
	for (i = 0; i < A.data.GetCount(); i++)
	{
		AddInventory(A.data.GetAt(A.data.FindIndex(i)));
	}
	return *this;
}
int CInventoryList::findByName(const CString& str)
{
	int i;
	CInventory cur;
	for(i = 0 ;i<data.GetCount();i++ )
	{
		cur = data.GetAt(data.FindIndex(i));
		if (cur.name == str) break;
	}
	if (i == data.GetCount()) return -1;
	return i;
}

void CInventoryList::AddInventory(const CInventory newOne)
{
	int i;
	for (i = 0; i < data.GetCount(); i++)
	{
		CInventory  cur = data.GetAt(data.FindIndex(i));
		if (cur.name == newOne.name)
		{
			cur.count += newOne.count;
			data.SetAt(data.FindIndex(i), cur);
			break;
		}
	}
	if (i == data.GetCount()) //Not found
	{
		data.AddTail(newOne);
	}

}

int CInventoryList::fromString(CString src)
{
	// TODO: Add your implementation code here.
	data.RemoveAll();
	int nTokenPos = 0;
	CString strToken = src.Tokenize(_T("#"), nTokenPos);

	while (!strToken.IsEmpty())
	{
		// do something with strToken
		// ....
		CInventory cur; cur.fromString(strToken);
		data.AddTail(cur);
		strToken = src.Tokenize(_T("#"), nTokenPos);
	}
	return 1;
}


CString CInventoryList::toString()
{
	// TODO: Add your implementation code here.
	int i;
	POSITION pos = data.GetHeadPosition();
	CString res;
	while (pos)
	{
		CInventory cur = data.GetNext(pos);
		res.Append(cur.toStrong());
		res.AppendChar('#');
	}
	return res;
}


int CInventoryList::GetCount()
{
	// TODO: Add your implementation code here.
	return data.GetCount();
}


CInventory CInventoryList::GetAt(int i)
{
	// TODO: Add your implementation code here.
	return data.GetAt(data.FindIndex(i));
}
