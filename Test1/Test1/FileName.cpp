#include <windows.h>
#include <GL/glut.h>
void init(void);
void display(void);
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First OpenGL Application");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void init(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.5);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-5.0, 5.0, 5.0, -5.0);
	glutSwapBuffers();
}