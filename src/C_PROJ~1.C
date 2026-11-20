#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

char patern[3][3]={{ ' ',' ',' '}, { ' ',' ',' '}, { ' ',' ',' '}};
int  x1,y1,x2,y2,x3,y3,x4,y4,startx=20,starty=20,vertpad=20,patnx1,patny1,patnx2,patny2;
char users[2][25]={0},mark[3]={' ',' ','\0'},tagline[]="WELCOME TO TIC TAC TOE!";

// Function - gamesound()
void gamesound(char sndorigin)
{
int i;
/*
N-normal input
q-Quit/Exit
y-Quit/Exit yes
n-Quit/Exit no
e-error(any)
r-Proceed/Restart
*/

if(sndorigin=='N')
{
//------------------Valid input Beep----------------
    sound(800);
    delay(100);
    nosound();
    sound(1000);
    delay(300);
    nosound();
//------------------Valid input Beep----------------
}else if(sndorigin=='e')
{
      //------------------Invalid input Beep----------------
      sound(800);
      delay(300);
      nosound();
      sound(700);
      delay(300);
      nosound();
     //------------------Invalid input Beep----------------
}else if(sndorigin=='q')
{
    //------------------Final Quit/Exit Beep----------------
    for(i=12;i>=1;i--)
    {
      sound(i*800);
      delay(100);
    }
    nosound();
    //------------------Final Quit/Exit Beep----------------
}else if(sndorigin=='n')
{
   //------------------Final Quit/Exit no Beep----------------
   for(i=1;i<=2;i++)
   {
    sound(i*800);
    delay(100);
   }
   nosound();
//------------------Final Quit/Exit no Beep------------
}else if(sndorigin=='y')
{
    //------------------Final Quit/Exit yes Beep----------------
   for(i=4;i>=1;i--)
   {
    sound(i*800);
    delay(100);
   }
   nosound();
//------------------Final Quit/Exit yes Beep----------------
}else if(sndorigin=='r')
{
	 //------------------Final Proceed/Restart Beep----------------
    for(i=1;i<17;i++)
    {
     //sprintf(temp,"%c",tagline[j]);
     //outtextxy(startx*4+j*20,starty,temp);
     sound(50*i);
     delay(100);
     nosound();
    }
    nosound();

	 /*
	 for(i=1;i<=12;i++)
	 {
	  sound(i*800);
	  delay(100);
	 }
	  nosound();
	  */

	 //------------------Final Proceed/Restart Beep----------------
}
/*
else if()
{
 for(j=0;j<23;j++)
    {
     //sprintf(temp,"%c",tagline[j]);
     //outtextxy(startx*4+j*20,starty,temp);
     sound(50*j);
     delay(100);
     nosound();
    }
    nosound();
}
*/

/* done
//------------------Final exit/quit no Beep----------------
for(i=1;i<=2;i++)
{
sound(i*800);
delay(100);
}
nosound();
*/
//------------------Final exit/quit no Beep------------
//getch();
/*done
//------------------Final exit/quit yes Beep----------------
for(i=4;i>=1;i--)
{
sound(i*800);
delay(100);
}
nosound();
//------------------Final exit/quit yes Beep----------------
*/
/* done
//------------------Final X/O selction Beep----------------
for(i=12;i>=1;i--)
{
sound(i*800);
delay(100);
}
nosound();
//------------------Final X/O selction Beep----------------
*/
}
// Function - gamesound()

