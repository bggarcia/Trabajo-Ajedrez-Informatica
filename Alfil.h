#pragma once
#include "Figura.h"
class Alfil : public Figura {
  private:
	float lado;

public:
	Alfil(bool color_, int identidad_) :Figura(color_, identidad_) {
		lado = 0.1f;
		tipo="a";
	}
	Alfil();
	void dibuja();
	bool movLegal(int ident_);
	std::string getName();
};

