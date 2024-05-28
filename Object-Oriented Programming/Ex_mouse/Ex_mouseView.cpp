
// Ex_mouseView.cpp: CExmouseView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex_mouse.h"
#endif

#include "Ex_mouseDoc.h"
#include "Ex_mouseView.h"
#include"afxwin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExmouseView

IMPLEMENT_DYNCREATE(CExmouseView, CView)

BEGIN_MESSAGE_MAP(CExmouseView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExmouseView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExmouseView 构造/析构

CExmouseView::CExmouseView() noexcept
{
	// TODO: 在此处添加构造代码

}

CExmouseView::~CExmouseView()
{
}

BOOL CExmouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExmouseView 绘图

void CExmouseView::OnDraw(CDC* /*pDC*/)
{
	CExmouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExmouseView 打印


void CExmouseView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExmouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExmouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExmouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CExmouseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExmouseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExmouseView 诊断

#ifdef _DEBUG
void CExmouseView::AssertValid() const
{
	CView::AssertValid();
}

void CExmouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExmouseDoc* CExmouseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExmouseDoc)));
	return (CExmouseDoc*)m_pDocument;
}
#endif //_DEBUG


// CExmouseView 消息处理程序
HWND hwnd;
RECT rect;
CPoint s_p;
CPoint p;

bool operate=FALSE;


void CExmouseView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	s_p = point;
	operate = TRUE;

}



void CExmouseView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HCURSOR cur = LoadCursor(NULL, IDC_CROSS);
	CView::OnLButtonUp(nFlags, point);

	SetCursor(cur);
	operate = FALSE;

}


void CExmouseView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC = GetDC();
	CView::OnMouseMove(nFlags, point);
	CBrush brush(RGB(170,180,190));
	CPoint p;
	HCURSOR cur0 = LoadCursor(NULL, IDC_CROSS);
	HCURSOR cur = LoadCursor(NULL, IDC_WAIT);

	SetCursor(cur0);
	p = point;
	pDC->SelectObject(brush);
	if (operate == TRUE) {
		SetCursor(cur);
		pDC->Rectangle(s_p.x, s_p.y, p.x, p.y);
	}


}


void CExmouseView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC = GetDC();
	CBrush brush(RGB(170,180,190));
	CView::OnLButtonDblClk(nFlags, point);
	GetClientRect(&rect);
	pDC->SelectObject(brush);
	pDC->Rectangle(rect.left,rect.top,rect.right,rect.bottom);



}



void CExmouseView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDown(nFlags, point);
	InvalidateRect(&rect);
}
