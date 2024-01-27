#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


int jumpIndex = 0, doracordinatex= 70, doracordinatey = -20;

int run[10],jump[2];
int bg,obs1,obs2;
float x=0,obsx=400,obsx2=320;
bool stand = true;
int standCounter = 0;
bool jumpp = false;
bool jumpup = false;
bool jumpdown = false;
#define JUMPHEIGHT 150
int jumpCordinate = 0;
int doraIndex = 0;
void runindexIncrease()
{
	doraIndex++;
	if (doraIndex >=9)
		doraIndex = 0;
	//stand = false;
}




void iDraw()
{
	iClear();
	iShowImage(x, 0, 1200, 400, bg);
	iShowImage(x+1200, 0, 1200, 400, bg);
	//iShowImage(120, -20, 80, 180, obs2);
	iShowImage(obsx2, -30, 120, 180, obs2);
	//iShowImage(obsx, 0, 180, 120, obs1);
	//iShowImage(obsx1, 0, 180, 120, obs2);
   // iShowImage(50, -20, 120, 220, run[runIndex]);
	//iShowImage(50, -20, 120, 220, jump[jumpIndex]);
	x -= 0.15;
	if (x < -1200)
		x = 0;
	//obsx -= 0.03;
	obsx2 -= 0.015;
	if (jumpp)
	{
		if (jumpup)
		{
			iShowImage(doracordinatex, doracordinatey + jumpCordinate, 120, 220, jump[0]);
		}
		else{
			iShowImage(doracordinatex, doracordinatey + jumpCordinate, 120, 220, jump[1]);
		}
		
	}
	else {
		iShowImage(doracordinatex, doracordinatey, 120, 220, run[doraIndex]);
	}
	
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
	else if (key == ' ' )
	{
		if (!jumpp)
		{
			jumpp = true;
			jumpup=true;
		}
	}
	
}
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

		doracordinatex += 10;
		doraIndex++;
		if (doraIndex >= 9){
			doraIndex = 0;
		}
		
		stand = false;
	}
	if (key == GLUT_KEY_LEFT)
	{
		doracordinatex -= 10;
		doraIndex--;;
		if (doraIndex <0)
			doraIndex = 9;
		stand = false;

	}

	if (key == GLUT_KEY_HOME)
	{

	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void change()
{
	if (jumpp)
	{
		if (jumpup)
		{
			jumpCordinate += 5;
			if (jumpCordinate >= JUMPHEIGHT)
			{
				jumpup = false;
			}
		}
		else{
			jumpCordinate -= 5;
			if (jumpCordinate < 0)
			{
				jumpp = false;
				jumpCordinate = 0;
			}
		}
	}
}


int main()
{
	
	iInitialize(1200, 400, "Project Title");
	bg= iLoadImage("./image/BG.png");
    obs1 = iLoadImage("./image/obstacleBomb.png");
	obs2 = iLoadImage("./image/obstacleBox.png");
	run[0] = iLoadImage("./image/rundora1.png");
	run[1] = iLoadImage("./image/rundora2.png");
	run[2] = iLoadImage("./image/rundora3.png");
	run[3] = iLoadImage("./image/rundora4.png");
	run[4] = iLoadImage("./image/rundora5.png");
	run[5] = iLoadImage("./image/rundora6.png");
	run[6] = iLoadImage("./image/rundora7.png");
	run[7] = iLoadImage("./image/rundora8.png");
	run[8] = iLoadImage("./image/rundora9.png");
	run[9] = iLoadImage("./image/rundora10.png");
	jump[0] = iLoadImage("./image/dorajump2.png");
	jump[1] = iLoadImage("./image/dorajump7.png");
	//jump[2] = iLoadImage("./image/dorajump3.png");
	//jump[3] = iLoadImage("./image/dorajump4.png");
	//jump[4] = iLoadImage("./image/dorajump5.png");
	//jump[5] = iLoadImage("./image/dorajump6.png");
	//jump[6] = iLoadImage("./image/dorajump7.png");
	//jump[7] = iLoadImage("./image/dorajump8.png");

    iSetTimer(80, runindexIncrease);
	//iSetTimer(80, jumpIndexIncrease);
	
	iSetTimer(25, change);
	///updated see the documentations
	iStart();
	return 0;
}