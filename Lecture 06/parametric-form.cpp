#include <GL/freeglut.h>
#include <math.h>
void display(void);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(250,250);
    glutInitWindowSize(500,300);
    glutCreateWindow("Parametric Form");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-500,500,-350,350);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float x1,x2,y1,y2,x,y,t;
    x1 = -400;
    x2 = -100;
    y1 = 120;
    y2 = 200;

        glBegin(GL_POINTS);
            glColor3f(1,0,0);

            for(t = 0; t <= 1; t += 0.001)
            {
                x = x1 + t * (x2 - x1);
                y = y1 + t * (y2 - y1);
                glVertex2i(x,y);
            }

        glEnd();

    glFlush();
}