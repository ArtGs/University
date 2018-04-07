
#include <iostream>
#include "windows.h"
#include "WObject.h"



/* Список  обычных адач
 *  Сделать в диалоговом окне считку RGB цвета и отрисовать этим цветом фигуру
 *
 */

/* Индивидуалки номер 6
 * В диалоговом окне сделать выбор стиля текста:
 * 1) По левой границе
 * 2) По правой границе
 * Выбор типа шрифта:
 * 1) Обычный
 * 2) Жирный
 * 3) Курсив
 * 4) Жирный курсив
 * <Сделать возможность активировать их>
 * После нажатия на кнопку "Ок" отрисовать надпись "Пробный текст"
 *
 */
WObject *wnd;

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
        break;
        case WM_CLOSE:
            DestroyWindow(window_handler);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            // Обработка сообщений от кнопок и не только
        case WM_COMMAND:
            break;
        default:
            return DefWindowProc(window_handler, uMsg, wParam, lParam);
    }
    return 0;
}