// Function - flashscreen()
int flashscreen()
{
    char ch='\0',temp[2]={' ','\0'},posno='1',usercount;
    int c,i=0,j,k,blnkflag=0,width,height,flagproc=0;

    //--------------------Welcome Tagline-----------------
    settextstyle(DEFAULT_FONT,0,2);
    for(j=0;j<23;j++)
    {
     sprintf(temp,"%c",tagline[j]);
     outtextxy(startx*4+j*20,starty,temp);
     sound(50*j);
     delay(100);
     nosound();
    }
    nosound();
    cleardevice();
    //--------------------Welcome Tagline-----------------
    // getch();


    for(usercount=0;usercount<2;++usercount)
    {
    do
    {
     posno='1';
    //********************************************************
    settextstyle(DEFAULT_FONT,0,1);
    setcolor(WHITE);
    patnx1=140;
    patny1=105;
    patnx2=180;
    patny2=145;
    for(j=0;j<3;j++)
    {
	     for(k=0;k<3;k++)
     {
       //rectangle(patnx1,patny1,patnx2,patny2);
       rectangle(patnx1+2,patny1+2,patnx2-2,patny2-2);
       rectangle(patnx1+5,patny1+5,patnx2-5,patny2-5);

       temp[0]=posno++;
       outtextxy(patnx1+20,patny1+20,temp);
       patnx1 = patnx1+40;
       patnx2 = patnx2+40;
     }
       patnx1=140;
       patnx2=180;
       patny1 = patny1+40;
       patny2 = patny2+40;
    }
//    posno=1;
  //************************************************************************
    rectangle(0,0,getmaxx(),getmaxy());
    //setbkcolor(BLUE);
    settextstyle(DEFAULT_FONT,0,2);


    outtextxy(0+(getmaxx()-textwidth(tagline))/2,starty,tagline);
    //width = textwidth(tagline);
    height = textheight(tagline);

    line(getmaxx()/2+90,height+60,getmaxx()/2+90,height+430);

    settextstyle(SMALL_FONT,0,5);

    outtextxy(getmaxx()/2+90+55,height+60+10,"KEY INSTRUCTIONS");

    height = height + textheight("KEY INSTRUCTIONS");
    settextstyle(DEFAULT_FONT,0,1);
    outtextxy(getmaxx()/2+90+15,height+60+10+30,"1-9 - no# keys to select");//vertical pad is 30

    width = textwidth("1-9 - ");
    outtextxy(getmaxx()/2+90+15+width,height+8*2+60+10+30,"position as per ");
    outtextxy(getmaxx()/2+90+15+width,height+8*4+60+10+30,"sequence order ");
    outtextxy(getmaxx()/2+90+15+width,height+8*6+60+10+30,"mentioned in right");
    outtextxy(getmaxx()/2+90+15+width,height+8*8+60+10+30,"panel");

    //padding of vertpad-10 required
    outtextxy(getmaxx()/2+90+15,height+8*10+60+10+30+vertpad-10,"Esc - Escape key to EXIT ");
    outtextxy(getmaxx()/2+90+15+width,height+8*12+60+10+30+vertpad-10,"in between or at");
    outtextxy(getmaxx()/2+90+15	+width,height+8*14+60+10+30+vertpad-10,"the end of the");
    outtextxy(getmaxx()/2+90+15+width,height+8*16+60+10+30+vertpad-10,"game");

    //Player 1/2 display
    outtextxy(60,height+8*14+60+10+30+vertpad-10,"Player 1");
    outtextxy(280,height+8*14+60+10+30+vertpad-10,"Player 2");

    outtextxy(getmaxx()/2+90+15,height+8*18+60+10+30+(vertpad-10)*2,"Q/q - QUIT the game");
    outtextxy(getmaxx()/2+90+15,height+8*20+60+10+30+(vertpad-10)*3,"Y/N - To confirm");
    outtextxy(getmaxx()/2+90+15,height+8*24+60+10+30+vertpad-10,"(y/n)");
    //setcolor(BLACK);
    if(i==24) //terminate string
    {
     users[usercount][i]='\0';
     gamesound('N');
     //getch();
     //str[i]='\0';
  ////   printf("i val %d",i);
    // getch();
     break;
    }

    while(!kbhit())
      {
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);

	//outtextxy(50,50,"Enter Players name");
	}
	else
	{
	 setcolor(BLACK);

	//outtextxy(50,50,"Enter Players name");
	}
	//if()
	//{
	//printf("4");
	outtextxy(0+(getmaxx()/2+90-textwidth("Enter Players name"))/2,getmaxy()-80,"Enter Players name");
	setcolor(WHITE);

	delay(300);
	blnkflag++;
      }

      settextstyle(DEFAULT_FONT,0,1);
      setcolor(WHITE);
    //Individual player name input
    ch=getch();
    if(ch==0)
    {
     getch();
    }
    //fflush(stdin);
    if(ch==27)//exit check - escape from individual input
    {
      settextstyle(SMALL_FONT,0,6); //to hide previous notify
      setcolor(BLACK);
      outtextxy(0+(getmaxx()/2+90-textwidth("Enter Players name"))/2,getmaxy()-80,"Enter Players name");
      if(chkqutext(ch,'f')==1)
      {
	return 1; //if 1 return for exit
	//printf("Check flash exit");
	//system("pause");
      }
      else
      {
	//printf("N pressed in ");
	//system("pause");
	continue; //not mandatry but to skip further execution
      }
       //break;
    }else if(ch==8)
    {
    //printf("dfsdfsdfs");
    if(i>0)
    {
       --i;
     ////  printf("%d",i);
       //str[i]='\0';
       users[usercount][i]='\0';
    }
    } else if(ch==13 && i!=0)//'\r')
    {
       users[usercount][i]='\0';
       gamesound('N');
    //   str[i]='\0';
     ////  printf("newline");
       break;
    }else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')|| ch==' ')
    {
    users[usercount][i]=ch;
	    // str[i]=ch;
      ++i;
    ////  printf("%d",i);
    } else
    {
      gamesound('e');
      //("Invalid Input");
    }
  /*  if(i==24)
    {
     users[usercount][i]='\0';
     //str[i]='\0';
     printf("i val %d",i);
    // getch();
      break;
}*/




   // printf("before clear scrren");
   cleardevice();
     //  printf("after clear scrren");

   setcolor(WHITE);
   if(strlen(users[0])!=0)
   {
   //printf("u1 leng=th %d",strlen(users[0]));
   if(strlen(users[0])<=16)
   {
     outtextxy(50,height+8*16+60+10+30+vertpad-10,users[0]);//str);//"Enter name");
   } else if(strlen(users[0])>16 && strlen(users[0])<=20)
   {
     outtextxy(20,height+8*16+60+10+30+vertpad-10,users[0]);//str);//"Enter name");
   }else if(strlen(users[0])>20 && strlen(users[0])<=24)
   {
     outtextxy(10,height+8*16+60+10+30+vertpad-10,users[0]);//str);//"Enter name");
   }
   }

   if(strlen(users[1])!=0)
   {
   if(strlen(users[1])<=16)
   {
    outtextxy(270,height+8*16+60+10+30+vertpad-10,users[1]);//str);//"Enter name");
   } else if(strlen(users[1])>16 && strlen(users[1])<=20)
   {
     outtextxy(240,height+8*16+60+10+30+vertpad-10,users[1]);//str);//"Enter name")
   }else if(strlen(users[1])>20 && strlen(users[1])<=24)
   {
     outtextxy(210,height+8*16+60+10+30+vertpad-10,users[1]);//str);//"Enter name")
   }
   }


 /*
    if(i==24) //terminate string
    {
     users[usercount][i]='\0';
     //str[i]='\0';
     printf("i val %d",i);
    // getch();
      break;
    }
*/
   /*-----------------------------------
    if(i<=16)
    {
     if(usercount==0)
     {
     outtextxy(50,height+8*16+60+10+30+vertpad-10,users[usercount]);//str);//"Enter name");
     }
     else
     {
     outtextxy(270,height+8*16+60+10+30+vertpad-10,users[usercount]);//str);//"Enter name");
     }
    }
    else if(i>16 && i<=20)
    {
     if(usercount==0)
     {
     outtextxy(20,height+8*16+60+10+30+vertpad-10,users[usercount]);//str);//"Enter name");
     }
     else
     {
     outtextxy(240,height+8*16+60+10+30+vertpad-10,users[usercount]);//str);//"Enter name")
     }
    }
    else if(i>20 && i<=24)
    {
     if(usercount==0)
     {
     outtextxy(10,height+8*16+60+10+30+vertpad-10,users[usercount]);//str);//"Enter name");
     }
     else
     {
     outtextxy(210,height+8*16+60+10+30+vertpad-10,users[usercount]);//str);//"Enter name")
     }
    }
    -------------------------------------------- */
   // printf("While lopp");
    }while(1); //do while end
   // printf("While loop terminated");
    i=0;
    }//for end
    //printf("For loop terminated");
    //printf("\n%s",users[0]);
    //printf("\n%s",users[1]);
 ////   printf("Out of for loop");
      settextstyle(SMALL_FONT,0,6);
      setcolor(BLACK);
      outtextxy(0+(getmaxx()/2+90-textwidth("Enter Players name"))/2,getmaxy()-80,"Enter Players name");


    /*  while(!kbhit())
      {
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	if(temp[0]!='X' || temp[0]!='O')
	{
	 outtextxy(0+(getmaxx()/2+90-textwidth("Enter X/O for Player 1"))/2,getmaxy()-80,"Enter X/O for Player 1");
	}
	else
	{
	 outtextxy(0+(getmaxx()/2+90-textwidth("Press any key to proceed..."))/2,getmaxy()-80,"Press any key to proceed...");
	}
	delay(300);
	blnkflag++;
      //setcolor(BLACK);
      }*/

      settextstyle(DEFAULT_FONT,0,1);
      setcolor(WHITE);

   for(i=0;i<2;i++)
   {
    while(1)
    {
    while(!kbhit())
      {
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	if(flagproc==0)
	{
	 outtextxy(0+(getmaxx()/2+90-textwidth("Enter X/O for Player 1"))/2,getmaxy()-80,"Enter X/O for Player 1");
	}
	else
	{
	 outtextxy(0+(getmaxx()/2+90-textwidth("Press any key to proceed..."))/2,getmaxy()-80,"Press any key to proceed...");
	}
	delay(300);
	blnkflag++;
      }
      settextstyle(SMALL_FONT,0,6);
      setcolor(BLACK);
      outtextxy(0+(getmaxx()/2+90-textwidth("Enter X/O for Player 1"))/2,getmaxy()-80,"Enter X/O for Player 1");

      settextstyle(DEFAULT_FONT,0,1);
      setcolor(WHITE);
    //printf("Printf prior");
    ch=toupper(getch());
    if(ch==0) // to skip special characters scenario as it executes gecth() twice
    {
     getch();
     //prckey=getch()+255;
     //inpval[0]='x';//temporary assign any letter so that further inpval value not remains 0 as invalid notification is displayed by checking of inpval value
     //printf("%c",inpval[0]);
     //printf("%s",inpval);
     //outtextxy(20,20,inpval);
     //outtextxy(getmaxx()/2+(textwidth("Enter input (1-9 :"))+20,patny2-100,inpval);
    }

    if(ch==27)//exit check - escape from X/O & proceed
    {
      if(flagproc!=0)// set color black of proceed if proceed active
      {
      settextstyle(SMALL_FONT,0,6); //to hide previous notify
      setcolor(BLACK);
      outtextxy(0+(getmaxx()/2+90-textwidth("Press any key to proceed..."))/2,getmaxy()-80,"Press any key to proceed...");
      }
      if(chkqutext(ch,'f')==1)
      {
	return 1; //if 1 return for exit
	//printf("Check flash exit");
	//system("pause");
      }
      //else
      //{
	//printf("N pressed in ");
	//system("pause");
   //	continue;
     // }
       //break;
    }
    else
    {
    if(flagproc==0) //run untill flagproc is set to 1 and is set in same block so that same block does'nt runs in next iteration
    {
    //mark[0]=ch;
    fflush(stdin);
    if((ch=='X' || ch=='O'))//(mark[0]=='X' || mark[0]=='O')
    {
    gamesound('N');
    //gamesound('e');
    mark[0]=ch;
    mark[1]=mark[0]=='X'?'O':'X';
    flagproc=1; //set flagproc to 1 so that code doesnt run in next iteration
    sprintf(temp,"%c",mark[0]);
    settextstyle(DEFAULT_FONT,0,2);
    //setcolor(RED);
    outtextxy(60,height+8*19+60+10+30+vertpad-10,temp);
    sprintf(temp,"%c",mark[1]);
    outtextxy(280,height+8*19+60+10+30+vertpad-10,temp);
   // settextstyle(SMALL_FONT,0,6);
  //  setcolor(BLACK);
//    outtextxy(0+(getmaxx()/2+90-textwidth("Enter X/O for Player 1"))/2,getmaxy()-80,"Enter X/O for Player 1");
    break; //if break removed doesnt proceeds further loop continues
    }
    else
    {
      //printf("Error");
      gamesound('e');
      //getch();
    }
    }// end of flagproc if
    // below block was unnecessary
    else
    {
      //printf("Process continue");
//      delay(2000);
      break;
      //return 0; //end of flash screen - NOTE - instead of break fine but return ay end of function remains unexecuted and is required to remove compile time warning
    }

    }//end of else - exit check - escape from X/O & proceed
    }   //   while end
     //	  printf("out of loop");
  } //for end
