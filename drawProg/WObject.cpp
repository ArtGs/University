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

    // Настройка мыши
    mouse = new Mouse();

    // Регистрация класса окна
    RegisterClassEx(&wc);

    // Создание основного окна
    hMainWindow = CreateWindow(szClassName, "DrawProgram", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
                               CW_USEDEFAULT, 0, (HWND)NULL, (HMENU)NULL, (HINSTANCE)hInst, NULL);
    // Настройка палитры
    ZeroMemory(&palette, sizeof(palette));
    palette.lStructSize = sizeof(palette);
    palette.hwndOwner = hMainWindow;
    palette.lpCustColors = (LPDWORD) acrCustClr;
    palette.rgbResult = rgbCurrent;
    palette.Flags = CC_FULLOPEN || CC_RGBINIT;



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

    // File
    HMENU fileHandler = CreateMenu();
    HMENU showInfo = CreateMenu();

    // Edit
    HMENU editHandler = CreateMenu();
    HMENU beginDraw = CreateMenu();


    // Figures
    HMENU figuresHandler = CreateMenu();	// Parent Figures
    HMENU figures_My = CreateMenu();
    HMENU figures_API = CreateMenu();

    // Style
    HMENU styleHandler = CreateMenu();	// Parent Style
    HMENU pencilHandler = CreateMenu();
    HMENU penHandler = CreateMenu();


    //File
    AppendMenu(fileHandler, MF_STRING, SHOW_PROG_INFO, "Show info");

    // Edit
    //Draw
    AppendMenu(editHandler, MF_STRING, START_DRAW, "Start draw");
    AppendMenu(editHandler, MF_STRING, STOP_DRAW, "End draw");
    AppendMenu(editHandler, MF_STRING, CLEAR_SCREEN, "Clear");

    // Figures
    // My Figures
    AppendMenu(figuresHandler, MF_POPUP, (UINT_PTR)figures_My, "My figures");
    AppendMenu(figures_My, MF_STRING, LINE_ID, "Line");
    AppendMenu(figures_My, MF_STRING, SQUARE_ID, "Square");
    AppendMenu(figures_My, MF_STRING, CUBE_ID, "Cube");
    AppendMenu(figures_My, MF_STRING, TESSERACT_ID, "Tesseract");
    // Api Figures
    AppendMenu(figuresHandler, MF_POPUP, (UINT_PTR)figures_API, "API figures");
    AppendMenu(figures_API, MF_STRING, ELLIPSE_API_ID , "Ellipse");
    AppendMenu(figures_API, MF_STRING, ROUND_API_ID, "Round");
    AppendMenu(figures_API, MF_STRING, SQUARE_API_ID, "Square");
    AppendMenu(figures_API, MF_STRING, POLYGON_API_ID, "Polygon");
    AppendMenu(figures_API, MF_STRING, RECTANGLE_API_ID, "Rectangle");

    //Style
    // Pencil
    AppendMenu(styleHandler, MF_POPUP, (UINT_PTR)pencilHandler, "Brushes");
    AppendMenu(pencilHandler, MF_STRING, BRUSH1_ID, "Brush1");
    AppendMenu(pencilHandler, MF_STRING, BRUSH12_ID, "Brush2");
    AppendMenu(pencilHandler, MF_STRING, BRUSH13_ID, "Brush3");
    // Pen
    AppendMenu(styleHandler, MF_POPUP, (UINT_PTR)penHandler, "Pens");
    AppendMenu(penHandler, MF_STRING, PEN1_ID, "Pen1");
    AppendMenu(penHandler, MF_STRING, PEN2_ID, "Pen2");
    AppendMenu(penHandler, MF_STRING, PEN3_ID, "Pen3");
    // Palette
    AppendMenu(styleHandler, MF_STRING, PALETTE_ID, "Palette");

    // Add to menu Global Items
    AppendMenu(menu_Handler, MF_POPUP, (UINT_PTR)fileHandler, "File");
    AppendMenu(menu_Handler, MF_POPUP, (UINT_PTR)editHandler, "Edit");
    AppendMenu(menu_Handler, MF_POPUP, (UINT_PTR)figuresHandler, "Figures");
    AppendMenu(menu_Handler, MF_POPUP, (UINT_PTR)styleHandler, "Style");


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

    hdc = BeginPaint(hMainWindow, &ps);

    switch (drawTool){
        case PEN_TOOL:
            SelectObject(hdc, pen);
            mouse->setPen(pen);
            break;
        case BRUSH_TOOL:
            SelectObject(hdc, brush);
            break;
    }

    POINT point_mas[6] = {
            { 1, 400 },
            { 51, 400 },
            { 51, 350 },
            { 25, 320 },
            { 1, 350 },
            { 1, 400 }
    };

    switch (id) {
        // MY FIGURES
        case LINE_ID:
            drawLine(hdc, 400, 50, 450, 100);
            EndPaint(hMainWindow, &ps);
            break;
        case SQUARE_ID:
            drawSqr(hdc, 400, 150, 50);
            EndPaint(hMainWindow, &ps);
            break;
        case CUBE_ID:
            drawCube(hdc, 400, 150, 50);
            EndPaint(hMainWindow, &ps);
            break;
        case TESSERACT_ID:
            drawTeseract(hdc, 400, 150, 50);
            EndPaint(hMainWindow, &ps);
            break;
            // API FIGURES
        case ELLIPSE_API_ID:
            Ellipse(hdc, 50, 50, 100, 200);
            EndPaint(hMainWindow, &ps);
            break;
        case ROUND_API_ID:
            Ellipse(hdc, 50, 50, 100, 100);
            EndPaint(hMainWindow, &ps);
            break;
        case RECTANGLE_API_ID:
            Rectangle(hdc, 50, 50, 200, 100);
            EndPaint(hMainWindow, &ps);
            break;
        case POLYGON_API_ID:
            Polygon(hdc, point_mas, 6);
            EndPaint(hMainWindow, &ps);
            break;
        case SQUARE_API_ID:
            Rectangle(hdc, 50, 50, 100, 100);
            EndPaint(hMainWindow, &ps);
            break;
         // Show info
        case SHOW_PROG_INFO:
            LOGFONT lfont;
            lfont.lfHeight = 14;// При использовании lfHeigh перестает отображаться текст
            lfont.lfWidth = 5;
            lfont.lfStrikeOut = 0;

            HFONT hFont = CreateFontIndirect(&lfont);


            SelectObject(ps.hdc, hFont);
            LPSTR text = new TCHAR[11];
            GetWindowText(hMainWindow, text, 12);

            drawText(50, 50, 200 , 64 , text);

            pen = CreatePen(PS_SOLID, 1, RGB(0,255,0));
            SelectObject(hdc, pen);
            Rectangle(hdc, 210, 40, 210 + 3 * 14, 60);


            pen = CreatePen(PS_SOLID, 1, RGB(0,0,255));
            SelectObject(hdc, pen);

            Ellipse(hdc,  210, 40, 210 + 3* 14, 60);




            break;
    }
}

