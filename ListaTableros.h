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
   
};
