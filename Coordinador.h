#pragma once
#include "Mundo.h

class Coordinador
{
  public: 
    	Coordinador();
	virtual ~Coordinador();
  protected: 
    	Mundo mundo;
   	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSE };
  	Vector2D raton;
	Estado estado;
	bool aux;


}
