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
    glutSwapBuffers();///�洫2����buffer
    angle+=0.03;
}
int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc,argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///�⭿+3D
    glutCreateWindow("week12 TRT TRT");///�ص���
    glutIdleFunc(display);
    glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡
    glutMainLoop();///�D�n�j��
    return 0;
}
