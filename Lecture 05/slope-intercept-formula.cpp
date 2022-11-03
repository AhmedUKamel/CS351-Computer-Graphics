#include <GL/freeglut.h>
#include <math.h>
void display(void);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(250,250);
    glutInitWindowSize(500,300);
    glutCreateWindow("Slope-Intercept formula");
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

    float x1,x2,y1,y2,m,b,i,y;
    x1 = -400;
    x2 = 100;
    y1 = 120;
    y2 = 200;
    m = (y2 - y1) / (x2 - x1);
    b = y1 - (m * x1);

        glBegin(GL_POINTS);
            glColor3f(1,0,0);

            for(i = x1; i <= x2; i += 0.1)
            {
                y = m * i + b;
                glVertex2i(i,y);
            }

        glEnd();

    glFlush();
}