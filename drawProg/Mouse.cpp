//
// Created by Artem on 3/19/2018.
//

#include "Mouse.h"
#include <iostream>
Mouse::Mouse() {

    previousX = 0;
    previousY = 0;
    x = 0;
    y = 0;
    active_paint = false;
    mode = false;
}

Mouse::~Mouse(){

}


void Mouse::draw(int x, int y) {
    if(active_paint && mode){
        SelectObject(hdc, pen);
        drawLine(hdc, previousX, previousY, x, y);
        previousX = x;
        previousY = y;
    }
}

void Mouse::setFirstDot(int x, int y) {
    previousX = x;
    previousY = y;
}

void Mouse::setPen(HPEN pen) {
    this->pen = pen;
}
