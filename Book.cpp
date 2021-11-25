#include"LIB_Class.h"
void Test::print()
{
	cout << "类别：教科书 学科：" << sub << endl;
	cout << "ISBN：" << get_num() << endl
		<< "书名：" << get_name()
		<< " 作者：" << get_author() << endl
		<< "出版社：" << get_pub()
		<< " 售价：" << get_val() << endl
		<< "出版时间：";
	get_data(); cout << endl;
}

void Tool::print()
{
	cout << "类别：工具书 学科：" << sub << endl;
	cout << "ISBN：" << get_num() << endl
		<< "书名：" << get_name()
		<< " 作者：" << get_author() << endl
		<< "出版社：" << get_pub()
		<< " 售价：" << get_val() << endl
		<< "出版时间：";
	get_data(); cout << endl;
}

void Period::print()
{
	cout << "类别：期刊 通讯作者：" << commun_author << endl;
	cout << "ISBN：" << get_num() << endl
		<< "书名：" << get_name()
		<< " 第一作者：" << get_author() << endl
		<< "出版社：" << get_pub()
		<< " 售价：" << get_val() << endl
		<< "出版时间：";
	get_data(); cout << endl;
}

bool operator ==(Book* lhs, string rhs) {
	return lhs->author == rhs || lhs->name == rhs || lhs->pub == rhs;
}