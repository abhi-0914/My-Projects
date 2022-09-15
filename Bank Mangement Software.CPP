// Created To Run On Dosbox Only //
// !!! Must Set bgi Path According To their .bgi Directory before starting //

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<graphics.h>
#include<time.h>

// .bgi path initialization 
char *bgi="c:\\turboc3\\bgi";

//Some global Variables used in program
int totalaccounts=0,pass;
long int acnumber;
//main functions
void home();
void oneplus();
void loadingscreen();
void door();
void firstpage();
void rect_loading();

void accountservices();
void administrator();
void administrator_menu(int);
void sbimenu();
void sort_menu();

void add_interest();
void mab_charges();

void reset_admin();
void re_define();
int recaptcha();
void Default_records(int,int);
///account manipulation functions
void create_account();
void modify_account();
void close_account();
void convert_type();
/// basic account function
void account_history();
void search_account();
void display_account();
// functions to deposit or withdraw money
void deposit_amount();
void withdraw_amount();

void starting_config();
void create_labels(int, int);
void history_labels(int );
void design();
void design()
{
	cout<<endl;
	for(int i=0;i<80;i++)
	{
		cout<<"_";
	}
	cout<<endl;
}
void Exit();
void Exit()
{
	clrscr();
	cout<<'\n'<<'\n'<<'\t'<<" Terminating Program  . . . . . . . . . . . .";
	cout<<'\n'<<'\n'<<'\t'<<" Press Any Key - - - - > > > >";
	getch();
	abort();
}
void count_accounts();
void error_code01();
void error_code01()
{
	clrscr();
	cout<<'\n'<<'\n'<<'\n'<<":: TASK TERMINATED DUE TO MULTIPLE WRONG ATTEMPTS ::";
	cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
	getch();
	accountservices();
}
void task_complete();
void task_complete()
{
	clrscr();
	cout<<'\n'<<'\n'<<'\n'<<":: USER DEMAND EXIT ::";
	cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
	getch();
	accountservices();
}
void create_labels(int x,int y)
{
	gotoxy(1,y);
	cout<<"Sr.";
	gotoxy(x,y);
	cout<<"Ac No.";
	gotoxy(x+15,y);
	cout<<"UIN No.";
	gotoxy(x+25,y);
	cout<<"OWNER's Name";
	gotoxy(x+40,y);
	cout<<"Ac.Type";
	gotoxy(x+55,y);
	cout<<"Opening Balance";
	design();
}
void display_labels(int x,int y)
{
	gotoxy(1,y);
	cout<<"Sr.";
	gotoxy(x,y);
	cout<<"Ac No.";
	gotoxy(x+17,y);
	cout<<"UIN No.";
	gotoxy(x+30,y);
	cout<<"OWNER's Name";
	gotoxy(x+45,y);
	cout<<"Ac.Type";
	gotoxy(x+60,y);
	cout<<"Current Balance";
	design();
}
void modify_labels(int x,int y)
{
	gotoxy(x,y);
	cout<<"Acc. No.";
	gotoxy(x+15,y);
	cout<<"New UIN No.";
	gotoxy(x+30,y);
	cout<<"OWNER's Name";
	gotoxy(x+45,y);
	cout<<"Confirm Y/N";
	gotoxy(x+60,y);
	cout<<"Status";
	design();
}
void history_labels(int y)
{
	int x=1;
	gotoxy(x,y);
	cout<<"Sr No.";
	gotoxy(x+8,y);
	cout<<"Name.";
	gotoxy(x+22,y);
	cout<<"Date AND Time";
	gotoxy(x+50,y);
	cout<<"Debit";
	gotoxy(x+60,y);
	cout<<"Credit";
	gotoxy(x+70,y);
	cout<<"Balance";
	design();
}
class account
{
	long int acno;
	int uin;
	char acname[24];
	char actype[20];
	float acbalance;

	public:

	void create(int);
	void assigntype();
	void modify(int);
	void display(int);
	void Delete(int);

	void convert(char newtype[])
	{
		strcpy(actype,newtype);
	}

	void deposit(float add)
	{
		acbalance=acbalance+add;
	}
	void withdraw(float  draw)
	{
		acbalance=acbalance-draw;
	}

	char* ret_actype()
	{
		return(actype);
	}
	int ret_uin()
	{
		return(uin);
	}
	long int ret_acno()
	{
		return(acno);
	}
	float ret_acbalance()
	{
		return(acbalance);
	}
};
void display_sorted_account(account [],int);
void sort_account_number(account [],int,int);
void sort_account_balance(account [],int,int);
void filter_account_type(account [],int,int);
void filter_account_balance(account[],int,int);
struct admin
{
	char user_name[24];
	char password[16];
	float ir_sav;
	float ir_cur;
	float mab_sav;
	float mab_cur;
};
struct transaction
{
	long int acnum;
	char name[20];
	char res_time[30];
	float credit;
	float debit;
	float balance;

