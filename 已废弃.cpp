//#include"LIB_Class.h"
//
//void Book::print() {
//	cout << "ISBN：" << num
//		<< " 作者：" << author
//		<< " 出版社：" << pub
//		<< " 售价：" << val;
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
//	cout << "请选择图书分类 1 教科书 2 工具书 3 期刊" << endl;
//	cin >> t;
//	cout << "请输入 ISBN 作者 出版社 出版日期 售价" << endl;
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
//	cout << "1 教科书" << endl;
//	for (i = text.begin(); i != text.end(); i++) {
//		i->print();
//	}
//	cout << "2 工具书" << endl;
//	for (i = reference.begin(); i != reference.end(); i++) {
//		i->print();
//	}
//	cout << "3 期刊" << endl;
//	for (i = periodical.begin(); i != periodical.end(); i++) {
//		i->print();
//	}
//}
//void Library::sreach() {
//	system("clean");
//	int t;
//	cout << "1 按书名查找" << endl;
//	cout << "2 按作者查找" << endl;
//	cout << "3 按出版社查找" << endl;
//	cout << "4 按编号查找" << endl;
//	cin >> t;
//	vector<Book>::iterator i;
//	cout << "1 教科书内查找中..." << endl;
//	for (i = text.begin(); i != text.end(); i++) {
//		i->sreach();
//	}
//	cout << "2 工具书内查找中..." << endl;
//	for (i = reference.begin(); i != reference.end(); i++) {
//		i->sreach();
//	}
//	cout << "3 期刊内查找中..." << endl;
//	for (i = periodical.begin(); i != periodical.end(); i++) {
//		i->sreach();
//	}
//	cout << "######查找结束######" << endl;
//	system("pause");
//}
//void Library::queue() {}
//void Library::delet() {}
//void Library::read() {}
//void Library::save() {}