#include <GL/glut.h> 
#include <math.h>

//Animation
GLfloat animYRot = 0.0;
GLfloat x = 0.0;
GLUquadricObj* p = gluNewQuadric();

GLfloat gatey = 0.0;

GLfloat upY = 0.0f;

//variables to move Object Frame
GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 0.0f;

//variables to rotate Object Frame
GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

//variables to move the camera
GLfloat camX = 0.0f;
GLfloat camY = 0.0f;
GLfloat camZ = 0.0f;

//variables for show grid and axes
GLboolean showGrid = true;
GLboolean showAxes = true;

void initLighting() {
	GLfloat L0_Ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat L0_Diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat L0_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat L0_postion[] = { 0, 500, 0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, L0_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, L0_Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, L0_Specular);
	glLightfv(GL_LIGHT0, GL_POSITION, L0_postion);

	GLfloat specularReflectance[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularReflectance);
	glMateriali(GL_FRONT, GL_SHININESS, 50);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GLfloat globalAmbient[] = { 0.8, 0.8, 0.8, 1.0 };

	glEnable(GL_DEPTH_TEST);

	initLighting();
	//Turn on lighting
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_NORMALIZE);
}


void rectangularCube(GLfloat length, GLfloat width, GLfloat height, GLfloat r, GLfloat b, GLfloat g) {
	//wall bottom
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, width);
	glVertex3f(length, 0.0, width);
	glVertex3f(length, 0.0, 0.0);
	glEnd();

	//wall top
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(0.0, height, width);
	glVertex3f(length, height, width);
	glVertex3f(length, height, 0.0);
	glEnd();

	//wall front
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(0.0, height, width);
	glVertex3f(0.0, 0.0, width);
	glVertex3f(length, 0.0, width);
	glVertex3f(length, height, width);
	glEnd();

	//wall back
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(length, 0.0, 0.0);
	glVertex3f(length, height, 0.0);
	glEnd();

	//wall left
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, width);
	glVertex3f(0.0, height, width);
	glVertex3f(0.0, height, 0.0);
	glEnd();

	//wall right
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(length, 0.0, 0.0);
	glVertex3f(length, 0.0, width);
	glVertex3f(length, height, width);
	glVertex3f(length, height, 0.0);
	glEnd();
}

void drawFloor() {
	glPushMatrix();
	glTranslatef(-11.5, 0.0, -5.0);
	rectangularCube(23.0, 12.0, 0.05, 0.78 , 0.8 , 0.88);
	glPopMatrix();
}

