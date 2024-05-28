// cw1.cpp: 实现文件
//

#include "pch.h"
#include "MFC_hw2.h"
#include "afxdialogex.h"
#include "cw1.h"
#include "MFC_hw2Dlg.h"
// cw1 对话框

IMPLEMENT_DYNAMIC(cw1, CDialogEx)

cw1::cw1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
    , m_pswd(_T(""))
{

}

cw1::~cw1()
{
}

void cw1::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_TEXT, m_pswd);
}


BEGIN_MESSAGE_MAP(cw1, CDialogEx)
	ON_BN_CLICKED(IDOK, &cw1::OnBnClickedOk)
END_MESSAGE_MAP()


// cw1 消息处理程序


void cw1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
    UpdateData(TRUE); // 更新控件对应变量的值
    if (m_pswd == "123456")
    {
        // 进入主对话框界面
        m_state = "密码正确";
        UpdateData(FALSE); // 更新编辑框控件的显示值
    }
    else
    {
        // 弹出窗口提示用户名或密码不正确
        m_state = "密码错误";

        // 清空用户名和密码，便于重新输入
        m_pswd = "";
    }
}
