#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Disparo:public ObjetoMovil
{
protected:
    float radio;
    //unsigned char rojo;
    //unsigned char verde;
   // unsigned char azul;
    Vector2D origen;
    //Vector2D posicion;
    //Vector2D velocidad;
    //Vector2D aceleracion;
public:
    Disparo();
    virtual ~Disparo();
    void dibuja();
    //void mueve(float t);
    void setPos(float ix, float iy);
    void setVel(float vx, float vy);
    float getRadio();
    Vector2D getPos();
    friend class Interaccion;
};

