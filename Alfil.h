#pragma once
#include "Figura.h"
class Alfil : public Figura {
  private:
	float lado=0.1f;

public:
	Alfil(bool color_, int identidad_) :Figura(color_, identidad_) {
		tipo="a";
	}
	Alfil();
	void dibuja();
	bool movLegal(int ident_);
	std::string getName();
};

