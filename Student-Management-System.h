#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#include <string>


typedef struct Student
{
	int  StudentId; //学生ID
	char Name[15]; //学生姓名
	char Sex[5];  //学生性别
	int  Age;  //学生年龄
	int  C_Score, M_Score, E_Score; //学生成绩
};

typedef struct StudentLink
{
	struct Student stu; //链表数据域
	struct StudentLink *next; //链表指针域
}Link;



#endif // 
