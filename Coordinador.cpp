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
     mundo.tecla(key);
        ETSIDI::playMusica("bin/sonidos/CancionDeFondo.mp3", 1);
        if (key == 'p')
        {
            estado = PAUSE;
            ETSIDI::play("bin/sonidos/Pause.mp3");
        }
        if (key == 'f') estado = FIN;
        if (key == 'g')
        {
            estado = GAMEOVER;
            ETSIDI::play("bin/sonidos/GameOver.mp3");
        }
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
