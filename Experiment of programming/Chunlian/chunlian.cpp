#include <windows.h>

void InvertBlock(HWND hwnd, POINT ptBeg, POINT ptEnd) {
    HDC hdc;
    hdc = CreateDC(L"DISPLAY", NULL, NULL, NULL);
    ClientToScreen(hwnd, &ptBeg); // ����������ת��Ϊ��Ļ����
    ClientToScreen(hwnd, &ptEnd);
    PatBlt(hdc, ptBeg.x, ptBeg.y, ptEnd.x - ptBeg.x, ptEnd.y - ptBeg.y, DSTINVERT);
    DeleteDC(hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static BOOL operate = FALSE, ready = TRUE;
    static POINT BeginP, EndP;
    static RECT rect = { 0, 0, 0, 0 };
    HDC hdc;
    PAINTSTRUCT PtStr;
    HBRUSH hBrush;

    switch (message) {
    case WM_LBUTTONDOWN:
        if ((!operate) && ready) {
            operate = TRUE;
            ready = FALSE;
            SetCapture(hwnd);
            SetCursor(LoadCursor(NULL, IDC_CROSS));
            BeginP.x = LOWORD(lParam);
            BeginP.y = HIWORD(lParam);
        }
        return 0;

    case WM_MOUSEMOVE:
        if (operate) {
            EndP.x = LOWORD(lParam);
            EndP.y = HIWORD(lParam);
            rect.left = BeginP.x < EndP.x ? BeginP.x : EndP.x;
            rect.right = BeginP.x > EndP.x ? BeginP.x : EndP.x;
            rect.top = BeginP.y < EndP.y ? BeginP.y : EndP.y;
            rect.bottom = BeginP.y > EndP.y ? BeginP.y : EndP.y;
            SetCursor(LoadCursor(NULL, IDC_WAIT));
            InvalidateRect(hwnd, NULL, TRUE);
        }
        return 0;

    case WM_LBUTTONUP:
        if (operate) {
            operate = FALSE;
            SetCursor(LoadCursor(NULL, IDC_WAIT));
            InvalidateRect(hwnd, NULL, TRUE);
            SetCursor(LoadCursor(NULL, IDC_ARROW));
            ReleaseCapture();
        }
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &PtStr);
        if (ready == FALSE) {
            hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
            SelectObject(hdc, hBrush);
            Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
            DeleteObject(hBrush);
        }
        else {
            GetClientRect(hwnd, &rect);
            Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
        }
        EndPaint(hwnd, &PtStr);
        return 0;

    case WM_LBUTTONDBLCLK:
        if (ready == FALSE) {
            // ���������쵽��������
            GetClientRect(hwnd, &rect);
            ready = TRUE;
            InvalidateRect(hwnd, NULL, TRUE);
        }
        return 0;

    case WM_RBUTTONDOWN:
        if (ready == FALSE) {
            // �����ɫ���Σ��ָ����ڵ���ʼ״̬�����ָ�Ϊʮ����
            ready = TRUE;
            InvalidateRect(hwnd, NULL, TRUE);
            SetCursor(LoadCursor(NULL, IDC_ARROW));
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // ���崰����
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"MouseApp";

    // ע�ᴰ����
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, L"����ע��ʧ��!", L"����", MB_ICONERROR);
        return 1;
    }

    // ��������
    HWND hwnd = CreateWindow(L"MouseApp", L"Mouse Application", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL);

    if (!hwnd) {
        MessageBox(NULL, L"���ڴ���ʧ��!", L"����", MB_ICONERROR);
        return 1;
    }

    // ��ʾ����
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // ��Ϣѭ��
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
