//header file
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
//global variable strcmp
//--------------------------------------------------------------------------------------------------------------
int test;
int test1;
int test2;
int test3;
int test4;
int result;
int flag=0;
int *ptr;

//user class
//---------------------------------------------------------------------------------------------------------------
class USER
{
public:
char date[20];
char name[20];
char mobile_no[15];
char father_name[20];
char mother_name[20];
char birth_place[20];
char user_password[20];
char present_address[100];
char permanent_address[100];
int i,n;
void write();
void uservarification(char use[20],char pa[20],int*t);
};

//base class search and parent class user
//----------------------------------------------------------------------------------------------------------------
class SEARCH: public USER
{
public:
	void display(char da[]);
	void advancedisplay(int  x);
};
//write function
//----------------------------------------------------------------------------------------------------------------
void USER:: write()
{
	FILE *fp;
	char dat[20];
	char nam[20];
	char mobile_n[15];
	char father_nam[20];
	char mother_nam[20];
	char birth_plac[20];
	char user_passwor[20];
	char present_addres[100];
    char permanent_addres[100];

	cout<<"\n\n\tENTER BIRTHDAY DATE (DD/MM/YYYY)                  ::";
	scanf("%s",dat);
	cout<<"\tENTER NAME              (FIRST_MID_LAST)          ::";
	scanf("%s",nam);
	cout<<"\tENTER PASSWORD                                    ::";
	scanf("%s",user_passwor);
	cout<<"\tENTER BIRTH PLACE       (DISTRICT)                ::";
	scanf("%s",birth_plac);
	cout<<"\tENTER MOBILE NUMBER     (+880)                    ::";
	scanf("%s",mobile_n);
	cout<<"\tENTER FATHER NAME       (FIRST_MID_LAST)          ::";
	scanf("%s",father_nam);
	cout<<"\tENTER MOTHER NAME       (FIRST_MID_LAST)          ::";
	scanf("%s",mother_nam);
	cout<<"\tENTER PRESENT ADDRESS   (NO SPACE)                ::";
	scanf("%s",present_addres);
	cout<<"\tENTER PERMANENT ADDRESS (NO SPACE)                ::";
	scanf("%s",permanent_addres);

	fp=fopen("record.txt","a");
	fprintf(fp,"\n%s  %s  %s  %s  %s  %s  %s  %s  %s\n",dat,nam,user_passwor,birth_plac,mobile_n,father_nam,mother_nam,present_addres,permanent_addres);
	cout<<"\n     record written successfully!!!!!\n\n\n\n";
	fclose(fp);
}

