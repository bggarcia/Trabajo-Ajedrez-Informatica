#include "Reina.h"


Reina::Reina(){
  lado=0.1f;
}

void Reina::dibuja(){
  if (color==1)
  {
    sprite1.setCenter(0.0f, 0.0f);
        sprite1.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(4);
        sprite1.draw();
        glPopMatrix();
  }
  else
  {
        sprite2.setCenter(0.0f, 0.0f);
        sprite2.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(4);
        sprite2.draw();
        glPopMatrix();
  }

  std::string Reina::getName() {
    return tipo;
  }
}
