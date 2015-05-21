#include "stdafx.h"
#include "employee.h"

employee::employee()
{
	/*string name;//姓名
	bool sex;//性别  1---男  0----女
	long long jobNumber;//工号
	long long phoneNumber;//电话号码
	string department;//所在部门科室
	string title;//职称
	int levelOftitle;//职称等级*/
	/*name = "无";
	sex = 1;
	jobNumber = 0;
	phoneNumber = 0;
	department = "无";
	title = "无";
	levelOftitle = -1;
	*/
}
employee::employee(string na, bool se, long long jobNu, long long phoneNu, string depart, string tit)
{
	string TITLE[4] = { "教授","副教授","讲师","助教" };//职称列表
	name = na;
	sex = se;
	jobNumber = jobNu;
	phoneNumber = phoneNu;
	department = depart;
	title = tit;
	//通过职称得到职称等级
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
//展示职称信息
void employee::display()
{
	cout << "姓名:" << name<<" 性别: ";
	if (sex)
		cout << "男";
	else
		cout << "女";
	cout << " 工号:" << jobNumber << " 电话号码:" << phoneNumber << " 所在部门:" << department << " 职称:" << title << endl;
}
//以下为返回employee的各项值
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
//从输入设定值
void employee::setAllFromeCin()
{
	string TITLE[4] = { "教授","副教授","讲师","助教" };//职称列表
	cout << "姓名:" ;
	cin >> name;
	
	string SEX;
	//限定输入自能为男或女
	do
	{
		cout << "性别(男/女):";
		cin >> SEX;
		if (SEX == "男")
			sex = 1;
		else if (SEX == "女")
			sex = 0;

	} while (SEX != "男"&&SEX != "女");
	cout << "工号:";
	while (!(cin >> jobNumber))
	{
		cout << "工号:";
		cin.clear();
		cin.ignore();
	}
	cout << "电话号码:";
	while (!(cin >> phoneNumber))
	{
		cout << "电话号码:";
		cin.clear();
		cin.ignore();
	}
	cout << "所在科室部门:";
	cin >> department;
	bool isTitalIllegal = false;
	//职称限定
	while (isTitalIllegal == false)
	{
		cout << "职称:(限定为教授,副教授,讲师,助教)" << endl;;
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
	cout << "信息已经更新" << endl;
}