//g++ 'homeautomation.cpp' -lGL -lGLU -lglut
#include<GL/glut.h>
#include<math.h>

int seq=0,k=0;
float af=0,aF=0;
int l=0,L=0,f=0,F=0,t=0;

void rgb(int r,int g,int b)
{
  glColor3f(r/255.0,g/255.0,b/255.0);	
}

void Printtext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);   
}

void start()
{
     Printtext(0.9,0.5,0.8,"CG MINI PROJECT",465,320);
     Printtext(0.9,0.5,0.8,"_______________",465,310);
     Printtext(0.9,0.5,0.8,"HOME AUTOMATION",465,280);
     Printtext(0.9,0.5,0.8,"4SF13CS052",480,240);
     if(k)
      Printtext(0.6,0.2,0.7,"Press s/S for start!",447,70);
     k=~k;
     glutPostRedisplay();
     glutSwapBuffers();
}

void end()
{
	 glClearColor(0,0,0,1.0);
     Printtext(0.6,0.2,0.7,"THANK YOU!",450,320);
     glutPostRedisplay();
     glutSwapBuffers();
}

void DrawSegment(float cx, float cy, float r, int degree1,int degree2,int shade) 
{ 
	int num_segments=360;
	if(shade==0)
	  glBegin(GL_LINE_LOOP); 
	if(shade==1)
	  glBegin(GL_POLYGON);
	for(int i = degree1; i < degree2; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void DrawSector(float cx, float cy, float r, int degree1, int degree2, int shade) 
{ 
	int num_segments=360;
	if(shade==0)
	  glBegin(GL_LINE_LOOP); 
	if(shade==1)
	  glBegin(GL_POLYGON);
	glVertex2f(cx,cy);  
	for(int i = degree1; i < degree2; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void room()
{
    rgb(165, 34, 47);//floor
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(1100,0);
	rgb(89, 4, 12);
	glVertex2f(900,200);
	glVertex2f(200,200);
	glEnd();
	
	glColor3f(0.0,0.6,0.6);//left wall
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glColor3f(0.0,0.3,0.3);
	glVertex2f(200,200);
	glVertex2f(200,600);
	glColor3f(0.0,0.6,0.6);
	glVertex2f(0,700);
	glEnd();
	
	glColor3f(0.0,0.3,0.3);//front wall
	glBegin(GL_POLYGON);
	glVertex2f(200,200);
	glVertex2f(200,600);
	glVertex2f(900,600);
	glVertex2f(900,200);
	glEnd();
	
	glColor3f(0.0,0.6,0.6);//left wall
	glBegin(GL_POLYGON);
	glVertex2f(1100,0);
	glColor3f(0.0,0.3,0.3);
	glVertex2f(900,200);
	glVertex2f(900,600);
	glColor3f(0.0,0.6,0.6);
	glVertex2f(1100,700);
	glEnd();
	
	glColor3f(0.9,0.9,0.9);//ceiling
	glBegin(GL_POLYGON);
	glVertex2f(0,700);
	glColor3f(0.7,0.7,0.7);
	glVertex2f(200,600);
	glVertex2f(900,600);
	glColor3f(0.9,0.9,0.9);
	glVertex2f(1100,700);
	glEnd();
}

void tvframe()
{
    rgb(48, 45, 43);
	glBegin(GL_POLYGON);
	glVertex2f(400,300);
	glVertex2f(400,450);
	glVertex2f(700,450);
	glVertex2f(700,300);
	glEnd();	
}
void tvoff()
{	
	rgb(25, 25, 25);
	glBegin(GL_POLYGON);
	glVertex2f(410,310);
	glVertex2f(410,440);
	glVertex2f(690,440);
	glVertex2f(690,310);
	glEnd();	
}

void tvshow()
{
   Printtext(0.9,0.5,0.8,"WELCOME",515,370);
}


void tvon()
{	
	rgb(0,255,0);
	glBegin(GL_POLYGON);
	glVertex2f(410,310);
	glVertex2f(410,440);
	glVertex2f(690,440);
	glVertex2f(690,310);
	glEnd();	

	tvshow();
}

void lamp_wire()
{
	glLineWidth(2);//lamp wire
    rgb(132, 125, 119);
	glBegin(GL_LINES);
	glVertex2f(300,680);
    glVertex2f(300,550);
    glEnd();
}    

void lamp()
{    
	glBegin(GL_POLYGON);
	glVertex2f(290,550);
	glVertex2f(290,520);
	glVertex2f(310,520);
	glVertex2f(310,550);
	glEnd();
    	
}

void fanstand()
{
    rgb(132, 125, 119);//base
	glBegin(GL_POLYGON);
	glVertex2f(280,170);
	glVertex2f(320,170);
	rgb(120, 110, 100);
	glVertex2f(315,190);
	glVertex2f(285,190);
	glEnd();
	
	glLineWidth(4);//fan rod
    rgb(132, 125, 119);
	glBegin(GL_LINES);
	glVertex2f(300,180);
    glVertex2f(300,330);
    glEnd();
    
    glLineWidth(4);//outer circle
    DrawSegment(300, 330, 50, 0, 360, 0);
    glLineWidth(2);//center circle
    DrawSegment(300, 330, 30, 0, 360, 0);
    glLineWidth(2);//inner circle
    DrawSegment(300, 330, 8, 0, 360, 1);
    
    for(int i=0;i<360;i+=40)//sector
      DrawSector(300, 330, 50, i, i+20, 0);
}

void wing()
{
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.6, 1);
	glVertex2f(-5,0);
	glColor3f(0.6,0.8,1);
	glVertex2f(-10,35);
	glColor3f(0.8,1,1);
	glVertex2f(10,35);
	glColor3f(0.2, 0.6, 1);
	glVertex2f(5,0);
	glEnd();
	
	glBegin(GL_POLYGON); 			//Top Curve
    glColor3f(0, 0.5, 1);
	for(int i=0;i<180;i++)
	{
	  float v=(3.14/180)*i ;
	  glVertex2d(cos(v)*10, 35+sin(v)*5);
	}
	glEnd();
	
	glColor3f(0.1, 0.7, 0.9);
	DrawSegment(0, 0, 12, 0, 360, 1);
}

void fanwing(int i)
{ 
    glPushMatrix();
    glTranslated(300,330,0);
    glRotatef(i, 0, 0, 1);
	wing();					//Top Wing
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(300,330,0);
	glRotatef(i+120, 0, 0, 1); 
	wing();
	glPopMatrix();
		
	glPushMatrix();
	glTranslated(300,330,0);
	glRotatef(i+240, 0, 0, 1); 
	wing();
	glPopMatrix();
}
void process()
{
	  room();
      tvframe();
      
      if(t==0)
        tvoff();
      else
        tvon();
        
      lamp_wire();
      
      if(l==0)
      {
        glColor3f(0.0,0.6,0.6);
	  }
      else
      {
        rgb(255,255,255);
      }  
      
      lamp();
      
      glPushMatrix();
      glTranslated(500,0,0);
      lamp_wire();
      if(L==0)
      {
        glColor3f(0.0,0.6,0.6);
	  }
      else
      {
        rgb(255,255,255);
	  }
      lamp();
      glPopMatrix();
      
      fanwing(af);
      fanstand();
      
      glPushMatrix();
      glTranslated(500,0,0);
      fanwing(aF);
      fanstand();
      glPopMatrix();
      
      af-=f;
      aF-=F;
}

void display()
{        
	glClear(GL_COLOR_BUFFER_BIT);	
    if(seq==0)
    {
	  start();
    }
    if(seq==1)
    {
	  process();
    }
    
    if(seq==2)
    {
	  end();
    }
    
	glutPostRedisplay();
    glutSwapBuffers();
}

void init()
{
  glClearColor(0.0,0.0,0.0,1.0);
  gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void keys(unsigned char key,int x,int y)
{
	if(key=='c'||key=='C')
		seq=0;
		
	if(key=='s'||key=='S')
		seq=1;
		
    if(key=='l')
		l=~l;
		
    if(key=='L')
		L=~L;
		
    if(key=='f')
    {
		f=f+3;
		if(f>15)
		   f=0;
    }		   

	if(key=='F')
    {
		F=F+3;
		if(F>15)
		   F=0;
    }		   
	
    if(key=='t'||key=='T')
		t=~t;	
		
    if(key=='e'||key=='E')
		seq=2;				
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1100.0,700.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("HOME AUTOMATION");
    init();
    glutKeyboardFunc(keys);
    glutDisplayFunc(display);
	glutMainLoop();
}
