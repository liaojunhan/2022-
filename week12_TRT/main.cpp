#include<GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotated(angle,0,0,1);
        glTranslatef(0.4,-0.07,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();///�洫2����buffer
    angle+=0.1;
}
int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc,argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///�⭿+3D
    glutCreateWindow("week12 TRT");///�ص���
    glutIdleFunc(display);
    glutDisplayFunc(display);///���ѥΨӵe�Ϫ��禡
    glutMainLoop();///�D�n�j��
    return 0;
}
