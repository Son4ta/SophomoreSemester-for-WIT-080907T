#include"LIB_Class.h"
//FIXME:删除函数还未完全测试
//FIXME:已修复while死循环问题
//FIXME:暂不能搜索ISBN
void Library::add()
{
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

//TODO:文件IO与排序还未实现
//TODO:排序或许可能要手写，operator实现多字段 < 重载需要解决
void Library::queue() {
	sort(lib.begin(), lib.end(), sort_data);
}
void Library::read()
{
}
void Library::save()
{
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
	return lhs->d < rhs->d;
}