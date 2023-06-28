#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Figura.h"

//class Tablero

class Tablero
{
private:
    
    Vector2D limite1;
    Vector2D limite2;
    ColorRGB color;
    Vector2D pos;
    int ident;
    Figura* Pieza = nullptr;
public:
    Tablero();
    Tablero(float x1, float y1);
     virtual ~Tablero();
    
};



