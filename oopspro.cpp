

#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>

using namespace std;

map <string, pair<string, pair<vector<string>, vector<string> > > >  hash;
map <string, pair<string, pair<vector<string>, vector<string> > > > :: iterator it;


void add_friend(string id)
{
	string s;
	cout<<" Enter friends id\n";
	cin>>s;
	if(hash.find(s)!=hash.end())
	hash[id].second.second.push_back(s);
	else
	cout<<" No such id exits\n\n";
}

void post_scrap(string id)
{
	string s,i;
	cout<<"enter friend id to post scarp\t";
	cin>>i;

	if(hash.find(i)!=hash.end())
	{
	cout<<"Write scrap\t";
	cin>>s;
	hash[i].second.first.push_back("From "+id+" : "+s);

	}
	else
	cout<<" No such id exits\n\n";

}

void scraps(string id)
{
	int i;
	it=hash.find(id);
	cout<<"------------Your scraps--------\n";
	for(i=0;i<(it->second).second.first.size();i++)
	cout<<(it->second).second.first[i]<<endl;
	cout<<"--------------------------------------\n";
}

void friends(string id)
{
	int i;
	it=hash.find(id);
	cout<<"--------------Your Friends-----------\n";
	for(i=0;i<(it->second).second.second.size();i++)
	cout<<(it->second).second.second[i]<<endl;
	cout<<"--------------------------------------\n";

}


//----------------GAMES-------------------------




void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
int amount=0;
struct node
{
char name[20];
struct node *right;
struct node *down;
}*start,*ptr;

struct abc
{
    int score;
    int bet;
    struct abc *next;
}*ptrabc,*startabc;




void initilze()
{
FILE *fp;
int i,j;
char word[20],aux[200];
fp=fopen("W_G_DATA.txt","r");
rand();
if(fp==NULL)
{
cout<<"can't open file";
getch();
return;
}
i=rand()%5;
for(j=0;j<i;j++)
fgets(aux,200,fp);
ptr=start=(struct node *)malloc(sizeof(struct node));
fscanf(fp,"%s ",word);
//printf("\t%s",word);
strcpy(start->name,word);
fscanf(fp,"%s ",word);
while(strcmp(word,"E_N_D"))
{
ptr->right=(struct node *)malloc(sizeof(struct node));
ptr=ptr->right;
fscanf(fp,"%s ",word);
strcpy(ptr->name,word);
//printf("\t%s",word);
}
ptr->right=NULL;
}

int check(char test[],int t,char ans[][20])
{
int j;
ptr=start->right;
while(ptr!=NULL)
{
  if(!stricmp(test,ptr->name))
  {
  for(j=0;j<t;j++)
     {
	if(!stricmp(test,ans[j]))
	{
//	textcolor(YELLOW);
	cout<<"repeated\n";
	return 0;
	}
      }
     // textcolor(5);
  cout<<"correct\n";
  return (strlen(test));
  }
ptr=ptr->right;
}
//textcolor(RED);
cout<<"wrong\n";
return 0;
}

void Word_find()
{
clock_t startc,endc;
int t=0,marks=0,m;
char test[20],ans[20][20];
system("cls");
initilze();
startc=clock();
printf("\t----WELCOME----\n\t**WORD FINDER**\nmake relevant words with this alphabets %s\t",start->name);
printf("\n you have only 30 secs \n\t");
while(1)
{
endc=clock();

if((endc-startc)/CLK_TCK>30)
break;

scanf("%s",test);
    if((m=check(test,t,ans)))
    { marks+=m;
    strcpy(ans[t++],test);
     }
}

//textcolor(BLUE+BLINK);
cout<<"\n\n Marks are"<<marks;
getch();
}

void Tic()
{
    int i;
    int player = 0;
    int winner = 0;
    int choice = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    char board [3][3] = {
		 {'1','2','3'},
		{'4','5','6'},
		 {'7','8','9'}
			};

system("cls");
	//textbackground(RED);
	//textcolor(GREEN);
	//textmode(C40);
	gotoxy(14,1);
	cout<<"TIC";
//	delay(700);
	gotoxy(18,1);
	cout<<"TAC";
	//delay(1000);

    for (i = 0; i<9 && winner==0; i++)
    {
	system("cls");

	//textcolor(3);
	//textmode(C40);
	//textbackground(BLUE);tf("\n\n");
	printf("\n\n");
	printf(" %c Û %c Û %c", board[0][0], board[0][1], board[0][2]);
	printf("\n");
	printf("ÜÜÜÛÜÜÜÛÜÜ");
	printf("\n");

	printf(" %c Û %c Û %c", board[1][0], board[1][1], board[1][2]);
	printf("\n");
	printf("ÜÜÜÛÜÜÜÛÜÜ");
	printf("\n");
	printf(" %c Û %c Û %c", board[2][0], board[2][1], board[2][2]);
	printf("\n");
	player = i%2 + 1;
	do
	{
	    cout<<"\nPlayer"<<player<<" please enter the number of the square where you want to place your sign % ";
		cout<<((player==1)?'X':'O');
	 cin>>choice;
	    row = --choice/3;
	    column = choice%3;
	}while(choice<0 || choice>9 || board [row][column]>'9');
	board[row][column] = (player == 1) ? 'X' : 'O';

	if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
	   (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
	   winner = player;

	else

	    for(line = 0; line <=2; line++)
		if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
		    (board[0][line]==board[1][line] && board[0][line]==board[2][line]))
		    winner = player;


    }
	 //textcolor(GREEN+BLINK);

	cout<<endl<<endl;
	cout<<board[0][0]<<board[0][1]<<board[0][2];
	cout<<endl;
	//cprintf("---|---|---\n");
	cout<<endl;
	cout<< board[1][0]<< board[1][1]<< board[1][2];
		cout<<endl;
	//cprintf("---|---|---\n");
		cout<<endl;
		cout<< board[2][0]<< board[2][1]<< board[2][2];
		cout<<endl;
	//textcolor(RED+BLINK);
	if(winner==0)
	    cout<<"The game is a draw";
	else
	    cout<<"Player "<<winner<<" has won";
      getch();

}


