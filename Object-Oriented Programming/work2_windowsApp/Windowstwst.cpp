#include <windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    WNDCLASS wndcls; // ����һ��������
    TCHAR *lpszClassName = TEXT("����");
    TCHAR *lpszTitle = TEXT("��������ϰ");
    wndcls.cbClsExtra = 0;                                      // ��Ķ����ڴ棬Ĭ��Ϊ0����
    wndcls.cbWndExtra = 0;                                      // ���ڵĶ����ڴ棬Ĭ��Ϊ0����
    wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ��ȡ��ˢ����������ص�HGDIOBJ����ǿ������ת����
    wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);               // ���ù��
    wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);                   // ���ô������Ͻǵ�ͼ��
    wndcls.hInstance = hInstance;                               // ���ô���������Ӧ�ó���ʵ��
    wndcls.lpfnWndProc = WndProc;                               // ���ô���Ļص���������ʱûд��������ΪNULL�����油��
    wndcls.lpszClassName = lpszClassName;                       // ���ô��������
    wndcls.lpszMenuName = NULL;                                 // ���ô���Ĳ˵�,û�У���NULL
    wndcls.style = CS_HREDRAW | CS_VREDRAW;                     // ���ô�����Ϊˮƽ�ػ��ʹ�ֱ�ػ�
    if (!RegisterClass(&wndcls))
    {
        MessageBox(NULL, TEXT("����ע�ᴰ����"), TEXT("����"), MB_ICONERROR);
        return FALSE;
    } // �����ϵͳע�ᴰ��
    HWND hwnd = CreateWindow(lpszClassName, lpszTitle,
                             WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
                             //CW_USEDEFAULT, CW_USEDEFAULT,
                             0, 0,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, TEXT("���ܴ�������"), TEXT("����"), MB_ICONERROR);
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
	switch (message)//ͨ���ж���Ϣ������Ϣ��Ӧ
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);//���ٴ��ڲ�����WM_DESTROY��Ϣ�����ǳ���û���˳�
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//����WM_QUIT��Ϣ��������Ϣѭ��
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);//�Բ�����Ȥ����Ϣ����ȱʡ���������иô��룬�������������
	}
	return 0;

}