void USER::uservarification(char use[20],char pa[20],int*t)
{
    FILE *fp;
	fp=fopen("record.txt ","r");
    while(fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",date,name,user_password,birth_place,mobile_no,father_name,mother_name,present_address,permanent_address)!=EOF)
        {
		    test=strcmp(use,name);
		    test1=strcmp(pa,user_password);
			if((test==0)&&(test1==0))
			{
			    *t=1;
			}else{}

		}//closing while loop
	fclose(fp);


}

//advance search by admin
//--------------------------------------------------------------------------------------------------------------------
void SEARCH::advancedisplay(int  x)
{   char d[20];
    char na[20];
    char birth_pla[20];
    char mobile[20];
    char father_na[20];
    char mother_na[20];

	FILE *fp;
	fp=fopen("record.txt ","r");
	while(fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",date,name,user_password,birth_place,mobile_no,father_name,mother_name,present_address,permanent_address)!=EOF)//starting while loop
		{
    if(x==5){
                cout<<"\n\n\tENTER BIRTHDAY DATE (DD/MM/YYYY)                  ::";
                scanf("%s",d);
                cout<<"\tENTER NAME              (FIRST_MID_LAST)          ::";
                scanf("%s",na);
                cout<<"\tENTER BIRTH PLACE       (DISTRICT)                ::";
                scanf("%s",birth_pla);
                cout<<"\tENTER MOBILE NUMBER     (+880)                    ::";
                scanf("%s",mobile);
                cout<<"\tENTER FATHER NAME       (FIRST_MID_LAST)          ::";
                scanf("%s",father_na);
                cout<<"\tENTER MOTHER NAME       (FIRST_MID_LAST)          ::";
                scanf("%s",mother_na);
                result=strcmp(d,date);
                test=strcmp(na,name);
                test1=strcmp(birth_pla,birth_place);
                test2=strcmp(mobile,mobile_no);
                test3=strcmp(father_na,father_name);
                test4=strcmp(mother_na,mother_name);
                if((result==0)||(test==0)||(test1==0)||(test2==0)||(test3==0)||(test4==0)){

                cout<<"\n BIRTHDAY DATE     :: "<<date<<endl;
				cout<<"\n NAME              :: "<<name<<endl;
				cout<<"\n BIRTH PLACE       :: "<<birth_place<<endl;
	 			cout<<"\n MOBILE NUMBER     :: "<<mobile_no<<endl;
				cout<<"\n FATHER NAME       :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME       :: "<<mother_name<<endl;
				cout<<"\nPRESENT ADDRESS    ::"<<present_address<<endl;
                cout<<"\nPERMANENT ADDRESS  ::"<<permanent_address<<endl;
				cout<<"-----------------------------------------\n";
                   }else{}
			}else{}}//closing while loop
	fclose(fp);
}

//basic search by user
//------------------------------------------------------------------------------------------------------------------
void SEARCH ::display(char da[])
{
	FILE *fp;
	fp=fopen("record.txt ","r");
while(fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",date,name,user_password,birth_place,mobile_no,father_name,mother_name,present_address,permanent_address)!=EOF)
    {
			result=strcmp(da,date);
            test=strcmp(da,name);
            test1=strcmp(da,birth_place);
            test2=strcmp(da,mobile_no);
            test3=strcmp(da,father_name);
            test4=strcmp(da,mother_name);
			if(result==0)//check by birthday date
			{
				cout<<"\n NAME          :: "<<name<<endl;
				cout<<"\n BIRTH PLACE   :: "<<birth_place<<endl;
				cout<<"\n FATHER NAME   :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME   :: "<<mother_name<<endl;
				cout<<"-----------------------------------------\n";
			}else if(test==0){//check by birth place
			    cout<<"\n NAME          :: "<<name<<endl;
				cout<<"\n BIRTH PLACE   :: "<<birth_place<<endl;
				cout<<"\n FATHER NAME   :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME   :: "<<mother_name<<endl;
				cout<<"-----------------------------------------\n";
			}else if(test1==0){//check by phone no
			    cout<<"\n NAME          :: "<<name<<endl;
				cout<<"\n BIRTH PLACE   :: "<<birth_place<<endl;
				cout<<"\n FATHER NAME   :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME   :: "<<mother_name<<endl;
				cout<<"-----------------------------------------\n";
			}else if(test2==0){//check by father name
			    cout<<"\n NAME          :: "<<name<<endl;
				cout<<"\n BIRTH PLACE   :: "<<birth_place<<endl;
				cout<<"\n FATHER NAME   :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME   :: "<<mother_name<<endl;
				cout<<"-----------------------------------------\n";
			}else if(test3==0){//check by mother name
			    cout<<"\n NAME          :: "<<name<<endl;
				cout<<"\n BIRTH PLACE   :: "<<birth_place<<endl;
				cout<<"\n FATHER NAME   :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME   :: "<<mother_name<<endl;
				cout<<"-----------------------------------------\n";
			}else if(test4==0){
			    cout<<"\n NAME          :: "<<name<<endl;
				cout<<"\n BIRTH PLACE   :: "<<birth_place<<endl;
				cout<<"\n FATHER NAME   :: "<<father_name<<endl;
				cout<<"\n MOTHER NAME   :: "<<mother_name<<endl;
				cout<<"-----------------------------------------\n";
			}
			else{}

		}//closing while loop
	fclose(fp);
}//closing display function


//main function
//-----------------------------------------------------------------------------------------------------------------------
int main()
{
    USER a;
    SEARCH b;

    int ok;// user verification
    char ch;
	char lm[20];
	char userId[30]="2015-1-60-130";
    char userI[30];
    char password[15]="ewu2015";
    char pass[15];int k;
	do// starting main menu do-while loop
		{
		    out:
		    system("CLS");
			cout<<"\n\t----------------------------MAIN MENU----------------------------";
			cout<<"\n\t|                                                               |";
			cout<<"\n\t|             (A)dmin                                           |";
			cout<<"\n\t|             (U)ser                                            |";
			cout<<"\n\t|             (Q)uit                                            |";
			cout<<"\n\t|                                                               |";
			cout<<"\n\t----------------------------MAIN MENU----------------------------";

			cout<<"\n\tENTER YOUR CHOICE:: ";
			cin>>ch;
				switch(ch)
					{
                    case 'a':cout<<"\tENTER YOUR USER ID :";
                             cin>>userI;
                             cout<<"\tENTER YOUR PASSWORD :";
                             cin>>pass;
                             test1=strcmp(userI,userId);
                             test=strcmp(pass,password);
                             if(test==0&&test1==0){
                             do     //starting admin do-while loop
                             {
                                system("CLS");
                                cout<<"\n\t----------------------------ADMIN MENU----------------------------";
                                cout<<"\n\t|                                                                |";
                                cout<<"\n\t|              (N)ew Entry User                                  |";
                                cout<<"\n\t|              (A)dvance Search                                  |";
                                cout<<"\n\t|              (L)ogout                                          |";
                                cout<<"\n\t|                                                                |";
                                cout<<"\n\t----------------------------ADMIN MENU----------------------------";

                                cout<<"\n\tENTER YOUR CHOICE:: ";
                                cin>>ch;
                                    switch(ch)
                                        {
                                        case 'n': a.write();
                                                 break;

                                        case 'a':system("CLS");
                                                k=5;
                                                b.advancedisplay(k);
                                                system("PAUSE ");
                                                break;

                                        case 'l': goto out;

                                        default:cout<<"\n INVALID CHOICE!!!!!!";
                                        }
                                    }while(ch!='l');}else{}
                                     break;
					case 'u':cout<<"\tENTER YOUR USER NAME :";
                             cin>>userI;
                             cout<<"\tENTER YOUR PASSWORD :";
                             cin>>pass;
                             a.uservarification(userI,pass,&ok);
                             if(ok==1){
                             do   //starting user do-while loop
                             {  in:
                                system("CLS");
                                cout<<"\n\t----------------------------USER MENU----------------------------";
                                cout<<"\n\t|                                                               |";
                                cout<<"\n\t|             (S)earch Other User Basic info                    |";
                                cout<<"\n\t|             (L)ogout                                          |";
                                cout<<"\n\t|                                                               |";
                                cout<<"\n\t----------------------------USER MENU----------------------------";

                                cout<<"\n\tENTER YOUR CHOICE:: ";
                                cin>>ch;
                                    switch(ch)
                                        {
                                        case 's':do//starting user basic search do-while loop
                                              {
                                                system("CLS");
                                                cout<<"\n\t----------------------------USER SEARCH--------------------------";
                                                cout<<"\n\t|             SEARCH BY:                                        |";
                                                cout<<"\n\t|             (U)ser Name                                       |";
                                                cout<<"\n\t|             (B)irthday Date                                   |";
                                                cout<<"\n\t|             (D)isrict                                         |";
                                                cout<<"\n\t|             (G)o toUser menu                                  |";
                                                cout<<"\n\t|                                                               |";
                                                cout<<"\n\t----------------------------MAIN MENU----------------------------";

                                                cout<<"\n\tENTER YOUR CHOICE:: ";
                                                cin>>ch;
                                                    switch(ch)
                                                        {
                                                        case 'u':system("CLS");
                                                                cout<<"\n\nENTER NAME          (FIRST_MID_LAST)      ::";
                                                                scanf("%s",lm);
                                                                b.display(lm);
                                                                system("PAUSE ");
                                                                break;
                                                        case 'b':system("CLS");
                                                                cout<<"\n\nENTER    BIRTHDAY DATE (DD/MM/YYYY)      ::";
                                                                scanf("%s",lm);
                                                                b.display(lm);
                                                                system("PAUSE ");
                                                                break;
                                                        case 'd':system("CLS");
                                                                cout<<"\n\nENTER    DISTRICT NAME                   ::";
                                                                scanf("%s",lm);
                                                                b.display(lm);
                                                                system("PAUSE ");
                                                                break;


                                                        case 'g': goto in;

                                                        default:cout<<"\n INVALID CHOICE!!!!!!";
                                                        }
                                                        }
                                                    while(ch!='g');
                                                system("PAUSE ");
                                                break;

                                        case 'l': goto out;

                                        default:cout<<"\n INVALID CHOICE!!!!!!";
                                        }
                                        }
                                    while(ch!='l');}else{}
                               break;

					case 'q': exit(0);

					 default:cout<<"\n INVALID CHOICE!!!!!!";
					}
				}while(ch!='q');

}//closeing main

