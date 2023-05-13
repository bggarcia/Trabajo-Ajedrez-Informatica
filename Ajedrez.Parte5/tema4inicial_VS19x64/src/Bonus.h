#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Bonus:public ObjetoMovil
{
private:
    float lado;
    //unsigned char rojo;
    //unsigned char verde;
    //unsigned char azul;
   // Vector2D posicion;
    //Vector2D velocidad;
    //Vector2D aceleracion;
public:
    Bonus();
    virtual ~Bonus();
    void dibuja();
    //void mueve(float t);
    void setPos(float ix, float iy);
};

