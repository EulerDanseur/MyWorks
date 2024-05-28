
// MFC_hw1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC_hw1.h"
#include "MFC_hw1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFChw1Dlg 对话框



CMFChw1Dlg::CMFChw1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_HW1_DIALOG, pParent)
	, m_static(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFChw1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT, m_static);
}

BEGIN_MESSAGE_MAP(CMFChw1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFChw1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFChw1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK3, &CMFChw1Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_RADIO1, &CMFChw1Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFChw1Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFChw1Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_CHECK4, &CMFChw1Dlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK2, &CMFChw1Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFChw1Dlg::OnBnClickedCheck1)
	ON_STN_CLICKED(IDC_TEXT, &CMFChw1Dlg::OnStnClickedText)
END_MESSAGE_MAP()


// CMFChw1Dlg 消息处理程序

BOOL CMFChw1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO2);
	CheckRadioButton(IDC_CHECK2, IDC_CHECK2, IDC_CHECK2);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFChw1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFChw1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFChw1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFChw1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	//界面回到初始状态
	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO2);
	CheckRadioButton(IDC_CHECK1, IDC_CHECK4, IDC_CHECK1);
	m_static = L"";//清空文本内容
	UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);

}


void CMFChw1Dlg::OnBnClickedButton2()
{
		// TODO: 在此添加控件通知处理程序代码
		CString str = L"用户的选择如下：\n内存：", str_rad, str_chk1, str_chk2, str_chk3, str_chk4;

		//获取单选按钮选中ID
		int memory = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO3);

		//获取被选中单选按钮的内容
		GetDlgItemText(memory, str_rad);

		//依次检查四个复选框是否被选中，如果选中，则获取其内容
		if (IsDlgButtonChecked(IDC_CHECK1) == 1) {
			GetDlgItemText(IDC_CHECK1, str_chk1);
		}
		if (IsDlgButtonChecked(IDC_CHECK2) == 1) {
			GetDlgItemText(IDC_CHECK2, str_chk2);
		}
		if (IsDlgButtonChecked(IDC_CHECK3) == 1) {
			GetDlgItemText(IDC_CHECK3, str_chk3);
		}
		if (IsDlgButtonChecked(IDC_CHECK4) == 1) {
			GetDlgItemText(IDC_CHECK4, str_chk4);
		}
		if (IsDlgButtonChecked(IDC_CHECK1) == 1) {
			GetDlgItemText(IDC_CHECK1, str_chk1);
		}

		//更新静态文本内容
		m_static = str + str_rad + L"，" + str_chk1 + str_chk2 + str_chk3 + str_chk4;
		UpdateData(FALSE);

		//使提交选择按钮为不可选状态
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
}


void CMFChw1Dlg::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFChw1Dlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFChw1Dlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFChw1Dlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFChw1Dlg::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFChw1Dlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFChw1Dlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMFChw1Dlg::OnStnClickedText() {

}