#pragma once
#include "afxdialogex.h"


// cw1 对话框

class cw1 : public CDialogEx
{
	DECLARE_DYNAMIC(cw1)

public:
	cw1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~cw1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_pswd;
};

extern CString m_state;
