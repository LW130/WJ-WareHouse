#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Num 30

int next[Num];

void BulidNext(char *P, int *next) //����ģʽ����Next���ݱ� 
{
	int i, j, len;
	
	next[0] = -1; //��ʼΪ-1,����0����
	i = 0; //�󴮳�ʼλ��,һֱ����,ֻ�ñ���һ�� 
	j = -1; //j==-1ʱ,����i++������һ��ƥ��,j����ǰ����ʼλ��,ƥ��ʧ�ܻص�-1
	len = strlen(P); //��ȡģʽ���ĳ��� 
	
	while(i < len-1) //����ģʽ����nextֵ
	{
		if(j == -1 || P[i] == P[j]) //ƥ��������,p[i]==p[j],next[i+1]=j+1;
		{
			++i;
			++j;
			next[i] = j;
		}
		else  //p[i] != p[j], j = next[j]
			j = next[j]; //��ƥ�䣬�������� 
	}
}

int KMP(char *T, char* P) //KMP�ַ��Ƚ��㷨 
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
	printf("�����˵�%dλ��ʼƥ��", num);
	
	return 0;
}

