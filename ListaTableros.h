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
    bool piezasEnMedio(Figura *ListaFiguras, int cont, int origen, int destino);
    bool getCasillaOcupada(int destino,int cont);
    int compPiezaMismoColor(Figura* ListaFiguras, int i_, int origen, int destino, int cont);
    friend class Interaccion;
    friend class Figura;
};
