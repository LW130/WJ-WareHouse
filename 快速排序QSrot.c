#include <stdio.h>

#define  NUM  8

void QSrot(int Arr[], int low, int high)
{
	int l, h, temp;
	l = low;
	h = high;
	
	if(low < high)
	{
		temp = Arr[low]; //设置一个枢轴,随便即可，这里用的是数组第一个数 
		
		while(l != h) //左标点与右标点不重合时 
		{
			while(l<h && temp<=Arr[h]) //右标点开始移动判断 
			{
				--h;
			}
			if(l<h) //当右边 < 枢轴时，停下移动
			{
				Arr[l] = Arr[h]; //将小值放到左边
				++l; 
			}
			//然后换左标点移动判断比较 
			while(l<h && Arr[l]<temp)
			{
				++l;
			}
			if(l<h)
			{
				Arr[h] = Arr[l]; //将大值放在右边 
				--h;
			}
		}
		
		Arr[l] = temp; //将枢轴保存到移动后的数组 
		//使用递归继续左半与右半排序 
		QSrot(Arr, low, l-1); //左半
		QSrot(Arr, l+1, high); //右半 
	}
}


int main()
{
	int Arr[NUM] = {70,50,30,20,10,70,40,60};
	int Arri; 
	
	QSrot(Arr, 0, NUM-1); //快排 
		
	for(Arri=0; Arri<NUM; Arri++)
	{
		printf("%d ", Arr[Arri]);
	}
	
	return 0;
}
