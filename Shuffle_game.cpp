#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <windows.h>

using namespace std;

int coxy[16][6],alpha;// COXY Storing co-ordinates.
//--------------------------------------------- Hard Problem Set ---------------------------------------------------------------------------------------
char h1[16][3] = {"07","15","01","06","09","11","13","04","14","03","08","02","05","10","12",""};
char h2[16][3] = {"08","15","02","06","09","11","13","04","14","03","07","01","05","10","12",""};
char h3[16][3] = {"09","15","01","06","07","11","13","04","14","03","08","02","05","10","12",""};
char h4[16][3] = {"10","15","01","06","09","11","13","04","14","03","08","02","05","07","12",""};
char h5[16][3] = {"11","15","01","06","09","07","13","04","14","03","08","02","05","10","12",""};
char h6[16][3] = {"12","15","01","06","09","11","13","04","14","03","08","02","05","10","07",""};
int hard = 0;//Getting The Problem to display for HARD
//-----------------------------------------------Easy Problem Set ----------------------------------------------------------------------------------------
char e1[16][3] = {"01","02","03","04","05","06","07","08","09","10","15","11","13","14","12",""};
char e2[16][3] = {"01","02","15","04","05","06","07","08","09","10","03","11","13","14","12",""};
char e3[16][3] = {"01","02","03","04","05","06","07","08","09","10","13","11","15","12","14",""};
char e4[16][3] = {"01","02","15","04","05","06","07","08","10","09","03","11","14","13","12",""};
int esy = 0;//Getting The Problem to display for EASY
//----------------------------------------------- Intermediate Problem Set -------------------------------------------------------------------------------
char intm1[16][3] = {"06","02","15","04","05","01","12","08","09","10","03","11","13","14","07",""};
char intm2[16][3] = {"01","12","15","04","05","06","07","08","09","10","03","11","13","14","02",""};
char intm3[16][3] = {"04","02","15","01","05","06","03","08","09","10","07","11","13","14","12",""};
char intm4[16][3] = {"03","02","08","04","05","06","07","15","09","10","01","11","13","14","12",""};
char intm5[16][3] = {"05","02","15","04","01","06","07","08","03","10","09","13","11","12","14",""};
char intm6[16][3] = {"07","15","01","12","09","11","13","04","14","03","08","02","05","10","06",""};
char intm7[16][3] = {"12","15","01","06","09","11","13","04","14","03","08","02","05","10","07",""};
char intm8[16][3] = {"07","15","01","06","09","11","13","04","14","03","12","02","05","10","08",""};
char intm9[16][3] = {"07","15","01","06","12","11","13","04","14","03","08","02","05","10","09",""};
char intm10[16][3] = {"07","15","01","06","09","11","13","04","14","03","08","02","05","12","10",""};
int intm = 0;//Getting The Problem to display for INTERMEDIATE
//------------------------------------------------ Primary Variable --------------------------------------------------------------------------------------
char d[16][3] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","","15"};
char dcmp[16][3] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15",""};//Ideal Arrangement
int cp =16 ;//denoting CURRENT POSITION
//////////////////////////////////////////// FILTERING VALID MOVES //////////////////////////////////////////////////////////////////////////////////////
int validmove(char c)
{
    if((cp==1)&&((toupper(c)=='W')||(toupper(c)=='A')))
        return 0;
    else if((cp==2)&&(toupper(c)=='W'))
        return 0;
    else if((cp==3)&&(toupper(c)=='W'))
        return 0;
    else if((cp==4)&&((toupper(c)=='W')||(toupper(c)=='D')))
        return 0;
    else if((cp==5)&&(toupper(c)=='A'))
        return 0;
    else if((cp==9)&&(toupper(c)=='A'))
        return 0;
    else if((cp==13)&&((toupper(c)=='S')||(toupper(c)=='A')))
        return 0;
    else if((cp==16)&&((toupper(c)=='S')||(toupper(c)=='D')))
        return 0;
    else if((cp==14)&&(toupper(c)=='S'))
        return 0;
    else if((cp==15)&&(toupper(c)=='S'))
        return 0;
    else if((cp==8)&&(toupper(c)=='D'))
        return 0;
    else if((cp==12)&&(toupper(c)=='D'))
        return 0;
    else if((toupper(c)=='R')||(toupper(c)=='Z')||(toupper(c)=='X')||(toupper(c)=='Y')||(toupper(c)=='W')||(toupper(c)=='A')||(toupper(c)=='S')||(toupper(c)=='D'))
        return 1;
    else
        return 0;
}
//////////////////////////////////////////////////////// COPY 2-D STRING ///////////////////////////////////////////////////////////////////////////
void strcopy(char a[16][3], char b[16][3])
{
    int i;
    for(i=0; i<16; i++)
        strcpy(a[i],b[i]);
}
//////////////////////////////////////////////////////// CHECKING WIN //////////////////////////////////////////////////////////////////////////////
int chkwn()
{
    int c=0;
    int i;
    for(i=0; i<16; i++)
        if(strcmp(d[i],dcmp[i])==0)
            c++;

    if(c==16)
        return 1;
    else return 0;

}
//////////////////////////////////////////////////////// SWAP //////////////////////////////////////////////////////////////////////////////

