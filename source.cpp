/*By Layode Oyebisi*/
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h> 
#pragma comment(lib, "winmm.lib") 
#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "t2.h"
#define  W 800		//window Sz=800x600 = WxH (width,and hight of the window)
#define  H 800		//window Sz=800x600 = WxH
int p=1, db=1, b=1, e=1, qd = 0;  //switch drawing: planes, data bars, box,envelop 
int n = 5, g[17][17], max = 20, axe = 2, G = 30; //was G=30
float sz = 60.;		//basic cube size
float x2 =-n, z2=-n, y2 = 0., scl=1.;

//******************************************** start MATH
typedef struct vect { GLfloat x, y, z; } vect;

vect vec(float a, float b, float c) { vect V; V.x = a; V.y = b; V.z = c; return V; }
vect li = { 1.,1.,1. };  //lightVector

vect normalize(vect v)
{	GLfloat le;    //le=length
	le = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	v.x /= le; v.y /= le; v.z /= le;
	return v;
}
vect normal(vect v1, vect v2)	//crossProd(v1,v2)	  			
{	vect v;
	v1 = normalize(v1);  v2 = normalize(v2);
	v.x = (v1.y * v2.z - v1.z * v2.y);
	v.y = (v1.z * v2.x - v1.x * v2.z);
	v.z = (v1.x * v2.y - v1.y * v2.x);
	v = normalize(v);
	return v;
}
float dotProd(vect v1, vect v2)
{	v1 = normalize(v1); v2 = normalize(v2);
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}
/*******************************************  end MATH */

float calculateD(int i, int j) //D = direction with respect to the sun
{	vect v1, v2, n, le = { 1.,1.,1. };
	v1.x = 1.0;
	v1.y = 0.0;
	v1.z = g[i + 1][j] - g[i][j];   //g  was geom
	v2.x = 0.0;
	v2.y = 1.0;
	v2.z = g[i][j + 1] - g[i][j];
	n = normal(v1, v2);
	return dotProd(n, le);
}

////////////////////////////////////////////////////////	NEWLY ADDED TERRAIN
float color(int i, int j)		//terrain coloring
{					//glColor3f(.5,.3,.1);
	vect nor = normal(vec(0., g[i][j] - g[i][j + 1], 1.), vec(1., g[i][j] - g[i + 1][j], 0.));  //g was ter
	float c = dotProd(nor, li);
	return c;
}

/////////////////////////////////////////////////////////   added envelop surface
void envelop() {
	float s = 16.;   l		C 0., 1., 1.);	glShadeModel(GL_SMOOTH); 
	M	for (int i = -n; i <= n; i++) for (int j = -n; j <= n; j++){
		float	c = color(i, j); 
		glColor3f(.5*c, .3*c, .5*c);  //.5, .3, .1
		/**/if (!qd) glBegin(GL_LINE_LOOP);	else  glBegin(GL_QUADS);
	
		glVertex3f((i + n)*sz, s*g[i][j], (j - n)*sz);
		glVertex3f((i + n + 1)*sz, s*g[i + 1][j], (j - n)*sz);
		glVertex3f((i + n + 1)*sz, s*g[i + 1][j + 1], (j - n + 1)*sz);
		glVertex3f((i + n)*sz, s*g[i][j + 1], (j - n + 1)*sz);
		glEnd();
	} m	    L
}
// The end of dot and cross vector product math and the color calculation
//////////////////////////////////////////////////////////
//starting program "Visualization Tools"

void getData(){	for (int i = -n; i <= n; i++)  for (int j = -n; j <= n; j++) g[i][j] = rand() % max;} //create data or get it from files

void drawData() 
{	M	T -x2, -y2, -z2);				//positionning grid
for (int i = z2; i <= n; i++)		//x2=-n
{
	M	for (int j = x2; j <= n; j++) { M   S 1., g[i][j], 1.);   Scub sz - G);  m	 T sz, 0., 0.); } m
		T 0., 0., -sz);
	}
	m
} 

