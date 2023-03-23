#include <stdio.h>

int scheme, height; //��¥���� ���� 

void DFS(int steps) //������ȱ��� 
{
	if(height == steps) //���н����� == �߶�ʱ��˵�������� 
	{
		scheme++;
		return;		
	}
	else if(steps > height) //���н����� > �߶�ʱ��Ҳ�ǵ����� 
	{
		return; 
	}
	
	DFS(steps + 1); //ÿ����1������3�� 
	DFS(steps + 3);
	
}


int main()
{
	printf("������̨�׸߶�:\n");
	scanf("%d", &height);
	
	scheme = 0;
	DFS(0);
	printf("һ����%d����¥��ʽ\n", scheme);
	
	return 0;
}

