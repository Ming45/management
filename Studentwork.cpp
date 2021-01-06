#include"mymanage.h"

Studentwork::~Studentwork() {//����������̬�ڴ�delete
	if (panduan[0] == 1) {//�ж��Ƿ�����˳ɼ��ı�����
		for (Student* temp; sshead->ssnext != ssend;) {//ɾȥ�Գɼ�����ָ��
			temp = sshead->ssnext;
			sshead->ssnext = sshead->ssnext->ssnext;
			delete temp;
		}
		delete sshead, ssend;
	}

	if (panduan[1] == 1) {//�ж��Ƿ������ѧ���ı�����
		for (Student* temp; shead->snext != send;) {//ɾȥ��ѧ������ָ��
			temp = shead->snext;
			shead->snext = shead->snext->snext;
			delete temp;
		}
		delete shead, send;
	}

	if (panduan[2] == 1) {//�ж��Ƿ�����˿γ��ı�����
		for (Course* temp; schead->cnext != scend;) {//ɾȥ�Կγ̴���ָ��
			temp = schead->cnext;
			schead->cnext = schead->cnext->cnext;
			delete temp;
		}
		delete schead, scend;
	}
}
void Studentwork::savescoretxt() {//����ɼ��ı�����sshead,ssend������
	outscore.open("sort.txt");
	if (outscore) {//�����ж�open�����Ƿ�ɹ�
		for (Student* p = sshead->ssnext; p != ssend; p = p->ssnext)//��ͷָ��ĺ�һ��ssnext��βָ��
			outscore << p->sid << "\t" << p->sname << "\t" << p->scourse.cname << "\t" << p->scourse.score << '\n';
		outscore.close();//�ر��ļ�
	}
}
void  Studentwork::getscoretxt() {//��ȡ�ɼ��ı�����tshead,tsend������
	panduan[0] = 1;//��������˳ɼ��ı��Ķ�ȡ
	sshead = new Student;//�ȿ�һ��ͷָ��sshead��ָ��Student����
	sshead->ssnext = new Student;//ͷָ��ָ���ssnext��Ҳ������ָ��Student����
	ssend = sshead->ssnext;//��һ��βָ������ȡ�Ǹ�ssnext
	inscore.open("sort.txt");//��ȡ
	if (!inscore)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {

		while (!inscore.eof()) {//û����β
			ssend->readscore(inscore);//��ȡβָ�������
			if (ssend->sid[0] == '\0') {//���βָ�������������Ϊ0����û�ˣ��ͽ���
				//end->scourse.pop_back();
				break;
			}
			ssend->ssnext = new Student;//Ϊβָ��ָ���ssnext��һ��
			ssend = ssend->ssnext;//�ø���βָ��Ϊβָ��ָ���ssnext
		}
		inscore.close();
		cout << "��ȡѧ���ɼ���Ϣ�ɹ�!" << endl;
	}
}

