#pragma once
#include "Figura.h"
class Torre : public Pieza {
private:
	float lado;
public:
	Torre(bool color_, const std::string& tipo_,int identidad_,bool vida_) :Figura(color_, tipo_,identidad_,vida_) {
		lado = 0.1f;
	}
	Torre(bool color_, int identidad_) :Figura(color_, identidad_) {
		lado = 0.1f;
		tipo = "t";	
	}
	Torre();
	void dibuja();
	void movLegal(int ident_);
	std::string getName();
};

