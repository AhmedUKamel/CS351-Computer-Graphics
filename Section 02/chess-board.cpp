#include <GL/freeglut.h>
const int SQUARE_SIZE = 100;
void display(void);
void drawSquare(int number);
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(SQUARE_SIZE*8,SQUARE_SIZE*8);
    glutCreateWindow("Chess Board");
    gluOrtho2D(0,SQUARE_SIZE*8,0,SQUARE_SIZE*8);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);

        glBegin(GL_QUADS);

            for (int i = 1; i <= 64; i++)
            {
                drawSquare(i);
            }

        glEnd();

    glFlush();
}
void drawSquare(int number)
{
    int row =  number / 8 + 1,
        col = (number % 8 != 0) ? number % 8 : 8;
    if ((row % 2 == 0 && col % 2 == 0) ||
        (row % 2 != 0 && col % 2 != 0))
    {
        glVertex3f(SQUARE_SIZE*(col-1) ,SQUARE_SIZE*(row-1)   ,0);
        glVertex3f(SQUARE_SIZE*(col-1) ,SQUARE_SIZE*row       ,0);
        glVertex3f(SQUARE_SIZE*col     ,SQUARE_SIZE*row       ,0);
        glVertex3f(SQUARE_SIZE*col     ,SQUARE_SIZE*(row-1)   ,0);
    }
}
