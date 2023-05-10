#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

/*void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
	//esfera.dibuja();
	//esfera2.dibuja();
	//caja.Dibuja();
	//hombre.dibuja();
	//disparo.dibuja();
	//plataforma.dibuja();
	//bonus.dibuja();
	//esferas.dibuja();
	//disparos.dibuja();
	//esferaPulsante.dibuja();
	//disparoEspecial.dibuja();
	//
	//tablero.dibuja();
	lt.Dibuja();
	player.dibuja();

}

void Mundo::mueve()
{
	/*for (int i = 0; i < esferas.getNumero(); i++)
	{
		for (int j = 0; j < disparos.getNum(); j++)
		{
			if (Interaccion::colision(*disparos[j], *esferas[i]))
			{
				Esfera* e = esferas[i]->dividir();
				if (e == 0)
					esferas.eliminar(esferas[i]);
				else
					esferas.agregar(e);

				disparos.eliminar(disparos[j]);

				ETSIDI::play("bin/sonidos/impacto.wav");
				break;
			}
		}
	}*/


	//
	//hombre.mueve(0.025f);
	//esfera.mueve(0.025f);
	//esfera2.mueve(0.025f);
	//bonus.mueve(0.025f);
	//disparo.mueve(0.025f);
	//esferas.mueve(0.025f);
	//esferas.rebote();
	//esferas.rebote(caja);
	//esferas.rebote(plataforma);
	/*Esfera* aux = esferas.colision(hombre);
	if (aux != 0)//si alguna esfera ha chocado
	{
		esferas.eliminar(aux);
		ETSIDI::play("bin/sonidos/impacto.wav"); //linea agregada 
	}
	disparos.mueve(0.025f);
	disparos.colision(caja);*/
	//disparos.colision(plataforma);
	//
	//Interaccion::rebote(hombre, caja);
	//Interaccion::rebote(esfera, caja);
	//Interaccion::rebote(esfera, plataforma);
	//Interaccion::rebote(esfera2, caja);
	//Interaccion::rebote(esfera2, plataforma);
	//Interaccion::rebote(esfera, esfera2);

	//esferaPulsante.mueve(0.025f);
	//Interaccion::rebote(esferaPulsante, plataforma);
	/*Interaccion::rebote(esferaPulsante, caja);
	for (int i = 0; i < esferas.getNumero(); i++)
		Interaccion::rebote(esferaPulsante, *esferas[i]);*/


	//disparoEspecial.mueve(0.025f);
	//
	//player.mueve(0.025f);
	lt.rebotee(player);
	//lt.LocFigura(player);


}

void Mundo::inicializa()
{
	//impacto = false;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;


	
	//bonus.setPos(5.0f, 5.0f);
	//nivel = 0;
	//cargarNivel();
	//disparo.setPos(-5.0f, 0.0f);
	//disparoEspecial.setPos(5.0f, 0.0f);
	//plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
	//tablero.setPos(-5, 9, -4, 10);
	lt.setPos();
	player.setPos(-4.5, 9.5);
	player.setIdent(11);

	
}

void Mundo::tecla(unsigned char key)
{
	/*switch (key)
	{
	case '1':
		esferas.agregar(new Esfera(0.5f, 0, 10));
		break;

	case '2':
		esferas.agregar(new Esfera(1.0f, 0, 10));
		break;
	case '3':
		esferas.agregar(new Esfera(1.5f, 0, 10));
		break;
	case '4':
		esferas.agregar(new Esfera(2.0f, 0, 10));
		break;
	case ' ':
	{
		Disparo* d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos.x, pos.y);
		if (disparos.agregar(d))
			hombre.setVel(0, 0);
		else delete d;
		break;
	}
	case 'z':
	{
		DisparoEspecial* d_esp = new DisparoEspecial;
		Vector2D pos = hombre.getPos();
		d_esp->setPos(pos.x, pos.y);
		disparos.agregar(d_esp);
		ETSIDI::play("bin/sonidos/disparo.wav");
		break;
	}
	}*/
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		//player.setVel(0,5.0);
		player.mueveey(1);
		player.moveIdenty(-1);
	break;
	case GLUT_KEY_LEFT:
		//hombre.setVel(-5.0f, 0.0f);
		//player.setVel( -5.0,0);
		player.mueveex(- 1);
		player.moveIdentx(-1);
		break;
	case GLUT_KEY_RIGHT:
		//hombre.setVel(5.0f, 0.0f);
		//player.setVel(5.0,0);
		player.mueveex(1);
		player.moveIdentx(1);
		break;
	case GLUT_KEY_DOWN:
		//player.setVel(0,-5.0f);
		player.mueveey(-1);
		player.moveIdenty(1);
		break;
	}
}


Mundo::~Mundo()
{
	//esferas.destruirContenido();
}

/*
bool Mundo::cargarNivel()
{
	nivel++;
	hombre.setPos(0, 0);
	esferas.destruirContenido();
	disparos.destruirContenido();
	if (nivel == 1)
	{
		plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
		Esfera* e1 = new Esfera(1.5f, 2, 4, 5, 15);
		e1->setColor(0, 0, 255);
		esferas.agregar(e1); //esfera
	}
	if (nivel == 2)
	{
		plataforma.setPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.setColor(255, 0, 0);
		EsferaPulsante* e3 = new EsferaPulsante;
		e3->setPos(0, 12);
		e3->setVel(5, 3);
		esferas.agregar(e3);

	}
	if (nivel == 3)
	{
		plataforma.setPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.setColor(255, 0, 255);
		for (int i = 0; i < 5; i++)
		{
			Esfera* aux = new Esfera(1.5, -5 + i, 12, i, 5);
			aux->setColor(i * 40, 0, 255 - i * 40);
			esferas.agregar(aux);
		}
	}
	if (nivel <= 3)
		return true;
	return false;
}

*/