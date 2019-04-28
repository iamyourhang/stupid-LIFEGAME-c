#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define High 25
#define Width 50 //��Ϸ����ߴ�

//ȫ�ֱ���
int cells[High][Width];

void gotoxy(int x, int y)//ˢ�´���
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void show() //��ʼ�������ϸ���������ʼ��
{	
	int i,j;
	gotoxy(0,0);
	//system("cls");
	

	for(i=0;i<=High;i++)
	{
		for(j=0;j<=Width;j++)
		{
			if(cells[i][j]==1)//ϸ�����
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	//sleep(50);����,����ĸ��д
	Sleep(50);
}

void startup()//���ݳ�ʼ��
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

void UpdateWithoutInput()//���û������޹صĸ��£�������Ϸ���㷨
{
	int Newcells[High][Width];//��һ֡��ϸ�����
	int Neibournumbers;//����ͳ���ھӸ���
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
			cells[i][j]=Newcells[i][j];//��һ֡ѭ������
}

//�Ľ�1.����ˮԴ��ˮԴ������ֳ����
//�Ľ�2.��+��ʵ�������ݻ�����
//�Ľ�3.���Ӳ�ʳ���뱻��ʳ�ߣ���ǿ��̬������Ч��

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





























