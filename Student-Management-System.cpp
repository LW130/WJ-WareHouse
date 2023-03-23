#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "main.h"


//��ʼ��ѧ������
Link *InitStudentLink()
{
	Link *head = (Link*)malloc(sizeof(Link)); //����һ��ͷ�ڵ�,������
	Link* temp = head; //����ʹ����ʱ�ڵ�����������

	int StudentNum; //
	cout << "�������ʼ����ѧ������:" ;
	cin >> StudentNum;

	for (int i = 1; i <= StudentNum; i++)
	{
		Link* Node = (Link*)malloc(sizeof(Link)); //�����½ڵ�

		//�ڵ����ݳ�ʼ��
		int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
		char InName[15], InSex[5];

		cout << "������ѧ��ID, ѧ������, ѧ���Ա�, ѧ������, ѧ������,��ѧ,Ӣ��ɼ�:" << endl;
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
		//strcpy(Node->stu.Sex, "��");
		//Node->stu.Age = 18;
		//Node->stu.C_Score = 90;
		//Node->stu.M_Score = 90;
		//Node->stu.E_Score = 90;

		//ָ�����ʼ��
		Node->next = NULL; 
		//�ڵ����
		temp->next = Node;
		temp = temp->next; //�ƶ�����һ���ڵ�
	}
	return head;
}

/*�����������ɾ�Ĳ����*/
//����ѧ��
Link* IncreaseLink(Link* L, int location) //��locationλ���ϲ���ѧ��
{
	Link* temp = L; //��tempָ���������в���

	for (int i = 1; i < location; i++) //�ƶ�����Ҫ����ڵ��ǰһ���ڵ�
	{

		temp = temp->next; //�ƶ�����һ���ڵ�,�Ƚ���һ���ƶ�(����ͷ�ڵ�)
		
		//�쳣�жϲ���λ��
		if (temp == NULL)
		{
			cout << "����λ����Ч" << endl;
			return L;
		}
	}

	//�����½ڵ�
	Link* NewNode = (Link*)malloc(sizeof(Link) );
		
	//�ڵ����ݳ�ʼ��
	int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
	char InName[15], InSex[5];

	cout << "������ѧ��ID, ѧ������, ѧ���Ա�, ѧ������, ѧ������,��ѧ,Ӣ��ɼ�:" << endl;
	cin >> InStudentId >> InName >> InSex >> InAge >> InC_Score >> InM_Score >> InE_Score;

	NewNode->stu.StudentId = InStudentId;
	strcpy(NewNode->stu.Name, InName);
	strcpy(NewNode->stu.Sex, InSex);
	NewNode->stu.Age = InAge;
	NewNode->stu.C_Score = InC_Score;
	NewNode->stu.M_Score = InM_Score;
	NewNode->stu.E_Score = InE_Score;

	//���в������(warning!˳�򲻿��Է�)
	NewNode->next = temp->next; //1.����һ���ڵ�ĵ�ַ��ֵ���½ڵ�
	temp->next = NewNode;  //2.���½ڵ�ĵ�ַ��ֵ��ǰһ���ڵ���ָ����
	
	return L;
}

//ɾ��ѧ��,����ѧ��IDɾ��
Link* DelLinkofID(Link* L, int DelStudentID)
{
	Link *temp, *pre = NULL; //tempָ�����ڱ�������,pre����ǰ���ڵ�
	temp = L;

	while (temp->stu.StudentId != DelStudentID) //��������
	{
		pre = temp; //����ǰ�ڵ���Ϊǰ���ڵ�
		temp = temp->next; //�ƶ�����һ���ڵ�

		//�쳣�ж�
		if (temp->next == NULL)
		{
			cout << "����Ҫɾ����ѧ��������" << endl;
			return L;
		}
	}

	pre->next = temp->next; //ɾ������,����ǰ��nextָ������
	free(temp); 

	return L;
}
//ɾ��ѧ��,��������λ��ɾ��
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
			cout << "����Ҫɾ����ѧ��������" << endl;
			return L;
		}
	}

	pre->next = temp->next;
	free(temp);

	return L;
}