void Studentwork::savestudenttxt() {//����ѧ���ı�����shead,send������
	outstudent.open("sortstudent.txt");
	if (outstudent) {//�����ж�open�����Ƿ�ɹ�
		for (Student* p = shead->snext; p != send; p = p->snext)
			outstudent << p->sid << "\t" << p->sname << "\t" << p->sclass << "\t" << p->major << '\n';
		outstudent.close();//�ر��ļ�
	}
}
void  Studentwork::getstudenttxt() {//��ȡѧ���ı�����thead,tend������
	panduan[1] = 1;//���������ѧ���ı��Ķ�ȡ
	shead = new Student;//��̬�ڴ溯����������Զ�����
	shead->snext = new Student;//��snext��ȡ
	send = shead->snext;
	instudent.open("sortstudent.txt");//��ȡ
	if (!instudent)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {
		while (!instudent.eof()) {//û����β
			send->readstudent(instudent);
			if (send->sid[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			send->snext = new Student;
			send = send->snext;
		}
		instudent.close();
		cout << "��ȡѧ����Ϣ�ɹ�!" << endl;
	}
}

void Studentwork::savecoursetxt() {//����γ��ı�
	outcourse.open("sortcourse.txt");
	if (outcourse) {//�����ж�open�����Ƿ�ɹ�
		for (Course* p = schead->cnext; p != scend; p = p->cnext)
			outcourse << p->cid << "\t" << p->cname << "\t" << p->credit << '\n';
		outcourse.close();//�ر��ļ�
	}
}
void  Studentwork::getcoursetxt() {//��ȡ�γ��ı�
	panduan[2] = 1;//��������˿γ��ı��Ķ�ȡ
	schead = new Course;//��̬�ڴ溯����������Զ�����
	schead->cnext = new Course;
	scend = schead->cnext;
	incourse.open("sortcourse.txt");//��ȡ
	if (!incourse) {
		cout << "����һ����ϵͳ���������롣" << endl;

	}
	else {
		while (!incourse.eof()) {//û����β
			scend->readcourse(incourse);
			if (scend->cid[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			scend->cnext = new Course;
			scend = scend->cnext;
		}
		incourse.close();
		cout << "��ȡѧ���ɼ���Ϣ�ɹ�!" << endl;
	}
}

Course* Studentwork::sfindcname(char* name) {//�������ҿγ�(�γ��ı�)
	for (Course* p = schead; p->cnext != scend; p = p->cnext)
		if (!strcmp(p->cnext->cname, name))return p;
	return NULL;
}
Course* Studentwork::sfindcid(char* Id) {//��ѧ���ҿγ�(�γ��ı�)
	for (Course* p = schead; p->cnext != scend; p = p->cnext)
		if (!strcmp(p->cnext->cid, Id))return p;
	return NULL;
}


Student* Studentwork::sfindsname(char* name) {//��������ѧ��(�ɼ��ı�����sshead,ssnext....)
	for (Student* p = sshead; p->ssnext != ssend; p = p->ssnext)
		if (!strcmp(p->ssnext->sname, name))return p;
	return NULL;
}
Student* Studentwork::sfindsid(char* Id) {//��ѧ����ѧ��(�ɼ��ı�����tshead,ssnext....)
	for (Student* p = sshead; p->ssnext != ssend; p = p->ssnext)
		if (!strcmp(p->ssnext->sid, Id))return p;
	return NULL;
}


void Studentwork::getstudentscore() {//��ȡ��ʾĿ��ѧ�����пγ̳ɼ�����sshead,ssend������
	char who[100];
	Student* p = NULL;
	int x = 0;
	cout << "��ѡ������������ѧ�Ų���(1�������֣�2����ѧ��)";
	cin >> x;
	if (x == 1) {
		cout << "������Ҫ���ҵ��˵�����:";
		cin >> who;
		if (p = sfindsname(who)) {
			double zong = 0;//���ڼ����ܷ�
			cout << "���ҵ�ѧ������Ϣ�����Ŀγ̼��ɼ�����" << endl;
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sname, who)) {
					if (pp->ssnext->scourse.score != -1) {
						cout << "�γ̣�" << pp->ssnext->scourse.cname << "\t�ɼ���" << pp->ssnext->scourse.score << endl;
						zong += pp->ssnext->scourse.score;
					}
					else
						cout << "�γ̣�" << pp->ssnext->scourse.cname << "\tδ�μӿ��ԣ��޳ɼ�" << endl;
				}
			}
			cout << "�ܷ�Ϊ��" << zong << endl;
			int _getch(void);
			system("pause");
		}
		else {
			cout << "û���ҵ�!" << endl;
			int _getch(void);
			system("pause");
		}
	}
	else {
		cout << "������Ҫ���ҵ��˵�ѧ��:";
		cin >> who;
		if (p = sfindsid(who)) {
			double zong = 0;//���ڼ����ܷ�
			cout << "���ҵ�ѧ������Ϣ�����Ŀγ̼��ɼ�����" << endl;
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sid, who)) {
					if (pp->ssnext->scourse.score != -1) {
						cout << "�γ̣�" << pp->ssnext->scourse.cname << "\t�ɼ���" << pp->ssnext->scourse.score << endl;
						zong += pp->ssnext->scourse.score;
					}
					else
						cout << "�γ̣�" << pp->ssnext->scourse.cname << "\tδ�μӿ��ԣ��޳ɼ�" << endl;
				}
			}
			cout << "�ܷ�Ϊ��" << zong << endl;
			int _getch(void);
			system("pause");
		}
		else {
			cout << "û���ҵ�!" << endl;
			int _getch(void);
			system("pause");
		}
	}
}

