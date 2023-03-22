#include <stdio.h>

int Queenes[8] = {0}; //记录皇后存放的列位置 
int counts = 0;

int Check(int line, int list) //检查皇后摆放位置是否合规 
{
	int i, data;
	
	for(i=0; i<line; i++)
	{
		data = Queenes[i]; //将皇后存的列位置取出做比较 
		
		if(data == list) //如果在同一列，该位置不能放
		{
			return 0;
		}	
		
		if((i-data) == (line-list)) //如果位置在当前的左斜上方
		{
			return 0;
		}
		
		if((i+data) == (line+list)) //如果位置在当前的右斜上方 
		{
			return 0;
		}		
	}
	return 1;
}

void QueenesPrintf()
{
	int i, j; //行 列 
	
	for(i=0; i<8; i++)
	{
		for(j=0; j<Queenes[i]; j++) //打印皇后的位置 
			printf("O");
		printf("#");
		
		for(j=Queenes[i]+1; j<8; j++ ) //打印皇后所在行后面的图标 
		{
			printf("O");
		}	
		
		printf("\n");
	}
	printf("================\n");
	
}

void Eight_Queen(int line)
{
	int list;
	
	for(list=0; list<8; list++)
	{
		if(Check(line, list)) //检查合规 
		{
			Queenes[line] = list; //保存皇后列位置 
			
			if(line == 7) //列举结束 
			{
				counts++; //记录成功次数
				QueenesPrintf();
				Queenes[line] = 0; //清空棋盘，用于下次列举 
				return ;
			}
			
			Eight_Queen(line + 1);
			Queenes[line] = 0; //当列举不合适时，也要清空 
		}	
	}
}

int main()
{
	Eight_Queen(0);
	printf("摆放的方式有%d种\n", counts);
	
	return 0;
}

