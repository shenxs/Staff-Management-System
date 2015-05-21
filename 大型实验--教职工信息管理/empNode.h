#pragma once
#include"employee.h"
#include <fstream>
#include <map>

using namespace std;
//此类为链表类 每个节点保存一个教职工的信息以及指向下一节点的指针
class empNode
{
public:
	empNode();
	empNode(const employee &item, empNode *nextNode = NULL) :emp(item), next(nextNode) {}
	//find***按照相应的变量查找
	void findName(string name);
	void findJobNumber(long long jobNumber);
	void findDepartment(string department);
	void findTitle(string title);
	//统计概览 各个职称人数与各个部门人数
	void overView();
	//将链表中的值写入文件
	void write();
	//修改某个工号的个人信息
	void change(long long);
	//删除某个工号
	void erease(long long);
	//按照职称排序输出
	void paixushuchu();
	~empNode();
	employee emp;//节点值
	empNode *next;
private:

};

