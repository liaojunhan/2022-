#include <GL/glut.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glutSolidTeapot(2);///大茶壼
glutSwapBuffers();
}
void motion(int x, int y)
{
glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
glLoadIdentity();
gluLookAt( (x-150)/15.0, (y-150)/15.0, 3, ///eye
0, 0, 0, ///center
0, 1, 0);///up
glutPostRedisplay();
}
void reshape(int w, int h)
{ const float ar = (float) w / (float) h;
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);///投影,把3D投射到2D畫面
glLoadIdentity();
gluPerspective(60, ar, 0.1, 100);

 glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
glLoadIdentity() ;
gluLookAt( 0, 0, 3, 0, 0, 0, 0, 1, 0);
}
int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("week16 camera lookat");

 glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutMotionFunc(motion);

 glutMainLoop();
}
