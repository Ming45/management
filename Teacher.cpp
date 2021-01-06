#include "mymanage.h"

void Teacher::showteacher() {//显示教师
	cout << tid << "\t" << tname << endl;
}

void Teacher::showteachercourse() {//显示教师教授的课程

	//cout <<  "学号:"<< "\t姓名:" << "\t选修课程:" << "\t\t课程成绩:" << endl;
	cout << tid << "\t" << tname << "\t" << tcourse.cname << endl;
}

void Teacher::inputteacher() {//存放添加教师
	cout << "请输入教师的姓名："; cin >> tname;
	cout << "请输入教师的编号："; cin >> tid;
	cout << "请输入教师教授的课程："; cin >> tcourse.cname;
}

void Teacher::readteacher(istream& in) {//读取教师文本

	in >> tid >> tname >> tcourse.cname ;

}
