// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
void show_sum();//����show_sum����
//�˵�
void menu()
{
	cout << endl << setw(40) << "��ӭʹ�ý�������ϵͳ" << endl;
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << setw(50) << "|��ѡ����Ҫ�Ĳ�����                   |" << endl;
	cout << setw(50) << "|  1.�ο�                             |" << endl;
	cout << setw(50) << "|  2.��ͨ��Աע��                     |" << endl;
	cout << setw(50) << "|  3.VIP��Աע��                      |" << endl;
	cout << setw(50) << "|  4.��Աͳ��                         |" << endl;
	cout << setw(50) << "|  5.�˳�                             |" << endl;
	cout << setw(50) << " ------------------------------------- " << endl;
	cout << endl << setw(28) << "�����빦�ܱ�ţ�1-5����";
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
	void new_member()
	{
		int choice = 1;
		char ch;
		cout << "��ͨ��Ա���1000�飬��������������ʹ��" << endl;
		while (choice) //ѭ���жϳ�������
		{
			comon_member obj1;
			
			cout << "������������";
			cin >> obj1.name;
			cout << "������쿨���ڣ�(��ʽ��20170701)" << endl;
			cin >> obj1.date;
			//�ļ����������
			ofstream fout("comon_member.txt", ios::app);
			fout << "��ͨ��Ա��" << endl;
			fout << "������" << obj1.name << "  ";
			fout << "Ԥ���" << obj1.money1 << endl;
			fout << "�쿨���ڣ�" << obj1.date << "��Ч��һ��" << endl;
			cout << "��1�������룬��0�˳�" << endl;
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
	int money2=2000;//�쿨Ԥ���
	string date;//�쿨����
	void new_vip_member()
	{
		int choice = 1;
		char ch;
		cout << "VIP��Ա���2000�飬����רҵ����ָ��" << endl;
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
			cout << "��1�������룬��0�˳�" << endl;
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
		case 1:
			cout << "60RMBÿ��" << endl; break;
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
			cout << "����������" << endl;
		}
		cout << "���沢����?(Y / N) :";
		cin >> ch;
		system("cls");
		if (ch == 'n' || ch == 'N')
			choice = 0;
	}
	return 0;
}
