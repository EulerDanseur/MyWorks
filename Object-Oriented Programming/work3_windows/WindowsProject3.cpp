#include<windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam) ;

BOOL InitWindowsClass(HINSTANCE hInstance);
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow);//初始化窗口

HWND hWndMain;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
	MSG Message;
	if (!InitWindowsClass(hInstance)) return FALSE;
	if (!InitWindows(hInstance, iCmdShow)) return FALSE;
	while (GetMessage(&Message, 0, 0, 0)) //消息循环
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam) {
	HDC hDC; //定义指向设备的句柄
	HBRUSH hBrush; //定义指向画刷的句柄
	HPEN hPen; //定义指向画笔的句柄
	PAINTSTRUCT PtStr;//定义指向包含绘图信息的结构体变量

	switch (iMessage) //处理消息
	{
	case WM_PAINT: //处理绘图消息
		hDC = BeginPaint(hWnd, &PtStr);
		SetMapMode(hDC, MM_ANISOTROPIC); //设置映像模式
		hPen = (HPEN)GetStockObject(BLACK_PEN); //黑色画笔
		hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //画刷
		SelectObject(hDC, hBrush); //选择画刷
		SelectObject(hDC, hPen); //选择画笔
		RoundRect(hDC, 50, 120, 100, 200, 15, 15); //绘制圆角矩形
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //采用亮灰色画刷
		SelectObject(hDC, hBrush); //选择画刷
		Ellipse(hDC, 150, 50, 200, 150); //绘制椭圆
		hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH); //虚画刷
		SelectObject(hDC, hBrush); //选择画刷
		Pie(hDC, 250, 50, 300, 100, 250, 50, 300, 50); //绘制饼形
		EndPaint(hWnd, &PtStr); //结束绘图
		return 0;
	case WM_DESTROY: //结束应用程序
		PostQuitMessage(0); return 0;
	default: //其他消息处理程序
		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}



BOOL InitWindowsClass(HINSTANCE hInstance) //定义窗口类
{
	WNDCLASS WndClass;
	TCHAR lpszClassName[] = TEXT("WinFill");//窗口类名
	TCHAR lpszTitle[] = TEXT("填充示例程序");//窗口标题名
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, "END");
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClassName;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	return RegisterClass(&WndClass);
}
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow)//初始化窗口
{
	HWND hWnd;
	TCHAR lpszClassName[] = TEXT("WinFill");//窗口类名
	TCHAR lpszTitle[] = TEXT("填充示例程序");//窗口标题名
	hWnd = CreateWindow(
		lpszClassName, //生成窗口
		lpszTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd) return FALSE;
	hWndMain = hWnd;
	ShowWindow(hWnd, nCmdShow); //显示窗口
	UpdateWindow(hWnd);
	return TRUE;
}