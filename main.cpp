#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<GL/gl.h>
#define PI          3.141516
#include<math.h>
#include <mmsystem.h>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////
GLfloat boatposition = 0.0f; //initial position of boat
GLfloat boatspeed = 0.015f;

GLfloat copyboatposition1 = -1.0f; //initial position of boat
GLfloat copyboatspeed1 = 0.01f;

GLfloat copyboatposition2 = 0.0f; //initial position of boat
GLfloat copyboatspeed2 = 0.01f;

GLfloat waterposition = 0.0;
GLfloat waterspeed = 0.015f;

GLfloat pos_car = 0.0f;
GLfloat speed_car = 0.05f;

GLfloat sunposition = 0.0f;
GLfloat sunspeed = 0.004f;

GLfloat moonposition = 0.0f;
GLfloat moonspeed = 0.004f;

GLfloat pos_cloud1 = 0.0f;
GLfloat speed_cloud1 = 0.014f;

GLfloat pos_cloud2 = 0.0f;
GLfloat speed_cloud2 = 0.014f;

GLfloat pos_plane = 0.0f;
GLfloat speed_plane = 0.02f;

GLfloat iceposition = 0.0f;
GLfloat icespeed = 0.003f;

GLfloat rainposition = 0.0f;
GLfloat rainspeed = 0.02f;

////////////////////////////////////////////////////////////////////

//BOOL isNight=FALSE;
//BOOL isDAY=TRUE;
//BOOL isRAIN =FALSE;

////////////////////////////////////////////////////////////////////

//float rain =0.0f;
/*
float tx = 0.0;
float ty = 0.0;
float tz = -30.0;

static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.2;
float sx = 0;
float sy = 1;
float sz = 0;
*/
/////////////////////////////////////////////////////////////
//Timer Functions
void boatupdate(int value);
void waterfallupdate(int value);
void update_sun(int value);
void update_moon(int value);
void update_cloud1(int value);
void update_cloud2(int value);
void update_car(int value);
void update_plane(int value);

/////////////////////////////////////////////////////////////
//Day Time [Summer] Functions - Base Object functions
void Boat(); //done, key action needed
void Circle(); //done
void Sun(); // done, key action needed
void Moon(); //WIP
void Cloud1(); //done, key action needed
void Cloud2(); //done, key action needed
void Mountains(); //done
void Waterfall(); //done
void Sky(); //done
void River(); //done
void City(); //working
void Land(); //done
void Bridge(); //working
void Lamppost();//done
void LamppostTranslate();//done
void Car(); //done, key action needed
void Plane(); //done, key action needed
void Trees(); //done
void DayScene();//done
///////////////////////////////////////////////////////////////
//Night Time Functions
void NightCar();//done
void NightCity();//done
void NightBridge();//done
void NightMountains();//done
void NightRiver();//done
void NightWaterfall();//done
void NightLamppost();//done
void NightLamppostTranslate();//done
void NightScene();//done
///////////////////////////////////////////////////////////////
//Winter Functions
void WinterIce();
void WinterIceTranslate();
void WinterSun();
void WinterCloud1();
void WinterCloud2();
void WinterMountains();
void WinterWaterfall();
void WinterSky();
void WinterRiver();
void WinterCity();
void WinterLand();
void WinterBridge();
void WinterTrees();
void WinterScene();
///////////////////////////////////////////////////////////////
//Autumn Functions
void SkyAutumn();
void SunAutumn();
void Cloud1Autumn();
void Cloud2Autumn();
void RiverAutumn();
void BoatAutumn();
void MountainsAutumn();
void WaterfallAutumn();
void CityAutumn();
void LandAutumn();
void BridgeAutumn();
void TreesAutumn();
void AutumnScene();
///////////////////////////////////////////////////////////////
//Spring [needs to have flowers or fruits on trees and mountains] Functions
void SpringSun();
void SpringCloud1();
void SpringCloud2();
void SpringMountains();
void SpringWaterfall();
void SpringSky();
void SpringRiver();
void SpringCity();
void SpringLand();
void SpringBridge();
void SpringTrees();
void SpringTressForest();
void SpringElements();
void SpringScene();
///////////////////////////////////////////////////////////////
//Rainy Season Functions

///////////////////////////////////////////////////////////////
//Universal Functions
void Circle();
///////////////////////////////////////////////////////////////

void boatupdate(int value)
{

    if(boatposition <-0.405) // this is where the object goes until it goes back to initial position
        boatposition = 1.0f;

    boatposition -= boatspeed;

glutPostRedisplay();
glutTimerFunc(100, boatupdate, 0);
}

void copyboatupdate1(int value)
{

    if(copyboatposition1 <-0.05) // this is where the object goes until it goes back to initial position
        copyboatposition1 = 1.0f;

    copyboatposition1-= copyboatspeed1;

glutPostRedisplay();
glutTimerFunc(100, copyboatupdate1, 0);
}

void copyboatupdate2(int value)
{

    if(copyboatposition2 <-1.0) // this is where the object goes until it goes back to initial position
        copyboatposition2 = -0.0f;

    copyboatposition2-= copyboatspeed2;

glutPostRedisplay();
glutTimerFunc(100, copyboatupdate2, 0);
}

void iceupdate(int value)
{

    if(iceposition <-0.305) // this is where the object goes until it goes back to initial position
        iceposition = 1.0f;

    iceposition -= icespeed;

glutPostRedisplay();
glutTimerFunc(100, iceupdate, 0);
}

void waterfallupdate(int value)
{

    if(waterposition <-0.309) // this is where the object goes until it goes back to initial position
        waterposition = 0.0f;

    waterposition -= waterspeed;

glutPostRedisplay();
glutTimerFunc(100, waterfallupdate, 0);
}

void update_sun(int value)
{

    if(sunposition <-1.0)
        sunposition = 1.0f;

    sunposition  -= sunspeed;

glutPostRedisplay();
glutTimerFunc(100, update_sun, 0);
}

void update_moon(int value)
{

    if(moonposition <-1.0)
        moonposition = 1.0f;

    moonposition  -= moonspeed;

glutPostRedisplay();
glutTimerFunc(100, update_moon, 0);
}

void update_cloud1(int value)
{

    if(pos_cloud1 <-1.0)
        pos_cloud1 = 1.0f;

    pos_cloud1  -= speed_cloud1;

glutPostRedisplay();
glutTimerFunc(100, update_cloud1, 0);
}

void update_cloud2(int value)
{

    if(pos_cloud2 <-1.0)
        pos_cloud2 = 1.0f;

    pos_cloud2  -= speed_cloud2;

glutPostRedisplay();
glutTimerFunc(100, update_cloud2, 0);
}

void update_car(int value)
{

    if(pos_car <-2.0)
        pos_car = 1.0f;

    pos_car  -= speed_car;

glutPostRedisplay();
glutTimerFunc(100, update_car, 0);
}

void update_plane(int value)
{

    if(pos_plane <-1.0)
        pos_plane = 1.0f;

    pos_plane  -= speed_plane;

glutPostRedisplay();
glutTimerFunc(100, update_plane, 0);
}

void update_rain(int value)
{

    if(rainposition <-1.0)
        rainposition = 1.0f;

    rainposition  -= rainspeed;

glutPostRedisplay();
glutTimerFunc(100, update_rain, 0);
}


void Circle(GLfloat p, GLfloat q, GLfloat radius, int triangle)
{
	int i;

//  GLfloat p1=0.0f; GLfloat q1= 0.50f; GLfloat r1 = 0.15f;
//    int tringle2=40;

    GLfloat tp =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    glVertex2f (p,q);
    for(i= 0;i<=triangle; i++)
    {
        glVertex2f (
                    p+(radius*cos(i*tp/triangle)),
                    q+(radius*sin(i*tp/triangle))
                    );


    }
    glEnd ();
}

void Raindrop()
{
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(178,220,255);

	glVertex2f(-0.793f, 0.225f);
	glVertex2f(-0.793f,0.21f);
}

void Rain()
{
    glPushMatrix();
    glTranslatef(0.0f, rainposition, 0.0f);
    for (int i=1; i<=100; i++)
    {
        int x=rand(),y=rand();
        x%=840; y%=843;
        if(x>=840&&x<=843&&y<=843)continue;
        Raindrop();
    }


	glEnd();
/*    for(int i=1;i<=100;i++)
    {
        int x=rand(),y=rand();
        x%=840; y%=843;
        if(x>=840&&x<=843&&y<=843)continue;
        glBegin(GL_LINES);
		glLineWidth(5.0);
        glColor3ub(0,0,0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }*/
    glPopMatrix();
    //glutSwapBuffers();
}

void BoatModel()
{
	glPushMatrix();

    glBegin(GL_POLYGON);
	glColor3ub(158,75,9);
	glVertex2f(-0.013f,-0.762f);//a
	glVertex2f(-0.066f,-0.714f);//b
	glVertex2f(-0.066f,-0.65f);//c
	glVertex2f(-0.013f,-0.611f);//d
	glVertex2f(0.04f,-0.65f);//e
	glVertex2f(0.04f,-0.714f);//f
	glVertex2f(-0.013f,-0.762f);//g
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(169,89,17);
	glVertex2f(-0.013f,-0.756f);//a
	glVertex2f(-0.06f,-0.714f);//b
	glVertex2f(-0.06f,-0.65f);//c
	glVertex2f(-0.013f,-0.62f);//d
	glVertex2f(0.035f,-0.65f);//e
	glVertex2f(0.035f,-0.714f);//f
	glVertex2f(-0.013f,-0.762f);//g
	glEnd();
//Horizontal Mast
   glBegin(GL_QUADS);
   glColor3ub(215,151,77);
   glVertex2f(-0.098f,-0.661f);
   glVertex2f(-0.098f,-0.656f);
   glVertex2f(0.071f,-0.661f);
   glVertex2f(0.071f,-0.656f);
   glEnd();

//Vertical Mast
   glBegin(GL_QUADS);
   glColor3ub(215,151,77);
   glVertex2f(-0.01f,-0.675f);
   glVertex2f(-0.015f,-0.675f);
   glVertex2f(-0.01f,-0.574f);
   glVertex2f(-0.015f,-0.574f);
   glEnd();

//Sails

  	glBegin(GL_TRIANGLES);
	glColor3ub(255,255,255);
	glVertex2f(-0.02f, -0.655f);
	glVertex2f(-0.02f, -0.58f);
	glVertex2f(-0.095f, -0.655f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255,255,255);
	glVertex2f(-0.007f, -0.655f);
	glVertex2f(-0.007f, -0.58f);
	glVertex2f(0.07f, -0.655f);
	glEnd();

//Wires

    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(178,220,255);

	glVertex2f(-0.095f, -0.655f);
	glVertex2f(-0.066f,-0.714f);

	glVertex2f(-0.08f, -0.655f);
	glVertex2f(-0.066f,-0.714f);

    glVertex2f(0.07f, -0.655f);
	glVertex2f(0.04f,-0.714f);

	glVertex2f(0.055f,-0.655f);
	glVertex2f(0.04f,-0.714f);

	glVertex2f(-0.007f, -0.58f);
	glVertex2f(-0.013f,-0.756f);

	glVertex2f(-0.02f, -0.58f);
	glVertex2f(-0.013f,-0.756f);

	glEnd();

	glPopMatrix();
}

void Boat()
{
	glPushMatrix();
	glTranslatef(0.0f,-boatposition, 0.0f);
	BoatModel();
	glEnd();

	glPopMatrix();
}

void BoatAutumn()
{
	glPushMatrix();
	glTranslatef(0.0f,-boatposition, 0.0f);

    glBegin(GL_POLYGON);
	glColor3ub(169,89,17);
	glVertex2f(-0.013f,-0.762f);//a
	glVertex2f(-0.066f,-0.714f);//b
	glVertex2f(-0.066f,-0.65f);//c
	glVertex2f(-0.013f,-0.611f);//d
	glVertex2f(0.04f,-0.65f);//e
	glVertex2f(0.04f,-0.714f);//f
	glVertex2f(-0.013f,-0.762f);//g
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(169,89,17);
	glVertex2f(-0.013f,-0.756f);//a
	glVertex2f(-0.06f,-0.714f);//b
	glVertex2f(-0.06f,-0.65f);//c
	glVertex2f(-0.013f,-0.62f);//d
	glVertex2f(0.035f,-0.65f);//e
	glVertex2f(0.035f,-0.714f);//f
	glVertex2f(-0.013f,-0.762f);//g
	glEnd();
//Horizontal Mast
   glBegin(GL_QUADS);
   glColor3ub(208,147,79);
   glVertex2f(-0.098f,-0.661f);
   glVertex2f(-0.098f,-0.656f);
   glVertex2f(0.071f,-0.661f);
   glVertex2f(0.071f,-0.656f);
   glEnd();

//Vertical Mast
   glBegin(GL_QUADS);
   glColor3ub(208,147,79);
   glVertex2f(-0.01f,-0.675f);
   glVertex2f(-0.015f,-0.675f);
   glVertex2f(-0.01f,-0.574f);
   glVertex2f(-0.015f,-0.574f);
   glEnd();

//Sails

  	glBegin(GL_TRIANGLES);
	glColor3ub(151,199,255);
	glVertex2f(-0.02f, -0.655f);
	glVertex2f(-0.02f, -0.58f);
	glVertex2f(-0.095f, -0.655f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(151,199,255);
	glVertex2f(-0.007f, -0.655f);
	glVertex2f(-0.007f, -0.58f);
	glVertex2f(0.07f, -0.655f);
	glEnd();

//Wires

    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(63,169,204);

	glVertex2f(-0.095f, -0.655f);
	glVertex2f(-0.066f,-0.714f);

	glVertex2f(-0.08f, -0.655f);
	glVertex2f(-0.066f,-0.714f);

    glVertex2f(0.07f, -0.655f);
	glVertex2f(0.04f,-0.714f);

	glVertex2f(0.055f,-0.655f);
	glVertex2f(0.04f,-0.714f);

	glVertex2f(-0.007f, -0.58f);
	glVertex2f(-0.013f,-0.756f);

	glVertex2f(-0.02f, -0.58f);
	glVertex2f(-0.013f,-0.756f);

	glEnd();

	glPopMatrix();
}

void BoatCopies()
{
    glPushMatrix();
    glTranslatef(0.0f,-copyboatposition1,0.0f);
    glTranslatef(-0.20f,0.0f,0.0f);
    glScalef(0.5f,0.5f,0.5f);
    BoatModel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,copyboatposition2,0.0f);
    glTranslatef(0.20f,0.0f,0.0f);
    glScalef(0.5f,0.5f,0.5f);
    BoatModel();
    glPopMatrix();
}


void WinterIce()
{
	glPushMatrix();
	glTranslatef(0.0f,-iceposition, 0.0f);

    glBegin(GL_POLYGON);
	glColor3ub(198,231,255);
	glVertex2f(-0.013f,-0.762f);//a
	glVertex2f(-0.066f,-0.714f);//b
	glVertex2f(-0.066f,-0.65f);//c
	glVertex2f(-0.013f,-0.611f);//d
	glVertex2f(0.04f,-0.65f);//e
	glVertex2f(0.04f,-0.714f);//f
	glVertex2f(-0.013f,-0.762f);//g
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(107,183,243);
	glVertex2f(-0.013f,-0.756f);//a
	glVertex2f(-0.06f,-0.714f);//b
	glVertex2f(-0.06f,-0.65f);//c
	glVertex2f(-0.013f,-0.62f);//d
	glVertex2f(0.035f,-0.65f);//e
	glVertex2f(0.035f,-0.714f);//f
	glVertex2f(-0.013f,-0.762f);//g
	glEnd();
	glPopMatrix();
}

