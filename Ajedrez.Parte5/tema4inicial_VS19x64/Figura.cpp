#include "Figura.h"

#include "freeglut.h"
#include <iostream>
Figura::Figura() {
   
    altura = 0.1f;
}

Figura::~Figura()
{

}
void Figura::dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(altura, 20, 20);
    glPopMatrix();
}

void Figura::mueve(float t)
{
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
}

void Figura::setPos(float x1, float y1)
{   
    posicion.x = x1;
    posicion.y = y1;
}

void Figura::setVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}

void Figura::mueveex(float x1) {
    posicion.x += x1;
    printf("(%f,%f)\n", posicion.x,posicion.y);
}

void Figura::mueveey(float y1) {
    posicion.y += y1;
    printf("(%f,%f)\n", posicion.x, posicion.y);
}

Vector2D Figura::getPos() {
    Vector2D pos;
    pos.x = posicion.x;
    pos.y = posicion.y;
    //printf("(%f,%f)\n", pos.x, pos.y);
    return pos;
}

Vector2D Figura::getPos1() {
    
    return this->posicion;
}

void Figura::setIdent(int identi) {
    ident = identi;
}
void Figura::moveIdentx(int x) {
    ident += x;
    printf("%d\n", ident);
}

void Figura::moveIdenty(int y) {
    ident += 10*y;
    printf("%d\n", ident);
}

void Figura::permitido(int ident) {
    Vector2D fpos;
    int resto,cociente;
    resto = this->getIdent() % 10;
    cociente = this->getIdent() / 10;
   // numero = 0;
    fpos = this->getPos();
    for (int i = 0; i < NUM; i++) //44
        posicionesLegales[i] = 0;

    // Filas
    for (int i = 0; i < NUM / 2; i++)
        posicionesLegales[i] = new Tablero((this->getIdent() - (resto-1)) + i,this->getPos1().x + i, this->getPos1().y);

    //Columnas
     for (int i = 8; i < NUM; i++)
         posicionesLegales[i] = new Tablero((this->getIdent() - (cociente-1)*10) + 10*(i-8), this->getPos1().x, this->getPos1().y-(i-8));
    
     for (int i = 0; i < NUM; i++) {
         if (ident == (posicionesLegales[i]->getIdent())) {
             this->setPos(posicionesLegales[i]->getPos1().x, posicionesLegales[i]->getPos1().y);
             this->setIdent(ident);
         }
     }


    

}

int Figura::getIdent() {
    return ident;
}

