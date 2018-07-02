
//        CLASS QUIZ

class QUIZ
{

 private:

  int marks,q_num;
  char ques[500],correct,answer;
  char op1[100],op2[100],op3[100],op4[100];

public:
  void getdata();
  float putdata();

  void write_quiz(char *);
  void display_quiz(char *ch);
  void modify_quiz(char *);
  void create_quiz();
};

//       QUIZ FUNCTIONS DEFINATIONS

void QUIZ::getdata()
 {
	clrscr();

	cout<<"\n_________________________________\n\n";
	cout<<"Enter The Question :";
	gets(ques);

	cout<<"\nEnter The Option 1 : ";
	gets(op1);

	cout<<"\nEnter The Option 2 : ";
	gets(op2);

	cout<<"\nEnter The Option 3 : ";
	gets(op3);

	cout<<"\nEnter The Option 4 : ";
	gets(op4);

	cout<<"\n_________________________________\n\n";

	cout<<"ENTER THE CORRECT OPTION NUMBER :";
	cin>>correct;
 }

float QUIZ::putdata()
 {
	clrscr();

	cout<<setw(60)<<setfill(95)<<endl;
	cout<<"\n\nQuestion "<<q_num<<":";
	puts(ques);
	cout<<setw(60)<<setfill(95)<<"\n";
	cout<<"\n\tOption 1 : ";
	puts(op1);

	cout<<"\n\tOption 2 : ";
	puts(op2);

	cout<<"\n\tOption 3 : ";
	puts(op3);

	cout<<"\n\tOption 4 : ";
	puts(op4);

	cout<<"\nENTER THE CORRECT OPTION :";
	cin>>answer;
	if(answer==correct)
	   {clrscr();cout<<"\n\t\t!! CORRECT  !!";return(marks);}
	else
	    {clrscr();cout<<"\n\t\t\t#   WRONG   #";return(-marks);}

	   return(0);
 }

void QUIZ::write_quiz(char *name)
{
	clrscr();
	QUIZ qt;
	int num;
	ofstream outFile;
	outFile.open(name,ios::app|ios::binary);

	cout<<"Enter the number of questions\n";
	cin>>num;
	cout<<"\n\nENTER THE MARKS OF EACH QUESTION :";
	 cin>>marks;


	for(int i=1;i<=num;i++)
	 {
	  qt.getdata();
	  qt.q_num=i;
	  qt.marks=marks;
	  outFile.write((char *) &qt, sizeof(QUIZ));
	  getch();
	 }
	outFile.close();
	clrscr();
	cout<<"\n\n\n\n\t\tQuiz Has Been Created ";
	getch();
	return;
}


void QUIZ::display_quiz(char *file)
{
	clrscr();
	int student;
	QUIZ qt;
	int i=0,score,k=0,j=0;

	ifstream inFile;
	inFile.open(file,ios::binary);

	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	cout<<"\n\n\n\t\tDISPLAY ALL QUIZ !!!\n\n";

	while(inFile.read((char *) &qt, sizeof(QUIZ)))
	    {

		i=qt.putdata();
		cout<<"\n\n=========================================="<<endl;
		if(i>0)
		  {score+=i;if(k==0){k=i;}}
		else if(i<0)
		   {if(k==0){k=(-1)*i;}}

		++j;

	       getch();
	     }

	  clrscr();

	cout<<"\n\n\t\t\t!! YOUR SCORE !!\n\n\n\t\t\t\t"<<score<<"/"<<k*j;
	cout<<"\n\n\n\t\t !!  THANKS FOR PLAYING  !!";

	inFile.close();
	getch();
	return;
}




void QUIZ::modify_quiz(char *file)
{
	clrscr();
	int found=0,n,mark;
	QUIZ q;
	fstream File;
	File.open(file,ios::binary|ios::in|ios::out);

       if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}


       cout<<"\n\n !! FILE FOUND !!";

       cout<<"\n\n !! Enter the question number to edit\n";
       cin>>n;


	while(File.read((char *) &q, sizeof(QUIZ)) && found==0)
	{
		if(q.q_num==n)
		{
			clrscr();
			cout<<"\n\n SIMULATE THE QUESTION BEFORE EDIT"<<endl;
                        getch();
			q.putdata();
			cout<<"\n\nPress Enter TO Add New Question"<<endl;
			getch();
			mark=q.marks;
			q.getdata();
			q.marks=mark;
                        q.q_num=n;
			int pos=(-1)*sizeof(q);
			File.seekp(pos,ios::cur);
			File.write((char *) &q, sizeof(QUIZ));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}



