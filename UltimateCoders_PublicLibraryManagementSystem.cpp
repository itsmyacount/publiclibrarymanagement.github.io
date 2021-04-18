#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<cstdlib>                                                 //Include directives
using namespace std;

//*******************************Declaring a class************************************
class Lib
{
   public:                                                           //Access Specifier
       char bookname[100],authorname[50],bookid[20],pubname[50],studentname[100],studentid[100];
       int quantity,Month,price,date,year,shelfno,referencebook;
       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(authorname,"No Author Name");
           strcpy(bookid,"No Book ID");
           strcpy(pubname,"No Publication");
           strcpy(studentname,"No name");
           strcpy(studentid,"No Student ID");
           quantity=0;
           Month=0;
           price=0;
           shelfno=0;
           referencebook=0;
       }
          void librarian();
          void getdata();
          void show();
          void booklist();
          void add();
          void member();
          void issue();
};
void Lib::member()                   //Outside class defination of object of class lib
{
    system("cls");
     ofstream outstream5;                            //making an output stream variable
     outstream5.open("member.txt",ios::binary);                        //Opening a file
                if(!outstream5)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    fflush(stdin);                                    //To Clear screen
    char memname[100],id[50];
    long int mobilenum;
    cout<<"\n\t\tEnter member name : ";
    cin.getline(memname,100);
    cout<<"\n\t\tEnter member id : ";
    cin.getline(id,50);
    cout<<"\n\t\tEnter mobile number : ";
    cin>>mobilenum;
    cout<<"\n\t\tMember Added Successfully";
    cout<<"\n\t\tEnter anything to return to the main menu: ";
    getch();
    system("cls");
    librarian();
                }

    outstream5.close();                                              //closing the file
}
void Lib::getdata()                   //Outside class defination of object of class lib
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(bookname,100);
                    for(i = 0;bookname[i] != '\0';i++)
                    {
                    if(bookname[i]>='a' && bookname[i]<='z')
                       bookname[i]-=32;
                    }
                    cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(authorname,50);
                    cout<<"\n\t\tEnter Publication name : ";
                    cin.getline(pubname,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(bookid,20);
                    cout<<"\n\t\tEnter Book's Price(in CAD) : ";
                    cin>>price;
                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>quantity;
                    cout<<"\n\t\tEnter Book's shelf no : ";
                    cin>>shelfno;
                    cout<<"\n\t\tEnter 1 if it is refrence book : ";
                    cin>>referencebook;
}
void Lib::show()                      //Outside class defination of object of class lib
{
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<authorname<<endl;
    cout<<"\n\t\tBook's ID : "<<bookid<<endl;
    cout<<"\n\t\tBook's Publication : "<<pubname<<endl;
    cout<<"\n\t\tBook's Price(in CAD) : "<<price<<endl;
    cout<<"\n\t\tBook's Quantity : "<<quantity<<endl;
    cout<<"\n\t\tBook is present in shelf: "<<shelfno<<endl;
    if(referencebook==1)
    {
        cout<<"\n\tThis is a Reference book\n\t";
    }
}
  void Lib::booklist()                //Outside class defination of object of class lib
  {
                int i,k=0;
                system("cls");
                ifstream instream5("Booksledger.txt",ios::binary);     //reading a file
                if(!instream5)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    instream5.read((char*)this,sizeof(*this));
                while(!instream5.eof())
                {
                       if (quantity!=0)
                            {
                                k++;
                                cout<<"\n\t\t********** "<<k<<". ********** \n";
                                show();
                            }
                    instream5.read((char*)this,sizeof(*this));
                }
                instream5.close();                                   //closing the file
  }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");

                    librarian();
    }
void Lib::add()                       //Outside class defination of object of class lib
{
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Add New Book\n\n\t\t2.Go back to main menu\n";
    cout<<"\n\n\t\tEnter your choice (Enter the numbers indicated with each option): ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    getdata();
                ofstream outf("Booksledger.txt",ios::app|ios::binary);// opening a file
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully.\n";
                    cout<<"\n\t\tEnter anything to go back to main menu: ";
            getch();
            system("cls");
            librarian();
            outf.close();                                            //closing the file
            cout<<"Book added successfully.";
    }
    else
    {
    system("cls");
    librarian();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();
  }
