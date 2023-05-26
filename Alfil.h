#pragma once
class Alfil : public Figura {
  private:
	float lado;
	Tablero* posicionesLegales[NUM];
	Vector2D max, min;
public:
	Alfil(bool color_, const std::string& tipo_) :Figura(color, tipo) {
		lado = 0.1f;
		color=color_;
	}
	Alfil();
	void dibuja();
	bool movLegal(int ident_);
	std::string getName();
};

