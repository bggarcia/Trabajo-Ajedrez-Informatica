#pragma once
#include "Vector2D.h"
#include "Tablero.h"
#define NUM 16

class Figura
{
protected:
    //float altura;
    Vector2D posicion;
    int ident;
    Tablero* posiciones Legales[NUM];
public:
    Figura();
    virtual ~Figura();
    friend class Lista Tableros;
    friend class Tablero;
    Vector2D getPos();
    void setPos(float x, float y);
    void setPos(Vector2D pos);
    //
    void setIdent(int identi);
    int getIdent();

};
