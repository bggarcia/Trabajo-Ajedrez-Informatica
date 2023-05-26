#pragma once
#include "Tablero.h"
#include "Figura.h"
#define MAX_TABLEROS 8
#define NUM 14
#define CAS 64
class ListaTableros
{
private:
    Tablero **listaa;
    Tablero* posicionesLegales[NUM];
    Tablero* casillasOcupadas[CAS];
public:
    ListaTableros();
    virtual ~ListaTableros();
    void Dibuja();
    void setPos();
    Vector2D getMin();
    Vector2D getMax();
    bool getCasilla(int ident);
    void setIndent();
};
