
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  
#define IDC_MAIN_EDIT 101

const char g_szClassName[] = "myWindowClass";
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		HFONT hfDefault;
		HWND hEdit;
		hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE |
			ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			0, 0, 100, 100, hwnd, (HMENU)IDC_MAIN_EDIT, GetModuleHandle(NULL),
			NULL);
		if (hEdit == NULL)
			MessageBox(hwnd, "Could not create edit box.", "Error", MB_OK |
				MB_ICONERROR);
		hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
		SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE, 0));
	}
	break;
	case WM_SIZE:
	{
		HWND hEdit;
		RECT rcClient;
		GetClientRect(hwnd, &rcClient);
		hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
		SetWindowPos(hEdit, NULL, 0, 0, rcClient.right, rcClient.bottom,
			SWP_NOZORDER);
	}
	break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);


	wc.style = 0;
		  wc.lpfnWndProc = WndProc;
		  wc.cbClsExtra = 0;
		  wc.cbWndExtra = 0;
		  wc.hInstance = hInstance;
		  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		  wc.lpszMenuName = NULL;
		  wc.lpszClassName = g_szClassName;
		  wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		  if (!RegisterClassEx(&wc))
		  {
			  MessageBox(NULL, "Window Registration Failed!", "Error!",
				  MB_ICONEXCLAMATION | MB_OK);
			  return 0;
		  }
		  // Step 2: Creating the Window
		  hwnd = CreateWindowEx(
			  WS_EX_CLIENTEDGE,
			  g_szClassName,
			  "The title of my window",
			  WS_OVERLAPPEDWINDOW,
			  CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
			  NULL, NULL, hInstance, NULL);
		  
		  if (hwnd == NULL)
		  {
			  MessageBox(NULL, "Window Creation Failed!", "Error!",
				  MB_ICONEXCLAMATION | MB_OK);
			  return 0;
		  }
		  ShowWindow(hwnd, nCmdShow);
		  UpdateWindow(hwnd);

		  // Step 3: The Message Loop
		  while (GetMessage(&Msg, NULL, 0, 0) > 0)
		  {
			  TranslateMessage(&Msg);
			  DispatchMessage(&Msg);
		  }
		  return Msg.wParam;
}