void drawPillar() {
	rectangularCube(0.5, 0.5, 2.2, 0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(-0.05, 2.2, -0.05);
	rectangularCube(0.6, 0.6, 0.05, 0.7, 0.8, 0.9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.1, 2.25, -0.1);
	rectangularCube(0.7, 0.7, 0.1, 0.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.05, 0.0, -0.05);
	rectangularCube(0.6, 0.6, 0.05, 0.7, 0.8, 0.9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.1, -0.1, -0.1);
	rectangularCube(0.7, 0.7, 0.1, 0.5, 0.5, 0.5);
	glPopMatrix();

}

void drawGate() {
	glPushMatrix();
	rectangularCube(2.0, 0.02, 0.02, 1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.96, 0.0);
	glRotatef(25.0, 0.0, 0.0, 1.0);
	rectangularCube(2.21, 0.02, 0.02, 1.0, 1.0, 1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.1, 0.0, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	rectangularCube(1.0, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.125, 0.0);
	rectangularCube(1.09, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.15, 0.0);
	rectangularCube(1.16, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.175, 0.0);
	rectangularCube(1.24, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.20, 0.0);
	rectangularCube(1.34, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.225, 0.0);
	rectangularCube(1.44, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.25, 0.0);
	rectangularCube(1.52, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.25, 0.0);
	rectangularCube(1.62, 0.02, 0.02, 1.0, 0.0, 1.0);
	glTranslatef(0.0, -0.25, 0.0);
	rectangularCube(1.74, 0.02, 0.02, 1.0, 0.0, 1.0);
	glPopMatrix();
}

void drawOuterFence() {
	//front
	glPushMatrix();
	glTranslatef(2.1, 0.05, 6.1);
	rectangularCube(8.0, 0.1, 2.0, 0.790, 0.7009, 0.745);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.1, 0.05, 6.1);
	rectangularCube(8.1, 0.1, 2.0, 0.790, 0.7009, 0.745);
	glPopMatrix();

	//back
	glPushMatrix();
	glTranslatef(-10.1, 0.05, -3.1);
	rectangularCube(20.2, 0.1, 2.0, 0.790, 0.7009, 0.745);
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslatef(-10.1, 0.05, 6.1);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	rectangularCube(9.2, 0.1, 2.0, 0.790, 0.7009, 0.745);
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslatef(10.1, 0.05, 6.1);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	rectangularCube(9.2, 0.1, 2.0, 0.790, 0.7009, 0.745);
	glPopMatrix();

	//left pillar
	glPushMatrix();
	glTranslatef(-2.1, 0.2, 6.1);
	drawPillar();
	glPopMatrix();

	//right pillar
	glPushMatrix();
	glTranslatef(2.1, 0.2, 6.6);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	drawPillar();
	glPopMatrix();

	//gate
	glPushMatrix();
	glTranslatef(-2.0, 0.3, 6.25);
	glScalef(1.0, 1.5, 1.0);
	glRotatef(gatey, 0.0, 1.0, 0.0);
	drawGate();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.0, 0.3, 6.25);
	glScalef(1.0, 1.5, 1.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glRotatef(-gatey, 0.0, 1.0, 0.0);
	drawGate();
	glPopMatrix();
}

void drawFence_() {
	gluQuadricDrawStyle(p, GL_LINE);
	glTranslatef(0.3, 0.0, 0.0);
	glPushMatrix();
	gluCylinder(p, 0.02, 0.02, 1.0, 50, 50);
	glTranslatef(0.0, 0.0, 1.0);
	glutSolidCone(0.02, 0.05, 50, 50);
	glPopMatrix();
}

void drawFence(int x, float length) {
	gluQuadricDrawStyle(p, GL_LINE);
	glColor3f(0.2, 0.2, 0.2);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(p, 0.02, 0.02, 1.0, 50, 50);
	for (int i = 0; i <= x; i++) {
		drawFence_();
	}
	gluCylinder(p, 0.02, 0.02, 1.0, 50, 50);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.15, 0.0, 0.0);
	gluCylinder(p, 0.02, 0.02, length, 50, 50);
	glTranslatef(0.15, 0.0, 0.0);
	gluCylinder(p, 0.02, 0.02, length, 50, 50);
	glTranslatef(0.15, 0.0, 0.0);
	gluCylinder(p, 0.02, 0.02, length, 50, 50);
	glTranslatef(0.15, 0.0, 0.0);
	gluCylinder(p, 0.02, 0.02, length, 50, 50);
	glTranslatef(0.15, 0.0, 0.0);
	gluCylinder(p, 0.02, 0.02, length, 50, 50);
}

void cageFence() {
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-5.0, 0.1, 6.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	drawFence(29, 9.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, 0.1, 6.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	drawFence(29, 9.2);
	glPopMatrix();
	glPopMatrix();
}


void centerLawn() {
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0,0.2,0.0);
	glVertex3f(5.0,0.2,0.0);
	glVertex3f(5.0,0.2,5.0);
	glVertex3f(0.0,0.2,5.0);
	glEnd();
	glPopMatrix();
}

void streetLampbody(){
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
	gluQuadricDrawStyle(p, GL_LINE);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(p, 0.15, 0.15, 1.6, 32, 32);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -19, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.0, 0.25, 5, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.0, 0.25, 5, 32);
	glPopMatrix();
	glPopMatrix();
}

