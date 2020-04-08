class Tablero
{
private:
	float lado_casilla;   ///1 <= lado_casilla < 7.5///   //////NO SE PINTA A PARTIR DE 7.5, NO SÉ POR QUÉ///////
	int R_blancas, G_blancas, B_blancas;
	int R_negras, G_negras, B_negras;
	int R_borde, G_borde, B_borde;
public:
	Tablero();
	void Dibuja();
	void SetLadoCasilla(float);
	void SetColorBlancas(int, int, int);
	void SetColorNegras(int, int, int);
	void SetColorBorde(int, int, int);
	float GetLadoCasilla();
};