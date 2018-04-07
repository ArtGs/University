

#include "Figures.h"

void drawLine(const HDC &hdc, int x1, int y1, int x2, int y2) {
	MoveToEx(hdc, x1, y1, 0);
	LineTo(hdc, x2, y2);
}
void drawSqr(const HDC &hdc, int x, int y, int size) {
	drawLine(hdc, x, y, x + size, y);
	drawLine(hdc, x, y, x, y + size);
	drawLine(hdc, x + size, y, x + size, y + size);
	drawLine(hdc, x, y + size, x + size, y + size);
}
void drawCube(const HDC &hdc, int x, int y, int size) {
	drawSqr(hdc, x, y, size);
	drawSqr(hdc, x + size / 2, y + size / 2, size);

	drawLine(hdc, x, y, x + size / 2, y + size / 2);
	drawLine(hdc, x, y + size, x + size / 2, y + 3 * size / 2);
	drawLine(hdc, x + size, y, x + 3 * size / 2, y + size / 2);
	drawLine(hdc, x + size, y + size, x + 3 * size / 2, y + 3 * size / 2);
}
void drawTeseract(const HDC &hdc, int x, int y, int size) {
	drawCube(hdc, x, y, size);
	drawCube(hdc, x + 50, y + 100, size);

	drawLine(hdc, x, y, x + 50, y + 100);
	drawLine(hdc, x, y + size, x + 50, y + 100 + size);

	drawLine(hdc, x + 50, y, x + 50 + size, y + 100);
	drawLine(hdc, x + 50, y + size, x + 50 + size, y + 100 + size);

	drawLine(hdc, x + 3 * size / 2, y + 3 * size / 2, x + 3 * size / 2 + 50, y + 100 + 3 * size / 2);
	drawLine(hdc, x + size / 2, y + 3 * size / 2, x + size / 2 + 50, y + 100 + 3 * size / 2);

	drawLine(hdc, x + 3 * size / 2, y + size / 2, x + 3 * size / 2 + 50, y + 100 + size / 2);
	drawLine(hdc, x + size / 2, y + size / 2, x + size / 2 + 50, y + 100 + size / 2);
}

