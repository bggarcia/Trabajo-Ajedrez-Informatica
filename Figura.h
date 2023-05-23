#pragma once
#include "Vector2D.h"
#define NUM 16

class Figura
{
protected:
    //float altura;
    Vector2D posicion;
    int ident;
public:
    Figura();
    virtual ~Figura();
   
    Vector2D getPos();
    void setPos(float x, float y);
    void setPos(Vector2D pos);
    //
    void setIdent(int identi);
    int getIdent();

};
