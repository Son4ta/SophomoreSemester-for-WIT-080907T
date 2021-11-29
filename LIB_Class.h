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
	//data构造函数
	Data(int y = 0, int m = 0, int d = 0) :Y(y), M(m), D(d) {}
	// 日期的打印和设置
	void print() { cout << Y << "/" << M << "/" << D << endl; }
	void set() { cin >> Y >> M >> D; }
	//日期对文件的写入与读取（注意！参数为文件指针的引用）
	void fprint(ofstream& file) { file << " " << Y << " " << M << " " << D; }
	void fset(ifstream& file) { file >> Y >> M >> D; }
	bool operator < (Data rhs) {
		return (Y * 365 + M * 30 + D) < (rhs.Y * 365 + rhs.M * 30 + rhs.D);
	}
private:
	//data数据成员
	int Y;
	int M;
	int D;
};

class Book
{
public:
	//构造函数
	Book() { num = 0; val = 0; }
	Book(int n, string na, string au, string p, Data dd, double v)
		:num(n), name(na), author(au), pub(p), d(dd), val(v) {}
	//纯虚函数
	virtual void print() = 0;
	virtual string get_feature(int& t) = 0;//特征接口
	//继承成员接口
	int get_num() { return num; }
	string get_name() { return name; }
	string get_author() { return author; }
	string get_pub() { return pub; }
	Data get_data() { return d; }
	double get_val() { return val; }
	//调用日期打印
	void print_data() { d.print(); }
	//运算符重载友元声明（用于支持find()函数）
	friend bool operator ==(Book* lhs, string rhs);
	//按日期分类友元声明（用于支持sort()函数）因为data是私有成员
	friend bool sort_data(Book* lhs, Book* rhs);
private:
	//Book成员
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
	//构造函数
	Test(int n, string na, string au, string p, Data dd, double v)
		:Book(n, na, au, p, dd, v) {
		cout << "输入书本学科:"; cin >> sub;
	}
	Test(int n, string na, string au, string p, Data dd, double v, string s)
		:Book(n, na, au, p, dd, v), sub(s) {}
	//重写实现多态
	void print()override;
	string get_feature(int& t)override;
private:
	//Test特有成员 学科
	string sub;
};

class Tool :public Book
{
public:
	//构造函数
	Tool(int n, string na, string au, string p, Data dd, double v)
		:Book(n, na, au, p, dd, v) {
		cout << "输入书本学科:"; cin >> sub;
	}
	Tool(int n, string na, string au, string p, Data dd, double v, string s)
		:Book(n, na, au, p, dd, v), sub(s) {}
	//重写实现多态
	void print()override;
	string get_feature(int& t)override;
private:
	//Tool特有成员 学科
	string sub;
};

class Period :public Book
{
public:
	//构造函数
	Period(int n, string na, string au, string p, Data dd, double v)
		:Book(n, na, au, p, dd, v) {
		cout << "输入通讯作者姓名:"; cin >> commun_author;
	}
	Period(int n, string na, string au, string p, Data dd, double v, string s)
		:Book(n, na, au, p, dd, v), commun_author(s) {}
	//重写实现多态
	void print()override;
	string get_feature(int& t)override;
private:
	//Period特有成员 通讯作者
	string commun_author;
};

class Library
{
public:
	Library() :lib({}) {}
	//lib的功能
	void add();
	void print();
	void sreach();
	void queue();
	void delet();
	void read();
	void save();
private:
	//lib的成员
	vector<Book*> lib;
};

//sort逻辑判断函数
bool sort_name(Book* lhs, Book* rhs);
bool sort_author(Book* lhs, Book* rhs);
bool sort_pub(Book* lhs, Book* rhs);
bool sort_num(Book* lhs, Book* rhs);
bool sort_data(Book* lhs, Book* rhs);

#endif