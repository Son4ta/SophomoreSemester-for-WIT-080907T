#include"LIB_Class.h"
//FIXME:这里是BOOK类的具体实现
//Test
void Test::print()
{
	cout << "类别：教科书 学科：" << sub << endl;
	cout << "ISBN：" << get_num() << endl
		<< "书名：" << get_name()
		<< " 作者：" << get_author() << endl
		<< "出版社：" << get_pub()
		<< " 售价：" << get_val() << endl
		<< "出版时间：";
	print_data(); cout << endl;
}
string Test::get_feature(int& t)
{
	t = 1;
	return sub;
}

//Tool
void Tool::print()
{
	cout << "类别：工具书 学科：" << sub << endl;
	cout << "ISBN：" << get_num() << endl
		<< "书名：" << get_name()
		<< " 作者：" << get_author() << endl
		<< "出版社：" << get_pub()
		<< " 售价：" << get_val() << endl
		<< "出版时间：";
	print_data(); cout << endl;
}
string Tool::get_feature(int& t)
{
	t = 2;
	return sub;
}

//Period
void Period::print()
{
	cout << "类别：期刊 通讯作者：" << commun_author << endl;
	cout << "ISBN：" << get_num() << endl
		<< "书名：" << get_name()
		<< " 第一作者：" << get_author() << endl
		<< "出版社：" << get_pub()
		<< " 售价：" << get_val() << endl
		<< "出版时间：";
	print_data(); cout << endl;
}
string Period::get_feature(int& t)
{
	t = 3;
	return commun_author;
}

//请尽量不要在头文件里实现函数，可能会造成重复声明
bool operator ==(Book* lhs, string rhs) {
	return lhs->author == rhs || lhs->name == rhs || lhs->pub == rhs;
}