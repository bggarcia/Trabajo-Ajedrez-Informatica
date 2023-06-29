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
  

};


