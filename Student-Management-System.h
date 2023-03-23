#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#include <string>


typedef struct Student
{
	int  StudentId; //ѧ��ID
	char Name[15]; //ѧ������
	char Sex[5];  //ѧ���Ա�
	int  Age;  //ѧ������
	int  C_Score, M_Score, E_Score; //ѧ���ɼ�
};

typedef struct StudentLink
{
	struct Student stu; //����������
	struct StudentLink *next; //����ָ����
}Link;



#endif // 