	void show(int);

};
void save_history(transaction);
void transaction::show(int y)
{
	int x=1;
	gotoxy(x+8,y);
	cout<<name;
	gotoxy(x+22,y);
	cout<<res_time;

	if(debit!=0)
	{
		gotoxy(x+50,y);
		cout<<debit;
	}
	if(credit!=0)
	{
		gotoxy(x+60,y);
		cout<<credit;
	}
	gotoxy(x+70,y);
	cout<<balance;
}
void account::assigntype()
{
	actype[0]=toupper(actype[0]);
	if(actype[0]=='C')
	{
		strcpy(actype,"Current");

	}
	else
	{
		strcpy(actype,"Savings");
	}
}
void account::create(int y)
{
	admin s1;
	fstream take("admin.txt",ios::in);
	take.read((char*)&s1,sizeof(s1));
	take.close();
	float sav,cur;
	cur=s1.mab_cur;
	sav=s1.mab_sav;
	gotoxy(1,1);
	cout<<"MAB Savings :: "<<sav;
	gotoxy(60,1);
	cout<<"MAB Current :: "<<cur;
	int x=5;
	acnumber=100000+random(200001);
	gotoxy(x,y);
	acno=acnumber;
	cout<<acno;
	int count1=0;
	again1:
	gotoxy(x+15,y);
	cout<<"***";
	gotoxy(x+15,y);
	cin>>uin;
	if(uin<100 || uin>999)
	{
		if(uin==0)
		{
		      task_complete();
		}
		else
		{
			gotoxy(x+15,y);
			cout<<"!!!";
			delay(300);
			gotoxy(x+15,y);
			cout<<"       ";
			count1++;
			if(count1>3)
			{
				error_code01();
			}
			goto again1;

		}
	}
	gotoxy(x+25,y);
	cin>>acname;
	if(acname[0]=='0')
	{
		task_complete();
	}
	gotoxy(x+40,y);
	cin>>actype;
	assigntype();
	int count2=0;
	again2:
	gotoxy(x+60,y);
	cin>>acbalance;
	if(((actype[0]=='S')&& acbalance<sav) || ((actype[0]=='C')&& acbalance<cur))
	{
		gotoxy(x+60,y);
		cout<<"!!!!";
		delay(300);
		gotoxy(x+60,y);
		cout<<"    ";
		count2++;
		if(count2>3)
		{
			 error_code01();
		}
		goto again2;

	}

	account objtemp;
	objtemp.acno=acno;
	objtemp.uin=uin;
	strcpy(objtemp.acname,acname);
	strcpy(objtemp.actype,actype);
	objtemp.acbalance=acbalance;
	fstream fout("accountlist.txt",ios::app);
	fout.write((char*)&objtemp,sizeof(objtemp));
	fout.close();
	++totalaccounts;
}
void account::modify(int y)
{
	int count1=0;
	long int num,pos;
	account temp;
	fstream fin("accountlist.txt",ios::in|ios::out);

	again1:
	int x=5;
	gotoxy(x,y);
	cin>>num;
	int found=0;
	if(num==0)
	{
		task_complete();
	}
	else if(num>10000)
	{
		while(fin.read((char*)&temp,sizeof(temp)))
		{
			pos=fin.tellg();
			if(temp.acno==num)
			{
				found=1;
				int count2=0;
				again:
				gotoxy(x+15,y);
				cout<<"***";
				gotoxy(x+15,y);
				cin>>uin;
				if(uin<100 || uin>999)
				{
					if(uin==0)
					{
						task_complete();
					}
					else
					{
						gotoxy(x+15,y);
						cout<<"!!!";
						delay(300);
						gotoxy(x+15,y);
						cout<<"       ";
						count2++;
						goto again;

					}
				}
				temp.uin=uin;
				gotoxy(x+30,y);
				cin>>temp.acname;
				char confirm_ch;
				gotoxy(x+45,y);
				cin>>confirm_ch;
				if(confirm_ch=='Y' || confirm_ch=='y')
				{
					fin.seekg(pos-sizeof(temp));
					fin.write((char*)&temp,sizeof(temp));
					gotoxy(x+60,y);
					cout<<"Modified";

				}
				else
				{
					gotoxy(x+60,y);
					cout<<"Unmodified";
				}
				break;

			}
		}
		if(found==0)
		{
			if(count1>3)
			{
				error_code01();
			}
			count1++;
			gotoxy(x,y);
			cout<<"          ";
			goto again1;
		}
	}
	else
	{
		if(count1>3)
		{
			error_code01();
		}
		count1++;
		gotoxy(x,y);
		cout<<"          ";
		goto again1;
	}
}
void account::display(int y)
{
	int x=5;
	gotoxy(x,y);
	cout<<acno;
	gotoxy(x+17,y);
	cout<<uin;
	gotoxy(x+30,y);
	cout<<acname;
	gotoxy(x+45,y);
	cout<<actype;
	gotoxy(x+60,y);
	cout<<acbalance;
}
void starting_config()
{
	int count1=0,count2=0,count3=0;
	fstream fin1("accountlist.txt",ios::in);
	if(!fin1)
	{
		count1=1;
	}
	fstream fin2("transaction.txt",ios::in);
	if(!fin2)
	{
		count2=1;
	}
	fstream fin3("admin.txt",ios::in);
	if(!fin3)
	{
		count3=1;
	}
	if(count1==1||count2==1||count3==1)
	{
		clrscr();
		char ch;
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<"         :: DATA FILE CONFIGURATION ERROR ::";
		design();
		int sr=1;
		cout<<'\n'<<'\n'<<'\t'<<"Following Data Files Were Not Found ---";
		if(count1==1)
		{
			cout<<'\n'<<'\n'<<'\t'<<sr<<". accountlist.txt   ---  File Storing Records";
			sr++;
		}
		if(count2==1)
		{
			cout<<'\n'<<'\n'<<'\t'<<sr<<". transaction.txt   ---  Stores Transaction History ";
			sr++;
		}
		if(count3==1)
		{
			cout<<'\n'<<'\n'<<'\t'<<sr<<". admin.txt         ---  Stores Administrator Details";
			sr++;
		}
		cout<<'\n'<<'\n'<<'\t'<<"Be Sure That These Files Are Present In The Directory Of Your System";
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Press( Y ) To Create Files Or Any Key To Restart Software -> > > :: ";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			Default_records(count1,count3);
			if(count2==1)
			{
				fstream fout("transaction.txt",ios::out);
				fout.close();
			}
		}
		else
		{
			exit(0);
		}
	 }
	 fstream take("pass.txt",ios::in);
	 if(!take)
	 {
		fstream out("pass.txt",ios::out);
		out<<"Proceed With Instructions In Create And Modify Accounts";
		pass=0;
	 }
	 else
	 {
		fstream out("pass.txt",ios::out);
		out<<"Skip Instructions In Create And Modify Accounts With Graphics";
		pass=1;
	 }
	 fin1.close();
	 fin2.close();
	 fin3.close();
	 take.close();
}
void count_accounts()
{
	account obj;
	fstream fin("accountlist.txt",ios::in);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		totalaccounts++;
	}
	fin.close();
}
void main()
{
	starting_config();
	count_accounts();
	if(pass==0)
	{
		home();
	}
	sbimenu();
	getch();
}
void sbimenu()
{
	clrscr();
	cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<"   :: STATE BANK OF INDIA ::";
	design();
	cout<<'\n'<<'\n'<<'\t'<<"ACCOUNT SERVICES                                    Press -> 1";
	cout<<'\n'<<'\n'<<'\t'<<"ADMINISTRATOR SERVICES                              Press -> 2";
	cout<<'\n'<<'\n'<<'\t'<<"Re-ialize Default Records                       Press -> 3";
	cout<<'\n'<<'\n'<<'\t'<<"Sort Out Accounts                                   Press -> 4";

	//cout<<'\n'<<'\n'<<'\t'<<"RESET ADMIN LOGIN DETAILS                           (Press R) ";
	cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Exit                                                Press -> 0 ";

	char *ch;
	cout<<'\n'<<'\n'<<'\n'<<'\t'<<"PLEASE ENTER YOUR CHOICE :: ";
	cin>>ch;
	int x=atoi(ch);

	if(x==1)
	{
		accountservices();
	}
	else if(x==2)
	{
		administrator();
	}
	else if(x==3)
	{
		re_define();
	}
	else if(x==4)
	{
		if(totalaccounts==0)
		{
			char ch;
			clrscr();
			cout<<"You Have Not Entered Any Records . . . . . . . .";
			cout<<'\n'<<'\n'<<"Press ( Y ) To Create Accounts :: ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				create_account();
			}
			else
			{
				sbimenu();
			}
		}
		else
		{
			sort_menu();
		}

	}
	else if(*ch=='R' || *ch=='r')
	{
		reset_admin();
	}
	else if(x==0)
	{
		Exit();
	}
	else
	{
		cout<<'\n'<<'\n'<<'\t'<<"!!! WRONG CHOICE";
		getch();
		sbimenu();
	}
}
void accountservices()
{
	clrscr();
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<"::  ACCOUNT  SERVICES  ::";
	design();
	cout<<'\t'<<"CREATE A NEW ACCOUNT                                Press -> 1 ";
	cout<<'\n'<<'\t'<<"MODIFY ACCOUNT DETAILS                              Press -> 2 ";
	cout<<'\n'<<'\t'<<"CLOSE AN ACCOUNT                                    Press -> 3 ";
	cout<<'\n'<<'\n'<<'\t'<<"ACCOUNT TYPE CONVERSION                             Press -> 4 ";

	cout<<'\n'<<'\n'<<'\t'<<"DEPOSIT AMOUNT                                      Press -> 5 ";
	cout<<'\n'<<'\t'<<"WITHDRAW AMOUNT                                     Press -> 6 ";

	cout<<'\n'<<'\n'<<'\t'<<"ACCOUNT HOLDERS LIST                                Press -> 7 ";
	cout<<'\n'<<'\t'<<"SEARCH AN ACCOUNT                                   Press -> 8 ";
	cout<<'\n'<<'\n'<<'\t'<<"ACCOUNT TRANSACTION HISTORY                         Press -> 9 ";

	cout<<'\n'<<'\n'<<'\t'<<"MAIN MENU                                           Press -> A ";
	cout<<'\n'<<'\t'<<"EXIT                                                Press -> 0 ";
	design();
	char *ch;
	cout<<'\t'<<"PLEASE ENTER YOUR CHOICE :: ";
	cin>>ch;
	int x=atoi(ch);

	int pass1,pass2;
	if(x==1)
	{
		create_account();
		pass1=1;
	}
	else if(x==2)
	{
		modify_account();
		pass2=1;
	}
	else if(x==3)
	{
		close_account();
	}
	else if(x==6)
	{
		withdraw_amount();
	}
	else if(x==5)
	{
		deposit_amount();
	}
	else if(x==4)
	{
		convert_type();
	}
	else if(x==7)
	{
		display_account();
	}
	else if(x==8)
	{
		search_account();
	}
	else if(x==9)
	{
		account_history();
	}
	else if(*ch=='a' || *ch=='A')
	{
		sbimenu();
	}
	else if(x==0)
	{
		Exit();
		sbimenu();

	}
	else
	{
		cout<<"!!! Wrong Choice ....";
		getch();
	}
	if(pass1==1 && pass2==1)
	{
		pass=1;
	}
	accountservices();
}
void create_account()
{
	account obj;
	admin s1;
	fstream take("admin.txt",ios::in);
	take.read((char*)&s1,sizeof(s1));
	take.close();
	float sav,cur;
	cur=s1.mab_cur;
	sav=s1.mab_sav;
	if(pass==0)
	{
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<"  :: CREATE ACCOUNTS  ::";
		design();
		cout<<"ATTENTION PLEASE NOTE THAT  ::: ";
		cout<<'\n'<<'\n'<<" !!!!  Enter 0 in Account Number OR in UIN Number Column To Stop Entering              Records After Creating Desired No. Of Accounts !!!";
		cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
		getch();
		design();
		cout<<"MINIMUM ACCOUNT BALANCE IS AS FOLLOWS :: ";
		cout<<'\n'<<'\n'<<"Saving account -> Greater than "<<sav;
		cout<<'\n'<<"Current Account -> Greater than "<<cur;
		cout<<'\n'<<'\n'<<"UIN NUMBER SHOULD OF 3 DIGITS ";
		cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
		getch();
	}
	int x=5,y=4;
	clrscr();
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<":: ACCOUNT DETAILS INSERTION ::";
	int n=1;
	create_labels(x,y);
	randomize();
	for(int i=0;i<100;i++)
	{
		gotoxy(1,y+4);
		cout<<n;
		obj.create(y+4);
		y+=2;
		n++;
		if(y>20)
		{

			clrscr();
			y=2;
			create_labels(x,y);
		}
	}
}
void modify_account()
{
	account obj;
	int x=5,y=4;

	if(pass==0)
	{
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: MODIFY ACCOUNTS  ::";
		design();
		cout<<"TO UPDATE RECORD  ::: ";
		cout<<'\n'<<'\n'<<" ->>>> Enter Account Number Of Your Account To Modify Your Account Information ..";
		cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
		getch();
		design();
		cout<<"Following Information Can Be Modified -----";
		cout<<'\n'<<'\n'<<"--->>> Account UIN Number ";
		cout<<'\n'<<"--->>> Account Owner's Name ";
		design();
		cout<<"ENTER 0 IN ACCOUNT NUMBER OR UIN NUMBER TO STOP FURTHER MODIFICATION ";
		cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
		getch();
	}
	clrscr();
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<":: ACCOUNT DETAILS UPDATION ::";
	modify_labels(x,y);
	randomize();
	for(int i=0;i<100;i++)
	{
		obj.modify(y+4);
		y+=2;
		if(y>20)
		{
			clrscr();
			y=2;
			modify_labels(x,y);
		}
	}


}
void display_account()
{
	int pages;
	if(totalaccounts==0)
	{
		char ch;
		clrscr();
		cout<<"You Have Not Entered Any Records . . . . . . . .";
		cout<<'\n'<<'\n'<<"Press ( Y ) To Create Accounts :: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			create_account();
		}
		else
		{
			sbimenu();
		}
	}
	else//(totalaccounts<=9)
	{
		if(totalaccounts<=9)
		{
			pages=1;
		}
		else if(totalaccounts%9==0)
		{
			pages=totalaccounts/9;
		}
		else
		{
			pages=(totalaccounts/9)+1;
		}
	}
	account obj;
	int x=5,y=3,a=1;
	clrscr();
	cout<<'\t'<<'\t'<<'\t'<<"       :: ACCOUNT DETAILS ::";
	display_labels(x,y);
	int n=1;
	int add=3;
	fstream fin("accountlist.txt",ios::in);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		gotoxy(1,y+add);
		cout<<n;
		obj.display(y+add);
		delay(50);
		if(y>18 || (n==totalaccounts))
		{
			design();
			gotoxy(5,24);
			cout<<"Page "<<a<<" Of "<<pages;
			if(a<pages)
			{
				gotoxy(55,24);
				cout<<"Press Y For Next Page ...";
			}
			else
			{
				gotoxy(50,24);
				cout<<"Press Any Key To Continue ...";
			}
			char ch;
			ch=getch();
			if(ch!='y' && ch!='Y')
			{
				break;
			}

			if(a<=pages)
			{
				clrscr();
				y=2;
				display_labels(x,y);
				add=1;
			}
			a++;
		}
		n++;
		y=y+2;
	}
	fin.close();
}
void close_account()
{
	clrscr();
	account obj,m[10];
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<":: CLOSE ACCOUNTS  ::";
	design();
	long int num;
	int y=8,n=0,x=5,serial_no;
	cout<<"Please Enter Uin Number Or Account Number To Be Closed :: ";
	cin>>num;
	int count=0;
	if(num>10000 || (num>=100 && num<1000))
	{
		fstream fin("accountlist.txt",ios::in);
		while(fin.read((char*)&obj,sizeof(obj)))
		{

			if(obj.ret_acno()==num || obj.ret_uin()==num)
			{
				if(n==0)
				{
					cout<<'\n'<<"Following Records Were Found :: ";
					create_labels(x,y);
					gotoxy(1,y);
					cout<<"Sr.";
				}
				m[n]=obj;
				gotoxy(1,y+3);
				cout<<n+1;
				obj.display(y+3);
				delay(100);
				n++;
				y=y+2;
				count++;

			}
		}
		serial_no=n;
	}
	if(count==0)
	{
		char ch;
		cout<<'\n'<<'\n'<<" No Accounts Mapped For Provided Number . . . . . . ";
		cout<<'\n'<<'\n'<<"Want To Create Account Press ( Y ):: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			create_account();
		}
		else
		{
			accountservices();
		}
	}
	else
	{
		design();
		int p,flag=0;
		again:
		cout<<'\n'<<"Enter Serial Number Of Account displayed Above To Be Deleted :: ";
		cin>>p;
		if(p==0 || p>serial_no)
		{
			cout<<" !!! Please Enter Valid Serial Number ";
			getch();
			flag++;
			if(flag>3)
			{
				error_code01();
			}
			goto again;
		}
		else
		{
			fstream fin("accountlist.txt",ios::in);
			fstream fout("new.txt",ios::out);
			account obj;
			while(fin.read((char*)&obj,sizeof(obj)))
			{
				if(m[p-1].ret_acno()==obj.ret_acno())
				{
					cout<<'\n'<<'\n'<<"Account With Account Number | "<<obj.ret_acno()<<" | Was Deleted Successfully";
					--totalaccounts;
					getch();
				}
				else
				{
					fout.write((char*)&obj,sizeof(obj));
				}
			}
			fin.close();
			fout.close();

			remove("accountlist.txt");
			rename("new.txt","accountlist.txt");

		}

	}
}
void search_account()
{
	clrscr();
	account obj;
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<":: SEARCH ACCOUNTS  ::";
	design();
	long int num;
	int y=7,n=0,x=5,serial_no;
	cout<<"Please Enter Uin Number Or Account Number To Be Searched :: ";
	cin>>num;
	int count=0;
	if(num>10000 || (num>=100 && num<1000))
	{
		fstream fin("accountlist.txt",ios::in);
		while(fin.read((char*)&obj,sizeof(obj)))
		{

			if(obj.ret_acno()==num || obj.ret_uin()==num)
			{
				if(n==0)
				{
					display_labels(x,y);
					gotoxy(1,y);
					cout<<"Sr.";
				}
				gotoxy(1,y+3);
				cout<<n+1;
				obj.display(y+3);
				delay(100);
				n++;
				y=y+2;
				count++;

			}
		}
	}
	if(count==0)
	{
		char ch;
		cout<<'\n'<<'\n'<<" No Accounts Mapped For Provided Number . . . . . . ";
		cout<<'\n'<<'\n'<<"Want To Create Account Press ( Y ):: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			create_account();
		}
		else
		{
			accountservices();
		}
	}
	getch();
}
void convert_type()
{
	int c=0;
	again:
	clrscr();
	account obj;
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<"::  ACCOUNT CONVERSION  ::";
	design();
	long int num;
	cout<<"Please Enter Account Number :: ";
	cin>>num;
	int found=0,pos,serial_no;

	fstream fin("accountlist.txt",ios::in|ios::out);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		pos=fin.tellg();
		if(obj.ret_acno()==num)
		{
			found++;
			cout<<'\n'<<"::: Account Number Verified Successfully :::";
			design();
			char name[24];
			cout<<"Please Enter ( 3 Digit ) Account's UIN Number :: ";
			cin>>num;
			if(obj.ret_uin()==num)
			{
				cout<<'\n'<<"::: UIN Authentication Successful ::: ACCOUNT DETAILS ----";
				obj.display(14);
				design();
				char cur_type[24];
				strcpy(cur_type,obj.ret_actype());
				cout<<"Your Present Account Type Is :: "<<cur_type;
				char new_type[24];
				if(strcmpi(cur_type,"Savings")==0)
				{
					strcpy(new_type,"Current");
				}
				else
				{
					strcpy(new_type,"Savings");
				}
				char ch;
				cout<<'\n'<<"If You Want To Convert It Into "<<new_type<<" Press ( Y ) :: ";
				cin>>ch;
				admin s1;
				fstream take("admin.txt",ios::in);
				take.read((char*)&s1,sizeof(s1));
				take.close();
				float sav,cur;
				cur=s1.mab_cur;
				sav=s1.mab_sav;
				if(ch=='Y'||ch=='y')
				{
					float cur_balance=obj.ret_acbalance(),add;
					if(((new_type[0]=='S')&&(cur_balance<sav)) || ((new_type[0]=='C')&& (cur_balance<cur)))
					{
						if(new_type[0]=='C')
						{
							add=cur-cur_balance;
						}
						else
						{
							add=sav-cur_balance;
						}
						char choice;
						cout<<'\n'<<"In Order To Carry Out Following Conersion , You Need Extra Account Balance ";
						cout<<'\n'<<"You Have To Deposit "<<add<<" Rupees To Carry Out Conversion ";
						cout<<'\n'<<'\n'<<"Press ( Y ) To Deposit Amount Or Abort Conversion :: ";
						cin>>choice;
						if(choice=='y' || choice=='Y')
						{
							obj.deposit(add);
							cout<<'\n'<<'\n'<<" New Account Balance :: "<<obj.ret_acbalance();
							obj.convert(new_type);
						}
						else
						{
							cout<<'\n'<<'\n'<<"Aborting Request ..... Please Wait ...";
							delay(400);
							accountservices();
						}
					}
					obj.convert(new_type);
					fstream fout("accountlist.txt",ios::in|ios::out);
					fout.seekp(pos-sizeof(obj));
					fout.write((char*)&obj,sizeof(obj));
					fout.close();
					cout<<'\n'<<"Your New Account Type Is :: "<<new_type;
					cout<<'\n'<<'\n'<<":: ACCOUNT TYPE MODIFIED SUCCESSFULLY ::";
					cout<<'\n'<<'\n'<<"   Press Any Key To Coninue - - - - > > > >";
					getch();
				}

			}
			else
			{
				cout<<'\n'<<'\n'<<"::: UIN Authentication Un-Successful ::: ";
				cout<<'\n'<<'\n'<<"    Terminating Request . . . . . . . .";
				getch();
			}

		}
	}
	if(found==0)
	{
		if(c>3)
		{
			error_code01();
		}
		cout<<'\n'<<'\n'<<"!!! Please Enter A Valid Account Number ...... ";
		design();
		cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again - - - - > >";
		char ch=getch();
		if(ch=='y' ||ch=='Y')
		{
			convert_type();
		}
		else
		{
			accountservices();
		}
		c++;
		goto again;
	}
}
void deposit_amount()
{
	int c=0;
	again:
	clrscr();
	account obj;
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<"::  DEPOSIT AMOUNT  ::";
	design();
	long int num;
	cout<<"Please Enter Account Number :: ";
	cin>>num;
	int found=0,pos;

	fstream fin("accountlist.txt",ios::in|ios::out);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		pos=fin.tellg();
		if(obj.ret_acno()==num)
		{
			cout<<'\n'<<"::: Account Number Verified Successfully :::";
			design();
			found++;
			break;
		}
	}
	if(found==0)
	{
		if(c>3)
		{
			error_code01();
		}
		cout<<'\n'<<'\n'<<"!!! Please Enter A Valid Account Number ...... ";
		design();
		cout<<'\n'<<'\n'<<"Press Any Key To Try Again - - - - > >";
		getch();
		c++;
		goto again;
	}
	else
	{
		char entered_name[20];
		int entered_uin;
		cout<<"Please Enter ( 3 Digit ) Account's UIN Number :: ";
		cin>>entered_uin;
		if(obj.ret_uin()==entered_uin)
		{
			float add;
			float cur_balance=obj.ret_acbalance();
			long int acnumber=obj.ret_acno();
			cout<<'\n'<<"::: UIN Authentication Successful ::: ACCOUNT DETAILS ----";
			obj.display(14);
			design();
			cout<<"Enter Name Of Depositer :: ";
			gets(entered_name);
			cout<<'\n'<<"Enter Amount To Be Deposited :: ";
			cin>>add;
			if(add==(0.0))
			{
				char ch;
				cout<<'\n'<<'\n'<<"!!! Please Enter Valid Amount . . . . . . ";
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again :: ";
				cin>>ch;
				if(ch=='y' || ch=='Y')
				{
					deposit_amount();
				}
				else
				{
					accountservices();
				}
			}
			else
			{
				obj.deposit(add);
			}

			cur_balance=obj.ret_acbalance();

			transaction temp;

			time_t now=time(0);
			char *cur_time=ctime(&now);
			strcpy(temp.res_time,cur_time);
			strcpy(temp.name,entered_name);
			temp.debit=0.0;
			temp.credit=add;
			temp.acnum=acnumber;
			temp.balance=cur_balance;
			cout<<'\n'<<"INR "<<add<<" Was Successfully Deposited By "<<entered_name<<" In Account Number "<<acnumber;
			cout<<'\n'<<"On Date/Time :: "<<temp.res_time;
			cout<<'\n'<<"New Account Balance ( INR ) ::: "<<obj.ret_acbalance();
			fin.seekg(pos-sizeof(obj));
			fin.write((char*)&obj,sizeof(obj));
			fin.close();
			getch();
			save_history(temp);
			accountservices();

		}
		else
		{
			cout<<'\n'<<'\n'<<"::: UIN Authentication Un-Successful ::: ";
			cout<<'\n'<<'\n'<<"    Terminating Request . . . . . . . . .";
			getch();
			accountservices();
		}

	}

}
void withdraw_amount()
{
	int c=0;
	again:
	clrscr();
	account obj;
	cout<<'\n'<<'\t'<<'\t'<<'\t'<<"::  WITHDRAW AMOUNT  ::";
	design();
	long int num;
	cout<<"Please Enter Account Number :: ";
	cin>>num;
	int found=0,pos;

	fstream fin("accountlist.txt",ios::in|ios::out);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		pos=fin.tellg();
		if(obj.ret_acno()==num)
		{
			cout<<'\n'<<"::: Account Number Verified Successfully :::";
			design();
			found++;
			break;
		}
	}
	if(found==0)
	{
		if(c>3)
		{
			error_code01();
		}
		cout<<'\n'<<'\n'<<"!!! Please Enter A Valid Account Number ...... ";
		design();
		cout<<'\n'<<'\n'<<"Press Any Key To Try Again - - - - > >";
		getch();
		c++;
		goto again;
	}
	else
	{
		char name[20];
		int entered_uin;
		cout<<"Please Enter ( 3 Digit ) Account's UIN Number :: ";
		cin>>entered_uin;
		if(obj.ret_uin()==entered_uin)
		{
			float deduct;
			float cur_balance=obj.ret_acbalance();
			long int acnumber=obj.ret_acno();
			cout<<'\n'<<"::: UIN Authentication Successful ::: ACCOUNT DETAILS ----";
			obj.display(14);
			design();
			cout<<"Enter Name Of Withdrawer :: ";
			gets(name);
			cout<<'\n'<<"Enter Amount To Be Withdrawn :: ";
			cin>>deduct;
			if(deduct==0)
			{
				char ch;
				cout<<'\n'<<'\n'<<"!!! Please Enter Valid Amount . . . . . . ";
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again :: ";
				cin>>ch;
				if(ch=='y' || ch=='Y')
				{
					withdraw_amount();
				}
				else
				{
					accountservices();
				}
			}
			else if(deduct<obj.ret_acbalance())
			{
				obj.withdraw(deduct);
				cur_balance=obj.ret_acbalance();
				transaction temp;
				//tm*cur;	  //cur->tm_year , cur->tm_mon , cur->tm_mday ,cur->tm_hour , cur->tm_min , cur->tm_sec
				time_t now=time(0);
				char *cur_time=ctime(&now);
				strcpy(temp.res_time,cur_time);
				strcpy(temp.name,name);
				temp.debit=deduct;
				temp.credit=0.0;
				temp.acnum=acnumber;
				temp.balance=cur_balance;
				cout<<'\n'<<"INR "<<deduct<<" Was Successfully Debited By "<<name<<" From Account Number "<<acnumber;
				cout<<'\n'<<"On Date / Time :: "<<temp.res_time;
				fin.seekg(pos-sizeof(obj));
				fin.write((char*)&obj,sizeof(obj));
				fin.close();
				cout<<'\n'<<"Updated Account Balance ::: "<<obj.ret_acbalance();
				getch();
				save_history(temp);
				accountservices();
			}
			else
			{
				char ch;
				cout<<'\n'<<'\n'<<"!!! You Have Insufficient Balance ";
				cout<<'\n'<<'\n'<<" Want To Withdraw Less Amount (Press Y) ::: ";
				cin>>ch;
				if(ch=='y'|| ch=='Y')
				{
					withdraw_amount();
				}
				else
				{
					cout<<'\n'<<'\n'<<"    Terminating Request ............";
					getch();
					accountservices();

				}
			}

		}
		else
		{
			cout<<'\n'<<'\n'<<"::: UIN Authentication Un-Successful ::: ";
			cout<<'\n'<<'\n'<<"    Terminating Request . . . . . . . .";
			getch();
			accountservices();
		}
	}
}
void save_history(transaction obj)
{
	cout<<'\n'<<sizeof(obj.acnum)<<"     "<<obj.acnum;
	cout<<'\n'<<sizeof(obj.name)<<"        "<<strlen(obj.name)<<"       "<<obj.name;
	cout<<'\n'<<sizeof(obj.res_time)<<"       "<<strlen(obj.res_time)<<"    "<<obj.res_time;
	cout<<'\n'<<sizeof(obj.credit)<<"    "<<obj.credit;
	cout<<'\n'<<sizeof(obj.debit)<<"        "<<obj.debit;
	cout<<'\n'<<sizeof(obj.balance)<<"        "<<obj.balance;
	fstream save("transaction.txt",ios::app);
	save.write((char*)&obj,sizeof(obj));
	save.close();
}
void account_history()
{
	clrscr();
	cout<<'\n'<<'\t'<<'\t'<<"   ::  ACCOUNT TRANSACTION HISTORY  ::";
	design();

	transaction obj;
	long int num;
	int y=4,n=0,x=1;
	cout<<"Please Enter Account Number To Get History :: ";
	cin>>num;
	int count=0,sr_no=1;
	float pre_balance;
	fstream fin("transaction.txt",ios::in);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		if(obj.acnum==num)
		{
			if(n==0)
			{
				if(obj.credit==0)
				{
					pre_balance=obj.balance+obj.debit;
				}
				else if(obj.debit==0)
				{
					pre_balance=obj.balance-obj.credit;
				}
				clrscr();
				cout<<'\n'<<'\t'<<"  TRANSACTION HISTORY  :: "<<num<<" :: Prevoius Balance = "<<pre_balance;;
				//cout<<'\n'<<'\t'<<'\t'<<"         Prevoius Balance ::: "<<pre_balance;
				history_labels(y);
			}
			gotoxy(x,y+3);
			cout<<sr_no;
			obj.show(y+3);
			delay(100);
			n++;
			sr_no++;
			y=y+2;
			if(y>24)
			{
				y=4;
				clrscr();
				cout<<'\n'<<'\t'<<'\t'<<"   ::  TRANSACTION HISTORY  - > > "<<num;
				history_labels(y);
			}
			count++;
		}
	}
	if(count==0)
	{
		char ch;
		cout<<'\n'<<'\n'<<" Either No Accounts Mapped For Provided Number . . . . . . ";
		cout<<'\n'<<'\n'<<"........ Or This Account Has Not Yet Done Any Transaction ";
		cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again :: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			account_history();
		}
		else
		{
			cout<<'\n'<<'\n'<<"Proceeding To Main Menu - - - - > > >";
			delay(200);
			accountservices();
		}
	}
	gotoxy(45,24);
	cout<<"Press Any Key To Continue ...";
	getch();
}
int recaptcha()
{
	int count=1;
	again:
	int gd=DETECT,gm;
	initgraph(&gd,&gm,bgi);
	cleardevice();
	int xc,yc;
	xc=getmaxx()/2;
	yc=getmaxy()/2;

	int a=xc-75,b=yc-100,c=xc+75,d=yc-50;
	setcolor(WHITE);
	rectangle(a-75,b-50,c+100,d+150);
	rectangle(a,b,c,d);


	settextstyle(3,HORIZ_DIR,2);
	outtextxy(a,b-35,"re_CAPTCHA");
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(a,d+10,"ENTER CAPTCHA");

	a=xc-75,b=yc-20,c=xc+100,d=yc+5;
	setcolor(WHITE);
	rectangle(a,b,c,d);

	randomize();
	char captcha[7]="ABHI01";  //48-57 digits(0-9) 65-90 capital alphabets 97-122 small alphabets
	char digit,alpha1,alpha2;  ///alpha1 for small letters while alpha 2 for capital letters

	int pos=1,y;                   /// 1 and 4th position in captcha are for digits(1-9)
	for(int i=0;i<2;i++)
	{
		digit=49+random(9);
		captcha[pos]=digit;
		pos=4;
	}

	pos=0;   ///since alphabets will be stored from 0 index
	for(i=0;i<4;i++)
	{
		if(pos==1 || pos==4)        // since 1 and 4th positions are already filled
		{
			pos++;
		}
		alpha1=65+random(26);    /// small letters
		alpha2=97+random(26);    //capital letters

		y=1+random(2);       //to randomly fill small and capital letters
		if(y==1)
		{
			captcha[pos]=alpha1;
		}
		else
		{
			captcha[pos]=alpha2;
		}

		pos++;
	}

	char recaptcha[12]="00000000000";  /// to avoid garbage values
	int j=0;
	for(i=0;i<11;i++)
	{
		if(i%2==0)
		{
			recaptcha[i]=captcha[j];
			j++;
		}
		else
		{
			recaptcha[i]=' ';
		}
	}

	settextstyle(3,HORIZ_DIR,1);
	outtextxy(a+18,b-70,recaptcha);
	char getotp[7]="1234567";    /// to avoid garbage values
	char ch;
	gotoxy(35,15);
	cin>>getotp;
	a=xc-75,b=yc-100,c=xc+75,d=yc-50;
	setcolor(WHITE);
	rectangle(a-75+20,d+150-50,c+100-20,d+150-20);
	c=a-75+20;
	for(i=0;i<(285);i++)
	{
		setcolor(LIGHTGRAY);
		rectangle(a-75+20,d+150-50,c,d+150-20);
		c++;
		delay(2);
	}
	setcolor(BLACK);
	settextstyle(3,HORIZ_DIR,1);
	if(strcmp(captcha,getotp)==0 || (strcmpi("00",getotp)==0))  /// to verify entered captcha
	{
		if(strcmp(captcha,getotp)==0 )
		{
			outtextxy(a+20,d+150-50,"Captcha Verified");
		}
		else
		{
			outtextxy(a+20,d+150-50,"Captcha Bypassed");
		}
		delay(1000);
		closegraph();
		return(1);
	}
	else        /// to verify entered otp
	{
		count++;
		outtextxy(a+20,d+150-50,"Invalid Captcha");
		if(count>3)
		{
			closegraph();
			return(0);
		}
		getch();
		goto again;
	}

}
void re_define()
{
	int count=0;
	tryagain:
	clrscr();

	cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: Account Holder's Data Reset ::";
	design();

	char user[24],pass[24];
	cout<<'\n'<<'\n'<<'\t'<<"PLEASE VERIFY YOUR CREDENTIALS --- ";

	cout<<'\n'<<'\n'<<"Username :: ";
	cin>>user;
	cout<<'\n'<<"Password :: ";
	cin>>pass;
	admin obj;
	fstream fin("admin.txt",ios::in);
	fin.read((char*)&obj,sizeof(obj));
	if(strcmp(user,obj.user_name)==0 && strcmp(pass,obj.password)==0)
	{
		cout<<'\n'<<'\n'<<"CREDENTIALS VERIFIED SUCCESSFULLY ";
		cout<<'\n'<<'\n'<<".......Proceeding To Captcha Verification ";
		delay(1000);
		int res;
		res=recaptcha();
		clrscr();
		if(res==1)
		{
			Default_records(1,0);
			cout<<'\n'<<'\n'<<"Data File Has Been Set To Its Factory Condition ";
		}
		else if(res==0)
		{
			cout<<'\n'<<'\n'<<'\n'<<"User Authentication Failed Due To Multiple Wrong Attempts";

		}
		cout<<'\n'<<'\n'<<"Press Any Key To Proceed  - - -  -> > > ";
		getch();
		sbimenu();
	}
	else
	{
		cout<<'\n'<<'\n'<<"Username OR Password are incorrect ";
		count++;
		cout<<'\n'<<'\n'<<(3-count)<<"  ATTEMPT(s) LEFT  ";
		char ch;
		if(count<3)
		{
			cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
		}
		ch=getch();
		if(ch=='y'||ch=='Y')
		{
			if(count>=3)
			{
				sbimenu();
			}
			goto tryagain;
		}
		else
		{
			sbimenu();
		}
	}
}
void Default_records(int target1,int target2)
{
	if(target1==1)
	{
		account obj[5]={
					{100001,101,"Aniket","Savings",20000},
					{100002,102,"Anshuman","Savings",5000},
					{100003,103,"Arjun","Current",10000},
					{100004,104,"Kushagra","Savings",21000},
					{100005,105,"Prakhar","Current",20500},
			       };
		fstream fout("accountlist.txt",ios::out);
		fout.write((char*)&obj[0],sizeof(obj[0]));
		fout.close();
		fstream out("accountlist.txt",ios::app);
		for(int i=1;i<5;i++)
		{
			out.write((char*)&obj[i],sizeof(obj[i]));
		}
		out.close();
	}
	if(target2==1)
	{
		administrator_menu(1);
	}
}
void reset_admin()
{
	int res;
	res=recaptcha();
	clrscr();
	if(res==1)
	{
		administrator_menu(1);
		getch();
		sbimenu();
	}
	else if(res==0)
	{
		cout<<'\n'<<'\n'<<'\n'<<"User Authentication Failed Due To Multiple Wrong Attempts";

	}
	cout<<'\n'<<'\n'<<"Press Any Key To Proceed  - - -  -> > > ";
	getch();
	sbimenu();
}
void administrator()
{
	int count=0;
	tryagain:
	clrscr();

	cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: ADMINISTRATIVE SERVICES ::";
	design();

	char user[24],pass[24];
	cout<<'\n'<<'\t'<<"PLEASE VERIFY YOUR CREDENTIALS --- ";

	cout<<'\n'<<'\n'<<"Username :: ";
	cin>>user;
	cout<<'\n'<<"Password :: ";
	cin>>pass;
	admin obj;
	fstream fin("admin.txt",ios::in);
	fin.read((char*)&obj,sizeof(obj));
	if(strcmp(user,obj.user_name)==0 && strcmp(pass,obj.password)==0)
	{
		cout<<'\n'<<'\n'<<"CREDENTIALS VERIFIED SUCCESSFULLY ";
		cout<<'\n'<<'\n'<<".......Proceeding To Captcha Verification ";
		delay(1000);
		int res;
		res=recaptcha();
		clrscr();
		if(res==1)
		{
			administrator_menu(0);
		}
		else if(res==0)
		{
			cout<<'\n'<<'\n'<<'\n'<<"User Authentication Failed Due To Multiple Wrong Attempts";

		}
		cout<<'\n'<<'\n'<<"Press Any Key To Proceed  - - -  -> > > ";
		getch();
		sbimenu();
	}
	else
	{
		cout<<'\n'<<'\n'<<"Username OR Password are incorrect ";
		count++;
		cout<<'\n'<<'\n'<<(3-count)<<"  ATTEMPT(s) LEFT  ";
		char ch;
		if(count<3)
		{
			cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
		}
		ch=getch();
		if(ch=='y'||ch=='Y')
		{
			if(count>=3)
			{
				sbimenu();
			}
			goto tryagain;
		}
		else
		{
			sbimenu();
		}
	}
}
void administrator_menu(int pass)
{	
	int x=pass;
	if(x==0)
	{
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: ADMINISTRATOR  SERVICES ::";
		design();
		cout<<'\n'<<'\t'<<"CHANGE USERNAME OR PASSWORD                         (Press 1) ";
		cout<<'\n'<<'\n'<<'\t'<<"MODIFY INTEREST RATES                               (Press 2) ";
		cout<<'\n'<<'\n'<<'\t'<<"CHANGE MINIMUM ACCOUNT BALANCE (MAB)                (Press 3) ";
		cout<<'\n'<<'\n'<<'\t'<<"ADD INTEREST TO ACCOUNTS                            (Press 4) ";
		cout<<'\n'<<'\n'<<'\t'<<"DEDUCT MAB CHARGES FROM ACCOUNTS                    (Press 5) ";
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"RETURN TO MAIN MENU                                 (Press A) ";
		cout<<'\n'<<'\n'<<'\t'<<"Exit                                                (Press 0) ";

		char* ch;
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"PLEASE ENTER YOUR CHOICE :: ";
		cin>>ch;
		int x=atoi(ch);
	}
	if(x==1)
	{
		int count=0;
		tryagain:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: ADMINISTRATIVE SERVICES ::"<<endl;
		cout<<'\n'<<'\n'<<":: Username and Password Reset ::";
		design();

		char user[24],pass1[16],pass2[16];
		cout<<'\t'<<"PLEASE ENTER YOUR NEW CREDENTIALS --- ";

		cout<<'\n'<<'\n'<<"Enter New Username :: ";
		cin>>user;
		cout<<'\n'<<"Enter New Password :: ";
		cin>>pass1;
		cout<<'\n'<<"Confirm New Password :: ";
		cin>>pass2;
		int l=strlen(pass2);
		if(strcmp(user,pass1)==0)
		{
				cout<<'\n'<<'\n'<<"User Name Cannot Be Used As Password";
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . .";
				char ch;
				ch=getch();
				if(ch=='y'||ch=='Y')
				{
					goto tryagain;
				}
				else
				{
					administrator_menu(1);
				}

		}
		else if(strcmp(pass1,pass2)==0)
		{
			if(l<6)
			{
				cout<<'\n'<<'\n'<<"Password Strength Should Be More Than 6 Characters ";
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . .";
				char ch;
				ch=getch();
				if(ch=='y'||ch=='Y')
				{
					goto tryagain;
				}
				else
				{
					administrator_menu(1);
				}
			}
			else
			{
				admin s1;
				fstream take("admin.txt",ios::in);
				take.read((char*)&s1,sizeof(s1));
				take.close();
				strcpy(s1.user_name,user);
				strcpy(s1.password,pass1);
				fstream update("admin.txt",ios::out);
				update.write((char*)&s1,sizeof(s1));
				update.close();
				cout<<'\n'<<'\n'<<"CREDENTIALS UPDATEDED SUCCESSFULLY ";
				cout<<'\n'<<'\n'<<"Press Any Key To Continue - - - - - > > > ";
				getch();
				administrator_menu(0);
			}
		}
		else
		{
			cout<<'\n'<<'\n'<<"Entered Passwords Didn't Matched ";
			count++;
			cout<<'\n'<<'\n'<<(3-count)<<"  ATTEMPT(s) LEFT  ";
			if(count<3)
			{
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
			}
			char ch;
			ch=getch();
			if(ch=='y'||ch=='Y')
			{
				if(count>=3)
				{
					administrator_menu(1);
				}
				goto tryagain;
			}
			else
			{
				administrator_menu(0);
			}
		}
		administrator_menu(0);
	}
	else if(x==2)
	{
		int count=0;
		again2:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: ADMINISTRATIVE SERVICES ::"<<endl;
		cout<<'\n'<<'\n'<<"   :: INTEREST RATES ::";
		design();
		float newir;
		cout<<"   PLEASE SELECT THE ACCOUNT TYPE --- ";
		cout<<'\n'<<'\n'<<'\t'<<"CURRENT ACCOUNT                                (Press 1)";
		cout<<'\n'<<'\n'<<'\t'<<"SAVINGS ACCOUNT                                (Press 2)";
		cout<<'\n'<<'\n'<<'\t'<<"Abort Task                                     (Press 0)";
		char *ch;
		cout<<'\n'<<'\n'<<'\t'<<"PLEASE ENTER YOUR CHOICE :: ";
		cin>>ch;
		int a=atoi(ch);
		if(a==1 || a==2)
		{
			admin s1;
			fstream take("admin.txt",ios::in);
			take.read((char*)&s1,sizeof(s1));
			take.close();
			cout<<'\n'<<'\n'<<'\t'<<"ENTER NEW INTEREST RATE  :: ";
			cin>>newir;
			if(newir<=0 ||newir>11)
			{
				if(a==1)
				{
					s1.ir_cur=newir;
				}
				else
				{
					s1.ir_sav=newir;
				}
				cout<<'\n'<<'\n'<<"Interest Rates Cannot Be Zero Or Greater Than 10 %";
				char ch;
				cout<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
				ch=getch();
				if(ch=='y'||ch=='Y')
				{
					goto again2;
				}
				else
				{
					administrator_menu(0);
				}
			}
			else
			{
				fstream update("admin.txt",ios::out);
				update.write((char*)&s1,sizeof(s1));
				update.close();
				cout<<'\n'<<'\n'<<":: INTEREST RATES UPDATED SUCCESSFULLY ::";
				cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
				getch();
				administrator_menu(0);
			}
		}
		else if(a==0)
		{
			cout<<'\n'<<'\n'<<"Proceeding To Main Menu . . . . . ";
			delay(200);
			administrator_menu(0);
		}
		else
		{
			cout<<'\n'<<'\n'<<"!!!! Please Enter Valid Choice ....";
			count++;
			cout<<'\n'<<'\n'<<(3-count)<<"  ATTEMPT(s) LEFT  ";
			char ch;
			if(count<3)
			{
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
			}
			ch=getch();
			if(ch=='y'||ch=='Y')
			{
				if(count>=3)
				{
					administrator_menu(0);
				}
				goto again2;
			}
			else
			{
				administrator_menu(0);
			}
		}
		administrator_menu(0);
	}
	else if(x==3)
	{
		int count=0;
		again3:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<":: ADMINISTRATIVE SERVICES ::"<<endl;
		cout<<'\n'<<'\n'<<":: MINIMUM ACCOUNT BALANCE (MAB) RESET ::";
		design();
		float newMAB;

		cout<<"   PLEASE SELECT THE ACCOUNT TYPE --- ";
		cout<<'\n'<<'\n'<<'\t'<<"CURRENT ACCOUNT                                (Press 1)";
		cout<<'\n'<<'\t'<<"SAVINGS ACCOUNT                                (Press 2)";
		cout<<'\n'<<'\t'<<"Abort Task                                     (Press 0)";
		char *ch;
		cout<<'\n'<<'\n'<<'\t'<<"PLEASE ENTER YOUR CHOICE :: ";
		cin>>ch;
		int a=atoi(ch);
		if(a==1 || a==2)
		{
			admin s1;
			fstream take("admin.txt",ios::in);
			take.read((char*)&s1,sizeof(s1));
			take.close();
			cout<<'\n'<<'\n'<<'\t'<<"ENTER NEW MINIMUM ACCOUNT BALANCE  :: ";
			cin>>newMAB;
			if(newMAB<0 || newMAB>100001)
			{
				cout<<'\n'<<'\n'<<"MAB Cannot Be Negative Or Greater Than 10000";
				char ch;
				cout<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
				ch=getch();
				if(ch=='y'||ch=='Y')
				{
					goto again3;
				}
				else
				{
					administrator_menu(0);
				}
			}
			else
			{
				if(a==1)
				{
					s1.mab_cur=newMAB;
				}
				else
				{
					s1.mab_sav=newMAB;
				}
				fstream New("admin.txt",ios::out);
				New.write((char*)&s1,sizeof(s1));
				New.close();
				cout<<'\n'<<'\n'<<":: MAB UPDATED SUCCESSFULLY ::";
				cout<<'\n'<<'\n'<<"Press Any Key To Proceed -> > >";
				getch();
				administrator_menu(0);
			}

		}
		else if(a==0)
		{
			cout<<'\n'<<'\n'<<"Proceeding To Main Menu . . . . . ";
			delay(200);
			administrator_menu(0);
		}
		else
		{
			cout<<'\n'<<'\n'<<"!!!! Please Enter Valid Choice ....";
			count++;
			cout<<'\n'<<'\n'<<(3-count)<<"  ATTEMPT(s) LEFT  ";
			char ch;
			if(count<3)
			{
				cout<<'\n'<<'\n'<<"Press ( Y ) To Try Again . . . . . ";
			}
			ch=getch();
			if(ch=='y'||ch=='Y')
			{
				if(count>=3)
				{
					administrator_menu(0);
				}
				goto again3;
			}
			else
			{
				administrator_menu(0);
			}
		}
		administrator_menu(0);
	}
	else if(*ch=='A'||*ch=='a')
	{
		cout<<'\n'<<'\n'<<"Proceeding To Main Menu .. .. .. ";
		delay(200);
		sbimenu();
	}
	else if(x==4)
	{
		add_interest();
		clrscr();
		cout<<'\n'<<'\n'<<"Interest Added Successfully . . . . . . ";
		cout<<'\n'<<'\n'<<"Press ( Y ) To See Updated Account Balances   -- ->  ";
		char choice;
		cin>>choice;
		if(choice=='y' ||  choice =='Y')
		{
			display_account();
			administrator_menu(0);
		}
		else
		{
			administrator_menu(0);
		}
	}
	else if(x==5)
	{
		mab_charges();
		clrscr();
		cout<<'\n'<<'\n'<<"Charges Deducted Successfully . . . . . . ";
		cout<<'\n'<<'\n'<<"Press ( Y ) To See Updated Account Balance  -- ->  ";
		char choice;
		cin>>choice;
		if(choice=='y' ||  choice =='Y')
		{
			display_account();
			administrator_menu(0);
		}
		else
		{
			administrator_menu(0);
		}
	}
	else if(x==0)
	{
		Exit();
	}
	else
	{
		cout<<'\n'<<'\n'<<"!!! Wrong Choice";
		getch();
		administrator_menu(0);
	}
}
void add_interest()
{
	admin s1;
	account obj;
	fstream take("admin.txt",ios::in);
	take.read((char*)&s1,sizeof(s1));
	take.close();
	fstream fin("accountlist.txt",ios::in|ios::out);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		int pos=fin.tellg(),forward=0,balance=obj.ret_acbalance();
		float add,cur_balance,ir;
		cur_balance=balance;
		if(strcmpi(obj.ret_actype(),"Savings")==0)
		{
			if(cur_balance>=s1.mab_sav)
			{
				ir=s1.ir_sav;
				add=(ir*(0.001))*cur_balance;
				forward=1;
			}
		}
		else if(strcmpi(obj.ret_actype(),"Current")==0)
		{
			if(cur_balance>=s1.mab_cur)
			{
				ir=s1.ir_cur;
				add=(ir*(0.001))*cur_balance;
				forward=1;
			}
		}
		if(forward==1)
		{
			int plus=add;
			float interest=plus;
			obj.deposit(interest);

			transaction temp;

			time_t now=time(0);
			char *cur_time=ctime(&now);
			strcpy(temp.res_time,cur_time);
			strcpy(temp.name,"Interest");
			temp.debit=0.0;
			temp.credit=interest;
			long int acnumber=obj.ret_acno();
			temp.acnum=acnumber;
			int new_balance=obj.ret_acbalance();
			float final=new_balance;
			temp.balance=final;
			save_history(temp);
			fin.seekg(pos-sizeof(obj));
			fin.write((char*)&obj,sizeof(obj));

		}
	}
	fin.close();
}
void mab_charges()
{
	admin s1;
	account obj;
	fstream take("admin.txt",ios::in);
	take.read((char*)&s1,sizeof(s1));
	take.close();
	fstream fin("accountlist.txt",ios::in|ios::out);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		int pos=fin.tellg(),forward=0,balance=obj.ret_acbalance();
		float deduct,cur_balance;
		cur_balance=balance;
		if(strcmpi(obj.ret_actype(),"Savings")==0)
		{
			if(cur_balance<s1.mab_sav)
			{
				if(cur_balance<=11.0)
				{
					deduct=cur_balance;
				}
				else
				{
					deduct=11.0;
				}
				forward=1;
			}
		}
		else if(strcmpi(obj.ret_actype(),"Current")==0)
		{
			if(cur_balance<s1.mab_cur)
			{
				if(cur_balance<=17.0)
				{
					deduct=cur_balance;
				}
				else
				{
					deduct=17.0;
				}
				forward=1;
			}
		}
		if(forward==1)
		{
			int minus=deduct;
			float charges=minus;
			obj.withdraw(charges);

			transaction temp;
			time_t now=time(0);
			char *cur_time=ctime(&now);
			strcpy(temp.res_time,cur_time);
			strcpy(temp.name,"MAB Charges");
			temp.debit=charges;
			temp.credit=0.0;
			long int acnumber=obj.ret_acno();
			temp.acnum=acnumber;
			int new_balance=obj.ret_acbalance();
			float final=new_balance;
			temp.balance=final;

			save_history(temp);
			fin.seekg(pos-sizeof(obj));
			fin.write((char*)&obj,sizeof(obj));
		}
	}
	fin.close();
}