//     getch();
     return 0;
 //   }//for loop

/*    //outtextxy(60,height+8*14+60+10+30+vertpad-10,"Player 1");
    //outtextxy(280,height+8*14+60+10+30+vertpad-10,"Player 2")
    sprintf(temp,"%c",mark[0]);
    outtextxy(60,height+8*18+60+10+30+vertpad-10,temp);
    sprintf(temp,"%c",mark[1]);
    outtextxy(280,height+8*18+60+10+30+vertpad-10,temp);*/
   // getch();
}
// Function - flashscreen()

// Function - chkqutext()
int chkqutext(char ch, char flgorigin)
{
  int blnkflag=0,x,y;
  char choice;


  //x=0+(getmaxx()/2+90-textwidth("Do you want to EXIT curremt game (Y/N)"))/2;
  //y=getmaxy()-80;
  //flash  outtextxy(0+(getmaxx()/2+90-textwidth("Enter X/O for Player 1"))/2,getmaxy()-80,"Enter X/O for Player 1");
  //main getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80
  /*
      while(1)
      {
      while(!kbhit())
      {
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	outtextxy(0+(getmaxx()/2+90-textwidth("Do you want to Exit (Y/N)"))/2,getmaxy()-80,"Do you want to Exit (Y/N)");
	delay(300);
	blnkflag++;
      }
      //settextstyle(SMALL_FONT,0,6);
      //setcolor(BLACK);
      //outtextxy(0+(getmaxx()/2+90-textwidth("Do you want to Exit (Y/N)"))/2,getmaxy()-80,"Do you want to Exit (Y/N)");

      settextstyle(DEFAULT_FONT,0,1);
      setcolor(WHITE);

      ch=toupper(getch());
      settextstyle(SMALL_FONT,0,6);
      setcolor(BLACK);
      outtextxy(0+(getmaxx()/2+90-textwidth("Do you want to Exit (Y/N)"))/2,getmaxy()-80,"Do you want to Exit (Y/N)");
      if(ch=='Y')
      {
	 return 1;
      }
      else if(ch=='N')
      {
	 return 0;
      }
      else
      {
	 continue;//for no response to press other key
      }
      }//while end
 */

//-------------------------------------EXIT/QUIT-----------------------------

    if(flgorigin!='e')//echo sound only if Exit/Quit is not from end screen
    {
    gamesound('q');
    }
    //gamesound('q');

    if(ch=='Q' || ch=='q' || ch==27)
    {
      //exitscreen();
      //break;
      while(1)
      {
	if(flgorigin!='e') //check to execute or not if call is from end screen - if from end screen then not to run if block
	{
	while(!kbhit()) // to display quit message or exit message
	{
	  settextstyle(SMALL_FONT,0,6);
	  if(blnkflag%2==0)
	  {
	  setcolor(WHITE);
	  }
	  else
	  {
	  setcolor(BLACK);
	  }
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  if(ch=='Q' || ch=='q')// confirmation for Quit
	  {
	  outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-120,"Do you want to quit current game (Y/N)");
	  }
	  else  //confirmation for exit
	  {
	   if(flgorigin=='f') //echo exit Y/N message in flash
	   {
	   outtextxy(0+(getmaxx()/2+90-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");
	   }
	   else
	   {
	   outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-120,"Do you want to EXIT curremt game (Y/N)");
	   }
	  }
	  delay(300);
	  blnkflag++;
	}
	  //reset previous blinking message - Strange below hide lines when p;aced below input there was the patern box was swaping up down but when placed below kbhit loop swap was stop
      setcolor(BLACK);
      settextstyle(SMALL_FONT,0,6);
      outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-120,"Do you want to quit current game (Y/N)");
      outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-120,"Do you want to EXIT curremt game (Y/N)");
      outtextxy(0+(getmaxx()/2+90-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");

      setcolor(WHITE);
      settextstyle(DEFAULT_FONT,0,1);

      choice=toupper(getch());
      if(choice==0)  // to skip special characters scenario as it executes gecth() twice
      {
	 getch();
      }

      }
      else // run the else block if call is from end screen
      {
       choice=toupper('Y'); // to set default value of choice to 'Y' to skip input from user (as have to echo required notification)
      }//end if - check to execute or not if call is from end screen - if from end screen then not to run if block

      //reset previous blinking message
      //setcolor(BLACK);
      //settextstyle(SMALL_FONT,0,6);
      //outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-80,"Do you want to quit current game (Y/N)");
      //outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");
      //outtextxy(0+(getmaxx()/2+90-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");

      //----------------added
      //setcolor(WHITE);


      if(ch=='Q' || ch=='q') //Check if for quit logic
      {
      if(choice=='Y' || choice=='y')   //check if quit yes
      {
       if(flgorigin!='e')
       {
	 gamesound('y');//echo sound only if Exit/Quit is not from end screen
       }
	//gamesound('y'); //THINK WILL NEED FLAGING AS TWO SCREENS FLASHING MSG
	while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  if(flgorigin=='e') // to echo in endscreen
	  {
	   //outtextxy((getmaxx()-textwidth("Press any key to continue and Escape to EXIT"))/2,getmaxy()-40,"Press any key to continue and Escape to EXIT");
	   outtextxy((getmaxx()-textwidth("Press any key to continue and Escape to EXIT "))/2,getmaxy()-40,"Press any key to continue and Escape to EXIT ");
	  }
	  else //to echo in main screen
	  {
	   outtextxy((getmaxx()-textwidth("Press any key to continue new game and Escape to EXIT "))/2,getmaxy()-120,"Press any key to continue new game and Escape to EXIT ");
	  }
	  delay(300);
	  blnkflag++;
	}
	//reset
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT,0,6);
	outtextxy((getmaxx()-textwidth("Press any key to continue new game and Escape to EXIT "))/2,getmaxy()-120,"Press any key to continue new game and Escape to EXIT ");

	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,0,1);

	choice=getch(); // input for quit(esc/any key)
	if(choice==0)  // to skip special characters scenario as it executes gecth() twice
	{
	   getch();
	}

	//reset
	//setcolor(BLACK);
	//settextstyle(DEFAULT_FONT,0,6);
	//outtextxy((getmaxx()-textwidth("Press any key to continue new game and Escape to EXIT "))/2,getmaxy()-80,"Press any key to continue new game and Escape to EXIT ");

	//setcolor(WHITE);
	//settextstyle(DEFAULT_FONT,0,1);

	if(choice!=27) //restart from quit
	{
	   //RESTART GAME BEEP TO CONFIRM---------------------------
	   //flag=2;
	   //break;
	   return 2; //to restart new game if any key pressed from quit option
	}
	else //exit from quit
	{
	   gamesound('y');//NEED TO CHANGE done-------------------
	   //flag=1;
	   //break;
	   return 1; //to exit if esc pressed from quit option
	}

      }else if(choice=='N' || choice=='n') //check if quit no
      {
	 gamesound('n');
	 //flag=3;
	 //break;
	 return 3; // to conitnue if n pressed from quit option
      }
      else
      {
	 gamesound('e'); //Quit error
	 //error messsage below
	 //outtextxy(((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2)+textwidth("Press any key to continue new game and escape to EXIT "),getmaxy()-120,"Invalid Input");
      }
      }//if end of ch quit
      else if(ch==27)  //else if of ch EXIT
      {
	if(choice=='Y' || choice=='y') //EXIT from exit
	{
	  gamesound('y');
	  //flag=1;
	  //break;
	  return 1; //to EXIT if y pressed from Exit option
	}else if(choice=='N' || choice=='n') //continue from EXIT
	{
	  gamesound('n');
	  //flag=3;
	  //break;
	  return 3; //to continue if n pressed from EXIT option
	} else
	{
	  gamesound('e');
	  //error messsage below
	  //outtextxy(((getmaxx()-textwidth("Do you want to EXIT current game (Y/N) "))/2)+textwidth("Do you want to EXIT current game (Y/N) "),getmaxy()-120,"Invalid Input");
	}
      } //else if end of ch EXIT - end of else if of Exit key in between

      }//continuity while end
    }  //if of q/E ch

