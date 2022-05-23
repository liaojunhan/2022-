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
void mouse(int button,int state,int x,int y)///mouse���U�h
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
    glRectf(0.3,0.5,-0.3,-0.2);///����,�G��
    glPushMatrix();
        glTranslatef(0.3,0.5,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);///�k�W���u
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///��U��y���b���`
            glRotatef(angle[1],0,0,1);///����
            glTranslatef(-0.8,-0.4,0);///��U��y�����त�ߩ񥿤���
            glColor3f(0,1,0);///���
            glRectf(0.8,0.5,1.1,0.3);///�A�e�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.5,0);
        glRotatef(angle[2],0,0,1);
        glTranslatef(+0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.8,0.3);///���W���u
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);///��U��y���b���`
            glRotatef(angle[3],0,0,1);///����
            glTranslatef(+0.8,-0.4,0);///��U��y�����त�ߩ񥿤���
            glColor3f(0,1,0);///���
            glRectf(-0.8,0.5,-1.1,0.3);///�A�e���U��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///�洫2����buffer
}
int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc,argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///�⭿+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week14 TRT angle write");///�ص���
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡
    glutMainLoop();///�D�n�j��
    return 0;
}
