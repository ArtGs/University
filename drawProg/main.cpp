#include <windows.h>
#include "WObject.h"

WObject *wnd;

// ИНДИВИДУАЛКИ
/* В окне написать название заголовка красным цветом
 * Нарисовать правее текста синий эллипс, вписанный в зеленый прямоугольник, шириной в 3 высоты текста
 * Вписать это в пункт File / Show info
 *
 *
 *
 */

// ОБЫЧНОЕ ЗАДАНИЕ

/* Добавить Палитру
 *
 *
 */

// Предопредение функций
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//======================================================================
// Главная обрабатывающая процедура
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	MSG msg;
    wnd = new WObject("DrawSoft", hInst, ncmdshow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//======================================================================
// Процедура обработки сообщений 
int button_ID = 0;

LRESULT CALLBACK WndProc(HWND window_handler, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    HDC hdc;

	switch (uMsg) {
	case WM_PAINT:
        wnd->wmPaintEngine(button_ID);
	case WM_ACTIVATE:

		break;
	case WM_CLOSE:
		DestroyWindow(window_handler);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

        case WM_LBUTTONDOWN:    // Опущена конопка мыши
            hdc = GetDC(window_handler);
            wnd->mouse->activatePaint();
            wnd->mouse->setHDC(hdc);
            wnd->setMousePen();
            wnd->mouse->setFirstDot(LOWORD(lParam),HIWORD(lParam));
            break;
        case WM_LBUTTONUP:      // Подняли кнопку мыши
            wnd->mouse->deactivePaint();

            break;
        case WM_MOUSEMOVE:      // Сдвинули мышь

            wnd->mouse->draw(LOWORD(lParam),HIWORD(lParam));
            break;


	// Обработка сообщений от кнопок и не только 
	case WM_COMMAND:
		if(wParam >= LINE_ID && wParam <= RECTANGLE_API_ID || wParam == SHOW_PROG_INFO){
            button_ID = wParam;

            InvalidateRect(window_handler, NULL, true);
        }
        if(wParam >= BRUSH1_ID && wParam <= PEN3_ID){
            wnd->switchBrush(wParam);
		}

        switch (wParam){
           case CLEAR_SCREEN:
               InvalidateRect(window_handler, NULL, true);
               break;
           case START_DRAW:
               wnd->mouse->mouseON();
               break;
           case STOP_DRAW:
               wnd->mouse->mouseOFF();
               break;
        }
        if(wParam == PALETTE_ID){
            wnd->openPalette();
        }


        break;
	default:
		return DefWindowProc(window_handler, uMsg, wParam, lParam);
	}
	return 0;
}