void streetLight(){
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.8, 0.8);
	glutSolidSphere(0.25, 16, 16);
	glPopMatrix();
	streetLampbody();
	glPopMatrix();
}

void drawPond() {
	glPushMatrix();
	gluQuadricDrawStyle(p, GL_LINE);
	glTranslatef(0.0, 0.3, 2.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluDisk(p, 1.8, 2.0, 10, 200);
	glColor3f(0.1, 0.0, 1.0);
	gluDisk(p, 0.0, 1.8, 10, 200);
	glPopMatrix();
}

void drawBench() {
	glPushMatrix();
	rectangularCube(1.1, 0.3, 0.2, 0.20, 0.0, 0.0);
	glTranslatef(0.0, 0.2, 0.08);
	glRotatef(-98.0, 1.0, 0.0, 0.0);
	rectangularCube(1.1, 0.3, 0.06, 0.24, 0.0, 0.0);
	glPopMatrix();
}

void centerPark() {
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-2.5, -0.1,-0.5);
	centerLawn();
	glTranslatef(0.5, 1.8, 0.5);
	streetLight();
	glTranslatef(4.0, 0.0, 0.0);
	streetLight();
	glTranslatef(0.0, 0.0, 4.0);
	streetLight();
	glTranslatef(-4.0, 0.0, 0.0);
	streetLight();
	glPopMatrix();

	glPushMatrix();
	drawPond();
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();
	glTranslatef(-0.07, 0.2, -0.1);
	glRotatef(-163, 0.0, 1.0, 0.0);
	drawBench();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.3, 0.2, 0.25);
	glRotatef(163, 0.0, 1.0, 0.0);
	drawBench();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.3, 0.2, 3.6);
	glRotatef(52, 0.0, 1.0, 0.0);
	drawBench();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 0.2, 2.8);
	glRotatef(-53, 0.0, 1.0, 0.0);
	drawBench();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void drawTree1() {
	gluQuadricDrawStyle(p, GL_LINE);
	glPushMatrix();
	glColor3f(0.24, 0.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(p, 0.15, 0.1, 1.3, 8, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.1, 0.0);
	glRotatef(-130.0, 1.0, 0.0, 0.0);
	glColor3f(0.24, 0.0, 0.0);
	glutSolidCone(0.1, 0.8, 5, 5);
	glColor3f(0.0, 1.0, 0.0);
	glScalef(0.15, 0.15, 0.15);
	glTranslatef(0.0, 0.0, 3.5);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.1, 0.0);
	glRotatef(-60.0, 1.0, 1.0, 0.0);
	glColor3f(0.24, 0.0, 0.0);
	glutSolidCone(0.1, 0.9, 5, 5);
	glColor3f(0.0, 1.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(0.0, 0.0, 4.0);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.1, 0.0);
	glRotatef(-110.0, 1.0, 1.0, 1.0);
	glColor3f(0.24, 0.0, 0.0);
	glutSolidCone(0.1, 0.9, 5, 5);
	glColor3f(0.0, 1.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(0.0, 0.0, 4.0);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef(-150.0, 1.0, 0.0, 1.0);
	glColor3f(0.24, 0.0, 0.0);
	glutSolidCone(0.1, 0.7, 5, 5);
	glColor3f(0.0, 1.0, 0.0);
	glScalef(0.15, 0.15, 0.15);
	glTranslatef(0.0, 0.0, 3.5);
	glutSolidDodecahedron();
	glPopMatrix();
}

void drawTree2() {
	glPushMatrix();
	gluQuadricDrawStyle(p, GL_LINE);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.24, 0.0, 0.0);
	gluCylinder(p, 0.15, 0.15, 1.3, 6, 80);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.5);
	glColor3f(0.0, 1.0, 0.0);
	gluCylinder(p, 0.6, 0.3, 0.7, 8, 8);
	glTranslatef(0.0, 0.0, 0.3);
	glColor3f(0.1, 1.0, 0.1);
	gluCylinder(p, 0.6, 0.2, 0.6, 8, 8);
	glTranslatef(0.0, 0.0, 0.3);
	glColor3f(0.2, 1.0, 0.2);
	glutSolidCone(0.5, 0.5, 8, 8);
	glPopMatrix();
	glPopMatrix();
}

