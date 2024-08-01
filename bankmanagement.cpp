//Bank Management System Using OOP Concepts
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<string>
//Standard Library
using namespace std;

//Class:1
class bank
{	
protected:
//Variable Declaration(Protected)	
int menuWidth=28;
int numWidth=17;	
int gohome,menuID;

public:
	//Constructor
	bank()
	{
	gohome=0;
	menuID=0;	
	}
	
    void get()
    {
    cout<<endl;	
	cout<<"\t\t        Press 1 to go Main Menu: "<<endl;
    cin>>gohome;
	}
	
	void ID()
	{
	cout<<endl;	
	cout<<"\t\t      Plz Select Your Menu ID: "<<endl;
	cin>>menuID;	
	}
	
	void show()
    {
    //Loop	
    for(int i=0;i<5;i++)
    {
    cout<<"\t \t ************************************"<<endl;	
	cout<<"\t \t *        WELCOME TO MY Bank        *"<<endl;
	cout<<"\t \t ************************************"<<endl;
	system("color 9");
    //Clear Screen:
	system("cls");
	//Delay Screen:
	Sleep(500);
	}
	
    cout<<"\t \t ************************************"<<endl;	
	cout<<"\t \t *        WELCOME TO My Bank        *"<<endl;
	cout<<"\t \t ************************************"<<endl;
	Sleep(700);
	
	system("color 4");	 
    cout<<endl;
    
    //Goto Lable
	lable0:	
	bank::get();
	
	//Conditional Statement
	if(gohome==1)
	{
	system("cls");	
	bank::menu();	
	}	
	else
	{
	cout<<"\t \t Invalid Input Try Again!"<<endl;	
	goto lable0;
    }
	}
	
	void menu()
	{
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *           WELCOME TO BANK MENU            *"<<endl;
	cout<<"\t *********************************************"<<endl;
    
	//Delay Screen Function:
	Sleep(600);
	
	//Color Text Function
    system("color 9");
    cout<<"\t \t \t Main Menu"<<endl;
	
	cout<<"          --------------------------------------------"<<endl;
	cout<<"         |      ID       |            Menu            |"<<endl;
	cout<<"          --------------------------------------------"<<endl;

    cout << right << setw(numWidth)  << 1;    
    cout << right << setw(menuWidth) << "Home Page";   
    cout<<endl;
    Sleep(500);
    
	cout<<"         |_______________|____________________________|"<<endl;
	cout << right << setw(numWidth)  << 2;
    cout << right << setw(menuWidth) << "Cash Deposite"; 
	cout<<endl;
	Sleep(500);
	  
	cout<<"         |_______________|____________________________|"<<endl;
	cout << right << setw(numWidth)  << 3;
    cout << right << setw(menuWidth) << "Cash Withdraw";
    cout <<endl;
    Sleep(500);
    
	cout<<"         |_______________|____________________________|"<<endl;
    cout << right << setw(numWidth)  << 4;    
    cout << right << setw(menuWidth) << "Utility Bills";
	cout<<endl;
	Sleep(500); 
	
	cout<<"         |_______________|____________________________|"<<endl;
	cout << right << setw(numWidth)  << 5;
    cout << right << setw(menuWidth) << "Bank Loan";
    cout <<endl;
    Sleep(500);
    
	cout<<"         |_______________|____________________________|"<<endl;	
	cout << right << setw(numWidth)  << 6;
    cout << right << setw(menuWidth) << "Contact Us";
    cout <<endl;
    Sleep(500);
	cout<<"         |_______________|____________________________|"<<endl;	
	}
	~bank()
	{
		
	}
};

class deposite:public bank
{
    protected:
    string dpname,cnic;
	int accno,depamount;
	int currbalance,newbalance;	

    public:
    
    deposite()
    {
    dpname="null";
	cnic="null";
	accno=0;
	depamount=0;
	currbalance=0;
	newbalance=0;	
	}
	
    void get()
	{
	system("color 3");
	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *             Deposite Details              *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	
	cout<<"\t\t     Plz enter your name: "<<endl;
	cin>>dpname;
	cout<<"\t\t     Plz enter your CNIC No: "<<endl;
	cin>>cnic;
	cout<<"\t\t     Plz enter the account number: "<<endl;	
	cin>>accno;
	cout<<"\t\t     Plz enter the amount u want to deposite: "<<endl;	
	cin>>depamount;
	cout<<"\t\t     Plz enter your balance amount: "<<endl;	
	cin>>currbalance;
	newbalance=currbalance+depamount;
	cout<<endl;
	}	
	
