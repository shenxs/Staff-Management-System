// ����ʵ��--��ְ����Ϣ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "employee.h"
#include "empNode.h"
#include <iostream>
#include<string>
#include<limits>
#include<Windows.h>
#include<fstream>
using namespace std;

string name;//����
bool sex;//�Ա�  1---��  0----Ů
string SEX;
long long jobNumber;//����
long long phoneNumber;//�绰����
string department;//���ڲ��ſ���
string title;//ְ��
int levelOftitle;//ְ�Ƶȼ�

int main()
{
	//�����ļ�
	ifstream inData("data.txt");
	employee x;//x��Ϊ�����ĩλ��
	empNode *empList = NULL; empList = new empNode(x , NULL);
	//���ļ�����д������
	while (inData >> name >> sex >> jobNumber >> phoneNumber >> department >> title >> levelOftitle)
	{	
		employee employ(name, sex, jobNumber, phoneNumber, department, title);
		empList = new empNode(employ, empList);
	}
	//����С����
	if (1)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "          ��ӭ          " << endl;;
			for (int j = 0; j < 10; j++)
			{
				cout << ">>>";
				Sleep(50);
			}
			system("cls");
		}
	}
	//����
	system("cls");
	//signal1��Ϊһ���˵���ѡ���ź�
	int signal1 = 0; 
	while (signal1 != -1)
	{
		//�ص�һ���˵���λ�����˵��ź�ѡ��
		int signal2 = 0;
		system("cls");
		cout << " --------------��ְ����Ϣ����ϵͳ--------------\n";
		cout << "|      1.��ӽ�ְ��                            |" << endl;
		cout << "|      2.��ѯ                                  |" << endl;
		cout << "|      3.�޸�                                  |" << endl;
		cout << "|      4.��ְ���������                        |" << endl;
		cout << "|      5.ɾ��             ��Ȩû��,��Ȩ����    |" << endl;
		cout << " ---------����ҽзָ���-----------------------\n";
		cout << "��ѡ��1/2/3/4/5,����-1���沢�˳�����" << endl;
		//�Ƿ��ַ��������
		while (!(cin >> signal1))
		{
			cin.clear();
			cin.ignore();
			cout << "��ѡ��1/2/3/4/5,����-1���沢�˳�����" << endl;
			
		}
		//����
		system("cls");
		employee tmp;//��ʱ����
		switch (signal1)
		{
		case 1:
			cout << "�������ְ����Ϣ" << endl;
			tmp.setAllFromeCin();
			empList = new empNode(tmp, empList);
			cout << "��Ϣ��ӳɹ�!!!" << endl;
			Sleep(2000);
			break;
		case 2:
			while (signal2 != -1)
			{
				system("cls");
				cout << " --------------��ѡ���������------------------\n";
				cout << "|      1.����                                  |" << endl;
				cout << "|      2.����                                  |" << endl;
				cout << "|      3.����                                  |" << endl;
				cout << "|      4.ְ��             ��Ȩû��,��Ȩ����    |" << endl;
				cout << "|      5.ͳ��(��ʾ������������,��ְ������)     |" << endl;
				cout << " ---------����ҽзָ���-----------------------\n";
				cout << "��ѡ��1/2/3/4,����-1�����ϼ�����" << endl;
				//�������
				while (!(cin >> signal2))
				{
					cout << "������Ϸ��ַ�" << endl;
					cin.clear();
					cin.ignore();
				}
				system("cls");
				switch (signal2)
				{
				case 1:
					cout << "�����빤��" << endl;
					while (!(cin >> jobNumber))
					{
						cout << "������Ϸ��ַ�" << endl;
						cin.clear();
						cin.ignore();
					}
					empList->findJobNumber(jobNumber);
					cout << "�����������" << endl;
					cin.get();
					cin.get();

					break;
				case 2:
					cout << "����������" << endl;
					cin >> name;
					empList->findName(name);
					cout << "�����������" << endl;
					cin.get();
					cin.get();
					break;
				case 3:
					cout << "���������" << endl;
					cin >> department;
					empList->findDepartment(department);
					cout << "�����������" << endl;
					cin.get();
					cin.get();
					break;
				case 4:
					cout << "������ְ��" << endl;
					cin >> title;
					empList->findTitle(title);
					cout << "�����������" << endl;
					cin.get();
					cin.get();
					break;
				case 5:
					empList->overView();
					break;
				default:
					break;
				}

			}
			break;
		case 3:
			cout << "��������Ҫ�޸ĵĹ���" << endl;
			while (!(cin >> jobNumber))
			{
				cout << "������Ϸ��ַ�" << endl;
				cin.clear();
				cin.ignore();
			}
			empList->change(jobNumber);
			cout << "�����������" << endl;
			cin.get();
			cin.get();
			break;
		case 4:
			empList->paixushuchu();
			cout << "�����������" << endl;
			cin.get();
			cin.get();
			break;
		case 5:
			cout << "��������Ҫɾ���Ĺ���" << endl;
			//�������
			while (!(cin >> jobNumber))
			{
				cout << "������Ϸ��ַ�" << endl;
				cin.clear();
				cin.ignore();
			}
			if(jobNumber==(empList->emp.getJobNumber()))
			{ 
				empList->emp.display();
				string confirm;
				do
				{
					cout << "ȷ��ɾ��?(Y/N)" << endl;
					cin >> confirm;
					if (confirm == "Y")
					{
						empList = empList->next;
						cout << "�ɹ�ɾ�� :)" << endl;
					}
					else if (confirm == "N")
					{
						cout << "�Ѿ�ȡ��ɾ��" << endl;
					}
				} while (confirm != "Y"&&confirm != "N");
			}
			else
			{
				empList->erease(jobNumber);
			}
			Sleep(1500);
			break;
		default:
			break;
		}
	}

	/*
	д�������ļ�
	*/
	empList->write();
	//��������
	if (1)
	{
		for (int i = 0; i < 1; i++)
		{
			cout << "         ллʹ��         " << endl;;
			for (int j = 0; j < 10; j++)
			{
				cout << "<<<";
				Sleep(45);
			}
			system("cls");
		}
	}
	return 0;
}

