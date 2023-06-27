#pragma once
class Rey : public Pieza {
private:
	float lado;
	bool primerMov;
public:
	Rey(bool color_, const std::string& tipo_, int identidad_, bool vida_) :Figura(color_, tipo_, identidad_, vida_) {
		lado = 0.1f;
	}
	Rey(bool color_, int identidad_) :Figura(color_, identidad_) {
		lado = 0.1f;
		primerMov = true;
		tipo = "k";
		
	}
	Rey();
	void dibuja();
	bool movLegal(int ident_);
	std::string getName();
};

