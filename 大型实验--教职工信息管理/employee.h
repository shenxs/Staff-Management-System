#include <string>
#include<iostream>
using namespace std;
#pragma once

class employee
{
public:
	employee();
	//Ĭ�Ϲ��캯��
	employee(string na,bool sex,long long jobNu,long long phoneNu,string depart,string title);
~employee();
//��ʾ��ְ����Ϣ
void display();
//���ع���
long long getJobNumber();
//���ؿ���
string getDepartment();
//��������
string getName();
//����ְ��
string getTitle();
//�����Ա�
bool getSex();
//���ص绰����
long long getPhoneNumber();
//����ְ�Ƶȼ�
int getlevelOfTitle();
//�����޸�����
void setName(const string a);
//�޸��Ա�
void setSex(const bool a);
//�޸Ĺ���
void setJobNumber(const long long a);
//�޸ĵ绰����
void setPhoneNumber(const long long  a);
//�޸���������
void setDepartment(const string a);
//�޸�ְ��
void setTitle(const string a);
//����������Ϣ
void setAllFromeCin();
private:
	string name;//����
	bool sex;//�Ա�  1---��  0----Ů
	long long jobNumber;//����
	long long phoneNumber;//�绰����
	string department;//���ڲ��ſ���
	string title;//ְ��
	int levelOftitle;//ְ�Ƶȼ�

};

