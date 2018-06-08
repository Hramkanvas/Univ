#include <windows.h>
#include <tchar.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = ("MainFrame");
int APIENTRY WinMain(HINSTANCE This,
	HINSTANCE Prev, 
	LPTSTR cmd, 
	int mode) 
{
	HWND hWnd; 
	MSG msg; 
	WNDCLASS wc; 
				 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 
	wc.lpfnWndProc = WndProc; 
	wc.style = CS_HREDRAW | CS_VREDRAW; 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wc.lpszMenuName = NULL; 
	wc.cbClsExtra = 0; 
	wc.cbWndExtra = 0; 
					   
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClass(&wc)) return 0; 
									   
	hWnd = CreateWindow(WinName, 
		("Carcas"), 
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		HWND_DESKTOP, 
		NULL, 
		This, 
		NULL); 
	if (hWnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hWnd, mode); 
	UpdateWindow(hWnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg); 
	}
	return msg.wParam;
}
HPEN hpn = NULL;
BOOL fDraw = FALSE;
POINT ptPrevious = { 0 };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{ 
	HDC hdc;
	BOOL bRet = FALSE;
	BOOL bCmd = FALSE;
	int wmId = LOWORD(wParam);
	int wmEvent = HIWORD(wParam);
	switch (message)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		hpn = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
		SelectObject(hdc, hpn);
		break;
	case WM_LBUTTONDOWN:
		fDraw = TRUE;
		ptPrevious.x = LOWORD(lParam);
		ptPrevious.y = HIWORD(lParam);
		break;

	case WM_LBUTTONUP:
		if (fDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
			LineTo(hdc, LOWORD(lParam), HIWORD(lParam));
			ReleaseDC(hWnd, hdc);
			fDraw = FALSE;//
		}
		
		break;

	case WM_MOUSEMOVE:
		if (fDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
			LineTo(hdc, ptPrevious.x = LOWORD(lParam),
				ptPrevious.y = HIWORD(lParam));
			ReleaseDC(hWnd, hdc);
		}
		
		break;
	case WM_DESTROY: PostQuitMessage(0);
		break; 
			   
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}