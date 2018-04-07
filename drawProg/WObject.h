//
// Created by Artem on 3/16/2018.
//
#pragma  once
#ifndef DRAWPROG_WOBJECT_H
#define DRAWPROG_WOBJECT_H

#include <iostream>
#include "Figures.h"
#include "windows.h"
#include "IDLIST.h"
#include "Mouse.h"

class WObject {
private:
    HDC hdc;
    HPEN pen;
    PAINTSTRUCT ps;
    HBRUSH brush;
    byte drawTool;  // Select draw object

private:
    CHOOSECOLOR palette;
    DWORD rgbCurrent;
    COLORREF acrCustClr[16];
protected:
    HWND hMainWindow;
    WNDCLASSEX wc;
    HMENU menu_Handler;

public:
    WObject(LPCTSTR windowName, HINSTANCE hInst, int nCmdShow, LRESULT (WINAPI *pWndProc)(HWND, UINT, WPARAM, LPARAM),
    LPCTSTR menuName = NULL, int x = CW_USEDEFAULT, int y = 0, int width = CW_USEDEFAULT, int height = 0,
    UINT classStyle = CS_HREDRAW | CS_VREDRAW, DWORD windowStyle = WS_OVERLAPPEDWINDOW, HWND hParent = NULL);
    ~WObject();

    // Methods
    HWND getHWND();
    HDC getHDC();
    PAINTSTRUCT getPanitStruct(){
        return this->ps;
    }
    void setMousePen(){
        mouse->setPen(pen);
    }

    void drawText(int x1, int y1, int x2, int y2, LPSTR text);

    // Commands
    void wmPaintEngine(int id);
    void switchBrush(int id);
    void openPalette();

    // Objects
    Mouse *mouse;
private:
    void setupMenu();

};


#endif //DRAWPROG_WOBJECT_H
