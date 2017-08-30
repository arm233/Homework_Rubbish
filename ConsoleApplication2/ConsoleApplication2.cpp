// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
void show_sum();
void new_vip_member();
void menu()
{
	cout << endl << setw(40) << "欢迎使用健身房管理系统" << endl;
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << setw(50) << "|请选择需要的操作：                   |" << endl;
	cout << setw(50) << "|  1.游客                             |" << endl;
	cout << setw(50) << "|  2.普通会员注册                     |" << endl;
	cout << setw(50) << "|  3.VIP会员注册                      |" << endl;
	cout << setw(50) << "|  4.会员统计                         |" << endl;
	cout << setw(50) << "|  5.退出                             |" << endl;
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << endl << setw(28) << "请输入功能编号（1-5）：";
}



class people {
public:
	char name[100];
};

class comon_member:public people
{
public:
	int money1=1000;
	string date;
	void new_member()
	{
		int choice = 1;
		char ch;
		cout << "普通会员年费1000块，所有器材无限制使用" << endl;
		while (choice) {
			comon_member obj1;

			cout << "请输入姓名：";
			cin >> obj1.name;
			cout << "请输入办卡日期：(格式：20170701)" << endl;
			cin >> obj1.date;
			ofstream fout("comon_member.txt", ios::app);
			fout << "普通会员：" << endl;
			fout << "姓名：" << obj1.name << "  ";
			fout << "预存金额：" << obj1.money1 << endl;
			fout << "办卡日期：" << obj1.date << "有效期一年" << endl;
			cout << "按1继续输入，按0退出" << endl;
			cin >> ch;
			if (ch == '0')
				choice = 0;
			fout.close();


		}
	}
};
class vip_member:public people
{
public:
	int money2=2000;
	string date;
	void new_vip_member()
	{
		int choice = 1;
		char ch;
		cout << "VIP会员年费2000块，享受专业教练指导" << endl;
		while (choice) {
			vip_member obj2;
			cout << "请输入姓名：";
			cin >> obj2.name;
			cout << "请输入办卡日期：(格式：20170701)" << endl;
			cin >> obj2.date;
			ofstream fout("vip_member.txt", ios::app);
			fout << "VIP会员：" << endl;
			fout << "姓名:" << obj2.name << "  ";
			fout << "预存金额：" << obj2.money2 << endl;
			fout << "办卡日期：" << obj2.date << "有效期一年" << endl;
			cout << "按1继续输入，按0退出" << endl;
			fout.close();
			cin >> ch;
			if (ch == '0')
				choice = 0;
		}
	}
};



	
void show_sum()
{

	ifstream fin("comon_member.txt");
	char ch[100];
	while (!fin.eof())
	{
		fin>>ch;
		cout << ch << endl;;
	}
	fin.close();
	ifstream fine("vip_member.txt");
	char chi[100];
	while (!fine.eof())
	{
		fine >> chi;
		cout << chi << endl;;
	}
	fine.close();
}

int main()
{
	int choice = 1, a;
	char ch;
	while (choice)
	{
		menu();
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			cout << "60RMB每次" << endl; break;
		case 2:
		{comon_member w1;
		w1.new_member();
		break; }
		case 3:
		{vip_member w2;
		w2.new_vip_member();
		break; }
		case 4:
			show_sum();
			break;
		case 5:
			exit(0);
		default:
			cout << "输入结果有误" << endl;
		}
		cout << "保存并返回?(Y / N) :";
		cin >> ch;
		system("cls");
		if (ch == 'n' || ch == 'N')
			choice = 0;
	}
	return 0;
}
