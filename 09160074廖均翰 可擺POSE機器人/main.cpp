#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
float angle[20],oldX=0;
int angleID=0;
FILE*fout=NULL,*fin=NULL;
GLMmodel*pmodel=NULL;
GLMmodel*qmodel=NULL;
GLMmodel*rmodel=NULL;
GLMmodel*smodel=NULL;
GLMmodel*tmodel=NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
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
void myRead()
{
    if(fout!=NULL)
    {
        fclose(fout);
        fout=NULL;
    }
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
        fscanf(fin,"%f",&angle[i]);
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    printf("Hello World:%c\n",key);
    if(key=='r') myRead();
    if(key=='s') myWrite();
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
    ///myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL)
    {
        pmodel=glmReadOBJ("data/head.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
    glPushMatrix();
        glmDraw(pmodel,GLM_TEXTURE);
        if(qmodel==NULL)
        {
            qmodel=glmReadOBJ("data/hand.obj");
            glmUnitize(qmodel);
            glmFacetNormals(qmodel);
            glmVertexNormals(qmodel,90);
        }
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotated(angle[0],0,0,1);
            glTranslatef(0.5,0,0);
            glmDraw(qmodel,GLM_TEXTURE);
            if(rmodel==NULL)
            {
                rmodel=glmReadOBJ("data/arm.obj");
                glmUnitize(rmodel);
                glmFacetNormals(rmodel);
                glmVertexNormals(rmodel,90);
            }
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotated(angle[1],0,0,1);
                glTranslatef(0,0,0);
                glmDraw(rmodel,GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
    glPopMatrix();
    if(smodel==NULL)
        {
            smodel=glmReadOBJ("data/hand.obj");
            glmUnitize(smodel);
            glmFacetNormals(smodel);
            glmVertexNormals(smodel,90);
        }
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotated(angle[2],0,0,1);
            glTranslatef(-0.5,0,0);
            glmDraw(smodel,GLM_TEXTURE);
            if(tmodel==NULL)
            {
                tmodel=glmReadOBJ("data/arm.obj");
                glmUnitize(tmodel);
                glmFacetNormals(tmodel);
                glmVertexNormals(tmodel,90);
            }
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotated(angle[3],0,0,1);
                glTranslatef(0,0,0);
                glmDraw(tmodel,GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///�洫2����buffer
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///�⭿+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("09160074");///�ص���
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡
    myTexture("data/Hand.jpg");
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();///�D�n�j��
    return 0;
}
