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

