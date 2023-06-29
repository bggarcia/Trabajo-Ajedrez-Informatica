#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Figura.h"

//class Tablero

class Casilla
{
private:
    
    Vector2D limite1;
    Vector2D limite2;
    ColorRGB color;
    Vector2D pos;
    int ident;
    Figura* Pieza = nullptr;
public:
    Casilla();
    Casilla(float x1, float y1);
     virtual ~Casilla();
     void dibuja();
    void setColor(Byte r, Byte v, Byte a);
    void setPos(float x1, float y1, float x2, float y2);
     void identi(int i,int j);
    int getIdent();
    void setPieza(Figura* p);
    Figura* getPieza();
    Vector2D getPos();
    Vector2D getPos1();
    float getPosX();
    float getPosY();
    friend class Tablero;
};



