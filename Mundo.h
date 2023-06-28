#pragma once
#include "Tablero.h"
#include "ETSIDI.h"
#define NUM_FIGURAS 32
class Mundo
{
public:
virtual ~Mundo();
Tablero lt;
int ident,pos;
bool turno;


	float x_ojo;
	float y_ojo;
	float z_ojo;
	//void rotarOjo();
};

