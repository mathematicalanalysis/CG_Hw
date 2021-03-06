#include "glut.h"

float rotate_left = 0;
float rotate_right = 0;
float rotate_speed = 0.1;

void draw_triangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();
}

void draw_square()
{
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 1.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
}

void port_segment_left(int x, int y, int width, int height, float tx, float ty, float tz)
{
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glViewport(x, y, width, height);
	glLoadIdentity();

	glTranslatef(tx, ty, tz);
	glRotatef(rotate_left, 0, 1, 0);
	rotate_left += rotate_speed;
	draw_triangle();
}

void port_segment_right(int x, int y, int width, int height, float tx, float ty, float tz)
{
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glViewport(x, y, width, height);
	glLoadIdentity();

	glTranslatef(tx, ty, tz);
	glRotatef(rotate_right, 1, 0, 0);
	rotate_right += rotate_speed;
	draw_square();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	port_segment_right(0, 0, 300, 300, 1, 1, 0);
	port_segment_right(0, 300, 300, 300, 1, -1, 0);
	port_segment_right(300, 0, 300, 300, -1, 1, 0);
	port_segment_right(300, 300, 300, 300, -1, -1, 0);

	glViewport(0, 0, 600, 600);
	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glEnd();

	glutSwapBuffers();
}
void idle()
{
	display();
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("MyScreen");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutMainLoop();
	return 0;
}