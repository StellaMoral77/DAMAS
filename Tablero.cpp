#define N 8 //Numero de columnas y filas del tablero
#include "TABLERO.h"
#include "glut.h"

Tablero::Tablero()
{
	lado_casilla = 1;
	R_blancas = G_blancas = B_blancas = 255;
	R_negras = G_negras = B_negras = 0;
	R_borde = 80;
	G_borde = 45;
	B_borde = 30;
}
void Tablero::Dibuja()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((i + j) % 2)
			{
				glColor3ub(R_blancas, G_blancas, B_blancas); //BLANCAS
			}
			else
			{
				glColor3ub(R_negras, G_negras, B_negras);  //NEGRAS
			}
			glBegin(GL_POLYGON);
			glVertex3f(i * lado_casilla, j * lado_casilla, 0.0f);
			glVertex3f(i * lado_casilla, (j + 1) * lado_casilla, 0.0f);
			glVertex3f((i + 1) * lado_casilla, (j + 1) * lado_casilla, 0.0f);
			glVertex3f((i + 1) * lado_casilla, j * lado_casilla, 0.0f);
			glEnd();
		}
	}
	//////DIBUJAR BORDE//////
	glColor3ub(R_borde, G_borde, B_borde);            //BORDE, SI SE PONE VALOR CONSTANTE, AL HACER MUY GRANDE EL LADO DE CASILLA..
	glBegin(GL_POLYGON);			   //EL BORDE NO SE VE, POR ESO DEPENDE DEL LADO POR UN FACTOR DE 0.2
	glVertex3f(-0.2 * lado_casilla, -0.2 * lado_casilla, 0.0f);
	glVertex3f(-0.2 * lado_casilla, (N + 0.2) * lado_casilla, 0.0f);
	glVertex3f((N + 0.2) * lado_casilla, (N + 0.2) * lado_casilla, 0.0f);
	glVertex3f((N + 0.2) * lado_casilla, -0.2 * lado_casilla, 0.0f);
	glEnd();
}
void Tablero::SetColorBlancas(int r, int g, int b)
{
	R_blancas = r;
	G_blancas = g;
	B_blancas = b;
}
void Tablero::SetColorNegras(int r, int g, int b)
{
	R_negras = r;
	G_negras = g;
	B_negras = b;
}
void Tablero::SetColorBorde(int r, int g, int b)
{
	R_borde = r;
	G_borde = g;
	B_borde = b;
}
void Tablero::SetLadoCasilla(float lado)
{
	lado_casilla = lado;
}
float Tablero::GetLadoCasilla()
{
	return lado_casilla;
}