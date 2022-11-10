#include <windows.h>
#include <GL/freeglut.h>

GLfloat angle = 0;
void reshape(GLsizei width,GLsizei hight);
void displayCube(void);
void displayPyramid(void);
void timer(int value);
void drawBaseOfPyramid();

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("TRANSFORMATIONS EXAMPLE");
        /* UNCOMMENT ONE LINE BELOW TO DRAW */
        //glutDisplayFunc(displayCube);
        //glutDisplayFunc(displayPyramid);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glClearColor(0,0,0,1);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

void reshape(GLsizei width,GLsizei hight)
{
    if (!hight)
        hight = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)hight;
    glViewport(0,0,width,hight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspect,.1,100);
}

void displayCube(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-5);
    glRotatef(angle,1,1,1);
        glBegin(GL_QUADS);
            // UPPER FACE
            glColor3f(0,1,0);
            glVertex3f( 1, 1,-1);
            glVertex3f(-1, 1,-1);
            glVertex3f(-1, 1, 1);
            glVertex3f( 1, 1, 1);
            // LOWER FACE
            glColor3f(1,1,0);
            glVertex3f( 1,-1, 1);
            glVertex3f(-1,-1, 1);
            glVertex3f(-1,-1,-1);
            glVertex3f( 1,-1,-1);
            // FRONT FACE
            glColor3f(1,0,0);
            glVertex3f( 1, 1, 1);
            glVertex3f(-1, 1, 1);
            glVertex3f(-1,-1, 1);
            glVertex3f( 1,-1, 1);
            // BACK FACE
            glColor3f(1,.5,0);
            glVertex3f( 1,-1,-1);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1, 1,-1);
            glVertex3f( 1, 1,-1);
            // LEFT FACE
            glColor3f(0,0,1);
            glVertex3f(-1, 1, 1);
            glVertex3f(-1, 1,-1);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,-1, 1);
            // RIGHT FACE
            glColor3f(1,0,1);
            glVertex3f( 1, 1,-1);
            glVertex3f( 1, 1, 1);
            glVertex3f( 1,-1, 1);
            glVertex3f( 1,-1,-1);
        glEnd();
    glutSwapBuffers();
}

void timer(int value)
{
    angle += .5;
    glutPostRedisplay();
    glutTimerFunc(15,timer,0);
}

void displayPyramid(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-5);
    glRotatef(angle,1,1,1);
        glBegin(GL_TRIANGLES);
            // FRONT FACE
            glColor3f(1,1,1);
            glVertex3f( 0, 1, 0);
            glColor3f(1,0,0);
            glVertex3f(-1,-1, 1);
            glColor3f(1,1,0);
            glVertex3f( 1,-1, 1);
            // RIGHT FACE
            glColor3f(1,1,1);
            glVertex3f( 0, 1, 0);
            glColor3f(0,0,1);
            glVertex3f( 1,-1,-1);
            glColor3f(1,1,0);
            glVertex3f( 1,-1, 1);
            // LEFT FACE
            glColor3f(1,1,1);
            glVertex3f( 0, 1, 0);
            glColor3f(0,1,0);
            glVertex3f(-1,-1,-1);
            glColor3f(1,0,0);
            glVertex3f(-1,-1, 1);
            // BACK FACE
            glColor3f(1,1,1);
            glVertex3f( 0, 1, 0);
            glColor3f(0,1,0);
            glVertex3f(-1,-1,-1);
            glColor3f(0,0,1);
            glVertex3f( 1,-1,-1);
        glEnd();
        drawBaseOfPyramid();
    glutSwapBuffers();
}

void drawBaseOfPyramid()
{
    glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex3f(-1,-1, 1);
        glColor3f(1,1,0);
        glVertex3f( 1,-1, 1);
        glColor3f(0,0,1);
        glVertex3f( 1,-1,-1);
        glColor3f(0,1,0);
        glVertex3f(-1,-1,-1);
    glEnd();
}
