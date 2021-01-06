#include"mymanage.h"

Studentwork::~Studentwork() {//析构，将动态内存delete
	if (panduan[0] == 1) {//判断是否进行了成绩文本操作
		for (Student* temp; sshead->ssnext != ssend;) {//删去对成绩处理指针
			temp = sshead->ssnext;
			sshead->ssnext = sshead->ssnext->ssnext;
			delete temp;
		}
		delete sshead, ssend;
	}

	if (panduan[1] == 1) {//判断是否进行了学生文本操作
		for (Student* temp; shead->snext != send;) {//删去对学生处理指针
			temp = shead->snext;
			shead->snext = shead->snext->snext;
			delete temp;
		}
		delete shead, send;
	}

	if (panduan[2] == 1) {//判断是否进行了课程文本操作
		for (Course* temp; schead->cnext != scend;) {//删去对课程处理指针
			temp = schead->cnext;
			schead->cnext = schead->cnext->cnext;
			delete temp;
		}
		delete schead, scend;
	}
}
void Studentwork::savescoretxt() {//保存成绩文本，用sshead,ssend来处理
	outscore.open("sort.txt");
	if (outscore) {//用来判断open操作是否成功
		for (Student* p = sshead->ssnext; p != ssend; p = p->ssnext)//从头指针的后一个ssnext到尾指针
			outscore << p->sid << "\t" << p->sname << "\t" << p->scourse.cname << "\t" << p->scourse.score << '\n';
		outscore.close();//关闭文件
	}
}
void  Studentwork::getscoretxt() {//获取成绩文本，用tshead,tsend来处理
	panduan[0] = 1;//代表进行了成绩文本的读取
	sshead = new Student;//先开一个头指针sshead，指向Student对象
	sshead->ssnext = new Student;//头指针指向的ssnext，也开个，指向Student对象
	ssend = sshead->ssnext;//用一个尾指针来获取那个ssnext
	inscore.open("sort.txt");//读取
	if (!inscore)
		cout << "这是一个新系统，请先输入。" << endl;
	else {

		while (!inscore.eof()) {//没到结尾
			ssend->readscore(inscore);//读取尾指针的内容
			if (ssend->sid[0] == '\0') {//如果尾指针的内容中姓名为0，即没了，就结束
				//end->scourse.pop_back();
				break;
			}
			ssend->ssnext = new Student;//为尾指针指向的ssnext开一个
			ssend = ssend->ssnext;//用更改尾指针为尾指针指向的ssnext
		}
		inscore.close();
		cout << "读取学生成绩信息成功!" << endl;
	}
}