void planeX() {for (int i = -n; i <= n; i++) for (int j = -n; j <= n; j++) {M T 0.,.6*i, .6*j); Scub .01*(sz-2)); m }}
void planeY() {for (int i = -n; i <= n; i++) for (int j = -n; j <= n; j++) {M T .6*i,0., .6*j); Scub .01*(sz-3)); m }} //was .39
void planeZ() {for (int i = -n; i <= n; i++) for (int j = -n; j <= n; j++) {M T .6*j,.6*i, 0.); Scub .01*(sz-2)); m }}

void drawPlanes()
{	M	T -sz*x2, 0., sz*z2);
	M	T  sz*x2, 0., 0.);   S 1., 100., 100.);	l  C 1., 1., 0.);   planeX();	 m		// mobil X_plane  showing one row at a time
	M	T  0., y2, 0.);		 S 100., 1., 100.);	l  C 0., 0., 1.);   planeY();	 m		// mobil Y_plane  moving up_down floor (was Scub 8.);)
	M	T  0., 0., -sz*z2);  S 100., 100., 1.); l  C 0., 1., 0.);   planeZ();	 m	L	// mobil Z_plane  showing one column at a time
m
}

void box(){ M T W / 3., -W / 2., -W / 3.); L5 Scub W);  l5  m }

void display(void)
{	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	 
M	S scl, scl, scl);
if(p)	/**/drawPlanes();
if(db) /**/  L2  L6 //C 1., 0., 1.); 
				drawData();		l6 l2 //data bars
if(b) /**/box();
if(e)/**/envelop(); //envelop surf
m
	glutSwapBuffers(); 
}
void spinDisplay() { glutPostRedisplay(); }

void keyboard(unsigned char key, int xx, int yy)
{	float stp = 1.;
	switch (key)
	{
case '?':	getData(); break;
case 'p':	p = (++p) % 2; break;	//draw plane  toggling
case 'd':	db = (++db) % 2; break; //draw data bars	toggling
case 'b':	b = (++b) % 2; break;	//draw box	toggling
case 'e':	e = (++e) % 2; break;	//draw envelop surf toggling
case 'l':	qd = (qd++) % 2; break; //toggles lineLoop/Quad_surface 

case 's':	scl -=.1; break;   case 'S':	scl += .1; break;
case 'x':	R 1., 1., 0., 0.); break;	case 'X':	R -1., 1., 0., 0.); break;		//Rotate Scene in 3D space
case 'y':	R 1., 0., 1., 0.); break;	case 'Y':	R -1., 0., 1., 0.); break;
case 'z':	R 1., 0., 0., 1.); break;	case 'Z':	R -1., 0., 0., 1.); break;
case '0':	x2 = z2 =-n;  y2 = 0;  axe = 2.; break;	//reset original positionning //, col = row = -n
case '+':	if(axe==2&&y2<W/2.) y2 += stp; else if(axe==3 && z2 < n)z2 += stp; else x2 += stp; break;	//move plane along positive Y,Y,X-axis
case '-':	if(axe==2&&y2>-W/2.)y2 -= stp; else if(axe==3 && z2 >-n)z2 -= stp; else x2 -= stp; break;	//move plane along negative Y,Y,X-axis
case '1':	axe = 1; break; //activate	x-axis the red-plane  (to be moved by +- keys)
case '2':	axe = 2; break; //			y-axis the green-plane
case '3':	axe = 3; break; //activate	z-axis the blue-plane
	}
	glutPostRedisplay();
}

