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

}
