#include"LIB_Class.h"
//FIXME:ɾ��������δ��ȫ����
//FIXME:���޸�while��ѭ������
//FIXME:�ݲ�������ISBN
void Library::add()
{
	int t = 0;
	cout << "��ѡ��ͼ����� 1 �̿��� 2 ������ 3 �ڿ�" << endl;
	cin >> t;
	cout << "������ ISBN ���� ���� ������ �ۼ� ��������" << endl;

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
		cout << "�������" << endl;
		break;
	}
	lib.push_back(temp);
}

void Library::print()
{
	if (lib.empty()) {
		cout << "����ͼ���б�Ϊ�գ��볢����ӻ��ȡ" << endl;
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
	cout << "����������ֶΣ�" << endl;
	cin >> target;
	auto it = find(lib.begin(), lib.end(), target);
	if (it == lib.end())cout << "δ�ҵ���ؽ�� " << endl;
	else {
		cout << "�ҵ���ؽ�� " << endl;
		while (it != lib.end()) {
			(*it)->print();
			it = find(it + 1, lib.end(), target);
		}
	}
}

void Library::delet()
{
	string target;
	cout << "����������ֶΣ�" << endl;
	cin >> target;
	auto it = find(lib.begin(), lib.end(), target);
	if (it == lib.end())cout << "δ�ҵ���ؽ�� " << endl;
	else {
		cout << "�ҵ���ؽ�����Ƿ�ɾ����Y/N����������������" << endl;
		(*it)->print();
		cin >> target;
		if (target == "Y") {
			lib.erase(it);
			return;
		}
		it = find(it + 1, lib.end(), target);
		while (it != lib.end() && target == "N") {
			cout << "�ҵ���ؽ�����Ƿ�ɾ����Y/N����������������" << endl;
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

//TODO:�ļ�IO������δʵ��
//TODO:����������Ҫ��д��operatorʵ�ֶ��ֶ� < ������Ҫ���
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