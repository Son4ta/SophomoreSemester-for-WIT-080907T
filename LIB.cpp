#include"LIB_Class.h"
//FIXME:������LIB��ľ���ʵ��
void Library::add()
{
	system("cls");
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
	system("cls");
	cout << "�������������!" << endl;
	temp->print();
	system("pause");
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
	system("cls");
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
	system("pause");
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

void Library::queue() {
	cout << "1.����������" << endl;
	cout << "2.����������" << endl;
	cout << "3.����������" << endl;
	cout << "4.������������" << endl;
	cout << "5.��ISBN����" << endl;
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
		cout << "��������" << endl;
		break;
	}
	cout << "��ɣ�" << endl;
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
	cout << "�ļ��Ѷ�ȡ�����棡" << endl;
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
	cout << "�ļ��ѱ�����Date.txt" << endl;
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
	return rhs->d < lhs->d;//�µ���
}