/* THIS PROGRAM IS CREATED BY ABHISHEK KUMAR. THIS PROGRAM WILL ASK
	USER SIMPLE QUESTIONS AND USER SHOULD ANSWER THE QUESTIONS BY FILLING
	IN BLANK SPACES */

// CREATED TO RUN ON DOSBOX ONLY //

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<graphics.h>
#include<time.h>  ///REQUIRED FOR TIMEBAR//


void firstpage();//INTRO PAGE ///
void home();     //HERE NO. OF CONTESTANTS ARE ASKED//
void names(int );          ///THIS FUNCTION ASKS NAMES OF PLAYERS
void startpage();          ///START PAGE
void credits();

void border();   ///USED FOR BORDER DISPLAYED IN SPECIFIC PAGE////
void emptyg();   //USED FOR DRAWING G//
void filledg();  // USED FOR FILLING UP G//
void zoomin();   ///USED FOR CLEARING PAGE
void zoomout();  //USED FOR CLEARING PAGE
void timebar();  //TIME BAR CODING TO RESTRICT USER TO ENTER ANSWERS IN TIME//


void instructions(int); ///GAME INSTRUCTIONS
int tie_instructions(); // TIE ROUND INSTRUCTIONS

void tie_breaker(char [4][8],int );  //TIE BREAKER ROUND
void tie_equal(char [4][10],int);    //CONTAINS CODING IF MORE THAN 2 PLAYERS SCORED EQUAL  MARKS IN TIE BREAKER
void round2(char [4][8],int [4],int ); //CONATAINS CODING OF ROUND 2
void round1(char [4][8],int);        ///CODING OF ROUND 1
void playerexit(char [4][8],int [4],int );  ///CODING IF ANY PLAYER WANTS TO EXIT GAME AFTER ROUND 1
void winner(char [8]);       ///CODING OF PLAYER WHO WINS GAME
void fail(char [4][8],int);  ///CONTAINS CODING IF PLAYER IS NOT ABLE TO PASS
void score1(char [][8], int [4] ,int);  ///GENERALLY CODING OF SCOREBOARD


char qu[50][250],ans[50][39];  ////DECLARATION OF GLABAL QUESTIONS AND ANSWERS USED IN GAME
char pos[12][100],neg[6][100]; ///POSITIVE ( CORRECT ANSWER) AND NEGATIVE ( WRONG ANSWERS) REMARKS

void main()
{


	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	firstpage();

	getch();
}

void firstpage()
{

	cleardevice();

	int a=80,b=50,c=100,d=51,b1=420,d1=419;   //loading bars vertical
	for(int i=0;i<370;i++)
	{
		setcolor(6);
		delay(5);
		rectangle(a,b,c,d);
		d++;
		rectangle(558,b1,538,d1);
		d1--;
	}
	a=80,b=30,c=81,d=50;                 ///loading bars horizontal
	int a1=558,c1=557;
	for(i=0;i<478;i++)
	{
		setcolor(5);
		delay(5);
		rectangle(a,b,c,d);
		c++;
		rectangle(a1,420,c1,440);
		c1--;
	}
	setcolor(15);
	settextstyle(2,HORIZ_DIR,7);
	outtextxy(170,130,"WELCOME TO >>>>> ");



	setcolor(GREEN);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(300,300,"DEVELOPED BY --");
	setcolor(RED);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(340,330,"-- ABHISHEK KUMAR");

	int n=0;
	int x1=0;
	while(!kbhit())
	{
		setcolor(n+2);
		settextstyle(1,HORIZ_DIR,12);
		outtextxy(200,150,"WGG");
		setcolor(WHITE);
		settextstyle(1,HORIZ_DIR,1);
		outtextxy(250,55,"Press Any Key To Begin ");
		int a=240,b=55,c=530,d=80;
		delay(300);
		for(int i=0;i<290;i++)
		{
			setcolor(BLACK);
			rectangle(a,b,c,d);
			a++;
		}

		setcolor(WHITE);
		settextstyle(1,HORIZ_DIR,1);
		outtextxy(470+x1,55,">");
		x1+=10;
		n++;
		if(n%4==0)
		{
			x1=0;
		}
       }
       char ch;
       ch=getch();


       a=1,b=1,c=638,d=478;

       for(i=0;i<240;i++)
       {
		setcolor(BLACK);
		rectangle(a,b,c,d);
		a++;
		b++;
		c--;
		d--;
		delay(10);
       }
       delay(50);
       startpage();

}
void border()
{
	cleardevice();
	randomize();
	for(int i=0;i<=3000;i++)      ///sets colored pixels in background
	{
		setcolor(i);

		int x=random(660),y=random(500);
		putpixel(x,y,i);
	}
	setcolor(BLUE);


	delay(100);
	int a=1,b=1,c=638,d=475;
	for(int j=0;j<=8;j++)      ///border by rectangles
	{
		setcolor(j+1);
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

}

void emptyg()
{
	setcolor(BLUE);
	///these rectangles are used to make a G- like pattern

	int a=80,b=20,c=558,d=80;
	for(int j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);


	a=80,b=85,c=140,d=375;
	for(j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);

	a=80,b=380,c=558,d=440;
	for(j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);


	a=498,b=245,c=558,d=375;
	for(j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);


	a=330,b=180,c=558,d=240;
	for(j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(200);
}

void filledg()
{
	setcolor(BLUE);
	///rectangles used to fill G pattern
	int a=558,b=20,c=557,d=80;
	for(int j=0;j<479;j++)
	{
		delay(3);
		rectangle(a,b,c,d);
		c=c-1;
	}
	delay(100);

	a=80,b=85,c=140,d=86;
	for(j=0;j<290;j++)
	{
		delay(3);
		rectangle(a,b,c,d);
		d=d+1;
	}
	delay(100);

	a=80,b=380,c=81,d=440;
	for(j=0;j<479;j++)
	{
		delay(3);
		rectangle(a,b,c,d);
		c=c+1;
	}
	delay(100);


	a=498,b=375,c=558,d=374;
	for(j=0;j<131;j++)
	{
		delay(3);
		rectangle(a,b,c,d);
		d=d-1;
	}
	delay(100);


	a=558,b=180,c=557,d=240;
	for(j=0;j<229;j++)
	{
		delay(3);
		rectangle(a,b,c,d);
		c=c-1;
	}
	delay(200);
}

void zoomin()
{
	///clears screen by animation
	int a=0,b=0,c=640,d=480;

	for(int i=0;i<240;i++)
	{
		setcolor(BLACK);
		rectangle(a,b,c,d);
		a++;
		b++;
		c--;
		d--;
		delay(6);
	}


}
void zoomout()
{
	//animation to clear screen
	int a=0,b=0,c=640,d=480;

	for(int i=0;i<240;i++)
	{
		setcolor(BLACK);
		rectangle(a,b,c,d);

		b++;
		d--;
		delay(6);
	}


}
void timebar()
{       ///time coding to restrict user to enter answer in time
	///green fulll///
	int a=160,b=200,c=310,d=220;
	for(int jx=0;jx<=150;jx++)
	{
		if(kbhit())
		{
			break;
		}
		setcolor(GREEN);
		rectangle(a,b,c,d);
		c=c-1;
	}
	/////black start(first 10 sec)///
	a=310,b=200,c=160,d=220;
	for(jx=0;jx<=50;jx++)
	{
		if(kbhit())
		{
			break;
		}
		delay(200);
		setcolor(BLACK);
		rectangle(a,b,c,d);
		a=a-1;

	}

	///orange color///

	a=160,b=200,c=260,d=220;
	for(jx=0;jx<=100;jx++)
	{
		if(kbhit())
		{
			break;
		}
		setcolor(14);
		rectangle(a,b,c,d);
		c=c-1;
	}

	////black again for 10 sec///
	a=260,b=200,c=160,d=220;
	for(jx=0;jx<=50;jx++)
	{
		if(kbhit())
		{
			break;
		}
		delay(200);
		setcolor(BLACK);
		rectangle(a,b,c,d);
		a=a-1;

	}

	 ///red color///

	a=160,b=200,c=210,d=220;
	for(jx=0;jx<=50;jx++)
	{
		if(kbhit())
		{
			break;
		}
		setcolor(RED);
		rectangle(a,b,c,d);
		c=c-1;
	}
	////black for ending///
	a=210,b=200,c=160,d=220;
	for(jx=0;jx<=50;jx++)
	{
		if(kbhit())
		{
			break;
		}
		delay(200);
		setcolor(BLACK);
		rectangle(a,b,c,d);
		a=a-1;

	}
}

void startpage()
{
	cleardevice();

	border();//called for border
	delay(200);

	emptyg();

	setcolor(CYAN);
	settextstyle(3,VERT_DIR,5);
	outtextxy(80,100,":: OFFICIAL ::");

	delay(200);
	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,5);
	outtextxy(105,22,"WORD GUESSING GAME");

	delay(100);
	setcolor(WHITE);
	settextstyle(3,VERT_DIR,5);
	outtextxy(500,263,"WGG");
	delay(500);

	delay(200);

	setcolor(6);

	settextstyle(2,HORIZ_DIR,6);
	outtextxy(340,157,"With Regards :: ");
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,8);
	outtextxy(345,195,"Mr. Saxena Sir");

	delay(200);

	setcolor(6);

	settextstyle(2,HORIZ_DIR,8);
	outtextxy(110,393,"Created By ::");
	setcolor(WHITE);

	settextstyle(2,HORIZ_DIR,9);
	outtextxy(300,390,"Abhishek Kumar");

	char *choice1;
	int choice;

	delay(200);
	setcolor(GREEN);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,250,"1 - NEW GAME");

	delay(200);
	setcolor(5);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,270,"2 - Credits");

	delay(200);
	setcolor(CYAN);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,290,"3 - Instructions");
	delay(200);

	setcolor(RED);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,310,"4 - Quit");

	label:
	delay(200);
	setcolor(WHITE);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,333,"Enter Choice :: ");
	gotoxy(61,22);
	cin>>choice1;

	choice=atoi(choice1);

	if(choice==4)
	{
		delay(200);
		setcolor(RED);
		settextstyle(2,HORIZ_DIR,5);
		outtextxy(325,353,":: See You Next Time ::");
	}
	else
	{
		delay(200);
		setcolor(GREEN);
		settextstyle(2,HORIZ_DIR,5);
		outtextxy(340,353,":: Sure Processing ::");
	}
	delay(100);
	setcolor(GREEN);
	int a=80,b=450,c=82,d=455;
	for(int j=0;j<477;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		c=c+1;
	}


	delay(200);
	///again same coding to hide previous one by black color
	setcolor(BLACK);

	settextstyle(3,VERT_DIR,5);
	outtextxy(80,100,":: OFFICIAL ::");

	delay(200);
	setcolor(BLACK);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(105,22,"WORD GUESSING GAME");



	delay(200);

	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,6);
	outtextxy(340,157,"With Regards :: ");
	setcolor(WHITE);

	settextstyle(2,HORIZ_DIR,8);
	outtextxy(345,195,"Mr. Saxena Sir");

	delay(200);

	setcolor(BLACK);

	settextstyle(3,VERT_DIR,5);
	outtextxy(500,263,"WGG");
	delay(200);

	setcolor(BLACK);
	settextstyle(2,HORIZ_DIR,8);
	outtextxy(110,393,"Created By ::");
	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,9);
	outtextxy(300,390,"Abhishek Kumar");


	delay(200);
	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,250,"1 - NEW GAME");

	delay(200);
	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,270,"2 - Credits");

	delay(200);
	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,290,"3 - Instructions");
	delay(200);

	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,310,"4 - Quit");

	delay(200);
	setcolor(BLACK);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(360,333,"Enter Choice :::");

	setcolor(BLACK);

	a=470,b=335,c=490,d=348;
	for(j=0;j<21;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		a=a+1;
	}

	if(choice==4)
	{
		setcolor(BLACK);

		settextstyle(2,HORIZ_DIR,5);
		outtextxy(325,353,":: See You Next Time ::");
		setcolor(BLACK);

		a=485,b=355,c=496,d=367;
		for(j=0;j<11;j++)
		{
			delay(5);
			rectangle(a,b,c,d);
			a=a+1;
		}

	}
	else
	{
		delay(200);
		setcolor(BLACK);

		settextstyle(2,HORIZ_DIR,5);
		outtextxy(340,353,":: Sure Processing ::");
	}
	setcolor(BLUE);

	filledg();


	if(choice==4)
	{
		exit(0);
	}

	else if(choice==1)
	{
		instructions(0);
	}

	else if(choice==2)
	{
		credits();
	}
	else if(choice==3)
	{
		instructions(1);
	}
	else
	{
		exit(0);
	}
	getch();
}

