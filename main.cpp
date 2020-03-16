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
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

// globals

GLuint object;

static int slices = 1;
static int slices2 = 1;
static int stacks = 10;
static int x = 30;
int oldX = 0;
int oldY = 0;

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
    glBegin(GL_POLYGON);
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

    glColor3f(1.0,0.23,0.27);
    glCallList(object);
  
    /* const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0; */
    /* double a = t*90.0; */

    /* /// Main body */
    /* glColor3d(0.5,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(0,0,0); */
    /*     glScaled(3,0.4,0.5); */
    /*     glutWireSphere(1,30,30); */
    /* glPopMatrix(); */

    /* glColor3d(0,0,0); */
    /* glPushMatrix(); */
    /*     glTranslated(1.7,0.1,0); */
    /*     glScaled(1.5,0.7,0.8); */
    /*     glRotated(40,0,1,0); */
    /*     glutWireSphere(0.45,30,30); */
    /* glPopMatrix(); */


    /* ///Right */
    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(0,0,1.2); */
    /*     glRotated(-50,0,1,0); */
    /*     glScaled(0.7,0.1,3); */
    /*     glRotated(25,0,1,0); */
    /*     glutWireCube(1); */
    /* glPopMatrix(); */

    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(-0.3,-0.15,1.5); */
    /*     glRotated(90,0,1,0); */
    /*     glScaled(0.1,0.1,0.9); */
    /*     glutWireTorus(0.5,0.5,50,50); */
    /* glPopMatrix(); */

    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(0.2,-0.15,0.9); */
    /*     glRotated(90,0,1,0); */

/* //        /// FAN */
/* //        glPushMatrix(); */
/* //            glTranslated(0,0,0.5); */
/* //            //glRotated(10*a,0,0,1); */
/* //            glScaled(0.1,0.1,0.1); */
/* //            fan(); */
/* //        glPopMatrix(); */

    /*     glScaled(0.1,0.1,0.9); */
    /*     glutWireTorus(0.5,0.5,50,50); */
    /* glPopMatrix(); */

    /* ///Left */
    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(0,0,-1.2); */
    /*     glRotated(50,0,1,0); */
    /*     glScaled(0.7,0.1,3); */
    /*     glRotated(-25,0,1,0); */
    /*     glutWireCube(1); */
    /* glPopMatrix(); */

    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(-0.3,-0.15,-1.5); */
    /*     glRotated(90,0,1,0); */
    /*     glScaled(0.1,0.1,0.9); */
    /*     glutWireTorus(0.5,0.5,50,50); */
    /* glPopMatrix(); */

    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(0.2,-0.15,-0.9); */
    /*     glRotated(90,0,1,0); */
    /*     glScaled(0.1,0.1,0.9); */
    /*     glutWireTorus(0.5,0.5,50,50); */
    /* glPopMatrix(); */


    /* glPushMatrix(); */
    /*     glTranslated(-2.8,0,0); */
    /*     glScaled(0.8,0.5,0.3); */

    /*     ///Right */
    /*     glColor3d(0.8,1,0); */
    /*     glPushMatrix(); */
    /*         glTranslated(0.4,0,1.5); */
    /*         glRotated(-30,0,1,0); */
    /*         glScaled(0.7,0.1,3); */
    /*         glRotated(10,0,1,0); */
    /*         glutWireCube(1); */
    /*     glPopMatrix(); */

    /*     ///left */
    /*     glColor3d(0.8,1,0); */
    /*     glPushMatrix(); */
    /*         glTranslated(0.4,0,-1.5); */
    /*         glRotated(30,0,1,0); */
    /*         glScaled(0.7,0.1,3); */
    /*         glRotated(-10,0,1,0); */
    /*         glutWireCube(1); */
    /*     glPopMatrix(); */
    /* glPopMatrix(); */

    /* /// Pesoner Uporer pakha */
    /* glColor3d(0.8,1,0); */
    /* glPushMatrix(); */
    /*     glTranslated(-2.7,0.5,0); */
    /*     glRotated(45,0,0,1); */
    /*     glScaled(0.8,2,0.1); */
    /*     glRotated(-20,0,0,1); */
    /*     glutWireCube(0.5); */
    /* glPopMatrix(); */

    /* glColor3d(0.8,1,0); */
    /*     glPushMatrix(); */
    /*     glTranslated(-2.95,0.85,0); */
    /*     glRotated(90,0,1,0); */
    /*     glScaled(0.05,0.05,0.6); */
    /*     glutWireTorus(0.5,0.5,50,50); */
    /* glPopMatrix(); */


    /* ///FANS */

    /* glPushMatrix(); */
    /*     glTranslated(3,0,0); */
    /*     glRotated(10*a,1,0,0); */
    /*     //glRotated(0,1,0,0); */
    /*     fan(); */
    /* glPopMatrix(); */
}

void drawStrokeText(char* str,int x,int y,int z) {
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(10,10,10);

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
    glColor3d(1,0,0);

    glLoadIdentity();

    gluLookAt(	0.0, 4.5, 10.0,
                0, 4, 0,
                0, 1.0f, 0.0f);

    glPushMatrix();
        glTranslated(0,0,-80);
        glRotated(slices,1,0,0);
        glRotated(slices2,0,1,0);
        glRotated(30,1,0,0);
        glScaled(stacks,stacks,stacks);
        plane();
    glPopMatrix();

    drawStrokeText("UP: W, DOWN: S, LEFT: A, RIGHT: D, MAIN MENU: M",0,1,-5);

    drawStrokeText("Press G to Start",0,10,-10);
    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y) {
    switch (key)
    {
        case 'r':
            slices = 1;
            slices2 = 1;
            stacks = 1;
            break;
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices > 1) {
                slices--;
                stacks--;
            }
            break;

    }

    glutPostRedisplay();
}

static void mouse(int button, int state, int x, int y) {
  // If button1 pressed, mark this state so we know in motion function.
  switch (button) {
    case GLUT_LEFT_BUTTON:
        {
            slices+=0.4;
            stacks+=0.4;
        }
        break;
    case GLUT_RIGHT_BUTTON:
        {
        }
        slices-=0.4;
        stacks-=0.4;
        break;
  }

}

static void idle(void)
{
    glutPostRedisplay();
}

void motion(int x, int y) {
    slices +=(y-oldY);
    oldY = y;
    slices2 +=(x-oldX);
    oldX = x;

}


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

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
    //glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutMotionFunc(motion);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
