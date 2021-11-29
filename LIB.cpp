#include"LIB_Class.h"
//FIXME:这里是LIB类的具体实现
void Library::add()
{
	system("cls");
	int t = 0;
	cout << "请选择图书分类 1 教科书 2 工具书 3 期刊" << endl;
	cin >> t;
	cout << "请输入 ISBN 书名 作者 出版社 售价 出版日期" << endl;

	int n;
	string na, au, p;
	Data dd;
	double v;
	cin >> n >> na >> au >> p >> v;
	dd.set();
	Book* temp = nullptr;
	switch (t)
	{
	case 1:
		temp = new Test(n, na, au, p, dd, v);
		break;
	case 2:
		temp = new Tool(n, na, au, p, dd, v);
		break;
	case 3:
		temp = new Period(n, na, au, p, dd, v);
		break;
	default:
		cout << "输入错误" << endl;
		break;
	}
	lib.push_back(temp);
	system("cls");
	cout << "已添加如下内容!" << endl;
	temp->print();
	system("pause");
}

void Library::print()
{
	if (lib.empty()) {
		cout << "缓存图书列表为空，请尝试添加或读取" << endl;
		return;
	}
	auto it = lib.begin();
	for (; it != lib.end(); it++) {
		(*it)->print();
	}
	return;
}

void Library::sreach()
{
	system("cls");
	string target;
	cout << "请输入查找字段：" << endl;
	cin >> target;
	auto it = find(lib.begin(), lib.end(), target);
	if (it == lib.end())cout << "未找到相关结果 " << endl;
	else {
		cout << "找到相关结果 " << endl;
		while (it != lib.end()) {
			(*it)->print();
			it = find(it + 1, lib.end(), target);
		}
	}
	system("pause");
}

void Library::delet()
{
	string target;
	cout << "请输入查找字段：" << endl;
	cin >> target;
	auto it = find(lib.begin(), lib.end(), target);
	if (it == lib.end())cout << "未找到相关结果 " << endl;
	else {
		cout << "找到相关结果，是否删除？Y/N（否或查找其他相关项）" << endl;
		(*it)->print();
		cin >> target;
		if (target == "Y") {
			lib.erase(it);
			return;
		}
		it = find(it + 1, lib.end(), target);
		while (it != lib.end() && target == "N") {
			cout << "找到相关结果，是否删除？Y/N（否或查找其他相关项）" << endl;
			(*it)->print();
			cin >> target;
			it = find(it + 1, lib.end(), target);
		}
		if (target == "Y") {
			lib.erase(it);
			return;
		}
	}
}

void Library::queue() {
	cout << "1.按日期排序" << endl;
	cout << "2.按书名排序" << endl;
	cout << "3.按作者排序" << endl;
	cout << "4.按出版社排序" << endl;
	cout << "5.按ISBN排序" << endl;
	int chose = 0;
	cin >> chose;
	switch (chose)
	{
	case 1:
		sort(lib.begin(), lib.end(), sort_data);
		break;
	case 2:
		sort(lib.begin(), lib.end(), sort_name);
		break;
	case 3:
		sort(lib.begin(), lib.end(), sort_author);
		break;
	case 4:
		sort(lib.begin(), lib.end(), sort_pub);
		break;
	case 5:
		sort(lib.begin(), lib.end(), sort_num);
		break;
	default:
		cout << "输入有误！" << endl;
		break;
	}
	cout << "完成！" << endl;
}

void Library::read()
{
	system("cls");
	int t = 0;
	int n;
	string na, au, p, s;
	Data dd;
	double v;
	ifstream file;

	file.open("Date.txt", ios::in);

	while (!file.eof()) {
		file >> t >> n >> na >> au >> p >> v;
		dd.fset(file);
		file >> s;
		Book* temp = nullptr;
		switch (t)
		{
		case 1:
			temp = new Test(n, na, au, p, dd, v, s);
			break;
		case 2:
			temp = new Tool(n, na, au, p, dd, v, s);
			break;
		case 3:
			temp = new Period(n, na, au, p, dd, v, s);
			break;
		default:
			break;
		}
		lib.push_back(temp);
	}
	file.close();
	cout << "文件已读取至缓存！" << endl;
	system("pause");
}

void Library::save()
{
	ofstream file;
	file.open("Date.txt", ios::out);
	int t = 0;
	string feature;
	auto it = lib.begin();
	for (; it != lib.end(); it++) {
		feature = (*it)->get_feature(t);
		file << t << ' ' << (*it)->get_num() << ' ' << (*it)->get_name()
			<< ' ' << (*it)->get_author() << ' ' << (*it)->get_pub()
			<< ' ' << (*it)->get_val();
		(*it)->get_data().fprint(file);
		file << ' ' << feature;
		if (it + 1 != lib.end()) {
			file << endl;
		}
	}
	file.close();
	cout << "文件已保存至Date.txt" << endl;
}

bool sort_name(Book* lhs, Book* rhs) {
	return lhs->get_name() < rhs->get_name();
}
bool sort_author(Book* lhs, Book* rhs) {
	return lhs->get_author() < rhs->get_author();
}
bool sort_pub(Book* lhs, Book* rhs) {
	return lhs->get_pub() < rhs->get_pub();
}
bool sort_num(Book* lhs, Book* rhs) {
	return lhs->get_num() < rhs->get_num();
}
bool sort_data(Book* lhs, Book* rhs) {
	return rhs->d < lhs->d;//新到旧
}