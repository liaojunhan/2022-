#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t)
{
    printf("鬧鐘%d,我起床了\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    printf("設定下一個鬧鐘\n");
    glutTimerFunc(2000,timer,t+1);
}
void display()
{

}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);///初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///兩倍+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week14 timer");///建視窗
    glutTimerFunc(3000,timer,0);
    glutDisplayFunc(display);///今天用來畫圖的函式
    glutMainLoop();///主要迴圈
}
