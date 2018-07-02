//            CLASS MATHS

class QUIZ_MATHS:public QUIZ_RECORD
{
 public :
  void play();
  void create();
  void del();
  void modify_q();
  char *getfile();
};

char * QUIZ_MATHS::getfile()
{
  return("record1.txt");
}

void QUIZ_MATHS::play()
 {
    QUIZ_MATHS m;
    read_record(&m);
    display_quiz(get_quiz_name());
    getch();
 }

void QUIZ_MATHS::create()
 {
   QUIZ_MATHS m;
   read_record(&m);
   write_quiz(write_record(&m));
 }

void QUIZ_MATHS::del()
{
  QUIZ_MATHS m;
  read_record(&m);
  delete_record(&m);
}

void QUIZ_MATHS::modify_q()
{
  QUIZ_MATHS m;
   read_record(&m);
  modify_quiz(get_quiz_name());
}

//                      CLASS IQ

class QUIZ_IQ:public QUIZ_RECORD
{
 public :
  void play();
  void create();
  void del();
  void modify_q();
  char *getfile();
};

char * QUIZ_IQ::getfile()
{
  return("record2.txt");
}

void QUIZ_IQ::play()
 {
    QUIZ_IQ m;
    read_record(&m);
    display_quiz(get_quiz_name());
    getch();
 }

void QUIZ_IQ::create()
 {
   QUIZ_IQ m;
    read_record(&m);
   write_quiz(write_record(&m));
 }

void QUIZ_IQ::del()
{
  QUIZ_IQ m;
 read_record(&m);
  delete_record(&m);
}

void QUIZ_IQ::modify_q()
{
  QUIZ_IQ m;
 read_record(&m);
  modify_quiz(get_quiz_name());
}


//                CLASS QUIZ GK
 
class QUIZ_GK:public QUIZ_RECORD
{
 public :
  void play();
  void create();
  void del();
  void modify_q();
  char *getfile();
};

char * QUIZ_GK::getfile()
{
  return("record3.txt");
}

void QUIZ_GK::play()
 {
    QUIZ_GK m;
    read_record(&m);
    display_quiz(get_quiz_name());
    getch();
 }

void QUIZ_GK::create()
 {
   QUIZ_GK m;
 read_record(&m);
   write_quiz(write_record(&m));
 }

void QUIZ_GK::del()
{
  QUIZ_GK m;
 read_record(&m);
  delete_record(&m);
}

void QUIZ_GK::modify_q()
{
  QUIZ_GK m;
 read_record(&m);
  modify_quiz(get_quiz_name());
}



