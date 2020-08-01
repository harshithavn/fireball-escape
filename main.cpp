/*
 * doll.c
 *
 */

#include <stdio.h>
#include <GL/glut.h> //GLUT toolkit
#include <time.h>
#define INIT_VIEW_X 0.0    //Define initial camera position and viewing window values
#define INIT_VIEW_Y 0.0
#define INIT_VIEW_Z -4.5
#define VIEW_LEFT -2.0
#define VIEW_RIGHT 2.0
#define VIEW_BOTTOM -2.0
#define VIEW_TOP 2.0
#define VIEW_NEAR 1.0
#define VIEW_FAR 200.0
GLfloat AmbientLight[]={0.3,0.3,0.3,1.0};                  //Initialization values for lighting
GLfloat DiffuseLight[] ={0.8,0.8,0.8,1.0};
GLfloat SpecularLight[] ={1.0,1.0,1.0,1.0};
GLfloat SpecRef[] = {0.7,0.7,0.7,1.0};
GLfloat LightPos[] = {-50.0,50.0,100.0,1.0};
GLint Shine =128;
GLint lookX=0,lookY=0;
float walkX=1,walkY=-4;
GLint world=1,oldX=-1,oldY=-1;
GLint doll=-1;


void eyeright()
{
    //function for the right eye
    glPushMatrix();
    glTranslatef(.17,1.1,.75);     //Specify the coordinates for the right eye
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);            //Specify the size of the right eye
    glColor3f(1.0,1.0,1.0);       //Specify the color of the eye
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}
void eyeleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.75);     //Specify the position for the left eye
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void legleft()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);     //Specify the position for the left leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void legright()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);     //Specify the position for the right leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void armleft()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);     //Specify the position for the left arm
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void armright()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);      //Specify the position for the right arm
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void handleft()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);     //Specify the position for the left hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}
void handright()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);    //Specify the position for the right hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void mouth()
{
    glPushMatrix();
    glTranslatef(0,.78,.74);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void teeth()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.76);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glPopMatrix();
}
void eyebrowleft()
{
    glPushMatrix();
    glTranslatef(-.3,1.5,.97);;
    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void eyebrowright()
{
    glPushMatrix();
    glTranslatef(.3,1.5,.97);
    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void neckring()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}


void head()
{
    glPushMatrix();
    glTranslatef(0,1.2,0);
    glScalef(.9 ,.9,.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
}

void maintopball()
{
    glPushMatrix();
    glTranslatef(0,2.2,0);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.18,100,100);
    glPopMatrix() ;
}
//int a=0,b=0;
void hatring()
{

    glPushMatrix();
    glTranslatef(0,1.4,0);
    glScalef(.84,.84,.84);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1,20,20);
    glPopMatrix();
}
void hat()
{
//    a=1;
    glPushMatrix();
    glColor3d(1,2,0);
    glTranslatef(0,2.3,0);
    glScalef(.84,.84,.84);
    glRotatef(90.0,1,0,0);
    glutSolidCone(1.4,1,20,20);
    glPopMatrix();
}

void footleft()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void footright()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void bellyCoatbottom()
{
    glPushMatrix();
    glTranslatef(0,-.2,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,.8,30,30);
    glPopMatrix();
}

void BellyCoat()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
}

void pupilleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void pupilright()
{
    glPushMatrix();
    glTranslatef(.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void topbutton()
{
    glPushMatrix();
    glTranslatef(-.1,.4,.85);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void middlebutton()
{
    glPushMatrix()  ;
    glTranslatef(-.1,.15,.98);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void bottombutton()
{
    glPushMatrix();
    glTranslatef(-.1,-.1,.92);
    glScalef(1.9,1.9,1.9);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.04,100,100);

    glPopMatrix();
}


void dance(){
    glColor3ub(50, 50, 150);
//    clo();
    //update();//Change the draw color to slate blue
    glPushMatrix();//Save viewing matrix state
    if(world==1)
	{
       	      glTranslatef(walkX,-3.5,walkY);
                 glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}


    //*******************Doll***********************
    glPushMatrix();
    glTranslatef(-1,0,-6);



    /* if(doll==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,2,0);
                  glRotatef(lookX,1,0,0);
	}*/
	hat();
    eyeright();
    eyeleft();
    eyebrowleft();
    eyebrowright();
    glColor3f(0.0,1.0,0.0);
    neckring();
    glColor3ub(50,40,60);
    legright();
    legleft();
    glColor3ub(255,90,0);
    armleft();
    armright();
    BellyCoat();
    bellyCoatbottom();
    glColor3ub(0,185,0);
    handleft();
    handright();
    mouth();
    teeth();
    glColor3ub(255,222,173);
    head();
    glColor3f(0.0,0.0,0.0);
    footleft();
    footright();
    topbutton();
    middlebutton();
    bottombutton();
    pupilleft();
    pupilright();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

float j=2.8,k=0.5,f;
int a[100],w;
void update1()
{
    j-=0.5;
    if(j<-3){
        j=2.8;k=rand()%4+1;
        //printf("k=%f\n",k);
        }


    //game
    //printf(" w:%f\n",walkX);

    //for(w=0;w<100;w++)
      //  a[w]=j;
}
float c=0;
void sh()
{

//    b=1;
    float s1=16,s2=16,z;
    int p=0,i,f=0;

    glMatrixMode(GL_MODELVIEW);
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    const double a = a*90.0;double time_spent=0;
    // printf("score=%f\n",c);
    glLoadIdentity();
    glPushMatrix();
    glColor3d(1,0,0);
//    clock_t +    +begin =clock();
    while(p<999){

    for(i=-5;i<100;i++){
    for(z=-8;z<10;z+=2){
    //c+=1;
    glPushMatrix();

    //f=2*(rand()%100-4);
    //glTranslated(f+k,j,-6);

        glTranslated(z+k,j,-6);
        //printf("x:%f\n",z+k);

        glRotated(36,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(0.2,16,16);
        //printf("j=%f\twalkx=%f\twalky=%f\n");
       if(j<-1.3 && walkY==-4  ){
            /*if(walkX==5||walkX==7)
            {
                if(walkX==z+k+1) {printf("y=%f\tj=%f\tx:%f\twalkx:%f\n",walkY,j,z+k,walkX);exit(0);}
            }*/
            if(walkX==-6||walkX==-3||walkX==-5)
            {
                if(walkX==z+k-1||walkX==z+k+1) {
                        //zprintf("y=%f\tj=%f\tx:%f\twalkx:%f\n",walkY,j,z+k,walkX);
                exit(0);}
            }
            /*if(walkX==6)
            {
                if(walkX==z+k+1){printf("y=%f\tj=%f\tx:%f\twalkx:%f\n",walkY,j,z+k,walkX);exit(0);}
            }*/
            if(walkX==2||walkX==-4||walkX==6||walkX==1||walkX==5||walkX==7||walkX==-5)
            {
                if(walkX==z+k+1||walkX==z+k-0.5){
                        //printf("y=%f\tj=%f\tx:%f\twalkx:%f\n",walkY,j,z+k,walkX);
                        exit(0);}
            }

            else
            {
                if(walkX==z+k) {
                        //printf("y=%f\tj=%f\tx:%f\twalkx:%f\n",walkY,j,z+k,walkX);
                exit(0);}
            }
           // printf("y=%f\tj=%f\tx:%f\twalkx:%f\n",walkY,j,z+k,walkX);
    //printf("j!=%f\n",j);
    }


       // printf("x:%f\twalkx:%f\n",z+k,walkX);
        glPopMatrix();
    }

   //
    /*glPushMatrix();

    //f=2*(rand()%100-4);
    //glTranslated(f+k,j,-6);

        glTranslated(-1,j,-6);
        glRotated(36,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(0.2,16,16);


    glPopMatrix();*/
    p++;
    glEnd();



     }

    }

}


void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // clo();
    dance();
    //clock_t begin =clock();
    sh();

    update1();
    glutSwapBuffers();

}



void SetupRend()
{
    //glClearColor(0.7,0.7,1.0,1.0);
    glClearColor(0.15,0.15,0.15,1.0);
    glEnable(GL_DEPTH_TEST);         //Enable depth testing
    glEnable(GL_LIGHTING);             //Enable lighting
    glLightfv(GL_LIGHT0,GL_AMBIENT,AmbientLight);//Set up and enable light zero
    glLightfv(GL_LIGHT0,GL_DIFFUSE,DiffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,SpecularLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);                   //Enable color tracking
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//Set material to follow
    glMaterialfv(GL_FRONT,GL_SPECULAR,SpecRef);//Set specular reflectivity and shine
    glMateriali(GL_FRONT,GL_SHININESS,Shine);
}

void walk(int key,int x,int y)                                      //change positions using arrow keys
{
   //if(key==GLUT_KEY_UP)    walkY+=1;
    //if(key==GLUT_KEY_DOWN)    walkY-=1;
    //if(key==GLUT_KEY_DOWN)  walkY-=1;
    //for(;;){
    //float a[50],u=0;
    if(key==GLUT_KEY_RIGHT && walkX<8.5 ){ walkX+=1;}
    if(key==GLUT_KEY_LEFT && walkX>-6.5) { walkX-=1;}

    //printf("sore=%f\n",c+=c);

    //if(key==GLUT_KEY_F10)    world=-world;
    //if(key==GLUT_KEY_F9)    doll=-doll;

}



void myReshape(int w, int h)
{
    GLfloat Ratio;
    glViewport(0,0,w,h);
    Ratio=1*w/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(50.0,Ratio,VIEW_NEAR,VIEW_FAR);
    gluPerspective(50,(double)w/(double)h,0.1,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(INIT_VIEW_X,INIT_VIEW_Y,INIT_VIEW_Z);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    //const double t = glutGet(GLUT_ELAPSED_TIME);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1500, 750);
    glutInitWindowPosition(20,20);
    glutCreateWindow("climax");
    glutReshapeFunc(myReshape);

//    glutReshapeFunc(reshaped);
    double t_time;
    clock_t start,end;
    start = clock();
    srand(time(NULL));
    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutSpecialFunc(walk);

    //printf("score=%.0f\n",(t_time));
//    glutPassiveMotionFunc(gaze);
    SetupRend();
    glEnable(GL_NORMALIZE);
     t_time=((double)(end-start))/CLK_TCK;
    if(t_time>0)
    t_time+=t_time;
    printf("score=%.0f\n",(t_time/100-39821.55)+100000+40);
    glutMainLoop();

}


