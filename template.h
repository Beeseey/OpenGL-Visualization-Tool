		//SamTemplate.h
////////////////////////////////////////////// MACROS
#define M glPushMatrix();				
#define m glPopMatrix();
#define T glTranslatef(
#define	R glRotatef(
#define S glScalef(
#define L  glEnable(GL_LIGHTING);
#define l  glDisable(GL_LIGHTING);
#define C	glColor3f(			//set a color:  C  r,g,b);  //added

#define L0 glEnable(GL_LIGHT0);	//red	// E/Disable four lights 0..3
#define l0 glDisable(GL_LIGHT0);
#define L1 glEnable(GL_LIGHT1);	//red
#define l1 glDisable(GL_LIGHT1);
#define L2 glEnable(GL_LIGHT2); //yellow
#define l2 glDisable(GL_LIGHT2);
#define L3 glEnable(GL_LIGHT3);	//move
#define l3 glDisable(GL_LIGHT3);
#define L4 glEnable(GL_LIGHT4);	//grey	// E/Disable four lights 0..3
#define l4 glDisable(GL_LIGHT4);
#define L5 glEnable(GL_LIGHT5); //move light 
#define l5 glDisable(GL_LIGHT5);
#define L6 glEnable(GL_LIGHT6); //red light
#define l6 glDisable(GL_LIGHT6);
#define L7 glEnable(GL_LIGHT7); // red
#define l7 glDisable(GL_LIGHT7);
//#define L8 glEnable(GL_LIGHT8); // no can be set to a color
//#define l8 glDisable(GL_LIGHT8);

