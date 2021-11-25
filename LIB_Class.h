#ifndef _LIB_Class_H_
#define _LIB_Class_H_
#include<vector>
#include<string>
#include <iostream>
#include<algorithm>

using namespace std;

class Data
{
public:
	Data(int y = 0, int m = 0, int d = 0) :Y(y), M(m), D(d) {}
	void print() { cout << Y << "/" << M << "/" << D << endl; }
	void set() { cin >> Y >> M >> D; }
	bool operator < (Data rhs) {
		return (Y * 365 + M * 30 + D) < (rhs.Y * 365 + rhs.M * 30 + rhs.D);
	}
private:
	int Y;
	int M;
	int D;
};

class Book
{
public:
	//���캯��
	Book() { num = 0; val = 0; }
	Book(int n, string na, string au, string p, Data dd, double v)
		:num(n), name(na), author(au), pub(p), d(dd), val(v) {}
	//���麯��
	virtual void print() = 0;
	//�ӿ�
	int get_num() { return num; }
	string get_name() { return name; }
	string get_author() { return author; }
	string get_pub() { return pub; }
	Data get_data() { d.print(); return d; }
	double get_val() { return val; }
	friend bool operator ==(Book* lhs, string rhs);
	friend bool sort_data(Book* lhs, Book* rhs);
private:
	//Book��Ա
	int num;
	string name;
	string author;
	string pub;
	Data d;
	double val;
};

class Test :public Book
{
public:
	//���캯��
	Test(int n, string na, string au, string p, Data dd, double v)
		:Book(n, na, au, p, dd, v) {
		cout << "�����鱾ѧ��:"; cin >> sub;
	}
	//��дʵ�ֶ�̬
	void print()override;
private:
	//Test���г�Ա ѧ��
	string sub;
};

class Tool :public Book
{
public:
	//���캯��
	Tool(int n, string na, string au, string p, Data dd, double v)
		:Book(n, na, au, p, dd, v) {
		cout << "�����鱾ѧ��:"; cin >> sub;
	}
	//��дʵ�ֶ�̬
	void print()override;

private:
	//Tool���г�Ա ѧ��
	string sub;
};

class Period :public Book
{
public:
	//���캯��
	Period(int n, string na, string au, string p, Data dd, double v)
		:Book(n, na, au, p, dd, v) {
		cout << "����ͨѶ��������:"; cin >> commun_author;
	}
	//��дʵ�ֶ�̬
	void print()override;

private:
	//Period���г�Ա ͨѶ����
	string commun_author;
};

class Library
{
public:
	Library() :lib({}) {}
	//TODO:дlib���ܺ���
	void add();
	void print();
	void sreach();
	void queue();
	void delet();
	void read();
	void save();
private:
	vector<Book*> lib;
};

//class Sort {
//public:
	//TODO:����

bool sort_name(Book* lhs, Book* rhs);
bool sort_author(Book* lhs, Book* rhs);
bool sort_pub(Book* lhs, Book* rhs);
bool sort_num(Book* lhs, Book* rhs);
bool sort_data(Book* lhs, Book* rhs);
//};
#endif