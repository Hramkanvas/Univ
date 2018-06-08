// APIDrawMouse.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


// Global Variables:
HINSTANCE hInst;								// current instance

// Foward declarations of functions included in this code module:
LRESULT CALLBACK	DlgProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	InfProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	return DialogBox
		(
			(hInst = hInstance), 
			(LPCTSTR)IDD_DIALOG, 
			NULL, 
			(DLGPROC)DlgProc
		);
}

//
//  FUNCTION: DlgProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the Dialog window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
HPEN hPen = NULL;
BOOL fDraw= FALSE;
POINT ptPrevious = {0};
LRESULT CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	BOOL bRet = FALSE;
	BOOL bCmd = FALSE;
	int wmId    = LOWORD(wParam); 
	int wmEvent = HIWORD(wParam); 
	switch (message) 
	{
	case WM_INITDIALOG:
		hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
		//bRet = TRUE;
		break;
	case WM_COMMAND:
		// Parse the menu selections:
		bCmd = TRUE;
		bRet = TRUE;
		break;
	case WM_LBUTTONDOWN: 
        fDraw = TRUE; 
        ptPrevious.x = LOWORD(lParam); 
        ptPrevious.y = HIWORD(lParam); 
        break;
	case WM_LBUTTONUP: 
        if(fDraw) 
        { 
            hdc = GetDC(hWnd); 
            MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL); 
            LineTo(hdc, LOWORD(lParam), HIWORD(lParam)); 
            ReleaseDC(hWnd, hdc);
			fDraw = FALSE; 
        } 
        break;
	case WM_MOUSEMOVE: 
        if (fDraw) 
        { 
            hdc = GetDC(hWnd); 
            MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL); 
            LineTo  
			(
				hdc, 
				ptPrevious.x = LOWORD(lParam), 
                ptPrevious.y = HIWORD(lParam)
			); 
            ReleaseDC(hWnd, hdc); 
        } 
		break;
	case WM_QUIT:
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		EndDialog(hWnd, LOWORD(wParam));
		break;
	}
	if(bCmd)
	{
		switch (wmId)
		{
			case IDM_ABOUT:
				DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)InfProc);
				break;
			case IDM_EXIT:
				SendMessage(hWnd,WM_DESTROY,wParam,lParam);
				break;
		}
	}
	return bRet;
}

// Mesage handler for about box.
LRESULT CALLBACK InfProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
