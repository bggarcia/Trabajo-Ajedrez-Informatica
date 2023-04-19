#pragma once
#include "Vector2D.h"
class Pieza {
  Vector2D posicion;
  unsigned char r;
  unsigned char g;
  unsigned char b;
  
  public:
  void dibuja();
  void mueve();
};
