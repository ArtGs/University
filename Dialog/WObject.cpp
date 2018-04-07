//
// Created by Artem on 3/16/2018.
//

#include "WObject.h"


WObject::WObject(LPCTSTR windowName, HINSTANCE hInst, int nCmdShow, LRESULT(*pWndProc)(HWND, UINT, WPARAM, LPARAM),
                 LPCTSTR menuName, int x, int y, int width, int height, UINT classStyle, DWORD windowStyle, HWND hParent)
{

    char szClassName[] = "WObjectClass";
    // Setup window field
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = pWndProc;	// Установка процедуры обработчика
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// Установка иконки
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// Установка типа курсора
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Регистрация класса окна
    RegisterClassEx(&wc);

    // Создание основного окна
    hMainWindow = CreateWindow(szClassName, "DialogProgram", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
                               CW_USEDEFAULT, 0, (HWND)NULL, (HMENU)NULL, (HINSTANCE)hInst, NULL);
    // Настройка палитры
    ZeroMemory(&palette, sizeof(palette));
    palette.lStructSize = sizeof(palette);
    palette.hwndOwner = hMainWindow;
    palette.lpCustColors = (LPDWORD) acrCustClr;
    palette.rgbResult = rgbCurrent;

    // Отображение окна
    setupMenu();
    ShowWindow(hMainWindow, nCmdShow);

    // Установка значений по умолчанию
    drawTool = 0;
}

WObject::~WObject(){
    DeleteObject(pen);
    DeleteObject(brush);
}


void WObject::setupMenu() {
    menu_Handler = CreateMenu();

    HMENU dialog_menu = CreateMenu();

    AppendMenuA(menu_Handler, MF_POPUP, (UINT_PTR)dialog_menu, "Dialogs");
    AppendMenuA(dialog_menu, MF_STRING, DIALOG_MENU_ID, "Change RGB");

    SetMenu(hMainWindow, menu_Handler);
}

// SET/GET

HWND WObject::getHWND() {
    return hMainWindow;
}

HDC WObject::getHDC() {
    return this->hdc;
}
// Methods for commands
void WObject::wmPaintEngine(int id) {


}

































