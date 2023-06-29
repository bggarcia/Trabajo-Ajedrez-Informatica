#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include<cmath>
#include <iostream>
using ETSIDI::SpriteSequence;
using namespace std;

class Figura
{
protected:
    Vector2D posicion;
    int ident;
    bool color;
    bool primerMov=true;
    string tipo;
    SpriteSequence sprite1{ "bin/imagenes/piezas_blancas.png", 6 };
    SpriteSequence sprite2{ "bin/imagenes/piezas_negras.png", 6 };
    Vector2D max,min;
public:
    Figura();
    Figura(bool color_, const string &tipo_,int identidad_,bool vida_);
    Figura(bool color_,int identidad_);
    virtual ~Figura();
    virtual void dibuja()=0;
    virtual bool movLegal (int ident_)=0;
    virtual string getName()=0;

    Vector2D getPos();
    void setPos(float x, float y);
    void setPos(Vector2D pos);
    void setPos(int ident);
    void setPrimerMov(bool mov) { primerMov = mov; }
    //
    void setIdent(int identi);
    int getIdent();
    bool getColor(){ if (this == nullptr)
            return false;
        return color;}
    bool coronacion(int);
    
    friend class Tablero;
    friend class Casilla;
};