//animals

//giraff
void drawGiraff() {
	gluQuadricDrawStyle(p, GL_LINE);
	glPushMatrix();

	glColor3f(1.0, 0.7, 0.1);

	//legs
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-0.2, 0.2, -0.7);
	gluCylinder(p, 0.08, 0.06, 0.6, 100, 100);
	glTranslatef(0.0, -0.4, 0.0);
	gluCylinder(p, 0.08, 0.06, 0.6, 100, 100);
	glTranslatef(0.4, 0.0, 0.0);
	gluCylinder(p, 0.08, 0.06, 0.6, 100, 100);
	glTranslatef(0.0, 0.4, 0.0);
	gluCylinder(p, 0.08, 0.06, 0.6, 100, 100);
	glPopMatrix();

	//body
	glScalef(1.4, 1.0, 1.0);
	glutSolidSphere(0.3, 50, 50);
	glPushMatrix();

	//neck
	glRotatef(-90.0, 1.0, 0.1, 0.0);
	glTranslatef(-0.16, 0.0, 0.2);
	gluCylinder(p, 0.08, 0.08, 0.9, 50, 50);

	//head
	glTranslatef(-0.06, 0.0, 0.9);
	glutSolidSphere(0.13, 50, 50);
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-0.09, 0.0, 0.02);
	glutSolidSphere(0.05, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.24, 0.0, 0.0);
	glRotatef(-90.0, 1.0, 0.1, 0.0);
	glTranslatef(-0.2, 0.05, 1.2);
	gluCylinder(p, 0.03, 0.01, 0.15, 50, 50);
	glColor3f(0.1, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.15);
	glutSolidSphere(0.03, 50, 50);
	glColor3f(0.24, 0.0, 0.0);
	glTranslatef(0.0, -0.1, -0.15);
	gluCylinder(p, 0.03, 0.01, 0.15, 50, 50);
	glColor3f(0.1, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.15);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslatef(0.25, 0.08, 0.0);
	glScalef(0.06, 0.06, 0.06);
	glutSolidDodecahedron();
	glPopMatrix();

	glPopMatrix();
}
void giraffCage() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-7.5, 1.2, 3.5);
	glScalef(1.2, 1.8, 1.2);
	glRotatef(-120.0, 0.0, 1.0, 0.0);
	drawGiraff();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.0, 0.2, 5.5);
	glScalef(1.0, 1.5, 1.0);
	drawTree1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 0.0, 2.0);
	rectangularCube(5.02, 0.2, 1.6, 0.790, 0.7009, 0.745);
	glPopMatrix();
	glPopMatrix();
}

