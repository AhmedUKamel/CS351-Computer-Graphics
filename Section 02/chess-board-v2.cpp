#include <GL/freeglut.h>
const int SQUARE_SIZE = 100,BOARD_SIZE = 8;
void display(void);
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(SQUARE_SIZE*BOARD_SIZE,SQUARE_SIZE*BOARD_SIZE);
    glutCreateWindow("Felxible Chess Board");
    gluOrtho2D(0,SQUARE_SIZE*BOARD_SIZE,0,SQUARE_SIZE*BOARD_SIZE);
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

            for(int row = 1; row <= BOARD_SIZE; row++)
            {
                for(int col = 1; col <= BOARD_SIZE; col++)
                {
                    if(row % 2 != col % 2)
                    {
                            glVertex3f(SQUARE_SIZE*(col-1) ,SQUARE_SIZE*(row-1)   ,0);
                            glVertex3f(SQUARE_SIZE*(col-1) ,SQUARE_SIZE*row       ,0);
                            glVertex3f(SQUARE_SIZE*col     ,SQUARE_SIZE*row       ,0);
                            glVertex3f(SQUARE_SIZE*col     ,SQUARE_SIZE*(row-1)   ,0);
                    }
                }
            }

        glEnd();
        
    glFlush();
}