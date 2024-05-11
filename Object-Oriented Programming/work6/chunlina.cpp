#include <windows.h>
#include <vector>
#include <string>

void DrawTextVertical(HDC hdc, const char *text, int len, int x, int y) {
    SIZE size;
    GetTextExtentPoint32A(hdc, text, len, &size);

    for (int i = 0; i < len; i++) {
        // 绘制每个字符
        RECT rect = {x, y + i * size.cy, x + size.cx, y + (i + 1) * size.cy};
        TextOutA(hdc, x, y + i * size.cy, &text[i], 1);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HFONT hFont;
    static std::string upperCouplet = "春到百花香满地";
    static std::string lowerCouplet = "时来万事喜临门";
    static std::string horizontalInscription = "迎春接福";

    switch (msg) {
    case WM_CREATE: {
        LOGFONT lf;
        memset(&lf, 0, sizeof(LOGFONT));
        lf.lfHeight = 30;
        lf.lfWeight = FW_BOLD;
        strcpy(lf.lfFaceName, "SimSun");
        hFont = CreateFontIndirect(&lf);
        break;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 设置背景色为白色
        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

        // 设置文字颜色为黄色
        SetTextColor(hdc, RGB(255, 255, 0));
        // 设置背景色为红色
        SetBkColor(hdc, RGB(255, 0, 0));

        SelectObject(hdc, hFont);
        SetBkMode(hdc, OPAQUE);

        // 绘制上联
        DrawTextVertical(hdc, upperCouplet.c_str(), upperCouplet.length(), 100, 50);
        // 绘制下联
        DrawTextVertical(hdc, lowerCouplet.c_str(), lowerCouplet.length(), 400, 50);
        // 绘制横批
        TextOutA(hdc, 300, 50, horizontalInscription.c_str(), horizontalInscription.length());

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY:
        DeleteObject(hFont);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "GDIWindow";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, "Spring Couplet", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}