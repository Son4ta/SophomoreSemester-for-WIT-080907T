#include"LIB_Class.h"
void Test::print()
{
	cout << "��𣺽̿��� ѧ�ƣ�" << sub << endl;
	cout << "ISBN��" << get_num() << endl
		<< "������" << get_name()
		<< " ���ߣ�" << get_author() << endl
		<< "�����磺" << get_pub()
		<< " �ۼۣ�" << get_val() << endl
		<< "����ʱ�䣺";
	get_data(); cout << endl;
}

void Tool::print()
{
	cout << "��𣺹����� ѧ�ƣ�" << sub << endl;
	cout << "ISBN��" << get_num() << endl
		<< "������" << get_name()
		<< " ���ߣ�" << get_author() << endl
		<< "�����磺" << get_pub()
		<< " �ۼۣ�" << get_val() << endl
		<< "����ʱ�䣺";
	get_data(); cout << endl;
}

void Period::print()
{
	cout << "����ڿ� ͨѶ���ߣ�" << commun_author << endl;
	cout << "ISBN��" << get_num() << endl
		<< "������" << get_name()
		<< " ��һ���ߣ�" << get_author() << endl
		<< "�����磺" << get_pub()
		<< " �ۼۣ�" << get_val() << endl
		<< "����ʱ�䣺";
	get_data(); cout << endl;
}

bool operator ==(Book* lhs, string rhs) {
	return lhs->author == rhs || lhs->name == rhs || lhs->pub == rhs;
}