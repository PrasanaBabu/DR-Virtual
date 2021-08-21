#include<graphics.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<process.h>

void medic();
void contdr();
void patdet();
void firstaid();

void main()
{
       int gd=DETECT, gm;
       initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
       setcolor(RED);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
       outtextxy(70,100,"Dr.Virtual");
       settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
       outtextxy(100,300,"Done By Keerthivasan.S and B.Prasana");
       getch();
       closegraph();

	int i,n;
	char ch;
	cout<<"                          Doctor.Virtual"<<endl;
	do
	{
	cout<<"How may I help you \n";
	cout<<" 1. Natural Remedies for common health issues\n";
	cout<<" 2. First-Aid Procedures at critical situations\n";
	cout<<" 3. Contact details for doctors\n";
	cout<<" 4. Details of patients consulted\n";
	cout<<" 5. Delete all patient details created before\n";
	cout<<" 6. Exit\n";
	cout<<"Enter you options";
	cin>>n;
	clrscr();
	if(n==1)
		medic();
	else if(n==2)
		firstaid();
	else if(n==3)
		contdr();
	else if(n==4)
		patdet();
	else if(n==5)
	{
		fstream begin("doc.txt",ios::out|ios::trunc);
		begin.close();
	}
	else if(n==6)
		exit(0);
	else
		cout<<"Enter the option properly again";
	cout<<"\nDo you wish to continue?";
	cin>>ch;
	clrscr();
	}while(ch=='y'||ch=='Y');
       //getch();

}
void medic()
{
	fstream f("Doc.txt",ios::out|ios::app);
	fstream temp("temp.txt",ios::in|ios::out|ios::trunc);
	clrscr();
	
	int op,age,wt,sd;
	char name[50],a[40],b[40],c[40];
	
	cout<<"Enter Your Name : ";
	   gets(name);
	f<<name<<',';
	temp<<name<<',';
	
	cout<<"Enter your weight : ";
	   cin>>wt;
	f<<wt<<' ';
	temp<<wt<<' ';
	
	cout<<"Enter your age : ";
	   cin>>age;
	f<<age<<' ';
	temp<<age<<' ';
	f.close();
	
	cout<<"\nChoose the Health Problem you are suffering from\n";
	cout<<"1.Stomach Pain\n";
	cout<<"2.Headache\n";
	cout<<"3.Common cold\n";
	   cin>>op;
	cout<<"Enter Number of days you have been suffering from the above disease "<<endl;
	   cin>>sd;
	clrscr();
	
	temp.seekg(0);
	temp.getline(a,50,',');
	temp.getline(b,50,' ');
	temp.getline(c,50,' ');
	
	while(!temp.eof())
	{
		cout<<"Patient Name: "<<a<<endl;
		cout<<"Patient Weight: "<<b<<endl;
		cout<<"Patient Age: "<<c<<endl;
		temp.getline(a,50,',');
		temp.getline(b,50,' ');
		temp.getline(c,50,' ');
	}
	temp.close();
	if(op==1)
	{
		cout<<"We suppose you have stomach pain\n";
		if(sd<=4)
		{
		   if(age<=12)
			cout<<"\t Eat Bland Food.\n\t Snack on Yoghurt \n\t Apply mild warmth using a towel on the kid's stomach ";
		   if(age>12)
		   {
		      cout<<"\nSip Chamomile Tea or Dark Ginger tea \n Use Foot Reflexology "<<endl;
		      cout<<"If Constipation Persists : Eat Bananas,Dates and Boiled Peas"<<endl;
		      cout<<"If Dysentry persists : Mix 1 Teaspoon of turmeric Powder with Yoghurt and consume twice a day ";
		   }
		}
		if(sd>4)
		{
			char ch;
			cout<<"As you are suffering from the symtoms for too long please meet the Dr. immediately \n Details will be provided to the nearest doctor"<<endl;
			cout<<"Do you want dr. details?(y/n)";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			    contdr();
		}
	}
	if(op==2)
	{
		cout<<"We suppose you have Headache\n";
		if(sd<=4)
		{
		    if(age<=12)
			cout<<"\tPut a cold,moist cloth or ice pack on the part of the head that hurts.\tGently massage your child's neck and shoulders.\n\tGive your child water,juice and other drinks that do not contain caffeine.";
		    if(age>12)
		    {
			cout<<"\t Apply Lavender Oil . \n\t Take Ginger Tea "<<endl;
			cout<<"\t Add Magnesium to your diet by having :\t\t Almonds&Cashews \t\t Milk&Eggs \t\t Sesame Seeds "<<endl;
		    }
		}
		if(sd>4)
		{
			char ch;
			cout<<"As you are suffering from the symtoms for too long please meet the Dr. immediately \n Details will be provided to the nearest doctor"<<endl;
			cout<<"Do you want dr. details?(y/n)";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			    contdr();

		}
	}

	if(op==3)
	{
	    cout<<"We suppose you have Common Cold\n ";
	    if(sd<=4)
	    {
		if(age<=18)
		{
		   cout<<"\t Give 1 spoon of honey to the Kid \n\t Make the place moisturised and less stuffy \t\n Hot soups also help in reducing cold and cough \t\n TAKE REST ";
		}
		if(age>18)
		{
		   cout<<"\t Gargle Salt water to soothe your throat \n\t Take 1 spoon of honey \n\t Make the place moisturised and less stuffy \t\n Hot soups also help in reducing cold and cough \t\n TAKE REST ";
		}
	    }
	    if(sd>4)
	    {
			char ch;
			cout<<"As you are suffering from the symtoms for too long please meet the Dr. immediately \n Details will be provided to the nearest doctor"<<endl;
			cout<<"Do you want dr. details?(y/n)";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			    contdr();

	   }
	}
}
void firstaid()
{
	int opt;
	cout<<"Choose the emergency"<<endl;
	cout<<"1. Heart Attack"<<endl;
	cout<<"2. Fracture"<<endl;
	cout<<"3. Heavy Blood Loss"<<endl;
	cout<<"4. Snake Bite"<<endl;
	cout<<"5. Fits"<<endl;
	cout<<" Enter Your Option ";
	cin>>opt;
	if(opt==1)
	{
		cout<<"If the injured is suffering from Heart Attack, You will have to perform CPR "<<endl;
		cout<<"CardioPulmonary Resuscitation - CPR "<<endl;
		cout<<"Procedure is as follows : "<<endl;
		cout<<"Compressions: RESTORE BLOOD CIRCULATIONS"<<endl;
		cout<<"\t 1. Put the person on his/her back."<<endl;
		cout<<"\t 2. Kneel next to the person, place one hand above the other and push \n\t hard straight down at the rate of 100 compressions/minute"<<endl;
		cout<<"Breathing : BREATHE FOR THE PERSON "<<endl;
		cout<<"\t 1. With the airway open , pinch the nostrils shut for mouth-to-mouth \n\t breathing and cover the persons mouth with yours"<<endl;
		cout<<"\t 2. Continue CPR until there are sign of active movement or emergency \n\t medics take over"<<endl;
	}
	if(opt==2)
	{
		cout<<"If the injured is found to have broken bones, You will have to do the following First-Aid :- "<<endl;
		cout<<"\t 1. Examine Injured area for swelling or deformities "<<endl;
		cout<<"\t 2. Use a Splint and clean Bandages to immobilise the fractures part.\n\t Use any available sterile splint like item if a medical shop \n\t  isnt in the vicinity "<<endl;
		cout<<"\t 3. Apply ice packs to the swelling, Check for Pulse sensation below\n\t the fractures area."<<endl;
		cout<<"\t 4. DO ask questions to the patient about the cause of injury \n\t and inform the Medics who take over"<<endl;
	}
	if(opt==3)
	{
		cout<<"If the injured is suffering from Heavy Blood Loss, You will have to do the following first aid :- "<<endl;
		cout<<"\t 1. Remove any obvious dirt or debris from the wound."<<endl;
		cout<<"\t 2. Stop the Bleeding : Place a sterile Bandage or clean cloth on the  \n\t wound. Maintain the pressure on the wound and control bredding. "<<endl;
		cout<<"\t 3. RAISE THE INJURED PART ABOVE THE LEVEL OF THE HEART "<<endl;
		cout<<"\t 4. Help the injured person lie down, preferably on a rug or blanket \n\t prevent loss of body heat"<<endl;
		cout<<"\t 5. Immobilize the injured body part once the bleeding has stopped \n\t Inform all First-Aid measures to the medics that take over."<<endl;

	}
	if(opt==4)
	{
		cout<<"If the injured is suffering from SNAKE BITE, You will have to do the following first aid :- "<<endl;
		cout<<"\t 1. Note the time of the bite. "<<endl;
		cout<<"\t 2. Keep calm and still as movement can cause the venom to travel \n\t more quickly through the body. "<<endl;
		cout<<"\t 3. Remove constricting clothing or jewelry because the area \n\t surrounding the bite will likely swell. "<<endl;
		cout<<"\t 4. Help the injured person lie down, preferably on a rug or blanket \n\t prevent loss of body heat"<<endl;
		cout<<"\t 5. Take a Picture of the snake and provide information to the \n\t Doctor. Carry or Transport the Victim "<<endl;

	}
	if(opt==5)
	{
		cout<<"If the injured is suffering from a SEIZURE, You will have to do the \n following first aid :- "<<endl;
		cout<<"\t 1. Protect them from hurting themselves. Clear away any potentially \n\t dangerous objects."<<endl;
		cout<<"\t 2. Take a note of the time when the seizure started and how \n\t long it lasts. "<<endl;
		cout<<"\t 3. Protect their head by placing something soft underneath it, \n\t like a towel, and loosen any clothing around their neck. "<<endl;
		cout<<"\t 4. Once the seizure has stopped, they may fall into a deep sleep \n\t if they do, open their airway and check their breathing."<<endl;
		cout<<"\t 5. If they're breathing, put them in the recovery position. "<<endl;
	}

}
void contdr()
{       clrscr();
	int ch,op;
	cout<<"Enter the part of the area you live in from the following\n";
	cout<<"1 for North Chennai\n2 for South Chennai\n3 for West Chennai\n4 for East Chennai\n";
	cout<<"\nEnter your option";
	   cin>>ch;
	clrscr();
	if(ch==1)
	{
	     cout<<"Enter the closest location for you from the following(number)\n";
	     cout<<"\n1.Ennore \n2.Thiruvottiyur\n3.Mint Street \n4.Washermanpet\n5.Tondiarpet \n6.Royapuram \n7.Perambur\n8.Parry's Corner\n9.Manali\n10.Red Hills ";
	     cout<<"\n Enter the option";
	     cin>>op;
	     clrscr();
	     cout<<endl;
	     switch(op)
	     {
		  case 1:
		     cout<<" Dr.Uma Karthik M.B.B.S \n 306,Kauvery Nagar,Ennore,600057 \n 044-23600057     ";
		  break;
		  case 2:
		     cout<<" Dr.M Chellamariappan M.B.B.S \n thulukka Naicken Street,Tiruvottiyur,600019 \n 044-25731746 ";
		  break;
		  case 3:
		     cout<<" Dr.Amrit M.B.B.S \n 310,Mint Street,Sowcarpet,60079 \n 044-25290867     ";
		  break;
		  case 4:
		     cout<<" Dr.H Nirmala M.B.B.S \n 12/1,Arani Ganga lane,Washermanpet,600021 \n 9840121676 ";
		  break;
		  case 5:
		     cout<<" Dr.MP Jeyapaul M.D.D.Ch.F.I.A.P \n No.35,Kanakapillai Street,Tondiarpet,600081 \n 9840492090 ";
		  break;
		  case 6:
		     cout<<" Dr.A Moinuddin M.B.B.S \n 125,S N Chetty Street,Royapuram,600013 \n 044-25956710    ";
		  break;
		  case 7:
		     cout<<" Dr.RK Bhakthavatsalam M.B.B.S \n 131,Madhavaram High Road,Perambur,600011 \n 044-25371976 ";
		  break;
		  case 8:
		     cout<<" Dr.TV Lakshmi M.B.B.S \n 85\165,Coralmathen Street,Parrys,600001 \n 044-25225759 ";
		  break;
		  case 9:
		     cout<<" Dr.Shifa M.B.B.S \n 47,Periya Thoppu,Manali,600051 \n 9003141343   ";
		  break;
		  case 10:
		     cout<<" Dr.AR Balamurugan M.B.B.S \n Ambedkar Street,Red Hills,600066 \n 044-42612366  ";
	     }
	}

	if(ch==2)
	{
	     cout<<"Enter the closest location for you from the following(number)\n";
	     cout<<"1.Sholinganallur \n2.Chengalpattu \n3.Alandur \n4.Tambaram \n5.Karapakkam \n6.Velachery \n7.Perungudi \n8.Thuraipakkam \n9.Medavakkam \n";
	     cout<<"\n Enter your option";
	     cin>>op;
	     clrscr();
	     cout<<endl;
	     switch(op)
	     {
		  case 1:
		     cout<<"Dr.Paul M.B.B.S \n 93,OMR,Sholinganallur,600119 \n 8646086460      ";
		  break;
		  case 2:
		     cout<<"Dr.Adithya M.B.B.S \n 70,Kanchi high road,Chengalpattu,603002 \n 7373122766     ";
		  break;
		  case 3:
		     cout<<"Dr.SG Vasan.M.B.B.S \n 37,Yadav Street,Alandur,6000   \n  725234789      ";
		  break;
		  case 4:
		     cout<<"Dr.K Keerthana M.B.B.S \n 36,Gandhi Road,West Tambaram, 600045 \n 044-22263670      ";
		  break;
		  case 5:
		     cout<<"Dr.Babu M.B.B.S \n 2/319,OMR,Karapakkam,600097 \n 044-24505700      ";
		  break;
		  case 6:
		     cout<<"Dr.Vikas M.B.B.S \n 4,Arunachalam Road,Velachery,600042 \n 044-65654441      ";
		  break;
		  case 7:
		     cout<<"Dr.Venkatesh Raj M.B.B.S \n 5,639,OMR,Perungudi,600096 \n 044-23551566      ";
		  break;
		  case 8:
		     cout<<"Dr.Sindhu M.B.B.S \n 122,Eashwaran Koil Street,THoraipakkam,600097 \n 8754099922      ";
		  break;
		  case 9:
		     cout<<"Dr.Balaji M.B.B.S \n 10/9,Moovendhar Street,Medavakkam,600100 \n 044-22771257      ";
	     }
	}

	if(ch==3)
	{
	     cout<<"Enter the closest location for you from the following(number)\n";
	     cout<<"1.Pallavaram \n2.St.Thomas Mount \n3.K.K.Nagar \n4.Ramapuram \n5.Ambattur \n6.Maduravoyal \n7.Koyambedu \n8.Mogappair \n9.Nanganallur \n";
	     cout<<"Enter your option";
	     cin>>op;
	     clrscr();
	     cout<<endl;
	     switch(op)
	     {
		  case 1:
		     cout<<"Dr.Karthik M.B.B.S \n 2,Manimegalai Street,Pallavaram,600043 \n  044-22663000      ";
		  break;
		  case 2:
		     cout<<"Dr.Malika Sam M.B.B.S \n 43,Main Road,St.Thomas Mount,600016 \n 044-42333639      ";
		  break;
		  case 3:
		     cout<<"Dr.S Achyuthan M.B.B.S \n 14,P.T.Rajan Salai,K.K.Nagar,600078 \n 044-42616448      ";
		  break;
		  case 4:
		     cout<<"Dr.VJ Chakravarthy M.B.B.S \n 23,Bharathi Nagar Main Road,Ramapuram,603201 \n 9884161687      ";
		  break;
		  case 5:
		     cout<<"Dr.Durai Nivaran M.B.B.S \n 40,Vinayagapuram,Ambattur,600053 \n 9444123801      ";
		  break;
		  case 6:
		     cout<<"Dr.Ganesh M.B.B.S \n 86\2A Kanniamman Main Road,Maduravoyal,600095 \n 9940004146      ";
		  break;
		  case 7:
		     cout<<"Dr.K Bala Murali M.B.B.S \n No2/6,Barathi Avenue,Koyambedu,600107 \n 9841139768       ";
		  break;
		  case 8:
		     cout<<"Dr.Meera M.B.B.S \n 8\11,thiruvallur high road,Mogappair East,600017 \n 9787871864    ";
		  break;
		  case 9:
		     cout<<"Dr.Chitambalam M.B.B.S \n C32,Hindu Colony,Nanganallur,600061 \n 044-22348984         ";

	     }
	}

	if(ch==4)
	{
	     cout<<"Enter the closest location for you from the following(number)\n";
	     cout<<"1.Mambalam \n2.Kodambakkam \n3.T.Nagar \n4.Aynavaram \n5.Puraswalkam \n6.Aminjikarai \n7.Mylapore \n8.Egmore \n9.Guindy \n10.Triplicane\n ";
	     cout<<"Enter your option";
	     cin>>op;
	     clrscr();
	     cout<<endl;
	     switch(op)
	     {
		  case 1:
		     cout<<"Dr.V Sriram M.B.B.S \n 22\38,Arya Gowda Road,West Mambalam,600033 \n 044-23723868";
		  break;
		  case 2:
		     cout<<"Dr.Jhai Kiran M.B.B.S \n 94,Arcot road,Kodambakkam,600024 \n 044-27350645      ";
		  break;
		  case 3:
		     cout<<"Dr.Shreya Suresh M.B.B.S \n 2,Radha Krishnan Street,T.Nagar,600017 \n 8754490508      ";
		  break;
		  case 4:
		     cout<<"Dr.Shiv Shakthi M.B.B.S \n 40,Ayanavaram Main Road,Aynavaram,600023 \n 044-42778321     ";
		  break;
		  case 5:
		     cout<<"Dr.P Lakshmi Narayan M.B.B.S \n 61/50,Vellala street,purasaiwalkam,60048 \n 9841564255      ";
		  break;
		  case 6:
		     cout<<"Dr.Shaji M.B.B.S \n 8/28,Vadagarm Road,Aminjikarai,600029 \n 044-23746220      ";
		  break;
		  case 7:
		     cout<<"Dr.V Nambi M.B.B.S \n No.49,PS Siva Swamy Salai,Mylapore,600004 \n 044-24991140      ";
		  break;
		  case 8:
		     cout<<"Dr.S Rajagopal M.B.B.S \n 10.Halls Road,Egmore,600008 \n 9566141143      ";
		  break;
		  case 9:
		     cout<<"Dr.S Srinivasan M.B.B.S \n 110,Anna Salai,Guindy,600032 \n 9840234430      ";
		  break;
		  case 10:
		     cout<<"Dr.MK Rahman M.B.B.S \n 14,Triplicane High Road,Triplicane,600005 \n 7401177733     ";
	     }
	}
	cout<<endl;
}
void patdet()
{       clrscr();
	char a[50],b[10],c[10];
	fstream f("Doc.txt",ios::in);
	cout<<setw(57)<<setfill('*')<<"  "<<endl;
	cout<<setw(57)<<setfill(' ')<<"  "<<endl;
	cout<<"Patient Name"<<setw(20)<<"Patient Weight"<<setw(20)<<"Patient Age\n";
	cout<<setw(57)<<setfill('*')<<"  "<<endl;
	cout<<setw(57)<<setfill(' ')<<"  "<<endl;
	f.getline(a,50,',');
	f.getline(b,50,' ');
	f.getline(c,50,' ');
	while(!f.eof())
	{

		cout<<setw(20)<<setiosflags(ios::left)<<a<<setiosflags(ios::right)<<setw(10)<<b<<setw(15)<<c<<endl;
		f.getline(a,50,',');
		f.getline(b,50,' ');
		f.getline(c,50,' ');
	}
	cout<<setw(57)<<setfill('*')<<"  "<<endl;
	cout<<setw(57)<<setfill(' ')<<"  "<<endl;
	f.close();
}
