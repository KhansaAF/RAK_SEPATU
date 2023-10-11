///////////////////////////////////
// rak sepatu.cpp
//
// OpenGL program to draw a rak sepatu.
// 
// Sumanta Guha.
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 

// Drawing routine.
void drawScene(void)

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

gluLookAt(50.0, 50.0, 150.0,  // Posisi kamera
	0.0, 0.0, 0.0,  // Pusat pandang
	0.0, 1.0, 0.0); // Vektor atas

glColor3f(1.0, 0.0, 0.0); // Warna hijau
glScalef(90.0, 55.0, 60.0);
glutSolidCube(1.0); // Membuat balok 3D

// Menggambar pemisah pertama (kubus kecil di dalam balok)
glPushMatrix();
glColor3f(0.0, 0.0, 0.0);
glTranslatef(0.0, -0.2, 0.2);
glScalef(1.7, 0.2, 1.6);
glutSolidCube(0.5);
glPopMatrix();

// Menggambar pemisah kedua (kubus kecil di dalam balok)
glPushMatrix();
glColor3f(0.0, 0.0, 0.0);
glTranslatef(0.0, 0.4, 0.2);
glScalef(1.7, 0.2, 1.6);
glutSolidCube(0.5);
glPopMatrix();

// Menggambar pemisah ketiga (kubus kecil di dalam balok)
glPushMatrix();
glColor3f(0.0, 0.0, 1.0);
glTranslatef(0.0, 0.1, 0.3);
glScalef(1.7, 0.2, 1.2);
glutSolidCube(0.5);
glPopMatrix();


glutSwapBuffers();

}


// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.


	
	void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / (float)height, 1.0, 200.0);

}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("rak sepatu.cpp");
	
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