	void show()
	{
	system("cls");	
	system("color 8");	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *              Deposite Recipt              *"<<endl;
	cout<<"\t *********************************************"<<endl;
	
	cout<<"         |_________________________________________|"<<endl;
	cout<<endl;
	
	time_t ttime = time(0);
    char* dt = ctime(&ttime);
    cout << "\t  date and time: " << dt << endl;
	Sleep(500);
	
	cout<<"\t\t     User name: "<<dpname<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	
	cout<<"\t\t     CNIC No: "<<cnic<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	
	cout<<"\t\t     Account number: "<<accno<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	
	cout<<"\t\t     Deposite amount: "<<depamount<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	
	cout<<"\t\t     Balance amount: "<<currbalance<<endl;		
    cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	
	cout<<"\t\t     New amount: "<<newbalance<<endl;		
    cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	
	cout<<"\t\t Thank you for banking with us"<<endl;
	cout<<"         |_________________________________________|"<<endl;
	}
	
	void writedata()
	{
	deposite d;	
	//write data:
	ofstream fout;
	fout.open("withdraw.txt",ios::binary|ios::out);
	d.get();	
	fout.write((char*)&d,sizeof(d));
	fout.close();
	cout<<"\t \t    Your Data is saved into file successfully"<<endl;
	Sleep(800);
	system("cls");
	
	//Read Data:
	ifstream fin;
	fin.open("withdraw.txt",ios::binary|ios::in);
	while(fin.read((char*)&d,sizeof(d)))
	{
	d.show();	
	}
	fin.close();
	
	cout<<endl;
	lable1:	
	bank::get();
	if(gohome==1)
	{
	system("cls");	
	bank::menu();	
	}	
	else
	{
	cout<<"\t \t Invalid Input Try Again!"<<endl;	
	goto lable1;
    }
}
    //destructor
    ~deposite()
    {
	}
};

class withdraw:public deposite
{
	protected:
	string withname;
	int pin,currbal;
	int withamount,newbal;	
		
	public:
	withdraw()
	{
	withname="null";
	pin=0;
	currbal=0;
	newbal=0;
	withamount=0;	
	}
		
	void get()
	{
	system("color 3");
	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *           Transaction Details             *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	
	cout<<"\t\t     Plz enter your name: "<<endl;
	cin>>withname;
	cout<<"\t\t     Plz enter your 4 digit pin code: "<<endl;
	cin>>pin;
	cout<<"\t\t     Plz enter the withdraw amount: "<<endl;	
	cin>>withamount;

	cout<<"\t\t     Plz enter your balance amount: "<<endl;	
	cin>>currbal;
	newbal=currbal-withamount;
	cout<<endl;
	}
	
	void show()
	{
	system("cls");
	system("color 2");	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *             Transaction Recipt             *"<<endl;
	cout<<"\t *********************************************"<<endl;
	
	time_t ttime = time(0);
    char* dt = ctime(&ttime);
    cout << "\t  date and time: " << dt << endl;
	Sleep(500);
	
	cout<<"         |_________________________________________|"<<endl;
	cout<<endl;
	cout<<"\t\t     User name: "<<withname<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);

	cout<<"\t\t     Pin Code: "<<pin<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t     Withdraw amount: "<<withamount<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t     Balance amount: "<<currbal<<endl;		
    cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t     New amount: "<<newbal<<endl;		
    cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t Thank you for banking with us"<<endl;
	cout<<"         |_________________________________________|"<<endl;
	}
	
	void writedata()
	{
	withdraw w;	
	//write data:
	ofstream fout;
	fout.open("withdraw.txt",ios::binary|ios::out);
	w.get();	
	
	fout.write((char*)&w,sizeof(w));
	fout.close();
	
	cout<<"\t \t    Your Data is saved into file successfully"<<endl;
	Sleep(1000);
	system("cls");
	
	//Read Data:
	ifstream fin;
	fin.open("withdraw.txt",ios::binary|ios::in);
	
	while(fin.read((char*)&w,sizeof(w)))
	{
	w.show();	
	}
	fin.close();

	cout<<endl;
	lable2:
	bank::get();
	if(gohome==1)
	{
	system("cls");	
	bank::menu();	
	}	
	else
	{
	cout<<"\t \t Invalid Input Try Again!"<<endl;	
	goto lable2;
    }
}
    ~withdraw()//destructor
    {
	}
};

class utilitybills:public withdraw
{
	protected:
    
	string ref,payment;
	int billid,billamount;	
    
	public:
	
	utilitybills()
	{
	ref="null";
	payment="null";
	billid=0;
	billamount=0;	
	}	
    
	void get()
	{	
	system("color 3");
	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *           Utility Bill Details            *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	
	cout<<"\t\t Plz enter your Bill refference No: "<<endl;
	cin>>ref;
	cout<<"\t\t Plz enter the bill amount: "<<endl;	
	cin>>billamount;
	cout<<"\t\t Plz enter your payment Type Cash/Credit Card: "<<endl;	
	cin>>payment;	
	}	
	