void WObject::switchBrush(int id) {
    switch (id){
        // Pens
        case PEN1_ID:
            pen = CreatePen(PS_DASH, 1, palette.rgbResult);
            drawTool = PEN_TOOL;
            break;
        case PEN2_ID:
            pen = CreatePen(PS_DOT, 1, palette.rgbResult);
            drawTool = PEN_TOOL;
            break;
        case PEN3_ID:
            pen = CreatePen(PS_DASHDOT, 1, palette.rgbResult);
            drawTool = PEN_TOOL;
            break;
        // Brushes
        case BRUSH1_ID:
            brush = CreateHatchBrush(3, palette.rgbResult);
            drawTool = BRUSH_TOOL;
            break;
        case BRUSH12_ID:
            brush = CreateSolidBrush(palette.rgbResult);
            drawTool = BRUSH_TOOL;
            break;
        case BRUSH13_ID:
            brush = CreateHatchBrush(1, palette.rgbResult);
            drawTool = BRUSH_TOOL;
            break;
    }
}

void WObject::drawText(int x1, int y1, int x2, int y2, LPSTR text) {
    RECT text_window;
    SetRect(&text_window, x1, y1, x2, y2);
    SetTextColor(hdc, RGB(255, 0, 0));
    DrawText(hdc, TEXT(text), strlen(text), &text_window,DT_LEFT);
}

void WObject::openPalette() {
    if(ChooseColor(&palette) == true){
        pen = CreatePen(PS_SOLID, 1, palette.rgbResult);
        rgbCurrent = palette.rgbResult;
    }
}
































