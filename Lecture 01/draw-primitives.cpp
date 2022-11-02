#include <GL/freeglut.h>
void display(void);
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(250,250);
    glutInitWindowSize(1000,700);
    glutCreateWindow("Draw Primitives");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
void display(void)
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

            glColor3f(0,1,0);
            glVertex3f(-0.5,-0.5,0);
            glColor3f(0,0,1);
            glVertex3f(0.5,-0.5,0);
            glColor3f(1,0,0);
            glVertex3f(0,0.7,0);

        glEnd();

    glFlush();
}
