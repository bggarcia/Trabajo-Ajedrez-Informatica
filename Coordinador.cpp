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
      //ETSIDI::stopMusica();
        if (key == 'c')
        {
            estado = INICIO; 
       
        }
  }
  else if (estado==FIN)
  {
     ETSIDI::stopMusica();
        if (key == 'c')
            estado = INICIO;
  }
  else if (estado==PAUSE)
    if (key=='c')
    {
      estado = JUEGO;
            ETSIDI::play("bin/sonidos/Continue.mp3");
    }
}

void Coordinador::teclaESpecial(unsigned char key)
{
  if (estado == JUEGO)
        mundo.teclaEspecial(key);
}

void Coordinador::mueve()
{
     if (estado == JUEGO && aux==true)
    {
        mundo.mueve();
    }
}
