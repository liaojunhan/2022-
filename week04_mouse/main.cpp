#include <GL/glut.h>
#include <stdio.h>///printf()
int mouseX=0,mouseY=0,N=0;
int mx[100],my[100];///�ΨӰO���A�����n�e�X�Ӫ��C
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<N;i++){
            glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
        }
       glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)///�ۭq���禡
{
        mouseX=x;mouseY=y;
        if(state==GLUT_DOWN){
            printf("    glVertex2f(%d-150)/150.0,-(%d-150)/150.0;\n",x,y);
            N++;
            mx[N-1]=x; my[N-1]=y;
        }
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///�⭿+3D
    glutCreateWindow("week04 mouse");///�ص���

    glutDisplayFunc( display );///���ѥΨӵe�Ϫ��禡
    glutMouseFunc(mouse);///Mouse�ƹ�

    glutMainLoop();///�D�n���j��
    return 0;
}