void WinterIceTranslate()
{

	glPushMatrix();
	glTranslatef(-0.1f, 0.1f, 0.0f);
	WinterIce();
    glTranslatef(-0.1f, -0.1f, 0.0f);
	WinterIce();
	glPopMatrix();
}

void Sun(void)
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
    glColor4ub(230,252,121,30);
	glTranslatef(0.0f,sunposition, 0.0f);
	Circle(0.0f, 0.50f, 0.20f, 40);
	glColor4ub(230,252,121,50);
    Circle(0.0f, 0.50f, 0.18f, 40);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f,sunposition, 0.0f);
	glColor3ub (252, 229, 112);
    Circle(0.0f, 0.50f, 0.15f, 40);
	glPopMatrix();
	glEnd();
}

void WinterSun(void)
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
    glColor4ub(250,214,137,30);
	glTranslatef(0.0f,sunposition, 0.0f);
	Circle(0.0f, 0.50f, 0.20f, 40);
	glColor4ub(250,214,137,50);
    Circle(0.0f, 0.50f, 0.18f, 40);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f,sunposition, 0.0f);
	glColor3ub (250,214,137);
    Circle(0.0f, 0.50f, 0.15f, 40);
	glPopMatrix();
	glEnd();
}

void SpringSun(void)
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
    glColor4ub(250,214,137,30);
	glTranslatef(0.0f,sunposition, 0.0f);
	Circle(0.0f, 0.50f, 0.20f, 40);
	glColor4ub(250,214,137,50);
    Circle(0.0f, 0.50f, 0.18f, 40);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f,sunposition, 0.0f);
	glColor3ub (250,214,137);
    Circle(0.0f, 0.50f, 0.15f, 40);
	glPopMatrix();
	glEnd();
}

void SunAutumn(void)
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
    glColor4ub(253,185,38,255);
	glTranslatef(0.0f,sunposition, 0.0f);
	Circle(0.0f, 0.50f, 0.20f, 40);
	glColor4ub(253,185,38,255);
    Circle(0.0f, 0.50f, 0.18f, 40);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f,sunposition, 0.0f);
	glColor3ub ( 253,185,38);
    Circle(0.0f, 0.50f, 0.15f, 40);
	glPopMatrix();
	glEnd();
}

void Moon(void)
{

	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
    glColor4ub(243,241,183,30);
	glTranslatef(0.0f,moonposition, 0.0f);
	Circle(-0.237f, 0.73f, 0.17f, 40);
	glColor4ub(243,241,183,50);
    Circle(-0.237f, 0.73f, 0.135f, 40);
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f,moonposition, 0.0f);
	glColor3ub (243,241,183);
    Circle(-0.237f, 0.73f, 0.122f, 40);
	glPopMatrix();
	glEnd();
}

