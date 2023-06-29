#pragma once
#include "Casilla.h"
//#include "Figura.h"
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#define MAX_TABLEROS 8
#define NUM 14
#define MAX_FIGURAS 32
#define CAS 64


class Tablero
{
private:
    Casilla **listaa;
    
public:
    Tablero();
    virtual ~Tablero();
    void Dibuja();
    void setPos();
    Vector2D getMin();
    Vector2D getMax();
    bool getCasilla(int ident);
    void setIndent();
    Casilla* getCasilla(int i, int j);
    Casilla* getCasillaPos(int ident);
    bool getColor(int ident);
    bool cumpleLimites(int ident);
    //Figura* getPiezaEnCasilla(int ident);
    void eliminarPieza(int ident);
    Casilla* getCasillaIndice(int i);
    void setFin(bool fin_) { fin = fin_; }
    bool getFin() { return fin; }
};


