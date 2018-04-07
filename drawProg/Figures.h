#pragma once
#include <Windows.h>
void drawLine(const HDC &hdc, int x1, int y1, int x2, int y2);
void drawSqr(const HDC &hdc, int x, int y, int size);
void drawCube(const HDC &hdc, int x, int y, int size);
void drawTeseract(const HDC &hdc, int x, int y, int size);