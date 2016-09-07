/*Name: Eduardo Azuri Gaytán Martínez A01165988
  First Partial Exam*/

#include <windows.h>
#include <gl/glut.h>

#include <stdlib.h>
//Variables for the rotation angle and movement of the teapot.
float teapotRotationAngle = 0.0f;
float teapotMove = 0.0f;
float teapotMoveX = 0.0f;
float teapotDirX = 0.02f;
float sphereMoveX = 0.0f;
float sphereDirX = 0.1f;
float sphereDirY = 0.1f;
float rotateCube = 0.01f;
float sphereMoveY = -9.3f;
static bool paused = false;
static bool restart = false;

static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void collision() {
	if (sphereMoveX >= 9.5) {
		sphereMoveX = 9.5;
	}
	if (sphereMoveX <= -9.5) {
		sphereMoveX = -9.5;
	}
}

static void display(void)
{
	int r = rand() % 6;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Add rotation to the teapot for every frame that is rendered.
	teapotMove += 0.01f;
	//Draw teapot.
	glPushMatrix();
	glTranslated(0, 4.0, -10);
	glColor3f(0.4, 1, 0.2);
	glTranslatef(teapotMoveX, 0, 0);
	glutSolidTeapot(0.5);
	//If the teapot leaves the screen, it appears on the other side to continue the movement.
	if (teapotMoveX >= 6.0 || teapotMoveX <= -6.0) {
		teapotDirX = teapotDirX * -1;
	}
	glPopMatrix();

	//Draw sphere.
	glPushMatrix();
	glTranslatef(sphereMoveX, sphereMoveY, -20);
	glColor3f(0.8, 0.7, .2);
	glScalef(0.25, 0.25, 0.25);
	glutSolidSphere(2, 16, 16);
	collision();
	
	glPopMatrix();
	if (r = 1) {

	}
	else if (r = 2) {

	}
	else if (r = 3) {

	}
	else if (r = 4) {

	}
	else if (r = 5) {

	}


	teapotMoveX += teapotDirX;

	glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
	if (key == 'D' || key == 'd') {
		sphereMoveX += 0.5;
	}
	if (key == 'A' || key == 'a') {
		sphereMoveX -= 0.5;
	}
	if (key == 'Q' || key == 'q') {
		exit(0);
	}
	if (key == 'P' || key == 'p') {
		paused = !paused;
	}
	if (key == 'R' || key == 'r') {
		
	}

	glutPostRedisplay();
}

static void idle(void)
{
	glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{	

	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();

	return EXIT_SUCCESS;
}
