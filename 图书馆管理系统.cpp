// FIXME:图书馆管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "LIB_Class.h"
void menu();

int main()
{
	Library wit;
	int chose = 0;				//用户模式选择

	while (chose != -1) {
		system("cls");
		menu();
		cin >> chose;
		switch (chose)
		{
		case 1:
			wit.read();
			break;
		case 2:
			wit.add();
			break;
		case 3:
			wit.sreach();
			break;
		case 4:
			system("cls");
			wit.print();
			system("pause");
			break;
		case 5:
			system("cls");
			wit.queue();
			system("pause");
			break;
		case 6:
			system("cls");
			wit.delet();
			system("pause");
			break;
		case 7:
			system("cls");
			wit.save();
			system("pause");
			break;
		default:
			chose = -1;
			cout << "程序结束:)" << endl;
			break;
		}
	}
}

//菜单打印
void menu() {
	cout << "***武汉工程大学图书馆***" << endl;
	cout << "1.读取文件" << endl;
	cout << "2.添加书本" << endl;
	cout << "3.搜索书本" << endl;
	cout << "4.书本一览" << endl;
	cout << "5.书本排序" << endl;
	cout << "6.删除书本" << endl;
	cout << "7.写入文件" << endl;
	cout << "X.退出程序" << endl;
	cout << "注意文件保存！！！" << endl;
}