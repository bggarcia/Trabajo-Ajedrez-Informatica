#include "Caballo.h"


Caballo::Caballo(){

	lado = 0.1f;
}

void Caballo::dibuja() {
	if (color==1){
		 sprite1.setCenter(0.0f, 0.0f);
        sprite1.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(3);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0.0f, 0.0f);
        sprite2.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(3);
        sprite2.draw();
        glPopMatrix();
    }

}

bool Caballo::movLegal(int ident_) {
   Vector2D pos_ini,pos,dif,dif_aux; //Posición onicial, posición final, diferencia de posiciones y valores absolutos de la diferencia.
	int aux_x,aux_y;
	pos_ini=this->getPos();

	//Se procede a la separación de la identidad en variables auxiliares para que la división sea 
	//una división de enteros, pero que luego se pase como float al vector de posición.
	
	aux_x=ident/10;
	aux_y=ident %10;
	pos= {(float)aux_x,(float)aux_y};

	dif=pos-pos_ini;
	dif_aux=dif.absoluto(pos,pos_ini); //Se llama a la función absoluto de Vector2D que devuelve un vector con el 
	//valor absoluto de cada miembro.

	//El movimiento del caballo es de 2 casillas en una dirección y de 1 casilla en la otra. Se verifican a través
	//del vector de diferencia auxiliar.
	
	if ((dif_aux.x ==1.0f && dif_aux.y==2.0f) || (dif_aux.x==2.0f && dif_aux.y==1.0f))
		return true
	else return false;
}

