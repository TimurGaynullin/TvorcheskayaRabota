#include <iostream>
#include <glut.h>

float y = 0, dy = 0.01;
float x = 0, dx = 0.01;
float zoom = 0, dzoom = 0.01;
float color = 0;
float i = 0;

GLfloat light_position[] = { 4.0, 4.0, 0, 0.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_ambient[] = { 1.0, 1.0, 0, 1.0 };
GLfloat light_specular[] = { 1.0, 0.0, .0, 1.0 };

//no resizable
void init(void)
{
	glClearColor(0.25, 0.25, 0.85, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	gluLookAt(0, 0, -18, 0, 0, -15, 0, 1, 1);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


	dx += 0.001;
	x = sinf(dx);
	y += 1;

	
	glPushMatrix(); //нос
	glTranslatef(6.5, 0, -5);
	glRotatef(90+27, 0, 1, 0);
	glutSolidCone(1.3, 3, 25, 25);
	glPopMatrix();

	
	glPopMatrix();


	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);

	glBegin(GL_QUAD_STRIP); //корпус (прямоугольник)
	glColor3f(1, 0, 0);
	glVertex3f(-5, 1, -10); //лев верх
	glVertex3f(-5, -1, -10); //лев низ
	glVertex3f(5, 1, -10); //прав верх
	glVertex3f(5, -1, -10); //прав низ
	glEnd();

	glBegin(GL_QUAD_STRIP); //хвост (многоугольник)
	glColor3f(0, 1, 0);
	glVertex3f(5, 3, -10); //лев верх
	glVertex3f(2, 1, -10); //лев низ
	glVertex3f(8, 3, -10); //прав верх
	glVertex3f(5, 1, -10); //прав низ
	glEnd();

	glBegin(GL_QUAD_STRIP); //крыло (многоугольник)
	glColor3f(0, 1, 1);
	glVertex3f(-1, 0, -10); //лев верх
	glVertex3f(2, -2, -10); //лев низ
	glVertex3f(1, 0, -10); //прав верх
	glVertex3f(4, -2, -10); //прав низ
	glEnd();

	glutSwapBuffers();
	glutPostRedisplay();
}

void reshape(int width, int height)
{
	if (width == 0 || height == 0) return;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLdouble)((GLdouble)width / (GLdouble)height),
		0.5, 200.0);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1900, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Творческая работа");
	init();
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutMainLoop();
}


