#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define High 25
#define Width 50 //游戏画面尺寸

//全局变量
int cells[High][Width];

void gotoxy(int x, int y)//刷新代替
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void show() //初始化活（死）细胞，界面初始化
{	
	int i,j;
	gotoxy(0,0);
	//system("cls");
	

	for(i=0;i<=High;i++)
	{
		for(j=0;j<=Width;j++)
		{
			if(cells[i][j]==1)//细胞存活
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	//sleep(50);错误,首字母大写
	Sleep(50);
}

void startup()//数据初始化
{
	int i,j;
	for(i=0;i<High;i++)
		for(j=0;j<Width;j++)
		{
			cells[i][j]=rand()%2;
		}
}

void UpdateWithInput()
{}

void UpdateWithoutInput()//与用户输入无关的更新，生命游戏的算法
{
	int Newcells[High][Width];//下一帧的细胞情况
	int Neibournumbers;//用于统计邻居个数
	int i,j;
	for(i=1;i<=High-1;i++)
	{
		for(j=1;j<=Width-1;j++)
		{
			Neibournumbers = cells[i-1][j-1] + cells[i-1][j] + cells[i-1][j+1] + cells[i][j-1] + cells[i][j+1] + cells[i+1][j-1] + cells[i+1][j] + cells[i+1][j+1];
			
		if(Neibournumbers == 3)
			Newcells[i][j]=1;
		else if(Neibournumbers == 2)
			Newcells[i][j]=cells[i][j];
		else
			Newcells[i][j]=0;
		}
	}
	for(i=1;i<=High-1;i++)
		for(j=1;j<=Width;j++)
			cells[i][j]=Newcells[i][j];//下一帧循环进行
}

//改进1.增加水源，水源附近繁殖更快
//改进2.按+键实现生命演化加速
//改进3.增加捕食者与被捕食者，加强生态环境的效果

int main()
{
	startup();
	while(1)
	{
		show();
		UpdateWithoutInput();
		UpdateWithInput();
	}
	return 0;
}





























