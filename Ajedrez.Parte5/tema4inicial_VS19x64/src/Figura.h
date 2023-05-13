#pragma once
#include "Vector2D.h"
#define NUM 16
#include "Tablero.h"
class Figura
{
private:
    float altura;
    //
    Vector2D posicionCentral;
    //
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    int ident;
    Tablero* posicionesLegales[NUM];
public:
    Figura();
    virtual ~Figura();
    void dibuja();
    void mueve(float t);
    void mueveex(float x1);
    void mueveey(float y1);
    void setPos(float x1, float y1);
    void setVel(float vx, float vy);
    //
    void setIdent(int identi);
    void moveIdentx(int x);
    void moveIdenty(int y);
    //void imprimir();
    //
    void permitido(int ident);
    Vector2D getPos();
    Vector2D getPos1();
    int getIdent();

    friend class Interaccion;
    friend class ListaTableros;
    friend class Tablero;
};

