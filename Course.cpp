#include"mymanage.h"

void Course::readcourse(istream& in) {//读取课程文本

	in >> cid >> cname >> credit;
}

void Course::showcourse() {//显示课程
	cout << cid << "\t" << cname << "\t\t" << credit << endl;
}

void Course::inputcourse() {//存放课程
	cout << "请输入课程编号："; cin >> cid;
	cout << "请输入课程名称："; cin >> cname;
	cout << "请输入课程学分："; cin >> credit;
}
