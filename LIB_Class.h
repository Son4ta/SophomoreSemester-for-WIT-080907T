#ifndef _LIB_Class_H_
#define _LIB_Class_H_
#include<vector>
#include<string>
#include <iostream>
#include<algorithm>
#include<fstream>

using namespace std;

class Data
{
public:
	//data���캯��
	Data(int y = 0, int m = 0, int d = 0) :Y(y), M(m), D(d) {}
	// ���ڵĴ�ӡ������
	void print() { cout << Y << "/" << M << "/" << D << endl; }
	void set() { cin >> Y >> M >> D; }
	//���ڶ��ļ���д�����ȡ��ע�⣡����Ϊ�ļ�ָ������ã�
	void fprint(ofstream& file) { file << " " << Y << " " << M << " " << D; }
	void fset(ifstream& file) { file >> Y >> M >> D; }
	bool operator < (Data rhs) {
		return (Y * 365 + M * 30 + D) < (rhs.Y * 365 + rhs.M * 30 + rhs.D);
	}
private:
	//data���ݳ�Ա
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
	virtual string get_feature(int& t) = 0;//�����ӿ�
	//�̳г�Ա�ӿ�
	int get_num() { return num; }
	string get_name() { return name; }
	string get_author() { return author; }
	string get_pub() { return pub; }
	Data get_data() { return d; }
	double get_val() { return val; }
	//�������ڴ�ӡ
	void print_data() { d.print(); }
	//�����������Ԫ����������֧��find()������
	friend bool operator ==(Book* lhs, string rhs);
	//�����ڷ�����Ԫ����������֧��sort()��������Ϊdata��˽�г�Ա
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
	Test(int n, string na, string au, string p, Data dd, double v, string s)
		:Book(n, na, au, p, dd, v), sub(s) {}
	//��дʵ�ֶ�̬
	void print()override;
	string get_feature(int& t)override;
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
	Tool(int n, string na, string au, string p, Data dd, double v, string s)
		:Book(n, na, au, p, dd, v), sub(s) {}
	//��дʵ�ֶ�̬
	void print()override;
	string get_feature(int& t)override;
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
	Period(int n, string na, string au, string p, Data dd, double v, string s)
		:Book(n, na, au, p, dd, v), commun_author(s) {}
	//��дʵ�ֶ�̬
	void print()override;
	string get_feature(int& t)override;
private:
	//Period���г�Ա ͨѶ����
	string commun_author;
};

class Library
{
public:
	Library() :lib({}) {}
	//lib�Ĺ���
	void add();
	void print();
	void sreach();
	void queue();
	void delet();
	void read();
	void save();
private:
	//lib�ĳ�Ա
	vector<Book*> lib;
};

//sort�߼��жϺ���
bool sort_name(Book* lhs, Book* rhs);
bool sort_author(Book* lhs, Book* rhs);
bool sort_pub(Book* lhs, Book* rhs);
bool sort_num(Book* lhs, Book* rhs);
bool sort_data(Book* lhs, Book* rhs);

#endif