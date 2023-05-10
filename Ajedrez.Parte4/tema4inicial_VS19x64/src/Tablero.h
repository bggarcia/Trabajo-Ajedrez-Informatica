#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Tablero
{
private:
    
    Vector2D limite1;
    Vector2D limite2;
    ColorRGB color;
    int ident;
public:
    Tablero();
     virtual ~Tablero();
    void dibuja();
    void setColor(Byte r, Byte v, Byte a);
    void setPos(float x1, float y1, float x2, float y2);
    void identi(int i,int j);
    Vector2D getPos();
    friend class Interaccion;
};

