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
        void tecla(unsigned char key);
        void inicializa();
        void mueve();
        bool piezaEnMedio();
        void realizarMovimiento();
	void introducirCasilla();
        void dibuja();
        void teclaEspecial(unsigned char key);
        int conversion(char[]); //Se encarga de convertir la posición de la casilla en formato letra-número a la identidad.
        //void detectaCas(Vector2D pos);
};