void cal(int a,int p,int s)
{


	 switch(a)
	    {
		case 1:if((p>(s+20))&&(p<(s+40)))
		{
		    amount=amount+(ptrabc->bet*3);
		}
		else
		{
		    amount=amount-(ptrabc->bet);
		}
		break;

		    case 2:if(p>s+40)
		{
		    amount=amount+(ptrabc->bet*3);
		}
		else
		{
		    amount=amount-(ptrabc->bet);
		}
		break;
		case 3:
		    if(p<s+20)
		{
		    amount=amount+(ptrabc->bet*3);
		}
		else
		{
		    amount=amount-(ptrabc->bet);
		}
		break;
	    }
	    cout<<"\n u have " <<amount<<"rupees";
	}
void Cricket()
{

  //  system(cls);
    int ch,s,a,p,amt;
    char b;
system("cls");
    cout<<"\t\t\tWELCOME TO THE CRICKET GAMBLE";



    cout<<"\n\t\t\tenter your choice";
   cout<<"\n \t\t1.place new beat";
    cout<<"\n\t\t2.previous record";
   cout<<"\n\t\t3.total money earned";
    cin>>ch;
    switch(ch)
    {
    case 1:
	{
	    do
	    {
	    srand(time(NULL));
	    s=(rand()%(200-1))+1;
	    cout<<"SCORE IS" <<s;
	    cout<<"\n what will be the range of score after this over";
	    cout<<"\n more den "<<s+20<<"press 1";
	   cout<<"\n more den "<<s+40<<" press 2";
	   cout<<"\n less den"<<s+20<<"press 3";
	    cin>>a;
	    cout<<"enter d amount you want to bet";
	    startabc=(struct abc*)malloc(sizeof(struct abc));
	    ptrabc=startabc;
	    cin>>ptrabc->bet;

	    srand(time(NULL));
	    p=(rand()%(250-s))+s;
	    cout<<"\t\t\t\t\t\t\tTHE SCORE NOW IS "<<p;
		cal(a,p,s);
	       cout<<"\n wana bet more";
	       fflush(stdin);
	       cin>>b;
	       if(b=='y')
	       {
		   ptrabc->next=(struct abc*)malloc(sizeof(struct abc));
		   ptrabc=ptrabc->next;
	       }
	    }while(b=='y');
	}
	break;
    case 2:
	{
	    cout<<"your last score was"<<amt;
	}

    }
//    return 0;
}








void play_games()
{
int choice;
char c='y';
system("cls");
while(c=='y')
{
//textmode(BW80);
//textcolor(3+BLINK);
cout<<"Welcome To Game Zone\n\n\n\n\n";
//textcolor(YELLOW);
cout<<"Tic Tac press 1\n\n";
cout<<"Word Finder press 2\n\n";
cout<<"cricket Gamble press 3 \n";

//textmode(C80);

cin>>choice;
switch(choice)
{
case 1: Tic();
break;
case 2: Word_find();
break;

case 3: Cricket();
break;
default:play_games();
}
cout<<"\n Do you want to play more games ";
fflush(stdin);
cin>>c;
system("cls");
}
getch();
}














void timeline(string id)
{
	int i=1;
	while(i)
	{
    cout<<" \n*-*-*-*-*-*-*-Welcome,  "<<id<<"-*-*-*-*-*-*-*-\n"<<endl;
    cout<<" To view your friends press 1\n";
    cout<<" To see scraps(including yours) press 2\n";
    cout<<" To post scrap press 3\n";
    cout<<" To add friend press 4\n";
    cout<<" To play Games press 5\n";
	cout<<" LOGOUT press 0\n";
	cin>>i;
	if(i==1) friends(id);
	if(i==2) scraps(id);
	if(i==3) post_scrap(id);
	if(i==4) add_friend(id);
	if(i==5) play_games();

	}

}

int first_display()
{
	int b;
	cout<<"-------------YAARI.COM-------------\n\n";
	cout<<" Create new account press 1\n";
	cout<<" Login press 2\n";
	cout<<" Exit press 0\n";
	cin>>b;
	return b;
}


int main()
{
	int j=1,test=1;
	string id,pass="";
char ch;
   	hash["admin"].first="admin";
   	test=first_display();
while(test)
{

   	if(test==1)
   	{
			cout<<"\t Enter Userid which you want"<<endl;
			cin>>id;
			if(hash.find(id)==hash.end())
			{
				cout<<"\tEnter Password "<<endl;
				//cin>>pass;
				ch=_getch();
				 while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
  // cout<<pass;

				hash[id].first=pass;
			}
				else
				cout<<"\t Sorry, User id already been there\n";
		}


   	if(test==2)
   	{
   	    string pass1="";
		 cout<<" \t \t Enter Login Id"<<endl;
        cout<<" \t \t ";
        cin>>id;
    if(hash.find(id)!=hash.end())
    {
		   		cout<<"\t Enter password\t";
		   		//cin>>pass;
		   		ch=_getch();
				 while(ch != 13){//character 13 is enter
      pass1.push_back(ch);
      cout << '*';
      ch = _getch();
   }
		   		if(hash[id].first==pass1)
		   		timeline(id);
		   		else
		   		cout<<"\t Wrong Password\n";
	}
	else
	cout<<"\tNo userid found\n\n";;
	}
test=first_display();
}

}





