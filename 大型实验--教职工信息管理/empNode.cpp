#include "stdafx.h"
#include "empNode.h"
empNode::empNode()
{
	next = NULL;
	
}

void empNode::findName(string nam)
{
	empNode *curr = this;
	bool bfound = false;//标记是否找到
	
	while (curr != NULL)
	{
		if (( curr->emp.getName()) == nam)
		{
			curr->emp.display();
			bfound = true;
		}
		curr = curr->next;
	}
	//如果没找到就提示一下
	if (!bfound)
	{
		cout << "未找到所需信息" << endl;
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
		cout << "未找到所需信息" << endl;
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
		cout << "未找到所需信息" << endl;
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
		cout << "未找到所需信息" << endl;
	}
	delete curr;
}
//显示统计信息
void empNode::overView()
{
	string TITLE[4] = { "教授","副教授","讲师","助教" };//职称列表
	empNode *curr = this;
	int number[4];
	for (int i = 0; i < 4; i++)//初始化
	{
		number[i] = 0;
	}//计数器初始化
	//统计各个职称的人数
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
	//显示统计结果
	for (int i = 0; i < 4; i++)
	{
		cout << TITLE[i] << ": " << number[i] << "人" << endl;
	}

	map<string, int> T;
	T.clear();
	empNode *front = this;
	while (front != NULL)
	{
		string str;
		str = front->emp.getDepartment();
		if(str!="无")//过滤掉链表的末节点
			T[str]++;
		front = front->next;//指针指向下一个节点
	}
	map<string, int>::iterator it = T.begin();//容器指针
	for (; it != T.end(); ++it)
		cout <<  it->first<< " : " << it->second <<"人"<< endl;
	cout << "按任意键继续" << endl;
	cin.get();
	cin.get();
}
//写入文件
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
			//显示原本的信息
			curr->emp.display();
			cout << "请输入" << endl;
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
	bool bFound = false;//是否找到
	while (curr!=NULL&&!bFound)
	{
		if (curr->emp.getJobNumber() == target)
		{
			curr->emp.display();
			string confirm;
			do
			{
				cout << "确认删除?(Y/N)" << endl;
				cin >> confirm;
				if (confirm == "Y")
				{
					pre->next = curr->next;
					cout << "成功删除 :)" << endl;
				}
				else if (confirm == "N")
				{
					cout << "已经取消删除" << endl;
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
		cout << "没有找到相应的工号" << endl;
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