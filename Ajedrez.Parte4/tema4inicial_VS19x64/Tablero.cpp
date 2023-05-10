#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero() {
    //rojo = verde = azul = 255; //blanco
}

Tablero::~Tablero()
{

}
Vector2D Tablero::getPos() {
    Vector2D pos;
    
    pos.x = (limite1.x + limite2.x) / 2.0;
    pos.y= (limite1.y + limite2.y) / 2.0;


        return pos;
}
void Tablero::dibuja()
{
    glDisable(GL_LIGHTING);
    color.ponColor();
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y,0);
    glVertex3d(limite2.x, limite1.y,0);
    glVertex3d(limite2.x, limite2.y,0);
    glVertex3d(limite1.x, limite2.y,0);
    glEnd();
    glEnable(GL_LIGHTING);
}

void Tablero::setColor(Byte r, Byte v, Byte a)
{
    color.set(r, v, a);
}

void Tablero::setPos(float x1, float y1, float x2, float y2)
{
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
}

void Tablero::identi(int i, int j) {
    ident = ((i + 1) * 10) + (j + 1);
}
