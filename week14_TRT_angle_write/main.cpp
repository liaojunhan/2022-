#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE*fout=NULL;
void myWrite()
{
    if(fout==NULL) fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
        printf("%.2f ",angle[i]);
        fprintf(fout,"%.2f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)///mouse按下去
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);///身體,瘦身
    glPushMatrix();
        glTranslatef(0.3,0.5,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///把下手肘掛在關節
            glRotatef(angle[1],0,0,1);///旋轉
            glTranslatef(-0.8,-0.4,0);///把下手肘的旋轉中心放正中心
            glColor3f(0,1,0);///綠色
            glRectf(0.8,0.5,1.1,0.3);///再畫下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.5,0);
        glRotatef(angle[2],0,0,1);
        glTranslatef(+0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.8,0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///把下手肘掛在關節
            glRotatef(angle[3],0,0,1);///旋轉
            glTranslatef(+0.8,-0.4,0);///把下手肘的旋轉中心放正中心
            glColor3f(0,1,0);///綠色
            glRectf(-0.8,0.5,-1.1,0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc,argv);///初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///兩倍+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week14 TRT angle write");///建視窗
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///今天用來畫圖的函式
    glutMainLoop();///主要迴圈
    return 0;
}
