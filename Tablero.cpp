#include "ListaTableros.h"
#include <iostream>

using namespace std;
ListaTableros::ListaTableros() {



}


ListaTableros::~ListaTableros() {
    
}
void ListaTableros::Dibuja()
{
   
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
    
}
Vector2D ListaTableros::getMax() {
    
}


void ListaTableros::movement(Figura& f) {
   
}

void ListaTableros::setPos() {

    
    
}