//�޸�ѧ����Ϣ������ѧ�Ų����޸ģ�λ�ò����޸�
Link* AmendLinkofID(Link* L, int AmendStudentID)
{
	Link* temp=L;

	while (temp->stu.StudentId != AmendStudentID)
	{
		temp = temp->next;

		if (temp->next == NULL)
		{
			cout << "��Ҫ�޸ĵ�ѧ����Ϣ������" << endl;
			return L;
		}
	}

	int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
	char InName[15], InSex[5];

	cout << "�������޸���Ϣ:" << endl 
		 << "ѧ��ID, ѧ������, ѧ���Ա�, ѧ������, ѧ������,��ѧ,Ӣ��ɼ�:" << endl;
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
//λ�ò����޸�
Link* AmendLinkoflocation(Link* L, int AmendStudentLocation)
{
	Link* temp = L;

	for(int i=0; i<AmendStudentLocation; i++)
	{
		temp = temp->next;

		if (temp->next == NULL && temp->stu.StudentId == NULL)
		{
			cout << "��Ҫ�޸ĵ�ѧ����Ϣ������" << endl;
			return L;
		}
	}

	int InStudentId, InAge, InC_Score, InM_Score, InE_Score;
	char InName[15], InSex[5];

	cout << "�������޸���Ϣ:" << endl
		<< "ѧ��ID, ѧ������, ѧ���Ա�, ѧ������, ѧ������,��ѧ,Ӣ��ɼ�:" << endl;
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

//����ѧ����Ϣ
Link* FindLink(Link* L, int FindStudentID)
{
	Link* temp = L;

	while (temp->stu.StudentId != FindStudentID)
	{
		temp = temp->next;

		if (temp->next == NULL)
		{
			cout << "��Ҫ���ҵ�ѧ��������" << endl;
			return L;
		}
	}

	cout << " ѧ��ѧ��:" << temp->stu.StudentId << endl;
	cout << " ѧ������:" << temp->stu.Name << endl;
	cout << " ѧ���Ա�:" << temp->stu.Sex << endl;
	cout << " ѧ������:" << temp->stu.Age << endl;
	cout << " ѧ�����ĳɼ�:" << temp->stu.C_Score << endl
		 << " ѧ����ѧ�ɼ�:" << temp->stu.M_Score << endl
		 << " ѧ��Ӣ��ɼ�:" << temp->stu.E_Score << endl;
	cout << endl;

	return L;
}

//��ʾ(��ӡ)����
void DisplayLink(Link* L) 
{
	Link* temp = L->next; //ͷ�ڵ�û�����ݣ�����ͷ�ڵ�

	while (temp->stu.StudentId != NULL) //����������������ʱ��ӡ���
	{
		cout << " ѧ��ѧ��:" << temp->stu.StudentId << endl;
		cout << " ѧ������:" << temp->stu.Name << endl;
		cout << " ѧ���Ա�:" << temp->stu.Sex << endl;
		cout << " ѧ������:" << temp->stu.Age << endl;
		cout << " ѧ�����ĳɼ�:" << temp->stu.C_Score << endl 
			 << " ѧ����ѧ�ɼ�:" << temp->stu.M_Score << endl 
			 << " ѧ��Ӣ��ɼ�:" << temp->stu.E_Score << endl;
		cout << endl;

		if (temp->next != NULL) //�����һ���ڵ㲻Ϊ��
			temp = temp->next;  //�ƶ�����һ���ڵ�
		else
			break; //�˳�ѭ��
	}
}

void ShowMenu()
{
	cout << " ------------------------------" << endl;
	cout << "|  Student Management System   |" << endl;
	cout << " ------------------------------" << endl;
	cout << "| 1.����ѧԱ                   |" << endl;
	cout << "| 2.ɾ��ѧԱ                   |" << endl;
	cout << "| 3.�޸�ѧԱ��Ϣ               |" << endl;
	cout << "| 4.����ѧԺ��Ϣ               |" << endl;
	cout << "| 5.��ѧԱ����(�����Ƿ��������)|" << endl;
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
		cout << "��������Ҫ������ѡ��:" ;
		cin >> choose;

		switch (choose)
		{
		case 1: 
			cout << "��ѧԱ�������ĸ�λ�ã�" << endl;
			cin >> Increaselocation;
			L = IncreaseLink(L, Increaselocation);

			cout << "����ɹ�,��ǰѧ���б�Ϊ:" << endl;
			DisplayLink(L);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "��ѡ��ɾ����ʽ: 1.ID  2.λ��" << endl;
			cin >> DelChoose;

			if (DelChoose == 1)
			{
				cout << "��������Ҫɾ����ѧԱID:" ;
				cin >> InDelStudentID;
				L = DelLinkofID(L, InDelStudentID);

				cout << "ɾ���ɹ�,��ǰѧ���б�Ϊ:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			else
			{
				cout << "��������Ҫɾ����ѧԱ���ڵ�λ��:";
				cin >> InDelStudentID;
				L = DelLinkoflocation(L, InDelStudentID);

				cout << "ɾ���ɹ�,��ǰѧ���б�Ϊ:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			break;

		case 3:
			cout << "�������޸ķ�ʽ: 1.ID  2.λ��" << endl;
			cin >> AmendChoose;

			if (AmendChoose == 1)
			{
				cout << "��������Ҫ�޸�ѧԱ��ID:" ;
				cin >> InAmendStudentID;
				L = AmendLinkofID(L, InAmendStudentID);

				cout << "�޸ĳɹ�,��ǰѧ���б�Ϊ:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			else
			{
				cout << "��������Ҫ�޸�ѧԱ��λ��:";
				cin >> InAmendStudentID;
				L = AmendLinkoflocation(L, InAmendStudentID);

				cout << "�޸ĳɹ�,��ǰѧ���б�Ϊ:" << endl;
				DisplayLink(L);
				system("pause");
				system("cls");
			}
			break;

		case 4:
			cout << "��������Ҫ�鿴��ѧԱID" << endl;
			cin >> InFindStudentID;
			L = FindLink(L, InFindStudentID);
			//DisplayLink(L);
			system("pause");
			system("cls");
			break;

		default:
			cout << "��лʹ��" <<endl ;
			system("pause");
			return 0;
			break;
		}

	}
	
	//cout << "����ɾ������" << endl;
	//cin >> InDelStudentID;
	//L = DelLinkofID(L, InDelStudentID);
	//DisplayLink(L);

	//cin >> InDelStudentID;
	//L = DelLinkoflocation(L, InDelStudentID);
	//DisplayLink(L);

	//cout << "�����޸Ĳ���" << endl;
	//cin >> InAmendStudentID;
	//L = AmendLinkofID(L, InAmendStudentID);
	//DisplayLink(L);

	//cout << "���в��Ҳ���" << endl;
	//cin >> InFindStudentID;
	//L = FindLink(L, InFindStudentID);


	return 0;
}
