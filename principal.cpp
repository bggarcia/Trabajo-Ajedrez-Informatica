#include "freeglut.h" 
#include "peon.h"
#include "torre.h"

Peon peonblanco1;
Torre torreblanca1;

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);

int main(int argc, char* argv[]) 
{ 
	//Inicializar el gestor de ventanas FREEGLUT 
	//y crear la ventana 
	glutInit(&argc, argv); 
	glutInitWindowSize(800,600); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	
	//habilitar luces y definir perspectiva 
	glEnable(GL_LIGHT0); 
	glEnable(GL_LIGHTING); 
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_COLOR_MATERIAL); 
	glMatrixMode(GL_PROJECTION); 
	gluPerspective( 40.0, 800/600.0f, 0.1, 150); 

	//Registrar los callbacks 
	glutDisplayFunc(OnDraw); 
	glutTimerFunc(25,OnTimer,0); 
	glutKeyboardFunc(OnKeyboardDown);

	//inicializaión datos

	//PEON BLANCO 1
	peonblanco1.setColor(255, 255, 255);
	peonblanco1.SetPos(1, 0);
	peonblanco1.SetTamaño(0.5);

	//TORRE BLANCA 1
	torreblanca1.setColor(255, 255, 255);
	torreblanca1.SetPos(0, 0);
	torreblanca1.SetTamaño(0.5);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();


	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	//Para definir el punto de vista 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	
	gluLookAt(0.0, 10, 20, // posicion del ojo 
		0.0, 0.0, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

	//Dibujar forma simple
	/*
	* glTranslatef(0, 0, 0);
	glColor3ub(0, 150, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0f, 5.0f, 0.0f);
	glVertex3f(-5.0f, 5.0f, 0.0f);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glVertex3f(5.0f, -5.0f, 0.0f);
	glEnd();
	*/

	//PEÓN 1
	peonblanco1.dibuja();

	//TORRE 1
	torreblanca1.dibuja();
	
	//Al final, cambiar el buffer (redibujar) 
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnTimer(int value)
{
	
	//no borrar estas lineas 
	glutTimerFunc(25,OnTimer,0); 
	glutPostRedisplay();

}
void OnKeyboardDown(unsigned char key, int x_t, int y_t) 
{
	//poner aqui el código de teclado

	if (key == 'a')
	{
		peonblanco1.Mueve();
	}
	
	int movimientotorre;
	if (key == 'q')
	{
		movimientotorre = 0;
		torreblanca1.Mueve(movimientotorre);
	}
	if (key == 'w')
	{
		movimientotorre = 1;
		torreblanca1.Mueve(movimientotorre);
	}
	if (key == 'e')
	{
		movimientotorre = 2;
		torreblanca1.Mueve(movimientotorre);
	}
	if (key == 'r')
	{
		movimientotorre = 3;
		torreblanca1.Mueve(movimientotorre);
	}

	glutPostRedisplay();
}