#include <stdio.h>

int scheme, height; //上楼方案 步数 

void DFS(int steps) //深度优先遍历 
{
	if(height == steps) //当行进步数 == 高度时就说明到顶了 
	{
		scheme++;
		return;		
	}
	else if(steps > height) //当行进步数 > 高度时，也是到顶了 
	{
		return; 
	}
	
	DFS(steps + 1); //每次走1步或者3步 
	DFS(steps + 3);
	
}


int main()
{
	printf("请输入台阶高度:\n");
	scanf("%d", &height);
	
	scheme = 0;
	DFS(0);
	printf("一共有%d种爬楼方式\n", scheme);
	
	return 0;
}

