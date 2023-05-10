#pragma once
#include "Tablero.h"
#include "Figura.h"
#define MAX_TABLEROS 8
class ListaTableros
{
private:
    Tablero cas1;
    Tablero cas2;
    Tablero cas3;
    Tablero cas4;
    Tablero **listaa;
    //int filas, columnas;
        
public:
    ListaTableros();
    virtual ~ListaTableros();
    void Dibuja();
    void setPos();
    Vector2D getMin();
    Vector2D getMax();
    void rebotee(Figura& f);
    void setIndent();
    //void LocFigura(Figura& f);
    friend class Interaccion;
    friend class Figura;
};

