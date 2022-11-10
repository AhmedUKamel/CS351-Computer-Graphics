#include <GL/freeglut.h>

struct ScreenPointStructure {GLint x,y;};
class ScreenPointClass
{
private:
    GLint x,y;
public:
    ScreenPointClass(){x = y = 0;}
    GLint getX(){return x;}
    GLint getY(){return y;}
    void setX(GLint xAxis){x = xAxis;}
    void setY(GLint yAxis){y = yAxis;}
    void incrementX(){x ++;}
    void decrementY(){y --;}
};

void display();
void initialize();
void setPixel(GLint x,GLint y);
void MidPointEllipsDrawingAlgorithm(ScreenPointStructure center,GLint rx,GLint ry);
void plot4Points(ScreenPointStructure center,ScreenPointClass point);

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("MidPoint Ellips Drawing Algorithm");
    initialize();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    ScreenPointStructure center;
    center.x = 300;
    center.y = 300;
    glColor3f(1,0,0);
    MidPointEllipsDrawingAlgorithm(center,200,100);
    glFlush();
}
void initialize()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,600,0,600);
}
void setPixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}
void plot4Points(ScreenPointStructure center,ScreenPointClass point)
{
    setPixel(center.x + point.getX(),
             center.y + point.getY());
    setPixel(center.x - point.getX(),
             center.y + point.getY());
    setPixel(center.x + point.getX(),
             center.y - point.getY());
    setPixel(center.x - point.getX(),
             center.y - point.getY());
}
void MidPointEllipsDrawingAlgorithm(ScreenPointStructure center,GLint rx,GLint ry)
{
    ScreenPointClass currentPoint;
    currentPoint.setX(0);
    currentPoint.setY(ry);
    GLint dx,dy,Pk2,Pk1;

    Pk1 = ry*ry - rx*rx*ry - .25*rx*rx;
    do {
        plot4Points(center,currentPoint);
        currentPoint.incrementX();
        dx = 2*ry*ry*currentPoint.getX();
        dy = 2*rx*rx*currentPoint.getY();
        if (Pk1 >= 0)
        {
            currentPoint.decrementY();
            dy = 2*rx*rx*currentPoint.getY();

            Pk1 -= dy;
        }
        Pk1 += dx + ry*ry;
    } while (dx < dy);

    Pk2 =     ry*ry*(currentPoint.getX()+.5)*(currentPoint.getX()+.5)
            + rx*rx*(currentPoint.getY() -1)*(currentPoint.getY() -1)
            - rx*rx*ry*ry;
    do {
        plot4Points(center,currentPoint);
        currentPoint.decrementY();
        dx = 2*ry*ry*currentPoint.getX();
        dy = 2*rx*rx*currentPoint.getY();
        if (Pk2 <= 0)
        {
            currentPoint.incrementX();
            dx = 2*ry*ry*currentPoint.getX();
            Pk2 += dx;
        }
        Pk2 += -dy + rx*rx;
    } while (currentPoint.getY() >= 0);
}
