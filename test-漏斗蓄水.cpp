#include<iostream>

using namespace std;

#define  CAPACITY  10

int main()
{
	int Input, Output;
	int Ccapacity=0, i=0;
	
	cout << "������©���Ľ�ˮ��:" << endl;
	cin >> Input;
	cout << "������©���ĳ�ˮ��:" << endl;
	cin >> Output;
	
	while(Ccapacity < CAPACITY)
	{
		i++; // 
		
		Ccapacity = Ccapacity + Input;
		if(Ccapacity == CAPACITY)
		{
			cout << "��" << i << "��ʱ��������֮����©��" << endl; 
			//break;
		}
		Ccapacity = Ccapacity - Output;
	}
	
	cout << "��Ҫעˮ " << i << " ��ע�����߳���ˮ����" << endl;
	
	return 0;
}
