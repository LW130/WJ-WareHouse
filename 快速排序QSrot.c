#include <stdio.h>

#define  NUM  8

void QSrot(int Arr[], int low, int high)
{
	int l, h, temp;
	l = low;
	h = high;
	
	if(low < high)
	{
		temp = Arr[low]; //����һ������,��㼴�ɣ������õ��������һ���� 
		
		while(l != h) //�������ұ�㲻�غ�ʱ 
		{
			while(l<h && temp<=Arr[h]) //�ұ�㿪ʼ�ƶ��ж� 
			{
				--h;
			}
			if(l<h) //���ұ� < ����ʱ��ͣ���ƶ�
			{
				Arr[l] = Arr[h]; //��Сֵ�ŵ����
				++l; 
			}
			//Ȼ�������ƶ��жϱȽ� 
			while(l<h && Arr[l]<temp)
			{
				++l;
			}
			if(l<h)
			{
				Arr[h] = Arr[l]; //����ֵ�����ұ� 
				--h;
			}
		}
		
		Arr[l] = temp; //�����ᱣ�浽�ƶ�������� 
		//ʹ�õݹ����������Ұ����� 
		QSrot(Arr, low, l-1); //���
		QSrot(Arr, l+1, high); //�Ұ� 
	}
}


int main()
{
	int Arr[NUM] = {70,50,30,20,10,70,40,60};
	int Arri; 
	
	QSrot(Arr, 0, NUM-1); //���� 
		
	for(Arri=0; Arri<NUM; Arri++)
	{
		printf("%d ", Arr[Arri]);
	}
	
	return 0;
}
