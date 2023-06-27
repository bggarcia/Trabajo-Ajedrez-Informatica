#pragma once
#include "Figura.h"
class Torre : public Pieza {
private:
	float lado;
public:
	
	void dibuja();
	void movLegal(int ident_);
	std::string getName();
};