//-------------------------------------EXIT/QUIT-----------------------------


//-------------------------------------EXIT/QUIT-----------------------------
/* if(inpval[0]=='Q' || inpval[0]=='q' || inpval[0]==27)
    {
      //exitscreen();
      //break;
      while(1)
      {
	while(!kbhit()) // to display quit message or exit message
	{
	  settextstyle(SMALL_FONT,0,6);
	  if(blnkflag%2==0)
	  {
	  setcolor(WHITE);
	  }
	  else
	  {
	  setcolor(BLACK);
	  }
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  if(inpval[0]=='Q' || inpval[0]=='q')
	  {
	  outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-80,"Do you want to quit current game (Y/N)");
	  }
	  else
	  {
	   outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");
	  }
	  delay(300);
	  blnkflag++;
	}
	  setcolor(WHITE);
	  settextstyle(DEFAULT_FONT,0,1);

      choice=toupper(getch());

      //reset previous blinking message
      setcolor(BLACK);
      settextstyle(SMALL_FONT,0,6);
      outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-80,"Do you want to quit current game (Y/N)");
      outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");

      //----------------added
      setcolor(WHITE);


      if(inpval[0]=='Q' || inpval[0]=='q') //Check if for quit logic
      {
      if(choice=='Y' || choice=='y')   //check is quit yes
      {
	while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2,getmaxy()-80,"Press any key to continue new game and escape to EXIT ");
	  delay(300);
	  blnkflag++;
	}
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,0,1);

	choice=getch();
	//reset
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT,0,6);
	outtextxy((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2,getmaxy()-80,"Press any key to continue new game and escape to EXIT ");

	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,0,1);

	if(choice!=27)
	{
	   flag=2;
	   break;
	}
	else
	{
	   flag=1;
	   break;
	}

      }else if(choice=='N' || choice=='n')
      {
	 flag=3;
	 break;
      }
      else
      {
	 //outtextxy(20,30,"Invalid input");
	 outtextxy(((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2)+textwidth("Press any key to continue new game and escape to EXIT "),getmaxy()-80,"Invalid Input");
      }
      }//if end of inpval quit
      else if(inpval[0]==27)  //if of inpval EXIT
      {
	if(choice=='Y' || choice=='y')
	{
	  flag=1;
	  break;
	}else if(choice=='N' || choice=='n')
	{
	  flag=3;
	  break;
	} else
	{
	  outtextxy(((getmaxx()-textwidth("Do you want to EXIT current game (Y/N) "))/2)+textwidth("Do you want to EXIT current game (Y/N) "),getmaxy()-80,"Invalid Input");
	}//end of i else if of Exit key in between
      } //else if end of inpval EXIT

      }//continuity while end
    }  //if of q input vaue
    */
//-------------------------------------EXIT/QUIT-----------------------------
}
// Function - chkqutext()

// Function - exitscreen()
void exitscreen()
{
    char gametag[]="TIC TAC TOE",temp[]={0,'\0'};
    int j,k,blnkflag=0;
    //char msg[10],inpval[2]={' ','\0'};
    //int count=0,patyind=1,flag=0;
    cleardevice();

    //--------------------------End screen-------------------------
    rectangle(0,0,getmaxx(),getmaxy());
    //maxcord = textwidth(tagline);
    settextstyle(DEFAULT_FONT,0,2);
    for(j=0;j<23;j++)
    {
     if(j==0)
     {
       outtextxy((getmaxx()-textwidth("Thankyou for Visiting!!!"))/2,getmaxy()/2-100,"Thankyou for Visiting!!!");
     }
     if(j<=11)
     {
     sprintf(temp,"%c",gametag[j]);
     outtextxy((getmaxx()-textwidth(gametag))/2+j*20,getmaxy()/2-50,temp); //outtextxy(20*4+j*20,20,temp);
     }
     sound(50*j);
     delay(100);
     nosound();
    }
    nosound();
    settextstyle(SMALL_FONT,0,6);
    while(!kbhit())
    {
      if(blnkflag%2==0)
      {
	setcolor(WHITE);
      }
      else
      {
	setcolor(BLACK);
      }
      outtextxy((getmaxx()-textwidth("Press any key..."))/2,getmaxy()-200,"Press any key...");
      delay(300);
      ++blnkflag;
    }
      setcolor(WHITE);
      gamesound('y');
    //--------------------------End screen-------------------------
}
// Function - exitscreen()

// Function - display()
void display(char *msgcount,int rowind,int colind)
{
  int j,k,height;
  static int flagcrnrcrd=0;
  char temp[]={' ','\0'};
    startx=10;
    starty=10;
    /*
    patnx1=140;
    patny1=105;
    patnx2=180;
    patny2=145;


    rectangle(0,0,getmaxx(),getmaxy());
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(0+(getmaxx()-textwidth(tagline))/2,starty,tagline);

    settextstyle(DEFAULT_FONT,0,1);
  for(j=0;j<3;j++)
    {
     for(k=0;k<3;k++)
     {
       rectangle(patnx1,patny1,patnx2,patny2);
       temp[0]=patern[j][k];
       outtextxy(patnx1+20,patny1+20,temp);
       patnx1 = patnx1+40;
       patnx2 = patnx2+40;
     }
       patnx1=50;
       patnx2=90;
       patny1 = patny1+40;
       patny2 = patny2+40;
    }
    //sprintf(msg,"Enter input (1-9=) for User %d: %c",inpval);
    outtextxy(patnx2+100,patny2-100,"Enter input (1-9) :");
     */


    //line(getmaxx()/2,0,getmaxx()/2,getmaxy()); //Line necassary while designing as is the contre partion od the screnn
    height = textheight(tagline);

    patnx1=getmaxx()/2-120;//140;
    patny1=starty+height+60;//105;
    patnx2=getmaxx()/2-(120+40);//180;
    patny2=patny1+40;//145;
    //outtextxy(getmaxx()/2-120,starty+height+60,"testing");
    //outtextxy(159,118,"TEST");

    /*
    //coordinates x1y1 for win
    x1=patnx1;
    y1=patny1;
    */

    rectangle(0,0,getmaxx(),getmaxy());
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(0+(getmaxx()-textwidth(tagline))/2,starty,tagline);

    settextstyle(DEFAULT_FONT,0,1);
    /*
    rectangle(patnx1-2,patny1+2,patnx2+2,patny2-2);
	if(patern[j][k]!=' ')
	{
	setcolor(WHITE);
	 rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
	 rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
	 //setfillstyle(1,DARKGRAY);
	 //floodfill(patnx1-6,patny1+6,WHITE);
	}
	*/

    for(j=0;j<3;j++)
    {
     for(k=0;k<3;k++)
     {
       rectangle(patnx1-2,patny1+2,patnx2+2,patny2-2);
       //printf("LLLLL%d %d %d %d",patnx1,patny1,patnx2,patny2);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       temp[0]=patern[j][k];
       if(patern[j][k]!=' ')
       {
       if(!(j==rowind && k==colind))//to skip current selection so that previous positions echo's first
       {
       setcolor(WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       setfillstyle(1,DARKGRAY);
       floodfill(patnx1-6,patny1+6,WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       outtextxy(patnx1+((patnx2-patnx1)/2),patny1+20,temp);
       }
       }
       //-----------------------------ADDED-------------
       if(flagcrnrcrd==0)
       {
       if(j==0&&k==0)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x1=patnx1+((patnx2-patnx1)/2);//getx();
	 y1=patny1+20;//gety();
	 //printf("%d,%d-%d,%d-%d,%d-%d,%d",x1,y1,x2,y2,x3,y3,x4,y4);
       }else if(j==0&&k==2)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x2=patnx1+((patnx2-patnx1)/2);//getx();
	 y2=patny1+20;//gety();
	 //printf("%d,%d-%d,%d-%d,%d-%d,%d",x1,y1,x2,y2,x3,y3,x4,y4);
       }else if(j==2&&k==0)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x3=patnx1+((patnx2-patnx1)/2);//getx();
	 y3=patny1+20;//gety();
	 //printf("%d,%d-%d,%d-%d,%d-%d,%d",x1,y1,x2,y2,x3,y3,x4,y4);
       }else if(j==2&&k==2)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x4=patnx1+((patnx2-patnx1)/2);//getx();
	 y4=patny1+20;//gety();
	 //printf("%d,%d-%d,%d-%d,%d-%d,%d",x1,y1,x2,y2,x3,y3,x4,y4);
	 flagcrnrcrd=1;
       }


       }
       //-----------------------------ADDED-------------


       patnx1 = patnx1+40;
       patnx2 = patnx2+40;

       /*
       if(j==0&&k==2)
       {
       //coordinates x2y2 for win
       x2=patnx2;
       y2=patny2;
       }
       if(j==2&&k==2)
       {
       //coordinates x4y4 for win
       x4=patnx1;
       y4=patny1;
       }
       */
     }
	//getch();
       patnx1=getmaxx()/2-120;//50;
       patnx2=getmaxx()/2-(120+40);//90;
       patny1 = patny1+40;
       patny2 = patny2+40;
       /*
       if(j==2)
       {
       //coordinates x3y3 for win
       x3=patnx1;
       y3=patny1;
       }
       */
    }

    //outtextxy(199,78,"testing");

    //---------------------------------------ADDEDDDDDD
    settextstyle(DEFAULT_FONT,0,1);
    setcolor(WHITE);
	//sprintf(msg,"Enter input (1-9=) for User %d: %c",inpval);
    outtextxy(getmaxx()/2,patny2-120,msgcount);
    outtextxy(getmaxx()/2,patny2-100,"Enter input (1-9) :");

