#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
int alan[80][23]={0};
int k, l;
int kuyrukLine[300];
int kuyrukColumn[300];



//bug olmamasi icin calistigina emin oldugum bir fonksiyonu aliyorum
void gotoxy(short x, short y)	{
	HANDLE hConsoleOutput;
	COORD Cursor_Fos = {x-1, y-1};
	
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Fos);
}
//cerceve
void kenar(int x1,int y1,int x2,int y2,int type)
{
	int i;
	for(i=x1;i<x2;i++)
		{
			alan[i][y1]=type;
			alan[i][y2]=type;
		}
	for(i=y1;i<y2;i++)
		{
			alan[x1][i]=type;
			alan[x2][i]=type;
		}
}



void screenWrite()
	{
		int x,y;
			for(x=0;x<80;x++)
			{
				for(y=0;y<23;y++)
					{
						gotoxy(x+1,y+1);
						
							if(alan[x][y]==2)
								{
									printf("%c",176);
								}
					}
			}
	}

int giveFood()
{
	srand(time(NULL));
	k=4+rand()%65;
	l=4+rand()%15;
	
}

void main()
{
	giveFood();
	kenar(0,0,79,22,2);
	screenWrite();
	int sx=40,sy=12;
	unsigned char tus;
	int dx=0;
	int dy=0;
	int kuyruk;
	int i;
	int xcontinue=1;

	
	do 
	{
		//yon tuslari ayarlama
		if(kbhit())
			{
				tus=getch();
				if(tus==224)
					{
						tus=getch();
						switch(tus)
							{
								case 72:	dy=-1;	dx=0;
									break;
								case 80:	dy=1;	dx=0;
									break;
								case 77:	dx=1;	dy=0;
									break;
								case 75:	dx=-1;	dy=0;
							}
					}
			}
			
				sx=sx+dx;
				sy=sy+dy;
				if(sx>78)
					sx=2;
				if(sx<2)
					sx=78;
				if(sy>22)
					sy=2;
				if(sy<2)
					sy=22;
		
		kuyrukLine[0]=sy;
		kuyrukColumn[0]=sx;			
		for(i=1;i<=kuyruk;i++)
		{
			if(sx==kuyrukColumn[i] && sy==kuyrukLine[i])
				{
					gotoxy(sx,sy);
					printf("_-_-_GAMEOVER_-_-_");
					kuyruk=0;
					getch();
					xcontinue=0;
					exit (0);
				}
					}
										
		gotoxy(sx,sy);
		printf("*");
		for(i=0;i<=kuyruk;i++)
		{
			gotoxy(kuyrukColumn[i],kuyrukLine[i]);printf("*");
		}
		
		if(sx==k && sy==l)
			{
				giveFood();
				kuyruk++;	
				gotoxy(2,2);
				printf("Score: %d",kuyruk);
			}
		gotoxy(k,l);printf("O");
		
		Sleep(60);
		gotoxy(sx,sy);
		printf(" ");
		for(i=0;i<=kuyruk;i++)
		{
			gotoxy(kuyrukColumn[i],kuyrukLine[i]);printf(" ");
		}
		
		for(i=kuyruk;i>0;i--)
			{
				kuyrukColumn[i]=kuyrukColumn[i-1];
				kuyrukLine[i]=kuyrukLine[i-1];
					}	
	}
	while(xcontinue=1);
}