void Studentwork::savestudenttxt() {//保存学生文本，用shead,send来处理
	outstudent.open("sortstudent.txt");
	if (outstudent) {//用来判断open操作是否成功
		for (Student* p = shead->snext; p != send; p = p->snext)
			outstudent << p->sid << "\t" << p->sname << "\t" << p->sclass << "\t" << p->major << '\n';
		outstudent.close();//关闭文件
	}
}
void  Studentwork::getstudenttxt() {//获取学生文本，用thead,tend来处理
	panduan[1] = 1;//代表进行了学生文本的读取
	shead = new Student;//动态内存函数结束后会自动销毁
	shead->snext = new Student;//用snext获取
	send = shead->snext;
	instudent.open("sortstudent.txt");//读取
	if (!instudent)
		cout << "这是一个新系统，请先输入。" << endl;
	else {
		while (!instudent.eof()) {//没到结尾
			send->readstudent(instudent);
			if (send->sid[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			send->snext = new Student;
			send = send->snext;
		}
		instudent.close();
		cout << "读取学生信息成功!" << endl;
	}
}

void Studentwork::savecoursetxt() {//保存课程文本
	outcourse.open("sortcourse.txt");
	if (outcourse) {//用来判断open操作是否成功
		for (Course* p = schead->cnext; p != scend; p = p->cnext)
			outcourse << p->cid << "\t" << p->cname << "\t" << p->credit << '\n';
		outcourse.close();//关闭文件
	}
}
void  Studentwork::getcoursetxt() {//获取课程文本
	panduan[2] = 1;//代表进行了课程文本的读取
	schead = new Course;//动态内存函数结束后会自动销毁
	schead->cnext = new Course;
	scend = schead->cnext;
	incourse.open("sortcourse.txt");//读取
	if (!incourse) {
		cout << "这是一个新系统，请先输入。" << endl;

	}
	else {
		while (!incourse.eof()) {//没到结尾
			scend->readcourse(incourse);
			if (scend->cid[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			scend->cnext = new Course;
			scend = scend->cnext;
		}
		incourse.close();
		cout << "读取学生成绩信息成功!" << endl;
	}
}

Course* Studentwork::sfindcname(char* name) {//由名字找课程(课程文本)
	for (Course* p = schead; p->cnext != scend; p = p->cnext)
		if (!strcmp(p->cnext->cname, name))return p;
	return NULL;
}
Course* Studentwork::sfindcid(char* Id) {//由学号找课程(课程文本)
	for (Course* p = schead; p->cnext != scend; p = p->cnext)
		if (!strcmp(p->cnext->cid, Id))return p;
	return NULL;
}


Student* Studentwork::sfindsname(char* name) {//由名字找学生(成绩文本，用sshead,ssnext....)
	for (Student* p = sshead; p->ssnext != ssend; p = p->ssnext)
		if (!strcmp(p->ssnext->sname, name))return p;
	return NULL;
}
Student* Studentwork::sfindsid(char* Id) {//由学号找学生(成绩文本，用tshead,ssnext....)
	for (Student* p = sshead; p->ssnext != ssend; p = p->ssnext)
		if (!strcmp(p->ssnext->sid, Id))return p;
	return NULL;
}


void Studentwork::getstudentscore() {//读取显示目标学生所有课程成绩，用sshead,ssend来处理
	char who[100];
	Student* p = NULL;
	int x = 0;
	cout << "请选择由姓名还是学号查找(1代表名字，2代表学号)";
	cin >> x;
	if (x == 1) {
		cout << "请输入要查找的人的姓名:";
		cin >> who;
		if (p = sfindsname(who)) {
			double zong = 0;//用于计算总分
			cout << "已找到学生的信息，他的课程及成绩如下" << endl;
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sname, who)) {
					if (pp->ssnext->scourse.score != -1) {
						cout << "课程：" << pp->ssnext->scourse.cname << "\t成绩：" << pp->ssnext->scourse.score << endl;
						zong += pp->ssnext->scourse.score;
					}
					else
						cout << "课程：" << pp->ssnext->scourse.cname << "\t未参加考试，无成绩" << endl;
				}
			}
			cout << "总分为：" << zong << endl;
			int _getch(void);
			system("pause");
		}
		else {
			cout << "没有找到!" << endl;
			int _getch(void);
			system("pause");
		}
	}
	else {
		cout << "请输入要查找的人的学号:";
		cin >> who;
		if (p = sfindsid(who)) {
			double zong = 0;//用于计算总分
			cout << "已找到学生的信息，他的课程及成绩如下" << endl;
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sid, who)) {
					if (pp->ssnext->scourse.score != -1) {
						cout << "课程：" << pp->ssnext->scourse.cname << "\t成绩：" << pp->ssnext->scourse.score << endl;
						zong += pp->ssnext->scourse.score;
					}
					else
						cout << "课程：" << pp->ssnext->scourse.cname << "\t未参加考试，无成绩" << endl;
				}
			}
			cout << "总分为：" << zong << endl;
			int _getch(void);
			system("pause");
		}
		else {
			cout << "没有找到!" << endl;
			int _getch(void);
			system("pause");
		}
	}
}

