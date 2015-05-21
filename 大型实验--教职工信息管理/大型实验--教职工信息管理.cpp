// 大型实验--教职工信息管理.cpp : 定义控制台应用程序的入口点。
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

string name;//姓名
bool sex;//性别  1---男  0----女
string SEX;
long long jobNumber;//工号
long long phoneNumber;//电话号码
string department;//所在部门科室
string title;//职称
int levelOftitle;//职称等级

int main()
{
	//读入文件
	ifstream inData("data.txt");
	employee x;//x作为链表的末位点
	empNode *empList = NULL; empList = new empNode(x , NULL);
	//将文件内容写入链表
	while (inData >> name >> sex >> jobNumber >> phoneNumber >> department >> title >> levelOftitle)
	{	
		employee employ(name, sex, jobNumber, phoneNumber, department, title);
		empList = new empNode(employ, empList);
	}
	//开场小动画
	if (1)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "          欢迎          " << endl;;
			for (int j = 0; j < 10; j++)
			{
				cout << ">>>";
				Sleep(50);
			}
			system("cls");
		}
	}
	//清屏
	system("cls");
	//signal1作为一级菜单的选择信号
	int signal1 = 0; 
	while (signal1 != -1)
	{
		//回到一级菜单后复位二级菜单信号选择
		int signal2 = 0;
		system("cls");
		cout << " --------------教职工信息管理系统--------------\n";
		cout << "|      1.添加教职工                            |" << endl;
		cout << "|      2.查询                                  |" << endl;
		cout << "|      3.修改                                  |" << endl;
		cout << "|      4.按职称排序输出                        |" << endl;
		cout << "|      5.删除             版权没有,侵权不究    |" << endl;
		cout << " ---------你好我叫分割线-----------------------\n";
		cout << "请选择（1/2/3/4/5,输入-1保存并退出）：" << endl;
		//非法字符输入过滤
		while (!(cin >> signal1))
		{
			cin.clear();
			cin.ignore();
			cout << "请选择（1/2/3/4/5,输入-1保存并退出）：" << endl;
			
		}
		//清屏
		system("cls");
		employee tmp;//临时变量
		switch (signal1)
		{
		case 1:
			cout << "请输入教职工信息" << endl;
			tmp.setAllFromeCin();
			empList = new empNode(tmp, empList);
			cout << "信息添加成功!!!" << endl;
			Sleep(2000);
			break;
		case 2:
			while (signal2 != -1)
			{
				system("cls");
				cout << " --------------请选择查找条件------------------\n";
				cout << "|      1.工号                                  |" << endl;
				cout << "|      2.姓名                                  |" << endl;
				cout << "|      3.科室                                  |" << endl;
				cout << "|      4.职称             版权没有,侵权不究    |" << endl;
				cout << "|      5.统计(显示各个科室人数,各职称人数)     |" << endl;
				cout << " ---------你好我叫分割线-----------------------\n";
				cout << "请选择（1/2/3/4,输入-1返回上级）：" << endl;
				//输入过滤
				while (!(cin >> signal2))
				{
					cout << "请输入合法字符" << endl;
					cin.clear();
					cin.ignore();
				}
				system("cls");
				switch (signal2)
				{
				case 1:
					cout << "请输入工号" << endl;
					while (!(cin >> jobNumber))
					{
						cout << "请输入合法字符" << endl;
						cin.clear();
						cin.ignore();
					}
					empList->findJobNumber(jobNumber);
					cout << "按任意键继续" << endl;
					cin.get();
					cin.get();

					break;
				case 2:
					cout << "请输入姓名" << endl;
					cin >> name;
					empList->findName(name);
					cout << "按任意键继续" << endl;
					cin.get();
					cin.get();
					break;
				case 3:
					cout << "请输入科室" << endl;
					cin >> department;
					empList->findDepartment(department);
					cout << "按任意键继续" << endl;
					cin.get();
					cin.get();
					break;
				case 4:
					cout << "请输入职称" << endl;
					cin >> title;
					empList->findTitle(title);
					cout << "按任意键继续" << endl;
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
			cout << "请输入需要修改的工号" << endl;
			while (!(cin >> jobNumber))
			{
				cout << "请输入合法字符" << endl;
				cin.clear();
				cin.ignore();
			}
			empList->change(jobNumber);
			cout << "按任意键继续" << endl;
			cin.get();
			cin.get();
			break;
		case 4:
			empList->paixushuchu();
			cout << "按任意键继续" << endl;
			cin.get();
			cin.get();
			break;
		case 5:
			cout << "请输入想要删除的工号" << endl;
			//输入过滤
			while (!(cin >> jobNumber))
			{
				cout << "请输入合法字符" << endl;
				cin.clear();
				cin.ignore();
			}
			if(jobNumber==(empList->emp.getJobNumber()))
			{ 
				empList->emp.display();
				string confirm;
				do
				{
					cout << "确认删除?(Y/N)" << endl;
					cin >> confirm;
					if (confirm == "Y")
					{
						empList = empList->next;
						cout << "成功删除 :)" << endl;
					}
					else if (confirm == "N")
					{
						cout << "已经取消删除" << endl;
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
	写入链表文件
	*/
	empList->write();
	//结束界面
	if (1)
	{
		for (int i = 0; i < 1; i++)
		{
			cout << "         谢谢使用         " << endl;;
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

