#define N 8 //numero de filas y columnas tablero
#include <stdio.h>
#include "Tablero.h"
#include "glut.h"

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void onMouse(int button, int state, int x, int y);
Tablero Tabla;
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("DAMAS");
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(100, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(onMouse);
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float x = Tabla.GetLadoCasilla();
	gluLookAt(5.4 * x, 4 * x, x * 11.5,                 //SE SITUA EN FUNCION DEL LADO DE LA CASILLA
		5.4 * x, 4 * x, 0.0,
		0.0, 1.0, 0.0);

	Tabla.Dibuja();        ////CAMBIAR POR MUNDO.DIBUJA();///////

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Esta linea no se borra
	glutPostRedisplay();
}
void onMouse(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN))
	{
		printf("\n\tx = %d\ty=%d", x, y);
	}
	if ((button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN))
	{
		if (x >= 14 && x < 85.25) Tabla.SetColumnaSelec(0);    //j=0
		if (x >= 85.25 && x < 156.5) Tabla.SetColumnaSelec(1);
		if (x >= 156.5 && x < 227.75) Tabla.SetColumnaSelec(2);
		if (x >= 227.75 && x < 299) Tabla.SetColumnaSelec(3);
		if (x >= 299 && x < 370.25) Tabla.SetColumnaSelec(4);
		if (x >= 370.25 && x < 441.5) Tabla.SetColumnaSelec(5);
		if (x >= 441.5 && x < 512.75) Tabla.SetColumnaSelec(6);
		if (x >= 512.75 && x < 584) Tabla.SetColumnaSelec(7);

		if (y >= 14 && y < 85.25) Tabla.SetFilaSelec(7);    //i=7
		if (y >= 85.25 && y < 156.5) Tabla.SetFilaSelec(6);
		if (y >= 156.5 && y < 227.75) Tabla.SetFilaSelec(5);
		if (y >= 227.75 && y < 299) Tabla.SetFilaSelec(4);
		if (y >= 299 && y < 370.25) Tabla.SetFilaSelec(3);
		if (y >= 370.25 && y < 441.5) Tabla.SetFilaSelec(2);
		if (y >= 441.5 && y < 512.75) Tabla.SetFilaSelec(1);
		if (y >= 512.75 && y < 584) Tabla.SetFilaSelec(0);
	}

}

void OnTimer(int value)
{
	glutTimerFunc(50, OnTimer, 0);
	glutPostRedisplay();
}