#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

static int slices = 16;
static int stacks = 16;


GLfloat dx=5,dy=-60,dz=-160;

GLfloat fx=5,fy=-60,fz=-80;

float angle = 0.0f;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f, z=5.0f;
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
/* GLUT callback Handlers */

//table
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 0.7, 0.3, 1.0 };
GLfloat mat_diffuse[] = { 0.5, 0.1, 0.6, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = {10};

//room
GLfloat no_mat2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient2[] = { 0, 0.3, 0.2, 1.0 };
GLfloat mat_diffuse2[] = { 0, 0.3, 0.2, 1.0 };
GLfloat mat_specular2[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess2[] = {10};

GLfloat no_mat3[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient3[] = { 0.4, 0, 0, 1.0 };
GLfloat mat_diffuse3[] = { 0.4, 0, 0, 1.0 };
GLfloat mat_specular3[] = { 0.5, 0.2, 0, 1.0 };
GLfloat mat_shininess3[] = {10};

//front
GLfloat no_mat4[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient4[] = { 0.9, 0.9, 0.9, 1.0 };
GLfloat mat_diffuse4[] = { 0.9, 0.9, 0.9, 1.0 };
GLfloat mat_specular4[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess4[] = {10};

GLfloat no_mat5[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient5[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat mat_diffuse5[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat mat_specular5[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess5[] = {10};

//flag
GLfloat no_mat6[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient6[] = { 0.8, 0.4, 0.2, 1.0 };
GLfloat mat_diffuse6[] = { 0.8, 0.4, 0.2, 1.0 };
GLfloat mat_specular6[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess6[] = {10};

GLfloat no_mat7[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient7[] = { 0, 0.5, 0.1, 1.0 };
GLfloat mat_diffuse7[] = { 0, 0.5, 0.1, 1.0 };
GLfloat mat_specular7[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess7[] = {10};

GLfloat no_mat8[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient8[] = { 1, 0, 0, 1.0 };
GLfloat mat_diffuse8[] = { 1, 0, 0, 1.0 };
GLfloat mat_specular8[] = { 1, 0, 0, 1.0 };
GLfloat mat_shininess8[] = {10};

//design
GLfloat no_matd0[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd0[] = { 0.95, 0.95, 0.95, 1.0 };
GLfloat mat_diffused0[] = { 0.95, 0.95, 0.95, 1.0 };
GLfloat mat_speculard0[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd0[] = {10};

GLfloat no_matd1[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd1[] = { 0.9, 0.9, 0.9, 1.0 };
GLfloat mat_diffused1[] = { 0.9, 0.9, 0.9, 1.0 };
GLfloat mat_speculard1[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd1[] = {10};

GLfloat no_matd2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd2[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat mat_diffused2[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat mat_speculard2[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd2[] = {10};


GLfloat no_matd3[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd3[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_diffused3[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_speculard3[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd3[] = {10};


GLfloat no_matd4[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd4[] = { 0.6, 0.6, 0.6, 1.0 };
GLfloat mat_diffused4[] = { 0.6, 0.6, 0.6, 1.0 };
GLfloat mat_speculard4[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd4[] = {10};


GLfloat no_matd5[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd5[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat mat_diffused5[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat mat_speculard5[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd5[] = {10};


GLfloat no_matd6[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd6[] = { 0.45, 0.45, 0.45, 1.0 };
GLfloat mat_diffused6[] = { 0.45, 0.45, 0.45, 1.0 };
GLfloat mat_speculard6[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd6[] = {10};

GLfloat no_matd7[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambientd7[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat mat_diffused7[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat mat_speculard7[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininessd7[] = {10};


GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position[] = { 2.0, 25.0, 3.0, 1.0 };













static void changeSize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 350.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void computePos(float deltaMove)
{

    x += deltaMove * lx * 0.1f;
    z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle)
{

    angle += deltaAngle;
    lx = sin(angle);
    lz = -cos(angle);
}


void pressKey(int key, int xx, int yy)
{

    switch (key)
    {
    case GLUT_KEY_LEFT :
        deltaAngle = -0.01f;
        break;
    case GLUT_KEY_RIGHT :
        deltaAngle = 0.01f;
        break;
    case GLUT_KEY_UP :
        deltaMove = 0.5f;
        break;
    case GLUT_KEY_DOWN :
        deltaMove = -0.5f;
        break;
    }
}

void releaseKey(int key, int x, int y)
{

    switch (key)
    {
    case GLUT_KEY_LEFT :
    case GLUT_KEY_RIGHT :
        deltaAngle = 0.0f;
        break;
    case GLUT_KEY_UP :
    case GLUT_KEY_DOWN :
        deltaMove = 0;
        break;
    }
}



/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 350.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void Room()
{
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);
    glBegin(GL_QUADS);
    ///Floor upper

    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, -100.0);

    ///Floor Lower
    glVertex3f(-100.0, -5.0, -100.0);
    glVertex3f(-100.0, -5.0, 100.0);
    glVertex3f(100.0, -5.0, 100.0);
    glVertex3f(100.0, -5.0, -100.0);

    ///front connector
    ///(0.2,0.2,0.2);
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(-100.0, -5.0, 100.0);
    glVertex3f(100.0, -5.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    ///Back connector

    ///(0.2,0.2,0.2);
    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(-100.0, -5.0, -100.0);
    glVertex3f(100.0, -5.0, -100.0);
    glVertex3f(100.0, 0.0, -100.0);

    ///Right side connector

    ///(0.2,0.2,0.2);
    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(-100.0, -5.0, -100.0);
    glVertex3f(-100.0, -5.0, 100.0);
    glVertex3f(-100.0, 0.0, 100.0);

    ///Left side connector

    ///(0.2,0.2,0.2);
    glVertex3f(100.0, 0.0, -100.0);
    glVertex3f(100.0, -5.0, -100.0);
    glVertex3f(100.0, -5.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);

    ///Floor complete

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient3);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse3);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular3);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess3);
    ///Wall start
    ///Back wall First
    ///(0.3,0.4,0.5);
    glVertex3f(-100.0, 70.0, -95.0);
    glVertex3f(-100.0, 0.0, -95.0);
    glVertex3f(100.0, 0.0, -95.0);
    glVertex3f(100.0, 70.0, -95.0);

    ///Back wall Last
    ///(0.3,0.4,0.5);
    glVertex3f(-100.0, 70.0, -100.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(100.0, 0.0, -100.0);
    glVertex3f(100.0, 70.0, -100.0);

    ///Back wall cover
    /// Side wall Last
    ///(0.2,0.2,0.2);
    glVertex3f(-100.0, 70.0, -100.0);
    glVertex3f(-100.0, 70.0, -95.0);
    glVertex3f(100.0, 70.0, -95.0);
    glVertex3f(100.0, 70.0, -100.0);




    /// Side wall Last
    ///(0.3,0.4,0.5);
    glVertex3f(-100.0, 70.0, -100.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(-100.0, 70.0, 100.0);

    /// Side wall Last
    ///(0.3,0.4,0.5);
    glVertex3f(-95.0, 70.0, -100.0);
    glVertex3f(-95.0, 0.0, -100.0);
    glVertex3f(-95.0, 0.0, 100.0);
    glVertex3f(-95.0, 70.0, 100.0);

    ///Back front cover

    ///(0.2,0.2,0.2);
    glVertex3f(-100.0, 70.0, 100.0);
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(-95.0, 0.0, 100.0);
    glVertex3f(-95.0, 70.0, 100.0);

    ///Left side wall top cover


    ///(0.2,0.2,0.2);
    glVertex3f(-95.0, 70.0, -100.0);
    glVertex3f(-100.0, 70.0, -100.0);
    glVertex3f(-100.0, 70.0, 100.0);
    glVertex3f(-95.0, 70.0, 100.0);

    ///Right side wall last

    ///(0.3,0.4,0.5);
    glVertex3f(100.0, 70.0, -100.0);
    glVertex3f(100.0, 0.0, -100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 70.0, 100.0);

    ///Right side wall first
    ///(0.3,0.4,0.5);
    glVertex3f(95.0, 70.0, -100.0);
    glVertex3f(95.0, 0.0, -100.0);
    glVertex3f(95.0, 0.0, 100.0);
    glVertex3f(95.0, 70.0, 100.0);

    ///Right side Front cover



    ///(0.2,0.2,0.2);
    glVertex3f(100.0, 70.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(95.0, 0.0, 100.0);
    glVertex3f(95.0, 70.0, 100.0);

    ///Right side top cover
    ///(0.2,0.2,0.2);
    glVertex3f(95.0, 70.0, -100.0);
    glVertex3f(100.0, 70.0, -100.0);
    glVertex3f(100.0, 70.0, 100.0);
    glVertex3f(95.0, 70.0, 100.0);





    glEnd();




}
void Table()
{
 glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_QUADS);
    ///Floor upper
    ///(0.42,0.42,0.42);
    glVertex3f(-40.0, 30.0, -40.0);
    glVertex3f(-40.0, 30.0, 40.0);
    glVertex3f(40.0, 30.0, 40.0);
    glVertex3f(40.0, 30.0, -40.0);

    ///Floor lower
    ///(0.42,0.42,0.42);
    glVertex3f(-40.0, 27.0, -40.0);
    glVertex3f(-40.0, 27.0, 40.0);
    glVertex3f(40.0, 27.0, 40.0);
    glVertex3f(40.0, 27.0, -40.0);


    ///front cover
    ///(0.2,0.2,0.2);
    glVertex3f(-40.0, 30.0, 40.0);
    glVertex3f(-40.0, 27.0, 40.0);
    glVertex3f(40.0, 27.0, 40.0);
    glVertex3f(40.0, 30.0, 40.0);


    ///Back cover
    ///(0.2,0.2,0.2);
    glVertex3f(-40.0, 30.0, -40.0);
    glVertex3f(-40.0, 27.0, -40.0);
    glVertex3f(40.0, 27.0, -40.0);
    glVertex3f(40.0, 30.0, -40.0);

    ///side left cover
    ///(0.2,0.2,0.2);
    glVertex3f(-40.0, 30.0, -40.0);
    glVertex3f(-40.0, 27.0, -40.0);
    glVertex3f(-40.0, 27.0, 40.0);
    glVertex3f(-40.0, 30.0, 40.0);

    ///side right cover
    ///(0.2,0.2,0.2);
    glVertex3f(40.0, 30.0, -40.0);
    glVertex3f(40.0, 27.0, -40.0);
    glVertex3f(40.0, 27.0, 40.0);
    glVertex3f(40.0, 30.0, 40.0);


    ///Front leg
    ///(0.4,0.5,0.6);
    glVertex3f(-40.0, 27.0, 40.0);
    glVertex3f(-40.0, 0.0, 40.0);
    glVertex3f(-37.0, 0.0, 40.0);
    glVertex3f(-37.0, 27.0, 40.0);

    ///Front leg back

    ///(0.4,0.5,0.6);
    glVertex3f(-40.0, 27.0, 37.0);
    glVertex3f(-40.0, 0.0, 37.0);
    glVertex3f(-37.0, 0.0, 37.0);
    glVertex3f(-37.0, 27.0, 37.0);

    ///Front leg side Right
    ///(0.2,0.2,0.2);
    glVertex3f(-37.0, 27.0, 37.0);
    glVertex3f(-37.0, 0.0, 37.0);
    glVertex3f(-37.0, 0.0, 40.0);
    glVertex3f(-37.0, 27.0, 40.0);

    ///Front leg side left
    ///(0.2,0.2,0.2);
    glVertex3f(-40.0, 27.0, 37.0);
    glVertex3f(-40.0, 0.0, 37.0);
    glVertex3f(-40.0, 0.0, 40.0);
    glVertex3f(-40.0, 27.0, 40.0);


    ///Back leg Back
    ///(0.4,0.5,0.6);
    glVertex3f(-40.0, 27.0, -40.0);
    glVertex3f(-40.0, 0.0, -40.0);
    glVertex3f(-37.0, 0.0, -40.0);
    glVertex3f(-37.0, 27.0, -40.0);

    ///Back leg front

    ///(0.4,0.5,0.6);
    glVertex3f(-40.0, 27.0, -37.0);
    glVertex3f(-40.0, 0.0, -37.0);
    glVertex3f(-37.0, 0.0, -37.0);
    glVertex3f(-37.0, 27.0, -37.0);

    ///Back leg side Right
    ///(0.2,0.2,0.2);
    glVertex3f(-37.0, 27.0, -37.0);
    glVertex3f(-37.0, 0.0, -37.0);
    glVertex3f(-37.0, 0.0, -40.0);
    glVertex3f(-37.0, 27.0, -40.0);

    ///Back leg side left
    ///(0.2,0.2,0.2);
    glVertex3f(-40.0, 27.0, -37.0);
    glVertex3f(-40.0, 0.0, -37.0);
    glVertex3f(-40.0, 0.0, -40.0);
    glVertex3f(-40.0, 27.0, -40.0);

    ///Front leg Right

    ///Front leg
    ///(0.4,0.5,0.6);
    glVertex3f(40.0, 27.0, 40.0);
    glVertex3f(40.0, 0.0, 40.0);
    glVertex3f(37.0, 0.0, 40.0);
    glVertex3f(37.0, 27.0, 40.0);

    ///Front leg back

    ///(0.4,0.5,0.6);
    glVertex3f(40.0, 27.0, 37.0);
    glVertex3f(40.0, 0.0, 37.0);
    glVertex3f(37.0, 0.0, 37.0);
    glVertex3f(37.0, 27.0, 37.0);

    ///Front leg side Right
    ///(0.2,0.2,0.2);
    glVertex3f(37.0, 27.0, 37.0);
    glVertex3f(37.0, 0.0, 37.0);
    glVertex3f(37.0, 0.0, 40.0);
    glVertex3f(37.0, 27.0, 40.0);

    ///Front leg side left
    ///(0.2,0.2,0.2);
    glVertex3f(40.0, 27.0, 37.0);
    glVertex3f(40.0, 0.0, 37.0);
    glVertex3f(40.0, 0.0, 40.0);
    glVertex3f(40.0, 27.0, 40.0);


    ///back Leg Right

    ///Back leg Back
    ///(0.4,0.5,0.6);
    glVertex3f(40.0, 27.0, -40.0);
    glVertex3f(40.0, 0.0, -40.0);
    glVertex3f(37.0, 0.0, -40.0);
    glVertex3f(37.0, 27.0, -40.0);

    ///Back leg front

    ///(0.4,0.5,0.6);
    glVertex3f(40.0, 27.0, -37.0);
    glVertex3f(40.0, 0.0, -37.0);
    glVertex3f(37.0, 0.0, -37.0);
    glVertex3f(37.0, 27.0, -37.0);

    ///Back leg side Right
    ///(0.2,0.2,0.2);
    glVertex3f(37.0, 27.0, -37.0);
    glVertex3f(37.0, 0.0, -37.0);
    glVertex3f(37.0, 0.0, -40.0);
    glVertex3f(37.0, 27.0, -40.0);

    ///Back leg side left
    ///(0.2,0.2,0.2);
    glVertex3f(40.0, 27.0, -37.0);
    glVertex3f(40.0, 0.0, -37.0);
    glVertex3f(40.0, 0.0, -40.0);
    glVertex3f(40.0, 27.0, -40.0);















    glEnd();





}
void Base()
{
           glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient3);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse3);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular3);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess3);

    glBegin(GL_QUADS);

///base upper
    ///(0.45,0.34,0.24);
    glVertex3f(-35.0, 33.0, -35.0);
    glVertex3f(-35.0, 33.0, 35.0);
    glVertex3f(35.0, 33.0, 35.0);
    glVertex3f(35.0, 33.0, -35.0);

    ///base lower
    ///(0.45,0.34,0.24);
    glVertex3f(-35.0, 30.0, -35.0);
    glVertex3f(-35.0, 30.0, 35.0);
    glVertex3f(35.0, 30.0, 35.0);
    glVertex3f(35.0, 30.0, -35.0);


    ///front cover
    ///(0.56,0.24,0.54);
    glVertex3f(-35.0, 33.0, 35.0);
    glVertex3f(-35.0, 30.0, 35.0);
    glVertex3f(35.0, 30.0, 35.0);
    glVertex3f(35.0, 33.0, 35.0);


    ///Back cover
    ///(0.56,0.24,0.54);
    glVertex3f(-35.0, 33.0, -35.0);
    glVertex3f(-35.0, 30.0, -35.0);
    glVertex3f(35.0, 30.0, -35.0);
    glVertex3f(35.0, 33.0, -35.0);

    ///side left cover
    ///(0.56,0.24,0.54);
    glVertex3f(-35.0, 33.0, -35.0);
    glVertex3f(-35.0, 30.0, -35.0);
    glVertex3f(-35.0, 30.0, 35.0);
    glVertex3f(-35.0, 33.0, 35.0);

    ///side right cover
    ///(0.56,0.24,0.54);
    glVertex3f(35.0, 33.0, -35.0);
    glVertex3f(35.0, 30.0, -35.0);
    glVertex3f(35.0, 30.0, 35.0);
    glVertex3f(35.0, 33.0, 35.0);

    glEnd();
}

void Main()
{

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambientd0);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffused0);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_speculard0);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininessd0);
    glBegin(GL_QUADS);

    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(-2.0, 53.0, 0.0);
    glVertex3f(-2.0, 33.0, 0.0);
    glVertex3f(2.0, 33.0, 0.0);
    glVertex3f(2.0, 53.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(-2.0, 53.0, -2.0);
    glVertex3f(-2.0, 33.0, -2.0);
    glVertex3f(2.0, 33.0, -2.0);
    glVertex3f(2.0, 53.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-2.0, 53.0, -2.0);
    glVertex3f(-2.0, 33.0, -2.0);
    glVertex3f(-2.0, 33.0, 0.0);
    glVertex3f(-2.0, 53.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(2.0, 53.0, -2.0);
    glVertex3f(2.0, 33.0, -2.0);
    glVertex3f(2.0, 33.0, 0.0);
    glVertex3f(2.0, 53.0, 0.0);

    ///Bend

    ///Front
    ///(1.0,1.0,1.0);
    glVertex3f(-2.0, 62.0, 3.0);
    glVertex3f(-2.0, 53.0, 0.0);
    glVertex3f(2.0, 53.0, 0.0);
    glVertex3f(2.0, 62.0, 3.0);

    ///Back
///(1.0,1.0,1.0);
    glVertex3f(-2.0, 62.0, 1.0);
    glVertex3f(-2.0, 53.0, -2.0);
    glVertex3f(2.0, 53.0, -2.0);
    glVertex3f(2.0, 62.0, 1.0);
    ///Right cover
    ///(1.0,1.0,1.0);
    glVertex3f(2.0, 62.0, 1.0);
    glVertex3f(2.0, 53.0, -2.0);
    glVertex3f(2.0, 53.0, 0.0);
    glVertex3f(2.0, 62.0, 3.0);


    ///Left cover
    ///(1.0,1.0,1.0);
    glVertex3f(-2.0, 62.0, 1.0);
    glVertex3f(-2.0, 53.0, -2.0);
    glVertex3f(-2.0, 53.0, 0.0);
    glVertex3f(-2.0, 62.0, 3.0);





///Middle Minar Left
    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 53.0, 0.0);
    glVertex3f(-9.0, 33.0, 0.0);
    glVertex3f(-5.0, 33.0, 0.0);
    glVertex3f(-5.0, 53.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 53.0, -2.0);
    glVertex3f(-9.0, 33.0, -2.0);
    glVertex3f(-5.0, 33.0, -2.0);
    glVertex3f(-5.0, 53.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 53.0, -2.0);
    glVertex3f(-9.0, 33.0, -2.0);
    glVertex3f(-9.0, 33.0, 0.0);
    glVertex3f(-9.0, 53.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-5.0, 53.0, -2.0);
    glVertex3f(-5.0, 33.0, -2.0);
    glVertex3f(-5.0, 33.0, 0.0);
    glVertex3f(-5.0, 53.0, 0.0);



    ///Front
    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 62.0, 3.0);
    glVertex3f(-9.0, 53.0, 0.0);
    glVertex3f(-5.0, 53.0, 0.0);
    glVertex3f(-5.0, 62.0, 3.0);

    ///Back
///(1.0,1.0,1.0);
    glVertex3f(-9.0, 62.0, 1.0);
    glVertex3f(-9.0, 53.0, -2.0);
    glVertex3f(-5.0, 53.0, -2.0);
    glVertex3f(-5.0, 62.0, 1.0);
    ///Right cover
    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 62.0, 1.0);
    glVertex3f(-9.0, 53.0, -2.0);
    glVertex3f(-9.0, 53.0, 0.0);
    glVertex3f(-9.0, 62.0, 3.0);


    ///Left cover
    ///(1.0,1.0,1.0);
    glVertex3f(-5.0, 62.0, 1.0);
    glVertex3f(-5.0, 53.0, -2.0);
    glVertex3f(-5.0, 53.0, 0.0);
    glVertex3f(-5.0, 62.0, 3.0);







///Middle Minar Right
    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(9.0, 53.0, 0.0);
    glVertex3f(9.0, 33.0, 0.0);
    glVertex3f(5.0, 33.0, 0.0);
    glVertex3f(5.0, 53.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(9.0, 53.0, -2.0);
    glVertex3f(9.0, 33.0, -2.0);
    glVertex3f(5.0, 33.0, -2.0);
    glVertex3f(5.0, 53.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(9.0, 53.0, -2.0);
    glVertex3f(9.0, 33.0, -2.0);
    glVertex3f(9.0, 33.0, 0.0);
    glVertex3f(9.0, 53.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(5.0, 53.0, -2.0);
    glVertex3f(5.0, 33.0, -2.0);
    glVertex3f(5.0, 33.0, 0.0);
    glVertex3f(5.0, 53.0, 0.0);

///Bend
    ///Front
    ///(1.0,1.0,1.0);
    glVertex3f(9.0, 62.0, 3.0);
    glVertex3f(9.0, 53.0, 0.0);
    glVertex3f(5.0, 53.0, 0.0);
    glVertex3f(5.0, 62.0, 3.0);

    ///Back
    ///(1.0,1.0,1.0);
    glVertex3f(9.0, 62.0, 1.0);
    glVertex3f(9.0, 53.0, -2.0);
    glVertex3f(5.0, 53.0, -2.0);
    glVertex3f(5.0, 62.0, 1.0);
    ///Right cover
    ///(1.0,1.0,1.0);
    glVertex3f(9.0, 62.0, 1.0);
    glVertex3f(9.0, 53.0, -2.0);
    glVertex3f(9.0, 53.0, 0.0);
    glVertex3f(9.0, 62.0, 3.0);


    ///Left cover
    ///(1.0,1.0,1.0);
    glVertex3f(5.0, 62.0, 1.0);
    glVertex3f(5.0, 53.0, -2.0);
    glVertex3f(5.0, 53.0, 0.0);
    glVertex3f(5.0, 62.0, 3.0);



    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 62.0, 1.0);
    glVertex3f(9.0, 62.0, 1.0);
    glVertex3f(9.0, 62.0, 3.0);
    glVertex3f(-9.0, 62.0, 3.0);

    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 60.0, 0.40);
    glVertex3f(9.0, 60.0, .40);
    glVertex3f(9.0, 60.0, 2.30);
    glVertex3f(-9.0, 60.0, 2.30);

    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 62.0, 3.0);
    glVertex3f(9.0, 62.0, 3.0);
    glVertex3f(9.0, 60.0, 2.30);
    glVertex3f(-9.0, 60.0, 2.30);

    ///(1.0,1.0,1.0);
    glVertex3f(-9.0, 62.0, 1.0);
    glVertex3f(9.0, 62.0, 1.0);
    glVertex3f(9.0, 60.0, 0.40);
    glVertex3f(-9.0, 60.0, 0.40);



    glEnd();


}

void Side1()
{


    glBegin(GL_QUADS);

    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(-15.0, 50.0, 0.0);
    glVertex3f(-15.0, 33.0, 0.0);
    glVertex3f(-12.0, 33.0, 0.0);
    glVertex3f(-12.0, 50.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(-15.0, 50.0, -2.0);
    glVertex3f(-15.0, 33.0, -2.0);
    glVertex3f(-12.0, 33.0, -2.0);
    glVertex3f(-12.0, 50.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-15.0, 50.0, -2.0);
    glVertex3f(-15.0, 33.0, -2.0);
    glVertex3f(-15.0, 33.0, 0.0);
    glVertex3f(-15.0, 50.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-12.0, 50.0, -2.0);
    glVertex3f(-12.0, 33.0, -2.0);
    glVertex3f(-12.0, 33.0, 0.0);
    glVertex3f(-12.0, 50.0, 0.0);


    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(-21.0, 50.0, 0.0);
    glVertex3f(-21.0, 33.0, 0.0);
    glVertex3f(-18.0, 33.0, 0.0);
    glVertex3f(-18.0, 50.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(-21.0, 50.0, -2.0);
    glVertex3f(-21.0, 33.0, -2.0);
    glVertex3f(-18.0, 33.0, -2.0);
    glVertex3f(-18.0, 50.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-21.0, 50.0, -2.0);
    glVertex3f(-21.0, 33.0, -2.0);
    glVertex3f(-21.0, 33.0, 0.0);
    glVertex3f(-21.0, 50.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-18.0, 50.0, -2.0);
    glVertex3f(-18.0, 33.0, -2.0);
    glVertex3f(-18.0, 33.0, 0.0);
    glVertex3f(-18.0, 50.0, 0.0);



    ///Top
    ///(1.0,1.0,1.0);
    glVertex3f(-12.0, 50.0, 0.0);
    glVertex3f(-21.0, 50.0, 0.0);
    glVertex3f(-21.0, 47.0, 0.0);
    glVertex3f(-12.0, 47.0, 0.0);
///Back
    ///(1.0,1.0,1.0);
    glVertex3f(-12.0, 50.0, -2.0);
    glVertex3f(-21.0, 50.0, -2.0);
    glVertex3f(-21.0, 47.0, -2.0);
    glVertex3f(-12.0, 47.0, -2.0);
///Top
    ///(1.0,1.0,1.0);
    glVertex3f(-12.0, 50.0, -2.0);
    glVertex3f(-21.0, 50.0, -2.0);
    glVertex3f(-21.0, 50.0, 0.0);
    glVertex3f(-12.0, 50.0, 0.0);









    ///Second side
    ///(1.0,1.0,1.0);
    glVertex3f(15.0, 50.0, 0.0);
    glVertex3f(15.0, 33.0, 0.0);
    glVertex3f(12.0, 33.0, 0.0);
    glVertex3f(12.0, 50.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(15.0, 50.0, -2.0);
    glVertex3f(15.0, 33.0, -2.0);
    glVertex3f(12.0, 33.0, -2.0);
    glVertex3f(12.0, 50.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(15.0, 50.0, -2.0);
    glVertex3f(15.0, 33.0, -2.0);
    glVertex3f(15.0, 33.0, 0.0);
    glVertex3f(15.0, 50.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(12.0, 50.0, -2.0);
    glVertex3f(12.0, 33.0, -2.0);
    glVertex3f(12.0, 33.0, 0.0);
    glVertex3f(12.0, 50.0, 0.0);


    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(21.0, 50.0, 0.0);
    glVertex3f(21.0, 33.0, 0.0);
    glVertex3f(18.0, 33.0, 0.0);
    glVertex3f(18.0, 50.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(21.0, 50.0, -2.0);
    glVertex3f(21.0, 33.0, -2.0);
    glVertex3f(18.0, 33.0, -2.0);
    glVertex3f(18.0, 50.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(21.0, 50.0, -2.0);
    glVertex3f(21.0, 33.0, -2.0);
    glVertex3f(21.0, 33.0, 0.0);
    glVertex3f(21.0, 50.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(18.0, 50.0, -2.0);
    glVertex3f(18.0, 33.0, -2.0);
    glVertex3f(18.0, 33.0, 0.0);
    glVertex3f(18.0, 50.0, 0.0);


    ///Top
    ///(1.0,1.0,1.0);
    glVertex3f(12.0, 50.0, 0.0);
    glVertex3f(21.0, 50.0, 0.0);
    glVertex3f(21.0, 47.0, 0.0);
    glVertex3f(12.0, 47.0, 0.0);
///Back
    ///(1.0,1.0,1.0);
    glVertex3f(12.0, 50.0, -2.0);
    glVertex3f(21.0, 50.0, -2.0);
    glVertex3f(21.0, 47.0, -2.0);
    glVertex3f(12.0, 47.0, -2.0);
///Top
    ///(1.0,1.0,1.0);
    glVertex3f(12.0, 50.0, -2.0);
    glVertex3f(21.0, 50.0, -2.0);
    glVertex3f(21.0, 50.0, 0.0);
    glVertex3f(12.0, 50.0, 0.0);








    glEnd();
}

void Side2()
{

    glBegin(GL_QUADS);

    //glBegin(GL_QUADS);

    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(-28.0, 47.0, 0.0);
    glVertex3f(-28.0, 33.0, 0.0);
    glVertex3f(-25.0, 33.0, 0.0);
    glVertex3f(-25.0, 47.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(-28.0, 47.0, -2.0);
    glVertex3f(-28.0, 33.0, -2.0);
    glVertex3f(-25.0, 33.0, -2.0);
    glVertex3f(-25.0, 47.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-28.0, 47.0, -2.0);
    glVertex3f(-28.0, 33.0, -2.0);
    glVertex3f(-28.0, 33.0, 0.0);
    glVertex3f(-28.0, 47.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-25.0, 47.0, -2.0);
    glVertex3f(-25.0, 33.0, -2.0);
    glVertex3f(-25.0, 33.0, 0.0);
    glVertex3f(-25.0, 47.0, 0.0);


    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(-34.0, 47.0, 0.0);
    glVertex3f(-34.0, 33.0, 0.0);
    glVertex3f(-31.0, 33.0, 0.0);
    glVertex3f(-31.0, 47.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(-34.0, 47.0, -2.0);
    glVertex3f(-34.0, 33.0, -2.0);
    glVertex3f(-31.0, 33.0, -2.0);
    glVertex3f(-31.0, 47.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-34.0, 47.0, -2.0);
    glVertex3f(-34.0, 33.0, -2.0);
    glVertex3f(-34.0, 33.0, 0.0);
    glVertex3f(-34.0, 47.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(-31.0, 47.0, -2.0);
    glVertex3f(-31.0, 33.0, -2.0);
    glVertex3f(-31.0, 33.0, 0.0);
    glVertex3f(-31.0, 47.0, 0.0);

///Top

///Front

    ///(1.0,1.0,1.0);
    glVertex3f(-25.0, 47.0, 0.0);
    glVertex3f(-34.0, 47.0, 0.0);
    glVertex3f(-34.0, 44.0, 0.0);
    glVertex3f(-25.0, 44.0, 0.0);
///Back
    ///(1.0,1.0,1.0);
    glVertex3f(-25.0, 47.0, -2.0);
    glVertex3f(-34.0, 47.0, -2.0);
    glVertex3f(-34.0, 44.0, -2.0);
    glVertex3f(-25.0, 44.0, -2.0);
///Top
    ///(1.0,1.0,1.0);
    glVertex3f(-25.0, 47.0, -2.0);
    glVertex3f(-34.0, 47.0, -2.0);
    glVertex3f(-34.0, 47.0, 0.0);
    glVertex3f(-25.0, 47.0, 0.0);





    ///Second side
    ///(1.0,1.0,1.0);
    glVertex3f(28.0, 47.0, 0.0);
    glVertex3f(28.0, 33.0, 0.0);
    glVertex3f(25.0, 33.0, 0.0);
    glVertex3f(25.0, 47.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(28.0, 47.0, -2.0);
    glVertex3f(28.0, 33.0, -2.0);
    glVertex3f(25.0, 33.0, -2.0);
    glVertex3f(25.0, 47.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(28.0, 47.0, -2.0);
    glVertex3f(28.0, 33.0, -2.0);
    glVertex3f(28.0, 33.0, 0.0);
    glVertex3f(28.0, 47.0, 0.0);

    ///Middle minar(right cover)
    ///(1.0,1.0,1.0);
    glVertex3f(25.0, 47.0, -2.0);
    glVertex3f(25.0, 33.0, -2.0);
    glVertex3f(25.0, 33.0, 0.0);
    glVertex3f(25.0, 47.0, 0.0);


    ///Middle minar first
    ///(1.0,1.0,1.0);
    glVertex3f(34.0, 47.0, 0.0);
    glVertex3f(34.0, 33.0, 0.0);
    glVertex3f(31.0, 33.0, 0.0);
    glVertex3f(31.0, 47.0, 0.0);
    ///Middle minar second
    ///(1.0,1.0,1.0);
    glVertex3f(34.0, 47.0, -2.0);
    glVertex3f(34.0, 33.0, -2.0);
    glVertex3f(31.0, 33.0, -2.0);
    glVertex3f(31.0, 47.0, -2.0);

    ///Middle minar(left cover)
    ///(1.0,1.0,1.0);
    glVertex3f(34.0, 47.0, -2.0);
    glVertex3f(34.0, 33.0, -2.0);
    glVertex3f(34.0, 33.0, 0.0);
    glVertex3f(34.0, 47.0, 0.0);

    ///Middle minar(right cover)
///(1.0,1.0,1.0);
    glVertex3f(31.0, 47.0, -2.0);
    glVertex3f(31.0, 33.0, -2.0);
    glVertex3f(31.0, 33.0, 0.0);
    glVertex3f(31.0, 47.0, 0.0);

///Front
///(1.0,1.0,1.0);
    glVertex3f(25.0, 47.0, 0.0);
    glVertex3f(34.0, 47.0, 0.0);
    glVertex3f(34.0, 44.0, 0.0);
    glVertex3f(25.0, 44.0, 0.0);
///Back
    ///(1.0,1.0,1.0);
    glVertex3f(25.0, 47.0, -2.0);
    glVertex3f(34.0, 47.0, -2.0);
    glVertex3f(34.0, 44.0, -2.0);
    glVertex3f(25.0, 44.0, -2.0);
///Top
    ///(1.0,1.0,1.0);
    glVertex3f(25.0, 47.0, -2.0);
    glVertex3f(34.0, 47.0, -2.0);
    glVertex3f(34.0, 47.0, 0.0);
    glVertex3f(25.0, 47.0, 0.0);





    glEnd();

//   glEnd();






}
void Circle()
{
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient8);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse8);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular8);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess8);
    int stacks=16,slices=16;
    glColor3f(1, 0, 0);
    glTranslatef(0.0,46,-2.2);

    glScalef(9,9,0);
    glutSolidSphere(1,slices,stacks);
}







static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 2500.0;
    const double a = t*40.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///(1,0,0);

    glPushMatrix();
    glTranslated(-10, -50, -250);

    glRotated(a,0,1,0);





    Room();

     Table();
   Base();
    Main();
    Side1();
    Side2();
    Circle();

    // ShahidMnr();

    glPopMatrix();


    glutSwapBuffers();
}




static void idle(void)
{
    glutPostRedisplay();
}





int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Home Work");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);

    glutIdleFunc(idle);

    glClearColor(0,0,0,0);
    glDisable(GL_CULL_FACE);  //back side disable or enable
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHTING);
    glEnable( GL_LIGHT0);

    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);




    glutMainLoop();

    return EXIT_SUCCESS;
}


