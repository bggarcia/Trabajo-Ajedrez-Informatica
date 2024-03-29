
#include "Tablero.h"
#include <iostream>
#define NUM_FIGURAS 32

using namespace std;
Tablero::Tablero() {
    listaa = new Casilla*[CAS];
    for (int i = 0; i < CAS; i++) {
        listaa[i] = new Casilla[CAS];
    }

    //Negras
    listaa[0]->setPieza(new Torre(false, 18));
    listaa[1]->setPieza(new Caballo(false, 28));
    listaa[2]->setPieza(new Alfil(false, 38));
    listaa[3]->setPieza(new Reina(false, 48));
    listaa[4]->setPieza(new Rey(false, 58));
    listaa[5]->setPieza(new Alfil(false, 68));
    listaa[6]->setPieza(new Caballo(false, 78));
    listaa[7]->setPieza(new Torre(false, 88));
    listaa[8]->setPieza(new Peon(false, 17));
    listaa[9]->setPieza(new Peon(false, 27));
    listaa[10]->setPieza(new Peon(false, 37));
    listaa[11]->setPieza(new Peon(false, 47));
    listaa[12]->setPieza(new Peon(false, 57));
    listaa[13]->setPieza(new Peon(false, 67));
    listaa[14]->setPieza(new Peon(false, 77));
    listaa[15]->setPieza(new Peon(false, 87));

    //Blancas
    listaa[48]->setPieza(new Peon(true, 12));
    listaa[49]->setPieza(new Peon(true, 22));
    listaa[50]->setPieza(new Peon(true, 32));
    listaa[51]->setPieza(new Peon(true,42));
    listaa[52]->setPieza(new Peon(true, 52));
    listaa[53]->setPieza(new Peon(true, 62));
    listaa[54]->setPieza(new Peon(true, 72));
    listaa[55]->setPieza(new Peon(true, 82));
    listaa[56]->setPieza(new Torre(true, 11));
    listaa[57]->setPieza(new Caballo(true, 21));
    listaa[58]->setPieza(new Alfil(true, 31));
    listaa[59]->setPieza(new Reina(true, 41));
    listaa[60]->setPieza(new Rey(true, 51));
    listaa[61]->setPieza(new Alfil(true, 61));
    listaa[62]->setPieza(new Caballo(true, 71));
    listaa[63]->setPieza(new Torre(true, 81));
    
    
    for (int i = 0; i < NUM_FIGURAS / 2; i++) {
        if (i < 8)
            listaa[i]->Pieza->setPos(1.0f + ((float)i), 8.0f);
        
        else
            listaa[i]->Pieza->setPos(1.0f + ((float)i - 8.0f), 7.0f);
    }

    for (int i = 3*CAS/ 4 ; i < CAS; i++) {
        if (i < 56)
            listaa[i]->Pieza->setPos(1.0 + ((float)i - 48.0f), 2.0f);
        else
            listaa[i]->Pieza->setPos(1.0 + ((float)i - 56.0f), 1.0f);
    }

    setIndent();
    setPos();
 
}


Tablero::~Tablero() {
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            delete (*(listaa + i) + j);
        }
    }
}

void Tablero::Dibuja()
{

    for (int i = 0; i < MAX_TABLEROS; i++) {
        
            //listaa[i]->dibuja();
        for (int j = 0; j < MAX_TABLEROS; j++) {
            (*(listaa + i) + j)->dibuja();
        }
        
    }
    for (int i = 0; i < CAS; i++) {
        if (listaa[i]->getPieza() != nullptr)
            listaa[i]->getPieza()->dibuja();
    }
}

void Tablero::setIndent() {
    int cont=0;
    for (int j = MAX_TABLEROS; j > 0; j--) {
        for (int i = 1; i <= MAX_TABLEROS; i++) {

            listaa[cont]->identi(i, j);
            cont++;
        }
            
    }
}

Vector2D Tablero::getMin() {
    Vector2D pos;
    pos=(*(listaa))->getPos();

    return pos;
}

Vector2D Tablero::getMax() {
    Vector2D pos;
    pos=(*(listaa+7)+7)->getPos();
    return pos;
}

bool Tablero::getCasilla(int ident) {

    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            // //lista[i][j]
           //delete (*(listaa + i) + j);
           /* if ((*(listaa + i) + j)->getIdent() == ident)
                return true;*/
            if (listaa[i][j].getIdent() == ident)
                return true;
        }
    }

    return false;
}

void Tablero::setPos() {

    
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            if ((i + j) % 2 == 0) {
                (*(listaa + i) + j)->setColor(101, 67, 33);
                
            }
            else{
                (*(listaa + i) + j)->setColor(225, 198, 153);
            }

            (*(listaa + i) + j)->setPos( 0.5f+(float)j,0.5f+  (float)i, 1.5f + (float)j, 1.5f + (float)i);
        }
    }
}


Casilla* Tablero::getCasilla(int i, int j) {

    return (*(listaa + i) + j);
}

Casilla* Tablero::getCasillaPos(int ident)
{
   
    for ( int i = 0;  i < CAS;  i++)
    {
        if (listaa[i]->getIdent() == ident)
            return listaa[i];
    }
    return listaa[0]; //Si la identidad no coincide, devuelve un valor arbitrario.
    //El control de acceso a este elemento se hace desde fuera a través de cumpleLimites.
    
    
}
bool Tablero::getColor(int ident) {

   //Arbitrario, normalmente al hacer la comprobación desde fuera se hará solamente si la pieza no es nullptr. Se retorna un valor por seguridad.
    if (getCasillaPos(ident) != nullptr)
        return getCasillaPos(ident)->getPieza()->getColor();
    else return false;
}

bool Tablero::cumpleLimites(int ident) {
    Vector2D pos;
    int aux_x, aux_y;
    aux_x = ident / 10; //valores auxiliares para que el primero se haga entero y luego se pase como float. Si se hiciera directamente la división float, quedaría una posición con decimales
    aux_y = ident % 10;
    pos = { (float)aux_x,(float)aux_y }; 
    if (pos.x < 1 || pos.x>8 || pos.y < 1 || pos.y>8) {
        return false;
    }
    else return true;
}



void Tablero::eliminarPieza(int destino)
{
   if (this->getCasillaPos(destino)->getPieza() != nullptr)
    {
        if (this->getCasillaPos(destino)->getPieza()->getName() == "k")
        {
            fin = true;
        }
    }
    this->getCasillaPos(destino)->setPieza(nullptr);

}

Casilla* Tablero::getCasillaIndice(int i) {

    return listaa[i];
}