void special(GLint key, GLint xx, GLint yy) //Arrow keys: Moves Screen in 3D space
{	switch(key)
	{
	case GLUT_KEY_RIGHT		: T  10., 0.,  0.);	 break; // move_right graph		X-axis
	case GLUT_KEY_LEFT		: T -10., 0.,  0.);	 break; // move_left  graph
	case GLUT_KEY_UP		: T 0.,  10.,  0.);	 break; // move_up graph		Y-axis
	case GLUT_KEY_DOWN		: T 0., -10.,  0.);	 break; // move_down graph
	case GLUT_KEY_PAGE_DOWN	: T 0.,  0.,  10.);	 break; // move_far graph		Z-axis
	case GLUT_KEY_PAGE_UP	: T 0.,  0., -10.);	 break; // move_close graph
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int xx, int yy)
{	switch (button)			//pointing(xx, yy);
	{
	case GLUT_LEFT_BUTTON:  if(state == GLUT_DOWN) { glutIdleFunc(spinDisplay); } break; 
	case GLUT_RIGHT_BUTTON: if(state == GLUT_UP)   { glutIdleFunc(NULL);	    } break; 
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	//gluPerspective(20., 1.,.1, 9*W); 
	/**/ glOrtho(-2.*W,2.*W,  -2.*H,2.*H,  -2.*W,2.*W);
	glMatrixMode(GL_MODELVIEW);		glLoadIdentity();	
	//T 0., 0., -5*W); //was -5*W  with perspective
}

void init() { glClearColor(1., 1., 1., 0.); initColoring(); srand(time(0));  getData(); glEnable(GL_DEPTH_TEST); glLineWidth(2.); glShadeModel(GL_FLAT);} //9.

void main(int argc, char **argv)
{ glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
  glutInitWindowSize (W, H); glutInitWindowPosition(0,0);
  glutCreateWindow("Dr. Tannouri's easiest volume visualization");
  init(); 
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);  
  glutSpecialFunc(special);
  glutReshapeFunc(reshape);
  glutMainLoop(); 
}
//////////////////////////////  E N D  ///////////////////////////////////



/*
float XXX = 0., YYY = 0.; //pointing: mouse position in window coordinates

void pointing(float xx, float yy)
{	int Wid = glutGet(GLUT_WINDOW_WIDTH); int Hei = glutGet(GLUT_WINDOW_HEIGHT);  cout << "\nwindowWH : " << Wid << ',' << Hei << endl;
	//cout << "mouse pixels: xx, yy :  " << xx << ",\t\t" << yy << endl;
	//glutGet(GLUT_WINDOW_X); glutGet(GLUT_WINDOW_Y); //https://www.opengl.org/resources/libraries/glut/spec3/node70.html
	XXX = (xx		/ Wid)*W;	//-0  because the window origin is the same as the coords origin (left, top and botum corner )
	YYY = ((Hei-yy) / Hei)*H;	//cout << "mouse coords: XXX,YYY : " << XXX << ",\t" << YYY << endl;
}

void axes()
{	l	C 0., 0., 0.);
 M	//T -sz/2., -.1*sz, -sz/2. );  //positionning exes origin     was:   T -.03*W , -4., -.03*W  );
	M	S W,1., 1.);  Scub 2.);	 m		// X_axis
	M	S 1.,W, 1.);  Scub 2.);  m		// Y_axis
	M	S 1.,1.,W);   Scub 2.);	 m		// Z_axis
m
	L
}

void init(){// readBMPfile(1);	//terrain without ocean
// readBMPfile(0);  //beautiful terrain with ocean
//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glEnable(GL_BLEND); //for transparency
}
*/


/*void surf() {
	float s = 16.;   l		C 0., 1., 1.);
	M	for (int i = -n; i <= n; i++) for (int j = -n; j <= n; j++)
			{	// glBegin(GL_LINE_LOOP);
				// glBegin(GL_QUADS);
				glVertex3f((i + n)*sz,		s*g[i][j],			(j - n)*sz);
				glVertex3f((i + n + 1)*sz,	s*g[i + 1][j],		(j - n)*sz);
				glVertex3f((i + n + 1)*sz,	s*g[i + 1][j + 1],	(j - n + 1)*sz);
				glVertex3f((i + n)*sz,		s*g[i][j + 1],		(j - n + 1)*sz);
				glEnd();
			} m	    L
}*/