void WinterCloud1(void)
{
	glPushMatrix();
	glScalef(0.8f,0.8f,0.8f);
	glTranslatef(0.0f, 0.2f,0.0f);
	glTranslatef(pos_cloud1,0.0f, 0.0f);
	glColor3ub (154,196,248);
    Circle(-0.60f, 0.60f, 0.10f, 40);
	Circle(-0.52f, 0.58f, 0.08f, 40);
	Circle(-0.68f, 0.58f, 0.08f, 40);
	Circle(-0.60f, 0.55f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void WinterCloud2(void)
{
	glPushMatrix();
	glScalef(0.8f,0.8f,0.8f);
	glTranslatef(0.0f, 0.2f,0.0f);
	glTranslatef(-pos_cloud2,0.0f, 0.0f);
	glColor3ub (154,196,248);
    Circle(0.60f, 0.80f, 0.10f, 40);
	Circle(0.52f, 0.78f, 0.08f, 40);
	Circle(0.68f, 0.78f, 0.08f, 40);
	Circle(0.60f, 0.75f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void Cloud1(void)
{
	glPushMatrix();
    glScalef(0.8f,0.8f,0.8f);
	glTranslatef(0.0f, 0.2f,0.0f);
	glTranslatef(pos_cloud1,0.0f, 0.0f);
	glColor3ub (255, 255, 255);
    Circle(-0.60f, 0.60f, 0.10f, 40);
	Circle(-0.52f, 0.58f, 0.08f, 40);
	Circle(-0.68f, 0.58f, 0.08f, 40);
	Circle(-0.60f, 0.55f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void Cloud2(void)
{
	glPushMatrix();
    glScalef(0.8f,0.8f,0.8f);
	glTranslatef(0.0f, 0.2f,0.0f);
	glTranslatef(-pos_cloud2,0.0f, 0.0f);
	glColor3ub (255, 255, 255);
    Circle(0.60f, 0.80f, 0.10f, 40);
	Circle(0.52f, 0.78f, 0.08f, 40);
	Circle(0.68f, 0.78f, 0.08f, 40);
	Circle(0.60f, 0.75f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}


void SpringCloud1(void)
{
	glPushMatrix();
	glScalef(0.8f,0.8f,0.8f);
	glTranslatef(0.0f, 0.2f,0.0f);
	glTranslatef(pos_cloud1,0.0f, 0.0f);
	glColor3ub (250,255,255);
    Circle(-0.60f, 0.60f, 0.10f, 40);
	Circle(-0.52f, 0.58f, 0.08f, 40);
	Circle(-0.68f, 0.58f, 0.08f, 40);
	Circle(-0.60f, 0.55f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void SpringCloud2(void)
{
	glPushMatrix();
	glScalef(0.8f,0.8f,0.8f);
	glTranslatef(0.0f, 0.2f,0.0f);
	glTranslatef(-pos_cloud2,0.0f, 0.0f);
	glColor3ub (250,255,255);
    Circle(0.60f, 0.80f, 0.10f, 40);
	Circle(0.52f, 0.78f, 0.08f, 40);
	Circle(0.68f, 0.78f, 0.08f, 40);
	Circle(0.60f, 0.75f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void Cloud1Autumn(void)
{
	glPushMatrix();
	glTranslatef(pos_cloud1,0.0f, 0.0f);
	glColor3ub (239,185,174);
    Circle(-0.60f, 0.60f, 0.10f, 40);
	Circle(-0.52f, 0.58f, 0.08f, 40);
	Circle(-0.68f, 0.58f, 0.08f, 40);
	Circle(-0.60f, 0.55f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void Cloud2Autumn(void)
{
	glPushMatrix();
	glTranslatef(-pos_cloud2,0.0f, 0.0f);
	glColor3ub (239,185,174);
    Circle(0.60f, 0.80f, 0.10f, 40);
	Circle(0.52f, 0.78f, 0.08f, 40);
	Circle(0.68f, 0.78f, 0.08f, 40);
	Circle(0.60f, 0.75f, 0.08f, 40);
	glPopMatrix();
	glEnd();
}

void Mountains()
{
//Tall Mountain
   glBegin(GL_POLYGON);
   glColor3ub(139,69,19); //Saddle Brown
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(-1.0f,0.49f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.69f,0.26f);
   glVertex2f(-0.33f,-0.30f);
   glEnd();
//Short Mountain
   glBegin(GL_POLYGON);
   glColor3ub(205,133,63); //Peru
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(-1.0f,0.14f);
   glVertex2f(-0.92f,0.28f);
   glVertex2f(-0.79f,0.07f);
   glVertex2f(-0.69f,0.19f);
   glVertex2f(-0.44f,-0.30f);
   glEnd();
}

void WinterMountains()
{
//Tall Mountain
   glBegin(GL_POLYGON);
   glColor3ub(154,190,249);
   glVertex2f(-1.0f,-0.30f);
   glColor3ub(154,190,249);
   glVertex2f(-1.0f,0.49f);
   glColor3ub(154,190,249);
   glVertex2f(-0.76f,0.22f);
   glColor3ub(250,250,255);
   glVertex2f(-0.69f,0.26f);
   glColor3ub(250,250,255);
   glVertex2f(-0.33f,-0.30f);
   glEnd();
//Short Mountain
   glBegin(GL_POLYGON);
   glColor3ub(1,92,155);
   glVertex2f(-1.0f,-0.30f);
   glColor3ub(1,92,155);
   glVertex2f(-1.0f,0.14f);
   glColor3ub(1,92,155);
   glVertex2f(-0.92f,0.28f);
   glColor3ub(1,92,155);
   glVertex2f(-0.79f,0.07f);
   glColor3ub(8,90,148);
   glVertex2f(-0.69f,0.19f);
   glColor3ub(8,90,148);
   glVertex2f(-0.44f,-0.30f);
   glEnd();
}

void SpringMountains()
{
//Tall Mountain
   glBegin(GL_POLYGON);
   glColor3ub(32,73,5);
   glVertex2f(-1.0f,-0.30f);
   glColor3ub(102,123,4);
   glVertex2f(-1.0f,0.49f);
   glColor3ub(102,123,4);
   glVertex2f(-0.76f,0.22f);
   glColor3ub(102,123,4);
   glVertex2f(-0.69f,0.26f);
   glColor3ub(32,73,5);
   glVertex2f(-0.33f,-0.30f);
   glEnd();
//Short Mountain
   glBegin(GL_POLYGON);
   glColor3ub(27,77,11);
   glVertex2f(-1.0f,-0.30f);
   glColor3ub(217,199,4);
   glVertex2f(-1.0f,0.14f);
   glColor3ub(217,199,4);
   glVertex2f(-0.92f,0.28f);
   glColor3ub(217,199,4);
   glVertex2f(-0.79f,0.07f);
   glColor3ub(217,199,4);
   glVertex2f(-0.69f,0.19f);
   glColor3ub(27,77,11);
   glVertex2f(-0.44f,-0.30f);
   glEnd();
}

void NightMountains()
{
//Tall Mountain
   glBegin(GL_POLYGON);
   glColor3ub(71,51,33); //Saddle Brown
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(-1.0f,0.49f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.69f,0.26f);
   glVertex2f(-0.33f,-0.30f);
   glEnd();
//Short Mountain
   glBegin(GL_POLYGON);
   glColor3ub(92,69,50); //Peru
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(-1.0f,0.14f);
   glVertex2f(-0.92f,0.28f);
   glVertex2f(-0.79f,0.07f);
   glVertex2f(-0.69f,0.19f);
   glVertex2f(-0.44f,-0.30f);
   glEnd();
}

void MountainsAutumn()
{
//Tall Mountain
   glBegin(GL_POLYGON);
   glColor3ub(96,89,113); //Saddle Brown
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(-1.0f,0.49f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.69f,0.26f);
   glVertex2f(-0.33f,-0.30f);
   glEnd();
//Short Mountain
   glBegin(GL_POLYGON);
   glColor3ub(146,118,108); //Peru
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(-1.0f,0.14f);
   glVertex2f(-0.92f,0.28f);
   glVertex2f(-0.79f,0.07f);
   glVertex2f(-0.69f,0.19f);
   glVertex2f(-0.44f,-0.30f);
   glEnd();
}

void Waterfall()
{
//Waterfall
   glBegin(GL_QUADS);
   glColor3ub(90,135,253);
   glVertex2f(-0.805f,0.2752f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(90,135,253);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.69f,-0.30f);
   glVertex2f(-0.90f,-0.30f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   //Flowing Animation
   glPushMatrix();
   glTranslatef(0.0f,waterposition, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(178,220,255);

	glVertex2f(-0.793f, 0.225f);
	glVertex2f(-0.793f,0.21f);

	glVertex2f(-0.776f, 0.215f);
	glVertex2f(-0.776f,0.198f);

	glVertex2f(-0.795f, 0.16f);
	glVertex2f(-0.795f, 0.14f);

	glVertex2f(-0.79f, 0.13f);
	glVertex2f(-0.79f, 0.11f);

	glVertex2f(-0.782f, 0.11f);
	glVertex2f(-0.782f, 0.09f);

	glVertex2f(-0.8f, 0.02f);
	glVertex2f(-0.8f, 0.0f);

	glVertex2f(-0.8f, 0.095f);
	glVertex2f(-0.8f, 0.115f);

	glVertex2f(-0.78f, 0.05f);
	glVertex2f(-0.78f, 0.03f);

	glVertex2f(-0.805f, 0.06f);
	glVertex2f(-0.805f, 0.042f);

	glEnd();

   glPopMatrix();

}

void WinterWaterfall()
{
//Waterfall
   glBegin(GL_QUADS);
   glColor3ub(59,117,199);
   glVertex2f(-0.805f,0.2752f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(59,117,199);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.69f,-0.30f);
   glVertex2f(-0.90f,-0.30f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   //Flowing Animation - Frozen in winter
   glPushMatrix();
   glTranslatef(0.0f,0.0f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(178,220,255);

	glVertex2f(-0.793f, 0.225f);
	glVertex2f(-0.793f,0.21f);

	glVertex2f(-0.776f, 0.215f);
	glVertex2f(-0.776f,0.198f);

	glVertex2f(-0.795f, 0.16f);
	glVertex2f(-0.795f, 0.14f);

	glVertex2f(-0.79f, 0.13f);
	glVertex2f(-0.79f, 0.11f);

	glVertex2f(-0.782f, 0.11f);
	glVertex2f(-0.782f, 0.09f);

	glVertex2f(-0.8f, 0.02f);
	glVertex2f(-0.8f, 0.0f);

	glVertex2f(-0.8f, 0.095f);
	glVertex2f(-0.8f, 0.115f);

	glVertex2f(-0.78f, 0.05f);
	glVertex2f(-0.78f, 0.03f);

	glVertex2f(-0.805f, 0.06f);
	glVertex2f(-0.805f, 0.042f);

	glEnd();

   glPopMatrix();

}

void SpringWaterfall()
{
//Waterfall
   glBegin(GL_QUADS);
   glColor3ub(38,196,254);
   glVertex2f(-0.805f,0.2752f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(38,196,254);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.69f,-0.30f);
   glVertex2f(-0.90f,-0.30f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   //Flowing Animation
   glPushMatrix();
   glTranslatef(0.0f,waterposition, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(178,220,255);

	glVertex2f(-0.793f, 0.225f);
	glVertex2f(-0.793f,0.21f);

	glVertex2f(-0.776f, 0.215f);
	glVertex2f(-0.776f,0.198f);

	glVertex2f(-0.795f, 0.16f);
	glVertex2f(-0.795f, 0.14f);

	glVertex2f(-0.79f, 0.13f);
	glVertex2f(-0.79f, 0.11f);

	glVertex2f(-0.782f, 0.11f);
	glVertex2f(-0.782f, 0.09f);

	glVertex2f(-0.8f, 0.02f);
	glVertex2f(-0.8f, 0.0f);

	glVertex2f(-0.8f, 0.095f);
	glVertex2f(-0.8f, 0.115f);

	glVertex2f(-0.78f, 0.05f);
	glVertex2f(-0.78f, 0.03f);

	glVertex2f(-0.805f, 0.06f);
	glVertex2f(-0.805f, 0.042f);

	glEnd();

   glPopMatrix();

}

void NightWaterfall()
{
//Waterfall
   glBegin(GL_QUADS);
   glColor3ub(51,75,229);
   glVertex2f(-0.805f,0.2752f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(51,75,229);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.69f,-0.30f);
   glVertex2f(-0.90f,-0.30f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   //Flowing Animation
   glPushMatrix();
   glTranslatef(0.0f,waterposition, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(71,97,236);

	glVertex2f(-0.793f, 0.225f);
	glVertex2f(-0.793f,0.21f);

	glVertex2f(-0.776f, 0.215f);
	glVertex2f(-0.776f,0.198f);

	glVertex2f(-0.795f, 0.16f);
	glVertex2f(-0.795f, 0.14f);

	glVertex2f(-0.79f, 0.13f);
	glVertex2f(-0.79f, 0.11f);

	glVertex2f(-0.782f, 0.11f);
	glVertex2f(-0.782f, 0.09f);

	glVertex2f(-0.8f, 0.02f);
	glVertex2f(-0.8f, 0.0f);

	glVertex2f(-0.8f, 0.095f);
	glVertex2f(-0.8f, 0.115f);

	glVertex2f(-0.78f, 0.05f);
	glVertex2f(-0.78f, 0.03f);

	glVertex2f(-0.805f, 0.06f);
	glVertex2f(-0.805f, 0.042f);
	glEnd();

   glPopMatrix();

}

void WaterfallAutumn()
{
//Waterfall
   glBegin(GL_QUADS);
   glColor3ub(131,205,245);
   glVertex2f(-0.805f,0.2752f);
   glVertex2f(-0.76f,0.22f);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(131,205,245);
   glVertex2f(-0.77f,0.11f);
   glVertex2f(-0.69f,-0.30f);
   glVertex2f(-0.90f,-0.30f);
   glVertex2f(-0.81f,0.11f);
   glEnd();

   //Flowing Animation
   glPushMatrix();
   glTranslatef(0.0f,waterposition, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3ub(161,214,251);

	glVertex2f(-0.793f, 0.225f);
	glVertex2f(-0.793f,0.21f);

	glVertex2f(-0.776f, 0.215f);
	glVertex2f(-0.776f,0.198f);

	glVertex2f(-0.795f, 0.16f);
	glVertex2f(-0.795f, 0.14f);

	glVertex2f(-0.79f, 0.13f);
	glVertex2f(-0.79f, 0.11f);

	glVertex2f(-0.782f, 0.11f);
	glVertex2f(-0.782f, 0.09f);

	glVertex2f(-0.8f, 0.02f);
	glVertex2f(-0.8f, 0.0f);

	glVertex2f(-0.8f, 0.095f);
	glVertex2f(-0.8f, 0.115f);

	glVertex2f(-0.78f, 0.05f);
	glVertex2f(-0.78f, 0.03f);

	glVertex2f(-0.805f, 0.06f);
	glVertex2f(-0.805f, 0.042f);

	glEnd();

   glPopMatrix();

}

void Sky()
{
   glBegin(GL_QUADS);
   glColor3ub(135,206,250);
   glVertex2f(-1.0f,-0.3f);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(1.0f,1.0f);
   glVertex2f(1.0f,-0.3f);
   glEnd();
}

void NightSky()
{
   glBegin(GL_QUADS);
   glColor3ub(75,121,204);
   glVertex2f(-1.0f,-0.3f);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(1.0f,1.0f);
   glVertex2f(1.0f,-0.3f);
   glEnd();
}

void WinterSky()
{
   glBegin(GL_QUADS);
   glColor3ub(51,187,245);
   glVertex2f(-1.0f,-0.3f);
   glColor3ub(2,116,205);
   glVertex2f(-1.0f,1.0f);
   glColor3ub(2,116,205);
   glVertex2f(1.0f,1.0f);
   glColor3ub(51,187,245);
   glVertex2f(1.0f,-0.3f);
   glEnd();
}

void SpringSky()
{
   glBegin(GL_QUADS);
   glColor3ub(235,225,245);
   glVertex2f(-1.0f,-0.3f);
   glColor3ub(18,193,225);
   glVertex2f(-1.0f,1.0f);
   glColor3ub(18,193,225);
   glVertex2f(1.0f,1.0f);
   glColor3ub(235,225,245);
   glVertex2f(1.0f,-0.3f);
   glEnd();
}

void SkyAutumn()
{
   glBegin(GL_QUADS);
   glColor3ub(182,168,201);
   glVertex2f(-1.0f,-0.3f);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(1.0f,1.0f);
   glVertex2f(1.0f,-0.3f);
   glEnd();
}

void River()
{
    glBegin(GL_QUADS);
	glColor3ub(67, 110, 238); // RoyalBlue2

	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.30f);
	glVertex2f(-1.0f, -0.30f);
	glEnd();
//River Upperbody
   glBegin(GL_POLYGON);
   glColor3ub(0,154,205); // DeepSkyBlue3
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(0.02f,-0.34f);
   glVertex2f(0.38f,-0.40f);
   glVertex2f(0.55f,-0.56f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(1.0f,-1.0f);
   glVertex2f(-1.0f,-1.0f);
   glEnd();
}

void NightRiver()
{
    glBegin(GL_QUADS);
	glColor3ub(38,62,162);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.30f);
	glVertex2f(-1.0f, -0.30f);
	glEnd();
//River Upperbody
   glBegin(GL_POLYGON);
   glColor3ub(13,57,93);
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(0.02f,-0.34f);
   glVertex2f(0.38f,-0.40f);
   glVertex2f(0.55f,-0.56f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(1.0f,-1.0f);
   glVertex2f(-1.0f,-1.0f);
   glEnd();

}

void SpringRiver()
{
    glBegin(GL_QUADS);
	glColor3ub(0,52,83);
	glVertex2f(-1.0f, -1.0f);
	glColor3ub(0,52,83);
	glVertex2f(1.0f, -1.0f);
	glColor3ub(0,187,207);
    glVertex2f(1.0f, -0.30f);
	glColor3ub(0,187,207);
	glVertex2f(-1.0f, -0.30f);
	glEnd();

//River Upperbody - 40% transparency
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glBegin(GL_POLYGON);
   glColor4ub(2,96,114,40);
   glVertex2f(-1.0f,-0.32f);
   glColor4ub(2,96,114,40);
   glVertex2f(0.02f,-0.34f);
   glColor4ub(2,96,114,40);
   glVertex2f(0.38f,-0.40f);
   glColor4ub(2,96,114,40);
   glVertex2f(0.55f,-0.56f);
   glColor4ub(22,74,178,40);
   glVertex2f(1.0f,-0.65f);
   glColor4ub(22,74,178,40);
   glVertex2f(1.0f,-1.0f);
   glColor4ub(22,74,178,40);
   glVertex2f(-1.0f,-1.0f);
   glEnd();
}

void WinterRiver()
{
    glBegin(GL_QUADS);
	glColor3ub(50,109,203);
	glVertex2f(-1.0f, -1.0f);
	glColor3ub(50,109,203);
	glVertex2f(1.0f, -1.0f);
	glColor3ub(24,73,168);
    glVertex2f(1.0f, -0.30f);
	glColor3ub(24,73,168);
	glVertex2f(-1.0f, -0.30f);
	glEnd();
}

void RiverAutumn()
{
    glBegin(GL_QUADS);
	glColor3ub(20,152,188); // Eastern Blue

	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.30f);
	glVertex2f(-1.0f, -0.30f);
	glEnd();
//River Upperbody
   glBegin(GL_POLYGON);
   glColor3ub(6,143,179); // Bondi Blue
   glVertex2f(-1.0f,-0.30f);
   glVertex2f(0.02f,-0.34f);
   glVertex2f(0.38f,-0.40f);
   glVertex2f(0.55f,-0.56f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(1.0f,-1.0f);
   glVertex2f(-1.0f,-1.0f);
   glEnd();
}

void City()
{
//From rightmost side

//Building 1
    glBegin(GL_QUADS);
	glColor3ub(23,75,113);
	glVertex2f(0.88f, 0.41f);
	glVertex2f(0.88f, -0.30);
	glVertex2f(1.0f, -0.30f);
	glVertex2f(1.0f, 0.41f);
	glEnd();

//Building 1 Windows
    glLineWidth(25.0);
    glBegin(GL_LINES);
	glColor3ub(252,229,113);
//1
	glVertex2f(0.901f, 0.37f);
	glVertex2f(0.983f, 0.37f);
//2
	glVertex2f(0.901f, 0.32f);
	glVertex2f(0.983f, 0.32f);
//3
	glVertex2f(0.901f, 0.27f);
	glVertex2f(0.983f, 0.27f);
//4
	glVertex2f(0.901f, 0.22f);
	glVertex2f(0.983f, 0.22f);
//5
	glVertex2f(0.901f, 0.17f);
	glVertex2f(0.983f, 0.17f);
//6
	glVertex2f(0.901f, 0.12f);
	glVertex2f(0.983f, 0.12f);
//7
	glVertex2f(0.901f, 0.07f);
	glVertex2f(0.983f, 0.07f);
//8
	glVertex2f(0.901f, 0.02f);
	glVertex2f(0.983f, 0.02f);
//9
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//10
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//11
	glVertex2f(0.901f, -0.08f);
	glVertex2f(0.983f, -0.08f);
//12
	glVertex2f(0.901f, -0.13f);
	glVertex2f(0.983f, -0.13f);
//13
	glVertex2f(0.901f, -0.18f);
	glVertex2f(0.983f, -0.18f);
//14
	glVertex2f(0.901f, -0.23f);
	glVertex2f(0.983f, -0.23f);
    glEnd();

//Building 2

	glBegin(GL_QUADS);
	glColor3ub(64,64,64);
	glVertex2f(0.73f, -0.04f);
	glVertex2f(0.73f, -0.30);

	glVertex2f(0.86f, -0.30f);
	glVertex2f(0.86f, 0.16f);
	glEnd();

//Building 2 Windows

//1
	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);
	glVertex2f(0.75f, -0.045f);
	glVertex2f(0.846f, 0.1f);
	glVertex2f(0.846f, 0.058f);
	glVertex2f(0.75f, -0.084f);
	glEnd();

//2
	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);
	glVertex2f(0.820f, 0.0f);
	glVertex2f(0.848f,0.042f);
	glVertex2f(0.848f,-0.30f);
    glVertex2f(0.820f,-0.30f);
	glEnd();

//3
	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);
	glVertex2f(0.75f, -0.105f);
	glVertex2f(0.78f, -0.064f);
	glVertex2f(0.78f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glEnd();


//Building 3

	glBegin(GL_QUADS);
	glColor3ub(48,57,113);

	glVertex2f(0.58f, -0.03f);
	glVertex2f(0.58f, -0.30);

	glVertex2f(0.70f, -0.30f);
	glVertex2f(0.70f, -0.03f);
	glEnd();

//Building 3 Windows

    glBegin(GL_QUADS);
	glColor3ub(228,175,148);
//1
	glVertex2f(0.59f, -0.05f);
	glVertex2f(0.69f, -0.05f);
    glVertex2f(0.69f, -0.095f);
	glVertex2f(0.59f, -0.095f);
	glEnd();

//2
    glBegin(GL_QUADS);
	glColor3ub(228,175,148);
	glVertex2f(0.59f, -0.114f);
	glVertex2f(0.69f, -0.114f);
    glVertex2f(0.69f, -0.133f);
	glVertex2f(0.59f, -0.133f);
	glEnd();

//3
    glBegin(GL_QUADS);
	glColor3ub(228,175,148);
	glVertex2f(0.59f, -0.145f);
	glVertex2f(0.69f, -0.145f);
    glVertex2f(0.69f, -0.195f);
	glVertex2f(0.59f, -0.195f);
	glEnd();

//4
    glBegin(GL_QUADS);
	glColor3ub(228,175,148);
	glVertex2f(0.59f, -0.21f);
	glVertex2f(0.69f, -0.21f);
    glVertex2f(0.69f, -0.23f);
	glVertex2f(0.59f, -0.23f);
	glEnd();

//5
    glBegin(GL_QUADS);
	glColor3ub(228,175,148);
	glVertex2f(0.59f, -0.255f);
	glVertex2f(0.69f, -0.255f);
    glVertex2f(0.69f, -0.30f);
	glVertex2f(0.59f, -0.30f);
	glEnd();



//Building 4

	glBegin(GL_QUADS);
	glColor3ub(24,62,98);

	glVertex2f(0.42f, 0.06f);
	glVertex2f(0.42f, -0.30);

	glVertex2f(0.54f, -0.30f);
	glVertex2f(0.54f, 0.06f);
	glEnd();

//Building 4 Windows


   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(111,245,209);

//Left Side windows
   glVertex2f(0.43f, 0.03f);
   glVertex2f(0.47f, 0.03f);

   glVertex2f(0.43f, -0.02f);
   glVertex2f(0.47f, -0.02f);

   glVertex2f(0.43f, -0.07f);
   glVertex2f(0.47f, -0.07f);

   glVertex2f(0.43f, -0.12f);
   glVertex2f(0.47f, -0.12f);

   glVertex2f(0.43f, -0.17f);
   glVertex2f(0.47f, -0.17f);

   glVertex2f(0.43f, -0.23f);
   glVertex2f(0.47f, -0.23f);


//Right Side Windows
   glVertex2f(0.482f, 0.03f);
   glVertex2f(0.522f, 0.03f);

   glVertex2f(0.482f, -0.02f);
   glVertex2f(0.522f, -0.02f);

   glVertex2f(0.482f, -0.07f);
   glVertex2f(0.522f, -0.07f);

   glVertex2f(0.482f, -0.12f);
   glVertex2f(0.522f, -0.12f);

   glVertex2f(0.482f, -0.17f);
   glVertex2f(0.522f, -0.17f);

   glVertex2f(0.482f, -0.23f);
   glVertex2f(0.522f, -0.23f);


   glEnd();


//Building 5

	glBegin(GL_QUADS);
	glColor3ub(82,107,187);
	glVertex2f(0.27f, 0.24f);
	glVertex2f(0.27f, -0.30);

	glVertex2f(0.38f, -0.30f);
	glVertex2f(0.38f, 0.24f);
	glEnd();

//Building 5 Windows

   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(228,175,148);

//Left Side windows
   glVertex2f(0.3f, 0.22f);
   glVertex2f(0.3f, 0.16f);

   glVertex2f(0.35f, 0.22f);
   glVertex2f(0.35f, 0.16f);

   glVertex2f(0.326f, 0.14f);
   glVertex2f(0.326f, 0.08f);

   glVertex2f(0.3f, 0.054f);
   glVertex2f(0.3f, -0.01f);

   glVertex2f(0.35f, 0.054f);
   glVertex2f(0.35f, -0.01f);

   glVertex2f(0.326f, -0.025f);
   glVertex2f(0.326f, -0.09f);

   glVertex2f(0.3f, -0.112f);
   glVertex2f(0.3f, -0.176f);

   glVertex2f(0.35f, -0.112f);
   glVertex2f(0.35f, -0.176f);

   glVertex2f(0.326f, -0.192f);
   glVertex2f(0.326f, -0.255f);


   glEnd();

}

void NightCity()
{
//From rightmost side

//Building 1
    glBegin(GL_QUADS);
	glColor3ub(23,75,113);
	glVertex2f(0.88f, 0.41f);
	glVertex2f(0.88f, -0.30);
	glVertex2f(1.0f, -0.30f);
	glVertex2f(1.0f, 0.41f);
	glEnd();

//Building 1 Windows
    glLineWidth(25.0);
    glBegin(GL_LINES);
	glColor3ub(244,173,93);
//1
	glVertex2f(0.901f, 0.37f);
	glVertex2f(0.983f, 0.37f);
//2
	glVertex2f(0.901f, 0.32f);
	glVertex2f(0.983f, 0.32f);
//3
	glVertex2f(0.901f, 0.27f);
	glVertex2f(0.983f, 0.27f);
//4
	glVertex2f(0.901f, 0.22f);
	glVertex2f(0.983f, 0.22f);
//5
	glVertex2f(0.901f, 0.17f);
	glVertex2f(0.983f, 0.17f);
//6
	glVertex2f(0.901f, 0.12f);
	glVertex2f(0.983f, 0.12f);
//7
	glVertex2f(0.901f, 0.07f);
	glVertex2f(0.983f, 0.07f);
//8
	glVertex2f(0.901f, 0.02f);
	glVertex2f(0.983f, 0.02f);
//9
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//10
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//11
	glVertex2f(0.901f, -0.08f);
	glVertex2f(0.983f, -0.08f);
//12
	glVertex2f(0.901f, -0.13f);
	glVertex2f(0.983f, -0.13f);
//13
	glVertex2f(0.901f, -0.18f);
	glVertex2f(0.983f, -0.18f);
//14
	glVertex2f(0.901f, -0.23f);
	glVertex2f(0.983f, -0.23f);
    glEnd();

//Building 2

	glBegin(GL_QUADS);
	glColor3ub(64,64,64);
	glVertex2f(0.73f, -0.04f);
	glVertex2f(0.73f, -0.30);

	glVertex2f(0.86f, -0.30f);
	glVertex2f(0.86f, 0.16f);
	glEnd();

//Building 2 Windows

//1
	glBegin(GL_QUADS);
	glColor3ub(232,224,249);
	glVertex2f(0.75f, -0.045f);
	glVertex2f(0.846f, 0.1f);
	glVertex2f(0.846f, 0.058f);
	glVertex2f(0.75f, -0.084f);
	glEnd();

//2
	glBegin(GL_QUADS);
	glColor3ub(232,224,249);
	glVertex2f(0.820f, 0.0f);
	glVertex2f(0.848f,0.042f);
	glVertex2f(0.848f,-0.30f);
    glVertex2f(0.820f,-0.30f);
	glEnd();

//3
	glBegin(GL_QUADS);
	glColor3ub(232,224,249);
	glVertex2f(0.75f, -0.105f);
	glVertex2f(0.78f, -0.064f);
	glVertex2f(0.78f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glEnd();


//Building 3

	glBegin(GL_QUADS);
	glColor3ub(48,57,113);

	glVertex2f(0.58f, -0.03f);
	glVertex2f(0.58f, -0.30);

	glVertex2f(0.70f, -0.30f);
	glVertex2f(0.70f, -0.03f);
	glEnd();

//Building 3 Windows

    glBegin(GL_QUADS);
	glColor3ub(234,181,137);
//1
	glVertex2f(0.59f, -0.05f);
	glVertex2f(0.69f, -0.05f);
    glVertex2f(0.69f, -0.095f);
	glVertex2f(0.59f, -0.095f);
	glEnd();

//2
    glBegin(GL_QUADS);
	glColor3ub(234,181,137);
	glVertex2f(0.59f, -0.114f);
	glVertex2f(0.69f, -0.114f);
    glVertex2f(0.69f, -0.133f);
	glVertex2f(0.59f, -0.133f);
	glEnd();

//3
    glBegin(GL_QUADS);
	glColor3ub(234,181,137);
	glVertex2f(0.59f, -0.145f);
	glVertex2f(0.69f, -0.145f);
    glVertex2f(0.69f, -0.195f);
	glVertex2f(0.59f, -0.195f);
	glEnd();

//4
    glBegin(GL_QUADS);
	glColor3ub(234,181,137);
	glVertex2f(0.59f, -0.21f);
	glVertex2f(0.69f, -0.21f);
    glVertex2f(0.69f, -0.23f);
	glVertex2f(0.59f, -0.23f);
	glEnd();

//5
    glBegin(GL_QUADS);
	glColor3ub(234,181,137);
	glVertex2f(0.59f, -0.255f);
	glVertex2f(0.69f, -0.255f);
    glVertex2f(0.69f, -0.30f);
	glVertex2f(0.59f, -0.30f);
	glEnd();



//Building 4

	glBegin(GL_QUADS);
	glColor3ub(24,62,98);

	glVertex2f(0.42f, 0.06f);
	glVertex2f(0.42f, -0.30);

	glVertex2f(0.54f, -0.30f);
	glVertex2f(0.54f, 0.06f);
	glEnd();

//Building 4 Windows


   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(126,249,210);

//Left Side windows
   glVertex2f(0.43f, 0.03f);
   glVertex2f(0.47f, 0.03f);

   glVertex2f(0.43f, -0.02f);
   glVertex2f(0.47f, -0.02f);

   glVertex2f(0.43f, -0.07f);
   glVertex2f(0.47f, -0.07f);

   glVertex2f(0.43f, -0.12f);
   glVertex2f(0.47f, -0.12f);

   glVertex2f(0.43f, -0.17f);
   glVertex2f(0.47f, -0.17f);

   glVertex2f(0.43f, -0.23f);
   glVertex2f(0.47f, -0.23f);


//Right Side Windows
   glVertex2f(0.482f, 0.03f);
   glVertex2f(0.522f, 0.03f);

   glVertex2f(0.482f, -0.02f);
   glVertex2f(0.522f, -0.02f);

   glVertex2f(0.482f, -0.07f);
   glVertex2f(0.522f, -0.07f);

   glVertex2f(0.482f, -0.12f);
   glVertex2f(0.522f, -0.12f);

   glVertex2f(0.482f, -0.17f);
   glVertex2f(0.522f, -0.17f);

   glVertex2f(0.482f, -0.23f);
   glVertex2f(0.522f, -0.23f);


   glEnd();


//Building 5

	glBegin(GL_QUADS);
	glColor3ub(46,60,105);
	glVertex2f(0.27f, 0.24f);
	glVertex2f(0.27f, -0.30);

	glVertex2f(0.38f, -0.30f);
	glVertex2f(0.38f, 0.24f);
	glEnd();

//Building 5 Windows

   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(229,153,85);

//Left Side windows
   glVertex2f(0.3f, 0.22f);
   glVertex2f(0.3f, 0.16f);

   glVertex2f(0.35f, 0.22f);
   glVertex2f(0.35f, 0.16f);

   glVertex2f(0.326f, 0.14f);
   glVertex2f(0.326f, 0.08f);

   glVertex2f(0.3f, 0.054f);
   glVertex2f(0.3f, -0.01f);

   glVertex2f(0.35f, 0.054f);
   glVertex2f(0.35f, -0.01f);

   glVertex2f(0.326f, -0.025f);
   glVertex2f(0.326f, -0.09f);

   glVertex2f(0.3f, -0.112f);
   glVertex2f(0.3f, -0.176f);

   glVertex2f(0.35f, -0.112f);
   glVertex2f(0.35f, -0.176f);

   glVertex2f(0.326f, -0.192f);
   glVertex2f(0.326f, -0.255f);


   glEnd();

}

void WinterCity()
{
//From rightmost side

//Building 1
    glBegin(GL_QUADS);
	glColor3ub(8,44,70);
	glVertex2f(0.88f, 0.41f);
	glVertex2f(0.88f, -0.30);
	glVertex2f(1.0f, -0.30f);
	glVertex2f(1.0f, 0.41f);
	glEnd();

//Building 1 Windows
    glLineWidth(25.0);
    glBegin(GL_LINES);
	glColor3ub(237,183,166);
//1
	glVertex2f(0.901f, 0.37f);
	glVertex2f(0.983f, 0.37f);
//2
	glVertex2f(0.901f, 0.32f);
	glVertex2f(0.983f, 0.32f);
//3
	glVertex2f(0.901f, 0.27f);
	glVertex2f(0.983f, 0.27f);
//4
	glVertex2f(0.901f, 0.22f);
	glVertex2f(0.983f, 0.22f);
//5
	glVertex2f(0.901f, 0.17f);
	glVertex2f(0.983f, 0.17f);
//6
	glVertex2f(0.901f, 0.12f);
	glVertex2f(0.983f, 0.12f);
//7
	glVertex2f(0.901f, 0.07f);
	glVertex2f(0.983f, 0.07f);
//8
	glVertex2f(0.901f, 0.02f);
	glVertex2f(0.983f, 0.02f);
//9
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//10
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//11
	glVertex2f(0.901f, -0.08f);
	glVertex2f(0.983f, -0.08f);
//12
	glVertex2f(0.901f, -0.13f);
	glVertex2f(0.983f, -0.13f);
//13
	glVertex2f(0.901f, -0.18f);
	glVertex2f(0.983f, -0.18f);
//14
	glVertex2f(0.901f, -0.23f);
	glVertex2f(0.983f, -0.23f);
    glEnd();

//Building 2

	glBegin(GL_QUADS);
	glColor3ub(57,29,77);
	glVertex2f(0.73f, -0.04f);
	glVertex2f(0.73f, -0.30);

	glVertex2f(0.86f, -0.30f);
	glVertex2f(0.86f, 0.16f);
	glEnd();

//Building 2 Windows

//1
	glBegin(GL_QUADS);
	glColor3ub(178,226,210);
	glVertex2f(0.75f, -0.045f);
	glVertex2f(0.846f, 0.1f);
	glVertex2f(0.846f, 0.058f);
	glVertex2f(0.75f, -0.084f);
	glEnd();

//2
	glBegin(GL_QUADS);
	glColor3ub(178,226,210);
	glVertex2f(0.820f, 0.0f);
	glVertex2f(0.848f,0.042f);
	glVertex2f(0.848f,-0.30f);
    glVertex2f(0.820f,-0.30f);
	glEnd();

//3
	glBegin(GL_QUADS);
	glColor3ub(178,226,210);
	glVertex2f(0.75f, -0.105f);
	glVertex2f(0.78f, -0.064f);
	glVertex2f(0.78f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glEnd();


//Building 3

	glBegin(GL_QUADS);
	glColor3ub(41,84,162);

	glVertex2f(0.58f, -0.03f);
	glVertex2f(0.58f, -0.30);

	glVertex2f(0.70f, -0.30f);
	glVertex2f(0.70f, -0.03f);
	glEnd();

//Building 3 Windows

    glBegin(GL_QUADS);
	glColor3ub(61,203,247);
//1
	glVertex2f(0.59f, -0.05f);
	glVertex2f(0.69f, -0.05f);
    glVertex2f(0.69f, -0.095f);
	glVertex2f(0.59f, -0.095f);
	glEnd();

//2
    glBegin(GL_QUADS);
	glColor3ub(61,203,247);
	glVertex2f(0.59f, -0.114f);
	glVertex2f(0.69f, -0.114f);
    glVertex2f(0.69f, -0.133f);
	glVertex2f(0.59f, -0.133f);
	glEnd();

//3
    glBegin(GL_QUADS);
	glColor3ub(61,203,247);
	glVertex2f(0.59f, -0.145f);
	glVertex2f(0.69f, -0.145f);
    glVertex2f(0.69f, -0.195f);
	glVertex2f(0.59f, -0.195f);
	glEnd();

//4
    glBegin(GL_QUADS);
	glColor3ub(61,203,247);
	glVertex2f(0.59f, -0.21f);
	glVertex2f(0.69f, -0.21f);
    glVertex2f(0.69f, -0.23f);
	glVertex2f(0.59f, -0.23f);
	glEnd();

//5
    glBegin(GL_QUADS);
	glColor3ub(61,203,247);
	glVertex2f(0.59f, -0.255f);
	glVertex2f(0.69f, -0.255f);
    glVertex2f(0.69f, -0.30f);
	glVertex2f(0.59f, -0.30f);
	glEnd();



//Building 4

	glBegin(GL_QUADS);
	glColor3ub(151,211,246);

	glVertex2f(0.42f, 0.06f);
	glVertex2f(0.42f, -0.30);

	glVertex2f(0.54f, -0.30f);
	glVertex2f(0.54f, 0.06f);
	glEnd();

//Building 4 Windows


   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(30,80,175);

//Left Side windows
   glVertex2f(0.43f, 0.03f);
   glVertex2f(0.47f, 0.03f);

   glVertex2f(0.43f, -0.02f);
   glVertex2f(0.47f, -0.02f);

   glVertex2f(0.43f, -0.07f);
   glVertex2f(0.47f, -0.07f);

   glVertex2f(0.43f, -0.12f);
   glVertex2f(0.47f, -0.12f);

   glVertex2f(0.43f, -0.17f);
   glVertex2f(0.47f, -0.17f);

   glVertex2f(0.43f, -0.23f);
   glVertex2f(0.47f, -0.23f);


//Right Side Windows
   glVertex2f(0.482f, 0.03f);
   glVertex2f(0.522f, 0.03f);

   glVertex2f(0.482f, -0.02f);
   glVertex2f(0.522f, -0.02f);

   glVertex2f(0.482f, -0.07f);
   glVertex2f(0.522f, -0.07f);

   glVertex2f(0.482f, -0.12f);
   glVertex2f(0.522f, -0.12f);

   glVertex2f(0.482f, -0.17f);
   glVertex2f(0.522f, -0.17f);

   glVertex2f(0.482f, -0.23f);
   glVertex2f(0.522f, -0.23f);


   glEnd();


//Building 5

	glBegin(GL_QUADS);
	glColor3ub(37,81,150);
	glVertex2f(0.27f, 0.24f);
	glVertex2f(0.27f, -0.30);

	glVertex2f(0.38f, -0.30f);
	glVertex2f(0.38f, 0.24f);
	glEnd();

//Building 5 Windows

   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(231,218,159);

//Left Side windows
   glVertex2f(0.3f, 0.22f);
   glVertex2f(0.3f, 0.16f);

   glVertex2f(0.35f, 0.22f);
   glVertex2f(0.35f, 0.16f);

   glVertex2f(0.326f, 0.14f);
   glVertex2f(0.326f, 0.08f);

   glVertex2f(0.3f, 0.054f);
   glVertex2f(0.3f, -0.01f);

   glVertex2f(0.35f, 0.054f);
   glVertex2f(0.35f, -0.01f);

   glVertex2f(0.326f, -0.025f);
   glVertex2f(0.326f, -0.09f);

   glVertex2f(0.3f, -0.112f);
   glVertex2f(0.3f, -0.176f);

   glVertex2f(0.35f, -0.112f);
   glVertex2f(0.35f, -0.176f);

   glVertex2f(0.326f, -0.192f);
   glVertex2f(0.326f, -0.255f);


   glEnd();

}

void SpringCity()
{
//From rightmost side

//Building 1
    glBegin(GL_QUADS);
	glColor3ub(190,112,97);
	glVertex2f(0.88f, 0.41f);
	glColor3ub(169,66,46);
	glVertex2f(0.88f, -0.30);
	glColor3ub(169,66,46);
	glVertex2f(1.0f, -0.30f);
	glColor3ub(190,112,97);
	glVertex2f(1.0f, 0.41f);
	glEnd();

//Building 1 Windows
    glLineWidth(25.0);
    glBegin(GL_LINES);
	glColor3ub(254,198,89);
//1
	glVertex2f(0.901f, 0.37f);
	glVertex2f(0.983f, 0.37f);
//2
	glVertex2f(0.901f, 0.32f);
	glVertex2f(0.983f, 0.32f);
//3
	glVertex2f(0.901f, 0.27f);
	glVertex2f(0.983f, 0.27f);
//4
	glVertex2f(0.901f, 0.22f);
	glVertex2f(0.983f, 0.22f);
//5
	glVertex2f(0.901f, 0.17f);
	glVertex2f(0.983f, 0.17f);
//6
	glVertex2f(0.901f, 0.12f);
	glVertex2f(0.983f, 0.12f);
//7
	glVertex2f(0.901f, 0.07f);
	glVertex2f(0.983f, 0.07f);
//8
	glVertex2f(0.901f, 0.02f);
	glVertex2f(0.983f, 0.02f);
//9
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//10
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//11
	glVertex2f(0.901f, -0.08f);
	glVertex2f(0.983f, -0.08f);
//12
	glVertex2f(0.901f, -0.13f);
	glVertex2f(0.983f, -0.13f);
//13
	glVertex2f(0.901f, -0.18f);
	glVertex2f(0.983f, -0.18f);
//14
	glVertex2f(0.901f, -0.23f);
	glVertex2f(0.983f, -0.23f);
    glEnd();

//Building 2

	glBegin(GL_QUADS);
	glColor3ub(139,79,97);
	glVertex2f(0.73f, -0.04f);
	glColor3ub(126,60,80);
	glVertex2f(0.73f, -0.30);
    glColor3ub(126,60,80);
	glVertex2f(0.86f, -0.30f);
	glColor3ub(139,79,97);
	glVertex2f(0.86f, 0.16f);
	glEnd();

//Building 2 Windows

//1
	glBegin(GL_QUADS);
	glColor3ub(193,225,255);
	glVertex2f(0.75f, -0.045f);
	glVertex2f(0.846f, 0.1f);
	glVertex2f(0.846f, 0.058f);
	glVertex2f(0.75f, -0.084f);
	glEnd();

//2
	glBegin(GL_QUADS);
	glColor3ub(193,225,255);
	glVertex2f(0.820f, 0.0f);
	glVertex2f(0.848f,0.042f);
	glVertex2f(0.848f,-0.30f);
    glVertex2f(0.820f,-0.30f);
	glEnd();

//3
	glBegin(GL_QUADS);
	glColor3ub(193,225,255);
	glVertex2f(0.75f, -0.105f);
	glVertex2f(0.78f, -0.064f);
	glVertex2f(0.78f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glEnd();


//Building 3

	glBegin(GL_QUADS);
    glColor3ub(255,197,94);
	glVertex2f(0.58f, -0.03f);
	glColor3ub(158,75,9);
	glVertex2f(0.58f, -0.30);
    glColor3ub(158,75,9);
	glVertex2f(0.70f, -0.30f);
	glColor3ub(255,197,94);
	glVertex2f(0.70f, -0.03f);
	glEnd();

//Building 3 Windows

    glBegin(GL_QUADS);
	glColor3ub(230,99,59);
//1
	glVertex2f(0.59f, -0.05f);
	glVertex2f(0.69f, -0.05f);
    glVertex2f(0.69f, -0.095f);
	glVertex2f(0.59f, -0.095f);
	glEnd();

//2
    glBegin(GL_QUADS);
	glColor3ub(230,99,59);
	glVertex2f(0.59f, -0.114f);
	glVertex2f(0.69f, -0.114f);
    glVertex2f(0.69f, -0.133f);
	glVertex2f(0.59f, -0.133f);
	glEnd();

//3
    glBegin(GL_QUADS);
	glColor3ub(230,99,59);
	glVertex2f(0.59f, -0.145f);
	glVertex2f(0.69f, -0.145f);
    glVertex2f(0.69f, -0.195f);
	glVertex2f(0.59f, -0.195f);
	glEnd();

//4
    glBegin(GL_QUADS);
	glColor3ub(230,99,59);
	glVertex2f(0.59f, -0.21f);
	glVertex2f(0.69f, -0.21f);
    glVertex2f(0.69f, -0.23f);
	glVertex2f(0.59f, -0.23f);
	glEnd();

//5
    glBegin(GL_QUADS);
	glColor3ub(230,99,59);
	glVertex2f(0.59f, -0.255f);
	glVertex2f(0.69f, -0.255f);
    glVertex2f(0.69f, -0.30f);
	glVertex2f(0.59f, -0.30f);
	glEnd();



//Building 4

	glBegin(GL_QUADS);
	glColor3ub(83,151,240);
	glVertex2f(0.42f, 0.06f);
	glColor3ub(7,81,132);
	glVertex2f(0.42f, -0.30);
	glColor3ub(7,81,132);
	glVertex2f(0.54f, -0.30f);
	glColor3ub(83,151,240);
	glVertex2f(0.54f, 0.06f);
	glEnd();

//Building 4 Windows


   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(209,234,248);

//Left Side windows
   glVertex2f(0.43f, 0.03f);
   glVertex2f(0.47f, 0.03f);

   glVertex2f(0.43f, -0.02f);
   glVertex2f(0.47f, -0.02f);

   glVertex2f(0.43f, -0.07f);
   glVertex2f(0.47f, -0.07f);

   glVertex2f(0.43f, -0.12f);
   glVertex2f(0.47f, -0.12f);

   glVertex2f(0.43f, -0.17f);
   glVertex2f(0.47f, -0.17f);

   glVertex2f(0.43f, -0.23f);
   glVertex2f(0.47f, -0.23f);


//Right Side Windows
   glVertex2f(0.482f, 0.03f);
   glVertex2f(0.522f, 0.03f);

   glVertex2f(0.482f, -0.02f);
   glVertex2f(0.522f, -0.02f);

   glVertex2f(0.482f, -0.07f);
   glVertex2f(0.522f, -0.07f);

   glVertex2f(0.482f, -0.12f);
   glVertex2f(0.522f, -0.12f);

   glVertex2f(0.482f, -0.17f);
   glVertex2f(0.522f, -0.17f);

   glVertex2f(0.482f, -0.23f);
   glVertex2f(0.522f, -0.23f);


   glEnd();


//Building 5

	glBegin(GL_QUADS);
	glColor3ub(117,73,62);
	glVertex2f(0.27f, 0.24f);
	glColor3ub(37,36,67);
	glVertex2f(0.27f, -0.30);
	glColor3ub(37,36,67);
	glVertex2f(0.38f, -0.30f);
	glColor3ub(117,73,62);
	glVertex2f(0.38f, 0.24f);
	glEnd();

//Building 5 Windows

   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(251,231,103);

//Left Side windows
   glVertex2f(0.3f, 0.22f);
   glVertex2f(0.3f, 0.16f);

   glVertex2f(0.35f, 0.22f);
   glVertex2f(0.35f, 0.16f);

   glVertex2f(0.326f, 0.14f);
   glVertex2f(0.326f, 0.08f);

   glVertex2f(0.3f, 0.054f);
   glVertex2f(0.3f, -0.01f);

   glVertex2f(0.35f, 0.054f);
   glVertex2f(0.35f, -0.01f);

   glVertex2f(0.326f, -0.025f);
   glVertex2f(0.326f, -0.09f);

   glVertex2f(0.3f, -0.112f);
   glVertex2f(0.3f, -0.176f);

   glVertex2f(0.35f, -0.112f);
   glVertex2f(0.35f, -0.176f);

   glVertex2f(0.326f, -0.192f);
   glVertex2f(0.326f, -0.255f);


   glEnd();

}

void CityAutumn()
{
//From rightmost side

//Building 1
    glBegin(GL_QUADS);
	glColor3ub(43,97,141);
	glVertex2f(0.88f, 0.41f);
	glVertex2f(0.88f, -0.30);
	glVertex2f(1.0f, -0.30f);
	glVertex2f(1.0f, 0.41f);
	glEnd();

//Building 1 Windows
    glLineWidth(25.0);
    glBegin(GL_LINES);
	glColor3ub(213,213,187);
//1
	glVertex2f(0.901f, 0.37f);
	glVertex2f(0.983f, 0.37f);
//2
	glVertex2f(0.901f, 0.32f);
	glVertex2f(0.983f, 0.32f);
//3
	glVertex2f(0.901f, 0.27f);
	glVertex2f(0.983f, 0.27f);
//4
	glVertex2f(0.901f, 0.22f);
	glVertex2f(0.983f, 0.22f);
//5
	glVertex2f(0.901f, 0.17f);
	glVertex2f(0.983f, 0.17f);
//6
	glVertex2f(0.901f, 0.12f);
	glVertex2f(0.983f, 0.12f);
//7
	glVertex2f(0.901f, 0.07f);
	glVertex2f(0.983f, 0.07f);
//8
	glVertex2f(0.901f, 0.02f);
	glVertex2f(0.983f, 0.02f);
//9
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//10
	glVertex2f(0.901f, -0.03f);
	glVertex2f(0.983f, -0.03f);
//11
	glVertex2f(0.901f, -0.08f);
	glVertex2f(0.983f, -0.08f);
//12
	glVertex2f(0.901f, -0.13f);
	glVertex2f(0.983f, -0.13f);
//13
	glVertex2f(0.901f, -0.18f);
	glVertex2f(0.983f, -0.18f);
//14
	glVertex2f(0.901f, -0.23f);
	glVertex2f(0.983f, -0.23f);
    glEnd();

//Building 2

	glBegin(GL_QUADS);
	glColor3ub(103,111,106);
	glVertex2f(0.73f, -0.04f);
	glVertex2f(0.73f, -0.30);

	glVertex2f(0.86f, -0.30f);
	glVertex2f(0.86f, 0.16f);
	glEnd();

//Building 2 Windows

//1
	glBegin(GL_QUADS);
	glColor3ub(179,200,192);
	glVertex2f(0.75f, -0.045f);
	glVertex2f(0.846f, 0.1f);
	glVertex2f(0.846f, 0.058f);
	glVertex2f(0.75f, -0.084f);
	glEnd();

//2
	glBegin(GL_QUADS);
	glColor3ub(179,200,192);
	glVertex2f(0.820f, 0.0f);
	glVertex2f(0.848f,0.042f);
	glVertex2f(0.848f,-0.30f);
    glVertex2f(0.820f,-0.30f);
	glEnd();

//3
	glBegin(GL_QUADS);
	glColor3ub(179,200,192);
	glVertex2f(0.75f, -0.105f);
	glVertex2f(0.78f, -0.064f);
	glVertex2f(0.78f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glEnd();


//Building 3

	glBegin(GL_QUADS);
	glColor3ub(78,75,103);

	glVertex2f(0.58f, -0.03f);
	glVertex2f(0.58f, -0.30);

	glVertex2f(0.70f, -0.30f);
	glVertex2f(0.70f, -0.03f);
	glEnd();

//Building 3 Windows

    glBegin(GL_QUADS);
	glColor3ub(252,135,39);
//1
	glVertex2f(0.59f, -0.05f);
	glVertex2f(0.69f, -0.05f);
    glVertex2f(0.69f, -0.095f);
	glVertex2f(0.59f, -0.095f);
	glEnd();

//2
    glBegin(GL_QUADS);
	glColor3ub(252,135,39);
	glVertex2f(0.59f, -0.114f);
	glVertex2f(0.69f, -0.114f);
    glVertex2f(0.69f, -0.133f);
	glVertex2f(0.59f, -0.133f);
	glEnd();

//3
    glBegin(GL_QUADS);
	glColor3ub(252,135,39);
	glVertex2f(0.59f, -0.145f);
	glVertex2f(0.69f, -0.145f);
    glVertex2f(0.69f, -0.195f);
	glVertex2f(0.59f, -0.195f);
	glEnd();

//4
    glBegin(GL_QUADS);
	glColor3ub(252,135,39);
	glVertex2f(0.59f, -0.21f);
	glVertex2f(0.69f, -0.21f);
    glVertex2f(0.69f, -0.23f);
	glVertex2f(0.59f, -0.23f);
	glEnd();

//5
    glBegin(GL_QUADS);
	glColor3ub(252,135,39);
	glVertex2f(0.59f, -0.255f);
	glVertex2f(0.69f, -0.255f);
    glVertex2f(0.69f, -0.30f);
	glVertex2f(0.59f, -0.30f);
	glEnd();



//Building 4

	glBegin(GL_QUADS);
	glColor3ub(33,83,173);

	glVertex2f(0.42f, 0.06f);
	glVertex2f(0.42f, -0.30);

	glVertex2f(0.54f, -0.30f);
	glVertex2f(0.54f, 0.06f);
	glEnd();

//Building 4 Windows


   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(139,201,211);

//Left Side windows
   glVertex2f(0.43f, 0.03f);
   glVertex2f(0.47f, 0.03f);

   glVertex2f(0.43f, -0.02f);
   glVertex2f(0.47f, -0.02f);

   glVertex2f(0.43f, -0.07f);
   glVertex2f(0.47f, -0.07f);

   glVertex2f(0.43f, -0.12f);
   glVertex2f(0.47f, -0.12f);

   glVertex2f(0.43f, -0.17f);
   glVertex2f(0.47f, -0.17f);

   glVertex2f(0.43f, -0.23f);
   glVertex2f(0.47f, -0.23f);


//Right Side Windows
   glVertex2f(0.482f, 0.03f);
   glVertex2f(0.522f, 0.03f);

   glVertex2f(0.482f, -0.02f);
   glVertex2f(0.522f, -0.02f);

   glVertex2f(0.482f, -0.07f);
   glVertex2f(0.522f, -0.07f);

   glVertex2f(0.482f, -0.12f);
   glVertex2f(0.522f, -0.12f);

   glVertex2f(0.482f, -0.17f);
   glVertex2f(0.522f, -0.17f);

   glVertex2f(0.482f, -0.23f);
   glVertex2f(0.522f, -0.23f);


   glEnd();


//Building 5

	glBegin(GL_QUADS);
	glColor3ub(92,83,158);
	glVertex2f(0.27f, 0.24f);
	glVertex2f(0.27f, -0.30);

	glVertex2f(0.38f, -0.30f);
	glVertex2f(0.38f, 0.24f);
	glEnd();

//Building 5 Windows

   glLineWidth(25.0);
   glBegin(GL_LINES);
   glColor3ub(248,221,140);

//Left Side windows
   glVertex2f(0.3f, 0.22f);
   glVertex2f(0.3f, 0.16f);

   glVertex2f(0.35f, 0.22f);
   glVertex2f(0.35f, 0.16f);

   glVertex2f(0.326f, 0.14f);
   glVertex2f(0.326f, 0.08f);

   glVertex2f(0.3f, 0.054f);
   glVertex2f(0.3f, -0.01f);

   glVertex2f(0.35f, 0.054f);
   glVertex2f(0.35f, -0.01f);

   glVertex2f(0.326f, -0.025f);
   glVertex2f(0.326f, -0.09f);

   glVertex2f(0.3f, -0.112f);
   glVertex2f(0.3f, -0.176f);

   glVertex2f(0.35f, -0.112f);
   glVertex2f(0.35f, -0.176f);

   glVertex2f(0.326f, -0.192f);
   glVertex2f(0.326f, -0.255f);


   glEnd();

}

void Land()
{
   glBegin(GL_POLYGON);
   glColor3ub(44,116,76); // Dark Green
   glVertex2f(0.24f,-0.30f);
   glVertex2f(0.52f,-0.40f);
   glVertex2f(0.68f,-0.56f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(1.0f,-0.30f);
   glEnd();
//Road
   glBegin(GL_QUADS);
   glColor3ub(121,121,121); // Dark Green
   glVertex2f(0.42f,-0.30f);
   glVertex2f(0.76f,-0.44f);
   glVertex2f(0.76f,-0.34f);
   glVertex2f(0.54f,-0.30f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(121,121,121); // Dark Green
   glVertex2f(0.76f,-0.44f);
   glVertex2f(1.0f,-0.47f);
   glVertex2f(1.0f,-0.35f);
   glVertex2f(0.76f,-0.34f);
   glEnd();

   glLineWidth(2.0);
   glBegin(GL_LINES);
   glColor3ub(255,255,255);

   glVertex2f(0.485f, -0.300f);
   glVertex2f(0.760f, -0.385f);

   glVertex2f(0.760f, -0.385f);
   glVertex2f(1.000f, -0.403f);
   glEnd();

}

void WinterLand()
{
   glBegin(GL_POLYGON);
   glColor3ub(198,231,255);
   glVertex2f(0.24f,-0.30f);
   glVertex2f(0.52f,-0.40f);
   glVertex2f(0.68f,-0.56f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(1.0f,-0.30f);
   glEnd();
//Road
   glBegin(GL_QUADS);
   glColor3ub(107,183,243);
   glVertex2f(0.42f,-0.30f);
   glVertex2f(0.76f,-0.44f);
   glVertex2f(0.76f,-0.34f);
   glVertex2f(0.54f,-0.30f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(107,183,243);
   glVertex2f(0.76f,-0.44f);
   glVertex2f(1.0f,-0.47f);
   glVertex2f(1.0f,-0.35f);
   glVertex2f(0.76f,-0.34f);
   glEnd();

   glLineWidth(2.0);
   glBegin(GL_LINES);
   glColor3ub(255,255,255);

   glVertex2f(0.485f, -0.300f);
   glVertex2f(0.760f, -0.385f);

   glVertex2f(0.760f, -0.385f);
   glVertex2f(1.000f, -0.403f);
   glEnd();

}

void SpringLand()
{
   glBegin(GL_POLYGON);
   glColor3ub(217,210,8);
   glVertex2f(0.24f,-0.30f);
   glColor3ub(217,210,8);
   glVertex2f(0.52f,-0.40f);
   glColor3ub(125,98,116);
   glVertex2f(0.68f,-0.56f);
   glColor3ub(125,98,116);
   glVertex2f(1.0f,-0.65f);
   glColor3ub(217,210,8);
   glVertex2f(1.0f,-0.30f);
   glEnd();
//Road
   glBegin(GL_QUADS);
   glColor3ub(113,113,113);
   glVertex2f(0.42f,-0.30f);
   glVertex2f(0.76f,-0.44f);
   glVertex2f(0.76f,-0.34f);
   glVertex2f(0.54f,-0.30f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(113,113,113);
   glVertex2f(0.76f,-0.44f);
   glVertex2f(1.0f,-0.47f);
   glVertex2f(1.0f,-0.35f);
   glVertex2f(0.76f,-0.34f);
   glEnd();

   glLineWidth(2.0);
   glBegin(GL_LINES);
   glColor3ub(255,255,255);

   glVertex2f(0.485f, -0.300f);
   glVertex2f(0.760f, -0.385f);

   glVertex2f(0.760f, -0.385f);
   glVertex2f(1.000f, -0.403f);
   glEnd();

}

void LandAutumn()
{
   glBegin(GL_POLYGON);
   glColor3ub(65,152,48); // Dark Green
   glVertex2f(0.24f,-0.30f);
   glVertex2f(0.52f,-0.40f);
   glVertex2f(0.68f,-0.56f);
   glVertex2f(1.0f,-0.65f);
   glVertex2f(1.0f,-0.30f);
   glEnd();
//Road
   glBegin(GL_QUADS);
   glColor3ub(133,131,131); // Dark Green
   glVertex2f(0.42f,-0.30f);
   glVertex2f(0.76f,-0.44f);
   glVertex2f(0.76f,-0.34f);
   glVertex2f(0.54f,-0.30f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(133,131,131); // Dark Green
   glVertex2f(0.76f,-0.44f);
   glVertex2f(1.0f,-0.47f);
   glVertex2f(1.0f,-0.35f);
   glVertex2f(0.76f,-0.34f);
   glEnd();

   glLineWidth(2.0);
   glBegin(GL_LINES);
   glColor3ub(255,255,255);

   glVertex2f(0.485f, -0.300f);
   glVertex2f(0.760f, -0.385f);

   glVertex2f(0.760f, -0.385f);
   glVertex2f(1.000f, -0.403f);
   glEnd();

}

void Bridge()
{
//Bridge Road
    glBegin(GL_QUADS);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(-1.0f, -0.135f);
	glVertex2f(1.0f, -0.135f);
	glVertex2f(1.0f, -0.184f);
	glVertex2f(-1.0f,-0.184f);
	glEnd();


//Bridge Top beams
	glBegin(GL_QUADS);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(-0.80f, -0.135f);
	glVertex2f(-0.40f, -0.135f);
	glVertex2f(-0.40f, -0.255f);
	glVertex2f(-0.80f, -0.255f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(0.80f, -0.135f);
	glVertex2f(0.40f, -0.135f);
	glVertex2f(0.40f, -0.255f);
	glVertex2f(0.80f, -0.255f);
	glEnd();

//Bridge Pillars
	glBegin(GL_QUADS);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(-0.68f, -0.255f);
	glVertex2f(-0.55f, -0.255f);
	glVertex2f(-0.55f, -0.735f);
	glVertex2f(-0.68f, -0.735f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(0.68f, -0.255f);
	glVertex2f(0.55f, -0.255f);
	glVertex2f(0.55f, -0.735f);
	glVertex2f(0.68f, -0.735f);
	glEnd();

//Railing

    glBegin(GL_LINES);
	glLineWidth(5.0);
	glColor3f(0.8f,0.8f,0.8f);
	glVertex2f(-1.0f, -0.0567f);
	glVertex2f(1.0f, -0.0567f);
	glEnd();

    glBegin(GL_LINES);
	glLineWidth(5.0);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(-0.97f, -0.14f);
	glVertex2f(-0.97f, -0.0567f);

	glVertex2f(-0.87f, -0.14f);
	glVertex2f(-0.87f, -0.0567f);

	glVertex2f(-0.77f, -0.14f);
	glVertex2f(-0.77f, -0.0567f);

	glVertex2f(-0.67f, -0.14f);
	glVertex2f(-0.67f, -0.0567f);

	glVertex2f(-0.57f, -0.14f);
	glVertex2f(-0.57f, -0.0567f);

	glVertex2f(-0.47f, -0.14f);
	glVertex2f(-0.47f, -0.0567f);

	glVertex2f(-0.37f, -0.14f);
	glVertex2f(-0.37f, -0.0567f);

	glVertex2f(-0.27f, -0.14f);
	glVertex2f(-0.27f, -0.0567f);

	glVertex2f(-0.17f, -0.14f);
	glVertex2f(-0.17f, -0.0567f);

	glVertex2f(-0.07f, -0.14f);
	glVertex2f(-0.07f, -0.0567f);

	glVertex2f(0.03f, -0.14f);
	glVertex2f(0.03f, -0.0567f);

	glVertex2f(0.13f, -0.14f);
	glVertex2f(0.13f, -0.0567f);

	glVertex2f(0.23f, -0.14f);
	glVertex2f(0.23f, -0.0567f);

	glVertex2f(0.33f, -0.14f);
	glVertex2f(0.33f, -0.0567f);

	glVertex2f(0.43f, -0.14f);
	glVertex2f(0.43f, -0.0567f);

	glVertex2f(0.53f, -0.14f);
	glVertex2f(0.53f, -0.0567f);

	glVertex2f(0.63f, -0.14f);
	glVertex2f(0.63f, -0.0567f);

	glVertex2f(0.73f, -0.14f);
	glVertex2f(0.73f, -0.0567f);

	glVertex2f(0.83f, -0.14f);
	glVertex2f(0.83f, -0.0567f);

	glVertex2f(0.93f, -0.14f);
	glVertex2f(0.93f, -0.0567f);


	glEnd();

}

void WinterBridge()
{
//Bridge Road
    glBegin(GL_QUADS);
	glColor3ub(178,212,248);

	glVertex2f(-1.0f, -0.135f);
	glVertex2f(1.0f, -0.135f);
	glVertex2f(1.0f, -0.184f);
	glVertex2f(-1.0f,-0.184f);
	glEnd();


//Bridge Top beams
	glBegin(GL_QUADS);
	glColor3ub(178,212,248);

	glVertex2f(-0.80f, -0.135f);
	glVertex2f(-0.40f, -0.135f);
	glVertex2f(-0.40f, -0.255f);
	glVertex2f(-0.80f, -0.255f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(178,212,248);

	glVertex2f(0.80f, -0.135f);
	glVertex2f(0.40f, -0.135f);
	glVertex2f(0.40f, -0.255f);
	glVertex2f(0.80f, -0.255f);
	glEnd();

//Bridge Pillars
	glBegin(GL_QUADS);
	glColor3ub(187,221,255);
	glVertex2f(-0.68f, -0.255f);
	glColor3ub(187,221,255);
	glVertex2f(-0.55f, -0.255f);
	glColor3ub(37,81,150);
	glVertex2f(-0.55f, -0.735f);
	glColor3ub(37,81,150);
	glVertex2f(-0.68f, -0.735f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(187,221,255);
	glVertex2f(0.68f, -0.255f);
	glColor3ub(187,221,255);
	glVertex2f(0.55f, -0.255f);
	glColor3ub(37,81,150);
	glVertex2f(0.55f, -0.735f);
	glColor3ub(37,81,150);
	glVertex2f(0.68f, -0.735f);
	glEnd();

//Railing

    glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(212,239,255);
	glVertex2f(-1.0f, -0.0567f);
	glVertex2f(1.0f, -0.0567f);
	glEnd();

	glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(212,239,255);

	glVertex2f(-0.97f, -0.14f);
	glVertex2f(-0.97f, -0.0567f);

	glVertex2f(-0.87f, -0.14f);
	glVertex2f(-0.87f, -0.0567f);

	glVertex2f(-0.77f, -0.14f);
	glVertex2f(-0.77f, -0.0567f);

	glVertex2f(-0.67f, -0.14f);
	glVertex2f(-0.67f, -0.0567f);

	glVertex2f(-0.57f, -0.14f);
	glVertex2f(-0.57f, -0.0567f);

	glVertex2f(-0.47f, -0.14f);
	glVertex2f(-0.47f, -0.0567f);

	glVertex2f(-0.37f, -0.14f);
	glVertex2f(-0.37f, -0.0567f);

	glVertex2f(-0.27f, -0.14f);
	glVertex2f(-0.27f, -0.0567f);

	glVertex2f(-0.17f, -0.14f);
	glVertex2f(-0.17f, -0.0567f);

	glVertex2f(-0.07f, -0.14f);
	glVertex2f(-0.07f, -0.0567f);

	glVertex2f(0.03f, -0.14f);
	glVertex2f(0.03f, -0.0567f);

	glVertex2f(0.13f, -0.14f);
	glVertex2f(0.13f, -0.0567f);

	glVertex2f(0.23f, -0.14f);
	glVertex2f(0.23f, -0.0567f);

	glVertex2f(0.33f, -0.14f);
	glVertex2f(0.33f, -0.0567f);

	glVertex2f(0.43f, -0.14f);
	glVertex2f(0.43f, -0.0567f);

	glVertex2f(0.53f, -0.14f);
	glVertex2f(0.53f, -0.0567f);

	glVertex2f(0.63f, -0.14f);
	glVertex2f(0.63f, -0.0567f);

	glVertex2f(0.73f, -0.14f);
	glVertex2f(0.73f, -0.0567f);

	glVertex2f(0.83f, -0.14f);
	glVertex2f(0.83f, -0.0567f);

	glVertex2f(0.93f, -0.14f);
	glVertex2f(0.93f, -0.0567f);


	glEnd();

}

void SpringBridge()
{
//Bridge Road
    glBegin(GL_QUADS);
	glColor3ub(228,201,183);
	glVertex2f(-1.0f, -0.135f);
	glVertex2f(1.0f, -0.135f);
	glVertex2f(1.0f, -0.184f);
	glVertex2f(-1.0f,-0.184f);
	glEnd();


//Bridge Top beams
	glBegin(GL_QUADS);
	glColor3ub(228,201,183);
	glVertex2f(-0.80f, -0.135f);
	glVertex2f(-0.40f, -0.135f);
	glVertex2f(-0.40f, -0.255f);
	glVertex2f(-0.80f, -0.255f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(228,201,183);
	glVertex2f(0.80f, -0.135f);
	glVertex2f(0.40f, -0.135f);
	glVertex2f(0.40f, -0.255f);
	glVertex2f(0.80f, -0.255f);
	glEnd();

//Bridge Pillars
	glBegin(GL_QUADS);
	glColor3ub(228,201,183);
	glVertex2f(-0.68f, -0.255f);
	glColor3ub(228,201,183);
	glVertex2f(-0.55f, -0.255f);
	glColor3ub(95,75,63);
	glVertex2f(-0.55f, -0.735f);
	glColor3ub(95,75,63);
	glVertex2f(-0.68f, -0.735f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(228,201,183);
	glVertex2f(0.68f, -0.255f);
	glColor3ub(228,201,183);
	glVertex2f(0.55f, -0.255f);
	glColor3ub(95,75,63);
	glVertex2f(0.55f, -0.735f);
	glColor3ub(95,75,63);
	glVertex2f(0.68f, -0.735f);
	glEnd();

//Railing

    glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(163,134,119);
	glVertex2f(-1.0f, -0.0567f);
	glVertex2f(1.0f, -0.0567f);
	glEnd();

	glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(212,239,255);

	glVertex2f(-0.97f, -0.14f);
	glVertex2f(-0.97f, -0.0567f);

	glVertex2f(-0.87f, -0.14f);
	glVertex2f(-0.87f, -0.0567f);

	glVertex2f(-0.77f, -0.14f);
	glVertex2f(-0.77f, -0.0567f);

	glVertex2f(-0.67f, -0.14f);
	glVertex2f(-0.67f, -0.0567f);

	glVertex2f(-0.57f, -0.14f);
	glVertex2f(-0.57f, -0.0567f);

	glVertex2f(-0.47f, -0.14f);
	glVertex2f(-0.47f, -0.0567f);

	glVertex2f(-0.37f, -0.14f);
	glVertex2f(-0.37f, -0.0567f);

	glVertex2f(-0.27f, -0.14f);
	glVertex2f(-0.27f, -0.0567f);

	glVertex2f(-0.17f, -0.14f);
	glVertex2f(-0.17f, -0.0567f);

	glVertex2f(-0.07f, -0.14f);
	glVertex2f(-0.07f, -0.0567f);

	glVertex2f(0.03f, -0.14f);
	glVertex2f(0.03f, -0.0567f);

	glVertex2f(0.13f, -0.14f);
	glVertex2f(0.13f, -0.0567f);

	glVertex2f(0.23f, -0.14f);
	glVertex2f(0.23f, -0.0567f);

	glVertex2f(0.33f, -0.14f);
	glVertex2f(0.33f, -0.0567f);

	glVertex2f(0.43f, -0.14f);
	glVertex2f(0.43f, -0.0567f);

	glVertex2f(0.53f, -0.14f);
	glVertex2f(0.53f, -0.0567f);

	glVertex2f(0.63f, -0.14f);
	glVertex2f(0.63f, -0.0567f);

	glVertex2f(0.73f, -0.14f);
	glVertex2f(0.73f, -0.0567f);

	glVertex2f(0.83f, -0.14f);
	glVertex2f(0.83f, -0.0567f);

	glVertex2f(0.93f, -0.14f);
	glVertex2f(0.93f, -0.0567f);


	glEnd();

}

void BridgeAutumn()
{
//Bridge Road
    glBegin(GL_QUADS);
	glColor3ub(155,155,155);

	glVertex2f(-1.0f, -0.135f);
	glVertex2f(1.0f, -0.135f);
	glVertex2f(1.0f, -0.184f);
	glVertex2f(-1.0f,-0.184f);
	glEnd();


//Bridge Top beams
	glBegin(GL_QUADS);
	glColor3ub(155,155,155);

	glVertex2f(-0.80f, -0.135f);
	glVertex2f(-0.40f, -0.135f);
	glVertex2f(-0.40f, -0.255f);
	glVertex2f(-0.80f, -0.255f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(155,155,155);

	glVertex2f(0.80f, -0.135f);
	glVertex2f(0.40f, -0.135f);
	glVertex2f(0.40f, -0.255f);
	glVertex2f(0.80f, -0.255f);
	glEnd();

//Bridge Pillars
	glBegin(GL_QUADS);
	glColor3ub(155,155,155);

	glVertex2f(-0.68f, -0.255f);
	glVertex2f(-0.55f, -0.255f);
	glVertex2f(-0.55f, -0.735f);
	glVertex2f(-0.68f, -0.735f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(155,155,155);

	glVertex2f(0.68f, -0.255f);
	glVertex2f(0.55f, -0.255f);
	glVertex2f(0.55f, -0.735f);
	glVertex2f(0.68f, -0.735f);
	glEnd();

//Railing

    glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-1.0f, -0.0567f);
	glVertex2f(1.0f, -0.0567f);
	glEnd();

	glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(255,255,255);

	glVertex2f(-0.97f, -0.14f);
	glVertex2f(-0.97f, -0.0567f);

	glVertex2f(-0.87f, -0.14f);
	glVertex2f(-0.87f, -0.0567f);

	glVertex2f(-0.77f, -0.14f);
	glVertex2f(-0.77f, -0.0567f);

	glVertex2f(-0.67f, -0.14f);
	glVertex2f(-0.67f, -0.0567f);

	glVertex2f(-0.57f, -0.14f);
	glVertex2f(-0.57f, -0.0567f);

	glVertex2f(-0.47f, -0.14f);
	glVertex2f(-0.47f, -0.0567f);

	glVertex2f(-0.37f, -0.14f);
	glVertex2f(-0.37f, -0.0567f);

	glVertex2f(-0.27f, -0.14f);
	glVertex2f(-0.27f, -0.0567f);

	glVertex2f(-0.17f, -0.14f);
	glVertex2f(-0.17f, -0.0567f);

	glVertex2f(-0.07f, -0.14f);
	glVertex2f(-0.07f, -0.0567f);

	glVertex2f(0.03f, -0.14f);
	glVertex2f(0.03f, -0.0567f);

	glVertex2f(0.13f, -0.14f);
	glVertex2f(0.13f, -0.0567f);

	glVertex2f(0.23f, -0.14f);
	glVertex2f(0.23f, -0.0567f);

	glVertex2f(0.33f, -0.14f);
	glVertex2f(0.33f, -0.0567f);

	glVertex2f(0.43f, -0.14f);
	glVertex2f(0.43f, -0.0567f);

	glVertex2f(0.53f, -0.14f);
	glVertex2f(0.53f, -0.0567f);

	glVertex2f(0.63f, -0.14f);
	glVertex2f(0.63f, -0.0567f);

	glVertex2f(0.73f, -0.14f);
	glVertex2f(0.73f, -0.0567f);

	glVertex2f(0.83f, -0.14f);
	glVertex2f(0.83f, -0.0567f);

	glVertex2f(0.93f, -0.14f);
	glVertex2f(0.93f, -0.0567f);


	glEnd();

}

void NightBridge()
{
//Bridge Road
    glBegin(GL_QUADS);
	glColor3ub(86,86,86);

	glVertex2f(-1.0f, -0.135f);
	glVertex2f(1.0f, -0.135f);
	glVertex2f(1.0f, -0.184f);
	glVertex2f(-1.0f,-0.184f);
	glEnd();


//Bridge Top beams
	glBegin(GL_QUADS);
	glColor3ub(86,86,86);

	glVertex2f(-0.80f, -0.135f);
	glVertex2f(-0.40f, -0.135f);
	glVertex2f(-0.40f, -0.255f);
	glVertex2f(-0.80f, -0.255f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(86,86,86);

	glVertex2f(0.80f, -0.135f);
	glVertex2f(0.40f, -0.135f);
	glVertex2f(0.40f, -0.255f);
	glVertex2f(0.80f, -0.255f);
	glEnd();

//Bridge Pillars
	glBegin(GL_QUADS);
	glColor3ub(86,86,86);

	glVertex2f(-0.68f, -0.255f);
	glVertex2f(-0.55f, -0.255f);
	glVertex2f(-0.55f, -0.735f);
	glVertex2f(-0.68f, -0.735f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(86,86,86);

	glVertex2f(0.68f, -0.255f);
	glVertex2f(0.55f, -0.255f);
	glVertex2f(0.55f, -0.735f);
	glVertex2f(0.68f, -0.735f);
	glEnd();

//Railing

    glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3ub(86,86,86);
	glVertex2f(-1.0f, -0.0567f);
	glVertex2f(1.0f, -0.0567f);
	glEnd();

	glLineWidth(5.0);
    glBegin(GL_LINES);
	glColor3f(0.8f,0.8f,0.8f);

	glVertex2f(-0.97f, -0.14f);
	glVertex2f(-0.97f, -0.0567f);

	glVertex2f(-0.87f, -0.14f);
	glVertex2f(-0.87f, -0.0567f);

	glVertex2f(-0.77f, -0.14f);
	glVertex2f(-0.77f, -0.0567f);

	glVertex2f(-0.67f, -0.14f);
	glVertex2f(-0.67f, -0.0567f);

	glVertex2f(-0.57f, -0.14f);
	glVertex2f(-0.57f, -0.0567f);

	glVertex2f(-0.47f, -0.14f);
	glVertex2f(-0.47f, -0.0567f);

	glVertex2f(-0.37f, -0.14f);
	glVertex2f(-0.37f, -0.0567f);

	glVertex2f(-0.27f, -0.14f);
	glVertex2f(-0.27f, -0.0567f);

	glVertex2f(-0.17f, -0.14f);
	glVertex2f(-0.17f, -0.0567f);

	glVertex2f(-0.07f, -0.14f);
	glVertex2f(-0.07f, -0.0567f);

	glVertex2f(0.03f, -0.14f);
	glVertex2f(0.03f, -0.0567f);

	glVertex2f(0.13f, -0.14f);
	glVertex2f(0.13f, -0.0567f);

	glVertex2f(0.23f, -0.14f);
	glVertex2f(0.23f, -0.0567f);

	glVertex2f(0.33f, -0.14f);
	glVertex2f(0.33f, -0.0567f);

	glVertex2f(0.43f, -0.14f);
	glVertex2f(0.43f, -0.0567f);

	glVertex2f(0.53f, -0.14f);
	glVertex2f(0.53f, -0.0567f);

	glVertex2f(0.63f, -0.14f);
	glVertex2f(0.63f, -0.0567f);

	glVertex2f(0.73f, -0.14f);
	glVertex2f(0.73f, -0.0567f);

	glVertex2f(0.83f, -0.14f);
	glVertex2f(0.83f, -0.0567f);

	glVertex2f(0.93f, -0.14f);
	glVertex2f(0.93f, -0.0567f);


	glEnd();

}

void NightLamppost()
{

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3ub(88,88,88);
	glVertex2f(-0.92f, -0.14f);
	glVertex2f(-0.93f, -0.14f);
	glVertex2f(-0.93f, 0.11f);
	glVertex2f(-0.92f, 0.11f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(88,88,88);
	glVertex2f(-0.92f, 0.11f);
	glVertex2f(-0.892f, 0.11f);
	glVertex2f(-0.892f, 0.098f);
	glVertex2f(-0.92f, 0.098f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230,252,121);
	glVertex2f(-0.892f, 0.098f);
	glVertex2f(-0.892f, 0.084f);
	glVertex2f(-0.92f, 0.084f);
	glVertex2f(-0.92f, 0.098f);
	glEnd();

//light

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor4ub(230,252,121,50);
	glVertex2f(-0.892f, 0.084f);
	glVertex2f(-0.845f, -0.08f);
	glVertex2f(-0.96f, -0.08f);
	glVertex2f(-0.92f, 0.084f);
	glEnd();

	glPopMatrix();

}

void Lamppost()
{

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3ub(88,88,88);
	glVertex2f(-0.92f, -0.14f);
	glVertex2f(-0.93f, -0.14f);
	glVertex2f(-0.93f, 0.11f);
	glVertex2f(-0.92f, 0.11f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(88,88,88);
	glVertex2f(-0.92f, 0.11f);
	glVertex2f(-0.892f, 0.11f);
	glVertex2f(-0.892f, 0.098f);
	glVertex2f(-0.92f, 0.098f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230,252,121);
	glVertex2f(-0.892f, 0.098f);
	glVertex2f(-0.892f, 0.084f);
	glVertex2f(-0.92f, 0.084f);
	glVertex2f(-0.92f, 0.098f);
	glEnd();
	glPopMatrix();

}

void LamppostTranslate()
{
    glPushMatrix();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	Lamppost();
	glPopMatrix();

}

void NightLamppostTranslate()
{
    glPushMatrix();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glTranslatef(0.185f,0.0f,0.0f);
	NightLamppost();
	glPopMatrix();

}

void Car()
{

	glPushMatrix();
	glTranslatef(-pos_car,0.0f, 0.0f);

//Upper part and window

	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);

	glVertex2f(-0.594f, -0.022f);
	glVertex2f(-0.546f, -0.022f);
	glVertex2f(-0.500f, -0.068f);
	glVertex2f(-0.594f, -0.068f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(52,52,52);

	glVertex2f(-0.582f, -0.032f);
	glVertex2f(-0.552f, -0.032f);
	glVertex2f(-0.524f, -0.060f);
	glVertex2f(-0.582f, -0.060f);
	glEnd();

//Lower part and Decal

	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);

	glVertex2f(-0.685f, -0.068f);
	glVertex2f(-0.500f, -0.068f);
	glVertex2f(-0.500f, -0.098f);
	glVertex2f(-0.685f, -0.098f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(63,61,186);

	glVertex2f(-0.672f, -0.074f);
	glVertex2f(-0.514f, -0.074f);
	glVertex2f(-0.514f, -0.093f);
	glVertex2f(-0.672f, -0.093f);
	glEnd();
//Wheels


    glColor3ub(77,77,77);
	Circle(-0.649f, -0.114f, 0.022f, 20);
	Circle(-0.537f, -0.114f, 0.022f, 20);
	glColor3ub(255,255,255);
	Circle(-0.649f, -0.114f, 0.012f, 20);
	Circle(-0.537f, -0.114f, 0.012f, 20);

	glPopMatrix();
//	glEnd();


}

void NightCar()
{

	glPushMatrix();
	glTranslatef(-pos_car,0.0f, 0.0f);

//Upper part and window

	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);

	glVertex2f(-0.594f, -0.022f);
	glVertex2f(-0.546f, -0.022f);
	glVertex2f(-0.500f, -0.068f);
	glVertex2f(-0.594f, -0.068f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(52,52,52);

	glVertex2f(-0.582f, -0.032f);
	glVertex2f(-0.552f, -0.032f);
	glVertex2f(-0.524f, -0.060f);
	glVertex2f(-0.582f, -0.060f);
	glEnd();

//Lower part and Decal

	glBegin(GL_QUADS);
	glColor3ub(249, 244, 254);

	glVertex2f(-0.685f, -0.068f);
	glVertex2f(-0.500f, -0.068f);
	glVertex2f(-0.500f, -0.098f);
	glVertex2f(-0.685f, -0.098f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(63,61,186);

	glVertex2f(-0.672f, -0.074f);
	glVertex2f(-0.514f, -0.074f);
	glVertex2f(-0.514f, -0.093f);
	glVertex2f(-0.672f, -0.093f);
	glEnd();
//Wheels


    glColor3ub(77,77,77);
	Circle(-0.649f, -0.114f, 0.022f, 20);
	Circle(-0.537f, -0.114f, 0.022f, 20);
	glColor3ub(255,255,255);
	Circle(-0.649f, -0.114f, 0.012f, 20);
	Circle(-0.537f, -0.114f, 0.012f, 20);

//light
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor4ub(230,252,121,50);
	glVertex2f(-0.500f, -0.068f);
	glVertex2f(-0.38f, -0.045f);
	glVertex2f(-0.38f, -0.124f);
	glVertex2f(-0.500f, -0.098f);
	glEnd();

	glPopMatrix();
//	glEnd();


}

void Plane()
{
    glPushMatrix();
	glTranslatef(-pos_plane,-pos_plane, 0.0f);

//Main Body
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-0.966f, 0.1980f);
	glVertex2f(-0.956f, 0.2308f);
	glVertex2f(-0.878f, 0.2840f);
	glVertex2f(-0.848f, 0.2680f);
	glEnd();

//Left Wing
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-0.928f, 0.250f);
	glVertex2f(-0.972f, 0.282f);
	glVertex2f(-0.944f, 0.298f);
	glVertex2f(-0.902f, 0.266f);
	glEnd();

//Right Wing
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-0.920f, 0.226f);
	glVertex2f(-0.892f, 0.242f);
	glVertex2f(-0.892f, 0.190f);
	glVertex2f(-0.920f, 0.164f);
	glEnd();

//Tail
	glBegin(GL_TRIANGLES);
	glColor3ub(255,255,255);
	glVertex2f(-0.966f, 0.1980f);
	glVertex2f(-0.994f, 0.2440f);
	glVertex2f(-0.956f, 0.2308f);
	glEnd();

    glPopMatrix();
}

void Trees()
{
   glLineWidth(10.0);
   glBegin(GL_LINES);
   glColor3ub(94,62,50);
   glVertex2f(0.760f, -0.440f);
   glVertex2f(0.760f, -0.360f);

   glVertex2f(0.840f, -0.350f);
   glVertex2f(0.840f, -0.300f);

   glVertex2f(0.930f, -0.461f);
   glVertex2f(0.930f, -0.380f);

   glEnd();

//1st tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.715f, -0.357f);
	glVertex2f(0.757f, -0.280f);
	glVertex2f(0.802f, -0.357f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.715f, -0.377f);
	glVertex2f(0.757f, -0.300f);
	glVertex2f(0.802f, -0.377f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.715f, -0.397f);
	glVertex2f(0.757f, -0.320f);
	glVertex2f(0.802f, -0.397f);
	glEnd();

//2nd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.813f, -0.298f);
	glVertex2f(0.837f, -0.254f);
	glVertex2f(0.864f, -0.298f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.813f, -0.318f);
	glVertex2f(0.837f, -0.274f);
	glVertex2f(0.864f, -0.318f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.813f, -0.338f);
	glVertex2f(0.837f, -0.294f);
	glVertex2f(0.864f, -0.338f);
	glEnd();

//3rd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.885f, -0.380f);
	glVertex2f(0.927f, -0.302f);
	glVertex2f(0.972f, -0.380f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.885f, -0.400f);
	glVertex2f(0.927f, -0.326f);
	glVertex2f(0.972f, -0.400f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(48,177,15);
	glVertex2f(0.885f, -0.420f);
	glVertex2f(0.927f, -0.346f);
	glVertex2f(0.972f, -0.420f);
	glEnd();

}

void WinterTrees()
{
   glLineWidth(10.0);
   glBegin(GL_LINES);
   glColor3ub(37,36,67);
   glVertex2f(0.760f, -0.440f);
   glVertex2f(0.760f, -0.360f);

   glVertex2f(0.840f, -0.350f);
   glVertex2f(0.840f, -0.300f);

   glVertex2f(0.930f, -0.461f);
   glVertex2f(0.930f, -0.380f);

   glEnd();

//1st tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.715f, -0.357f);
	glColor3ub(33,82,101);
	glVertex2f(0.757f, -0.280f);
	glColor3ub(5,24,45);
	glVertex2f(0.802f, -0.357f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.715f, -0.377f);
	glColor3ub(33,82,101);
	glVertex2f(0.757f, -0.300f);
	glColor3ub(5,24,45);
	glVertex2f(0.802f, -0.377f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.715f, -0.397f);
	glColor3ub(33,82,101);
	glVertex2f(0.757f, -0.320f);
	glColor3ub(5,24,45);
	glVertex2f(0.802f, -0.397f);
	glEnd();

//2nd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.813f, -0.298f);
	glColor3ub(33,82,101);
	glVertex2f(0.837f, -0.254f);
	glColor3ub(5,24,45);
	glVertex2f(0.864f, -0.298f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.813f, -0.318f);
	glColor3ub(33,82,101);
	glVertex2f(0.837f, -0.274f);
	glColor3ub(5,24,45);
	glVertex2f(0.864f, -0.318f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.813f, -0.338f);
	glColor3ub(33,82,101);
	glVertex2f(0.837f, -0.294f);
	glColor3ub(5,24,45);
	glVertex2f(0.864f, -0.338f);
	glEnd();

//3rd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.885f, -0.380f);
	glColor3ub(33,82,101);
	glVertex2f(0.927f, -0.302f);
	glColor3ub(5,24,45);
	glVertex2f(0.972f, -0.380f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.885f, -0.400f);
	glColor3ub(33,82,101);
	glVertex2f(0.927f, -0.326f);
	glColor3ub(5,24,45);
	glVertex2f(0.972f, -0.400f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(5,24,45);
	glVertex2f(0.885f, -0.420f);
	glColor3ub(33,82,101);
	glVertex2f(0.927f, -0.346f);
	glColor3ub(5,24,45);
	glVertex2f(0.972f, -0.420f);
	glEnd();

}

void TreesAutumn()
{
   glLineWidth(10.0);
   glBegin(GL_LINES);
   glColor3ub(173,86,36);
   glVertex2f(0.760f, -0.440f);
   glVertex2f(0.760f, -0.360f);

   glVertex2f(0.840f, -0.350f);
   glVertex2f(0.840f, -0.300f);

   glVertex2f(0.930f, -0.461f);
   glVertex2f(0.930f, -0.380f);

   glEnd();

//1st tree
//
  	glBegin(GL_TRIANGLES);
	glColor3ub(204,136,49);
	glVertex2f(0.715f, -0.357f);
	glVertex2f(0.757f, -0.280f);
	glVertex2f(0.802f, -0.357f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204,136,49);
	glVertex2f(0.715f, -0.377f);
	glVertex2f(0.757f, -0.300f);
	glVertex2f(0.802f, -0.377f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(204,136,49);
	glVertex2f(0.715f, -0.397f);
	glVertex2f(0.757f, -0.320f);
	glVertex2f(0.802f, -0.397f);
	glEnd();

//2nd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(170,187,59);
	glVertex2f(0.813f, -0.298f);
	glVertex2f(0.837f, -0.254f);
	glVertex2f(0.864f, -0.298f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(170,187,59);
	glVertex2f(0.813f, -0.318f);
	glVertex2f(0.837f, -0.274f);
	glVertex2f(0.864f, -0.318f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(170,187,59);
	glVertex2f(0.813f, -0.338f);
	glVertex2f(0.837f, -0.294f);
	glVertex2f(0.864f, -0.338f);
	glEnd();

//3rd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(251, 146, 42);
	glVertex2f(0.885f, -0.380f);
	glVertex2f(0.927f, -0.302f);
	glVertex2f(0.972f, -0.380f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(251, 146, 42);
	glVertex2f(0.885f, -0.400f);
	glVertex2f(0.927f, -0.326f);
	glVertex2f(0.972f, -0.400f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(251, 146, 42);
	glVertex2f(0.885f, -0.420f);
	glVertex2f(0.927f, -0.346f);
	glVertex2f(0.972f, -0.420f);
	glEnd();

}

void TreesMain()
{
    glPushMatrix();
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3ub(37,36,67);
    glVertex2f(0.760f, -0.440f);
    glVertex2f(0.760f, -0.360f);
    glEnd();

  	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.715f, -0.357f);
	glColor3ub(193,186,3);
	glVertex2f(0.757f, -0.280f);
	glColor3ub(26,72,17);
	glVertex2f(0.802f, -0.357f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.715f, -0.377f);
	glColor3ub(193,186,3);
	glVertex2f(0.757f, -0.300f);
	glColor3ub(26,72,17);
	glVertex2f(0.802f, -0.377f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.715f, -0.397f);
	glColor3ub(193,186,3);
	glVertex2f(0.757f, -0.320f);
	glColor3ub(26,72,17);
	glVertex2f(0.802f, -0.397f);
	glEnd();

	glPopMatrix();
}

void SpringTressForest()
{

//Top row of trees


    glPushMatrix();
    glTranslatef(-1.25f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.30f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.35f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.40f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.45f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

 /*   glPushMatrix();
    glTranslatef(-1.50f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.55f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.60f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();
*/
    glPushMatrix();
    glTranslatef(-1.65f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.70f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.80f,0.3f,0.0f);
    TreesMain();
    glPopMatrix();

//Middle row of trees

    glPushMatrix();
    glTranslatef(-1.20f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.25f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.30f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.35f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.40f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.45f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

 /*   glPushMatrix();
    glTranslatef(-1.50f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.55f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.60f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();
*/
    glPushMatrix();
    glTranslatef(-1.65f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.70f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.80f,0.22f,0.0f);
    TreesMain();
    glPopMatrix();

//Bottom row of trees
    glPushMatrix();
    glTranslatef(-1.1f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.15f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.20f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.25f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.30f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.35f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.40f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.45f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

 /*   glPushMatrix();
    glTranslatef(-1.50f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.55f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.60f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();*/

    glPushMatrix();
    glTranslatef(-1.65f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.70f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.80f,0.14f,0.0f);
    TreesMain();
    glPopMatrix();


}

void SpringTrees()
{
   glLineWidth(10.0);
   glBegin(GL_LINES);
   glColor3ub(37,36,67);
   glVertex2f(0.760f, -0.440f);
   glVertex2f(0.760f, -0.360f);

   glVertex2f(0.840f, -0.350f);
   glVertex2f(0.840f, -0.300f);

   glVertex2f(0.930f, -0.461f);
   glVertex2f(0.930f, -0.380f);

   glEnd();

//1st tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.715f, -0.357f);
	glColor3ub(193,186,3);
	glVertex2f(0.757f, -0.280f);
	glColor3ub(26,72,17);
	glVertex2f(0.802f, -0.357f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.715f, -0.377f);
	glColor3ub(193,186,3);
	glVertex2f(0.757f, -0.300f);
	glColor3ub(26,72,17);
	glVertex2f(0.802f, -0.377f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.715f, -0.397f);
	glColor3ub(193,186,3);
	glVertex2f(0.757f, -0.320f);
	glColor3ub(26,72,17);
	glVertex2f(0.802f, -0.397f);
	glEnd();

//2nd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.813f, -0.298f);
	glColor3ub(193,186,3);
	glVertex2f(0.837f, -0.254f);
	glColor3ub(26,72,17);
	glVertex2f(0.864f, -0.298f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.813f, -0.318f);
	glColor3ub(193,186,3);
	glVertex2f(0.837f, -0.274f);
	glColor3ub(26,72,17);
	glVertex2f(0.864f, -0.318f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.813f, -0.338f);
	glColor3ub(193,186,3);
	glVertex2f(0.837f, -0.294f);
	glColor3ub(26,72,17);
	glVertex2f(0.864f, -0.338f);
	glEnd();

//3rd tree
  	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.885f, -0.380f);
	glColor3ub(193,186,3);
	glVertex2f(0.927f, -0.302f);
	glColor3ub(26,72,17);
	glVertex2f(0.972f, -0.380f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.885f, -0.400f);
	glColor3ub(193,186,3);
	glVertex2f(0.927f, -0.326f);
	glColor3ub(26,72,17);
	glVertex2f(0.972f, -0.400f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(26,72,17);
	glVertex2f(0.885f, -0.420f);
	glColor3ub(193,186,3);
	glVertex2f(0.927f, -0.346f);
	glColor3ub(26,72,17);
	glVertex2f(0.972f, -0.420f);
	glEnd();

}

void SpringElements()
{
//Bottom Row
//1
	glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.34f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//2
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.39f,-0.24f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//3
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.44f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//4
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.49f,-0.24f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//5
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.54f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//6
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.59f,-0.24f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//7
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.64f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//8
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.69f,-0.24f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//9
/*    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.74f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//10
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.79f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//11
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.84f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();*/
//12
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.89f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//13
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.94f,-0.24f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//14
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.99f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

//MiddleRow

//3
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.44f,-0.16f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//4
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.49f,-0.14f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//5
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.54f,-0.16f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//6
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.59f,-0.14f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//7
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.64f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//8
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.69f,-0.16f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//9
/*    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.74f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//10
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.79f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//11
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.84f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();*/
//12
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.89f,-0.16f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//13
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.94f,-0.14f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//14
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.99f,-0.16f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

//Top Row

//4
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.49f,-0.08f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//5
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.54f,-0.06f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//6
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.59f,-0.08f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//7
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.64f,-0.06f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//8
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.69f,-0.08f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//9
/*    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.74f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//10
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.79f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//11
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.84f,-0.28f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();*/
//12
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.89f,-0.06f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//13
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.94f,-0.08f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//14
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(-0.99f,-0.06f,0.0f);
    glScalef(0.08f,0.08f,0.08f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

//Right Side Street

//Left most tree
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.76f,-0.37f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.74f,-0.40f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.78f,-0.40f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();
//Right Most tree
    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.93f,-0.37f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.91f,-0.42f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.95f,-0.42f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

//Middle Tree

    glPushMatrix();
	glColor3ub (175,104,37);
    glTranslatef(0.835f,-0.34f,0.0f);
    glScalef(0.07f,0.07f,0.07f);
    Circle(0.0f, 0.50f, 0.15f, 40);
    glColor3ub (81,49,25);
    Circle(0.0f, 0.50f, 0.08f, 40);
    glPopMatrix();

}


void SpringScene()
{
	SpringSky();
    SpringSun();
	SpringCloud1();
	SpringCloud2();
	SpringRiver();

	Boat();
	BoatCopies();

	Plane();
	SpringMountains();
	SpringWaterfall();
	SpringCity();


	SpringLand();
	SpringTressForest();
	SpringTrees();
	SpringElements();

    Car();
	SpringBridge();
	Lamppost();
	LamppostTranslate();

	glFlush();
}

void WinterScene()
{
	WinterSky();
	WinterSun();
	WinterCloud1();
	WinterCloud2();

	WinterRiver();
	WinterIce();
	WinterIceTranslate();

	WinterMountains();
	WinterWaterfall();
	WinterCity();
	Car();

	WinterLand();
	WinterBridge();
	Lamppost();
	LamppostTranslate();
	WinterTrees();

	glFlush();
}

void NightScene()
{
NightSky();
Moon();
Cloud1();
Cloud2();
NightRiver();

Boat();
Plane();
NightMountains();
NightWaterfall();
NightCity();

NightCar();
Land();
NightBridge();
NightLamppost();
NightLamppostTranslate();
Trees();
glFlush();
}

void DayScene()
{
Sky();
Sun();
Cloud1();
Cloud2();
River();

Boat();
Plane();
Mountains();
Waterfall();
City();

Car();
Land();
Bridge();
Lamppost();
LamppostTranslate();
Trees();
glFlush();
}

void AutumnScene()
{
SkyAutumn();
SunAutumn();
Cloud1Autumn();
Cloud2Autumn();
RiverAutumn();
BoatAutumn();
Plane();
MountainsAutumn();
WaterfallAutumn();
CityAutumn();
Car();
LandAutumn();
BridgeAutumn();
Lamppost();
LamppostTranslate();
TreesAutumn();
glFlush();
}

void Mouseinteraction_Car (int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{
	speed_car += 0.1f;
}
if (button == GLUT_RIGHT_BUTTON)
{
	speed_car -= 0.1f;
}
glutPostRedisplay();
}


void KeyInteraction(unsigned char key, int x, int y)
{
if (key=='n')
{
    glutDisplayFunc(NightScene);
}
else if (key=='d')
{
    glutDisplayFunc(DayScene);
}
else if (key=='w')
{
    glutDisplayFunc(WinterScene);
}
else if (key=='s')
{
    glutDisplayFunc(SpringScene);
}
else if (key=='a')
{
    glutDisplayFunc(AutumnScene);
}

glutPostRedisplay();
}

void display(void)
{

DayScene();

glFlush();  // Render now
glutSwapBuffers();
}



/* Main function: GLUT runs as a console application starting at main()  */

int main(int argc, char** argv)
{

	cout << endl << "//////////////// Summertime Bridge Scene \\\\\\\\\\\\\\\\" << endl <<endl;

	cout << " A : Autumn Season" << endl << endl;
	cout << " D : Enables Day" << endl << endl;
	cout << " N : Enables Night" << endl << endl;
	cout << " S : Spring Season" << endl << endl;
	cout << " W : Winter Season" << endl << endl;
	cout << " Mouse Left Click : Increase Car speed" << endl << endl;
	cout << " Mouse Right Click : Decrease Car speed" << endl << endl;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
glutInit(&argc, argv);                 // Initialize GLUT

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Display mode for output

glutInitWindowSize(840, 843);   // Set the window's initial width & height, must use before glutCreateWindow function

glutCreateWindow("Summertime Bridge"); // Create a window with the given title

glutInitWindowPosition(0,0); //Set Initial window's position

glutDisplayFunc(display); // Register display callback handler for window re-paint

glutKeyboardFunc(KeyInteraction); //Keyboard Interaction function

glutMouseFunc(Mouseinteraction_Car); //Mouse interaction function

glutTimerFunc(100, boatupdate, 0); //Update call back function for Boat

glutTimerFunc(100, copyboatupdate1, 0);

glutTimerFunc(100, copyboatupdate2, 0);

glutTimerFunc(100, waterfallupdate, 0);

glutTimerFunc(100, update_car, 0); //Update call back function for Car

glutTimerFunc(100, update_sun, 0);

glutTimerFunc(100, update_moon, 0);

glutTimerFunc(100, update_cloud1, 0);

glutTimerFunc(100, update_cloud2, 0);

glutTimerFunc(100, update_plane, 0);

glutTimerFunc(1000, iceupdate, 0);

glutTimerFunc(100, update_rain, 0);

//glutTimerFunc(5, Rain, 0);//not working

glutMainLoop();           // Enter the event-processing loop

return 0;

}
