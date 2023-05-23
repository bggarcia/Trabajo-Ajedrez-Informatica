#pragma once
#include "Tablero.h"
#include "Figura.h"
#define MAX_TABLEROS 8
#define NUM 14
class ListaTableros
{
private:
    Tablero **listaa;
    Tablero* posicionesLegales[NUM]; //nuestra matriz
        
public:
    ListaTableros();
    virtual ~ListaTableros();
    void Dibuja();
    void setPos();
    Vector2D getMin();
    Vector2D getMax();
    void setIndent();
    void movement(Figura& f);
    //friend class Interaccion; //mas adelante
    friend class Figura;
};

