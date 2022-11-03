#include <GL/freeglut.h>
#include <math.h>
void display(void);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(250,250);
    glutInitWindowSize(500,300);
    glutCreateWindow("Digital Differential Analyzer (DDA)");
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

    float x1,x2,y1,y2,x,y,dx,dy,steps,Xinc,Yinc;
    x1 = -400;
    x2 = 100;
    y1 = 120;
    y2 = 200;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = fmax(dx,dy);
    Xinc = dx / steps;
    Yinc = dy / steps;


        glBegin(GL_POINTS);
            glColor3f(1,0,0);

            for(int i = 0; i <= steps; i++)
            {
                glVertex2i(round(x),round(y));
                x += Xinc;
                y += Yinc;
            }

        glEnd();

    glFlush();
}