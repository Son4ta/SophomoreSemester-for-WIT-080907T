#include"LIB_Class.h"
//FIXME:������BOOK��ľ���ʵ��
//Test
void Test::print()
{
	cout << "��𣺽̿��� ѧ�ƣ�" << sub << endl;
	cout << "ISBN��" << get_num() << endl
		<< "������" << get_name()
		<< " ���ߣ�" << get_author() << endl
		<< "�����磺" << get_pub()
		<< " �ۼۣ�" << get_val() << endl
		<< "����ʱ�䣺";
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
	cout << "��𣺹����� ѧ�ƣ�" << sub << endl;
	cout << "ISBN��" << get_num() << endl
		<< "������" << get_name()
		<< " ���ߣ�" << get_author() << endl
		<< "�����磺" << get_pub()
		<< " �ۼۣ�" << get_val() << endl
		<< "����ʱ�䣺";
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
	cout << "����ڿ� ͨѶ���ߣ�" << commun_author << endl;
	cout << "ISBN��" << get_num() << endl
		<< "������" << get_name()
		<< " ��һ���ߣ�" << get_author() << endl
		<< "�����磺" << get_pub()
		<< " �ۼۣ�" << get_val() << endl
		<< "����ʱ�䣺";
	print_data(); cout << endl;
}
string Period::get_feature(int& t)
{
	t = 3;
	return commun_author;
}

//�뾡����Ҫ��ͷ�ļ���ʵ�ֺ��������ܻ�����ظ�����
bool operator ==(Book* lhs, string rhs) {
	return lhs->author == rhs || lhs->name == rhs || lhs->pub == rhs;
}