#include <windows.h>
#include <tchar.h>
#include "framework.h"
#include "WindowsProject6.h"
#include <iostream>
using namespace std;
#define MAX_LOADSTRING 100
TCHAR szClassWindow[] = TEXT("†аркасное приложение");
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

    /* 1. Эпределение класса окна  */

    wcl.cbSize = sizeof(wcl);	// размер структуры WNDCLASSEX 
    wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcl.lpfnWndProc = WndProc;	// адрес оконной процедуры
    wcl.cbClsExtra = 0;		// используетсИ Windows 
    wcl.cbWndExtra = 0; 	// используетсИ Windows 
    wcl.hInstance = hInst;	// дескриптор данного приложениИ
    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);		// загрузка стандартного курсора
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//заполнение окна белым цветом			
    wcl.lpszMenuName = NULL;	// приложение не содержит меню
    wcl.lpszClassName = szClassWindow;	// имИ класса окна
    wcl.hIconSm = NULL;	// отсутствие маленькой иконки длИ свИзи с классом окна


    /*  2. ЦегистрациИ класса окна  */

    if (!RegisterClassEx(&wcl))
        return 0;	// при неудачной регистрации - выход

    /*  3. Чоздание окна  */

    // создаетсИ окно и  переменной hWnd присваиваетсИ дескриптор окна
    hWnd = CreateWindowEx(
        0,		// расширенный стиль окна
        szClassWindow,	// имИ класса окна
        TEXT("†аркас  Windows приложениИ"),	// заголовок окна
        /* Ђаголовок, рамка, позволИющаИ менИть размеры, системное меню,
            кнопки разв™ртываниИ и св™ртываниИ окна  */
        WS_OVERLAPPEDWINDOW,	// стиль окна
        CW_USEDEFAULT,	// х-координата левого верхнего угла окна
        CW_USEDEFAULT,	// y-координата левого верхнего угла окна
        CW_USEDEFAULT,	// ширина окна
        CW_USEDEFAULT,	// высота окна
        NULL,			// дескриптор родительского окна
        NULL,			// дескриптор меню окна
        hInst,		// идентификатор приложениИ, создавшего окно
        NULL);		// указатель на область данных приложениИ


    /* 4. Этображение окна */

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);	// перерисовка окна


    /* 5. Ђапуск цикла обработки сообщений  */

    // получение очередного сообщениИ из очереди сообщений
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);	// транслИциИ сообщениИ
        DispatchMessage(&Msg);	// диспетчеризациИ сообщений
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
{//заполнение резюме
    TCHAR str[20] = _TEXT("Naima");
    TCHAR str1[20] = _TEXT("Bilal");
    TCHAR str2[20] = _TEXT("18");
    TCHAR str3[20] = _TEXT("STEP");
    TCHAR str4[20] = _TEXT("Developer");
    TCHAR str5[20] = _TEXT("Guitar");
    switch (message)
    {
    case WM_MOUSEMOVE:
        wsprintf(str, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // текущие координаты курсора мыши
        SetWindowText(hWnd, str);	// строка выводитс€ в заголовок окна
        break;
    case WM_LBUTTONDOWN:          //нажатие левой кнопки мыши
    {
        int rez = MessageBox(hWnd, str, TEXT("NAME"), MB_OKCANCEL | MB_ICONINFORMATION);
        if (rez == IDOK)       //если нажата кнопка ок
        {
            MessageBox(hWnd, str1, TEXT("SURNAME"), MB_OKCANCEL | MB_ICONINFORMATION);   //вывод информации 
            MessageBox(hWnd, str2, TEXT("AGE"), MB_OKCANCEL | MB_ICONINFORMATION);               
            MessageBox(hWnd, str3, TEXT("Study"), MB_OKCANCEL | MB_ICONINFORMATION);
            MessageBox(hWnd, str4, TEXT("Job"), MB_OKCANCEL | MB_ICONINFORMATION);
            MessageBox(hWnd, str5, TEXT("Hobby"), MB_OKCANCEL | MB_ICONINFORMATION);
        }
        else if(rez==IDCANCEL)                   //если кнопка отмена
        {
            int sum = _tcslen(str) + _tcslen(str1) + _tcslen(str2) + _tcslen(str3) + _tcslen(str4) + _tcslen(str5);       //суммируем 
            int sum2=sum / 5;     //делим на их количество 
            TCHAR buff[100];
            wsprintf(buff, TEXT("Cреднее число символов в резюме: %d"), sum2);
            MessageBox(hWnd, buff, TEXT("заголовок"), MB_OKCANCEL);
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




//2 задание

    /*int Attempt = 0;            //попытки
    int n = rand() % (1-100);        //рандом
    switch (message)
    {
    case WM_LBUTTONDOWN://движение мышки
    {
        while (true)       
        {
            TCHAR Buff[50];
            wsprintf(Buff, TEXT("Число пользователя: %d "), n);     //вывод в окно 
            int rez = MessageBox(hWnd, Buff, TEXT("Числа:"), MB_OKCANCEL | MB_ICONINFORMATION);   // заголовок окна
            if (rez == IDOK)           //если кнопка ok
            {
                wsprintf(Buff, TEXT("Количество попыток: %d "), Attempt);   //то выводим кол-во попыток
                MessageBox(hWnd, Buff, TEXT("Результат"), MB_OKCANCEL);      //тоже заголовок окна
                break;
            }
            if (rez == IDCANCEL)            //если кнопка cancel 
            {
                n;                   //выводим рандом
                Attempt++;           //увеличиваем кол-во попыток
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
