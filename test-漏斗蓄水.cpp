#include<iostream>

using namespace std;

#define  CAPACITY  10

int main()
{
	int Input, Output;
	int Ccapacity=0, i=0;
	
	cout << "请输入漏斗的进水量:" << endl;
	cin >> Input;
	cout << "请输入漏斗的出水量:" << endl;
	cin >> Output;
	
	while(Ccapacity < CAPACITY)
	{
		i++; // 
		
		Ccapacity = Ccapacity + Input;
		if(Ccapacity == CAPACITY)
		{
			cout << "第" << i << "次时刚满，可之后又漏了" << endl; 
			//break;
		}
		Ccapacity = Ccapacity - Output;
	}
	
	cout << "需要注水 " << i << " 次注满或者超过水池量" << endl;
	
	return 0;
}
