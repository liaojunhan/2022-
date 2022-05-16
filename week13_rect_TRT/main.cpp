#include<GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int state,int x,int y)///mouse按下去
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.5,0.5,-0.5,-0.5);
    glPushMatrix();
        glTranslatef(0.5,0.5,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.5,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.5,0.5,1.0,0.3);
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc,argv);///初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///兩倍+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");///建視窗
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///今天用來畫圖的函式
    glutMainLoop();///主要迴圈
    return 0;
}