//    outtextxy(60,height+8*14+60+10+30+vertpad-10,"Player 1");
      outtextxy((getmaxx()/2-textwidth("Player 1"))/2,patny2,"Player 1");
//    outtextxy(280,height+8*14+60+10+30+vertpad-10,"Player 2");
      outtextxy(getmaxx()/2+(getmaxx()/2-textwidth("Player 2"))/2,patny2,"Player 2");

      height=textheight("Player 2");

    if(strlen(users[0])<=16)
   {
     //outtextxy(50,patny2+height+20,users[0]);
     outtextxy((getmaxx()/2-textwidth(users[0]))/2,patny2+height+10,users[0]);
   } else if(strlen(users[0])>16 && strlen(users[0])<=20)
   {
     //outtextxy(20,patny2+height+20,users[0]);//str);//"Enter name");
     outtextxy((getmaxx()/2-textwidth(users[0]))/2,patny2+height+10,users[0]);
   }else if(strlen(users[0])>20 && strlen(users[0])<=24)
   {
     //outtextxy(10,patny2+height+20,users[0]);//str);//"Enter name");
     outtextxy((getmaxx()/2-textwidth(users[0]))/2,patny2+height+10,users[0]);
   }

   if(strlen(users[1])<=16)
   {
     //outtextxy(270,patny2+height+20,users[1]);//str);//"Enter name");
     outtextxy(getmaxx()/2+(getmaxx()/2-textwidth(users[1]))/2,patny2+height+10,users[1]);
   } else if(strlen(users[1])>16 && strlen(users[1])<=20)
   {
     //outtextxy(240,patny2+height+20,users[1]);//str);//"Enter name")
     outtextxy(getmaxx()/2+(getmaxx()/2-textwidth(users[1]))/2,patny2+height+10,users[1]);
   }else if(strlen(users[1])>20 && strlen(users[1])<=24)
   {
     //outtextxy(210,patny2+height+20,users[1]);//str);//"Enter name")
     outtextxy(getmaxx()/2+(getmaxx()/2-textwidth(users[1]))/2,patny2+height+10,users[1]);
   }

   settextstyle(DEFAULT_FONT,0,2);
   setcolor(WHITE);
   sprintf(temp,"%c",mark[0]);
   outtextxy((getmaxx()/2-textwidth(temp))/2,patny2+height*2+20,temp);
   sprintf(temp,"%c",mark[1]);
   outtextxy(getmaxx()/2+(getmaxx()/2-textwidth(temp))/2,patny2+height*2+20,temp);
   settextstyle(SMALL_FONT,0,6);
   outtextxy((getmaxx()/2-textwidth("Q - RRESS Q/q KEY TO QUIT"))/2,getmaxy()-30,"Q - RRESS Q/q KEY TO QUIT");
   outtextxy(getmaxx()/2+(getmaxx()/2-textwidth("ESC - RRESS ESC KEY TO EXIT"))/2,getmaxy()-30,"ESC - RRESS WSC KEY TO EXIT");

   //---------------------------------------ADDEDDDDDD
    settextstyle(DEFAULT_FONT,0,1);

    //------------------------------FROM HERE

    patnx1=getmaxx()/2-120;//140;
    patny1=starty+height+60;//105;
    patnx2=getmaxx()/2-(120+40);//180;
    patny2=patny1+40;//145;

    for(j=0;j<3;j++)
    {
     for(k=0;k<3;k++)
     {
       if(j==rowind && k==colind)//to apply on/off effect for current selection only and skip others
       {
       //--------------------Double box patern------------------

       temp[0]=patern[j][k];
       setcolor(BLACK);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       setcolor(WHITE);
       rectangle(patnx1-7,patny1+7,patnx2+7,patny2-7);
       delay(300);
       setcolor(BLACK);
       rectangle(patnx1-7,patny1+7,patnx2+7,patny2-7);
       setcolor(WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       setfillstyle(1,DARKGRAY);
       floodfill(patnx1-6,patny1+6,WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       outtextxy(patnx1+((patnx2-patnx1)/2),patny1+20,temp);
       /*
       if(j==0&&k==0)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x1=patnx1+((patnx2-patnx1)/2);//getx();
	 y1=patny1+20;//gety();
       }else if(j==0&&k==2)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x2=patnx1+((patnx2-patnx1)/2);//getx();
	 y2=patny1+20;//gety();
       }else if(j==2&&k==0)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x3=patnx1+((patnx2-patnx1)/2);//getx();
	 y3=patny1+20;//gety();
       }else if(j==2&&k==2)
       {
	 //moveto(patnx1+((patnx2-patnx1)/2),patny1+20);
	 x4=patnx1+((patnx2-patnx1)/2);//getx();
	 y4=patny1+20;//gety();
       }
       */
       //printf("%d,%d-%d,%d-%d,%d-%d,%d",x1,y1,x2,y2,x3,y3,x4,y4);
       //--------------------Double box patern------------------
       /*--------------------Single box patern------------------
       temp[0]=patern[j][k];
       setcolor(BLACK);
       rectangle(patnx1-2,patny1+2,patnx2+2,patny2-2);
       setcolor(WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       delay(200);
       setcolor(BLACK);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       setcolor(WHITE);
       rectangle(patnx1-2,patny1+2,patnx2+2,patny2-2);
       setcolor(WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       delay(400);
       setfillstyle(1,DARKGRAY);
       floodfill(patnx1-6,patny1+6,WHITE);
       rectangle(patnx1-5,patny1+5,patnx2+5,patny2-5);
       setcolor(WHITE);
       outtextxy(patnx1+((patnx2-patnx1)/2),patny1+20,temp);
       --------------------Single box patern------------------*/
       }
       patnx1 = patnx1+40;
       patnx2 = patnx2+40;
    }
       patnx1=getmaxx()/2-120;//50;
       patnx2=getmaxx()/2-(120+40);//90;
       patny1 = patny1+40;
       patny2 = patny2+40;
       }

      setcolor(WHITE);//Necesarry as if not endscreen msg(Won/Drawn) does blink slowly(unproper)
}
// Function - display()

// Function - winline()
void winline(int tmpx1,int tmpy1,int tmpx2,int tmpy2)
{
int x,y;
      //-------------Final win line--------------------
	//for(x=50,y=50;x<=130,y<=130;x++,y++)
	//for(x=tmpx1,y=tmpy1+2;x<=tmpx2;)
	/*
	if(tmpx1==tmpx2&&tmpy1==tmpy2)
	{
	x=tmpx1;
	y=tmpy1+2;
	}else if(tmpx1==tmpx2)
	{
	x=tmpx1;
	y=tmpy1+2;
	)else if(tmpy1==tmpy2)
	{
	x=tmpx1;
	y=tmpy1+2;
	)
	*/
	while(1)
	{
	  //printf("%d,%d-%d,%d",x,y,tmpx2,tmpy2);
	  setcolor(BLACK);
	  if(tmpx1!=tmpx2&&tmpy1!=tmpy2)
	  {
	  if(tmpx1<tmpx2)
	  {
	  line(tmpx1,tmpy1,tmpx1++,tmpy1++);
	  sound((tmpy1-48)*5);
	  if(tmpx1>tmpx2){break;}
	  }else if(tmpx1>tmpx2)
	  {
	  line(tmpx1+3,tmpy1,(tmpx1--)+3,tmpy1++);
	  sound((tmpy1-48)*5);
	  if(tmpx1<tmpx2){break;}
	  }
	  }else if(tmpy1==tmpy2)
	  {
	  line(tmpx1,tmpy1+2,tmpx1++,tmpy2+2);
	  sound((tmpx1-129)*5);
	  if(tmpx1>tmpx2){break;}
	  }else if(tmpx1==tmpx2)
	  {
	  line(tmpx1+3,tmpy1,tmpx1+3,tmpy1++);
	  sound((tmpy1-48)*5);
	  if(tmpy1>tmpy2){break;}
	  }
	  delay(10);
	}
	  nosound();
	  //setcolor(WHITE);
	  //printf("%d,%d-%d,%d",x,y,tmpx2,tmpy2);
	  //getch();
	  //return;
      //-------------Final win line--------------------
}
// Function - winline()

// Function - checkstatus()
int checkstatus(int count, char *msgcount)
{
  int i,j,k,drawcount=0,x,y;
  char msg[30];
  //cleardevice();
  //printf("%d",count);
  /*
  for(i=0;i<3;i++)
  {
    if((patern[i][0]==patern[i][1] && patern[i][0]==patern[i][2] && patern[i][0]!=' ') || (patern[0][i]==patern[1][i] && patern[0][i]==patern[2][i] && patern[0][i]!=' '))
    {
      display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      sprintf(msg,"Player %d Won!!!",count);
      //sound(1000);
      //delay(35);
      //endscreen(msg);
      //return 1;
      delay(1000);
      //setcolor(WHITE);
      return endscreen(msg,(count==1)?users[0]:users[1]);
    }
    if((patern[0][0]==patern[1][1] && patern[1][1]==patern[2][2] && patern[2][2]!=' ') || (patern[0][2]==patern[1][1] && patern[1][1]==patern[2][0] && patern[2][0]!=' '))
    {
      display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      sprintf(msg,"Player %d Won!!!",count);
      //endscreen(msg);
      //return 1;
      delay(1000);
      //setcolor(WHITE);
      return endscreen(msg,(count==1)?users[0]:users[1]);
    }
  }
*/
//------------------------------last step-----------------------
  for(i=0;i<3;i++)
  {
    //if((patern[i][0]==patern[i][1] && patern[i][0]==patern[i][2] && patern[i][0]!=' ') || (patern[0][i]==patern[1][i] && patern[0][i]==patern[2][i] && patern[0][i]!=' '))
    if(patern[i][0]==patern[i][1] && patern[i][0]==patern[i][2] && patern[i][0]!=' ')
    {
      display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      sprintf(msg,"Player %d Won!!!",count);
      //draw win line as per row
      winline(x1,y1+(40*i),x2,y2+(40*i));
      //delay(500);
      //winline(x1,y1,x2,y2);
      //printf("2");
      //getch();
      //sound(1000);
      //delay(35);
      //endscreen(msg);
      //return 1;
      //delay(1000);
      /*
      if(i==0)
      {
       //printf("Final %d,%d-%d,%d",x1,y1,x2,y2);
      //-------------Final win line--------------------
	winline(x1,y1,x2,y2);
	  getch();
      //-------------Final win line--------------------
      }else if(i==1)
      {
       //printf("Final %d,%d-%d,%d",x1,y1,x2,y2);
      //-------------Final win line--------------------
	winline(x1,y1+40,x2,y2+40);
	  getch();
      //-------------Final win line--------------------
      }else if(i==0)
      {
       //printf("Final %d,%d-%d,%d",x1,y1,x2,y2);
      //-------------Final win line--------------------
	winline(x1,y1,x2,y2);
	}
	*/
	  //getch();
      //-------------Final win line--------------------
      //}


      //getch();
      //delay(1000);
      //setcolor(WHITE);
      return endscreen(msg,(count==1)?users[0]:users[1]);
    }else if(patern[0][i]==patern[1][i] && patern[0][i]==patern[2][i] && patern[0][i]!=' ')
    {
      display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      sprintf(msg,"Player %d Won!!!",count);

      //draw win line as per col
      winline(x1+(40*i),y1,x3+(40*i),y3);
      //delay(1000);
      //sound(1000);
      //delay(35);
      //endscreen(msg);
      //return 1;
      //delay(1000);
      //setcolor(WHITE);
      return endscreen(msg,(count==1)?users[0]:users[1]);
    }
    //if((patern[0][0]==patern[1][1] && patern[1][1]==patern[2][2] && patern[2][2]!=' ') || (patern[0][2]==patern[1][1] && patern[1][1]==patern[2][0] && patern[2][0]!=' '))
    if(patern[0][0]==patern[1][1] && patern[1][1]==patern[2][2] && patern[2][2]!=' ')
    {
      display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      sprintf(msg,"Player %d Won!!!",count);
      winline(x1,y1,x4,y4);
      //delay(1000);
      //endscreen(msg);
      //return 1;
      //delay(1000);
      //setcolor(WHITE);
      return endscreen(msg,(count==1)?users[0]:users[1]);
    }else if(patern[0][2]==patern[1][1] && patern[1][1]==patern[2][0] && patern[2][0]!=' ')
    {
      display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      sprintf(msg,"Player %d Won!!!",count);
      winline(x2,y2,x3,y3);
      //delay(1000);
      //endscreen(msg);
      //return 1;
      //delay(1000);
      //setcolor(WHITE);
      return endscreen(msg,(count==1)?users[0]:users[1]);
    }
  }
//------------------------------last step-----------------------

  for(j=0;j<3;j++)
  {
  for(k=0;k<3;k++)
  {
     if(patern[j][k]!=' ')
     {
     drawcount++;
     }
  }
  }

  if(drawcount==9)
  {
    display(msgcount,3,3);//set to row/col index 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
    sprintf(msg,"Game Drawn... No Winner.");
    //endscreen(msg);
    //outtextxy(10,20,"Game Drawn... No Winner");
    //sound(100);
    //delay(1500);
    //nosound();
    //return 1;
    //delay(1000);
    return endscreen(msg);
  }
  return 0;
}
// Function - checkstatus()

// Function - endscreen()
int endscreen(char *msg, char *winner)
{
int i,j=0,k,blnkflag=0,snd=100;

cleardevice();
rectangle(0,0,getmaxx(),getmaxy());
setcolor(WHITE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

k=1;
while(k<400)
{
for(i=0;i<50;i++)
{
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   if(blnkflag%2==0)
   {
     setcolor(WHITE);
   }
   else
   {
     setcolor(j);
   }

outtextxy((getmaxx()-textwidth(msg))/2,getmaxy()/2-20,msg);//settextstyle(SMALL_FONT,0,6);
outtextxy((getmaxx()-textwidth(winner))/2,getmaxy()/2+20,winner);//settextstyle(SMALL_FONT,0,6);
blnkflag++;
sound(k+10);//sound(k+(k+100));
setcolor(j);
circle(getmaxx()/2,getmaxy()/2,i*4);
delay(20);
j++;
if(j==16)
{
 j=1;
}
k++;
snd++;
}
i=0;
}
nosound();
setcolor(WHITE);
outtextxy((getmaxx()-textwidth(msg))/2,getmaxy()/2-20,msg);//settextstyle(SMALL_FONT,0,6);
outtextxy((getmaxx()-textwidth(winner))/2,getmaxy()/2+20,winner);//settextstyle(SMALL_FONT,0,6);

//outtextxy((getmaxx()-textwidth(msg))/2,getmaxy()/2,msg);//settextstyle(SMALL_FONT,0,6);
//setcolor(WHITE);
//outtextxy((getmaxx()-textwidth(msg))/2,getmaxy()/2,msg);

//setcolor(WHITE);
//settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
//outtextxy(getmaxx()/2-180,getmaxy()/2,msg);
//outtextxy((getmaxx()-textwidth(msg))/2,getmaxy()/2,msg);
//settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
//setcolor(WHITE);
/*
   while(!kbhit())
   {
    settextstyle(SMALL_FONT,HORIZ_DIR,6);
    if(blnkflag%2==0)
   {
     setcolor(WHITE);
   }
   else
   {
     setcolor(BLACK);
   }
   outtextxy((getmaxx()-textwidth("Press any key to continue and Escape to EXIT"))/2,getmaxy()-40,"Press any key to continue and Escape to EXIT");
   delay(300);
   blnkflag++;
}
   term = getch();
   fflush(stdin);
 if(term!=27)
 {
   //display();
   return 2;  //want to restart i.e. continue
 }
 else
 {
   return 1;  //want to exit
 }
 */
 return chkqutext('q','e'); // calling quit block as same block of code so the q passed
}
// Function - endscreen()



int main()
{
    int gdriver = DETECT, gmode;
    char msg[10],inpval[]={0,'\0'};
    int  x,clr=0,c=0,y,prckey=0,ptnrowind=3,tempcolind=3,sameflag,i,j,count=0,patyind=1,flag=0,choice,blnkflag=0,dissndflag=0;
    clrscr();
    initgraph(&gdriver, &gmode, "");// initgraph(&gdriver, &gmode, "C:\\BGI");//initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

    if(!flashscreen()) //run only if flasscreen returns continuation
    {
    cleardevice();
    //gamesound('r');
    //actual main code to run the game
    while(1)
    {
    //getch();
    cleardevice();

    sprintf(msg,"Player %d:",count%2+1);
  //outtextxy(patnx2+110,patny2-120,msg);
   // settextstyle(DEFAULT_FONT,0,1);
    //setcolor(WHITE);
    display(msg,ptnrowind,tempcolind);

    //settextstyle(DEFAULT_FONT,0,2);
    //setcolor(WHITE);
    /*
    settextstyle(SMALL_FONT,0,6);
    outtextxy((getmaxx()/2-textwidth("Q - RRESS Q/q KEY TO QUIT"))/2,getmaxy()-30,"Q - RRESS Q/q KEY TO QUIT");
    outtextxy(getmaxx()/2+(getmaxx()/2-textwidth("ESC - RRESS ESC KEY TO EXIT"))/2,getmaxy()-30,"ESC - RRESS WSC KEY TO EXIT");
    */

    if(dissndflag==0)//game sound to start/restart
    {
      gamesound('r');
      ++dissndflag;
    }

    // printf("   %d",(count%2)+1);
  /*  if(checkstatus((count-1%2)+1)==1)
    {
      break;
    } */

    //ADDED
  /*
    if(inpval[0]!=0 && !(inpval[0]>=49 && inpval[0]<=57) && inpval[0]!=27 && inpval[0]!='Q')
    {
    while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	  //"Press any key to continue and escape to EXIT:");
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Invlid Input"))/2,getmaxy()-80,"Invalid Input");
	  delay(300);
	  blnkflag++;
	}
	//setcolor(WHITE);
	//settextstyle(DEFAULT_FONT,0,1);
    setcolor(BLACK);
    settextstyle(SMALL_FONT,0,6);
    outtextxy((getmaxx()-textwidth("Invlid Input"))/2,getmaxy()-80,"Invalid Input");
    }
/*
    //ADDED
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,0,1);
  /*
    if(inpval[0]!=27)
    {
    outtextxy(getmaxx()/2+(textwidth("Enter input (1-9 :"))+20,patny2-100,inpval);
    }
    delay(10);
*/

    settextstyle(DEFAULT_FONT,0,1);
    //printf("process key");
    inpval[0] = getch();
    //fflush(stdin);
    /*
//------------------Valid input Beep----------------
    sound(800);
    delay(100);
    nosound();
    sound(1000);
    delay(300);
    nosound();
//------------------Valid input Beep----------------
      */
//reset Invali Input message to black

//  settextstyle(DEFAULT_FONT,0,1);
   if(inpval[0]==0)
   {
    prckey=getch()+255;
    inpval[0]='x';//temporary assign any letter so that further inpval value not remains 0 as invalid notification is displayed by checking of inpval value
    //printf("%c",inpval[0]);
    //printf("%s",inpval);
    //outtextxy(20,20,inpval);
    //outtextxy(getmaxx()/2+(textwidth("Enter input (1-9 :"))+20,patny2-100,inpval);
   }
//   getch();

   if((prckey==0) && inpval[0]!=8  && inpval[0]!=27 && inpval[0]!=13) //if(inpval[0]!=27 || inpval[0]!=13)//dont display escape character
   {
    outtextxy(getmaxx()/2+(textwidth("Enter input (1-9 :"))+20,patny2-100,inpval);
   }
    delay(300);
    /*
    //***************************************   check for selected position and in valid inout
    //-------------------------------------------------------
    if(inpval[0]!=0 && !(inpval[0]>=49 && inpval[0]<=57) && inpval[0]!=27 && inpval[0]!='Q')
    {
    while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	  //"Press any key to continue and escape to EXIT:");
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Invlid Input"))/2,getmaxy()-80,"Invalid Input");
	  delay(300);
	  blnkflag++;
	}
	//setcolor(WHITE);
	//settextstyle(DEFAULT_FONT,0,1);
    setcolor(BLACK);
    settextstyle(SMALL_FONT,0,6);
    outtextxy((getmaxx()-textwidth("Invlid Input"))/2,getmaxy()-80,"Invalid Input");
    }
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,0,1);

    //--------------------------------------------------------
    //Check for selected already marked positio
    if(inpval[0]!=0  && (inpval[0]>=49 && inpval[0]<=57) && inpval[0]!=27 && inpval[0]!='Q' && patern[0][atoi(inpval)-patyind] != ' ')  //check if empty then mark
    {
     while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	  //"Press any key to continue and escape to EXIT:");
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Invlid Input - Position selected already marked"))/2,getmaxy()-80,"Invlid Input - Position selected already marked");
	  delay(300);
	  blnkflag++;
	}
	//setcolor(WHITE);
	//settextstyle(DEFAULT_FONT,0,1);
    setcolor(BLACK);
    settextstyle(SMALL_FONT,0,6);
    outtextxy((getmaxx()-textwidth("Invlid Input - Position selected already marked"))/2,getmaxy()-80,"Invlid Input - Position selected already marked");
    }//Check for selected already marked positio
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,0,1);


    //***************************************
     */

    switch(inpval[0])
    {
       case '1':
       case '2':
       case '3':
       case '4':
       case '5':
       case '6':
       case '7':
       case '8':
       case '9':
       {
       if(inpval[0]>=49 && inpval[0]<=51)
       {
	  patyind = patyind*1;
	  ptnrowind=0;//set row index as per position selection
	  //printf("r1 %d %d",patyind,ptnrowind);
	  //getch();
       }
       else if(inpval[0]>=52 && inpval[0]<=54)
       {
	  patyind = patyind*4;
	  ptnrowind=1;//set row index as per position selection
	  //printf("r2 %d %d",patyind,ptnrowind);
	  //getch();
       }else
       {
	  patyind = patyind*7;
	  ptnrowind=2;//set row index as per position selection
	  //printf("r3 %d %d",patyind,ptnrowind);
	  //getch();
       }
	 if(patern[ptnrowind][atoi(inpval)-patyind] == ' ')  //check if empty then mark
	 {
	  tempcolind=atoi(inpval)-patyind;//set col index as per position selection
//------------------Valid input Beep----------------
	 gamesound('N');
//------------------Valid input Beep----------------
	 if(count%2 == 0) //if player 1 mark
	 {
	 patern[ptnrowind][atoi(inpval)-patyind]=mark[0];
	 //printf("%d-%d",ptnrowind,atoi(inpval)-patyind);
	 //getch();
	 }
	 else   //if player 2 mark
	 {
	 patern[ptnrowind][atoi(inpval)-patyind]=mark[1];
	 //printf("%d-%d",ptnrowind,atoi(inpval)-patyind);
	 //getch();
	 }

	 flag=checkstatus(count%2+1,msg); //once markes check the status
	 if(flag==1)//for EXIT  if(checkstatus(count%2+1)==1)
	 {
	   flag=1;
	   break;
	 }else if(flag==2)
	 {
	   flag=2;  //for restart i.e. continue
	   break;
	 }
	 count++;
	 }
	 else  //else if not empty if selected already marked position
	 {
	 ptnrowind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	 tempcolind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
      //--------------------------------------------------------
    //Check for selected already marked positio
    if(inpval[0]!=0)  //&& (inpval[0]>=49 && inpval[0]<=57) && inpval[0]!=27 && inpval[0]!='Q' && patern[0][atoi(inpval)-patyind] != ' ')  //check if empty then mark
    {
      //------------------Invalid input Beep----------------
       gamesound('e');
     //------------------Invalid input Beep----------------
     while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	  //"Press any key to continue and escape to EXIT:");
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Invlid Input - Position selected already marked"))/2,getmaxy()-120,"Invlid Input - Position selected already marked");
	  delay(300);
	  blnkflag++;
	}
	//setcolor(WHITE);
	//settextstyle(DEFAULT_FONT,0,1);
    setcolor(BLACK);
    settextstyle(SMALL_FONT,0,6);
    outtextxy((getmaxx()-textwidth("Invlid Input - Position selected already marked"))/2,getmaxy()-120,"Invlid Input - Position selected already marked");
    }//Check for selected already marked positio
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,0,1);

	 //  printf("Invalid Input...Select the unmarked Position");
	 }
	 patyind=1; //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
	 //count++;
       break;
       }
       case 'Q':
       case 'q':
       {
	 flag = chkqutext(inpval[0],'m');
	 ptnrowind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	 tempcolind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	 break;
       }
       case 27:
       {
	  flag = chkqutext(inpval[0],'m');
	  ptnrowind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	  tempcolind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	  break;
       }

       default:
       {
	 ptnrowind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	 tempcolind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	    //-------------------------------------------------------
    if(inpval[0]!=0) //&& !(inpval[0]>=49 && inpval[0]<=57) && inpval[0]!=27 && inpval[0]!='Q')
    {
      //------------------Invalid input Beep----------------
      gamesound('e');
     //------------------Invalid input Beep----------------
    while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	  //"Press any key to continue and escape to EXIT:");
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Invlid Input - Select 1-9"))/2,getmaxy()-120,"Invalid Input - Select 1-9");
	  delay(300);
	  blnkflag++;
	}
	//setcolor(WHITE);
	//settextstyle(DEFAULT_FONT,0,1);
    setcolor(BLACK);
    settextstyle(SMALL_FONT,0,6);
    outtextxy((getmaxx()-textwidth("Invalid Input - Select 1-9"))/2,getmaxy()-120,"Invalid Input - Select 1-9");
    }
    prckey=0; //to reset prckey to 0 so that further special keys can be processed
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,0,1);
	 //count--;
	 //printf("Invalid Key pressed... Please input 1-9");
       }//Default end
       //printf("%d",inpval[0]);
       }   //switch end

//-------------------------------------EXIT/QUIT-----------------------------
/*  if(inpval[0]=='Q' || inpval[0]=='q' || inpval[0]==27)
    {
      //exitscreen();
      //break;
      while(1)
      {
	while(!kbhit()) // to display quit message or exit message
	{
	  settextstyle(SMALL_FONT,0,6);
	  if(blnkflag%2==0)
	  {
	  setcolor(WHITE);
	  }
	  else
	  {
	  setcolor(BLACK);
	  }
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  if(inpval[0]=='Q' || inpval[0]=='q')
	  {
	  outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-80,"Do you want to quit current game (Y/N)");
	  }
	  else
	  {
	   outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");
	  }
	  delay(300);
	  blnkflag++;
	}
	  setcolor(WHITE);
	  settextstyle(DEFAULT_FONT,0,1);

      choice=toupper(getch());

      //reset previous blinking message
      setcolor(BLACK);
      settextstyle(SMALL_FONT,0,6);
      outtextxy((getmaxx()-textwidth("Do you want to quit current game (Y/N)"))/2,getmaxy()-80,"Do you want to quit current game (Y/N)");
      outtextxy((getmaxx()-textwidth("Do you want to EXIT curremt game (Y/N)"))/2,getmaxy()-80,"Do you want to EXIT curremt game (Y/N)");

      //----------------added
      setcolor(WHITE);


      if(inpval[0]=='Q' || inpval[0]=='q') //Check if for quit logic
      {
      if(choice=='Y' || choice=='y')   //check is quit yes
      {
	while(!kbhit()) // message for after quit weather to restart new game or exit
	{
	settextstyle(SMALL_FONT,0,6);
	if(blnkflag%2==0)
	{
	setcolor(WHITE);
	}
	else
	{
	 setcolor(BLACK);
	}
	  //settextstyle(SMALL_FONT,0,6);
	  //setcolor(BLACK);
	  outtextxy((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2,getmaxy()-80,"Press any key to continue new game and escape to EXIT ");
	  delay(300);
	  blnkflag++;
	}
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,0,1);

	choice=getch();
	//reset
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT,0,6);
	outtextxy((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2,getmaxy()-80,"Press any key to continue new game and escape to EXIT ");

	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,0,1);

	if(choice!=27)
	{
	   flag=2;
	   break;
	}
	else
	{
	   flag=1;
	   break;
	}

      }else if(choice=='N' || choice=='n')
      {
	 flag=3;
	 break;
      }
      else
      {
	 //outtextxy(20,30,"Invalid input");
	 outtextxy(((getmaxx()-textwidth("Press any key to continue new game and escape to EXIT "))/2)+textwidth("Press any key to continue new game and escape to EXIT "),getmaxy()-80,"Invalid Input");
      }
      }//if end of inpval quit
      else if(inpval[0]==27)  //if of inpval EXIT
      {
	if(choice=='Y' || choice=='y')
	{
	  flag=1;
	  break;
	}else if(choice=='N' || choice=='n')
	{
	  flag=3;
	  break;
	} else
	{
	  outtextxy(((getmaxx()-textwidth("Do you want to EXIT current game (Y/N) "))/2)+textwidth("Do you want to EXIT current game (Y/N) "),getmaxy()-80,"Invalid Input");
	}//end of i else if of Exit key in between
      } //else if end of inpval EXIT

      }//continuity while end
    }  //if of q input vaue
    */
//-------------------------------------EXIT/QUIT-----------------------------

    if(flag==3)
    {
      flag=0;  //reset flag important
      inpval[0]=0; // to reset invali input msg
	 ptnrowind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
	 tempcolind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
      continue;
    }
    if(flag==1)
    {
       break;
    }
    if(flag==2)
    {
       flag=0;  //very important reset flag for restart
       count=0;
       patyind=1; //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
       inpval[0]=0; // to reset invalid input msg
       dissndflag=0;//reset for game sound to restart
	 ptnrowind=3; //set to 3 so that no diplay's button on/off for loop runs CCCCCCCCCCCCCCCCCCCCCCCCCCC
	 tempcolind=3; //set to 3 so that no diplay's button on/off for loop runsCCCCCCCCCCCCCCCCCCCCCCCCCCC
       for(i=0;i<3;i++)
       {
	for(j=0;j<3;j++)
	{
	  patern[i][j]=' ';
	}
       }
       //gamesound('r');
       //display(msg);// due to which display box was shifting
       //gamesound('r');
      // printf("Restart");
    }  //if end
   // else
    //{
      // flag=0;
      // continue;
   // }


//    getch();
    //inpval[0]=' ';
    //outtextxy(patnx2+50+(textwidth("Enter input (1-9):")),patny2-50,inpval);


    /*outtextxy(startx,starty,"Welcome to Tic Tac Toe");
    rectangle(patnx1,patny1,patnx2,patny2);

    outtextxy(patnx2+50,patny2-50,"Enter input (1-9):");*/
    //display();
    } //while end
    } //flashscreen return if end
   /*
    inpval[0] = getchar();
    //printf("%c",textwidth("Enter input (1-9):"));
    outtextxy(patnx2+50+(textwidth("Enter input (1-9):")),patny2-50,inpval);
    */
    //sprintf("%d",choice);
    //scanf("%s",&choice);
    //choice[0]=getchar();
    //outtextxy(50,400,choice);
    //gotoxy(0,150);

    cleardevice();
    exitscreen();
    //printf("Thankyou for visiting");
    getch();
   // getchar();
    closegraph();
    return;
}