void rplc(int a, int b)
{
    char c[3];
    strcpy(c,d[a-1]);
    strcpy(d[a-1],d[b-1]);
    strcpy(d[b-1],c);
    cp = b;
}

void swap(char ch)
{
    if(toupper(ch)=='W')
        rplc(cp,cp-4);
    if(toupper(ch)=='S')
        rplc(cp,cp+4);
    if(toupper(ch)=='A')
        rplc(cp,cp-1);
    if(toupper(ch)=='D')
        rplc(cp,cp+1);
}
//////////////////////////////////////////////////////// INPUT CHECK //////////////////////////////////////////////////////////////////////////////

void checkinput(char c)
{
    if((toupper(c)=='W')||(toupper(c)=='S')||(toupper(c)=='A')||(toupper(c)=='D'))
        swap(c);
}

//////////////////////////////////////////////////////// MAIN //////////////////////////////////////////////////////////////////////////////

int main()
{
    int gd = DETECT,gm,i,j,k,t,o,x=0,xx,y;
    initgraph(&gd,&gm, "C:\\TC\\BGI");

    xx=getmaxx()/2;
    y=getmaxy()/2;
    settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
    setbkcolor(LIGHTCYAN);
    setcolor(4);
    int c=150;// Initial circle size
// -------------------------------------------------------------LOADING SCREEN-----------------------------------------------------------------

    for(int e=0;e<20;e++) //Change 20 to your desired value
    {
        for(int i=50;i<100;i++)
        {
            setcolor(0);
            settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
            outtextxy(xx/4,(y/3),"Welcome To The Shuffle Game");
            outtextxy(xx,y,"Loading...");
            circle(xx,y,i);// producing CIRCLE Animation
            circle(xx,y,c);
            c--;
            cleardevice();
        }
    }
// -------------------------------------------------------------MAIN MENU-----------------------------------------------------------------
    char ures=0;// Taking USER RESPONSE
    while(ures!='3')
    {
        outtextxy(xx/4,(y/3),"Hello Gamer! Make your choice");
        outtextxy(xx/4,(y/3 + 40),"1. Read The Instructions");
        outtextxy(xx/4,(y/3 + 80),"2. Read The Controls ");
        outtextxy(xx/4,y/3+ 120 ,"3. Start the game");
        char main_menu=getche();
        if(main_menu=='1')// Displaying RULES
        {
            cleardevice();
            settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
            outtextxy(xx/4,y/3,"The Instruction are as follows : ");
            outtextxy(xx/4-43,y/3+40,"1. Your aim is to arrange boxes with numbers");
            outtextxy(xx/4-43,y/3+80," at their respective indexes");
            outtextxy(xx/4-43,y/3+120,"2. You can swap the blank tile with adjacent");
            outtextxy(xx/4-43,y/3+160,"   tile");
            outtextxy(xx/4-43,y/3+200,"3. The tile at its correct index would be ");
            outtextxy(xx/4-43,y/3+240,"   displayed in Green");
            outtextxy(xx/4-43,y/3+300,"To Return To the Main Menu, Press 1");
            outtextxy(xx/4-43,y/3 +340,"To Start the game, Press 3");
            int i7=1;
            while(i7)   // Checking VALID MOVE
            {
                ures=getche();
                if((ures=='1')||(ures=='3'))
                    i7 = 0;
            }
            settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
        }

        else if(main_menu=='2')// Displaying CONTROLS
        {
            cleardevice();
            settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
            outtextxy(xx/4,y/3-40,"The Controls are as follows : ");
            outtextxy(xx/4-43,y/3,"1. Press W to swap blank tile with the ");
            outtextxy(xx/4-43,y/3+40," tile just above it.");
            outtextxy(xx/4-43,y/3+80,"2. Press A to swap blank tile with the ");
            outtextxy(xx/4-43,y/3+120,"   tile just left to it.");
            outtextxy(xx/4-43,y/3+160,"3. Press S to swap blank tile with the  ");
            outtextxy(xx/4-43,y/3+200,"   tile just below it.");
            outtextxy(xx/4-43,y/3+240,"3. Press D to swap blank tile with the  ");
            outtextxy(xx/4-43,y/3+280,"   tile just right to it.");
            outtextxy(xx/4-43,y/3+340,"To Return To the Main Menu, Press 1");
            outtextxy(xx/4-43,y/3 +380,"To Start the game, Press 3");
            int i7=1;
            while(i7)// Checking VALID MOVE
            {
                ures=getche();
                if((ures=='1')||(ures=='3'))
                    i7 = 0;
            }
            settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
        }
        else if(main_menu=='3')// Proceeding to GAME
            break;
        else// Toast message of INVALID INPUT
        {
            outtextxy(xx/4-43,y/3+200,"Invalid Input. Please Try Again.");
            delay(2000);
        }

      cleardevice();
    }
//------------------------------------------------------LEVEL MENU----------------------------------------------------------------------

    char level;// Storing CURRENT LEVEL
    int checkint=1;// Integer used for counter in checking correct input
    while(checkint)
    {
        cleardevice();
        settextstyle(BOLD_FONT, HORIZ_DIR, 2);// Level Display with score points
        outtextxy(xx/4,y/3-10,"Choose The Level, You want to Play : ");
        outtextxy(xx/4-43,y/3+40,"1. BEGINNER    (Under 999 Moves)");
        outtextxy(xx/4-63,y/3+80,"   Points for each Green tile (at end of Game) = 10");
        outtextxy(xx/4-43,y/3+120,"2. INTERMEDIATE     (Under 450 Moves)");
        outtextxy(xx/4-63,y/3+160,"   Points for each Green tile (at end of Game) = 20");
        outtextxy(xx/4-43,y/3+200,"3. ADVANCED       (Under 200 Moves) ");
        outtextxy(xx/4-63,y/3+240,"   Points for each Green tile (at end of Game) = 30");

        level=getche();
        if((level=='1')||(level=='2')||(level=='3'))
            checkint=0;
        else
        {
            cleardevice();
            setcolor(RED);  // DISPLAYING input message in RED
            outtextxy(xx/4-43,y/3+100,"    Invalid Input. Please Try Again.");
            setcolor(BLACK);
            delay(2000);
        }

    }
//LEVEL INPUT
//--------------------------------------------------SETTING DISPLAY PROBLEM-------------------------------------------------------------------
    if((level == '1')&&(esy==0))        // Assigning Default Problem
        strcopy(d,e1);
    if((level == '2')&&(intm==0))
        strcopy(d,intm1);
    if((level == '3')&&(hard==0))
        strcopy(d,h1);

    setcolor(BLACK);
    settextstyle(BOLD_FONT, HORIZ_DIR,2 );
    cleardevice();
    setbkcolor(WHITE);

    char *p = d[0];
    char a[4] = {'0','0','0'};
    char strmv[100],undo[100];
// -------------------------------------------------------------PRINTING FIRST DISPLAY-----------------------------------------------------------------

    cleardevice();
    outtextxy(xx/4-43,y/3+300,"To REFRESH , Press R           To UNDO, Press Z");   // Available user menu
    outtextxy(xx/4-43,y/3 +340,"To EXIT, Press X               To REDO, Press Y");

    for(int temp7=0,j=0,k=0,t=0; j<4; j++,t++,k=0)
    for(i=0; i<4; i++,temp7++)
    {

        setbkcolor(WHITE);
        if(strcmp(p,"")==0)
           setfillstyle(SOLID_FILL,DARKGRAY);//Displaying blank tile in dark-gray.
        else if(strcmp(dcmp[temp7],d[temp7])==0)
            setfillstyle(SOLID_FILL,GREEN);//Displaying correct tile in green
        else
            setfillstyle(SOLID_FILL,YELLOW);//Displaying incorrect in yellow
        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
        coxy[k-1][0] = 169+(65*i)+k;        // text x
        coxy[k-1][1] = 105+(65*j)+t;        // text y
        coxy[k-1][2] = 140+(65*i)+k;        // box start x
        coxy[k-1][3] = 75+(65*j)+t;         // box start y
        coxy[k-1][4] = 205+(65*i)+k;        // box end x
        coxy[k-1][5] = 140+(65*j)+t;        // box end y
        k++;
        p+=3;
    }

//------------------------------------------------------------ GAME STARTS HERE -------------------------------------------------------------------------
    for(o=0; o<5000; o++)
    {

//------------------------------------------------------------------- MOVES Counter---------------------------------------------------------------------
            outtextxy(230,25,"MOVES");
            if(a[2]=='9')// Move incrementation
            {
                outtextxy(300,25,a);
                a[2]='0';

                if(a[1]=='9')
                {
                    a[1]='0';
                    a[0]++;
                }

                else
                    a[1]++;
            }

            else
            {
                outtextxy(300,25,a);
                a[2]++;
            }

        char c1;//Input character
        checkint=1;
        while(checkint)// Using checkint for our move checking counter
        {
            c1 = getche();
            if(validmove(c1)==1)
                checkint=0;
            else
            {
                setcolor(RED);// Providing red color to message
                outtextxy(xx/4-43,y/3+126,"   Invalid Input. Please Try Again.");
                outtextxy(xx/4-43,y/3+100,"");
                setcolor(BLACK);
            }
        }

//------------------------------------------------------------ CHECKING MOVES , WIN AND LOSE ------------------------------------------------------------
        if(level == '1')
        {
            if(a[0]=='9'&&a[1]=='9'&&a[2]=='9')//LIMITING MOVES IN BEGINNERS
            {
                cleardevice();
                outtextxy(169,105, "Sorry YOU Lose!");  // Losing message
                outtextxy(169,165, "Press R to Try Again");
                outtextxy(169,205, "Press X to Exit");

                int cnt11=0; // calculating score based on number of correctly positioned tiles
                for(int i=0; i<16; i++)
                {
                    if(strcmp(dcmp[i],d[i])==0)
                        cnt11+=10;
                }

                char c[4];
                c[3] = '\0';

                for(int i=0; i<3; i++)
                {
                    c[2-i] = cnt11%10 + 48;// converting integer to suitable ASCII value
                    cnt11= (cnt11-cnt11%10)/10;
                }

                outtextxy(169,285,"Your score is");// Outputting score
                outtextxy(349,285,c);
                checkint=1;
                while(checkint)// Input checking for exit and refresh
                {
                  c1 = getche();
                  if((toupper(c1)=='X')||(toupper(c1)=='R'))
                        checkint=0;
                  else
                  {
                    setcolor(RED);
                    outtextxy(xx/4-43,y/3+226,"     Invalid Input. Please Try Again.");
                    setcolor(BLACK);
                  }
                }
            }
        }

        else if(level == '2')
        {
            if(a[0]=='4'&&a[1]=='5'&&a[2]=='0')//LIMITING SCORES IN INTERMEDIATE
            {
                cleardevice();
                outtextxy(169,105, "Sorry YOU Lose!");
                outtextxy(169,165, "Press R to Try Again");
                outtextxy(169,205, "Press X to Exit");

                int cnt11=0;
                for(int i=0; i<16; i++)// Calculating Score
                {
                    if(strcmp(dcmp[i],d[i])==0)
                        cnt11+=20;
                }

                char c[4];
                c[3] = '\0';

                for(int i=0; i<3; i++)
                {
                    c[2-i] = cnt11%10 + 48;
                    cnt11= (cnt11-cnt11%10)/10;
                }

                outtextxy(169,285,"Your score is");
                outtextxy(349,285,c);
                checkint=1;
                while(checkint)
                {
                  c1 = getche();
                  if((toupper(c1)=='X')||(toupper(c1)=='R'))
                        checkint=0;
                  else
                  {
                    setcolor(RED);
                    outtextxy(xx/4-43,y/3+226,"     Invalid Input. Please Try Again.");
                    setcolor(BLACK);
                  }
                }

            }
        }

        else if(level == '3')
        {
            if((a[0]=='2')&&(a[1]=='0')&&(a[2]=='0'))// LIMITING SCORES IN ADVANCED
            {
                cleardevice();
                outtextxy(169,105, "Sorry YOU Lose!");
                outtextxy(169,165, "Press R to Try Again");
                outtextxy(169,205, "Press X to Exit");

                int cnt11=0;
                for(int i=0; i<16; i++)
                {
                    if(strcmp(dcmp[i],d[i])==0)
                        cnt11+=30;
                }

                char c[4];
                c[3] = '\0';

                for(int i=0; i<3; i++)
                {
                    c[2-i] = cnt11%10 + 48;
                    cnt11= (cnt11-cnt11%10)/10;
                }

                outtextxy(169,285,"Your score is");
                outtextxy(349,285,c);
                checkint=1;
                while(checkint)
                {
                  c1 = getche();
                  if((toupper(c1)=='X')||(toupper(c1)=='R'))
                        checkint=0;
                  else
                  {
                    setcolor(RED);
                    outtextxy(xx/4-43,y/3+226,"     Invalid Input. Please Try Again.");
                    setcolor(BLACK);
                  }
                }
            }
        }

//----------------------------------------------------------------- EXIT ---------------------------------------------------------------------------------
        if((toupper(c1))=='X')
            break;
//----------------------------------------------------------------- UNDO ---------------------------------------------------------------------------------
        if((toupper(c1)=='Z')&&(o>0))
        {
            undo[x] = strmv[o-1];
            x++;

            if((a[2]=='0')&&(a[1]=='0')&&(a[0]!='0'))
            {
                a[1]='9';
                a[2]='9';
                a[0]--;
            }
            else if ((a[2]=='0')&&(a[1]!='0'))
            {
                a[2]='9';
                a[1]--;
            }
            else
                a[2]--;

            if((a[2]=='0')&&(a[1]=='0')&&(a[0]!='0'))
            {
                a[1]='9';
                a[2]='9';
                a[0]--;
            }
            else if ((a[2]=='0')&&(a[1]!='0'))
            {
                a[2]='9';
                a[1]--;
            }
            else
                a[2]--;

            if(toupper(strmv[o-1])=='W')
                swap('S');//rplc(cp,cp+4);
            else if(toupper(strmv[o-1])=='S')
                swap('W');//rplc(cp,cp-4);
            else if(toupper(strmv[o-1])=='A')
                swap('D');//rplc(cp,cp+1);
            else if(toupper(strmv[o-1])=='D')
                swap('A');//rplc(cp,cp-1);

            p = d[0];
            outtextxy(xx/4-43,y/3+300,"To REFRESH , Press R           To UNDO, Press Z");
            outtextxy(xx/4-43,y/3 +340,"To EXIT, Press X               To REDO, Press Y");

            for(j=0,k=0,t=0,alpha=0; j<4; j++,t++,k=0)
            for(i=0; i<4; i++)
            {
                if(strcmp(dcmp[alpha],d[alpha])==0)
                {
                    if(strcmp(d[alpha],"")==0)
                    {
                        setfillstyle(SOLID_FILL,DARKGRAY);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                    else
                    {
                        setfillstyle(SOLID_FILL,GREEN);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                }

                else
                {
                    if(strcmp(d[alpha],"")==0)
                    {
                        setfillstyle(SOLID_FILL,DARKGRAY);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                    else
                    {
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                }

                k++;
                alpha++;
                p+=3;
            }

            o-=2;
        }

        else
        {
//--------------------------------------------------------------------- REDO ------------------------------------------------------------------------------
            if(toupper(c1)=='Y')
                c1 = strmv[o];
            else
                strmv[o]=c1;
//--------------------------------------------------------------------- REFRESH ------------------------------------------------------------------------------

            if(toupper(c1)=='R')
            {
                closegraph();
                cp =16 ;

                if(level == '1')
                {
                    hard=0;
                    esy++;
                    intm = 0;

                    if(esy>3)
                        esy=0;

                    if(esy==0)
                        strcopy(d,e1);
                    else if(esy==1)
                        strcopy(d,e2);
                    else if(esy==2)
                        strcopy(d,e3);
                    else if(esy==3)
                        strcopy(d,e4);
                }

                else if(level == '2')
                {
                    hard=0;
                    esy=0;
                    intm++;
                    if(intm>10)
                        intm=0;

                    if(intm==0)
                        strcopy(d,intm1);
                    else if(intm==1)
                        strcopy(d,intm2);
                    else if(intm==2)
                        strcopy(d,intm3);
                    else if(intm==3)
                        strcopy(d,intm4);
                    else if(intm==4)
                        strcopy(d,intm5);
                    else if(intm==5)
                        strcopy(d,intm6);
                    else if(intm==6)
                        strcopy(d,intm7);
                    else if(intm==7)
                        strcopy(d,intm8);
                    else if(intm==8)
                        strcopy(d,intm9);
                    else if(intm==9)
                        strcopy(d,intm10);
                }

                else if(level == '3')
                {
                    hard++;
                    esy=0;
                    intm = 0;

                    if(hard>6)
                        hard=0;

                    if(hard==0)
                        strcopy(d,h1);
                    else if(hard==1)
                        strcopy(d,h2);
                    else if(hard==2)
                        strcopy(d,h3);
                    else if(hard==3)
                        strcopy(d,h4);
                    else if(hard==4)
                        strcopy(d,h5);
                    else if(hard==5)
                        strcopy(d,h6);
                }
                main();
            }

//-------------------------------------------------- DISPLAY GAME ------------------------------------------------------------------------------

            checkinput(c1);
            cleardevice();

            p = d[0];
            int k2;
            int temp = chkwn();
            outtextxy(xx/4-43,y/3+300,"To REFRESH , Press R           To UNDO, Press Z");
            outtextxy(xx/4-43,y/3 +340,"To EXIT, Press X               To REDO, Press Y");
            for(j=0,k=0,t=0,alpha=0; j<4; j++,t++,k=0)
            for(i=0; i<4; i++)
            {
                if(strcmp(dcmp[alpha],d[alpha])==0)
                {
                    if(strcmp(d[alpha],"")==0)
                    {
                        setfillstyle(SOLID_FILL,DARKGRAY);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                    else
                    {
                        setfillstyle(SOLID_FILL,GREEN);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                }

                else
                {
                    if(strcmp(d[alpha],"")==0)
                    {
                        setfillstyle(SOLID_FILL,DARKGRAY);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                    else
                    {
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(140+(65*i)+k,75+(65*j)+t,205+(65*i)+k,140+(65*j)+t);
                        setcolor(BLACK);
                        outtextxy(169+(65*i)+k,105+(65*j)+t,p);
                    }
                }
                k++;
                alpha++;
                p+=3;
            }

            k2 = chkwn();
            if( k2 == 1 )
            {

                cleardevice();
                outtextxy(169,105,"CONGRATULATIONS YOU WIN");
                cout<<"\a";
                outtextxy(140, 165, "Press X to EXIT ");
                outtextxy(140, 205, "Press R to RESTART");

                char c2;
                checkint=1;
                while(checkint)
                {
                  c2 = getche();
                  if((toupper(c2)=='X')||(toupper(c2)=='R'))
                        checkint=0;
                  else
                  {
                    setcolor(RED);
                    outtextxy(xx/4-43,y/3+246,"     Invalid Input. Please Try Again.");
                    setcolor(BLACK);
                  }
                }
                if(toupper(c2)=='X')
                    break;
                else if(toupper(c2)=='R')
                {
                    closegraph();
                    cp =16 ;

                    if(level == '1')
                    {
                        hard=0;
                        esy++;
                        intm = 0;

                        if(esy>3)
                            esy=0;

                        if(esy==0)
                            strcopy(d,e1);

                        else if(esy==1)
                            strcopy(d,e2);
                        else if(esy==2)
                            strcopy(d,e3);
                        else if(esy==3)
                            strcopy(d,e4);
                    }

                    else if(level == '2')
                    {
                        hard=0;
                        esy=0;
                        intm++;
                        if(intm>10)
                            intm=0;

                        if(intm==0)
                            strcopy(d,intm1);
                        else if(intm==1)
                            strcopy(d,intm2);
                        else if(intm==2)
                            strcopy(d,intm3);
                        else if(intm==3)
                            strcopy(d,intm4);
                        else if(intm==4)
                            strcopy(d,intm5);
                        else if(intm==5)
                            strcopy(d,intm6);
                        else if(intm==6)
                            strcopy(d,intm7);
                        else if(intm==7)
                            strcopy(d,intm8);
                        else if(intm==8)
                            strcopy(d,intm9);
                        else if(intm==9)
                            strcopy(d,intm10);
                    }

                    else if(level == '3')
                    {
                        hard++;
                        esy=0;
                        intm = 0;

                        if(hard>6)
                            hard=0;

                        if(hard==0)
                            strcopy(d,h1);
                        else if(hard==1)
                            strcopy(d,h2);
                        else if(hard==2)
                            strcopy(d,h3);
                        else if(hard==3)
                            strcopy(d,h4);
                        else if(hard==4)
                            strcopy(d,h5);
                        else if(hard==5)
                            strcopy(d,h6);
                    }
                    main();
                }

            }

            if(k2==1) break;
        }
    }
    cleardevice();                              //clearing the screen
    settextstyle(BOLD_FONT,HORIZ_DIR,2);      // changing the text style and font
    outtextxy(169,100,"\A9 COPYRIGHT ");
    outtextxy(169,140,"Mohit Mohta : 150001018");
    outtextxy(169,180,"Pranjal Singh Tomar : 150002025");
    outtextxy(169,260,"Hope You Enjoyed our Game! ");
    cout<< "\a \a" ;                      //exit the game with a buzz sound !
    delay(2000);
    getchar();
    closegraph(); // end of the program
    return 0;
}