void home()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,bgi);
	cleardevice();
	rect_loading();
	door();
	firstpage();
	getch();
	closegraph();
}

void rect_loading()
{
	loadingscreen();
	cleardevice();
	int xc,yc,n=0;
	xc=getmaxx()/2;
	yc=getmaxy()/2;
	char ch[10][100];
	strcpy(ch[0],"Configuring Software .............");
	strcpy(ch[1],"Creating Data Files  .............");
	strcpy(ch[2],"Loading Required Files ...........");

	while(n!=3)
	{
		cleardevice();
		int a=xc-150,b=yc-20,c=xc+150,d=yc+20;
		for(int i=0;i<10;i++)
		{
			c=a+20;
			if(c>xc+150)
			{
				break;
			}
			for(int j=0;j<20;j++)
			{
				setcolor(DARKGRAY);
				rectangle(a,b,c,d);
				a++;
			}
			a+=10;
		}
		setcolor(WHITE);
		settextstyle(2,HORIZ_DIR,5);
		outtextxy(xc-150,yc+40,ch[n]);
		int p;
		a=xc-150,b=yc-20,c=xc+150,d=yc+20;
		for(i=0;i<10;i++)
		{
			c=a+20;
			p=a;
			if(c>xc+150)
			{
				break;
			}
			for(int j=0;j<20;j++)
			{
				setcolor(YELLOW);
				rectangle(a,b,c,d);
				a++;
			}
			delay(300);
			for(j=0;j<20;j++)
			{
				setcolor(LIGHTGRAY);
				rectangle(p,b,c,d);
					p++;
			}
			a+=10;
		}
		n++;

	}
}
void firstpage()
{
	cleardevice();
	int a=150,b=100,c=488,d=250;
	for(int i=0;i<8;i++)
	{
		setcolor(WHITE);
		rectangle(a,b,c,d);
		a++;
		b++;
		c--;
		d--;
	}

	a=125,b=125,c=150,d=150;
	for(i=0;i<25;i++)
	{
		setcolor(WHITE);
		rectangle(a,b,c,d);
		a++;
	}
	a=125,b=200,c=150,d=225;
	for(i=0;i<25;i++)
	{
		setcolor(WHITE);
		rectangle(a,b,c,d);
		a++;
	}
	a=488,b=125,c=513,d=150;
	for(i=0;i<25;i++)
	{
		setcolor(WHITE);
		rectangle(a,b,c,d);
		a++;
	}
	a=488,b=200,c=513,d=225;
	for(i=0;i<25;i++)
	{
		setcolor(WHITE);
		rectangle(a,b,c,d);
		a++;
	}

	int x=225,y=175,r=42;
	setfillstyle(SOLID_FILL,BLUE);
	circle(x,y,r);
	floodfill(x,y,WHITE);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x,y,15);  circle(x,y,r);
	floodfill(x,y,WHITE);

	setcolor(BLACK);
	circle(x,y,r);
	circle(x,y,15);
	/*
	int x=225,y=175,r=40;      //alternative method
	for(i=0;i<=25;i++)
	{
		setcolor(BLUE);
		circle(x,y,r);
		r--;
	}
	*/
	a=221,b=180,c=229,d=225;
	for(i=0;i<8;i++)
	{

		setcolor(BLACK);
		rectangle(a,b,c,d);
		a++;
	}

	setcolor(WHITE);

	settextstyle(3,HORIZ_DIR,10);
	outtextxy(285,90,"SBI");
	setcolor(WHITE);

	settextstyle(2,HORIZ_DIR,9);
	outtextxy(153,270,"STATE BANK OF INDIA");

	setlinestyle(DASHED_LINE,1,2);
	int x1=153,y1=310,x2=488,y2=310;
	line(x1,y1,x2,y2);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(280,320,"PURE BANKING, NOTHING ELSE");

	delay(1000);
}
void door()
{
	cleardevice();
	int xc,yc;
	xc=getmaxx()/2;
	yc=getmaxy()/2;
	setcolor(WHITE);
	line(xc+180,yc-70,xc+280,yc-75);
	line(xc+180,yc-70,xc+180,yc+50);
	line(xc+280,yc-75,xc+280,yc+50);

	int ax,bx;
	ax=xc+180+random(101);
	bx=yc+50;

	randomize();
	for(int i=0;i<100;i++)
	{
		ax=xc+180+random(101);
		bx=yc-70+random(120);
		putpixel(ax,bx,WHITE);
	}


	line(xc+180,yc+50,0,getmaxy());
	line(xc+280,yc+50,xc+200,getmaxy());
	int x1=xc+280,x2=xc+200,y1=yc-75,px=xc+200,a=0;
	for(i=0;i<100;i++)
	{

		setcolor(BLACK);
		settextstyle(1,HORIZ_DIR,6);
		outtextxy(xc+170,yc+50,"Dr.");
		settextstyle(1,HORIZ_DIR,5);
		outtextxy(xc+60,yc+90,"Virendra");
		settextstyle(1,HORIZ_DIR,5);
		outtextxy(xc+30,yc+120,"Swarup");
		settextstyle(1,HORIZ_DIR,4);
		outtextxy(xc-70,yc+160,"Education Centre");
		setcolor(WHITE);
		x2=xc+200;
		line(x1,y1,x1,yc+50);

		a+=5;
		for(int j=0;j<30;j++)
		{
			line(x1,yc+50,px,getmaxy());
			px--;
		}
		px=x2-a;
		x1--;
		if(i%20==0)
		{
			y1++;
		}
	}
	settextstyle(1,HORIZ_DIR,7);
	outtextxy(0,yc+110,"M");
	outtextxy(50,yc+120-20,"r");
	outtextxy(80,yc+120-25,".");
	outtextxy(110,yc+100-20,"S");
	outtextxy(145,yc+100-40,"a");
	outtextxy(175,yc+100-50,"x");
	outtextxy(210,yc+100-60,"e");
	outtextxy(240,yc+100-75,"n");
	outtextxy(280,yc+100-85,"a");
	outtextxy(330,yc+100-105,"S");
	outtextxy(365,yc+100-120,"i");
	outtextxy(382,yc+100-125,"r");
	getch();
	oneplus();
}
void oneplus()
{
	cleardevice();
	int x,y,xc,yc;
	x=getmaxx();
	y=getmaxy();
	xc=x/2;
	yc=y/2;

	int a=0;
	for(int i=0;i<x;i++)    ///a white sheet is made using rectangles
	{
		setcolor(WHITE);
		rectangle(a,yc-100,x,yc+100);
		a++;
	}
	int k1=0,k2=75,k3=x,k4=x-75;
	for(int j=0;j<650;j++)   /// 485 to stop // 650 to run till end //this loop made to make the pattern run j<1 can be changed
	{
		for(i=0;i<25;i++)    ///loop for left bars
		{
			setcolor(RED);
			//for first
			line(k1,yc-100,k2,yc);
			line(k1,yc+100,k2,yc);
			//for second
			line(k1+50,yc-100,k2+50,yc);
			line(k1+50,yc+100,k2+50,yc);


			k1++;
			k2++;
		}
		for(i=0;i<25;i++)   //loop for right bars
		{
			setcolor(RED);
			//for first
			line(k3,yc-100,k4,yc);
			line(k3,yc+100,k4,yc);
			//for second
			line(k3-50,yc-100,k4-50,yc);
			line(k3-50,yc+100,k4-50,yc);
			k3--;
			k4--;
		}

		setcolor(WHITE);
		//for first
		line(k1-25,yc-100,k2-25,yc);
		line(k1-25,yc+100,k2-25,yc);
		//for second
		line(k1+25,yc-100,k2+25,yc);
		line(k1+25,yc+100,k2+25,yc);



		setcolor(WHITE);
		//for first
		line(k3+25,yc-100,k4+25,yc);
		line(k3+25,yc+100,k4+25,yc);
		//for second
		line(k3-50+25,yc-100,k4-50+25,yc);
		line(k3-50+25,yc+100,k4-50+25,yc);


		//delay(1);
		k1=k1-24;
		k2=k2-24;
		k3=k3+24;
		k4=k4+24;

		/*if(k1>=xc)
		{
			setcolor(RED);
			line(x1,yc-100,x1,yc-90);
			line(x1,yc+100,x1,yc+90);
			x1--;
			line(x2,yc-100,x2,yc-90);
			line(x2,yc+100,x2,yc+90);
			x2++;
		}*/
		if(j==450)
		{
			setcolor(RED);

			int a=xc-150,b=yc-20,c=xc-110,d=yc+20;
			for(i=0;i<5;i++)    ///a white sheet is made using rectangles
			{
				setcolor(RED);
				rectangle(a,b,c,d);
				a++;
				b++;
				c--;
				d--;
			}
			setcolor(RED);
			settextstyle(1,HORIZ_DIR,5);
			outtextxy(a+5,b-12,"1");
			settextstyle(3,HORIZ_DIR,4);

			setcolor(RED);
			outtextxy(a+50,b-8,"| ABHISHEK KUMAR |");
		}
	}
}
void loadingscreen()
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

	int n=1;
	int x1=0;
	while(!kbhit())
	{
		if(n==0)
		{
			n++;
		}
		else if(n>15)
		{
			n=1;
		}
		setcolor(n);
		settextstyle(1,HORIZ_DIR,12);
		outtextxy(170,150,"B.M.S");
		setcolor(WHITE);
		settextstyle(1,HORIZ_DIR,1);
		outtextxy(250,55,"Press Any Key To Begin ");
		int a=470,b=55,c=530,d=80;
		delay(300);
		for(int i=0;i<(c-470);i++)
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
       getch();
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
}
void sort_menu()
{
	int size=totalaccounts,i=0;
	account *ARR=new account[size];
	account obj;
	fstream fin("accountlist.txt",ios::in);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		ARR[i]=obj;
		i++;
	}
	fin.close();
	int c=1;
	again:
	clrscr();
	cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<"   :: SORT ACCOUNTS MENU ::";
	design();
	cout<<'\n'<<'\t'<<"Arrange Records By Account Number                    Press -> 1";
	cout<<'\n'<<'\n'<<'\t'<<"Arrange Records By Account Balance                   Press -> 2";
	cout<<'\n'<<'\n'<<'\t'<<"Filter Records By Account Type                       Press -> 3";
	cout<<'\n'<<'\n'<<'\t'<<"Records With Min Or Max Acc. Balances                Press -> 4";
	cout<<'\n'<<'\n'<<'\t'<<"MAIN MENU                                            Press -> A ";
	cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Exit                                                 Press -> 0";


	char *ch;
	cout<<'\n'<<'\n'<<'\n'<<'\t'<<"PLEASE ENTER YOUR CHOICE :: ";
	cin>>ch;
	int x=atoi(ch);
	if(x==1)
	{
		clrscr();
		int c1=1;
		again1:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<"    :: ARRANGE RECORDS BY ACCOUNT NUMBER ::";
		design();
		cout<<'\n'<<'\t'<<"Arrange In Ascending Order                     Press -> 1";
		cout<<'\n'<<'\n'<<'\t'<<"Arrange In Descending Order                    Press -> 2";
		cout<<'\n'<<'\n'<<'\t'<<"MAIN MENU                                      Press -> A ";
		char choice;
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Please Enter Your Choice :: ";
		cin>>choice;
		if(choice=='1')
		{
			sort_account_number(ARR,size,0);
			display_sorted_account(ARR,size);
		}
		else if(choice=='2')
		{
			sort_account_number(ARR,size,1);
			display_sorted_account(ARR,size);
		}
		else if(choice=='a' || choice=='A')
		{
			sort_menu();
		}
		else
		{
			cout<<"!!! Wrong Choice ";
			c1++;
			if(c1>3)
			{
				sort_menu();
			}
			getch();
			goto again1;
		}

	}
	else if(x==2)
	{
		clrscr();
		int c2=1;

		again2:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<"    :: ARRANGE RECORDS BY ACCOUNT BALANCE ::";
		design();
		cout<<'\n'<<'\t'<<"Arrange In Ascending Order                     Press -> 1";
		cout<<'\n'<<'\n'<<'\t'<<"Arrange In Descending Order                    Press -> 2";
		cout<<'\n'<<'\n'<<'\t'<<"MAIN MENU                                      Press -> A ";
		char choice;
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Please Enter Your Choice :: ";
		cin>>choice;
		if(choice=='1')
		{
			sort_account_balance(ARR,size,0);
			display_sorted_account(ARR,size);
		}
		else if(choice=='2')
		{
			sort_account_balance(ARR,size,1);
			display_sorted_account(ARR,size);
		}
		else if(choice=='a' || choice=='A')
		{
			sort_menu();
		}
		else
		{
			cout<<"!!! Wrong Choice ";
			c2++;
			if(c2>3)
			{
				sort_menu();
			}
			getch();
			goto again2;
		}

	}
	else if(x==3)
	{
		clrscr();
		int c3=1;

		again3:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<"    :: FILTER RECORDS BY ACCOUNT TYPE ::";
		design();
		cout<<'\n'<<'\t'<<"Filter All Savings Accounts                    Press -> 1";
		cout<<'\n'<<'\n'<<'\t'<<"Filter All Current Accounts                    Press -> 2";
		cout<<'\n'<<'\n'<<'\t'<<"MAIN MENU                                      Press -> A ";
		char choice;
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Please Enter Your Choice :: ";
		cin>>choice;
		if(choice=='1')
		{
			filter_account_type(ARR,size,0);   ///0 For Savings
		}
		else if(choice=='2')
		{
			filter_account_type(ARR,size,1);  /// 1 For Current Accounts
		}
		else if(choice=='a' || choice=='A')
		{
			sort_menu();
		}
		else
		{
			cout<<"!!! Wrong Choice ";
			c3++;
			if(c3>3)
			{
				sort_menu();
			}
			getch();
			goto again3;
		}

	}
	else if(x==4)
	{
		int c4=1;
		again4:
		clrscr();
		cout<<'\n'<<'\n'<<'\t'<<'\t'<<" :: FILTER RECORDS FOR ACCOUNT BALANCES ::";
		design();
		cout<<'\n'<<'\n'<<'\t'<<"Filter Accounts With Minimum Ac. Balance             Press -> 1";
		cout<<'\n'<<'\n'<<'\t'<<"Filter Accounts With Maximum Ac. Balance             Press -> 2";
		cout<<'\n'<<'\n'<<'\t'<<"MAIN MENU                                            Press -> A ";
		char choice;
		cout<<'\n'<<'\n'<<'\n'<<'\t'<<"Please Enter Your Choice :: ";
		cin>>choice;
		if(choice=='1')
		{
			filter_account_balance(ARR,size,0);   ///0 For Savings
		}
		else if(choice=='2')
		{
			filter_account_balance(ARR,size,1);  /// 1 For Current Accounts
		}
		else if(choice=='a' || choice=='A')
		{
			sort_menu();
		}
		else
		{
			cout<<"!!! Wrong Choice ";
			c4++;
			if(c4>3)
			{
				sort_menu();
			}
			getch();
			goto again4;
		}

	}
	else if(*ch=='a' || *ch=='A')
	{
		sbimenu();
	}
	else if(x==0)
	{
		Exit();
	}
	else
	{
		cout<<"!!! Wrong Choice ";
		c++;
		if(c>3)
		{
			sort_menu();
		}
		getch();
		goto again;
	}
	sort_menu();
}
void sort_account_number(account M[],int N,int target)      ///target 0= ascending order //target =1 for descending order
{
	/// Using BUBBLE Sort Method ///
	/// Arranging Records In Order Of Account Number //
	account temp,compare;
	int pos;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N-1-i;j++)
		{
			if(target==0)
			{
				if((M[j].ret_acno())>(M[j+1].ret_acno()))
				{
					temp=M[j];
					M[j]=M[j+1];
					M[j+1]=temp;
				}
			}
			else if(target==1)
			{
				if((M[j].ret_acno())<(M[j+1].ret_acno()))
				{
					temp=M[j];
					M[j]=M[j+1];
					M[j+1]=temp;
				}
			}
		}
	}

}
void sort_account_balance(account M[],int N,int target)      ///target 0= ascending order //target =1 for descending order
{
	/// Using BUBBLE Sort Method ///
	/// Arranging Records In Order Of Account BALANCE //
	account temp,compare;
	int pos;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N-1-i;j++)
		{
			if(target==0)
			{
				if((M[j].ret_acbalance())>(M[j+1].ret_acbalance()))
				{
					temp=M[j];
					M[j]=M[j+1];
					M[j+1]=temp;
				}
			}
			else if(target==1)
			{
				if((M[j].ret_acbalance())<(M[j+1].ret_acbalance()))
				{
					temp=M[j];
					M[j]=M[j+1];
					M[j+1]=temp;
				}
			}
		}
	}
}
void filter_account_type(account M[],int N,int target)      ///target 0= Savings //target =1 for Current
{
	int c=0;
	account RES[100];
	for(int i=0;i<N;i++)
	{
		if(target==0)
		{
			if(strcmpi(M[i].ret_actype(),"Savings")==0)
			{
				RES[c]=M[i];
				c++;
			}
		}
		else if(target==1)
		{
			if(strcmpi(M[i].ret_actype(),"Current")==0)
			{
				RES[c]=M[i];
				c++;
			}
		}
	}
	int new_size=c;
	display_sorted_account(RES,new_size);
}
void filter_account_balance(account M[],int N,int target) /// target =0 for minimum and 1 for maximum
{
	clrscr();
	int c=0;
	account RES[100];
	if(target==0)
	{
		sort_account_balance(M,N,0);    //arranging records in ascending order of balances
		float small=M[0].ret_acbalance();
		cout<<small;
		for(int j=0;j<N;j++)
		{
			if(M[j].ret_acbalance()==small)
			{
				RES[c]=M[j];
				c++;
			}
		}
	}
	else if(target==1)
	{
		sort_account_balance(M,N,1); //arranging records in descending order of balances
		float big=M[0].ret_acbalance();
		cout<<big;
		for(int j=0;j<N;j++)
		{
			if(M[j].ret_acbalance()==big)
			{
				RES[c]=M[j];
				c++;
			}
		}
	}
	int new_size=c;
	display_sorted_account(RES,new_size);

}
void display_sorted_account(account ARR[],int Size)
{
	int pages;

	if(Size<=9)
	{
		pages=1;
	}
	else if(Size%9==0)
	{
		pages=Size/9;
	}
	else
	{
		pages=(Size/9)+1;
	}
	int x=5,y=3,a=1;
	clrscr();
	cout<<'\t'<<'\t'<<'\t'<<"   :: SORTED ACCOUNT DETAILS ::";
	display_labels(x,y);
	int n=1;
	int add=3;
	for(int i=0;i<Size;i++)
	{
		gotoxy(1,y+add);
		cout<<n;
		ARR[i].display(y+add);
		delay(50);
		if(y>18 || (n==Size))
		{
			design();
			gotoxy(5,24);
			cout<<"Page "<<a<<" Of "<<pages;
			if(a<pages)
			{
				gotoxy(55,24);
				cout<<"Press Y For Next Page ...";
			}
			else
			{
				gotoxy(50,24);
				cout<<"Press Any Key To Continue ...";
			}
			char ch;
			ch=getch();
			if(ch!='y' && ch!='Y')
			{
				break;
			}

			if(a<=pages)
			{
				clrscr();
				y=2;
				display_labels(x,y);
				add=1;
			}
			a++;
		}
		n++;
		y=y+2;
	}
}
