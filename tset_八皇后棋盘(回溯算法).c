#include <stdio.h>

int Queenes[8] = {0}; //��¼�ʺ��ŵ���λ�� 
int counts = 0;

int Check(int line, int list) //���ʺ�ڷ�λ���Ƿ�Ϲ� 
{
	int i, data;
	
	for(i=0; i<line; i++)
	{
		data = Queenes[i]; //���ʺ�����λ��ȡ�����Ƚ� 
		
		if(data == list) //�����ͬһ�У���λ�ò��ܷ�
		{
			return 0;
		}	
		
		if((i-data) == (line-list)) //���λ���ڵ�ǰ����б�Ϸ�
		{
			return 0;
		}
		
		if((i+data) == (line+list)) //���λ���ڵ�ǰ����б�Ϸ� 
		{
			return 0;
		}		
	}
	return 1;
}

void QueenesPrintf()
{
	int i, j; //�� �� 
	
	for(i=0; i<8; i++)
	{
		for(j=0; j<Queenes[i]; j++) //��ӡ�ʺ��λ�� 
			printf("O");
		printf("#");
		
		for(j=Queenes[i]+1; j<8; j++ ) //��ӡ�ʺ������к����ͼ�� 
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
		if(Check(line, list)) //���Ϲ� 
		{
			Queenes[line] = list; //����ʺ���λ�� 
			
			if(line == 7) //�оٽ��� 
			{
				counts++; //��¼�ɹ�����
				QueenesPrintf();
				Queenes[line] = 0; //������̣������´��о� 
				return ;
			}
			
			Eight_Queen(line + 1);
			Queenes[line] = 0; //���оٲ�����ʱ��ҲҪ��� 
		}	
	}
}

int main()
{
	Eight_Queen(0);
	printf("�ڷŵķ�ʽ��%d��\n", counts);
	
	return 0;
}

