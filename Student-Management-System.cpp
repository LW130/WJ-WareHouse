#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "main.h"


//初始化学生链表
Link *InitStudentLink()
{
	Link *head = (Link*)malloc(sizeof(Link)); //创建一个头节点,无数据
	Link* temp = head; //创建使用临时节点进行链表操作

	int StudentNum; //
	cout << "请输入初始化的学生数量:" ;
	cin >> StudentNum;

	for (int i = 1; i <= StudentNum; i++)
	{
		Link* Node = (Link*)malloc(sizeof(Link)); //创建新节点

		//节点数据初始化
		int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
		char InName[15], InSex[5];

		cout << "请输入学生ID, 学生姓名, 学生性别, 学生年龄, 学生语文,数学,英语成绩:" << endl;
		cin >> InStudentId >> InName >> InSex >> InAge >> InC_Score >> InM_Score >> InE_Score;

		Node->stu.StudentId = InStudentId;
		strcpy(Node->stu.Name, InName);
		strcpy(Node->stu.Sex, InSex);
		Node->stu.Age = InAge;
		Node->stu.C_Score = InC_Score;
		Node->stu.M_Score = InM_Score;
		Node->stu.E_Score = InE_Score;

		//test
		//Node->stu.StudentId = 1234;
		//strcpy(Node->stu.Name, "W");
		//strcpy(Node->stu.Sex, "男");
		//Node->stu.Age = 18;
		//Node->stu.C_Score = 90;
		//Node->stu.M_Score = 90;
		//Node->stu.E_Score = 90;

		//指针域初始化
		Node->next = NULL; 
		//节点操作
		temp->next = Node;
		temp = temp->next; //移动到下一个节点
	}
	return head;
}

/*对链表进行增删改查操作*/
//增加学生
Link* IncreaseLink(Link* L, int location) //在location位置上插入学生
{
	Link* temp = L; //用temp指针对链表进行操作

	for (int i = 1; i < location; i++) //移动到需要插入节点的前一个节点
	{

		temp = temp->next; //移动到下一个节点,先进行一次移动(跳过头节点)
		
		//异常判断插入位置
		if (temp == NULL)
		{
			cout << "插入位置无效" << endl;
			return L;
		}
	}

	//创建新节点
	Link* NewNode = (Link*)malloc(sizeof(Link) );
		
	//节点数据初始化
	int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
	char InName[15], InSex[5];

	cout << "请输入学生ID, 学生姓名, 学生性别, 学生年龄, 学生语文,数学,英语成绩:" << endl;
	cin >> InStudentId >> InName >> InSex >> InAge >> InC_Score >> InM_Score >> InE_Score;

	NewNode->stu.StudentId = InStudentId;
	strcpy(NewNode->stu.Name, InName);
	strcpy(NewNode->stu.Sex, InSex);
	NewNode->stu.Age = InAge;
	NewNode->stu.C_Score = InC_Score;
	NewNode->stu.M_Score = InM_Score;
	NewNode->stu.E_Score = InE_Score;

	//进行插入操作(warning!顺序不可以反)
	NewNode->next = temp->next; //1.将后一个节点的地址赋值给新节点
	temp->next = NewNode;  //2.将新节点的地址赋值给前一个节点大的指针域
	
	return L;
}

//删除学生,依据学生ID删除
Link* DelLinkofID(Link* L, int DelStudentID)
{
	Link *temp, *pre = NULL; //temp指针用于遍历链表,pre保存前驱节点
	temp = L;

	while (temp->stu.StudentId != DelStudentID) //遍历查找
	{
		pre = temp; //将当前节点作为前驱节点
		temp = temp->next; //移动到下一个节点

		//异常判断
		if (temp->next == NULL)
		{
			cout << "所需要删除的学生不存在" << endl;
			return L;
		}
	}

	pre->next = temp->next; //删除操作,将其前驱next指向其后继
	free(temp); 

	return L;
}
//删除学生,依据链表位置删除
Link* DelLinkoflocation(Link* L, int DelLocation)
{
	Link* temp, *pre = NULL;
	temp = L;

	for (int i = 0; i < DelLocation; i++)
	{
		pre = temp;
		temp = temp->next;

		if (temp->next == NULL && temp->stu.StudentId == NULL)
		{
			cout << "所需要删除的学生不存在" << endl;
			return L;
		}
	}

	pre->next = temp->next;
	free(temp);

	return L;
}

//修改学生信息，根据学号查找修改，位置查找修改
Link* AmendLinkofID(Link* L, int AmendStudentID)
{
	Link* temp=L;

	while (temp->stu.StudentId != AmendStudentID)
	{
		temp = temp->next;

		if (temp->next == NULL)
		{
			cout << "需要修改的学生信息不存在" << endl;
			return L;
		}
	}

	int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
	char InName[15], InSex[5];

	cout << "请输入修改信息:" << endl 
		 << "学生ID, 学生姓名, 学生性别, 学生年龄, 学生语文,数学,英语成绩:" << endl;
	cin >> InStudentId >> InName >> InSex >> InAge >> InC_Score >> InM_Score >> InE_Score;

	temp->stu.StudentId = InStudentId;
	strcpy(temp->stu.Name, InName);
	strcpy(temp->stu.Sex, InSex);
	temp->stu.Age = InAge;
	temp->stu.C_Score = InC_Score;
	temp->stu.M_Score = InM_Score;
	temp->stu.E_Score = InE_Score;

	return L;
}
//位置查找修改
Link* AmendLinkoflocation(Link* L, int AmendStudentLocation)
{
	Link* temp = L;

	for(int i=0; i<AmendStudentLocation; i++)
	{
		temp = temp->next;

		if (temp->next == NULL && temp->stu.StudentId == NULL)
		{
			cout << "需要修改的学生信息不存在" << endl;
			return L;
		}
	}

	int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
	char InName[15], InSex[5];

	cout << "请输入修改信息:" << endl
		<< "学生ID, 学生姓名, 学生性别, 学生年龄, 学生语文,数学,英语成绩:" << endl;
	cin >> InStudentId >> InName >> InSex >> InAge >> InC_Score >> InM_Score >> InE_Score;

	temp->stu.StudentId = InStudentId;
	strcpy(temp->stu.Name, InName);
	strcpy(temp->stu.Sex, InSex);
	temp->stu.Age = InAge;
	temp->stu.C_Score = InC_Score;
	temp->stu.M_Score = InM_Score;
	temp->stu.E_Score = InE_Score;

	return L;
}

