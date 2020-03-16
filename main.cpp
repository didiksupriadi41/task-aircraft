/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry zoom and xRotation can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
//#include <GL/freeglut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

GLuint object;

static float xRotation = 1;
static float yRotation = 1;
static float zRotation = 1;
static int zoom = 10;
static int x = 30;
int oldX = 0;
int oldY = 0;
float angle = 0;
float xz = 1;
float xy = 0;
/* GLUT callback Handlers */

static void resize(int width, int height) {
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void fan(){
    glColor3d(0.5,1,0);
    glPushMatrix();
        glScaled(1,1,1);
        glutSolidSphere(0.05,7,7);
    glPopMatrix();

    glColor3d(0.5,1,0);
    glPushMatrix();
        glScaled(0.05,0.7,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0.5,1,0);
    glPushMatrix();
        glRotated(90,1,0,0);
        glScaled(0.05,0.7,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

}
void plane2(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    /// Main body
    glColor3d(0.5,1,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(3,0.4,0.5);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(1.7,0.1,0);
        glScaled(1.5,0.7,0.8);
        glRotated(40,0,1,0);
        glutSolidSphere(0.45,30,30);
    glPopMatrix();


    ///Right
    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(0,0,1.2);
        glRotated(-50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(-0.3,-0.15,1.5);
        glRotated(90,0,1,0);
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(0.2,-0.15,0.9);
        glRotated(90,0,1,0);

//        /// FAN
//        glPushMatrix();
//            glTranslated(0,0,0.5);
//            glRotated(10*a,0,0,1);
//            glScaled(0.1,0.1,0.1);
//            fan();
//        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    ///Left
    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(0,0,-1.2);
        glRotated(50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(-25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(-0.3,-0.15,-1.5);
        glRotated(90,0,1,0);
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(0.2,-0.15,-0.9);
        glRotated(90,0,1,0);
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();


    ///Pechoner pakha
    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

        ///Right
        glColor3d(0.8,1,0);
        glPushMatrix();
            glTranslated(0.4,0,1.5);
            glRotated(-30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

        ///left
        glColor3d(0.8,1,0);
        glPushMatrix();
            glTranslated(0.4,0,-1.5);
            glRotated(30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    /// Pesoner Uporer pakha
    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(-2.7,0.5,0);
        glRotated(45,0,0,1);
        glScaled(0.8,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.5);
    glPopMatrix();

    glColor3d(0.8,1,0);
        glPushMatrix();
        glTranslated(-2.95,0.85,0);
        glRotated(90,0,1,0);
        glScaled(0.05,0.05,0.6);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();


//    ///FANS
//
//    glPushMatrix();
//        glTranslated(0,0,0);
//        glRotated(10*a,0,0,1);
//        glRotated(90,1,0,0);
//        fan();
//    glPopMatrix();
}



void loadObj(char *fname)
{
  FILE *fp;
  int read;
  GLfloat x, y, z;
  char ch;
  object=glGenLists(1);
  fp=fopen(fname,"r");
  if (!fp) {
    printf("can't open file %s\n", fname);
    exit(1);
  }
  glPointSize(2.0);
  glNewList(object, GL_COMPILE);
  {
    glPushMatrix();
    glBegin(GL_POINTS);
    while(!(feof(fp))) {
      read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
      if(read==4&&ch=='v') {
        glVertex3f(x,y,z);
      }
    }
    glEnd();
  }
  glPopMatrix();
  glEndList();
  fclose(fp);
}


void plane() {

    glColor3f(0.43,0.45,0.44);
    glCallList(object);
}

void drawStrokeText(char* str,int x,int y,int z) {
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.003f,0.003f,10);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

//void WriteText(float x, float y, void *font, const unsigned char* Text)
//{
//    char *c;
//    glColor3f(1.0f, 1.0f, 1.0f);
//    glRasterPos3f(0, 0, 0);
//    glutBitmapString(font, Text);
//}

static void display(void) {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);

    glLoadIdentity();

    gluLookAt(	0.0, 4.5, 10.0,
                0 + cos(xz), 4, 0 + sin(xz),
                0 + cos(xy), 1.0f, 0.0f + sin(xy));

    glPushMatrix();
    glTranslated(0,0,-80);
    glRotated(xRotation,1,0,0);
    glRotated(yRotation,0,1,0);
    glRotated(zRotation,0,0,1);
    glRotated(30,1,0,0);
    glScaled(zoom,zoom,zoom);
    plane2();
    glPopMatrix();

    drawStrokeText("Zoom in and out: + and -\n Rotation x y z: a s d\n Mengitari model: c v z x \nReset: r\nQuit: q\n",-10,1,-5);
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y) {
    switch (key)
    {
        case 'r':
            xRotation = 1;
            yRotation = 1;
            zoom = 1;
            break;
        case 'q':
            exit(0);
            break;

        case '+':
            zoom++;
            break;

        case '-':
            if (xRotation > 1) {
                zoom--;
            }
            break;
        case 'a':
            xRotation++;
            break;
        case 's':
            yRotation++;
            break;
        case 'd':
            zRotation++;
            break;
        case 'z':
            // calculateAngle(0.01);
            xz += 0.01;
                    break;
        case 'x':
            xz -= 0.01;
            break;
        case 'c':
            xy += 0.01;
            // if (xy >= M_PI) xy=;
            printf("%f\n", cos(xy));
            printf("{%f 1.0 %f]\n", 0+cos(xy), 0+sin(xy));
            break;
        case 'v':
            xy -= 0.01;
            break;


    }

    glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
}

void motion(int x, int y) {
    xRotation +=(y-oldY);
    oldY = y;
    yRotation +=(x-oldX);
    oldX = x;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    //loadObj("ww1.obj");
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMotionFunc(motion);
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return EXIT_SUCCESS;
}
