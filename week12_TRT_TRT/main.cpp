#include<GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);
    glPushMatrix();
        glTranslatef(0.3,0,0);
        glRotated(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);
        glPushMatrix();
            glTranslatef(0.2,0,0);
            glRotated(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
    angle+=0.03;
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc,argv);///初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///兩倍+3D
    glutCreateWindow("week12 TRT TRT");///建視窗
    glutIdleFunc(display);
    glutDisplayFunc(display);///今天用來畫圖的函式
    glutMainLoop();///主要迴圈
    return 0;
}
