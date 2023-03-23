#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Num 30

int next[Num];

void BulidNext(char *P, int *next) //构建模式串的Next回溯表 
{
	int i, j, len;
	
	next[0] = -1; //初始为-1,或者0都行
	i = 0; //后串初始位置,一直增加,只用遍历一遍 
	j = -1; //j==-1时,代表i++进入下一轮匹配,j代表前串起始位置,匹配失败回到-1
	len = strlen(P); //获取模式串的长度 
	
	while(i < len-1) //遍历模式串求next值
	{
		if(j == -1 || P[i] == P[j]) //匹配的情况下,p[i]==p[j],next[i+1]=j+1;
		{
			++i;
			++j;
			next[i] = j;
		}
		else  //p[i] != p[j], j = next[j]
			j = next[j]; //不匹配，发生回溯 
	}
}

int KMP(char *T, char* P) //KMP字符比较算法 
{
	int i, j;
	int Tlen = strlen(T);
	int Plen = strlen(P);
	
	while(i<Tlen && j<Plen)
	{
		if(j == -1 || T[i] == P[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	return i-j;
}


int main()
{
	int num;
	char org[] = "ABABABABABD";
	char str[] = "ABABD";
	
	BulidNext(str, next);
	num = KMP(org, str);
	printf("经过了第%d位后开始匹配", num);
	
	return 0;
}

