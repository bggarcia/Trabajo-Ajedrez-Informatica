#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Tablero.h"
#define NUM 50
#include <iostream>
using ETSIDI::SpriteSequence;

class Figura
{
protected:
    //float altura;
    Vector2D posicion;
    int ident;
    Tablero* posiciones Legales[NUM];
    bool color;
    std::string tipo;
    SpriteSequence sprite1{ "bin/imagenes/piezas_blancas.png", 6 };
    SpriteSequence sprite2{ "bin/imagenes/piezas_negras.png", 6 };
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
