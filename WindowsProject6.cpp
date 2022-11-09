#include <windows.h>
#include <tchar.h>
#include "framework.h"
#include "WindowsProject6.h"
#include <iostream>
using namespace std;
#define MAX_LOADSTRING 100
TCHAR szClassWindow[] = TEXT("��������� ����������");
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG Msg;
    WNDCLASSEX wcl;

    /* 1. ����������� ������ ����  */

    wcl.cbSize = sizeof(wcl);	// ������ ��������� WNDCLASSEX 
    wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcl.lpfnWndProc = WndProc;	// ����� ������� ���������
    wcl.cbClsExtra = 0;		// ������������ Windows 
    wcl.cbWndExtra = 0; 	// ������������ Windows 
    wcl.hInstance = hInst;	// ���������� ������� ����������
    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������
    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);		// �������� ������������ �������
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//���������� ���� ����� ������			
    wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
    wcl.lpszClassName = szClassWindow;	// ��� ������ ����
    wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����


    /*  2. ����������� ������ ����  */

    if (!RegisterClassEx(&wcl))
        return 0;	// ��� ��������� ����������� - �����

    /*  3. �������� ����  */

    // ��������� ���� �  ���������� hWnd ������������� ���������� ����
    hWnd = CreateWindowEx(
        0,		// ����������� ����� ����
        szClassWindow,	// ��� ������ ����
        TEXT("������  Windows ����������"),	// ��������� ����
        /* ���������, �����, ����������� ������ �������, ��������� ����,
            ������ ������������ � ���������� ����  */
        WS_OVERLAPPEDWINDOW,	// ����� ����
        CW_USEDEFAULT,	// �-���������� ������ �������� ���� ����
        CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
        CW_USEDEFAULT,	// ������ ����
        CW_USEDEFAULT,	// ������ ����
        NULL,			// ���������� ������������� ����
        NULL,			// ���������� ���� ����
        hInst,		// ������������� ����������, ���������� ����
        NULL);		// ��������� �� ������� ������ ����������


    /* 4. ����������� ���� */

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);	// ����������� ����


    /* 5. ������ ����� ��������� ���������  */

    // ��������� ���������� ��������� �� ������� ���������
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);	// ���������� ���������
        DispatchMessage(&Msg);	// ��������������� ���������
    }
    return Msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT6));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT6);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{//���������� ������
    TCHAR str[20] = _TEXT("Naima");
    TCHAR str1[20] = _TEXT("Bilal");
    TCHAR str2[20] = _TEXT("18");
    TCHAR str3[20] = _TEXT("STEP");
    TCHAR str4[20] = _TEXT("Developer");
    TCHAR str5[20] = _TEXT("Guitar");
    switch (message)
    {
    case WM_MOUSEMOVE:
        wsprintf(str, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // ������� ���������� ������� ����
        SetWindowText(hWnd, str);	// ������ �������� � ��������� ����
        break;
    case WM_LBUTTONDOWN:          //������� ����� ������ ����
    {
        int rez = MessageBox(hWnd, str, TEXT("NAME"), MB_OKCANCEL | MB_ICONINFORMATION);
        if (rez == IDOK)       //���� ������ ������ ��
        {
            MessageBox(hWnd, str1, TEXT("SURNAME"), MB_OKCANCEL | MB_ICONINFORMATION);   //����� ���������� 
            MessageBox(hWnd, str2, TEXT("AGE"), MB_OKCANCEL | MB_ICONINFORMATION);               
            MessageBox(hWnd, str3, TEXT("Study"), MB_OKCANCEL | MB_ICONINFORMATION);
            MessageBox(hWnd, str4, TEXT("Job"), MB_OKCANCEL | MB_ICONINFORMATION);
            MessageBox(hWnd, str5, TEXT("Hobby"), MB_OKCANCEL | MB_ICONINFORMATION);
        }
        else if(rez==IDCANCEL)                   //���� ������ ������
        {
            int sum = _tcslen(str) + _tcslen(str1) + _tcslen(str2) + _tcslen(str3) + _tcslen(str4) + _tcslen(str5);       //��������� 
            int sum2=sum / 5;     //����� �� �� ���������� 
            TCHAR buff[100];
            wsprintf(buff, TEXT("C������ ����� �������� � ������: %d"), sum2);
            MessageBox(hWnd, buff, TEXT("���������"), MB_OKCANCEL);
        }
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;




//2 �������

    /*int Attempt = 0;            //�������
    int n = rand() % (1-100);        //������
    switch (message)
    {
    case WM_LBUTTONDOWN://�������� �����
    {
        while (true)       
        {
            TCHAR Buff[50];
            wsprintf(Buff, TEXT("����� ������������: %d "), n);     //����� � ���� 
            int rez = MessageBox(hWnd, Buff, TEXT("�����:"), MB_OKCANCEL | MB_ICONINFORMATION);   // ��������� ����
            if (rez == IDOK)           //���� ������ ok
            {
                wsprintf(Buff, TEXT("���������� �������: %d "), Attempt);   //�� ������� ���-�� �������
                MessageBox(hWnd, Buff, TEXT("���������"), MB_OKCANCEL);      //���� ��������� ����
                break;
            }
            if (rez == IDCANCEL)            //���� ������ cancel 
            {
                n;                   //������� ������
                Attempt++;           //����������� ���-�� �������
            }
        }
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
    {
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    }
    return 0;*/
}






INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
