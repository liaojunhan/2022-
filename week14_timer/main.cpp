#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t)
{
    printf("�x��%d,�ڰ_�ɤF\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    printf("�]�w�U�@�Ӿx��\n");
    glutTimerFunc(2000,timer,t+1);
}
void display()
{

}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///�⭿+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week14 timer");///�ص���
    glutTimerFunc(3000,timer,0);
    glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡
    glutMainLoop();///�D�n�j��
}