void credits()
{
	border();
	delay(500);

	setcolor(5);
	int a=80,b=35,c=558,d=85;
	for(int j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(135,32,"GAME DEVELOPERS");

	delay(500);

	setcolor(BLUE);

	a=80,b=410,c=558,d=460;
	for(j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(500);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(195,407,":::: THANKS ::::");
	delay(500);


	delay(500);
	setcolor(BLUE);

	a=80,b=95,c=140,d=400;
	for(j=0;j<3;j++)
	{
		delay(100);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);

	setcolor(WHITE);

	settextstyle(3,VERT_DIR,5);
	outtextxy(80,100,":: CREDITS ::");

	setcolor(BLUE);
	delay(500);


	a=498,b=95,c=558,d=400;
	for(j=0;j<3;j++)
	{
		delay(100);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(500);

	setcolor(WHITE);

	settextstyle(3,VERT_DIR,5);
	outtextxy(500,90," ::::: W.G.G ::::: ");

	delay(1000);
	setcolor(CYAN);
	settextstyle(2,HORIZ_DIR,7);
	outtextxy(240,100,"- WITH REGARDS -");

	setcolor(WHITE);
	delay(300);
	settextstyle(2,HORIZ_DIR,7);
	outtextxy(230,130,"MR. VIVEK SAXENA SIR");

	delay(500);
	setcolor(CYAN);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(210,160,"- DESIGNED AND DEVELOPED BY -");

	delay(500);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(270,180,"ABHISHEK KUMAR");

	setcolor(CYAN);
	delay(500);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(255,210,"- CO DEVELOPERS -");

	setcolor(5);
	delay(500);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(280,240,"ARJUN SAXENA");

	delay(500);
	outtextxy(280,260,"KUSHAGRA GUPTA");

	delay(500);
	outtextxy(280,280,"HARSH KUMAR");

	delay(500);
	outtextxy(280,300,"ANSHUMAN TIWARI");

	delay(500);
	outtextxy(280,320,"AVIRAL PRAKASH");

	delay(500);
	outtextxy(280,340,"ARYENDRA SINGH");

	delay(500);
	outtextxy(280,360,"PRAKHAR PRATAP");

	delay(500);
	outtextxy(280,380,"SHIVANSH PATHAK");
	delay(1000);
	zoomout();
	startpage();
	getch();
}

void instructions(int num)
{

	cleardevice();
	border();

	delay(1000);

	setcolor(5);


	int a=80,b=35,c=558,d=85;
	for(int j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(1000);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(125,32,"GAME INSTRUCTIONS");

	delay(400);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,90,"Loading.....");
	delay(400);

	a=80,b=110,c=558,d=115;
	for(j=0;j<477;j++)
	{
		setcolor(j+1);
		delay(5);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(300);

	setcolor(CYAN);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(80,130,"1....EACH PLAYER MUST ENTER A UNIQUE NAME , EAH PLAYER WILL ");
	delay(50);

	outtextxy(110,145,"BE IDENTIFIED UNIQUELY IN WHOLE GAME .");

	delay(300);

	outtextxy(80,170,"2....GAME CONSISTS OF TWO ROUNDS AS FOLOWS : ");

	delay(200);
	setcolor(5);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(120,190,":::: Round 1 . ...TOTAL 3 QUESTIONS OF 10 MARKS EACH.");


	delay(200);
	outtextxy(150,205,".... EACH CANDIDATE WILL BE ASKED 3 QUESTIONS");

	delay(200);
	outtextxy(120,230,"::: Round 2(The Final Round ). .ONLY 1 QUESTION OF 20 MARKS.");

	delay(300);
	setcolor(6);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(80,250,"3....SO WE HAVE TOTAL 50 MARKS FOR EACH CANDIDATE ");

	delay(300);
	outtextxy(80,280,"4....AFTER GAME GETS OVER , SCORECARD WOULD BE SHOWN.");

	delay(50);
	outtextxy(110,295,"PLAYER WITH MAXIMUM MARKS WINS THE GAME.");

	delay(300);
	outtextxy(80,320,"4....THE ANSWER SHOULD BE GIVEN BY FILLING CORRECT -");

	delay(50);
	outtextxy(110,335,"WORD AT RIGHT SPACE.");

	delay(400);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(80,360,"5....PLEASE DON'T PRESS UNNECESSARY KEYS.");

	delay(300);

	setcolor(WHITE);
	delay(200);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,390,"Loading.....");
	delay(300);

	a=60,b=410,c=573,d=415;
	for(j=0;j<520;j++)
	{
		setcolor(j+1);
		delay(5);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(500);

	a=578,b=415,c=583,d=15;
	for(j=0;j<401;j++)
	{
		setcolor(j+1);
		delay(5);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(200);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(j+1);
		delay(5);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(200);

	a=55,b=15,c=60,d=415;
	for(j=0;j<401;j++)
	{
		setcolor(j+1);
		delay(5);
		rectangle(a,b,c,d);
		b=b+1;
	}
	delay(100);
	zoomout();

	if(num==0)
	{
		home();
	}
	else
	{
		startpage();
	}
	getch();
}

void home()
{
	border();

	setcolor(BLUE);
	delay(200);
	int a=80,b=30,c=558,d=100;
	for(int j=0;j<3;j++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(200);
	setcolor(BLUE);
	a=280,b=102,c=558,d=130;
	for(j=0;j<2;j++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}


	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,14);
	outtextxy(120,40,":: LUCKY TRIVIA ::");

	setcolor(RED);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(300,105," -- WORD GUESSING GAME -- ");

	delay(200);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,160,"Loading.....");
	delay(200);

	a=80,b=180,c=558,d=185;
	for(j=0;j<477;j++)
	{
		setcolor(j+1);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	setcolor(5);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(80,200,"Great  Ok, when the music starts, things  might  get a");
	delay(100);

	outtextxy(80,215,"little slowbiz . Prepare yourself.");

	delay(100);
	outtextxy(80,250,"THIS IS ANSWER GUESSING GAME BY FILLING WORDS IN SPACES");

	delay(100);
	setcolor(6);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,290,"AND I AM Alexa .The HOST");

	delay(100);

	delay(200);
	setcolor(BLUE);
	a=80,b=340,c=490,d=380;
	for(j=0;j<2;j++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);

	delay(200);
	setcolor(BLUE);
	a=500,b=340,c=558,d=380;
	for(j=0;j<2;j++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(100);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(88,350,"HOW MANY CONTESTANTS DO WE HAVE (Max 4)");

	int players;

	delay(100);
	setcolor(5);

	gotoxy(66,23);
	cin>>players;

	delay(100);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,390,"Loading.....");
	delay(200);

	a=60,b=410,c=573,d=415;
	for(j=0;j<520;j++)
	{
		setcolor(j+1);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(100);

	a=578,b=415,c=583,d=15;
	for(j=0;j<401;j++)
	{
		setcolor(j+1);
		delay(2);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(100);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(j+1);
		delay(2);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(100);

	a=55,b=15,c=60,d=415;
	for(j=0;j<401;j++)
	{
		setcolor(j+1);
		delay(2);
		rectangle(a,b,c,d);
		b=b+1;
	}
	zoomout();

	if(players>4)
	{
		players=4;
	}
	else if(players<=0)
	{
		players=1;

	}
	names(players);

	getch();
}

void names( int p)
{
	border();

	delay(200);
	setcolor(5);


	int a=80,b=35,c=558,d=85;
	for(int j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(140,32,"::: LUCKY TRIVIA ::: ");

	delay(500);
	setcolor(6);

	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,100,"LET's START WITH YOUR NAMES ::: ");
	if(p<1)
	{
		p=1;
	}
	char enteredname[4][8];
	int x=0;
	int u=0;
	for(int r=0;r<p;r++)
	{
		delay(200);
		setcolor(BLUE);
		a=80,b=130+x,c=380,d=169+x;
		for(int j=0;j<2;j++)
		{
			delay(200);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}

		delay(200);
		setcolor(GREEN);
		int e=400,f=130+x,g=558,h=169+x;
		for(j=0;j<2;j++)
		{
			delay(200);
			rectangle(e,f,g,h);
			e=e+1;
			f=f+1;
			g=g-1;
			h=h-1;
		}

		delay(100);
		setcolor(BLUE);
		settextstyle(2,HORIZ_DIR,6);
		gotoxy(13,10+u);
		cout<<"PLAYER :: "<<r+1<<" :: ENTER YOUR NAME  ::";

		delay(100);
		setcolor(BLUE);

		gotoxy(53,10+u);
		cin.getline(enteredname[r],8);

		x=x+64;      //creates next block
		u=u+4;
	}

	delay(200);
	setcolor(BLUE);
	a=80,b=370,c=558,d=410;
	for(int i=0;i<2;i++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);
	setcolor(BLUE);
	settextstyle(2,HORIZ_DIR,6);
	gotoxy(13,25);
	cout<<"WELL NAME SOUNDS GOOD....LET'S PROCEED WITH GAME. ";
	delay(100);

	delay(100);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,430,"Loading.....");
	delay(200);

	a=60,b=450,c=573,d=455;
	for(j=0;j<520;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(100);

	a=578,b=455,c=583,d=15;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(100);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(100);

	a=55,b=15,c=60,d=455;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b+1;
	}

	delay(100);
	zoomout();
	cleardevice();
	round1(enteredname,p);

}

void round1(char name[4][8], int p)
{

	cleardevice();

	char newname[4][8];
	strcpy(newname[0],name[0]);
	strcpy(newname[1],name[1]);
	strcpy(newname[2],name[2]);
	strcpy(newname[3],name[3]);



	//GENERAL STRUCTURE//---

	///questions which are asked in game
	strcpy(qu[0],"Is it correct to say - 'The Yolk of Eggs is White ' or 'The Yolk of Eggs are White '?");
	strcpy(qu[1],"What is the difference between Lava and Magma ?");
	strcpy(qu[2],"What made the AK-47 gun so popular ?");
	strcpy(qu[3],"Legally , are Tomatoes Fruits or Vegetables ?");
	strcpy(qu[4],"What's the sound of One Hand clapping ?");
	strcpy(qu[5],"How far can a Rabbit run into the Woods ?");
	strcpy(qu[6],"Which is the highest degree of Comparison ?");
	strcpy(qu[7],"What's the name of the Space between your Thumb and other Fingers ?");
	strcpy(qu[8],"What is full of Holes but can still hold Water?");
	strcpy(qu[9],"What never asks a question but gets answered all the Time ?");
	strcpy(qu[10],"Before Mount Everest was discovered, what was the highest mountain in the World ?");
	strcpy(qu[11],"Credit , Debit or Paypal :: What's the safest way to pay ONLINE ?");
	strcpy(qu[12],"You measure my Life in hours and i serve you by expiring. I'm quick when I'm thin and slow when I'm fat.The wind is my Enemy .Guess who am I ?");
	strcpy(qu[13],"What word en English language does the following- the first two letters signify a Male , The first three letters signify a Female , the first four letters signify a Great. What is the word ?");
	strcpy(qu[14],"What disappers as soon as you say its name ?");
	strcpy(qu[15],"I have keys but no locks and space , and no rooms. You can enter , but you can't go outside. What am I ?");
	strcpy(qu[16],"What gets wet while drying ?");
	strcpy(qu[17],"How many letters are there in alphabet ?");
	strcpy(qu[18],"If you jump off the roof of a ten storey building , where would you land ?");
	strcpy(qu[19],"Which word in English Dictionary is always spelled incorrectly ?");
	strcpy(qu[20],"What starts with 'e' and ends with 'e' but only has one letter in it ?");
	strcpy(qu[21],"What can Run but not Walk ?");
	strcpy(qu[22],"Which weighs more , a pound of feather or a pound of bricks ?");
	strcpy(qu[23],"What can you hold without touching it at all ?");
	strcpy(qu[24],"I'm so fragile that if you say my name, you'll break me.What am I ?");
	strcpy(qu[25],"What goes up as soon as rain comes down ?");
	strcpy(qu[26],"The more you take, the more you leave behind.What am I ?");
	strcpy(qu[27],"What has three feet but can't Walk ?");
	strcpy(qu[28],"What has four eyes but can't see ?");
	strcpy(qu[29],"What's as big as elephant but weighs absolutely nothing ?");
	strcpy(qu[30],"If I have it , I don't share it.If I share it, Idon't have it.What is it ?");
	strcpy(qu[31],"What has one eye but can't see anything at all ?");
	strcpy(qu[32],"Who will become the President if Vice-President dies ?");
	strcpy(qu[33],"If a Monkey,Bird and Squirrel race up a coconut tree.Which one of them is most likely to get banana?");
	strcpy(qu[34],"I am something,people work extremely hard to het me everyday. When they get me ,they give me away. What am I ?");
	strcpy(qu[35],"What has four legs bu can't walk ?");
	strcpy(qu[36],"What is Black and White that gets read over ?");
	strcpy(qu[37],"What did the Mouse say to Cheese ?");
	strcpy(qu[38],"What is a Ten letter word that has thousands of words in it ?");
	strcpy(qu[39],"What normally stands up and grows down ?");
	strcpy(qu[40],"How do you call people that come from a country of medal ?");
	strcpy(qu[41],"What seven letter word has hundreds of letters?");
	strcpy(qu[42],"What happens when you mix C and SUN ?");
	strcpy(qu[43],"What has a head at night but none during the Day ?");
	strcpy(qu[44],"Where does Friday always comes before Thursday ?");
	strcpy(qu[45],"Made from a variety of materials, such as Carbon,which inhibits thd flow of Current ?");
	strcpy(qu[46],"The first step to getting output from a Laser is to Excite an active Medium.What is the process called ");
	strcpy(qu[47],"Which Programming Language is exclusively used for Artificial Intelligence ?");
	strcpy(qu[48],"Where is the headquarter of Microsoft Office located ?");
	strcpy(qu[49],"Which is the default 'Word Processor' of Microsoft Windows ?");

	///answers of question aq to index of questions
	strcpy(ans[0],"Neither");
	strcpy(ans[1],"Location");
	strcpy(ans[2],"Reliability");
	strcpy(ans[3],"Veggies");
	strcpy(ans[4],"Pwwwft");
	strcpy(ans[5],"Halfway");
	strcpy(ans[6],"Superlative");
	strcpy(ans[7],"Purlicue");
	strcpy(ans[8],"Sponge");
	strcpy(ans[9],"Cellphone");
	strcpy(ans[10],"Everest");
	strcpy(ans[11],"Credit");
	strcpy(ans[12],"Candle");
	strcpy(ans[13],"Heroine");
	strcpy(ans[14],"Silence");
	strcpy(ans[15],"Keyboard");
	strcpy(ans[16],"Towel");
	strcpy(ans[17],"Eight");
	strcpy(ans[18],"Hospital");
	strcpy(ans[19],"Incorrectly");
	strcpy(ans[20],"Envelope");
	strcpy(ans[21],"Raindrops");
	strcpy(ans[22],"Neither");
	strcpy(ans[23],"Conversation");
	strcpy(ans[24],"Silence");
	strcpy(ans[25],"Umbrella");
	strcpy(ans[26],"Footprints");
	strcpy(ans[27],"Yardstick");
	strcpy(ans[28],"Mississippi");
	strcpy(ans[29],"Shadow");
	strcpy(ans[30],"Secret");
	strcpy(ans[31],"Needle");
	strcpy(ans[32],"President");
	strcpy(ans[33],"Noneofthem");
	strcpy(ans[34],"Money");
	strcpy(ans[35],"Table");
	strcpy(ans[36],"Newspaper");
	strcpy(ans[37],"Squeak");
	strcpy(ans[38],"Dictionary");
	strcpy(ans[39],"Candle");
	strcpy(ans[40],"Medallions");
	strcpy(ans[41],"Mailbox");
	strcpy(ans[42],"Season");
	strcpy(ans[43],"Pillow");
	strcpy(ans[44],"Dictionary");
	strcpy(ans[45],"Resistor");
	strcpy(ans[46],"Pumping");
	strcpy(ans[47],"Prolog");
	strcpy(ans[48],"Washington");
	strcpy(ans[49],"Wordpad");


	int score[4];
	///scores of players
	score[0]=0;
	score[1]=0;
	score[2]=0;
	score[3]=0;
	///correct answer remarks
	strcpy(pos[0],"...Oh  man ......You are Damn GOOD..");
	strcpy(pos[1],"...WoW..........Excellent...");
	strcpy(pos[2],"...Interesting....Good....");
	strcpy(pos[3],"...You are the only Genius...");
	strcpy(pos[4],"...Good...It's Right Answer...");
	strcpy(pos[5],"....WINNER WINNER CHICKEN DINNER....");
	strcpy(pos[6],"......Excellent......");
	strcpy(pos[7],"......OutStanding......");
	strcpy(pos[8],"....Fantastic....");
	strcpy(pos[9],"..........Perfect..........");
	strcpy(pos[10],"..........Amazing Answer..........");
	strcpy(pos[11],"..........Not Bad..........");

	///wrong answer remarks
	strcpy(neg[0],"......Missed this time...");
	strcpy(neg[1],"...Sorry.......You went wrong...");
	strcpy(neg[2],"......It was Quite Easy.... ");
	strcpy(neg[3],"....Better Luck next Time....");
	strcpy(neg[4],"........Wrong answer ....");
	strcpy(neg[5],".....Tried WELL...");


	///END OF GENERAL STRUCTURE//

	/////LOADING OF ROUND 1////


		cleardevice();
		setcolor(WHITE);

		settextstyle(3,HORIZ_DIR,3);
		outtextxy(175,110,"LOADING ROUND 1....");
		outtextxy(270,140,"...PLEASE WAIT");
		setcolor(BLUE);
		filledg();    ///displays G

		delay(1000);



	////ROUND 1 CODING///



	for(int i1=0;i1<3;i1++)  ///round 1 consists of 3 question rounds
	{
		cleardevice();

		delay(50);
		setcolor(WHITE);
		settextstyle(2,HORIZ_DIR,6);
		outtextxy(1,140,"LOADING QUESTION ROUND :: ");

		gotoxy(33,10);
		cout<<(i1+1);

		setcolor(WHITE);
		settextstyle(2,HORIZ_DIR,6);
		outtextxy(1,164,"PLEASE WAIT ........... ");


		int a=1,b=200,c=2,d=240;
		for(int i=0;i<638;i++)   ///loading bar
		{
			setcolor(WHITE);
			delay(3);
			rectangle(a,b,c,d);
			c++;

		}
		randomize();
		delay(300);
		for(int j=0;j<p;j++)///runs for number of players to ask each player 1 question
		{

			////LOADING///

			cleardevice();
			border();

			setcolor(BLUE);
			delay(200);

			emptyg();
			delay(50);

			setcolor(WHITE);
			settextstyle(3,VERT_DIR,5);
			outtextxy(80,95,":: ROUND 1 ::");

			delay(200);
			setcolor(WHITE);
			settextstyle(3,VERT_DIR,5);
			outtextxy(500,263,"WGG");
			delay(1000);

			delay(50);

			delay(50);
			setcolor(WHITE);
			settextstyle(3,HORIZ_DIR,5);
			outtextxy(105,382,"WORD GUESSING GAME");



			int q;     ///variable to select a random question
			q=random(50);
			char an[100]; ///variable to store answer of question
			int answer;  ///stores length of answer
			answer=strlen(ans[q]);
			strcpy(an,ans[q]);

			int answer2; ///variable to adjust spaces for short answers and long answers
			if(answer<6)
			{
				answer2=answer-2; ///for short answer space calculation
			}
			else
			{
				answer2=answer;
			}

			randomize();
			for(int k=0;k<10;k++)
			{
				int c222=0;///variable used to find whether required number of characters are converted to '_' space
				int sp;

				sp=random(answer); ///random '_' spaces in answers
				an[sp]='_';

				for(int t=0;t<answer;t++)
				{
					if(an[t]=='_')
					{
						c222++;
					}
				}
				if(c222==answer2)
				{
					break;
				}

			}

			delay(500);
			setcolor(5);
			settextstyle(2,HORIZ_DIR,7);
			outtextxy(108,35,"THIS QUESTION IS FOR :: ");
			setcolor(WHITE);
			char name1[10];//stores name of player to which question is asked
			strcpy(name1,newname[j]);
			delay(200);
			outtextxy(386,35,name1);

			///QUESTION STRING ADJUSTMENT///

			int quo=strlen(qu[q]);///calculates string length of question

			int c22=(quo/48)+1;//calculates in how many lines the question can be displayed if one line holds 48 characters
			int br1=0;
			int r1=7,c1=20,k1=48,c3=0;
			for(int q1=0;q1<c22;q1++)
			{
				c1=20;

				for(int q2=c3;q2<k1;q2++)
				{
					delay(20);

					if(qu[q][q2]=='\0')///as soon as question ends, loop stops
					{
						br1=1;
						break;
					}
					gotoxy(c1,r1);///sets co ordinates to display 1 1 character of question
					cout<<qu[q][q2];//displayers1 character at a time
					c1++;
				}

				if(br1==1) ///breaks outer loop
				{
					break;
				}
				q2=q2+48;//after 48 charcters of question are displayed, next 48 characters are displayed
				c3=c3+48;//same as above to run inner loop for next 48 characters to display characters of question
				k1=k1+48;//same as above to run inner loop
				r1++;    //transfers cursor to next line
			}
			////TO SHOW ANSWER ///

			setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,8);
			outtextxy(355,195,an);



			////SPACE FILLING///
			for(int l=0;l<answer;l++)
			{
				if(an[l]=='_')
				{
					char answ;
					delay(50);
					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					outtextxy(160,252,"CHARACTER FOR SPACE :: ");
					gotoxy(49,17);
					cout<<l+1;

					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					outtextxy(410,252,":: ");
					gotoxy(53,17);


					int a=330,b=180,c=558,d=240;
					for(int jx=0;jx<5;jx++)
					{
						delay(50);
						rectangle(a,b,c,d);
						a=a+1;
						b=b+1;
						c=c-1;
						d=d-1;
					}
					setcolor(WHITE);
					settextstyle(2,HORIZ_DIR,8);
					outtextxy(355,195,an);
					delay(50);

					clock_t start=clock();

					while(!kbhit())
					{


						if(((clock()-start)/CLOCKS_PER_SEC)>=1)
						{
							an[l]='-';
							gotoxy(55,17);
							cout<<"TIMEOUT"<<endl;
							goto time;
						}
						timebar();

					}

					an[l]=getch();

					time:
					if(an[l]!='-')
					{
						gotoxy(55,17);
						setcolor(GREEN);
						settextstyle(2,HORIZ_DIR,6);
						cout<<an[l];
					}



				}


				////to hide previous answer///

				setcolor(BLACK);


				int a=330,b=180,c=558,d=240;
				for(int j7=0;j7<229;j7++)
				{
					rectangle(a,b,c,d);
					a=a+1;
				}

				setcolor(BLUE);

				a=330,b=180,c=558,d=240;
				for(j7=0;j7<5;j7++)
				{

					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				delay(50);
				setcolor(WHITE);
				settextstyle(2,HORIZ_DIR,8);
				outtextxy(355,195,an);
				///TO HIDE ENTERED NUMBER///
				delay(200);
				setcolor(BLACK);
				a=160,b=253,c=490,d=272;
				for(int j1=0;j1<331;j1++)
				{
					rectangle(a,b,c,d);
					a=a+1;
				}
			}

			delay(500);
			setcolor(CYAN);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(160,272,"YOU ENTERED :::: ");

			setcolor(GREEN);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(330,272,an);///shows answer entered by answer



			delay(1000);
			setcolor(6);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(160,302,"LET'S SEE YOUR LUCK");


			randomize();
			if(strcmpi(an,ans[q])==0)//checks whether answer entered by user is correct or not
			{

				randomize();
				delay(500);
				score[j]=score[j]+10;/// increases score of user
				int ges;
				ges=random(10); //picks a random remark

				///green rectangle//
				setcolor(GREEN);
				a=330,b=180,c=558,d=240;
				for(int jx=0;jx<5;jx++)
				{
					delay(50);
					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}//rectangle in which answer is shown becomes green to indicate correct answer
				delay(50);

				setcolor(GREEN);
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(160,322,pos[ges]);  ///shows remarks  of green color (+ remark)

				delay(500);
				setcolor(CYAN);
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(155,342,"WELL ");
				setcolor(WHITE);
				outtextxy(215,342,name1);//displays name of current player
				setcolor(CYAN);
				outtextxy(290,342," 10 MARKS CREDITED ");

			}

			else
			{
				randomize();
				delay(500);
				int ges;
				ges=random(6);  ///picks a random remark

				///NEGATIVE REMARK///

				setcolor(RED);

				a=330,b=180,c=558,d=240;
				for(int jx=0;jx<5;jx++)
				{
					delay(50);
					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				setcolor(RED);

				settextstyle(2,HORIZ_DIR,6);
				outtextxy(160,322,neg[ges]);

				delay(500);
				setcolor(CYAN);

				settextstyle(2,HORIZ_DIR,6);
				outtextxy(155,342,"WELL ");
				setcolor(WHITE);
				outtextxy(205,342,name1);
				setcolor(CYAN);
				outtextxy(280,342," BETTER LUCK NEXT TIME ");
			}
			delay(1000);

			setcolor(BLACK);
			a=80,b=380,c=558,d=440;
			for(int j1=0;j1<479;j1++)
			{
				delay(1);
				rectangle(a,b,c,d);
				a=a+1;
			}
			delay(50);

			setcolor(BLUE);

			a=80,b=380,c=558,d=440;
			for(int j8=0;j8<5;j8++)
			{
				delay(50);
				rectangle(a,b,c,d);
				a=a+1;
				b=b+1;
				c=c-1;
				d=d-1;
			}

			delay(50);
			setcolor(WHITE);
			settextstyle(3,HORIZ_DIR,5);
			outtextxy(155,382,"THANKS  ");
			outtextxy(325,382,name1);  ///THANKS USER

			delay(1000);

		}

		setcolor(BLUE);

		a=330,b=180,c=558,d=240;
		for(int jx=0;jx<5;jx++)
		{
			delay(50);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		 }

		delay(1000);

		setcolor(BLACK);
		a=80,b=380,c=558,d=440;
		for(int j1=0;j1<479;j1++)
		{
			delay(2);
			rectangle(a,b,c,d);
			a=a+1;
		}

		setcolor(BLUE);


		a=80,b=380,c=558,d=440;
		for(j1=0;j1<5;j1++)
		{
			delay(50);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}

		delay(50);

		delay(50);
		setcolor(WHITE);

		settextstyle(3,HORIZ_DIR,5);
		outtextxy(105,382,"WORD GUESSING GAME");
		delay(500);

		///LOADING////
		delay(200);
		setcolor(GREEN);

		a=80,b=450,c=82,d=455;
		for(j1=0;j1<477;j1++)
		{
			delay(3);
			rectangle(a,b,c,d);
			c=c+1;
		}

		delay(200);

		zoomin();

		cleardevice();

	}

	delay(500);
	playerexit(newname,score,p);    ///if any player wants to exit
	////END OF ROUND 1/////
}

void playerexit(char newname[4][8],int score[4],int n)
{
	again:
	cleardevice();
	char choice;
	char names[4][8];
	strcpy(names[0],newname[0]);
	strcpy(names[1],newname[1]);
	strcpy(names[2],newname[2]);
	strcpy(names[3],newname[3]);

	delay(50);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(1,76,"IS THERE ANYONE WILLING TO EXIT THE GAME (Y/N):: ");
	gotoxy(60,6);
	cin>>choice;
	int place=10; ///for verification

	if(choice=='Y' || choice=='y')    //if anyone wants to exit game
	{
		char search[8];

		delay(50);
		setcolor(WHITE);
		settextstyle(2,HORIZ_DIR,6);
		outtextxy(1,107,"PLEASE ENTER GAME ID NAME :: ");

		gotoxy(38,8);
		cin.getline(search,8);

		for(int s1=0;s1<n;s1++)
		{
			if(strcmpi(names[s1],search)==0)
			{

				place=s1;
				break;
			}
		}
		if(n==1 && place!=10)//if 1 player is playing and he wants to exit game then coding to quit game
		{
			char  x1[10];
			strcpy(x1,search);
			strupr(x1);
			gotoxy(1,10);
			delay(500);
			cout<<"WELL "<<x1<<" YOU SCORED ::  "<<score[place]<<" /30 MARKS IN ROUND-1  "; //displays score of round 1
			gotoxy(1,11);
			delay(500);
			cout<<"SEE YOU NEXT TIME .......";

			delay(500);
			setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(1,184,"EXITING GAME PLEASE WAIT ........... ");

			int a=1,b=220,c=2,d=260;
			for(int i=0;i<638;i++)
			{
				setcolor(WHITE);
				delay(3);
				rectangle(a,b,c,d);
				c++;

			}
			exit(0);

		}
		if(place==10) //if entered name not found
		{
			setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(1,135,"SORRY CREDENTIALS DIDN'T MATCHED ..PLEASE TRY AGAIN.");
			delay(1000);
			cleardevice();
			goto again;

		}

		else   ///if more than 1 players playing game and 1 wants to exit game
		{

			char  x1[10];
			strcpy(x1,search);
			strupr(x1);
			gotoxy(1,10);
			delay(500);
			cout<<"WELL "<<x1<<" YOU SCORED ::  "<<score[place]<<" /30 MARKS IN  ROUND-1";
			gotoxy(1,11);
			delay(500);
			cout<<"SEE YOU NEXT TIME .......";

			delay(500);
			setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(1,184,"PLEASE WAIT ........... ");

			int a=1,b=220,c=2,d=260;
			for(int i=0;i<638;i++)
			{
				setcolor(WHITE);
				delay(3);
				rectangle(a,b,c,d);
				c++;

			}

			char enames[3][8];  ///adjusts names left to go in round 2

			for(i=s1;i<n;i++)
			{
				strcpy(names[i],names[i+1]);
				score[i]=score[i+1];//adjusts score of players left
			}
			for(i=0;i<(n-1);i++)
			{

				strcpy(enames[i],names[i]);
			}
			n=n-1;  //players decrease as 1 exited game
			round2(enames,score,n); ///left players and scores for round 2

		}

	}

	else //if no one wants to exit game
	{

		delay(50);
		setcolor(WHITE);
		settextstyle(2,HORIZ_DIR,6);
		outtextxy(1,140,"PROCEEDING WITH THE GAME :: ");
		setcolor(WHITE);
		settextstyle(2,HORIZ_DIR,6);
		outtextxy(1,164,"PLEASE WAIT ........... ");
		int a=1,b=200,c=2,d=240;
		for(int i=0;i<638;i++)
		{
			setcolor(WHITE);
			delay(3);
			rectangle(a,b,c,d);
			c++;

		}
		delay(500);
		round2(newname,score,n); //same players

	}

}


void round2(char newname[4][8],int score[4],int p)
{

	////ROUND 2 LOADING///
	cleardevice();

	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,3);
	outtextxy(175,110,"LOADING ROUND 2....");
	outtextxy(270,140,"...PLEASE WAIT");
	setcolor(BLUE);
	filledg();
	delay(1000);
	//////end////

	/* ROUND 2 IS SAME AS ROUND 1 BUT HERE ONLY ONE QUESTION IS ASKED OF 20 MARKS*/
	////ROUND 2 CODING////
	for(int i1=0;i1<1;i1++)//ONLY 1 QUESTION ASKED
	{

		randomize();
		for(int j=0;j<p;j++)
		{
			border();
			/////G////
			setcolor(BLUE);
			emptyg();

			delay(50);

			/////Main//////
			setcolor(WHITE);
			settextstyle(3,VERT_DIR,5);
			outtextxy(80,95,":: ROUND 2 ::");

			delay(200);
			setcolor(WHITE);
			settextstyle(3,VERT_DIR,5);
			outtextxy(500,263,"WGG");
			delay(50);

			delay(50);

			delay(50);
			setcolor(WHITE);
			settextstyle(3,HORIZ_DIR,5);
			outtextxy(105,382,"WORD GUESSING GAME");



			int q;
			q=random(50);
			char an[100];
			int answer;
			answer=strlen(ans[q]);
			strcpy(an,ans[q]);

			int answer2;
			if(answer<6)
			{
				answer2=answer-2;
			}
			else
			{
				answer2=answer;
			}
			randomize();

			for(int k=0;k<10;k++)
			{
				int c22=0;

				int sp;
				sp=random(answer);
				an[sp]='_';

				for(int t=0;t<answer;t++)
				{
					if(an[t]=='_')
					{
						c22++;
					}
				}
				if(c22==answer2)
				{
					break;
				}

			}

			delay(500);
			setcolor(5);
			settextstyle(2,HORIZ_DIR,7);
			outtextxy(108,35,"THIS QUESTION IS FOR :: ");
			setcolor(WHITE);
			char name1[10];
			strcpy(name1,newname[j]);
			delay(200);
			outtextxy(386,35,name1);

			///QUESTION STRING ADJUSTMENT///

			int quo=strlen(qu[q]);

			int c22=(quo/48)+1;
			int br1=0;
			int r1=7,c1=20,k1=48,c3=0;
			for(int q1=0;q1<c22;q1++)
			{
				c1=20;

				for(int q2=c3;q2<k1;q2++)
				{
					delay(20);

					if(qu[q][q2]=='\0')
					{
						br1=1;
						break;
					}
					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					gotoxy(c1,r1);
					cout<<qu[q][q2];
					c1++;
				}

				if(br1==1)
				{
					break;
				}
				q2=q2+48;
				c3=c3+48;
				k1=k1+48;
				r1++;
			}

			////TO SHOW ANSWER ///

			setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,8);
			outtextxy(355,195,an);



			////SPACE FILLING///
			for(int l=0;l<answer;l++)
			{
				if(an[l]=='_')
				{
					char answ;
					delay(50);
					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					outtextxy(160,252,"CHARACTER FOR SPACE :: ");
					gotoxy(49,17);
					cout<<l+1;

					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					outtextxy(410,252,":: ");
					gotoxy(53,17);


					int a=330,b=180,c=558,d=240;
					for(int jx=0;jx<5;jx++)
					{
						delay(50);
						rectangle(a,b,c,d);
						a=a+1;
						b=b+1;
						c=c-1;
						d=d-1;
					}
					setcolor(WHITE);
					settextstyle(2,HORIZ_DIR,8);
					outtextxy(355,195,an);
					delay(50);

					clock_t start=clock();

					while(!kbhit())
					{


						if(((clock()-start)/CLOCKS_PER_SEC)>=1)
						{
							an[l]='-';
							gotoxy(55,17);
							cout<<"TIMEOUT"<<endl;
							goto time;
						}
						timebar();

					}

					an[l]=getch();

					time:
					if(an[l]!='-')
					{
						gotoxy(55,17);
						setcolor(GREEN);
						settextstyle(2,HORIZ_DIR,6);
						cout<<an[l];
					}



				}


				////to hide previous answer///

				setcolor(BLACK);


				int a=330,b=180,c=558,d=240;
				for(int j7=0;j7<229;j7++)
				{
					rectangle(a,b,c,d);
					a=a+1;
				}

				setcolor(BLUE);

				a=330,b=180,c=558,d=240;
				for(j7=0;j7<5;j7++)
				{

					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				delay(50);
				setcolor(WHITE);
				settextstyle(2,HORIZ_DIR,8);
				outtextxy(355,195,an);
				///TO HIDE ENTERED NUMBER///
				delay(200);
				setcolor(BLACK);
				a=160,b=253,c=490,d=272;
				for(int j1=0;j1<331;j1++)
				{
					rectangle(a,b,c,d);
					a=a+1;
				}
			}


			delay(500);
			setcolor(CYAN);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(160,272,"YOU ENTERED :::: ");

			setcolor(GREEN);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(330,272,an);



			delay(1000);
			setcolor(6);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(160,302,"LET'S SEE YOUR LUCK");

			randomize();
			if(strcmpi(an,ans[q])==0)
			{
				randomize();
				delay(500);
				score[j]=score[j]+20;
				int ges;
				ges=random(10);
				delay(500);

				setcolor(GREEN);

				int a=330,b=180,c=558,d=240;
				for(int jx=0;jx<5;jx++)
				{
					delay(50);
					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}
				delay(50);

				setcolor(GREEN);
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(160,322,pos[ges]);

				delay(500);
				setcolor(CYAN);
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(155,342,"WELL ");
				setcolor(WHITE);
				outtextxy(215,342,name1);
				setcolor(CYAN);
				outtextxy(290,342," 20 MARKS CREDITED ");

			}


			else
			{
				randomize();
				delay(500);
				int ges;
				ges=random(6);

				///NEGATIVE REPLY///

				setcolor(RED);

				int a=330,b=180,c=558,d=240;
				for(int jx=0;jx<5;jx++)
				{
					delay(50);
					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				delay(50);
				setcolor(RED);

				settextstyle(2,HORIZ_DIR,6);
				outtextxy(160,322,neg[ges]);

				delay(500);
				setcolor(CYAN);

				settextstyle(2,HORIZ_DIR,6);
				outtextxy(155,342,"WELL ");
				setcolor(WHITE);
				outtextxy(205,342,name1);
				setcolor(CYAN);
				outtextxy(280,342," BETTER LUCK NEXT TIME ");
			}
			delay(500);

			setcolor(BLACK);
			int a=80,b=380,c=558,d=440;
			for(int j1=0;j1<479;j1++)
			{
				delay(1);
				rectangle(a,b,c,d);
				a=a+1;
			}
			delay(50);

			setcolor(BLUE);

			a=80,b=380,c=558,d=440;
			for(int j8=0;j8<5;j8++)
			{
				delay(50);
				rectangle(a,b,c,d);
				a=a+1;
				b=b+1;
				c=c-1;
				d=d-1;
			}

			delay(50);
			setcolor(WHITE);
			settextstyle(3,HORIZ_DIR,5);
			outtextxy(155,382,"THANKS  ");
			outtextxy(325,382,name1);

			delay(500);

		}

		delay(1000);

		setcolor(BLUE);

		int a=330,b=180,c=558,d=240;
		for(int jx=0;jx<5;jx++)
		{
			delay(50);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}

		setcolor(BLACK);
		a=80,b=380,c=558,d=440;
		for(int j1=0;j1<479;j1++)
		{
			delay(2);
			rectangle(a,b,c,d);
			a=a+1;
		}

		setcolor(BLUE);


		a=80,b=380,c=558,d=440;
		for(j1=0;j1<5;j1++)
		{
			delay(50);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}

		delay(50);

		delay(50);
		setcolor(WHITE);

		settextstyle(3,HORIZ_DIR,5);
		outtextxy(105,382,"WORD GUESSING GAME");
		delay(500);

		///LOADING////
		delay(200);
		setcolor(GREEN);

		a=80,b=450,c=82,d=455;
		for(j1=0;j1<477;j1++)
		{
			delay(10);
			rectangle(a,b,c,d);
			c=c+1;
		}

		delay(500);

		zoomin();

		cleardevice();

	}

	score1(newname,score,p);


}




void score1(char name[4][8],int score[4],int p)
{

	cleardevice();

	////scoreboard  loading///

	delay(50);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(1,140,"LOADING SCORE BOARD  :: ");

	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(1,164,"PLEASE WAIT ........... ");


	int a=1,b=200,c=2,d=240;
	for(int i=0;i<638;i++)
	{
		setcolor(WHITE);
		delay(3);
		rectangle(a,b,c,d);
		c++;

	}

	//////
	border();

	delay(500);
	setcolor(5);

	a=80,b=35,c=558,d=85;
	for(int j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(150,32,":: SCORE BOARD :: ");

	delay(500);
	setcolor(6);

	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,100,"LET's SEE SCORES ::: ");

	char tag[5][20];

	///tags based on performance
	strcpy(tag[0],"M.V.P");
	strcpy(tag[1],"TERMINATOR");
	strcpy(tag[2],"MASTER");
	strcpy(tag[3],"HELPLESS");
	int x1;

	int x=0;
	int u=0;
	for(int r=0;r<p;r++)  ///decides tags for players
	{

		if(score[r]==50)
		{
			x1=1;
		}
		else if(score[r]<10)
		{
			x1=3;
		}
		else if(score[r]>=10 && score[r]<30)
		{
			x1=2;
		}
		else if(score[r]>=30 && score[r]<50)
		{
			x1=0;
		}

		delay(500);
		/// rectangular blocks to hold player name, score and player tag received
		delay(200);
		setcolor(BLUE);
		a=80,b=130+x,c=250,d=169+x;
		for(int j=0;j<2;j++)
		{
			delay(200);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}
		delay(100);

		delay(200);
		setcolor(GREEN);
		int e=300,f=130+x,g=400,h=169+x;
		for(j=0;j<2;j++)
		{
			delay(200);
			rectangle(e,f,g,h);
			e=e+1;
			f=f+1;
			g=g-1;
			h=h-1;
		}

		delay(100);
		setcolor(CYAN);
		int k=420,l=130+x,m=558,n=169+x;
		for(int j1=0;j1<2;j1++)
		{
			delay(200);
			rectangle(k,l,m,n);
			k=k+1;
			l=l+1;
			m=m-1;
			n=n-1;
		}

		gotoxy(18,10+u);
		cout<<name[r];
		gotoxy(42,10+u);
		cout<<score[r]<<" /50";
		gotoxy(56,10+u);
		cout<<tag[x1];

		x=x+64;
		u=u+4;
	}

	delay(200);
	setcolor(BLUE);
	a=80,b=370,c=558,d=410;
	for(i=0;i<2;i++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);
	setcolor(BLUE);
	settextstyle(2,HORIZ_DIR,6);
	gotoxy(13,25);
	cout<<"WELL .... LET'S PROCEED FURTHER ";
	delay(100);

	delay(100);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,430,"Loading.....");
	delay(200);

	a=60,b=450,c=573,d=455;
	for(j=0;j<520;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(100);

	a=578,b=455,c=583,d=15;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(100);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(100);

	a=55,b=15,c=60,d=455;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b+1;
	}


	int npass=0; // holds how many players passed game or got more than 20 marks

	for(i=0;i<p;i++)
	{
		if(score[i]>=20)   //calculates number of players who passed
		{
			npass++;
		}
	}

	if(npass==0)//if no one passes
	{
		fail(name,p);
	}
	else
	{
		int tie=0,win=0;

		for(i=0;i<p;i++)
		{
			if(score[i]>=20)
			{
				if(score[i]>win)
				{
					win=score[i]; ///stores winner score
				}
			}
		}

		for(i=0;i<p;i++)
		{
			if(score[i]==win)
			{
				tie++;    ///calculates how many players got equal marks
			}

		}

		if(tie==1) //if marks of two players are not equal or only one winner is there
		{
			char winplayer[8];
			for(int i=0;i<p;i++)
			{
				if(score[i]==win)
				{
					strcpy(winplayer,name[i]); ///stores name of winner
				}
			}
			winner(winplayer);///winner function to congrat winner
		}
		else if(tie>1) ///if two or more got equal marks
		{
			char top[4][8]; ///stores name of players who got equal marks to send it ti tie breaker round
			int newscore[4];   ///stores scores
			int c11=0;//tores number of players who get equal marks

			for(i=0;i<p;i++)
			{
				if(score[i]==win) ///gets winners name
				{
					strcpy(top[c11],name[i]);
					newscore[c11]=score[i];
					c11++;
				}
			}

			tie_breaker(top,c11); ///players again compete to decide the real winner
		 }

	}
	delay(100);
	cleardevice();

}


int tie_instructions()
{
	border();
	setcolor(5);

	int a=80,b=35,c=558,d=85;
	for(int j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,4);
	outtextxy(120,40,"Tie- Breaker Instructions");

	delay(400);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,90,"Loading.....");
	delay(200);

	a=80,b=110,c=558,d=115;
	for(j=0;j<477;j++)
	{
		setcolor(j+1);
		delay(5);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(200);

	setcolor(CYAN);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,130,"1....EACH PLAYER WILL BE ASKED ONE -ONE QUESTION.");
	delay(50);


	delay(300);
	setcolor(5);
	outtextxy(80,160,"2....EACH QUESTION CONSISTS OF 50 MARKS.");

	delay(200);
	setcolor(CYAN);
	outtextxy(80,190,"3....OLD SCORES OF GAME WILL NOT BE CONSIDERED");

	delay(300);
	setcolor(5);
	outtextxy(80,220,"4....SO WE HAVE TOTAL 50 MARKS FOR EACH PLAYER. ");

	delay(300);
	setcolor(CYAN);
	outtextxy(80,250,"5....AFTER TIE-BREAKER,YOU CAN SEE YOUR SCORES.");

	delay(50);
	setcolor(CYAN);
	outtextxy(110,270,"PLAYER WITH MAXIMUM MARKS WINS THE GAME.");

	delay(300);
	setcolor(5);
	outtextxy(80,300,"4....THE ANSWER SHOULD BE GIVEN BY FILLING CORRECT");

	delay(50);
	setcolor(5);
	outtextxy(110,320,"LETTER AT RIGHT SPACE.");

	delay(400);
	setcolor(WHITE);
	outtextxy(80,350,"5....PLEASE DON'T PRESS UNNECESSARY KEYS.");

	delay(300);

	setcolor(5);

	a=80,b=380,c=558,d=430;
	for(j=0;j<3;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);
	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,5);
	outtextxy(120,375,"....BEST OF LUCK....");

	delay(100);
	setcolor(GREEN);
	a=80,b=450,c=82,d=455;
	for(j=0;j<477;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		c=c+1;
	}
	delay(100);
	zoomout();
	return(0);
}



void tie_breaker(char name[4][8],int p)
{
	border();
	delay(200);

	setcolor(BLUE);
	int a=80,b=20,c=558,d=80;
	for(int j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	delay(500);
	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(120,30,"WELCOME TO TIE-BREAKER");

	setcolor(6);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,100,"THESE ARE PLAYERS WHO SCORED EQUAL MARKS ::: ");


	int x=0,u=0;
	for(int r=0;r<p;r++)
	{
		delay(500);

		setcolor(GREEN);
		a=250,b=130+x,c=400,d=169+x;
		for(int j=0;j<2;j++)
		{
			delay(200);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}
		delay(100);


		delay(100);
		setcolor(BLUE);
		settextstyle(2,HORIZ_DIR,6);
		gotoxy(38,10+u);
		cout<<name[r];

		delay(100);
		setcolor(BLUE);

		x=x+64;
		u=u+4;
	}

	delay(200);
	setcolor(BLUE);
	a=80,b=370,c=558,d=410;
	for(int i=0;i<2;i++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);
	setcolor(BLUE);
	settextstyle(2,HORIZ_DIR,6);
	gotoxy(13,25);
	cout<<"OK.. Let's Proceed To Decide The Real Chicken Master ::: ";
	delay(100);

	delay(100);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,430,"Loading.....");
	delay(200);

	///progress bar
	a=60,b=450,c=573,d=455;
	for(j=0;j<520;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(100);

	a=578,b=455,c=583,d=15;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(100);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(100);

	a=55,b=15,c=60,d=455;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b+1;
	}
	//end of progress bar

	delay(100);

	/////Loading of tie breaker instructions////
	cleardevice();
	delay(50);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(1,140,"LOADING Tie - Breaker Instructios :: ");
	outtextxy(1,164,"PLEASE WAIT ........... ");

	a=1,b=200,c=2,d=240;
	for(i=0;i<638;i++)
	{
		setcolor(WHITE);
		delay(3);
		rectangle(a,b,c,d);
		c++;
	}

	delay(500);
	////tie breaker instructions///
	tie_instructions();

	/////LOADING TIE BREAKER ROUND/////
	cleardevice();

	delay(50);
	setcolor(WHITE);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(1,140,"LOADING Tie - Breaker Round  :: ");
	outtextxy(1,164,"PLEASE WAIT ........... ");

	a=1,b=200,c=2,d=240;
	for(i=0;i<638;i++)
	{
		setcolor(WHITE);
		delay(3);
		rectangle(a,b,c,d);
		c++;
	}
	int tiescore[4]={0,0,0,0};
	cleardevice();

	randomize();
	for(i=0;i<1;i++)
	{
		for(j=0;j<p;j++)
		{
			////LOADING///

			border();
			setcolor(BLUE);
			emptyg();
			delay(50);

			setcolor(WHITE);
			settextstyle(3,VERT_DIR,5);
			outtextxy(80,95,"TIE-BREAKER");

			delay(200);
			outtextxy(500,263,"WGG");
			delay(500);
			settextstyle(3,HORIZ_DIR,5);
			outtextxy(105,382,"WORD GUESSING GAME");

			////same as round 1
			int q;
			q=random(50);
			char an[100];
			int answer;
			answer=strlen(ans[q]);
			strcpy(an,ans[q]);

			int answer2;
			if(answer<6)
			{
				answer2=answer-2;
			}
			else
			{
				answer2=answer;
			}

			randomize();
			for(int k=0;k<10;k++)
			{
				int c222=0;
				int sp;

				sp=random(answer);
				an[sp]='_';

				for(int t=0;t<answer;t++)
				{
					if(an[t]=='_')
					{
						c222++;
					}
				}
				if(c222==answer2)
				{
					break;
				}

			}

			delay(500);
			setcolor(5);
			settextstyle(2,HORIZ_DIR,7);
			outtextxy(108,35,"THIS QUESTION IS FOR :: ");
			setcolor(WHITE);
			char name1[10];
			strcpy(name1,name[j]);
			delay(200);
			outtextxy(386,35,name1);

			///QUESTION STRING ADJUSTMENT///

			int quo=strlen(qu[q]);

			int c22=(quo/48)+1;
			int br1=0;
			int r1=7,c1=20,k1=48,c3=0;
			for(int q1=0;q1<c22;q1++)
			{
				c1=20;

				for(int q2=c3;q2<k1;q2++)
				{
					delay(20);

					if(qu[q][q2]=='\0')
					{
						br1=1;
						break;
					}
					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					gotoxy(c1,r1);
					cout<<qu[q][q2];
					c1++;
				}

				if(br1==1)
				{
					break;
				}
				q2=q2+48;
				c3=c3+48;
				k1=k1+48;
				r1++;
			}
			////TO SHOW ANSWER ///

			setcolor(WHITE);
			settextstyle(2,HORIZ_DIR,8);
			outtextxy(355,195,an);



			////SPACE FILLING///
			for(int l=0;l<answer;l++)
			{
				if(an[l]=='_')
				{
					char answ;
					delay(50);
					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					outtextxy(160,252,"CHARACTER FOR SPACE :: ");
					gotoxy(49,17);
					cout<<l+1;

					setcolor(CYAN);
					settextstyle(2,HORIZ_DIR,6);
					outtextxy(410,252,":: ");
					gotoxy(53,17);


					a=330,b=180,c=558,d=240;
					for(int jx=0;jx<5;jx++)
					{
						delay(50);
						rectangle(a,b,c,d);
						a=a+1;
						b=b+1;
						c=c-1;
						d=d-1;
					}
					setcolor(WHITE);
					settextstyle(2,HORIZ_DIR,8);
					outtextxy(355,195,an);
					delay(50);

					clock_t start=clock();

					while(!kbhit())
					{


						if(((clock()-start)/CLOCKS_PER_SEC)>=1)
						{
							an[l]='-';
							gotoxy(55,17);
							cout<<"TIMEOUT"<<endl;
							goto time;
						}
						timebar();

					}

					an[l]=getch();

					time:
					if(an[l]!='-')
					{
						gotoxy(55,17);
						setcolor(GREEN);
						settextstyle(2,HORIZ_DIR,6);
						cout<<an[l];
					}



				}


				////to hide previous answer///

				setcolor(BLACK);


				a=330,b=180,c=558,d=240;
				for(int j7=0;j7<229;j7++)
				{
					rectangle(a,b,c,d);
					a=a+1;
				}

				setcolor(BLUE);

				a=330,b=180,c=558,d=240;
				for(j7=0;j7<5;j7++)
				{

					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				delay(50);
				setcolor(WHITE);
				settextstyle(2,HORIZ_DIR,8);
				outtextxy(355,195,an);
				///TO HIDE ENTERED NUMBER///
				delay(200);
				setcolor(BLACK);
				a=160,b=253,c=490,d=272;
				for(int j1=0;j1<331;j1++)
				{
					rectangle(a,b,c,d);
					a=a+1;
				}
			}


			delay(500);
			setcolor(CYAN);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(160,272,"YOU ENTERED :::: ");

			setcolor(GREEN);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(330,272,an);



			delay(1000);
			setcolor(6);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(160,302,"LET'S SEE YOUR LUCK");

			randomize();
			if(strcmpi(an,ans[q])==0)
			{

				delay(500);
				tiescore[j]=tiescore[j]+10;
				int ges;
				ges=random(10);
				delay(500);

				setcolor(GREEN);

				a=330,b=180,c=558,d=240;
				for(int jx=0;jx<5;jx++)
				{
					delay(50);
					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				delay(100);
				setcolor(GREEN);
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(160,322,pos[ges]);

				delay(500);
				setcolor(CYAN);
				settextstyle(2,HORIZ_DIR,6);
				outtextxy(155,342,"WELL ");
				setcolor(WHITE);
				outtextxy(215,342,name1);
				setcolor(CYAN);
				outtextxy(290,342," 50 MARKS CREDITED ");

			}
			else
			{

				delay(500);
				int ges;
				ges=random(6);

				///NEGATIVE REPLY///

				setcolor(RED);

				a=330,b=180,c=558,d=240;
				for(int jx=0;jx<5;jx++)
				{
					delay(50);
					rectangle(a,b,c,d);
					a=a+1;
					b=b+1;
					c=c-1;
					d=d-1;
				}

				delay(100);
				setcolor(RED);

				settextstyle(2,HORIZ_DIR,6);
				outtextxy(160,322,neg[ges]);

				delay(500);
				setcolor(CYAN);

				settextstyle(2,HORIZ_DIR,6);
				outtextxy(155,342,"WELL ");
				setcolor(WHITE);
				outtextxy(205,342,name1);
				setcolor(CYAN);
				outtextxy(280,342," BETTER SPECTATE");
			}
			delay(500);

			setcolor(BLACK);
			a=80,b=380,c=558,d=440;
			for(int j1=0;j1<479;j1++)
			{
				delay(1);
				rectangle(a,b,c,d);
				a=a+1;
			}
			delay(50);

			setcolor(BLUE);

			a=80,b=380,c=558,d=440;
			for(int j8=0;j8<5;j8++)
			{
				delay(50);
				rectangle(a,b,c,d);
				a=a+1;
				b=b+1;
				c=c-1;
				d=d-1;
			}

			delay(50);
			setcolor(WHITE);
			settextstyle(3,HORIZ_DIR,5);
			outtextxy(155,382,"THANKS  ");
			outtextxy(325,382,name1);

			delay(1000);



		 }
	}

	delay(50);

	setcolor(BLUE);

	a=330,b=180,c=558,d=240;
	for(int jx=0;jx<5;jx++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}

	zoomin();

	cleardevice();

	 int win=0,tiecount=0;
	 char winname[15];
	 char winplayers[4][10];

	 for(i=0;i<p;i++)
	 {
		if(tiescore[i]>win)
		{
			win=tiescore[i];    ///calculates winner score
		}
	 }
	 for(i=0;i<p;i++)
	 {
		if(tiescore[i]==win)
		{
			strcpy(winplayers[tiecount],name[i]);
			strcpy(winname,name[i]);
			tiecount++;     ///if more than one player gets equal marks
		}
	 }

	 if(tiecount==1)
	 {
		winner(winname);   ///if only one winner is there
	 }
	 else
	 {
		tie_equal(winplayers,tiecount);
	 }




}

void winner(char winplayer[10])
{

	border();
	strupr(winplayer);

	delay(300);

	setcolor(BLUE);
	int a=80,b=20,c=558,d=80;
	for(int j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(500);
	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,5);
	outtextxy(100,23,"WORD GUESSING GAME");

	setcolor(5);
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(100,80,"SO,HERE IS THE LUCKY....");
	outtextxy(280,110,"....WINNER OF THE GAME ");



	setcolor(6);
	settextstyle(3,HORIZ_DIR,5);
	outtextxy(215,195,winplayer);

	///to enclose winner name in box

	setcolor(WHITE);
	a=180,b=250,c=181,d=255;
	for(j=0;j<241;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		c=c+1;
	}
	setcolor(WHITE);
	a=420,b=255,c=425,d=254;
	for(j=0;j<56;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		d=d-1;
	}
	setcolor(WHITE);
	a=180,b=200,c=425,d=195;
	for(j=0;j<246;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		c=c-1;
	}
	setcolor(WHITE);
	a=180,b=200,c=185,d=201;
	for(j=0;j<56;j++)
	{
		delay(5);
		rectangle(a,b,c,d);
		b=b+1;
	}

	setcolor(GREEN);
	settextstyle(3,HORIZ_DIR,5);
	outtextxy(120,280,"WINNER.....");
	delay(500);
	outtextxy(300,310,".....WINNER");
	delay(500);
	setcolor(RED);
	outtextxy(120,350,"CHICKEN.....");
	delay(500);
	outtextxy(300,380,".....DINNER");
	delay(500);

	delay(100);
	setcolor(BLUE);
	a=80,b=450,c=82,d=455;
	for(j=0;j<477;j++)
	{
		delay(7);
		rectangle(a,b,c,d);
		c=c+1;
	}

	delay(1000);
	exit(0);


}

void tie_equal(char name[][10],int p)    ///if more than one player gets equla marks in tie breaker round
{

	border();
	delay(200);
	setcolor(BLUE);

	rectangle(80,20,558,80);
	int a=80,b=20,c=558,d=80;
	for(int j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(500);
	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(120,30,"..TIE-BREAKER RESULT..");

	setcolor(6);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,100,"THESE PLAYERS ARE TERMINATORS ::: ");


	int x=0,u=0;
	for(int r=0;r<p;r++)
	{
		delay(500);

		setcolor(GREEN);
		a=250,b=130+x,c=400,d=169+x;
		for(int j=0;j<2;j++)
		{
			delay(200);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}
		delay(100);


		delay(100);
		setcolor(BLUE);
		settextstyle(2,HORIZ_DIR,6);
		gotoxy(38,10+u);
		cout<<name[r];

		delay(100);
		setcolor(BLUE);

		x=x+64;
		u=u+4;
	}

	delay(200);
	setcolor(BLUE);
	a=80,b=370,c=558,d=410;
	for(int i=0;i<2;i++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);
	setcolor(BLUE);
	settextstyle(2,HORIZ_DIR,6);
	gotoxy(13,25);
	cout<<":: WINNER WINNNER CHICKEN DINNER ::";
	delay(100);

	delay(100);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,430,"Loading.....");
	delay(200);

	a=60,b=450,c=573,d=455;
	for(j=0;j<520;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(100);

	a=578,b=455,c=583,d=15;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(100);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(100);

	a=55,b=15,c=60,d=455;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b+1;
	}

	delay(100);
	exit(0);
	getch();
}

void fail(char name[][8],int p)
{

	cleardevice();
	border();

	delay(200);

	setcolor(BLUE);

	rectangle(80,20,558,80);
	int a=80,b=20,c=558,d=80;
	for(int j=0;j<5;j++)
	{
		delay(50);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(200);
	delay(500);
	setcolor(WHITE);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(120,30,"....::: GAME  RESULT :::....");

	setcolor(6);
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(80,100,"THESE ARE PLAYERS WHO WERE NOT ABLE TO PASS::: ");


	int x=0,u=0;
	for(int r=0;r<p;r++)
	{
		delay(500);

		setcolor(GREEN);
		a=250,b=130+x,c=400,d=169+x;
		for(int j=0;j<2;j++)
		{
			delay(200);
			rectangle(a,b,c,d);
			a=a+1;
			b=b+1;
			c=c-1;
			d=d-1;
		}
		delay(100);


		delay(100);
		setcolor(BLUE);
		settextstyle(2,HORIZ_DIR,6);
		gotoxy(38,10+u);
		cout<<name[r];

		delay(100);
		setcolor(BLUE);

		x=x+64;
		u=u+4;
	}

	delay(200);
	setcolor(BLUE);
	a=80,b=370,c=558,d=410;
	for(int i=0;i<2;i++)
	{
		delay(200);
		rectangle(a,b,c,d);
		a=a+1;
		b=b+1;
		c=c-1;
		d=d-1;
	}
	delay(100);
	setcolor(BLUE);
	settextstyle(2,HORIZ_DIR,6);
	gotoxy(13,25);
	cout<<"...SEE YOU NEXT TIME ::::::::";
	delay(100);

	delay(100);

	setcolor(WHITE);
	delay(100);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(85,430,"Loading.....");
	delay(200);

	a=60,b=450,c=573,d=455;
	for(j=0;j<520;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a+1;
	}

	delay(100);

	a=578,b=455,c=583,d=15;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b-1;
	}

	delay(100);

	a=578,b=20,c=60,d=15;
	for(j=0;j<519;j++)
	{
		setcolor(CYAN);
		delay(2);
		rectangle(a,b,c,d);
		a=a-1;
	}

	delay(100);

	a=55,b=15,c=60,d=455;
	for(j=0;j<441;j++)
	{
		setcolor(6);
		delay(2);
		rectangle(a,b,c,d);
		b=b+1;
	}

	delay(100);
	exit(0);
	getch();
}





