//
// Created by Artem on 3/19/2018.
//

#ifndef DRAWPROG_MOUSE_H
#define DRAWPROG_MOUSE_H

#pragma once
#include "windows.h"
#include "Figures.h"

class Mouse {
    int x;
    int y;
    int previousX;
    int previousY;

    HPEN pen;

    HDC hdc;

    bool active_paint;
    bool mode;
public:
    Mouse();
    ~Mouse();

    void draw(int x, int y);
    void setFirstDot(int x, int y);
    void setPen(HPEN pen);

    void setHDC(HDC hdc){
        this->hdc = hdc;
    }
    void activatePaint(){
            active_paint = true;
    }
    void deactivePaint(){
        active_paint = false;
    }
    void mouseON(){
        mode = true;
    }
    void mouseOFF(){
        mode = false;
    }
};


#endif //DRAWPROG_MOUSE_H
