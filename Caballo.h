#pragma once
#include "Figura.h"
class Caballo : public Figura {
private:
	float lado=0.1f;

public:
	Caballo(bool color_,int identidad_) :Figura(color_,identidad_)                {tipo="c";}
	Caballo();
	void dibuja();
	bool movLegal(int ident_);
};


