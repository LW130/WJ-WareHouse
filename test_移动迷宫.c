#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
	false,
	true
}bool;

//迷宫是一个8行10列的矩形 
int ROWS = 8;  
int COLUMNS = 10;

void InitMaze(char Maze[ROWS][COLUMNS], int *, int *, int *, int *);
void PrintfMaze(const char Maze[ROWS][COLUMNS]);
void TraversalMaze(char Maze[ROWS][COLUMNS], int row, int column, int EntryRow, int EntryColumn, int ExitRow, int ExitColumn);
bool ValidMove(const char Maze[ROWS][COLUMNS], int , int ); 



int main()
{
	int i, j; //循环 
	int xStart, yStart; //迷宫坐标入口
	int x, y; //迷宫终点 
	char Maze[ROWS][COLUMNS]; //定义一个迷宫二维数组
	
	printf("*********移动迷宫*********\n");
	//种下随机种子数,每次运行种下不同的种子,后序通过rand()函数获得的随机数就不同。
	srand(time(0));
	
	
	//通过一个嵌套循环,先将迷宫中各个地方设置为死路('#'表示为墙，表示此处不可通过)
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLUMNS; j++)
		{
			Maze[i][j] = '#';
		}
	}
	//初始化迷宫
	InitMaze(Maze, &xStart, &yStart, &x, &y);
	
	printf("迷宫入口位置坐标为(%d,%d);出口位置坐标为：(%d，%d);\n", xStart+1, yStart+1, x+1, y+1);
    printf("迷宫设置如下（‘#’表示墙，‘0’表示通路）：\n");
	
	PrintfMaze(Maze);
	
	//走出迷宫，从起点开始行走，传入起点坐标，传入终点坐标 
	TraversalMaze(Maze, xStart, yStart, xStart, yStart, x, y);
	
	return 0;
}

//迷宫初始化 
void InitMaze(char Maze[ROWS][COLUMNS], int *xPtr, int *yPtr, int *xExit, int *yExit)
{
	int x, y;
	int i, temp; //循环 
	int Entry, Exit; //入口位置 出口位置 
	
	do //随机入口与随机出口 
	{
		Entry = rand()%4; //0-3中取随机 
		Exit = rand()%4;
	}
	while(Entry == Exit);
	
	//确定入口位置,0左边，1上边，2右边，3下边
	if(Entry == 0)
	{
		*xPtr = rand()%(ROWS-2) + 1; //取随机值
		*yPtr = 0;
		Maze[*xPtr][*yPtr] = '0'; //作为开口标记 
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
	
	//确定出口位置 
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
	
	//在迷宫中央设置多出不同的随机通路
	for(i=1; i<(ROWS-2)*(COLUMNS-2); i++)
	{
		x = rand()%(ROWS-2) + 1;
		y = rand()%(COLUMNS-2) + 1;
		Maze[x][y] = '0';
	}
	
}


//使用回溯法走迷宫
void TraversalMaze(char Maze[ROWS][COLUMNS], int row, int column, int EntryRow, int EntryColumn, int ExitRow, int ExitColumn) 
{
	//由入口进入,将走过的路标记为'X' 
	Maze[row][column] = 'X'; //将迷宫二维数组走过的位置标记 
	static bool Judge = false; //设置一个判断变量,判断在入口位置是否通路 
	static int fre = 0; //记录通关次数
	
	if(row==ExitRow && column==ExitColumn) //如果行进坐标与终点坐标相等 
	{
		printf("成功走出迷宫,路线图如下:\n");
		PrintfMaze(Maze);
		fre++; // 
		return ;
	}
	
	if( ValidMove(Maze, row+1, column) ) //回溯中递归试探行走 
	{
		Judge = true; //
		//递归
		TraversalMaze(Maze, row+1, column, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	if( ValidMove(Maze, row, column+1) )
	{
		Judge = true;
		//递归
		TraversalMaze(Maze, row, column+1, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	if( ValidMove(Maze, row-1, column) )
	{
		Judge = true;
		//递归
		TraversalMaze(Maze, row-1, column, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	if( ValidMove(Maze, row, column-1) )
	{
		Judge = true;
		//递归
		TraversalMaze(Maze, row, column-1, EntryRow, EntryColumn, ExitRow, ExitColumn);
	}
	
	
	if(Judge == false) //判断入口 
	{
		printf("入口已被封死,无路可走！\n");
		PrintfMaze(Maze);
	} 
	else if(Judge==true && row==EntryRow && column==EntryColumn && fre==0)
	{
		printf("尝试了所有道路，出口和入口之间没有通路！\n");
		PrintfMaze(Maze);
	} 
	
}

//移动是否有效
bool ValidMove(const char Maze[ROWS][COLUMNS], int x, int y)
{
	return(x>=0 && x<=ROWS-1 && y>=0 && y<=COLUMNS-1 && Maze[x][y]!='#' && Maze[x][y]!='X' );
} 

//打印输出迷宫(打印二维数组)
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

