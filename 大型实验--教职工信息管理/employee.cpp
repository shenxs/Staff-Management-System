#include "stdafx.h"
#include "employee.h"

employee::employee()
{
	/*string name;//����
	bool sex;//�Ա�  1---��  0----Ů
	long long jobNumber;//����
	long long phoneNumber;//�绰����
	string department;//���ڲ��ſ���
	string title;//ְ��
	int levelOftitle;//ְ�Ƶȼ�*/
	/*name = "��";
	sex = 1;
	jobNumber = 0;
	phoneNumber = 0;
	department = "��";
	title = "��";
	levelOftitle = -1;
	*/
}
employee::employee(string na, bool se, long long jobNu, long long phoneNu, string depart, string tit)
{
	string TITLE[4] = { "����","������","��ʦ","����" };//ְ���б�
	name = na;
	sex = se;
	jobNumber = jobNu;
	phoneNumber = phoneNu;
	department = depart;
	title = tit;
	//ͨ��ְ�Ƶõ�ְ�Ƶȼ�
	for (int i = 0; i < 4; i++)
	{
		if (title == TITLE[i])
		{
			levelOftitle = i;
			break;
		}
	}
	
}

employee::~employee()
{
}
//չʾְ����Ϣ
void employee::display()
{
	cout << "����:" << name<<" �Ա�: ";
	if (sex)
		cout << "��";
	else
		cout << "Ů";
	cout << " ����:" << jobNumber << " �绰����:" << phoneNumber << " ���ڲ���:" << department << " ְ��:" << title << endl;
}
//����Ϊ����employee�ĸ���ֵ
long long employee::getJobNumber()
{
	return jobNumber;
}

string employee::getDepartment()
{
	return department;
}

string employee::getName()
{
	return name;
}

string employee::getTitle()
{
	return title;
}

bool employee::getSex()
{
	return sex;
}

long long employee::getPhoneNumber()
{
	return phoneNumber;
}

int employee::getlevelOfTitle()
{
	return levelOftitle;
}

void employee::setName(const string a)
{
	name = a;
}

void employee::setSex(const bool a)
{
	sex = a;
}

void employee::setJobNumber(const long long a)
{
	jobNumber = a;
}

void employee::setPhoneNumber(const long long a)
{
	phoneNumber = a;
}

void employee::setDepartment(const string a)
{
	department = a;
}

void employee::setTitle(const string a)
{
	title = a;
}
//�������趨ֵ
void employee::setAllFromeCin()
{
	string TITLE[4] = { "����","������","��ʦ","����" };//ְ���б�
	cout << "����:" ;
	cin >> name;
	
	string SEX;
	//�޶���������Ϊ�л�Ů
	do
	{
		cout << "�Ա�(��/Ů):";
		cin >> SEX;
		if (SEX == "��")
			sex = 1;
		else if (SEX == "Ů")
			sex = 0;

	} while (SEX != "��"&&SEX != "Ů");
	cout << "����:";
	while (!(cin >> jobNumber))
	{
		cout << "����:";
		cin.clear();
		cin.ignore();
	}
	cout << "�绰����:";
	while (!(cin >> phoneNumber))
	{
		cout << "�绰����:";
		cin.clear();
		cin.ignore();
	}
	cout << "���ڿ��Ҳ���:";
	cin >> department;
	bool isTitalIllegal = false;
	//ְ���޶�
	while (isTitalIllegal == false)
	{
		cout << "ְ��:(�޶�Ϊ����,������,��ʦ,����)" << endl;;
		cin >> title;
		for (int i = 0; i < 4; i++)
		{
			if (title == TITLE[i])
			{
				isTitalIllegal = true;
				levelOftitle = i;
				break;
			}
		}
	}
	cout << "��Ϣ�Ѿ�����" << endl;
}