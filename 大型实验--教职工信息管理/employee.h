#include <string>
#include<iostream>
using namespace std;
#pragma once

class employee
{
public:
	employee();
	//默认构造函数
	employee(string na,bool sex,long long jobNu,long long phoneNu,string depart,string title);
~employee();
//显示教职工信息
void display();
//返回工号
long long getJobNumber();
//返回科室
string getDepartment();
//返回姓名
string getName();
//返回职称
string getTitle();
//返回性别
bool getSex();
//返回电话号码
long long getPhoneNumber();
//返回职称等级
int getlevelOfTitle();
//用于修改姓名
void setName(const string a);
//修改性别
void setSex(const bool a);
//修改工号
void setJobNumber(const long long a);
//修改电话号码
void setPhoneNumber(const long long  a);
//修改所属部门
void setDepartment(const string a);
//修改职称
void setTitle(const string a);
//输入所有信息
void setAllFromeCin();
private:
	string name;//姓名
	bool sex;//性别  1---男  0----女
	long long jobNumber;//工号
	long long phoneNumber;//电话号码
	string department;//所在部门科室
	string title;//职称
	int levelOftitle;//职称等级

};