#define Scub glutSolidCube(			//four primitives
#define Ssph glutSolidSphere(
#define Scon glutSolidCone(
#define Stor glutSolidTorus(
#define Wcub glutWireCube(
#define Wsph glutWireSphere(
#define Wcon glutWireCone(
#define Wtor glutWireTorus(
	
	GLfloat mat_ambient[] = { 1.,1.,1., .0 };  //white
	GLfloat mat_specular[] = { 1.,1.,0., .0 }; //yellow

	GLfloat mat_diffuse0[] = { 1.,1.,1., 1. }; //white
	GLfloat mat_diffuse1[] = { 1.,.0, 0., 0. }; //red
	GLfloat mat_diffuse2[] = { .5, 1., 0., 0. }; //brown
	GLfloat mat_diffuse3[] = { 0.,0., 1., .0 }; //blue
	GLfloat mat_diffuse4[] = { 0.,1., 0., .0 }; //sky
	GLfloat mat_diffuse5[] = { 1.,0., 1., .0 }; //violet
	GLfloat mat_diffuse6[] = { 1.,.5, 0., .0 }; //orange
	GLfloat mat_diffuse7[] = { 1.,1., 0., .0 }; //yellow
												//GLfloat mat_diffuse8[]={ 1.,1.,5., .0 }; //yellow
	GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)
										//
	float h = 1000., w = 100., d = 4000.; //height,width,depth	//added
	GLfloat light_position[] = { w, h, d, .0 };					//added
																//
	GLfloat light0_position[] = { 0.,   1000.,  1000., .0 };
	GLfloat light1_position[] = { 0.,   2500.,  2500.,  1. };
	GLfloat light2_position[] = { 70., 3000.,  30000., .0 };
	GLfloat light3_position[] = { 200., 2000.,  1560., .0 };
	GLfloat light4_position[] = { -200., 2000.,  1150., .0 };
	GLfloat light5_position[] = { 100., 2000.,  -1260., .0 };
	GLfloat light6_position[] = { -1000., 2000.,  1260., .0 };
	GLfloat light7_position[] = { 100., 2000.,   650., .0 };
	//GLfloat light8_position[]= { 0.,  150.,   450., .0 }; 

	void initColoring(void)
	{	//glClearColor(1., 1., 1., 1.);
		glShadeModel(GL_SMOOTH);	//default: SMOOTH   not  FLAT
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
		/**/glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_ambient);
		glLightfv(GL_LIGHT0, GL_SPECULAR, mat_ambient);

		glLightfv(GL_LIGHT0, GL_POSITION, light0_position); //three positions for light sources
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
		glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
		glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
		glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
		glLightfv(GL_LIGHT5, GL_POSITION, light5_position);
		glLightfv(GL_LIGHT6, GL_POSITION, light6_position);
		glLightfv(GL_LIGHT7, GL_POSITION, light7_position);
		//glLightfv(GL_LIGHT8, GL_POSITION, light8_position);

		glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse0);	//eight different colors for material lighting	
		glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_diffuse1);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, mat_diffuse2);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, mat_diffuse3);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, mat_diffuse4);
		glLightfv(GL_LIGHT5, GL_DIFFUSE, mat_diffuse5);
		glLightfv(GL_LIGHT6, GL_DIFFUSE, mat_diffuse6);
		glLightfv(GL_LIGHT7, GL_DIFFUSE, mat_diffuse7);
		//glLightfv(GL_LIGHT8, GL_DIFFUSE, mat_diffuse8); 

		glEnable(GL_LIGHTING); glEnable(GL_LIGHT1);		//enable some lighting
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	/*
	void pointing(float xx, float yy)
	{
		cout << "\n\nmouse position xx,yy (in pixels):\n mouseXY : " << xx << "," << yy << endl;
		int Wid = glutGet(GLUT_WINDOW_WIDTH); int Hei = glutGet(GLUT_WINDOW_HEIGHT);  cout << "windowWH : " << Wid << ',' << Hei << endl;
		//glutGet(GLUT_WINDOW_X); glutGet(GLUT_WINDOW_Y); //https://www.opengl.org/resources/libraries/glut/spec3/node70.html
		M T xx, yy, 0.); Wcub 5.); m
		XXX = (xx / Wid)*500. - 250.; YYY = 250. + (-yy / Hei) * 500;
		cout << " mouse position: " << (xx / Wid)*500. - 250. << '_' << 250. + (-yy / Hei)*500. << endl;
	}
	*///////////////////////////////////////////////////////////////

		static GLuint texName[8];

	/*	void readBMPfile(int txk)
	{	FILE *fil = NULL;    unsigned char info[54];
	if(txk==0) fopen_s(&fil, "bg.bmp", "rb"); else
	if(txk==1) fopen_s(&fil, "bg1.bmp", "rb"); else
	if(txk==2) fopen_s(&fil, "bg2.bmp", "rb");
	if (!fil) { cout << fil <<" txk= "<<txk<< " cannot open this file: fil\n"; getchar(); exit(0); }
	else fread(info, sizeof(unsigned char), 54, fil); // Read info: 54-byte_header;  info[18] and info[22]  //Problem ?

	int width =  *(int*)&info[18];		// extract image_width  from header
	int height = *(int*)&info[22];		// extract image_height from header
	int size = 3 * width * height;

	unsigned char *data = new unsigned char[3 * width*height];

	fread(data, sizeof(unsigned char), size, fil); // Read the rest of the data (image data)
	fclose(fil);
	/////////////////////////	S  W  A  P       R,B colors
	for (int i=0; i<size; i+=3) { unsigned char tmp; tmp = data[i]; data[i] = data[i + 2]; data[i + 2] = tmp; }
	/////////////////////////
	glGenTextures(2, &texName[txk]);									// genTexture(2D,texName[txk])
	glBindTexture(GL_TEXTURE_2D, texName[txk]);							// bind(texture,texName)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}

	void drawTexture(int txk) {
	float h = 1000.; short int  w = 1000., d = 300.;
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName[txk]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	//D..,BLEND,MODULATE,REPLACE);//
	glBegin(GL_QUADS);					//x,y,z
	glTexCoord2f(0., 0.);	glVertex3f(-w, -h, d);
	glTexCoord2f(0., 1.);	glVertex3f(-w, h, d);
	glTexCoord2f(1., 1.);	glVertex3f(w, h, d);
	glTexCoord2f(1., 0.);	glVertex3f(w, -h, d);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	}
	*/
