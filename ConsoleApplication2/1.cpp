// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdlib.h>
using namespace std;
void show_sum();//����show_sum����
//�˵�
void menu()
{
	cout << endl << setw(40) << "��ӭʹ�ý�������ϵͳ" << endl;
	
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << setw(50) << "|��ѡ����Ҫ�Ĳ�����                   |" << endl;
	cout << setw(50) << "|  0.�ο�                             |" << endl;
	cout << setw(50) << "|  1.��Ŀһ��                         |" << endl;
	cout << setw(50) << "|  2.�����Աע��                     |" << endl;
	cout << setw(50) << "|  3.VIP��Աע��                      |" << endl;
	cout << setw(50) << "|  4.��Աͳ��                         |" << endl;
	cout << setw(50) << "|  5.�˳�                             |" << endl;
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << endl << setw(28) << "�����빦�ܱ�ţ�0-5����"<<endl;
	cout << endl << "*�����н����ݺ���Ӿ������������VIP��Ա������������ʹ�ò�����רҵ����ָ��" << endl;
}
class Base//������Ŀ�Ļ���
{
public:
	int projectId;//��Ŀ���
	string openTime;//��Ŀ����ʱ��
	string limit_age;//��Ŀ��������
	Base(int id, string opTime,string age)
	{
		projectId = id;
		openTime = opTime;
		limit_age = age;

	}

};
class SwimPool :public Base//��Ӿ��Ŀ
{
public:
	SwimPool(int id, string opTime, string age, string wendu, string dep) :Base(id, opTime,age)
	{
		Temperater = wendu;
		depth = dep;
	}
	void showInfo() {
		cout <<"	-------------------" << endl;
		cout << "	��Ӿ��:" << endl;
		cout << "	��Ŀ��:" << projectId << endl;
		cout << "	����ʱ��:" << openTime << endl;
		cout << "	ˮ��:" << depth << endl;
		cout << "	ˮ��:" << Temperater << endl;
		cout << "	��������:" <<limit_age<< endl;
		cout << "	-------------------" << endl;
		cout << endl;
	}

	string Temperater;//ˮ��
	string depth;//ˮ��
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
		cout << "	����:" << endl;
		cout << "	��Ŀ��:" << projectId << endl;
		cout << "	����ʱ��:" << openTime << endl;
		cout << "	��������:" << sum_number << endl;
		cout << "	��������:" << limit_age << endl;
		cout << "	-------------------" << endl;
		cout << endl;
	}

	int sum_number;
};

void AllInfo() {
	SwimPool sp = SwimPool(1,  "5-10��", "10-50��", "25��C","1.0m-1.7m");
	FitRoom fr = FitRoom(2,  "ȫ�꿪��","18-60��", 50);
	sp.showInfo();
	fr.showInfo();
	cout << "*�쿨�뷵����һҳ" << endl;
	cout << endl;
}




















//people����
class people {
public:
	char name[100];
};
//��ͨ��Ա��
class comon_member:public people
{
public:
	int money1=1000;//�쿨Ԥ���
	string date;//�쿨����
	string card;
	void new_member()
	{
		int choice = 1;
		char ch;
		cout << "		NOTICE!" << endl;
		cout << "�����Ա�����1000 RMB��ÿ�ŵ������һ����Ŀʹ��" << endl;
		while (choice) //ѭ���жϳ�������
		{
			comon_member obj1;
			
			cout << "������������";
			cin >> obj1.name;

			cout << "�����뵥��ࣨ��Ӿ��Or��������";
			cin >> obj1.card;

			cout << "������쿨���ڣ�(��ʽ��20170701)" << endl;
			cin >> obj1.date;
			//�ļ����������
			ofstream fout("comon_member.txt", ios::app);
			fout << "��ͨ��Ա��" << endl;
			fout << "������" << obj1.name << "  ";
			fout << "��������:" << obj1.card <<"	";
			fout << "Ԥ���" << obj1.money1 << endl;
			fout << "�쿨���ڣ�" << obj1.date << "	��Ч��һ��" << endl;
			fout << endl;
			cout << "��1�����쿨����0�˳�" << endl;
			cin >> ch;
			if (ch == '0')
				choice = 0;
			fout.close();


		}
	}
};
//VIP��Ա��
class vip_member:public people
{
public:
	int money2=3000;//�쿨Ԥ���
	string date;//�쿨����
	void new_vip_member()
	{
		int choice = 1;
		char ch;
		cout << "VIP��Ա���3000 RMB��������������ʹ�ò�����רҵ����ָ��" << endl;
		while (choice) //ѭ���жϳ�������
		{
			vip_member obj2;
			cout << "������������";
			cin >> obj2.name;
			cout << "������쿨���ڣ�(��ʽ��20170701)" << endl;
			cin >> obj2.date;
			//�ļ����������
			ofstream fout("vip_member.txt", ios::app);
			fout << "VIP��Ա��" << endl;
			fout << "����:" << obj2.name << "  ";
			fout << "Ԥ���" << obj2.money2 << endl;
			fout << "�쿨���ڣ�" << obj2.date << "��Ч��һ��" << endl;
			fout << endl;
			cout << "��1�����쿨����0�˳�" << endl;
			fout.close();
			cin >> ch;
			if (ch == '0')
				choice = 0;
		}
	}
};



	
void show_sum()//������������ļ���ȡ
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
	while (choice)//�жϲ˵�ѭ��
	{
		menu();
		cin >> a;
		system("cls");
		switch (a)
		{
		case 0:
			cout << "60RMBÿ��" << endl; break;
		case 1:
			AllInfo();
			break;
		case 2:
			//��ͨ��Աע��
		{comon_member w1;
		w1.new_member();
		break; }
		case 3:
			//VIP��Աע��
		{vip_member w2;
		w2.new_vip_member();
		break; }
		case 4:
			show_sum();//��ʾ��Աͳ�ƽ��
			break;
		case 5:
			exit(0);//�˳�
		default:
			cout << "����������" << endl;
		}
		cout << "���沢����?(Y / N) :";
		cin >> ch;
		system("cls");//����
		if (ch == 'n' || ch == 'N')
			choice = 0;
	}
	return 0;
}