void Lib::issue()                     //Outside class defination of object of class lib
{
    char st[50],st1[20],ch1[100],ch3[100];
    int b,i,j,d,m,y,dd,mm,yy,cont=0,t;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.Go back to Main Menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    int t=0;
    system("cls");
    cout<<"\n\t\t->Please Enter Details : \n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(ch3,100);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(bookid,20);
    cout<<"\n\t\tEnter author's name : ";
    cin.getline(ch1,100);
    cout<<"\n\t\tEnter Member Name : ";
    cin.getline(studentname,100);
    cout<<"\n\t\tEnter Member's ID : ";
    cin.getline(studentid,100);
    cout<<"\n\t\tEnter date(in dd mm yyyy(Please use space as indicated) format) : ";
    cin>>d>>Month>>year;
    ofstream outf("issue.txt",ios::binary|ios::app);                   //opening a file
    outf.write((char*)this,sizeof(*this));
    outf.close();                                                    //closing the file
    cout<<"\n\n\t\tIssue Successfully.\n";
    int ch;
    cout<<"\n\n\t\tDo you want to see some Recommendations from the same author or some reference book(if yes then press 1 else 2)\n\t\t";
    cin>>t;
    if(t==1)
    {
        system("cls");
        cout<<"\n\n\t1.Enter 1 for Books From Same Author\n\n\t2.For Reference Books\t\n\n\t3.Go back to main menu\n\n\t\tEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
        fflush(stdin);
        ifstream instream("Booksledger.txt",ios::binary);           //reading from file
        instream.read((char*)this,sizeof(*this));
        while(!instream.eof())
          {
            for(i=0;authorname[i]!='\0'&&ch1[i]!='\0'&&ch1[i]==authorname[i];i++);
             if(authorname[i]=='\0'&&ch1[i]=='\0')
                {
                            cout<<"\n\t\tOther Books from same author are:-\n";
                            show();
                            break;
                }
            else
            {
                cout<<"No other book of the same author is present";
                cout<<"\n\t\tEnter any thing to go back to main menu:";
            getch();
            system("cls");
            librarian();
            break;
            }
              instream.read((char*)this,sizeof(*this));
          }
          instream.close();                                            //closing a file
        }
        case 2:
            {
            fflush(stdin);
            fstream instream("Booksledger.txt",ios::binary);        //reading from file
            instream.read((char*)this,sizeof(*this));
            while(!instream.eof())
            {
              for(i=0;authorname[i]!='\0'&&ch1[i]!='\0'&&ch1[i]==authorname[i];i++);
             if(referencebook==1)
                {
                            cout<<"\n\t\t reference books are:-\n";
                            show();
                            break;
                }
            else
            {
                cout<<"No reference book present";
                cout<<"\n\t\tPlease enter correct option :";
            getch();
            system("cls");
            librarian();
            break;
            }
              instream.read((char*)this,sizeof(*this));
          }
          instream.close();                                            //closing a file
            }cout<<"\n\t\tEnter anything to return to the main menu: \n";
    getch();
    system("cls");
    librarian();
    }
    }
    else{
        system("cls");
        librarian();
    }
    }
    else if(i==2)
    {
        system("cls");
        librarian();

    }
}
void Lib::librarian()                 //Outside class defination of object of class lib
{
    int i;
        cout<<"\n\t*************** MAIN MENU *****************\n";
        cout<<"\n\t\tPlease Choose One Option:\n";
        cout<<"\n\t\t1.View Booklist\n\n\t\t2.Add a Book\n\n\t\t3.Issue Book\n\n\t\t4.Add a member\n\n";
        cout<<"\n\t\tEnter your choice (Enter the numbers indicated with each option): ";
        cin>>i;
        switch(i)
        {
            case 1:booklist();                                     //calling a function
                     break;
            case 2:add();                                          //calling a function
                     break;
            case 3:issue();                                        //calling a function
                     break;
            case 4:member();                                       //calling a function
                     break;
            default:cout<<"\n\t\tPlease enter correct option :";
            getch();
            system("cls");
            librarian();
        }
}
int main()
{
    Lib obj; //                                enstantiating an object out of class Lib
    obj.librarian();                      //calling the memberfunction of the class lib
    getch();
    return 0;
}
