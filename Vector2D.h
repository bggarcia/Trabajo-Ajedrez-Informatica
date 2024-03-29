#pragma once
#include <cmath>
class Vector2D
{
public:
  float x=0.0F;
  float y=0.0F;
  Vector2D(float xv = 0.0f, float yv = 0.0f); // (1)
  virtual ~Vector2D();
  float modulo();			   // (2) modulo del vector
  float argumento();		   // (3) argumento del vector
  Vector2D unitario();		   // (4) devuelve un vector unitario
  Vector2D operator - (Vector2D);	// (5) resta de vectores
  Vector2D operator + (Vector2D);	// (6) suma de vectores
  float operator *(Vector2D&);	 	// (7) producto escalar
  Vector2D operator *(float);		// (8) producto por un escalar
  Vector2D& operator += (Vector2D&);
  bool operator != (Vector2D&);
  bool operator == (Vector2D&);
  Vector2D absoluto(Vector2D aux,Vector2D aux2) {
        Vector2D res;
        res.x = abs(aux.x-aux2.x);
        res.y = abs(aux.y-aux2.y);
        return res;
    }
};

