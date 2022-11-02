#include <GL/freeglut.h>
#include <math.h>
void display(void);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(250,250);
    glutInitWindowSize(1000,700);
    glutCreateWindow("Drawing a Circle Using GL_POINTS");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);
    gluOrtho2D(-500,500,-350,350);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float x,y,i,r = 250;

        glBegin(GL_POINTS);
            
            glColor3f(1,0,0);

            for(i = 0; i <= M_PI * 2; i += 0.001)
            {
                x = r * cos(i);
                y = r * sin(i);
                glVertex2i(x,y);
            }
            
        glEnd();

    glFlush();
}