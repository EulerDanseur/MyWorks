#include <windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    WNDCLASS wndcls; // 创建一个窗体类
    TCHAR *lpszClassName = TEXT("窗口");
    TCHAR *lpszTitle = TEXT("第三章练习");
    wndcls.cbClsExtra = 0;                                      // 类的额外内存，默认为0即可
    wndcls.cbWndExtra = 0;                                      // 窗口的额外内存，默认为0即可
    wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 获取画刷句柄（将返回的HGDIOBJ进行强制类型转换）
    wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);               // 设置光标
    wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);                   // 设置窗体左上角的图标
    wndcls.hInstance = hInstance;                               // 设置窗体所属的应用程序实例
    wndcls.lpfnWndProc = WndProc;                               // 设置窗体的回调函数，暂时没写，先设置为NULL，后面补上
    wndcls.lpszClassName = lpszClassName;                       // 设置窗体的类名
    wndcls.lpszMenuName = NULL;                                 // 设置窗体的菜单,没有，填NULL
    wndcls.style = CS_HREDRAW | CS_VREDRAW;                     // 设置窗体风格为水平重画和垂直重画
    if (!RegisterClass(&wndcls))
    {
        MessageBox(NULL, TEXT("不能注册窗体类"), TEXT("错误"), MB_ICONERROR);
        return FALSE;
    } // 向操作系统注册窗体
    HWND hwnd = CreateWindow(lpszClassName, lpszTitle,
                             WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
                             //CW_USEDEFAULT, CW_USEDEFAULT,
                             0, 0,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, TEXT("不能创建窗体"), TEXT("错误"), MB_ICONERROR);
        return FALSE;
    }
    ShowWindow(hwnd, SW_NORMAL);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)//通过判断消息进行消息响应
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);//销毁窗口并发送WM_DESTROY消息，但是程序没有退出
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//发出WM_QUIT消息，结束消息循环
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);//对不感兴趣的消息进行缺省处理，必须有该代码，否则程序有问题
	}
	return 0;

}