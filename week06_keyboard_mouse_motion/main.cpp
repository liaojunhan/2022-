#include <stdio.h>
#include <GL/glut.h>
float x=0,y=0,z=0,scale=1.0,angle=0.0,oldx,oldy;
int now=1;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotatef(angle,0,0,1);
        glScalef(scale,scale,scale);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mousex,int mousey)
{
    ///printf("現在按下:%c 座標在:%d %d\n",key,mousex,mousey);
    if(key=='w'||key=='W') now=1;
    if(key=='e'||key=='E') now=2;
    if(key=='r'||key=='R') now=3;
}
void mouse(int button,int state,int mousex,int mousey)
{
     oldx=mousex;oldy=mousey;
}
void motion(int mousex,int mousey)
{
    if(now==1)
    {
        x+=(mousex-oldx);
        y+=(mousey-oldy);
    }
    else if(now==3)
    {
        if(mousex>oldx) scale*=1.01;
        if(mousex<oldx) scale*=0.99;
    }
    oldx=mousex;oldy=mousey;
    display();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week06 keyboard_mouse_motion");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
