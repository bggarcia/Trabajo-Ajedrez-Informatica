#pragma once
class Alfil : public Pieza {
  private:
	float lado;
	Tablero* posicionesLegales[NUM];
	Vector2D max, min;
public:
	Alfil(bool color_) :Figura(color, 'a') { lado = 0.1f; }
	Alfil();
	void dibuja();
	bool movLegal(int ident_);
};