void Studentwork::getcoursecredit() {//��ȡ��ʾĿ��ѧ�����пγ�ѧ��
	char who[100];
	Student* p = NULL;
	int x = 0;
	cout << "��ѡ������������ѧ�Ų���(1�������֣�2����ѧ��)";
	cin >> x;
	if (x == 1) {
		cout << "������Ҫ���ҵ��˵�����:";
		cin >> who;
		if (p = sfindsname(who)) {
			cout << "���ҵ�ѧ������Ϣ�����Ŀγ̼�ѧ������" << endl;
			double zong = 0;//������������ѧ��
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {//�ҵ�ѧ��
				if (!strcmp(pp->ssnext->sname, who)) {//��ָ��Ķ����������Ŀ��ѧ������ʱ

					for (Course* pc = schead; pc != scend; pc = pc->cnext) {//�ҵ��γ�          ��ע���ж�ʱ����ֱ���ж�pc�Ƿ��е��ף�
						if (!strcmp(pp->ssnext->scourse.cname, pc->cname)) {//��ָ��Ķ���Ŀγ�����Ŀ��γ���ʱ
							cout << "�γ̣�" << pc->cname << "\tѧ�֣�" << pc->credit << endl;
							zong += pc->credit;
						}
					}
				}
			}
			cout << "������ѧ�֣�" << zong << endl;
			int _getch(void);
			system("pause");
		}
		else {
			cout << "û���ҵ�!" << endl;
			int _getch(void);
			system("pause");
		}
	}
	else {
		cout << "������Ҫ���ҵ��˵�ѧ��:";
		cin >> who;
		if (p = sfindsid(who)) {
			cout << "���ҵ�ѧ������Ϣ�����Ŀγ̼�ѧ������" << endl;
			for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sid, who)) {

					for (Course* pc = schead; pc != scend; pc = pc->cnext) {//�ҵ��γ�    ��ע���ж�ʱ����ֱ���ж�pc�Ƿ��е��ף�
						if (!strcmp(pp->ssnext->scourse.cname, pc->cname)) {//��ָ��Ķ���Ŀγ�����Ŀ��γ���ʱ
							cout << "�γ̣�" << pc->cname << "\tѧ�֣�" << pc->credit << endl;
						}
					}
				}
			}
			int _getch(void);
			system("pause");
		}
		else {
			cout << "û���ҵ�!" << endl;
			int _getch(void);
			system("pause");
		}
	}
}

void Studentwork::showallcourse() {//��ȡ��ʾ���пγ̣�����ѡ��
	cout << "�γ̱��:" << "\t�γ�����:" << "\t�γ�ѧ��:" << endl;
	for (Course* p = schead->cnext; p != scend; p = p->cnext) {
		p->showcourse();//��ʾ�γ�
	}
	int _getch(void);
	system("pause");
}

void Studentwork::choosecourse() {//���ѡ��γ̵��ɼ��ı�
	int A = 1;
	while (A == 1) {
		cout << "����дѡ����Ϣ";
		ssend->sinputcourse();
		ssend->ssnext = new Student;
		ssend = ssend->ssnext;
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

// ɾ����Ϣ
void Studentwork::sremovecourse() {//ѧ����ѡ�ε��ɼ��ı�
	char name[50],ke[50];
	cout << "������Ҫɾ����ѧ���������Ϳγ�:" << endl;
	cin >> name;
	cin >> ke;
	if (sfindsname(name)) {
		for (Student* pp = sshead; pp->ssnext != ssend; pp = pp->ssnext)
			if ((!strcmp(pp->ssnext->sname, name))&&(!strcmp(pp->ssnext->scourse.cname,ke))) {
				Student* temp = NULL;
				int A;
				temp = pp->ssnext;
				pp->ssnext = pp->ssnext->ssnext;
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
	}
	else {
		cout << "û���ҵ�!" << endl;
		int _getch(void);
		system("pause");
	}
}
