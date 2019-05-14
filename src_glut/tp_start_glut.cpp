#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <stdlib.h>
    #include <iostream>
    #include <unistd.h>
#else
    #include <GL/glut.h>
#endif

using namespace std;

int c1_angle_x = 0;
int c1_angle_y = 0;
int c1_angle_z = 0;


void def_carre(void){
  
  glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
  glEnd();
  
}

void def_boite(int a){
  glLoadIdentity();
  glPushMatrix();
    glScalef(a*1.0,a*1.0,a*1.0); //  /!\ attention

    //glPushMatrix();
     // glRotatef(45, 1, 0, 0);
     // glRotatef(45, 0, 1, 0);
     // glRotatef(45, 0, 0, 1); 
      
      
      
      glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(0, 0, 0.5);
        def_carre(); // face 5   
      glPopMatrix();

      glPushMatrix();    
        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(0, 0, -0.5);
        def_carre(); // face 4
      glPopMatrix();

      glPushMatrix();
        glColor3f(0.0, 0.0, 1.0);
        glTranslatef(0.5, 0, 0);
        glRotatef(90, 0, 1, 0);
        def_carre(); // face 3
      glPopMatrix(); 

      glPushMatrix();
        glColor3f(0.0, 1.0, 1.0);
        glTranslatef(0, 0.5, 0);
        glRotatef(90, 1, 0, 0);
        def_carre(); // face 1
      glPopMatrix();

      glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-0.5, 0, 0);
        glRotatef(90, 0, 1, 0);
        def_carre(); // face 2
      glPopMatrix();

    //glPopMatrix();
    
  glPopMatrix();
}

void def_axes(void){
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0, 0.0);
  glEnd();
  glFlush();

  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
  glEnd();
  glFlush();

  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
  glEnd();
  glFlush();
}

/* Render here */
void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  
  //glColor3f(1.0, 1.0, 1.0);
  //def_carre();
  def_boite(1);
  def_axes();

  glFlush();
  /* Swap front and back buffers */
  glutSwapBuffers();
}

void redim(int w, int h){
  glViewport(0, 0, w, h);
}

void keyboard(unsigned char key, int x, int y)
{
  cout << key;
  switch (key)
  {
  case 'q':
  case 'Q':
    exit(0);
    break;

    // For cube 1 rotation:

  case 'a': // rotate X
    c1_angle_x += 5;
    break;
  case 's':
    c1_angle_x -= 5;
    break;


  case 'd': // rotate Y
    c1_angle_y += 5;
    break;
  case 'f':
    c1_angle_y -= 5;


  case 'g': // rotate Z
    c1_angle_z += 5;
    break;
  case 'h':
    c1_angle_z -= 5;
  }
}

int main(int argc, char **argv) {

  /* Create a windowed mode window and its OpenGL context */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 800);
  glutCreateWindow("OMG! it's a Fucking BOX!!");

  /* Callback for display */
  glutReshapeFunc(redim);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  /* Main loop */
  glutMainLoop();
  return 0;
}