#pragma once
#include"employee.h"
#include <fstream>
#include <map>

using namespace std;
//����Ϊ������ ÿ���ڵ㱣��һ����ְ������Ϣ�Լ�ָ����һ�ڵ��ָ��
class empNode
{
public:
	empNode();
	empNode(const employee &item, empNode *nextNode = NULL) :emp(item), next(nextNode) {}
	//find***������Ӧ�ı�������
	void findName(string name);
	void findJobNumber(long long jobNumber);
	void findDepartment(string department);
	void findTitle(string title);
	//ͳ�Ƹ��� ����ְ�������������������
	void overView();
	//�������е�ֵд���ļ�
	void write();
	//�޸�ĳ�����ŵĸ�����Ϣ
	void change(long long);
	//ɾ��ĳ������
	void erease(long long);
	//����ְ���������
	void paixushuchu();
	~empNode();
	employee emp;//�ڵ�ֵ
	empNode *next;
private:

};

