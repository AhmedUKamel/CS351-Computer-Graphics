#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>

const int HIGHT = 500, WIDTH = 700;
bool isFirst = true;
int xs,xf,ys,yf;
void * FONT = GLUT_BITMAP_HELVETICA_18;
char initialPoint[10], finalPoint[10];

void str(int x,int y,char * string);
void pixel(GLint x,GLint y);
void bresenham(int x1,int y1,int x2,int y2);
void display(void);
void mouse(int button, int state, int x, int y);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(250,250);
    glutInitWindowSize(WIDTH,HIGHT);
    glutCreateWindow("Bresenham's LDA");
    gluOrtho2D(0,WIDTH, 0,HIGHT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
void str(int x,int y,char * string)
{
    glRasterPos2i(x,y);
    int string_length = (int) strlen(string);

    for (int i = 0; i <= string_length; i++)
        glutBitmapCharacter(FONT, string[i]);
}
void pixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}
void bresenham(int x1,int y1,int x2,int y2)
{
    int dx,dy,p0,xk,yk,Xinc,Yinc;
    dx = x2 - x1;
    dy = y2 - y1;

    Xinc = (dx >= 0)? 1 : -1;
    Yinc = (dy >= 0)? 1 : -1;

    dx = abs(dx);
    dy = abs(dy);

    xk = x1;
    yk = y1;

    if (dy < dx)
    {
        p0 = 2 * dy - dx;
        pixel(x1,y1);

        for (int k = x1; k < x2; k++)
        {
            if (p0 < 0)
            {
                pixel(++xk, yk);
                p0 += 2 * dy;
            }
            else
            {
                pixel(++xk, yk += Yinc);
                p0 += 2 * dy - 2 * dx;
            }
        }
    }
    else
    {
        p0 = 2 * dx - dy;
        pixel(x1,y1);

        for (int k = y1; k < y2; k++)
        {
            if (p0 < 0)
            {
                pixel(xk, ++yk);
                p0 += 2 * dx;
            }
            else
            {
                pixel(xk += Xinc, ++yk);
                p0 += 2 * dx - 2 * dy;
            }
        }
    }
}
void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    str(xs,ys,initialPoint);
    str(xf,yf,finalPoint);

    if (isFirst) {
        int dx = xf - xs, dy = yf - ys;

        if (abs(dy) < abs(dx)) {
            if (xs < xf)
                bresenham(xs,ys,xf,yf);
            else
                bresenham(xf,yf,xs,ys);
        }
        else {
            if (ys < yf)
                bresenham(xs,ys,xf,yf);
            else
                bresenham(xf,yf,xs,ys);
        }
    }

    glFlush();
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (isFirst)
        {
            sprintf(initialPoint,"");
            sprintf(finalPoint,"");
            xs = x;
            ys = HIGHT - y;
            sprintf(initialPoint,"(%d,%d)",xs,ys);
            isFirst = false;
        }
        else
        {
            xf = x;
            yf = HIGHT - y;
            sprintf(finalPoint,"(%d,%d)",xf,yf);
            isFirst = true;
        }
    }
}