void drawElephant() {
	glPushMatrix();
	glColor3f(0.05, 0.05, 0.0);
	gluQuadricDrawStyle(p, GL_LINE);
	//legs
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(p, 0.17, 0.15, 0.6, 15, 15);
	glTranslatef(0.0, 0.58, 0.0);
	gluCylinder(p, 0.17, 0.15, 0.6, 15, 15);
	glTranslatef(0.9, 0.0, 0.0);
	gluCylinder(p, 0.17, 0.15, 0.6, 15, 15);
	glTranslatef(0.0, -0.58, 0.0);
	gluCylinder(p, 0.17, 0.15, 0.6, 15, 15);
	glPopMatrix();

	//body
	glPushMatrix();
	glTranslatef(0.4, 0.8, -0.32);
	glScalef(2.0, 1.5, 1.7);
	glutSolidSphere(0.4, 15, 15);
	glPopMatrix();

	//head
	glPushMatrix();
	glTranslatef(-0.5, 1.1, -0.32);
	glScalef(1.0, 0.75, 0.85);
	glutSolidSphere(0.5, 15, 15);
	glPopMatrix();

	//trunk
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-0.75, -0.3, -1.0);
	gluCylinder(p, 0.2, 0.1, 0.6, 20, 20);
	glTranslatef(0.0, 0.0, 0.5);
	gluCylinder(p, 0.1, 0.05, 0.6, 20, 20);
	glPopMatrix();

	//ear
	glPushMatrix();
	glTranslatef(-0.7, 1.1, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluDisk(p, 0.0, 0.3, 15, 20);
	glTranslatef(0.7, 0.0, 0.0);
	gluDisk(p, 0.0, 0.3, 15, 20);
	glPopMatrix();

	glPopMatrix();

}
void elephantCage() {
	glPushMatrix();
	glTranslatef(-7.0, 0.0, 0.0);
	glRotatef(170, 0.0, 1.0, 0.0);
	glScalef(1.0, 1.8, 1.0);
	drawElephant();
	glPopMatrix();
}

void bird() {
	glPushMatrix();
	
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, 1.2, 0.0);
	glutSolidSphere(0.3, 50, 50);
	glTranslatef(-0.28, 0.25, 0.0);
	glutSolidSphere(0.16, 50, 50);
	glColor3f(0.3, 0.0, 0.0);
	glTranslatef(-0.14, 0.006, 0.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glutSolidCone(0.05, 0.1, 20, 20);

	glPopMatrix();
}

void birdCage() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(7.5,0.2,4.0);
	glScalef(1.0, 1.6, 1.0);
	drawTree1();
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(p, GL_LINE);
	glColor3f(0.24, 0.1, 0.0);
	glTranslatef(7.0, 1.2, 4.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluPartialDisk(p, 0.8, 1.2, 10, 20, 0.0, -180.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.4, 1.5, 5.0);
	glScalef(0.5, 0.5, 0.5);
	bird();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.9, 0.0, 2.0);
	rectangularCube(5.02, 0.2, 1.6, 0.790, 0.7009, 0.745);
	glPopMatrix();

	glPopMatrix();
}

