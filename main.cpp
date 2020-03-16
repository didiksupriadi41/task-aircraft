/*
 * GLUT Aircraft Demo
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
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

// globals

GLuint object;
static int zoomDefault = 40;

static float xRotation = 1;
static float yRotation = 1;
static float zRotation = 1;
static int zoom = 40;
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
    plane();
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
            zoom = zoomDefault;

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
    loadObj("ww1.obj");
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMotionFunc(motion);
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return EXIT_SUCCESS;
}