//查找学生信息
Link* FindLink(Link* L, int FindStudentID)
{
	Link* temp = L;

	while (temp->stu.StudentId != FindStudentID)
	{
		temp = temp->next;

		if (temp->next == NULL)
		{
			cout << "需要查找的学生不存在" << endl;
			return L;
		}
	}

	cout << " 学生学号:" << temp->stu.StudentId << endl;
	cout << " 学生姓名:" << temp->stu.Name << endl;
	cout << " 学生性别:" << temp->stu.Sex << endl;
	cout << " 学生年龄:" << temp->stu.Age << endl;
	cout << " 学生语文成绩:" << temp->stu.C_Score << endl
		 << " 学生数学成绩:" << temp->stu.M_Score << endl
		 << " 学生英语成绩:" << temp->stu.E_Score << endl;
	cout << endl;

	return L;
}

//显示(打印)链表
void DisplayLink(Link* L) 
{
	Link* temp = L->next; //头节点没有数据，跳过头节点

	while (temp->stu.StudentId != NULL) //当数据域中有数据时打印输出
	{
		cout << " 学生学号:" << temp->stu.StudentId << endl;
		cout << " 学生姓名:" << temp->stu.Name << endl;
		cout << " 学生性别:" << temp->stu.Sex << endl;
		cout << " 学生年龄:" << temp->stu.Age << endl;
		cout << " 学生语文成绩:" << temp->stu.C_Score << endl 
			 << " 学生数学成绩:" << temp->stu.M_Score << endl 
			 << " 学生英语成绩:" << temp->stu.E_Score << endl;
		cout << endl;

		if (temp->next != NULL) //如果下一个节点不为空
			temp = temp->next;  //移动到下一个节点
		else
			break; //退出循环
	}
}

void ShowMenu()
{
	cout << " ------------------------------" << endl;
	cout << "|  Student Management System   |" << endl;
	cout << " ------------------------------" << endl;
	cout << "| 1.增加学员                   |" << endl;
	cout << "| 2.删除学员                   |" << endl;
	cout << "| 3.修改学员信息               |" << endl;
	cout << "| 4.查找学院信息               |" << endl;
	cout << "| 5.将学员排序(链表是否可以排序？)|" << endl;
	cout << " ------------------------------" << endl;
}


int main()
{
	Link *L;
	int Increaselocation, InDelStudentID, InAmendStudentID, InFindStudentID;
	int choose, DelChoose, AmendChoose;

	L = InitStudentLink();

	while (1)
	{
		ShowMenu();
		cout << "请输入需要操作的选项:" ;
		cin >> choose;

		switch (choose)
		{
		case 1: 
			cout << "将学员安排在哪个位置？" << endl;
			cin >> Increaselocation;
			L = IncreaseLink(L, Increaselocation);

			cout << "插入成功,当前学生列表为:" << endl;
			DisplayLink(L);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "请选择删除方式: 1.ID  2.位置" << endl;
			cin >> DelChoose;

			if (DelChoose == 1)
			{
				cout << "请输入需要删除的学员ID:" ;
				cin >> InDelStudentID;
				L = DelLinkofID(L, InDelStudentID);

				cout << "删除成功,当前学生列表为:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			else
			{
				cout << "请输入需要删除的学员所在的位置:";
				cin >> InDelStudentID;
				L = DelLinkoflocation(L, InDelStudentID);

				cout << "删除成功,当前学生列表为:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			break;

		case 3:
			cout << "请输入修改方式: 1.ID  2.位置" << endl;
			cin >> AmendChoose;

			if (AmendChoose == 1)
			{
				cout << "请输入需要修改学员的ID:" ;
				cin >> InAmendStudentID;
				L = AmendLinkofID(L, InAmendStudentID);

				cout << "修改成功,当前学生列表为:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			else
			{
				cout << "请输入需要修改学员的位置:";
				cin >> InAmendStudentID;
				L = AmendLinkoflocation(L, InAmendStudentID);

				cout << "修改成功,当前学生列表为:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			break;

		case 4:
			cout << "请输入需要查看的学员ID" << endl;
			cin >> InFindStudentID;
			L = FindLink(L, InFindStudentID);
			//DisplayLink(L);
			system("pause");
			system("cls");
			break;

		default:
			cout << "感谢使用" <<endl ;
			system("pause");
			return 0;
			break;
		}

	}
	
	//cout << "进行删除操作" << endl;
	//cin >> InDelStudentID;
	//L = DelLinkofID(L, InDelStudentID);
	//DisplayLink(L);

	//cin >> InDelStudentID;
	//L = DelLinkoflocation(L, InDelStudentID);
	//DisplayLink(L);

	//cout << "进行修改操作" << endl;
	//cin >> InAmendStudentID;
	//L = AmendLinkofID(L, InAmendStudentID);
	//DisplayLink(L);

	//cout << "进行查找操作" << endl;
	//cin >> InFindStudentID;
	//L = FindLink(L, InFindStudentID);


	return 0;
}
