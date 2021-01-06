#include"mymanage.h"

Manage::~Manage() {//����������̬�ڴ�delete

	if (panduan[0] == 1) {//�ж��Ƿ������ѧ���ı�����
		for (Student* temp; mshead->snext != msend;) {
			temp = mshead->snext;
			mshead->snext = mshead->snext->snext;
			delete temp;
		}
		delete mshead, msend;
	}

	if (panduan[1] == 1) {//�ж��Ƿ�����˿γ��ı�����
		for (Course* temp; mchead->cnext != mcend;) {//ɾȥ�Կγ̴���ָ��
			temp = mchead->cnext;
			mchead->cnext = mchead->cnext->cnext;
			delete temp;
		}
		delete mchead, mcend;
	}

	if (panduan[2] == 1) {//�ж��Ƿ�����˽�ʦ�ı�����
		for (Teacher* temp; mthead->tnext != mtend;) {
			temp = mthead->tnext;
			mthead->tnext = mthead->tnext->tnext;
			delete temp;
		}
		delete mthead, mtend;
	}

}

void Manage::savestudenttxt() {//����ѧ���ı������µ��ı���
	outstudent.open("newsortstudent.txt");
	if (outstudent) {//�����ж�open�����Ƿ�ɹ�
		for (Student* p = mshead->snext; p != msend; p = p->snext)
			outstudent << p->sid << "\t" << p->sname << "\t" << p->sclass << "\t" << p->major << '\n';
		outstudent.close();//�ر��ļ�
	}
}
void  Manage::getstudenttxt() {//��ȡѧ���ı�
	panduan[0] = 1;//���������ѧ���ı��Ķ�ȡ
	mshead = new Student;//��̬�ڴ溯����������Զ�����
	mshead->snext = new Student;//��snext��ȡ
	msend = mshead->snext;
	instudent.open("sortstudent.txt");//��ȡ
	if (!instudent)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {
		while (!instudent.eof()) {//û����β
			msend->readstudent(instudent);
			if (msend->sname[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			msend->snext = new Student;
			msend = msend->snext;
		}
		instudent.close();
		cout << "��ȡѧ����Ϣ�ɹ�!" << endl;
	}
}

void Manage::savecoursetxt() {//����γ��ı������µ��ı���
	outcourse.open("newsortcourse.txt");
	if (outcourse) {//�����ж�open�����Ƿ�ɹ�
		for (Course* p = mchead->cnext; p != mcend; p = p->cnext)
			outcourse << p->cid << "\t" << p->cname << "\t" << p->credit << '\n';
		outcourse.close();//�ر��ļ�
	}
}
void  Manage::getcoursetxt() {//��ȡ�γ��ı�
	panduan[1] = 1;//��������˿γ��ı��Ķ�ȡ
	mchead = new Course;//��̬�ڴ溯����������Զ�����
	mchead->cnext = new Course;
	mcend = mchead->cnext;
	incourse.open("sortcourse.txt");//��ȡ
	if (!incourse) {
		cout << "����һ����ϵͳ���������롣" << endl;

	}
	else {
		while (!incourse.eof()) {//û����β
			mcend->readcourse(incourse);
			if (mcend->cid[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			mcend->cnext = new Course;
			mcend = mcend->cnext;
		}
		incourse.close();
		cout << "��ȡѧ���ɼ���Ϣ�ɹ�!" << endl;
	}
}
void Manage::saveteachertxt() {//�����ʦ�ı������µ��ı���
	outteacher.open("newsortteacher.txt");
	if (outteacher) {//�����ж�open�����Ƿ�ɹ�
		for (Teacher* p = mthead->tnext; p != mtend; p = p->tnext)
			outteacher << p->tid << "\t" << p->tname << "\t" << p->tcourse.cname << '\n';
		outteacher.close();//�ر��ļ�
	}
}
void Manage::getteachertxt() {//��ȡ��ʦ�ı�
	panduan[2] = 1;//��������˽�ʦ�ı��Ķ�ȡ
	mthead = new Teacher;//��̬�ڴ溯����������Զ�����
	mthead->tnext = new Teacher;
	mtend = mthead->tnext;
	inteacher.open("sortteacher.txt");//��ȡ
	if (!inteacher)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {
		while (!inteacher.eof()) {//û����β
			mtend->readteacher(inteacher);
			if (mtend->tname[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			mtend->tnext = new Teacher;
			mtend = mtend->tnext;
		}
		inteacher.close();
		cout << "��ȡѧ����Ϣ�ɹ�!" << endl;
	}
}

void Manage::addstudent() {//���ѧ��
	int A = 1;
	while (A == 1) {
		msend->inputstudent();
		msend->snext = new Student;
		msend = msend->snext;
		cout << "��ӳɹ�!" << endl;
		cout << " ���������?1��ȷ����0�Ƿ�";
		cin >> A;
		if (A != 1) {
			if (A == 0) { break; }
			else {
				cout << "���������䣺";
				cin >> A;
			}
		}
	}
	int _getch(void);
	system("pause");
}

void Manage::addteacher() {//��ӽ�ʦ
	int A = 1;
	while (A == 1) {
		mtend->inputteacher();
		mtend->tnext = new Teacher;
		mtend = mtend->tnext;
		cout << "��ӳɹ�!" << endl;
		cout << " ���������?1��ȷ����0�Ƿ�";
		cin >> A;
		if (A != 1) {
			if (A == 0) { break; }
			else {
				cout << "���������䣺";
				cin >> A;
			}
		}
	}
	int _getch(void);
	system("pause");
}
void Manage::addcourse() {//��ӿγ�
	int A = 1;
	while (A == 1) {
		mcend->inputcourse();
		mcend->cnext = new Course;
		mcend = mcend->cnext;
		cout << "��ӳɹ�!" << endl;
		cout << " ���������?1��ȷ����0�Ƿ�";
		cin >> A;
		if (A != 1) {
			if (A == 0) { break; }
			else {
				cout << "���������䣺";
				cin >> A;
			}
		}
	}
	int _getch(void);
	system("pause");
}

Student* Manage::mfindsname(char* name) {//��������ѧ��(ѧ���ı�)
	for (Student* p = mshead; p->snext != msend; p = p->snext)
		if (!strcmp(p->snext->sname, name))return p;
	return NULL;
}

Teacher* Manage::mfindtname(char* name) {//�������ҽ�ʦ(��ʦ�ı�)
	for (Teacher* p = mthead; p->tnext != mtend; p = p->tnext)
		if (!strcmp(p->tnext->tname, name))return p;
	return NULL;
}
Course* Manage::mfindcname(char* name) {//�������ҿγ�(�γ��ı�)
	for (Course* p = mchead; p->cnext != mcend; p = p->cnext)
		if (!strcmp(p->cnext->cname, name))return p;
	return NULL;
}

// ɾ����Ϣ
void Manage::mremovestudent() {//ɾ��ѧ����ѧ���ı�
	char name[20];
	Student* p = NULL, * temp = NULL;
	cout << "������Ҫɾ����ѧ��������:" << endl;
	cin >> name;
	if (p = mfindsname(name)) {
		int A;
		temp = p->snext;
		p->snext = p->snext->snext;
		cout << "ȷ��ɾ����1��ȷ����0�Ƿ�" << endl;
		cout << "�����룺";
		cin >> A;
		if (A == 1) {
			delete temp;
			cout << "ɾ���ɹ�!" << endl;
		}
		else cout << "ɾ��ʧ��" << endl;
		int _getch(void);
		system("pause");
	}
	else {
		cout << "û���ҵ�!" << endl;
		int _getch(void);
		system("pause");
	}
}

void Manage::mremoveteacher() {//ɾ����ʦ����ʦ�ı�
	char name[20];
	Teacher* p = NULL, * temp = NULL;
	cout << "������Ҫɾ����ѧ��������:" << endl;
	cin >> name;
	if (p = mfindtname(name)) {
		int A;
		temp = p->tnext;
		p->tnext = p->tnext->tnext;
		cout << "ȷ��ɾ����1��ȷ����0�Ƿ�" << endl;
		cout << "�����룺";
		cin >> A;
		if (A == 1) {
			delete temp;
			cout << "ɾ���ɹ�!" << endl;
		}
		else cout << "ɾ��ʧ��" << endl;
		int _getch(void);
		system("pause");
	}
	else {
		cout << "û���ҵ�!" << endl;
		int _getch(void);
		system("pause");
	}
}

void Manage::mremovecourse() {//ɾ���γ̵��γ��ı�
	char name[20];
	Course* p = NULL, * temp = NULL;
	cout << "������Ҫɾ����ѧ��������:" << endl;
	cin >> name;
	if (p = mfindcname(name)) {
		int A;
		temp = p->cnext;
		p->cnext = p->cnext->cnext;
		cout << "ȷ��ɾ����1��ȷ����0�Ƿ�" << endl;
		cout << "�����룺";
		cin >> A;
		if (A == 1) {
			delete temp;
			cout << "ɾ���ɹ�!" << endl;
		}
		else cout << "ɾ��ʧ��" << endl;
		int _getch(void);
		system("pause");
	}
	else {
		cout << "û���ҵ�!" << endl;
		int _getch(void);
		system("pause");
	}
}