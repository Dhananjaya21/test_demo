#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<string>

using namespace std;
//dhana1
//kisal
//declare variables
const int width=200,height=20;
const int snakeStartX=1,snakeStartY=1;
int i=0,t=0,p=0,d=0,e=10,q,bx,by,bx1,by1,bx2,by2,bx3,by3,bx4,by4,bx5,by5;
bool gameover;
int tailLength;
int snakeX,snakeY;
int snakepartX=1,snakepartY=1;
int y=0,total=0;

int mpa[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

enum controll{STOP=0,LEFT,RIGHT};
controll dir;

enum bullet{RTOP=0, SHOOT};
bullet bul;
enum bullet2{ATOP=0,SHOT};
bullet2 bul2;
enum bullet3{PTOP=0,SHT};
bullet3 bul3;
enum bullet4{LTOP=0,SH};
bullet4 bul4;
enum bullet5{STOP5=0,S5};
bullet5 bul5;





//function to take cursor to a specified location
void gotoXY(int x=0,int y=0){
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(h,c);
	
}



//declare functions
void setup();
void logic();
void maze();
void input();
void snake();
void snakeMoving();

void startScreen(); //to display start screen
void gameName(); //to display the gamename
void LOADING(); //for loading animation
void congrats(); //to display congrats
void instructions();//to diplay the instructions
void gameOver();//to display the game over in console
void congrats();

//main functions
int main(){


	setup();
	LOADING();
	gameName();
	startScreen();
	instructions();
	
	 while(!gameover)
	 {
	 snake();
	 maze();
	 
	 logic();
	 input();
	 
	 
	 
	 }
	return 0;
}
	
	
	
	void LOADING() 
	{ //to loading animation
	
	
	
	Beep(1000,1000);// Beep(pitch, length in milli-seconds)
	Beep(1521, 400);
	Beep(2521, 500);
	Beep(3521, 600);
	Beep(4521, 700);
	Beep(3521, 600);
	Beep(2521, 500);
	Beep(1521, 400);
	
	
	cout<<"\a";
	gotoXY(170, 52);
	cout<<"powered by : R_D_D_D_DEVELOPERS"<<endl;
	
	
	
	gotoXY(20, 20);
	system("color f0");
	cout << "\n\n\n\t\t\t\tPlease wait while loading.......\n\n";
	char a = 177, b = 219;
	cout << "\t\t\t\t";
	for (int i = 0; i <= 50; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 50; i++)
	{
		cout << b;
		for (int j = 0; j <= 1e8; j++);
	}
	
	
	system("CLS");
}




void startScreen() 
	{



	Sleep(50); cout << "----------------------------------------------------------------------------------------------------------------\n";
	cout << endl;
    Sleep(50); cout << "_______  __   __  _______  _______  _______  _______  ______              _______  _______  __   __  _______     \n";
    Sleep(50); cout << "|       ||  | |  ||       ||       ||       ||       ||    _ |            |       ||   _   ||  |_|  ||       |   \n";
    Sleep(50); cout << "|  _____||  |_|  ||   _   ||   _   ||_     _||    ___||   | ||            |    ___||  |_|  ||       ||    ___|   \n";
    Sleep(50); cout << "| |_____ |       ||  | |  ||  | |  |  |   |  |   |___ |   |_||_           |   | __ |       ||       ||   |___    \n";
    Sleep(50); cout << "|_____  ||       ||  |_|  ||  |_|  |  |   |  |    ___||    __  |          |   ||  ||       ||       ||    ___|   \n";
    Sleep(50); cout << " _____| ||   _   ||       ||       |  |   |  |   |___ |   |  | |          |   |_| ||   _   || ||_|| ||   |___    \n";
    Sleep(50); cout << "|_______||__| |__||_______||_______|  |___|  |_______||___|  |_|          |_______||__| |__||_|   |_||_______|   \n";
	cout<<endl<<endl;
	Sleep(50); cout << "----------------------------------------------------------------------------------------------------------------\n";


	
	
  
    
    gotoXY(150,35);cout<<"CENTIPEDE ARCADE GAME\n";
    gotoXY(150,36);cout<<"Developed by USJ students of FOE \n";
    gotoXY(150,37);cout<<"_____________________________________________\n";
    
    gotoXY(150,38);cout<<"supervision of Dr.Ranima Dinalankara \n";
    gotoXY(150,39);cout<<"M.H.I.D.PREMARATHNE -18_ENG_081\n";
    gotoXY(150,40);cout<<"G.G.D.H.WERAPITYA   -18_ENG_116\n";
    gotoXY(150,41);cout<<"G.G.R.N.RANASINGHE  -18_ENG_091\n";
	gotoXY(150,42);cout<<"DHANUKA DUNUMADALAWA-18_ENG_015\n";


	  
	  Sleep(2000);
	  system("pause");
      system("cls");
      
	}
	
	
	void instructions()
	{
		
		
		gotoXY(80,22);cout<<"INSTRUCTIONS "<<endl;
		gotoXY(80,23);	cout<<"_________________"<<endl;
		
		gotoXY(80,24);cout<<"TO MOVE SHOOTER LEFT SIDE     \t     ---------->\t\t a"<<endl;
		gotoXY(80,25);cout<<"TO MOVE SHOOTER RIGHT SIDE	     ---------->     \t\t d"<<endl;
		gotoXY(80,26);cout<<"TO SHOOT                      \t     ---------->\t\t s"<<endl;		
		gotoXY(80,27);cout<<"TO PAUSE THE GAME             \t     ---------->\t\t p"<<endl;	
		gotoXY(80,28);cout<<"TO EXIT  THE GAME             \t     ---------->\t\t x"<<endl;	
	
	
		
	    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		system("pause");
		system("CLS");
	}


                                                                   

	
	//to print the name of the game as kajuwaththa eksath rikcet game in a smart animatedway. here we have used sleep dunctions.
	
	
	
	void gameName() 
	{ 
	

system("color F0"); 
string array1 = "\t\t  _    _  ___________  __        _  ___________            ___________  ___________  ___________  _         _  ___________  ___________  ___________  ___________ ";
string array2 = "\t\t ���  ��������������������      ����������������          ������������������������������������������       �������������������������������������������������������";
string array3 = "\t\t ��� ���  ����������� �����     ���������������           ������������  ����������� ������������ ���       ��� ����������� ������������ ������������������������� ";
string array4 = "\t\t ������       ���     ������    ������                    ���               ���     ���          ���       ���     ���     ���          ���       ������          ";
string array5 = "\t\t �����        ���     ��� ���   ������ ________           ���_________      ���     ��� ________ ���_______���     ���     ���_________ ���_______������_________ ";
string array6 = "\t\t ����         ���     ���  ���  ����������������          �������������     ���     ��������������������������     ���     ���������������������������������������";
string array7 = "\t\t �����        ���     ���   ��� ������ ���������          ������������      ���     ��� ����������������������     ���     ������������ ������������  ������������";
string array8 = "\t\t ������       ���     ���    ���������       ���          ���               ���     ���       ������       ���     ���     ���          ���     ���            ���";
string array9 = "\t\t ��� ���  ____���____ ���     ��������_______���          ���           ____���____ ���_______������       ���     ���     ���_________ ���      ���  _________���";
string array10 = "\t\t ���  �������������������      �����������������          ���          �����������������������������       ���     ���     ����������������       ����������������";
string array11= "\t\t  �    �  �����������  �        ��  �����������            �            �����������  �����������  �         �       �       �����������  �         �  ����������� ";
cout<<endl;
cout<<endl;                                                                                                                                                               
cout<<endl;
system("color F0");




string array12 = "\t\t _______  _______  __    _  _______  ___   _______  _______  ______   _______  ";     
string array13 = "\t\t|       ||       ||  |  | ||       ||   | |       ||       ||      | |       | ";     
string array14 = "\t\t|       ||    ___||   |_| ||_     _||   | |    _  ||    ___||  _    ||    ___| ";      
string array15 = "\t\t|       ||   |___ |       |  |   |  |   | |   |_| ||   |___ | | |   ||   |___  ";      
string array16 = "\t\t|      _||    ___||  _    |  |   |  |   | |    ___||    ___|| |_|   ||    ___| ";      
string array17 = "\t\t|     |_ |   |___ | | |   |  |   |  |   | |   |    |   |___ |       ||   |___  ";      
string array18 = "\t\t|_______||_______||_|  |__|  |___|  |___| |___|    |_______||______| |_______| ";     

cout<<endl;
cout<<endl;                                                                                                                                                               
cout<<endl;


	for (int n1 = 0; array1[n1] != '\0'; n1++) 
	{
		if (array1[n1] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array1[n1];
	}
	cout << endl;

	for (int n1 = 0; array2[n1] != '\0'; n1++) 
	{
		if (array2[n1] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array2[n1];
	}
	cout << endl;
	for (int n3 = 0; array3[n3] != '\0'; n3++) 
	{
		if (array3[n3] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array3[n3];
	}
	cout << endl;
	for (int n4 = 0; array4[n4] != '\0'; n4++) {
		if (array4[n4] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array4[n4];
	}
	cout << endl;
	for (int n5 = 0; array5[n5] != '\0'; n5++) 
	{
		if (array5[n5] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array5[n5];
	}
	cout << endl;
	for (int n6 = 0; array6[n6] != '\0'; n6++) 
	{
		if (array6[n6] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array6[n6];
	}
	cout << endl;
	for (int n7 = 0; array7[n7] != '\0'; n7++)
	 {
		if (array7[n7] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array7[n7];
	}
	cout << endl;
	for (int n8 = 0; array8[n8] != '\0'; n8++) 
	{
		if (array8[n8] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array8[n8];
	}
	cout << endl;
	for (int n9 = 0; array9[n9] != '\0'; n9++) 
	{
		if (array9[n9] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array9[n9];
	}
	cout << endl;
	for (int n10 = 0; array10[n10] != '\0'; n10++)
	{
		if (array10[n10] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array10[n10];
	}
	cout << endl;
	for (int n11 = 0; array11[n11] != '\0'; n11++) 
	{
		if (array11[n11] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array11[n11];
	}
	cout << endl;
	
	cout << "\n\n\n\n\n\n\n\n";
		
	for (int n12 = 0; array12[n12] != '\0'; n12++) 
	{
		if (array12[n12] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array12[n12];
	}
	
	for (int n13 = 0; array13[n13] != '\0'; n13++) 
	{
		if (array13[n13] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array13[n13];
	}
	cout << endl;
	for (int n14 = 0; array14[n14] != '\0'; n14++) 
	{
		if (array14[n14] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array14[n14];
	}
	cout << endl;
	for (int n15 = 0; array15[n15] != '\0'; n15++) 
	{
		if (array15[n15] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array15[n15];
	}
	cout << endl;
	for (int n16 = 0; array16[n16] != '\0'; n16++) 
	{
		if (array16[n16] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array16[n16];
	}
	cout << endl;
	for (int n17 = 0; array17[n17] != '\0'; n17++) 
	{
		if (array17[n17] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array17[n17];
	}
	cout << endl;
	for (int n18 = 0; array18[n18] != '\0'; n18++) {
		if (array18[n18] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << array18[n18];
	}

	
	cout << "\n\n\n\n\n\n\n\n\n";
	
	



	Sleep(2000);
	system("CLS");
	
	
	
}	

	



void setup()
{
	dir=STOP;
	bul=RTOP;
	gameover=false;
	p=width/2;
	q=height-1;
	bx=width/2;
	by=height-3;	
	

}





void maze()
{
	system("cls");

	cout<<"####################################################################################################";

	for(int j=0;j<height;j++)
		{
			cout<<"#"<<endl;
		}
		
		
		
	for (int t=0;t<20;t++)
	{
	
	if(snakepartX-t==bx&&snakepartY==by||snakepartX-t==bx1&&snakepartY==by1||snakepartX-t==bx2&&snakepartY==by2||snakepartX-t==bx3&&snakepartY==by3||snakepartX-t==bx4&&snakepartY==by4)
	{
		mpa[t]=0;
		total=total+10;
	}

	
	{
	if(mpa[t]==0)
	{
		gotoXY(snakepartX-t,snakepartY);
		cout<<" ";
		
		
	}
	else if(mpa[t]==1)
	{
		gotoXY(snakepartX-t,snakepartY);
		cout<<"O";
	}
	}
	if(total==200)
	{
		congrats();
		system("pause");
		gameover=true;
	}
	}
	

	
	gotoXY(0,45);
	cout<<"your score is "<<total;
	
	
	gotoXY(0,height);
	
	cout<<"####################################################################################################";
	gotoXY(5,5);
	cout<<"*";
	gotoXY(10,10);
	cout<<"*";
	gotoXY(15,7);
	cout<<"*";
	gotoXY(20,12);
	cout<<"*";
	gotoXY(18,4);
	cout<<"*";
	gotoXY(60,35);
	cout<<"*";
	gotoXY(75,28);
	cout<<"*";
	gotoXY(85,23);
	cout<<"*";
	gotoXY(65,27);
	cout<<"*";
	gotoXY(90,15);
	cout<<"*";
	gotoXY(50,15);
	cout<<"*";
	gotoXY(45,20);
	cout<<"*";
	gotoXY(58,20);
	cout<<"*";
	gotoXY(48,24);
	cout<<"*";
	gotoXY(49,10);
	cout<<"*";	
	gotoXY(80,10);
	cout<<"*";	
	gotoXY(30,10);
	cout<<"*";
	gotoXY(35,5);
	cout<<"*";
	gotoXY(85,5);
	cout<<"*";
	

	gotoXY(bx,by);
	cout<<"|"<<endl;
	gotoXY(bx1,by1);
	cout<<"|"<<endl;
	gotoXY(bx2,by2);
	cout<<"|"<<endl;
	gotoXY(bx3,by3);
	cout<<"|"<<endl;
	gotoXY(bx4,by4);
	cout<<"|"<<endl;
	gotoXY(p,q-2);
	cout<<"o"<<endl;
	
	gotoXY(p-1,q-1);cout<<"ooo"<<endl;
	gotoXY(p-1,q);cout<<"ooo";	
	
	for(int j=0;j<=height;j++)
		{
			gotoXY(100,j);
			cout<<"#"<<endl;
		}
		
		
		
}



	
void input()
{
	if(_kbhit())
		{
		switch(_getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			default:
				break;
						
			case 'x':
			gameover=true;
			cout<<"you exit the game!!!";
			break;
			case 'p':
			system("cls");
			instructions();
			system("pause");
			break;			
						
			case 's':
			bul=SHOOT ;
			bul2=SHOT;
			bul3=SHT;
			bul4=SH;
			bul5=S5;
			break;
				break;						
		}
	}else{
			dir=STOP;
}
		





	
}
void logic(){
	switch(dir)
	{
		case LEFT:
			p--;break;
		case RIGHT:
			p++;break;
	default :
			break;		
		
	}

	switch(bul){
		case SHOOT:
			by--;
			
			
	}
	switch(bul2){
		case SHOT:
			by1--;
			break;
	}
switch(bul3){
		case SHT:
			by2--;
			break;
	}	
	switch(bul4){
		case SH:
			by3--;
			break;
	}switch(bul5){
		case S5:
			by4--;
			break;
	}
	
	
	
	 if (p>=width-1)
	{
		p=width-2;
		}else if(p<=1){
			p=2;
			
		}else{
			
		}
			if(by4==-5|| (bx4==5 && by4==5) || (bx4==10 && by4==10) || (bx4==15 && by4==7) || (bx4==20 && by4==12) || (bx4==18 && by4==4)|| (bx4==60 && by4==35)||(bx4==75 && by4==28) || (bx4==85 && by4==23) || (bx4==65&&by4==27) || (bx4==90&&by4==15) || (bx4==50&&by4==15) || (bx4==45&&by4==20) || (bx4==58&&by4==20) || (bx4==48 && by4==24) || (bx4==49 && by4==10) ||(bx4==80&&by4==10)||(bx4==30&&by4==10)||(bx4==35&&by4==5)||(bx4==85&&by4==5)  )
		{
			bul5=STOP5;
			by4=height-3;
					}
		
		
		if(by4==height-3)
		{
			bx4=p;
		}
		if(by==-25|| (bx==5 && by==5) || (bx==10 && by==10) || (bx==15 && by==7) || (bx==20 && by==12) || (bx==18 && by==4)|| (bx==60 && by==35)||(bx==75 && by==28) || (bx==85 && by==23) || (bx==65&&by==27) || (bx==90&&by==15) || (bx==50&&by==15) || (bx==45&&by==20) || (bx==58&&by==20) || (bx==48 && by==24) || (bx==49 && by==10) ||(bx==80&&by==10)||(bx==30&&by==10)||(bx==35&&by==5)||(bx==85&&by==5) )
		{
			bul=RTOP;
			by=height-3;
			
					}
		
		
		if(by==height-3 )
		{
			bx=p;
		}if(by1==-10|| (bx1==5 && by1==5) || (bx1==10 && by1==10) || (bx1==15 && by1==7) || (bx1==20 && by1==12) || (bx1==18 && by1==4)|| (bx1==60 && by1==35)||(bx1==75 && by1==28) || (bx1==85 && by1==23) || (bx1==65&&by1==27) || (bx1==90&&by1==15) || (bx1==50&&by1==15) || (bx1==45&&by1==20) || (bx1==58&&by1==20) || (bx1==48 && by1==24) || (bx1==49 && by1==10) ||(bx1==80&&by1==10)||(bx1==30&&by1==10)||(bx1==35&&by1==5)||(bx1==85&&by1==5) ){
			bul2=ATOP;
		by1=height-3;
		}if(by1==height-3){
			bx1=p;
		}
		
		
		
		if(by2==-15|| (bx2==5 && by2==5) || (bx2==10 && by2==10) || (bx2==15 && by2==7) || (bx2==20 && by2==12) || (bx2==18 && by2==4)|| (bx2==60 && by2==35)||(bx2==75 && by2==28) || (bx2==85 && by2==23) || (bx2==65&&by2==27) || (bx2==90&&by2==15) || (bx2==50&&by2==15) || (bx2==45&&by2==20) || (bx2==58&&by2==20) || (bx2==48 && by2==24) || (bx2==49 && by2==10) ||(bx2==80&&by2==10)||(bx2==30&&by2==10)||(bx2==35&&by2==5)||(bx2==85&&by2==5) ){
			bul3=PTOP;
		by2=height-3;
		}if(by2==height-3){
			bx2=p;
		}
		if(by3==-20|| (bx3==5 && by3==5) || (bx3==10 && by3==10) || (bx3==15 && by3==7) || (bx3==20 && by3==12) || (bx3==18 && by3==4)|| (bx3==60 && by3==35)||(bx3==75 && by3==28) || (bx3==85 && by3==23) || (bx3==65&&by3==27) || (bx3==90&&by3==15) || (bx3==50&&by3==15) || (bx3==45&&by3==20) || (bx3==58&&by3==20) || (bx3==48 && by3==24) || (bx3==49 && by3==10) ||(bx3==80&&by3==10)||(bx3==30&&by3==10)||(bx3==35&&by3==5)||(bx3==85&&by3==5) ){
			bul4=LTOP;
		by3=height-3;
		}if(by3==height-3){
			bx3=p;
		}
	
	

	
	
}


void snake()
{

	
	if(t<98)
	{
		
		snakepartX++;
		
		t++;
		
	}
	else if(t==98||t==197)
	{
		snakepartY++;
		t++;		
	}
	else if(t>98&&t<197)
	{
		i--;
		snakepartX--;
		t++;	
	}
	else if(t>197)
	{
		t=0;
	}
	
}


void congrats()
{
	
system("color F1");



                                                                                                                                                                                           
                                                                                                                                                                                           
string arr1 = "\t\tYYYYYYY       YYYYYYY          OOOOOOOOO          UUUUUUUU     UUUUUUUU                    WWWWWWWW                           WWWWWWWW          OOOOOOOOO          NNNNNNNN        NNNNNNNN";
string arr2 = "\t\tY:::::Y       Y:::::Y        OO:::::::::OO        U::::::U     U::::::U                    W::::::W                           W::::::W        OO:::::::::OO        N:::::::N       N::::::N";
string arr3 = "\t\tY:::::Y       Y:::::Y      OO:::::::::::::OO      U::::::U     U::::::U                    W::::::W                           W::::::W      OO:::::::::::::OO      N::::::::N      N::::::N";
string arr4 = "\t\tY::::::Y     Y::::::Y     O:::::::OOO:::::::O     UU:::::U     U:::::UU                    W::::::W                           W::::::W     O:::::::OOO:::::::O     N:::::::::N     N::::::N";
string arr5 = "\t\tYYY:::::Y   Y:::::YYY     O::::::O   O::::::O      U:::::U     U:::::U                      W:::::W           WWWWW           W:::::W      O::::::O   O::::::O     N::::::::::N    N::::::N";
string arr6 = "\t\t   Y:::::Y Y:::::Y        O:::::O     O:::::O      U:::::D     D:::::U                       W:::::W         W:::::W         W:::::W       O:::::O     O:::::O     N:::::::::::N   N::::::N";
string arr7 = "\t\t    Y:::::Y:::::Y         O:::::O     O:::::O      U:::::D     D:::::U                        W:::::W       W:::::::W       W:::::W        O:::::O     O:::::O     N:::::::N::::N  N::::::N";
string arr8 = "\t\t     Y:::::::::Y          O:::::O     O:::::O      U:::::D     D:::::U                         W:::::W     W:::::::::W     W:::::W         O:::::O     O:::::O     N::::::N N::::N N::::::N";
string arr9 = "\t\t      Y:::::::Y           O:::::O     O:::::O      U:::::D     D:::::U                          W:::::W   W:::::W:::::W   W:::::W          O:::::O     O:::::O     N::::::N  N::::N:::::::N";
string arr10= "\t\t       Y:::::Y            O:::::O     O:::::O      U:::::D     D:::::U                           W:::::W W:::::W W:::::W W:::::W           O:::::O     O:::::O     N::::::N   N:::::::::::N";
string arr11= "\t\t       Y:::::Y            O:::::O     O:::::O      U:::::D     D:::::U                            W:::::W:::::W   W:::::W:::::W            O:::::O     O:::::O     N::::::N    N::::::::::N";
string arr12= "\t\t       Y:::::Y            O::::::O   O::::::O      U::::::U   U::::::U                             W:::::::::W     W:::::::::W             O::::::O   O::::::O     N::::::N     N:::::::::N";
string arr13= "\t\t\t\t       Y:::::Y            O:::::::OOO:::::::O      U:::::::UUU:::::::U                              W:::::::W       W:::::::W              O:::::::OOO:::::::O     N::::::N      N::::::::N";
string arr14= "\t\t    YYYY:::::YYYY          OO:::::::::::::OO        UU:::::::::::::UU                                W:::::W         W:::::W                OO:::::::::::::OO      N::::::N       N:::::::N";
string arr15= "\t\t    Y:::::::::::Y            OO:::::::::OO            UU:::::::::UU                                   W:::W           W:::W                   OO:::::::::OO        N::::::N        N::::::N";
string arr16= "\t\t    YYYYYYYYYYYYY              OOOOOOOOO                UUUUUUUUU                                      WWW             WWW                      OOOOOOOOO          NNNNNNNN         NNNNNNN";
                                                                                                                                                                                           
                                                                                                                                                                                           
                                                                                                                                                                                           
                                                                                                                                                                                           
                                                                                                                                                                                           
                                                                                                                                                                                           
                                                                                                                                                                                           








for (int n1 = 0; arr1[n1] != '\0'; n1++) 
	{
		if (arr1[n1] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr1[n1];
	}
	cout << endl;

	for (int n1 = 0; arr2[n1] != '\0'; n1++) 
	{
		if (arr2[n1] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr2[n1];
	}
	cout << endl;
	for (int n3 = 0; arr3[n3] != '\0'; n3++) 
	{
		if (arr3[n3] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr3[n3];
	}
	cout << endl;
	for (int n4 = 0; arr4[n4] != '\0'; n4++) {
		if (arr4[n4] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr4[n4];
	}
	cout << endl;
	for (int n5 = 0; arr5[n5] != '\0'; n5++) 
	{
		if (arr5[n5] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr5[n5];
	}
	cout << endl;
	for (int n6 = 0; arr6[n6] != '\0'; n6++) 
	{
		if (arr6[n6] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr6[n6];
	}
	cout << endl;
	for (int n7 = 0; arr7[n7] != '\0'; n7++)
	 {
		if (arr7[n7] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr7[n7];
	}
	cout << endl;
	for (int n8 = 0; arr8[n8] != '\0'; n8++) 
	{
		if (arr8[n8] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr8[n8];
	}
	cout << endl;
	for (int n9 = 0; arr9[n9] != '\0'; n9++) 
	{
		if (arr9[n9] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr9[n9];
	}
	cout << endl;
	for (int n10 = 0; arr10[n10] != '\0'; n10++)
	{
		if (arr10[n10] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr10[n10];
	}
	cout << endl;
	for (int n11 = 0; arr11[n11] != '\0'; n11++) 
	{
		if (arr11[n11] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr11[n11];
	}
	cout << endl;
			
	for (int n12 = 0; arr12[n12] != '\0'; n12++) 
	{
		if (arr12[n12] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr12[n12];
	}
	
	for (int n13 = 0; arr13[n13] != '\0'; n13++) 
	{
		if (arr13[n13] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr13[n13];
	}
	cout << endl;
	for (int n14 = 0; arr14[n14] != '\0'; n14++) 
	{
		if (arr14[n14] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr14[n14];
	}
	cout << endl;
	for (int n15 = 0; arr15[n15] != '\0'; n15++) 
	{
		if (arr15[n15] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr15[n15];
	}
	cout << endl;
	for (int n16 = 0; arr16[n16] != '\0'; n16++) 
	{
		if (arr16[n16] == ' ')
			Sleep((300 / 100) + rand() % (500 / 100));
		else
			Sleep((250 / 100) + rand() % (250 / 100));
		cout << arr16[n16];
	}
	cout << endl;
	
	cout << "\n\n\n\n\n\n\n\n";	
	
	
	Sleep(2000);
	system("CLS");
	
	
	
}


