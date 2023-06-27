#pragma once
#include "Figura.h"
#include <iostream>
#include <string>

class Peon : public Figura {
private:
        float altura;
	bool primerMov

public:
	Peon(bool color_,const std::string &tipo_,int identidad_,bool vida_):Figura(color_,tipo_,identidad_,vida_){
		altura=0.1f;
		primerMov=true;
	}
	Peon(bool color_,int identidad_):Figura(color_,identidad_){
		altrua=0.1f;
		primerMov=true;
		tipo="p";
	}
        Peon();
	void dibuja();
};

