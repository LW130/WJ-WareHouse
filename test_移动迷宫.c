#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
	false,
	true
}bool;

//�Թ���һ��8��10�еľ��� 
int ROWS = 8;  
int COLUMNS = 10;

void InitMaze(char Maze[ROWS][COLUMNS], int *, int *, int *, int *);
void PrintfMaze(const char Maze[ROWS][COLUMNS]);
void TraversalMaze(char Maze[ROWS][COLUMNS], int row, int column, int EntryRow, int EntryColumn, int ExitRow, int ExitColumn);
bool ValidMove(const char Maze[ROWS][COLUMNS], int , int ); 



int main()
{
	int i, j; //ѭ�� 
	int xStart, yStart; //�Թ��������
	int x, y; //�Թ��յ� 
	char Maze[ROWS][COLUMNS]; //����һ���Թ���ά����
	
	printf("*********�ƶ��Թ�*********\n");
	//�������������,ÿ���������²�ͬ������,����ͨ��rand()������õ�������Ͳ�ͬ��
	srand(time(0));
	
	
	//ͨ��һ��Ƕ��ѭ��,�Ƚ��Թ��и����ط�����Ϊ��·('#'��ʾΪǽ����ʾ�˴�����ͨ��)
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLUMNS; j++)
		{
			Maze[i][j] = '#';
		}
	}
	//��ʼ���Թ�
	InitMaze(Maze, &xStart, &yStart, &x, &y);
	
	printf("�Թ����λ������Ϊ(%d,%d);����λ������Ϊ��(%d��%d);\n", xStart+1, yStart+1, x+1, y+1);
    printf("�Թ��������£���#����ʾǽ����0����ʾͨ·����\n");
	
	PrintfMaze(Maze);
	
	//�߳��Թ�������㿪ʼ���ߣ�����������꣬�����յ����� 
	TraversalMaze(Maze, xStart, yStart, xStart, yStart, x, y);
	
	return 0;
}

//�Թ���ʼ�� 
void InitMaze(char Maze[ROWS][COLUMNS], int *xPtr, int *yPtr, int *xExit, int *yExit)
{
	int x, y;
	int i, temp; //ѭ�� 
	int Entry, Exit; //���λ�� ����λ�� 
	
	do //��������������� 
	{
		Entry = rand()%4; //0-3��ȡ��� 
		Exit = rand()%4;
	}
	while(Entry == Exit);
	
	//ȷ�����λ��,0��ߣ�1�ϱߣ�2�ұߣ�3�±�
	if(Entry == 0)
	{
		*xPtr = rand()%(ROWS-2) + 1; //ȡ���ֵ
		*yPtr = 0;
		Maze[*xPtr][*yPtr] = '0'; //��Ϊ���ڱ�� 
	}
	else if(Entry == 1)
	{
		*xPtr = 0;
		*yPtr = rand()%(COLUMNS-2) + 1;
		Maze[*xPtr][*yPtr] = '0';
	}
	else if(Entry == 2)
	{
		*xPtr = rand()%(ROWS-2) + 1;
		*yPtr = COLUMNS - 1; //
		Maze[*xPtr][*yPtr] = '0';
	}
	else
	{
		*xPtr = ROWS - 1;
		*yPtr = rand()%(COLUMNS-2) + 1;
		Maze[*xPtr][*yPtr] = '0';
	}
	
	//ȷ������λ�� 
	if(Exit == 0)
	{
		temp = rand()%(ROWS-2) + 1;
		*xExit = temp;
		*yExit = 0;
		Maze[temp][0] = '0';
	}
	else if(Exit == 1)
	{
		temp = rand()%(COLUMNS-2) + 1;
		*xExit = 0;
		*yExit = temp;
		Maze[0][temp] = '0';
	}
	else if(Exit == 2)
	{
		temp = rand()%(ROWS-2) + 1;
		*xExit = temp;
		*yExit = COLUMNS - 1;
		Maze[temp][COLUMNS-1] = '0';
	}
	else
	{
		temp = rand()%(COLUMNS-2) + 1;
		*xExit = ROWS - 1;
		*yExit = temp;
		Maze[ROWS-1][temp] = '0';
	}
	
	//���Թ��������ö����ͬ�����ͨ·
	for(i=1; i<(ROWS-2)*(COLUMNS-2); i++)
	{
		x = rand()%(ROWS-2) + 1;
		y = rand()%(COLUMNS-2) + 1;
		Maze[x][y] = '0';
	}
	
}


//ʹ�û��ݷ����Թ�
void TraversalMaze(char Maze[ROWS][COLUMNS], int row, int column, int EntryRow, int EntryColumn, int ExitRow, int ExitColumn) 
{
	//����ڽ���,���߹���·���Ϊ'X' 
	Maze[row][column] = 'X'; //���Թ���ά�����߹���λ�ñ�� 
	static bool Judge = false; //����һ���жϱ���,�ж������λ���Ƿ�ͨ· 
	static int fre = 0; //��¼ͨ�ش���
	
	if(row==ExitRow && column==ExitColumn) //����н��������յ�������� 
	{
		printf("�ɹ��߳��Թ�,·��ͼ����:\n");
		PrintfMaze(Maze);
		fre++; // 
		return ;
	}
	
	if( ValidMove(Maze, row+1, column) ) //�����еݹ���̽���� 
	{
		Judge = true; //
		//�ݹ�
		TraversalMaze(Maze, row+1, column, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	if( ValidMove(Maze, row, column+1) )
	{
		Judge = true;
		//�ݹ�
		TraversalMaze(Maze, row, column+1, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	if( ValidMove(Maze, row-1, column) )
	{
		Judge = true;
		//�ݹ�
		TraversalMaze(Maze, row-1, column, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	if( ValidMove(Maze, row, column-1) )
	{
		Judge = true;
		//�ݹ�
		TraversalMaze(Maze, row, column-1, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	
	if(Judge == false) //�ж���� 
	{
		printf("����ѱ�����,��·���ߣ�\n");
		PrintfMaze(Maze);
	} 
	else if(Judge==true && row==EntryRow && column==EntryColumn && fre==0)
	{
		printf("���������е�·�����ں����֮��û��ͨ·��\n");
		PrintfMaze(Maze);
	} 
	
}

//�ƶ��Ƿ���Ч
bool ValidMove(const char Maze[ROWS][COLUMNS], int x, int y)
{
	return(x>=0 && x<=ROWS-1 && y>=0 && y<=COLUMNS-1 && Maze[x][y]!='#' && Maze[x][y]!='X' );
} 

//��ӡ����Թ�(��ӡ��ά����)
void PrintfMaze(const char Maze[ROWS][COLUMNS])
{
	int x, y;
	
	for(x=0; x<ROWS; x++)
	{
		for(y=0; y<COLUMNS; y++)
		{
			printf("%c ", Maze[x][y]);
			
		}
		printf("\n");
	}
	printf("\n");
}

