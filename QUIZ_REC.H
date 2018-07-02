

//                       CLASS QUIZ RECORD

class QUIZ_RECORD:public QUIZ
{

 char quiz_name[50],name[30],pass[30];
 int num_quiz;

 public:

   int num;
   int ch;
   void get_record();
   void put_record();

   char *write_record(QUIZ_RECORD *ptr);
   void read_record(QUIZ_RECORD *ptr);
   void delete_record(QUIZ_RECORD *ptr);
   char *get_quiz_name();

   virtual char *getfile()
    {
     clrscr();
     return("NULL");
    }
  ~QUIZ_RECORD(){}
};

//               CLASS QUIZ_RECORD FUNCTION DEFINATIONS



char* QUIZ_RECORD::get_quiz_name()
{

  cout<<"\n_______________________________________"<<endl;
  cout<<"\n\nENTER THE QUIZ KEY TO PLAY : ";
  cin>>ch;

  QUIZ_RECORD qr;

  ifstream inFILE;
  inFILE.open(getfile(),ios::binary);

  while(inFILE.read((char *) &qr,sizeof(QUIZ_RECORD)))
   {
    if(ch==qr.num)
    {
	getch();
        return(strcat(qr.quiz_name,".txt"));
    }
   }
}



void QUIZ_RECORD::get_record()
{
 clrscr();
 char confirm;
 cout<<"\n\n\n\tEnter the new quiz deails"<<endl;
 cout<<"\n\n\nENTER THE QUIZ KEY :"<<endl;
 cin>>num;
 cout<<"\n\nENTER YOUR NAME"<<endl;
 gets(name);
 cout<<"\n\nGIVE YOUR QUIZ A NAME"<<endl;
 gets(quiz_name);
 cout<<"\n\nSET PASSWORD :"<<endl;
 gets(pass);
 getch();
}



void QUIZ_RECORD::put_record()
{
 cout<<num<<"\t"<<quiz_name<<"\t"<<"BY - "<<name;
}

char * QUIZ_RECORD::write_record(QUIZ_RECORD *ptr)
{
 QUIZ_RECORD qr;
 ofstream outFILE;
 char *file_name=ptr->getfile();

 qr.read_record(ptr);
 cout<<"\n\nt\t\tEXISTING QUIZ";
 qr.get_record();
 cout<<"\n\nNOTE: DON'T TAKE QUIZ KEY FROM EXISTING QUIZ NUMBER";

 outFILE.open(file_name,ios::binary|ios::app);

 if(!outFILE)
 {
  cerr<<"FILE NOT EXIST"<<endl;
  getch();
  return(NULL);
 }

 outFILE.write((char *) (&qr),sizeof(QUIZ_RECORD));
 outFILE.close();

 return(strcat(qr.quiz_name,".txt"));
}

void QUIZ_RECORD::read_record(QUIZ_RECORD *ptr)
{
 QUIZ_RECORD qr;
 ifstream inFILE;
 char *name=ptr->getfile();

 inFILE.open(name,ios::binary);

 if(!inFILE)
  {
   clrscr(); 
   cerr<<"\n\n\tCURRENTLY RECORD FILE IS NOT CREATED FOR THIS TOPIC"<<endl;
   cerr<<"\n\nTo create go to create quiz and enter twice to create new one"<<endl;
   cerr<<"\n\n\t If you already in create quiz press enter to create quiz";

   getch();
   return;
  }

 clrscr();
 cout<<"\t\n --QUIZ KEY -- QUIZ NAME - -QUIZ AUTHOR "<<endl;
 while(inFILE.read((char *) &qr,sizeof(QUIZ_RECORD)))
  {
   qr.put_record();
   cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
  }

  inFILE.close();
  getch();
}



void QUIZ_RECORD::delete_record(QUIZ_RECORD *ptr)
{

	clrscr();
	QUIZ_RECORD rt;
	ifstream inFile;
	int n;
	char confirm[30];
	char *ch=ptr->getfile(),*del;

	inFile.open(ch,ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	ofstream outFile;
	outFile.open("Temp.txt",ios::out);
	inFile.seekg(0,ios::beg);

	cout<<"\n\nEnter the Quiz Key to DELETE"<<endl;
	cin>>n;
	cout<<"\n\nEnter the password :"<<endl;
	gets(confirm);

	while(inFile.read((char *) &rt, sizeof(QUIZ_RECORD)))
	{
                //cout<<"OUT"<<rt.quiz_name<<endl;getch();
		if(rt.num!=n&&confirm!=pass)
		{
                 //        cout<<"IN"<<rt.quiz_name;getch();
			outFile.write((char *) &rt, sizeof(QUIZ_RECORD));
		}
                else
                   {del=strcat(rt.quiz_name,".txt");}
	}
	outFile.close();
	inFile.close();
	remove(ch);
        //cout<<"del"<<del;getch();
        remove(del);
	rename("Temp.txt",ch);
	cout<<"\n\n\tRecord Deleted ..";
	getch();}
