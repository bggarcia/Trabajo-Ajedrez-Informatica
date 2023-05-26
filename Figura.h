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
    Figura(bool color_, const std::string& tipo_);
    virtual ~Figura();
    virtual void dibuja()=0;
    virtual bool movLegal (int ident_)=0;
    virtual std::string getName()=0;

    Vector2D getPos();
    void setPos(float x, float y);
    void setPos(Vector2D pos);
    void setPos(int ident);
    //
    void setIdent(int identi);
    int getIdent();

    
    friend class Lista Tableros;
    friend class Tablero;
};
