//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
static void redraw2(void);
void DrawCircle(float cx, float cy, float r, int num_segments);
//void Keyboard(unsigned char key, int x1, int y1);
void specialKeys(int key, int x, int y);
void draw_wall();
void specialKeys1(int key, int x1, int y1);
double rx = 0, ry = 20, rz = 10000, e = 1e-3, x = 15, y = 20, z = 15, b = 0, m = 0, tz = 0, tx = 0, ty = 0, trz = 0, trx = 0, t_ry = 0, bx = 15, bz = 15;
bool map = 0;
int uz = 0, uy = 1;

float i=270.0;	

float xeye=0;
float yeye=20;
float zeye=100;

float xcenter=0;
float ycenter=0;
float zcenter=0;

void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("First Example");
	glutDisplayFunc(redraw2);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45, 1.0, 10.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
	//init();
	glDisable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}


void draw_wall() {
	int width = 50, hieght = 30;

	//**************** outer borders ************************** 
	glColor3f(0.0f, 0.3f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0, hieght, 0);  // Top left
	glVertex3f(0, hieght, 175);   // Top right
	glVertex3f( 0, 0, 175);  // Bottom right
	glVertex3f(0, 0, 0);  // Bottom left
	glEnd();

	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(200, hieght, 0);  // Top left
	glVertex3f(0, hieght, 0);   // Top right
	glVertex3f(0, 0, 0);  // Bottom right
	glVertex3f(200, 0, 0);  // Bottom left
	glEnd();

	glColor3f(0.0f, 0.3f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(200, hieght, 0);  // Top left
	glVertex3f(200, hieght,200);   // Top right
	glVertex3f(200, 0, 200);  // Bottom right
	glVertex3f(200, 0, 0);  // Bottom left
	glEnd();


	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(200, hieght, 200);  // Top left
	glVertex3f(0, hieght, 200);   // Top right
	glVertex3f(0, 0, 200);  // Bottom right
	glVertex3f(200, 0, 200);  // Bottom left
	glEnd();


	//*line 7
	glColor3f(0.0f, 0.3f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(25, hieght, 125);  // Top left
	glVertex3f(25, hieght, 200);   // Top right
	glVertex3f(25, 0, 200);  // Bottom right
	glVertex3f(25, 0, 125);  // Bottom left
	glEnd();

	//*line 6
	glColor3f(0.0f, 0.3f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(50, hieght, 150);  // Top left
	glVertex3f(50, hieght, 200);   // Top right
	glVertex3f(50, 0, 200);  // Bottom right
	glVertex3f(50, 0, 150);  // Bottom left
	glEnd();

	//*line 5
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(150, hieght, 150);  // Top left
	glVertex3f(50, hieght, 150);   // Top right
	glVertex3f(50, 0, 150);  // Bottom right
	glVertex3f(150, 0, 150);  // Bottom left
	glEnd();

	//*line 4
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(100, hieght, 125);  // Top left
	glVertex3f(25, hieght, 125);   // Top right
	glVertex3f(25, 0, 125);  // Bottom right
	glVertex3f(100, 0, 125);  // Bottom left
	glEnd();

	//*line 3
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(150, hieght, 100);  // Top left
	glVertex3f(0, hieght, 100);   // Top right
	glVertex3f(0, 0, 100);  // Bottom right
	glVertex3f(150, 0, 100);  // Bottom left
	glEnd();

	//*line 2
	glColor3f(0.0f, 0.3f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(150, hieght, 50);  // Top left
	glVertex3f(150, hieght, 100);   // Top right
	glVertex3f(150, 0, 100);  // Bottom right
	glVertex3f(150, 0, 50);  // Bottom left
	glEnd();


	//*line 1
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(150, hieght, 50);  // Top left
	glVertex3f(50, hieght, 50);   // Top right
	glVertex3f(50, 0, 50);  // Bottom right
	glVertex3f(150, 0, 50);  // Bottom left
	glEnd();
}

void specialKeys1(int key, int x, int y) {
    switch (key) {
	case GLUT_KEY_UP:
	if (!map) {
      x = x +0.1 * (rx - x);
			z = z +0.1 * (rz - z);
	}
    break;
    case GLUT_KEY_DOWN: 
	if (!map) {       
			x = x -0.01 * (rx - x);
			z = z -0.1 * (rz - z);
	}
    break;
	case GLUT_KEY_LEFT: 
	if (!map) {
			rx = 1000 * cos(i * 3.14 / 180) - x;
			rz = 1000 * sin(i * 3.14 / 180) - z;
			i -= 2;
	}
    break;
    case GLUT_KEY_RIGHT: 
	if (!map) {
			rx = 1000 * cos(i * 3.14  / 180) - x;
			rz = 1000 * sin(i * 3.14 / 180) - z;
			i += 2;
	}
	break;
	case GLUT_KEY_F1:
		if (!map) {
			tz = z;
			tx = x;
			ty = y;
			trz = rz;
			t_ry = ry;
			trx = rx;
			x = 75;
			y = 390;
			z = 75;
			rx = 100;
			ry = 0;
			rz = 100;
			uy = 0;
			uz = 1;
			map = !map;
		}
		break;
	case GLUT_KEY_F2:
		if (map) {
			x = tx;
			y = ty;
			z = tz;
			rx = trx;
			ry = t_ry;
			rz = trz;
			uy = 1;
			uz = 0;
			map = !map;
		}
		break;
    default:break;
    }
}

void specialKeys(int key, int x1, int y1) {

	switch (key) {
	case GLUT_KEY_END: exit(0);break;
	case GLUT_KEY_LEFT:
		if (!map) {
			if (rx == 0 && rz > 0) {
				rz -= 150;
				rx += 150;
			}
			else if (rx > 0) {
				rz -= 150;
				if (rz > 0) {
					rx = 10000 - rz;
				}
				else {
					rx = rz + 10000;
				}
			}
			else {
				rz += 150;
				if (rz < 0) {
					rx = -rz - 10000;
				}
				else {
					rx = rz - 10000;
				}
			}
		}
		break;
	case GLUT_KEY_RIGHT:
		if (!map) {
			if (rx == 0 && rz > 0) {
				rz -= 150;
				rx -= 150;
			}
			else if (rx < 0) {
				rz -= 150;
				if (rz > 0) {
					rx = rz - 10000;
				}
				else {
					rx = -rz - 10000;
				}
			}
			else {
				rz += 150;
				if (rz < 0) {
					rx = rz + 10000;
				}
				else {
					rx = 10000 - rz;
				}
			}
		}
		break;
	case GLUT_KEY_UP:
		if (!map) {
			if (rx == x) {
				if (rz > z)z += 1;
				else z -= 1;
			}
			else if (rz == z) {
				if (rx > x)x += 1;
				else x -= 1;
			}
			else {
				m = (rz - z) / (rx - x);
				b = z - (m * x);
				if (rx > x)x += 1;
				else x -= 1;
				z = (m * x) + b;
			}
			bx = x;
			bz = z;
		}
			break;
	case GLUT_KEY_DOWN:
		if (!map) {
			if (rx == x) {
				if (rz > z)z -= 1;
				else z += 1;
			}
			else if (rz == z) {
				if (rx > x)x -= 1;
				else x += 1;
			}
			else {
				m = (rz - z) / (rx - x);
				b = z - (m * x);
				if (rx > x)x -= 1;
				else x += 1;
				z = (m * x) + b;
			}
			bx = x;
			bz = z;
		}
		break;
	case GLUT_KEY_F1:
		if (!map) {
			tz = z;
			tx = x;
			ty = y;
			trz = rz;
			t_ry = ry;
			trx = rx;
			x = 75;
			y = 390;
			z = 75;
			rx = 100;
			ry = 0;
			rz = 100;
			uy = 0;
			uz = 1;
			map = !map;
		}
		break;
	case GLUT_KEY_F2:
		if (map) {
			x = tx;
			y = ty;
			z = tz;
			rx = trx;
			ry = t_ry;
			rz = trz;
			uy = 1;
			uz = 0;
			map = !map;
		}
		break;
	default:break;
	}
		std::cout << "rx=" << rx << "***" << "rz=" << rz << "***" << "x=" << x << "***" << "z=" << z << "\n";
}

static void redraw2(void)
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(xeye,yeye,zeye,   xcenter,ycenter,zcenter,   0,1,0);			

	gluLookAt(x, y, z, rx, ry, rz, 0, uy, uz);
	//gluLookAt(75, 350, 75, 100, 0, 100, 0, 1, 0);
	// Set up the first light position and properties (LIGHT0)
	/*GLfloat light_position_0[] = {50.0, 50.0, 50.0, 0.0}; // Directional light from the top - right
	GLfloat ambient_color_0[] = { 0.5, 0.5, 0.5, 1.0 }; // Ambient light color for LIGHT0
	GLfloat diffuse_color_0[] = { 1.0, 1.0, 1.0, 1.0 }; // Diffuse light color for LIGHT0
	GLfloat specular_color_0[] = { 1.0, 1.0, 1.0, 1.0 }; // Specular light color for LIGHT0
	glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color_0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color_0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color_0);

	// Set material properties for the teapot
	GLfloat teapot_ambient[] = { 0, 0, 0, 1.0 };
	GLfloat teapot_diffuse[] = { 0, 1, 0, 1.0 };
	GLfloat teapot_specular[] = { 0, 1, 0, 1.0 };
	GLfloat teapot_shininess = 1.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, teapot_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, teapot_diffuse);
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, teapot_specular);

	glMaterialf(GL_FRONT, GL_SHININESS, teapot_shininess);*/



	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	draw_wall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(bx, 50.0f, bz);
	glColor3f(0.6f, 0.6f, 0.6f);
	glutSolidSphere(5.0, 20, 16);
	glPopMatrix();
	

	//glutKeyboardFunc(Keyboard);
	glutSpecialFunc(specialKeys);
	glutSwapBuffers();
	glutPostRedisplay();
}