	void billmenu()
	{ 
	cout<<"          --------------------------------------------"<<endl;
	cout<<"         |      ID       |         Bill Type          |"<<endl;
	cout<<"          --------------------------------------------"<<endl;

    cout << right << setw(numWidth)  << 1;    
    cout << right << setw(menuWidth) << "LESCO BILLS";   
    cout<<endl;
    Sleep(500);
    
	cout<<"         |_______________|____________________________|"<<endl;
	cout << right << setw(numWidth)  << 2;
    cout << right << setw(menuWidth) << "SUI GAS"; 
	cout<<endl;
	Sleep(500);
	  
	cout<<"         |_______________|____________________________|"<<endl;
	cout << right << setw(numWidth)  << 3;
    cout << right << setw(menuWidth) << "PTCL";
    cout <<endl;
    Sleep(500);
	cout<<"         |_______________|____________________________|"<<endl;	
	cout<<endl;
	
	lable:
	cout<<"\t\t    Plz Select your Bill ID: "<<endl;
	cin>>billid;
	
	if(billid==1)
	{
	system("cls");	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *           LESCO Online Bills              *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	Sleep(500);
	}
	
	else if(billid==2)
	{
	system("cls");
	system("color 6");	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *        SUI GAS Online Bill Payment        *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	Sleep(500);
	}
	
	else if(billid==3)
	{	
	system("cls");	
	system("color 1");
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *           PTCL Online Bill Portal         *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	Sleep(500);
	}
	
	else
	{
	cout<<"Invalid Input Try Again! "<<endl;
	goto lable;
	}
    }
    
	void show()
	{
	system("cls");	
	system("color 2");	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *             Bill Payment Recipt           *"<<endl;
	cout<<"\t *********************************************"<<endl;
	
	time_t ttime = time(0);
    char* dt = ctime(&ttime);
    cout << "\t  date and time: " << dt << endl;
	
	cout<<"         |_________________________________________|"<<endl;
	cout<<endl;
	cout<<"\t\t     Bill Ref: "<<ref<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);

	cout<<"\t\t     Total Amount: "<<billamount<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t     Payment Type: "<<payment<<endl;
	cout<<"         |_________________________________________|"<<endl;
    
	Sleep(500);
	cout<<"\t     Thank you for the payment of "<<billamount<<"Rs/-"<<endl;
	cout<<"         |_________________________________________|"<<endl;
	}
	
	void writedata()
	{
	utilitybills u;	
	//write data:
	ofstream fout;
	fout.open("utility.txt",ios::binary|ios::out);
	u.get();	
	fout.write((char*)&u,sizeof(u));
	fout.close();
	
	cout<<"\t \t    Your Data is saved into file successfully"<<endl;
	Sleep(1000);
	system("cls");
	
	//Read Data:
	ifstream fin;
	fin.open("utility.txt",ios::binary|ios::in);
	
	while(fin.read((char*)&u,sizeof(u)))
	{
	u.show();	
	}
	fin.close();
	
	cout<<endl;	
	lable3:
	bank::get();
	
	if(gohome==1)
	{
	system("cls");	
	bank::menu();	
	}
		
	else
	{
	cout<<"\t \t Invalid Input Try Again!"<<endl;	
	goto lable3;
    }
}
    ~utilitybills()
    {
	}
};

class loan:public utilitybills
{
protected:
    int bankstat,loanamount;
	string name,city,branch;
public:

    loan()
    {
    bankstat=0;
	loanamount=0;
	name="null";
	city="null";
	branch="null";	
	}
    void get()
	{
	system("color 3");
	
	cout<<"\t *********************************************"<<endl;	
	cout<<"\t *           Verification Details            *"<<endl;
	cout<<"\t *********************************************"<<endl;	
	
	cout<<"\t\t     Plz enter your Name: "<<endl;
	cin>>name;
	cout<<"\t\t     Plz enter the loan amount: "<<endl;	
	cin>>loanamount;
	cout<<"\t\t     Plz enter your bank statement: "<<endl;	
	cin>>bankstat;	
	cout<<"\t\t     Plz enter your CNIC No: "<<endl;	
	cin>>cnic;
	cout<<"\t\t     Plz enter your City: "<<endl;	
	cin>>city;
	cout<<"\t\t     Plz enter your branch name: "<<endl;	
	cin>>branch;	
	}	
	
