//#include"LIB_Class.h"
//
//void Book::print() {
//	cout << "ISBN��" << num
//		<< " ���ߣ�" << author
//		<< " �����磺" << pub
//		<< " �ۼۣ�" << val;
//	d.print();
//	cout << endl;
//}
//void Book::add() {
//	cin >> num >> author >> pub;
//	d.add(); cin >> val;
//}
//
//
//void Library::add() {
//	int t = 0;
//	cout << "��ѡ��ͼ����� 1 �̿��� 2 ������ 3 �ڿ�" << endl;
//	cin >> t;
//	cout << "������ ISBN ���� ������ �������� �ۼ�" << endl;
//	Book input;
//	input.add();
//	if (t == 1) {
//		text.push_back(input);
//	}
//	else if (t == 2) {
//		reference.push_back(input);
//	}
//	else {
//		periodical.push_back(input);
//	}
//}
//void Library::print() {
//	vector<Book>::iterator i;
//	cout << "1 �̿���" << endl;
//	for (i = text.begin(); i != text.end(); i++) {
//		i->print();
//	}
//	cout << "2 ������" << endl;
//	for (i = reference.begin(); i != reference.end(); i++) {
//		i->print();
//	}
//	cout << "3 �ڿ�" << endl;
//	for (i = periodical.begin(); i != periodical.end(); i++) {
//		i->print();
//	}
//}
//void Library::sreach() {
//	system("clean");
//	int t;
//	cout << "1 ����������" << endl;
//	cout << "2 �����߲���" << endl;
//	cout << "3 �����������" << endl;
//	cout << "4 ����Ų���" << endl;
//	cin >> t;
//	vector<Book>::iterator i;
//	cout << "1 �̿����ڲ�����..." << endl;
//	for (i = text.begin(); i != text.end(); i++) {
//		i->sreach();
//	}
//	cout << "2 �������ڲ�����..." << endl;
//	for (i = reference.begin(); i != reference.end(); i++) {
//		i->sreach();
//	}
//	cout << "3 �ڿ��ڲ�����..." << endl;
//	for (i = periodical.begin(); i != periodical.end(); i++) {
//		i->sreach();
//	}
//	cout << "######���ҽ���######" << endl;
//	system("pause");
//}
//void Library::queue() {}
//void Library::delet() {}
//void Library::read() {}
//void Library::save() {}