void Studentwork::getcoursecredit() {//读取显示目标学生所有课程学分
	char who[100];
	Student* p = NULL;
	int x = 0;
	cout << "请选择由姓名还是学号查找(1代表名字，2代表学号)";
	cin >> x;
	if (x == 1) {
		cout << "请输入要查找的人的姓名:";
		cin >> who;
		if (p = sfindsname(who)) {
			cout << "已找到学生的信息，他的课程及学分如下" << endl;
			double zong = 0;//用于算现有总学分
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {//找到学生
				if (!strcmp(pp->ssnext->sname, who)) {//当指针的对象的姓名是目标学生姓名时

					for (Course* pc = schead; pc != scend; pc = pc->cnext) {//找到课程          （注意判断时，是直接判断pc是否有到底）
						if (!strcmp(pp->ssnext->scourse.cname, pc->cname)) {//当指针的对象的课程名是目标课程名时
							cout << "课程：" << pc->cname << "\t学分：" << pc->credit << endl;
							zong += pc->credit;
						}
					}
				}
			}
			cout << "现有总学分：" << zong << endl;
			int _getch(void);
			system("pause");
		}
		else {
			cout << "没有找到!" << endl;
			int _getch(void);
			system("pause");
		}
	}
	else {
		cout << "请输入要查找的人的学号:";
		cin >> who;
		if (p = sfindsid(who)) {
			cout << "已找到学生的信息，他的课程及学分如下" << endl;
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sid, who)) {

					for (Course* pc = schead; pc != scend; pc = pc->cnext) {//找到课程    （注意判断时，是直接判断pc是否有到底）
						if (!strcmp(pp->ssnext->scourse.cname, pc->cname)) {//当指针的对象的课程名是目标课程名时
							cout << "课程：" << pc->cname << "\t学分：" << pc->credit << endl;
						}
					}
				}
			}
			int _getch(void);
			system("pause");
		}
		else {
			cout << "没有找到!" << endl;
			int _getch(void);
			system("pause");
		}
	}
}

void Studentwork::showallcourse() {//获取显示所有课程，用于选课
	cout << "课程编号:" << "\t课程名称:" << "\t课程学分:" << endl;
	for (Course* p = schead->cnext; p != scend; p = p->cnext) {
		p->showcourse();//显示课程
	}
	int _getch(void);
	system("pause");
}

void Studentwork::choosecourse() {//添加选择课程到成绩文本
	int A = 1;
	while (A == 1) {
		cout << "请填写选课信息";
		ssend->sinputcourse();
		ssend->ssnext = new Student;
		ssend = ssend->ssnext;
		cout << "添加成功!" << endl;
		cout << " 继续添加吗?1是确定，0是否定";
		cin >> A;
		if (A != 1) {
			if (A == 0) { break; }
			else {
				cout << "错误，请重输：";
				cin >> A;
			}
		}
	}
	int _getch(void);
	system("pause");
}

// 删除信息
void Studentwork::sremovecourse() {//学生退选课到成绩文本
	char name[50],ke[50];
	cout << "请输入要删除的学生的姓名和课程:" << endl;
	cin >> name;
	cin >> ke;
	if (sfindsname(name)) {
		for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext)
			if ((!strcmp(pp->ssnext->sname, name))&&(!strcmp(pp->ssnext->scourse.cname,ke))) {
				Student* temp = NULL;
				int A;
				temp = pp->ssnext;
				pp->ssnext = pp->ssnext->ssnext;
				cout << "确定删除吗？1是确定，0是否定" << endl;
				cout << "请输入：";
				cin >> A;
				if (A == 1) {
					delete temp;
					cout << "删除成功!" << endl;
				}
				else cout << "删除失败" << endl;
				int _getch(void);
				system("pause");
			}
	}
	else {
		cout << "没有找到!" << endl;
		int _getch(void);
		system("pause");
	}
}
