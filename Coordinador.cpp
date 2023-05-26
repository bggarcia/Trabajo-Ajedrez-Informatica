#include "Coordinador.h"
#include "ETSIDI.h"

void Coordinador::tecla(unsigned char key)
{
  if (estado==INICIO)
  {
    ETSIDI::play("bin/sonidos/audio.mp3");
        ETSIDI::playMusica("bin/sonidos/CancionDeFondo.mp3", 1);
        if (key == 'e')
        {
            mundo.inicializa();
            estado = JUEGO;
        }
        if (key == 's')
            exit(0);
  }
  else if (estado==JUEGO)
  {
    
  }
  else if(estado==GAMEOVER)
  {
    
  }
  else if (estado==FIN)
  {
    
  }
  else if (estado==PAUSE)
    if (key=='c')
    {
      
    }
}

void Coordinador::teclaESpecial(unsigned char key)
{
  
}

void Coordinador::mueve()
{
    

}
