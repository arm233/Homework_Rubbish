// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdlib.h>
using namespace std;
void show_sum();//声明show_sum函数
//菜单
void menu()
{
	cout << endl << setw(40) << "欢迎使用健身房管理系统" << endl;
	
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << setw(50) << "|请选择需要的操作：                   |" << endl;
	cout << setw(50) << "|  0.游客                             |" << endl;
	cout << setw(50) << "|  1.项目一览                         |" << endl;
	cout << setw(50) << "|  2.单项会员注册                     |" << endl;
	cout << setw(50) << "|  3.VIP会员注册                      |" << endl;
	cout << setw(50) << "|  4.会员统计                         |" << endl;
	cout << setw(50) << "|  5.退出                             |" << endl;
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << endl << setw(28) << "请输入功能编号（0-5）："<<endl;
	cout << endl << "*我们有健身会馆和游泳馆两个场所，VIP会员两个场所任意使用并享受专业教练指导" << endl;
}
class Base//健身项目的基类
{
public:
	int projectId;//项目编号
	string openTime;//项目开放时间
	string limit_age;//项目年龄限制
	Base(int id, string opTime,string age)
	{
		projectId = id;
		openTime = opTime;
		limit_age = age;

	}

};
class SwimPool :public Base//游泳项目
{
public:
	SwimPool(int id, string opTime, string age, string wendu, string dep) :Base(id, opTime,age)
	{
		Temperater = wendu;
		depth = dep;
	}
	void showInfo() {
		cout <<"	-------------------" << endl;
		cout << "	游泳馆:" << endl;
		cout << "	项目号:" << projectId << endl;
		cout << "	开放时间:" << openTime << endl;
		cout << "	水深:" << depth << endl;
		cout << "	水温:" << Temperater << endl;
		cout << "	年龄限制:" <<limit_age<< endl;
		cout << "	-------------------" << endl;
		cout << endl;
	}

	string Temperater;//水温
	string depth;//水深
};
class FitRoom :public Base
{
public:
	FitRoom(int id, string opTime,string age, int sNumber) :Base(id, opTime,age)
	{
		sum_number = sNumber;
		
	}
	void showInfo() {
		cout << "	-------------------" << endl;
		cout << "	健身房:" << endl;
		cout << "	项目号:" << projectId << endl;
		cout << "	开放时间:" << openTime << endl;
		cout << "	器材数量:" << sum_number << endl;
		cout << "	年龄限制:" << limit_age << endl;
		cout << "	-------------------" << endl;
		cout << endl;
	}

	int sum_number;
};

void AllInfo() {
	SwimPool sp = SwimPool(1,  "5-10月", "10-50岁", "25°C","1.0m-1.7m");
	FitRoom fr = FitRoom(2,  "全年开放","18-60岁", 50);
	sp.showInfo();
	fr.showInfo();
	cout << "*办卡请返回上一页" << endl;
	cout << endl;
}




















//people基类
class people {
public:
	char name[100];
};
//普通会员类
class comon_member:public people
{
public:
	int money1=1000;//办卡预存款
	string date;//办卡日期
	string card;
	void new_member()
	{
		int choice = 1;
		char ch;
		cout << "		NOTICE!" << endl;
		cout << "单项会员卡年费1000 RMB，每张单项卡仅限一个项目使用" << endl;
		while (choice) //循环判断持续输入
		{
			comon_member obj1;
			
			cout << "请输入姓名：";
			cin >> obj1.name;

			cout << "请输入单项卡类（游泳卡Or健身卡）：";
			cin >> obj1.card;

			cout << "请输入办卡日期：(格式：20170701)" << endl;
			cin >> obj1.date;
			//文件输入输出流
			ofstream fout("comon_member.txt", ios::app);
			fout << "普通会员：" << endl;
			fout << "姓名：" << obj1.name << "  ";
			fout << "卡的类型:" << obj1.card <<"	";
			fout << "预存金额：" << obj1.money1 << endl;
			fout << "办卡日期：" << obj1.date << "	有效期一年" << endl;
			fout << endl;
			cout << "按1继续办卡，按0退出" << endl;
			cin >> ch;
			if (ch == '0')
				choice = 0;
			fout.close();


		}
	}
};
//VIP会员类
class vip_member:public people
{
public:
	int money2=3000;//办卡预存款
	string date;//办卡日期
	void new_vip_member()
	{
		int choice = 1;
		char ch;
		cout << "VIP会员年费3000 RMB，两个场所任意使用并享受专业教练指导" << endl;
		while (choice) //循环判断持续输入
		{
			vip_member obj2;
			cout << "请输入姓名：";
			cin >> obj2.name;
			cout << "请输入办卡日期：(格式：20170701)" << endl;
			cin >> obj2.date;
			//文件输入输出流
			ofstream fout("vip_member.txt", ios::app);
			fout << "VIP会员：" << endl;
			fout << "姓名:" << obj2.name << "  ";
			fout << "预存金额：" << obj2.money2 << endl;
			fout << "办卡日期：" << obj2.date << "有效期一年" << endl;
			fout << endl;
			cout << "按1继续办卡，按0退出" << endl;
			fout.close();
			cin >> ch;
			if (ch == '0')
				choice = 0;
		}
	}
};



	
void show_sum()//输出函数，从文件读取
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
	while (choice)//判断菜单循环
	{
		menu();
		cin >> a;
		system("cls");
		switch (a)
		{
		case 0:
			cout << "60RMB每次" << endl; break;
		case 1:
			AllInfo();
			break;
		case 2:
			//普通会员注册
		{comon_member w1;
		w1.new_member();
		break; }
		case 3:
			//VIP会员注册
		{vip_member w2;
		w2.new_vip_member();
		break; }
		case 4:
			show_sum();//显示会员统计结果
			break;
		case 5:
			exit(0);//退出
		default:
			cout << "输入结果有误" << endl;
		}
		cout << "保存并返回?(Y / N) :";
		cin >> ch;
		system("cls");//清屏
		if (ch == 'n' || ch == 'N')
			choice = 0;
	}
	return 0;
}