	void show()
	{
	system("color 2");	
	if(bankstat>=loanamount)
	{
	cout<<"\t ***********************************************"<<endl;	
	cout<<"\t *  Congratulations you are eligible for loan  *"<<endl;
	cout<<"\t ***********************************************"<<endl;
	
	time_t ttime = time(0);
    char* dt = ctime(&ttime);
    cout << "\t  date and time: " << dt << endl;
	
	cout<<"         |_________________________________________|"<<endl;
	cout<<endl;
	cout<<"\t\t     Customer Name: "<<name<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);

	cout<<"\t\t     Loan Amount: "<<loanamount<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t     Bank Statement: "<<bankstat<<endl;
	cout<<"         |_________________________________________|"<<endl;
    
	cout<<endl;
	cout<<"\t\t     CNIC No: "<<cnic<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);

	cout<<"\t\t     City Name: "<<city<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t\t     Branch Name: "<<branch<<endl;
	cout<<"         |_________________________________________|"<<endl;
	Sleep(500);
	cout<<"\t        Thank you for banking with us"<<endl;
	cout<<"         |_________________________________________|"<<endl;
	}
    else
    {
    cout<<"\t *****************************************"<<endl;	
	cout<<"\t *  Sorry!you are Not eligible for loan  *"<<endl;
	cout<<"\t *****************************************"<<endl;	
	}
    }
    
	void writedata()
	{
	loan l;	
	//write data:
	ofstream fout;
	fout.open("loan.txt",ios::binary|ios::out);
	l.get();	
	fout.write((char*)&l,sizeof(l));
	fout.close();
	cout<<"\t \t    Your Data is saved into file successfully"<<endl;
	Sleep(1000);
	system("cls");
	//Read Data:
	ifstream fin;
	fin.open("loan.txt",ios::binary|ios::in);
	while(fin.read((char*)&l,sizeof(l)))
	{
	l.show();	
	}
	fin.close();
	
	cout<<endl;	
	lable4:
	bank::get();
	if(gohome==1)
	{
	system("cls");	
	bank::menu();	
	}	
	else
	{
	cout<<"\t \t Invalid Input Try Again!"<<endl;	
	goto lable4;
    }
	}
	~loan()
	{
	}
};

class login:public loan
{
    private:
    string user,pass;	
    int contactWidth=22;
    int contactname=23;
    
	public:
	login(string u,string p)
	{
	user=u;
	pass=p;	
	}
	
	void get()
	{
	system("color 2");	
	cout<<"\t    **********************************************"<<endl;	
	cout<<"\t    *                Login Details               *"<<endl;
	cout<<"\t    **********************************************"<<endl;	
	cout<<endl;
	
	cout<<"\t\t\t Plz enter the user name: "<<endl;
	cin>>user;
	cout<<"\t\t\t Plz enter the password: "<<endl;
	cin>>pass;	
    }
    
    void show()
    {
    int i=0;
	//Do While Loop
	do
	{
	login::get();
	if(user=="malikzain" && pass=="1415")
	{	
	bank::show();
	login::display();
	Sleep(600);
    }	
	else
	{	
    cout<<"\t Inavlid input Try Again! You have only 3 Attempts"<<endl;
	cout<<endl;
    i++;
	}
    }
    while(i<2);
    
}
    //Dominant Function
    void display()
    {	
    
	lable6:	
	bank::ID();	
    if (menuID==1)
	{
	system("cls");
	bank::menu();	
	}
		
	else if(menuID==2)
	{
	system("cls");
	deposite::writedata();	
	}
	
	else if(menuID==3)
	{
	system("cls");
	withdraw::writedata();	
	}
	
	else if(menuID==4)
	{
	system("cls");
	utilitybills::billmenu();
	utilitybills::writedata();	
	}
	else if(menuID==5)
	{
	system("cls");	
	loan::writedata();
	}
	else if(menuID==6)
	{
	system("cls");	
	cout<<"\t    ************************************"<<endl;	
	cout<<"\t    *          CONTACT DETAILES        *"<<endl;
	cout<<"\t    ************************************"<<endl;	
	cout<<endl;
    Sleep(500);
    
	cout<<"          ----------------------------------------"<<endl;
	cout<<"         |      Name       |    Mobile Number     |"<<endl;
	cout<<"          ----------------------------------------"<<endl;
    Sleep(500);
    
	cout << right << setw(contactname)  <<	"Rabi Khan" ;    
    cout << right << setw(contactWidth) <<"03244437710" ;   
    cout<<endl;
    cout<<"         |_______________|________________________|"<<endl;
	Sleep(500);
	
	cout << right << setw(contactname)  << "Asher Khan";
    cout << right << setw(contactWidth) << "03234321415"; 
	cout<<endl;  
	cout<<"         |_______________|________________________|"<<endl;
    cout<<endl;
	}
	
	else
	{
	cout<<"\t \t You have not select any option go to main menu"<<endl;	
	Sleep(900);
	bank::menu();
    }
	goto lable6;
	}
};

int main()
{
	//Function Calling
	login l ("rabikhan","66321");
	l.show();
	
	return 0;
}