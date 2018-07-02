#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "quiz.h"
#include "quiz_rec.h"
#include "quiz_sub.h"

void intro();
void main_menu();
void play_quiz();
void modify();
void make();
void m_edit();
void m_del();

void main()
{
 clrscr();
 intro();
 main_menu();
}

void main_menu()
{
  clrscr();
 char ch;
 do
 {
  clrscr();
  cout<<setw(71)<<setfill(95);
  cout<<"\n\n\t\t\tMAIN MENU "<<endl;
  cout<<setw(60)<<setfill(95)<<"\n\n\n";
  cout<<"\t\t1. PLAY QUIZ"<<endl;
  cout<<"\t\t2. CREATE QUIZ "<<endl;
  cout<<"\t\t3. MODIFY QUIZ "<<endl;
  cout<<"\t\t4. EXIT"<<endl<<endl;

  cout<<"Enter Your Choice :";
  cin>>ch;

  switch(ch)
  {
    case '1': play_quiz();
		break;
    case '2': make();
		break;
    case '3': modify();
		break;
    case '4': exit(0);
		break;
    default :cout<<"\a";
    getch();
  }

 }while(ch!='3');

 getch();


}

void intro()
{       clrscr();
	cout<<"\n\n\n\t\t  !!__  QUIZ GAME  __!!";
	cout<<"\n\n\t\t\" CHECK YOUR KNOWLEDGE \"";
	cout<<"\n\n\n\n\tPROJECT :- ";
	cout<<"\n\tMADE BY : INDERDEEP SINGH";
	cout<<"\n\tSCHOOL  : DELHI TECHNICAL CAMPUS";
	getch();
}

void play_quiz()
{
 clrscr();
 char ch;

 QUIZ_MATHS m;
 QUIZ_IQ iq;
 QUIZ_GK gk;
 do
 {
  clrscr();
  cout<<"\n\t\t!    SELECT QUIZ TOPIC TO PLAY    !"<<endl;
  cout<<setw(100)<<setfill(95);
  cout<<"\n\n\t\t\t1. MATHS \n   \t\t\tCheck your claculations "<<endl<<endl;
  cout<<"\t\t\t2. IQ\n   \t\t\tI know you are smart\n"<<endl;
  cout<<"\t\t\t3. GK\n   \t\t\tCheck Knowledge \n"<<endl;
  cout<<"\t\t\t4. MAIN MENU"<<endl<<endl;

  cout<<"Enter Your Choice :";
  cin>>ch;

  switch(ch)
  {
    case '1': m.play();
		break;
    case '2': iq.play();
		break;
    case '3': gk.play();
		break;
    case '4':  main_menu();
	       break;
    default :cout<<"\a";
    getch();
  }

 }while(ch!='3');

 getch();

}

void make()
{
 char ch;
 do
 {
  clrscr();
  cout<<"\n\t\t!    SELECT QUIZ TOPIC FOR CREATE    !"<<endl;
  cout<<setw(60)<<setfill(95)<<"\n\n";
  cout<<"\t\t\t1. MATHS  "<<endl;
  cout<<"\t\t\t2. IQ"<<endl;
  cout<<"\t\t\t3. GK"<<endl;
  cout<<"\t\t\t4. EXIT"<<endl<<endl;

  cout<<"Enter Your Choice :";
  cin>>ch;

  switch(ch)
  {
    case '1': QUIZ_MATHS m;
	      m.create();
		break;
    case '2':  QUIZ_IQ iq;
	       iq.create();
		break;
    case '3':  QUIZ_GK gk;
	       gk.create();
		break;
    case '4':  main_menu();
	       break;
    default :cout<<"\a";
    getch();
  }

 }while(ch!='3');

 getch();
}

void modify()
{
 clrscr();
 int ch;
 cout<<"\n\t\t\tSELECT ONE :"<<endl;
 cout<<setw(60)<<setfill(95)<<"\n\n\n";
 cout<<"\t\t1. DELETE QUIZ "<<endl;
 cout<<"\t\t2. EDIT QUESTIONS "<<endl;
 cout<<"\t\t3. MAIN MENU "<<endl;
 cout<<"\n\nEnter your choice :";
 cin>>ch;

 switch(ch)
 {
  case 1:   m_del();
	    break;
  case 2:   m_edit();
	    break;

  default : cout<<"Enter the Correct choice"<<endl;
 }

 main_menu();
 getch();
}

void m_del()
{
 clrscr();
 int ch;
 cout<<"\n\t\t\tSELECT TOPIC :"<<endl;
 cout<<setw(60)<<setfill(95)<<"\n\n\n";
 cout<<"\t\t1. MATHS "<<endl;
 cout<<"\t\t2. IQ "<<endl;
 cout<<"\t\t3. GK "<<endl;
 cout<<"\n\nEnter your choice :";
 cin>>ch;

 switch(ch)
 {
  case 1: QUIZ_MATHS m;
	    m.del();
	    break;
  case 2: QUIZ_IQ i;
	    i.del();
	    break;

 case 3: QUIZ_GK g;
	    g.del();
	    break;
  default : cout<<"Enter the Correct choice"<<endl;
 }

 main_menu();
 getch();
}
void m_edit()
{
 clrscr();
 int ch;
 cout<<"\n\t\t\tSELECT QUIZ TOPIC TO MODIFY:"<<endl;
 cout<<setw(60)<<setfill(95)<<"\n\n\n";
 cout<<"\t\t1. MATHS "<<endl;
 cout<<"\t\t2. GK "<<endl;
 cout<<"\t\t3. IQ "<<endl;
 cout<<"\n\nEnter your choice :";
 cin>>ch;

 switch(ch)
 {
  case 1: QUIZ_MATHS m;
	    m.modify_q();
	    break;
  case 2: QUIZ_GK M;
	    M.modify_q();
	    break;

  case 3: QUIZ_IQ i;
	    i.modify_q();
	    break;
  default : cout<<"Enter the Correct choice"<<endl;
 }

 main_menu();
 getch();
}
