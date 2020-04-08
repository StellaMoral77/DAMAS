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
	gluLookAt(4 * x, 4 * x, x * 20,                 //SE SITUA EN FUNCION DEL LADO DE LA CASILLA
		4 * x, 4 * x, 0.0,
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
	if ((button == GLUT_LEFT_BUTTON) & (state == GLUT_UP))
	{
		printf("\n\tx = %d\ty=%d", x, y);  ////PROBLEMON, NO COGE EL (0,0) EN EL TABLERO, SI NO EN LA PANTALLA////
	}
}

void OnTimer(int value)
{
	glutTimerFunc(50, OnTimer, 0);
	glutPostRedisplay();
}