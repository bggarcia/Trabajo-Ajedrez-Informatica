#pragma once
class Reina : public Pieza {
private:
  float lado;
public:
  Reina(bool color_,const std::string& tipo_,int identidad_,bool vida_):Figura(clor_,tipo_,identidad_,vida_){
    lado=0.1f;
  }
  Reina(bool color_,int identidad_):Figura(color_,identidad_){
    lado=0.1f;
    tipo="q";
  }  
};
	
