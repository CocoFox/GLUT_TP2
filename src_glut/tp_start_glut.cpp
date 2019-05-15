#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <stdlib.h>
    #include <iostream>
    #include <unistd.h>
#else
    #include <GL/glut.h>
#endif

using namespace std;

GLfloat rot_angle = 0.8f; // rotation angle
int refreshmill = 1; // milisecond refresh rate
bool spin = false;
void def_boite(float a);

int init_translate = true;

void timer(int value){
  glutPostRedisplay();
  glutTimerFunc(refreshmill,timer,1);
  usleep(10000);
}

int c1_angle_x = 0;
int c1_angle_y = 0;
int c1_angle_z = 0;

void cube_spin(void){
  //rot_angle += 0.2;
  //if(rot_angle >= 360)
    //rot_angle -= 360;
  if(spin){
    glRotatef((GLfloat)rot_angle*4, 1, 0, 0);
    glRotatef((GLfloat)rot_angle*2 , 0, 1, 0);
    glRotatef((GLfloat)rot_angle  , 0, 0, 1);
  }
  def_boite(1);
  
}

void init_perspective(void){
  
}

void def_carre(void){
  

  glPolygonMode(GL_FRONT, GL_FILL);
  glPolygonMode(GL_BACK, GL_LINE);
  //glCullFace(GL_FRONT);
  
  glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
  glEnd();
  
}

void def_boite(GLfloat a){

  //
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
    
  
}

void def_axes(void){
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0, 0.0);
  glEnd();
  

  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
  glEnd();
  

  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
  glEnd();
  
}

/* Render here */
void display(void) {
  init_perspective();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
    
    

      
      
    if(spin){
      glRotatef(c1_angle_x, 1, 0, 0);
      glRotatef(c1_angle_y, 0, 1, 0);
      glRotatef(c1_angle_z, 0, 0, 1);
    }
    glPushMatrix(); 
    glTranslatef(1,0,0);
    def_boite(1);
    def_axes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,0,0);
    def_boite(1);
    def_axes();
    glPopMatrix();

    
    
  
  //usleep(1);

  

  /* Swap front and back buffers */
  
  glutSwapBuffers();
}
/*
void redim(int w, int h){
 
  glViewport(0, 0, w, h);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45,
    (GLfloat)w/h,
    10,
    1000);
  cout << endl << "aspect: " << (GLfloat) w/h << endl ; 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0,0,0,10,0,0,0,1,0);
 
}
 */
void redim(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -4,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, 1.0, 1.0, 12.0);
    glMatrixMode(GL_MODELVIEW);

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
    c1_angle_x = 5;
    break;
  case 's':
    c1_angle_x = -5;
    break;


  case 'd': // rotate Y
    c1_angle_y = 5;
    break;
  case 'f':
    c1_angle_y = -5;
    break;

  case 'g': // rotate Z
    c1_angle_z = 5;
    break;
  case 'h':
    c1_angle_z = -5;
    break;
  case 'j':
    spin = !spin;
  }
  glutPostRedisplay();
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
  glutIdleFunc(cube_spin); 
  glutTimerFunc(0,timer,0);

  //glEnable(GL_CULL_FACE);

  /* Main loop */
  glutMainLoop();
  return 0;
}