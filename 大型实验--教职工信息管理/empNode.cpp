#include "stdafx.h"
#include "empNode.h"
empNode::empNode()
{
	next = NULL;
	
}

void empNode::findName(string nam)
{
	empNode *curr = this;
	bool bfound = false;//����Ƿ��ҵ�
	
	while (curr != NULL)
	{
		if (( curr->emp.getName()) == nam)
		{
			curr->emp.display();
			bfound = true;
		}
		curr = curr->next;
	}
	//���û�ҵ�����ʾһ��
	if (!bfound)
	{
		cout << "δ�ҵ�������Ϣ" << endl;
	}
	delete curr;
}
void empNode::findJobNumber(long long jobNumber)
{
	empNode *curr = this;
	bool bfound = false;
	while (curr != NULL)
	{
		if (curr->emp.getJobNumber() == jobNumber)
		{
			curr->emp.display();
			bfound = true;
		}
		curr = curr->next;
	}
	if (!bfound)
	{
		cout << "δ�ҵ�������Ϣ" << endl;
	}
	delete curr;
}
void empNode::findDepartment(string department)
{
	empNode *curr = this;
	bool bfound = false;
	while (curr!= NULL)
	{
		if (curr->emp.getDepartment() == department)
		{
			curr->emp.display();
			bfound = true;
		}
		curr = curr->next;
	}
	if (!bfound)
	{
		cout << "δ�ҵ�������Ϣ" << endl;
	}
	delete curr;
}
void empNode::findTitle(string title)
{
	empNode *curr = this;
	bool bfound = false;
	while (curr!= NULL)
	{
		if (curr->emp.getTitle() == title)
		{
			curr->emp.display();
			bfound = true;
		}
		curr = curr->next;
	}
	if (!bfound)
	{
		cout << "δ�ҵ�������Ϣ" << endl;
	}
	delete curr;
}
//��ʾͳ����Ϣ
void empNode::overView()
{
	string TITLE[4] = { "����","������","��ʦ","����" };//ְ���б�
	empNode *curr = this;
	int number[4];
	for (int i = 0; i < 4; i++)//��ʼ��
	{
		number[i] = 0;
	}//��������ʼ��
	//ͳ�Ƹ���ְ�Ƶ�����
	while (curr != NULL)
	{
		int level = curr->emp.getlevelOfTitle();
		if (level != -1 && level >= 0 && level < 4)
		{
			number[level]++;
		}
		curr = curr->next;
	}
	delete curr;
	//��ʾͳ�ƽ��
	for (int i = 0; i < 4; i++)
	{
		cout << TITLE[i] << ": " << number[i] << "��" << endl;
	}

	map<string, int> T;
	T.clear();
	empNode *front = this;
	while (front != NULL)
	{
		string str;
		str = front->emp.getDepartment();
		if(str!="��")//���˵������ĩ�ڵ�
			T[str]++;
		front = front->next;//ָ��ָ����һ���ڵ�
	}
	map<string, int>::iterator it = T.begin();//����ָ��
	for (; it != T.end(); ++it)
		cout <<  it->first<< " : " << it->second <<"��"<< endl;
	cout << "�����������" << endl;
	cin.get();
	cin.get();
}
//д���ļ�
void empNode::write()
{
	ofstream out("data.txt");
	empNode *curr= this;
	while (curr->next != NULL)
	{
		out << curr->emp.getName() << " " << curr->emp.getSex() << " " << curr->emp.getJobNumber() << " " << curr->emp.getPhoneNumber() << " "
			<< curr->emp.getDepartment() << " " << curr->emp.getTitle() << " " << curr->emp.getlevelOfTitle() << endl;
		curr = curr->next;
	}
	delete curr;
}

empNode::~empNode()
{
}

void empNode::change(long long Jobnumber)
{
	empNode *curr;
	curr = this;
	while (curr != NULL)
	{
		if (curr->emp.getJobNumber() == Jobnumber)
		{
			//��ʾԭ������Ϣ
			curr->emp.display();
			cout << "������" << endl;
			curr->emp.setAllFromeCin();
		}
		curr = curr->next;
	}
	delete curr;
}

void empNode::erease( long long target)
{
	empNode *curr = this;
	empNode *pre = NULL;
	bool bFound = false;//�Ƿ��ҵ�
	while (curr!=NULL&&!bFound)
	{
		if (curr->emp.getJobNumber() == target)
		{
			curr->emp.display();
			string confirm;
			do
			{
				cout << "ȷ��ɾ��?(Y/N)" << endl;
				cin >> confirm;
				if (confirm == "Y")
				{
					pre->next = curr->next;
					cout << "�ɹ�ɾ�� :)" << endl;
				}
				else if (confirm == "N")
				{
					cout << "�Ѿ�ȡ��ɾ��" << endl;
				}
			} while (confirm != "Y"&&confirm != "N");
			delete curr;
			bFound = true;
		}
		else
		{                                                                      
			pre = curr;
			curr = curr->next;
		}

	}

	if (!bFound)
	{
		cout << "û���ҵ���Ӧ�Ĺ���" << endl;
	}
	
}

void empNode::paixushuchu()
{
	

	for (int i = 0; i < 4; i++)
	{
		empNode *curr = this;
		while (curr != NULL)
		{
			if (curr->emp.getlevelOfTitle() == i)
			{
				curr->emp.display();
			}
			curr = curr->next;
		}

	}
}