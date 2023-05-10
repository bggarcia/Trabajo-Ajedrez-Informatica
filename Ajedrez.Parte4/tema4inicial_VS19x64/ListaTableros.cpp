#include "ListaTableros.h"
#include <iostream>


ListaTableros::ListaTableros() {

   /* cas1.setColor(0, 100, 0);
    cas1.setPos(-5,9,-4,10);
    
    cas2.setColor(0, 100, 0);
    cas2.setPos(-4,9,-3,10);
    
    cas3.setColor(0, 150, 0);
    cas3.setPos(-4,10,-3,11);
    
    cas4.setColor(0, 150, 0);
    cas4.setPos(-5,10,-4, 11);*/
    //filas = columnas = 8;

    listaa = new Tablero*[MAX_TABLEROS];
    for (int i = 0; i < MAX_TABLEROS; i++) {
        listaa[i] = new Tablero[MAX_TABLEROS];
    }
        

}
/*
ListaTableros::~ListaTableros()
{
    /*for (int i = 0; i < MAX_TABLEROS; i++) // destrucción de esferas contenidas
        delete listaa[i];*/

ListaTableros::~ListaTableros() {
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            delete (*(listaa + i) + j);
        }
    }
}
void ListaTableros::Dibuja()
{
    /*cas1.dibuja();
    cas2.dibuja();
    cas3.dibuja();
    cas4.dibuja();*/
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            (*(listaa + i) + j)->dibuja();
        }
    }
}
void ListaTableros::setIndent() {
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            (*(listaa + i) + j)->identi(i,j);
        }
    }
}
Vector2D ListaTableros::getMin() {
    Vector2D pos;
    pos=(*(listaa))->getPos();

    return pos;
}
Vector2D ListaTableros::getMax() {
    Vector2D pos;
    pos=(*(listaa+7)+7)->getPos();
    return pos;
}
void ListaTableros::rebotee(Figura& f) {
    Vector2D min, max;
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            //(*(listaa + i) + j)->dibuja();
            if (i == 0 && j == 0)
            {
                min = (*(listaa + i) + j)->getPos();
            }
            if (i == 7 && j == 7)
            {
                max = (*(listaa + i) + j)->getPos();
            }
        }
    }
    if (f.posicion.x > max.x)
        f.posicion.x = max.x;
    if (f.posicion.x < min.x)
        f.posicion.x = min.x;
    //
    if (f.posicion.y < max.y)
        f.posicion.y = max.y;
    if (f.posicion.y > min.y)
        f.posicion.y = min.y;
        
}
/*oid ListaTableros::LocFigura(Figura& f) {
    Vector2D min, max,vec;
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            //(*(listaa + i) + j)->dibuja();
            
           
            if ((f.posicion.x = (*(listaa + i) + j)->getPos().x) && 
                (f.posicion.y = (*(listaa + i) + j)->getPos().y))
            {
                printf("La figura se encuentra en (%f,%f)\n", f.posicion.x, f.posicion.y);
            }
        }
    }
}*/

void ListaTableros::setPos() {

    /*for (int i = 0; i < MAX_TABLEROS; i++) {
        if (i % 2 == 0)
            listaa[i]->setColor(0, 255, 0);
        else
            listaa[i]->setColor(0, 0, 255);

        listaa[i]->setPos(-5 + i, 9, -4 + i, 10);
    }
    */
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            if ((i + j) % 2 == 0) {
                (*(listaa + i) + j)->setColor(0,255,0);
            }
            else{
                (*(listaa + i) + j)->setColor(0,0,255);
            }

            (*(listaa + i) + j)->setPos(-5 + j, 9 - i, -4 + j, 10 - i);
        }
    }
}