void bear() {
		glPushMatrix();
		GLfloat color[4] = { 0.92f, 0.814f, 0.382f, 1.0f };
		glColor4fv(color);

		GLfloat dog_specular[] = { 0.1f, 0.1f, 0.1f },
			dog_shininess = 0.1f;

		glMaterialfv(GL_FRONT, GL_SPECULAR, dog_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, dog_shininess);
		glMaterialf(GL_FRONT, GL_EMISSION, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

		//torso
		glPushMatrix();
		glScalef(2.0f * 0.3f, 2.0f * 0.3f, 4.0f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//legs
		glPushMatrix();
		glRotatef(0.0, 1, 0, 0);
		glTranslated(-1 * 0.3, -2.5 * 0.3, -2 * 0.3);
		glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		glPushMatrix();
		glRotatef(0.0, 1, 0, 0);
		glTranslated(0.3f, -2.5f * 0.3f, -0.6);
		glScalef(0.5f * 0.3f, 0.6f, 0.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		glPushMatrix();
		glRotatef(0.0, 1, 0, 0);
		glTranslated(0.3f, -2.5f * 0.3f, 2.0 * 0.3f);
		glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		glPushMatrix();
		glRotatef(0.0, 1, 0, 0);
		glTranslated(-0.3f, -2.5f * 0.3f, 0.6);
		glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//tail
		glPushMatrix();
		glTranslated(0.0f, 0.0f, -3.8f * 0.3f);
		glRotatef(-30, 1, 0, 0);
		glRotatef(110.0, 1, 0, 0);
		glRotatef(0.0, 0, 1, 0);
		glRotatef(0.0, 0, 1, 0);
		glScalef(0.5f * 0.3f, 0.5f * 0.3f, 1.8f * 0.3f);

		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//head rotation
		glPushMatrix();
		glRotatef(10.0, 1, 0, 0);
		glRotatef(0.0, 0, 1, 0);

		//head
		glPushMatrix();
		glTranslated(0.0f, 2.5f * 0.3f, 3.0f * 0.3f);
		glScalef(1.5f * 0.3f, 1.55f * 0.3f, 1.6f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//nose
		glPushMatrix();
		glTranslated(0.0f, 2.2f * 0.3f, 4.2f * 0.3f);
		glScalef(0.8f * 0.3f, 0.5f * 0.3f, 1.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//ears
		glPushMatrix();
		glTranslated(-0.8f * 0.3f, 3.8f * 0.3f, 2.6f * 0.3f);
		glScalef(0.5f * 0.3f, 0.3f, 0.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.8f * 0.3f, 3.8f * 0.3f, 2.6f * 0.3f);
		glScalef(0.5f * 0.3f, 1.0f * 0.3f, 0.5f * 0.3f);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//eyes
		GLfloat eyes_specular[] = { 0.4f, 0.4f, 0.4f },
			eyes_shininess = 1.0f;
		GLfloat black[] = { 0,0,0,1 };
		glColor4fv(black);
		glMaterialfv(GL_FRONT, GL_SPECULAR, eyes_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, eyes_shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, black);

		glPushMatrix();
		glTranslated(0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
		glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
		glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
		glutSolidCube(1);
		glPopMatrix();

		glPopMatrix();

		glPopMatrix();
}

void bearCage() {
	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	glTranslatef(10.0, 1.2, -1.0);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	bear();
	glPopMatrix();
}

void zoo() {
	glPushMatrix();
	drawFloor();
	drawOuterFence();
	cageFence();
	centerPark();
	glPushMatrix();
	glTranslatef(1.0, 0.0, -8.0);
	drawTree2();
	glTranslatef(-8.0, 0.0, 0.0);
	drawTree2();
	glPopMatrix();

	giraffCage();
	elephantCage();
	birdCage();
	bearCage();
	glPopMatrix();
}

void drawGrid() {
	GLfloat step = 1.0f;
	GLint line;
	glBegin(GL_LINES);
	for (line = -20; line <= 20; line += step) {
		glColor3f(1, 1, 1);
		glVertex3f(line, -0.4, 20);
		glVertex3f(line, -0.4, -20);
		glVertex3f(20, -0.4, line);
		glVertex3f(-20, -0.4, line);
	}
	glEnd();
}

void drawAxes() {
	glBegin(GL_LINES);
	glLineWidth(1.5);

	//x
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-100, 0, 0);
	glVertex3f(100, 0, 0);
	//y
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -100, 0);
	glVertex3f(0, 100, 0);
	//z
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -100);
	glVertex3f(0, 0, 100);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	//camera position
	gluLookAt(0.0, 2.0 + camY, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0 + camX, 0.0, 0.5 + camZ);



	// move the object frame using keyboard keys
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

	//if (showGrid)
	//	drawGrid(); //draw the grids
	//if (showAxes)
		drawAxes(); //draw the xyz axes
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
	zoo();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;
	if (key == GLUT_KEY_DOWN)
		camY -= 1;
	if (key == GLUT_KEY_LEFT)
		rotY -= 10.0;
	if (key == GLUT_KEY_RIGHT)
		rotY += 10.0;
	
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'l')
		camX += 0.5;
	if (key == 'r')
		camX -= 0.5;
	if (key == 'f')
		camZ += 0.5;
	if (key == 'b')
		camZ -= 0.5;
	if (key == 'o')
		gatey = -90.0;
	if (key == 'c')
		gatey = 0.0;
	glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Define the Perspective projection frustum 
	gluPerspective(120.0, aspect_ratio, 1.0, 100.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	// keyboard function activation
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	//glutTimerFunc(60.0, timer, 1);
	init();
	glutMainLoop();
	return 0;
}