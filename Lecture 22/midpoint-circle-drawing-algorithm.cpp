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

void initialization();
void setPixel(GLint x,GLint y);
void midPointAlgorithm(ScreenPointStructure center,GLint radius);
void plotOn8Octants(ScreenPointStructure center,ScreenPointClass point);
void display();

int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    initialization();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
void initialization()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,600,0,600);
}
void setPixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}
void midPointAlgorithm(ScreenPointStructure center,GLint radius)
{
    ScreenPointClass currentPoint;
    currentPoint.setX(0);
    currentPoint.setY(radius);
    plotOn8Octants(center,currentPoint);

    GLint p = 1 - radius;
    while(currentPoint.getX() < currentPoint.getY())
    {
        currentPoint.incrementX();
        if (p < 0)
        {
            p += 2*currentPoint.getX() + 1;
        }
        else
        {
            currentPoint.decrementY();
            p += 2*currentPoint.getX() + 1 - 2*currentPoint.getY();
        }
        plotOn8Octants(center,currentPoint);
    }
}
void plotOn8Octants(ScreenPointStructure center,ScreenPointClass point)
{
    setPixel(center.x + point.getX(),
             center.y + point.getY());
    setPixel(center.x - point.getX(),
             center.y + point.getY());
    setPixel(center.x + point.getX(),
             center.y - point.getY());
    setPixel(center.x - point.getX(),
             center.y - point.getY());

    setPixel(center.x + point.getY(),
             center.y + point.getX());
    setPixel(center.x - point.getY(),
             center.y + point.getX());
    setPixel(center.x + point.getY(),
             center.y - point.getX());
    setPixel(center.x - point.getY(),
             center.y - point.getX());
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(5);
        ScreenPointStructure center;
        center.x = 300;
        center.y = 300;
        glColor3f(0,0,1);
        midPointAlgorithm(center,200);
    glFlush();
}
