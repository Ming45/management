#include"mymanage.h"

Teacherwork::~Teacherwork() {//����������̬�ڴ�delete

	if (panduan[0] == 1) {//�ж��Ƿ�����˳ɼ��ı�����
		for (Student* temp; tshead->ssnext != tsend;) {//ɾȥtshead, tsend��ssnext��ָ
			temp = tshead->ssnext;
			tshead->ssnext = tshead->ssnext->ssnext;
			delete temp;
		}
		delete tshead, tsend;
	}

	if (panduan[1] == 1) {//�ж��Ƿ������ѧ���ı�����
		for (Student* temp; thead->snext != tend;) {//ɾȥthead, tend��snext��ָ
			temp = thead->snext;
			thead->snext = thead->snext->snext;
			delete temp;
		}
		delete thead, tend;
	}

	if (panduan[2] == 1) {//�ж��Ƿ�����˽�ʦ�ı�����
		for (Teacher* temp; tthead->tnext != ttend;) {
			temp = tthead->tnext;
			tthead->tnext = tthead->tnext->tnext;
			delete temp;
		}
		delete tthead, ttend;
	}

}
void Teacherwork::savescoretxt() {//����ɼ��ı�����tshead,tsend������
	outscore.open("sort.txt");
	if (outscore) {//�����ж�open�����Ƿ�ɹ�
		for (Student* p = tshead->ssnext; p != tsend; p = p->ssnext)
			outscore << p->sid << "\t" << p->sname << "\t" << p->scourse.cname << "\t" << p->scourse.score << '\n';
		outscore.close();//�ر��ļ�
	}
}
void  Teacherwork::getscoretxt() {//��ȡ�ɼ��ı�����tshead,tsend������
	panduan[0] = 1;//��������˳ɼ��ı��Ķ�ȡ
	tshead = new Student;//��̬�ڴ溯����������Զ�����
	tshead->ssnext = new Student;
	tsend = tshead->ssnext;
	inscore.open("sort.txt");//��ȡ
	if (!inscore)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {
		while (!inscore.eof()) {//û����β
			tsend->readscore(inscore);
			if (tsend->sname[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			tsend->ssnext = new Student;
			tsend = tsend->ssnext;
		}
		inscore.close();
		cout << "��ȡѧ���ɼ���Ϣ�ɹ�!" << endl;
	}
}

void Teacherwork::savestudenttxt() {//����ѧ���ı�����thead,tend������
	outstudent.open("sortstudent.txt");
	if (outstudent) {//�����ж�open�����Ƿ�ɹ�
		for (Student* p = thead->snext; p != tend; p = p->snext)
			outstudent << p->sid << "\t" << p->sname << "\t" << p->sclass << "\t" << p->major << '\n';
		outstudent.close();//�ر��ļ�
	}
}
void  Teacherwork::getstudenttxt() {//��ȡѧ���ı�����thead,tend������
	panduan[1] = 1;//���������ѧ���ı��Ķ�ȡ
	thead = new Student;//��̬�ڴ溯����������Զ�����
	thead->snext = new Student;//��snext��ȡ
	tend = thead->snext;
	instudent.open("sortstudent.txt");//��ȡ
	if (!instudent)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {
		while (!instudent.eof()) {//û����β
			tend->readstudent(instudent);
			if (tend->sname[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			tend->snext = new Student;
			tend = tend->snext;
		}
		instudent.close();
		cout << "��ȡѧ����Ϣ�ɹ�!" << endl;
	}
}

void Teacherwork::saveteachertxt() {//�����ʦ�ı�
	outteacher.open("sortteacher.txt");
	if (outteacher) {//�����ж�open�����Ƿ�ɹ�
		for (Teacher* p = tthead->tnext; p != ttend; p = p->tnext)
			outteacher << p->tid << "\t" << p->tname << "\t" << p->tcourse.cname << '\n';
		outteacher.close();//�ر��ļ�
	}
}
void  Teacherwork::getteachertxt() {//��ȡ��ʦ�ı�
	panduan[2] = 1;//��������˽�ʦ�ı��Ķ�ȡ
	tthead = new Teacher;//��̬�ڴ溯����������Զ�����
	tthead->tnext = new Teacher;
	ttend = tthead->tnext;
	inteacher.open("sortteacher.txt");//��ȡ
	if (!inteacher)
		cout << "����һ����ϵͳ���������롣" << endl;
	else {
		while (!inteacher.eof()) {//û����β
			ttend->readteacher(inteacher);
			if (ttend->tname[0] == '\0') {
				//end->scourse.pop_back();
				break;
			}
			ttend->tnext = new Teacher;
			ttend = ttend->tnext;
		}
		inteacher.close();
		cout << "��ȡѧ����Ϣ�ɹ�!" << endl;
	}
}


void Teacherwork::showallstudent() {//��ȡ��ʾ����ѧ������thead,tend������
	cout << "ѧ��:" << "\t����:" << endl;
	for (Student* p = thead->snext; p != tend; p = p->snext) {
		p->showstudent();//��ʾѧ��
	}
	int _getch(void);
	system("pause");
}
void Teacherwork::addscore() {//��ӳɼ�
	int A = 1;
	while (A == 1) {
		tsend->inputscore();
		tsend->ssnext = new Student;
		tsend = tsend->ssnext;
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
void Teacherwork::showstudentscore() {//��ȡ��ʾĿ��ѧ�����пγ̳ɼ��Լ��ܷ�
	char who[100];
	Student* p = NULL;
	int x = 0;
	cout << "��ѡ������������ѧ�Ų����޸�(1�������֣�2����ѧ��)";
	cin >> x;
	if (x == 1) {
		cout << "������Ҫ�޸ĵ��˵�����:";
		cin >> who;
		if (p = tfindsname(who)) {
			double zong = 0;//���ڼ����ܷ�
			cout << "���ҵ�ѧ������Ϣ�����Ŀγ̼��ɼ�����" << endl;
			for (Student* pp = tshead; pp->ssnext != tsend; pp = pp->ssnext) {
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
		cout << "������Ҫ�޸ĵ��˵�ѧ��:";
		cin >> who;
		if (p = tfindsid(who)) {
			double zong = 0;//���ڼ����ܷ�
			cout << "���ҵ�ѧ������Ϣ�����Ŀγ̼��ɼ�����" << endl;
			for (Student* pp = tshead; pp->ssnext != tsend; pp = pp->ssnext) {
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
void Teacherwork::modifyscore() {//�޸�ѧ������ĳ�γɼ�
	char who[100];
	Student* p = NULL;
	int x = 0;
	cout << "��ѡ������������ѧ�Ų����޸�(1�������֣�2����ѧ��)";
	cin >> x;
	if (x == 1) {
		cout << "������Ҫ�޸ĵ��˵�����:";
		cin >> who;
		if (p = tfindsname(who)) {
			cout << "���ҵ�ѧ������Ϣ��������ѡ����ѡ�޵Ŀγ�" << endl;
			char coursename[100];
			cin >> coursename;
			for (Student* pp = tshead; pp->ssnext != tsend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sname, who)) {//ȷ����Ŀ��ѧ��
					if (!strcmp(pp->ssnext->scourse.cname, coursename)) {//ȷ����ĳ�ſ�
						pp->ssnext->inputscore();
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
	else {
		cout << "������Ҫ�޸ĵ��˵�ѧ��:";
		cin >> who;
		if (p = tfindsid(who)) {
			cout << "���ҵ�ѧ������Ϣ��������ѡ����ѡ�޵Ŀγ�" << endl;
			char coursename[100];
			cin >> coursename;
			for (Student* pp = tshead; pp->ssnext != tsend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->sname, who)) {//ȷ����Ŀ��ѧ��
					if (!strcmp(pp->ssnext->scourse.cname, coursename)) {//ȷ����ĳ�ſ�
						pp->ssnext->inputscore();
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


Student* Teacherwork::tfindsname(char* name) {//��������ѧ��(�ɼ��ı�����tshead,ssnext....)
	for (Student* p = tshead; p->ssnext != tsend; p = p->ssnext)
		if (!strcmp(p->ssnext->sname, name))return p;//strcmp������string compare(�ַ����Ƚ�)����д�����ڱȽ������ַ��������ݱȽϽ������������
												  //������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�����
	return NULL;
}
Student* Teacherwork::tfindsid(char* Id) {//��ѧ����ѧ��(�ɼ��ı�����tshead,ssnext....)
	for (Student* p = tshead; p->ssnext != tsend; p = p->ssnext)
		if (!strcmp(p->ssnext->sid, Id))return p;
	return NULL;
}

Student* Teacherwork::tfindcnamesname(char* name, double high, double low) {//�ɿγ�����,�ɼ����ֵ���ɼ����ֵ   ��ѧ��(�ɼ��ı�����tshead,ssnext....)
	for (Student* p = tshead; p->ssnext != tsend; p = p->ssnext)
		if (!strcmp(p->ssnext->scourse.cname, name)) {
			if(low<=p->ssnext->scourse.score<=high)//����ڳɼ�������
				return p;
		}												
	return NULL;
}
Student* Teacherwork::tfindcidsid(char* id, double high, double low) {//�ɿγ̱��,�ɼ����ֵ���ɼ����ֵ   ��ѧ��(�ɼ��ı�����tshead,ssnext....)
	for (Student* p = tshead; p->ssnext != tsend; p = p->ssnext)
		if (!strcmp(p->ssnext->scourse.cid, id)) {
			if (low <= p->ssnext->scourse.score <= high)//����ڳɼ�������
				return p;
		}
	return NULL;
}

Student* Teacherwork::tfindclasssname(char* name) {//��ʦ�ɽ��ұ������(��ѧ���ı�)
	for (Student* p = thead; p->snext != tend; p = p->snext)
		if (!strcmp(p->snext->sclass, name))return p;
	return NULL;
}

Student* Teacherwork::tfindcourse(char* name) {//��ʦ�ɿγ�������ѡ���˵�ѧ��(�óɼ��ı�)
	for (Student* p = tshead; p->ssnext != tsend; p = p->ssnext)
		if (!strcmp(p->ssnext->scourse.cname, name))return p;
	return NULL;
}

void Teacherwork::showcoursestudent() {//����ĳ�ſγ̳ɼ�����ָ���������ڵ�ѧ���������ڳɼ��ı�����
	char who[100];
	double high = 0, low = 0;
	Student* p = NULL;
	int x = 0;
	cout << "��ѡ���ɿγ����ֻ��ǿγ̱�Ų����޸�(1�������֣�2����ѧ��)";
	cin >> x;
	if (x == 1) {
		cout << "������Ҫ���ҵĿγ�����:";
		cin >> who;
		cout << "������Ҫ���ҳɼ���Χ���ֵ:";
		cin >> high;
		cout << "������Ҫ���ҳɼ���Χ���ֵ:";
		cin >> low;
		if (p = tfindcnamesname(who,high,low)) {
			cout << "���ҵ��ÿγ̳ɼ���Χ��ѧ��" << endl;
			for (Student* pp = tshead; pp->ssnext != tsend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->scourse.cname, who)) {
					 if (low <= p->ssnext->scourse.score <= high){//����ڳɼ�������
						cout << "ѧ����" << pp->ssnext->sname << "\t�ɼ���" << pp->ssnext->scourse.score << endl;
					}
				}
			}
			int _getch(void);
			system("pause");
		}
		else {
			cout << "û���ҵ��ÿγ̳ɼ���Χ��ѧ��!" << endl;
			int _getch(void);
			system("pause");
		}
	}
	else {
		cout << "������Ҫ���ҵĿγ̱��:";
		cin >> who;
		cout << "������Ҫ���ҳɼ���Χ���ֵ:";
		cin >> high;
		cout << "������Ҫ���ҳɼ���Χ���ֵ:";
		cin >> low;
		if (p = tfindcidsid(who, high, low)) {
			cout << "���ҵ��ÿγ̳ɼ���Χ��ѧ��" << endl;
			for (Student* pp = tshead; pp->ssnext != tsend; pp = pp->ssnext) {
				if (!strcmp(pp->ssnext->scourse.cid, who)) {
					if (low <= p->ssnext->scourse.score <= high) {//����ڳɼ�������
						cout << "ѧ����" << pp->ssnext->sname << "\t�ɼ���" << pp->ssnext->scourse.score << endl;
					}
				}
			}
			int _getch(void);
			system("pause");
		}
		else {
			cout << "û���ҵ��ÿγ̳ɼ���Χ��ѧ��!" << endl;
			int _getch(void);
			system("pause");
		}
	}
}

//ͳ�������¼����
int Teacherwork::LC() {
	if (!tshead)
		return 0;
	int n = 0;
	for (Student* p = tshead->ssnext; p != tsend; p = p->ssnext) {
		n++;
	}
	return n;
}


void Teacherwork::swap(Student* p1, Student* p2) {//����Ϊ����ʱ��Ҫ�ĳɼ��ı��Ľ�������
	Student* temp = new Student;

	//���p1��temp
	strcpy_s(temp->sname, p1->sname); //����                   //strcpy_s��������p1->sname�ַ�����temp->sname
	strcpy_s(temp->sid, p1->sid);//ѧ��
	strcpy_s(temp->scourse.cname, p1->scourse.cname);//�γ�����
	temp->scourse.score=p1->scourse.score;//�γ̳ɼ�

	//��p2�ŵ�p1
	strcpy_s(p1->sname, p2->sname); //����                   
	strcpy_s(p1->sid, p2->sid);//ѧ��
	strcpy_s(p1->scourse.cname, p2->scourse.cname);//�γ�����
	p1->scourse.score = p2->scourse.score;//�γ̳ɼ�

	//��temp��p1�ŵ�p2
	strcpy_s(p2->sname, temp->sname); //����                   
	strcpy_s(p2->sid, temp->sid);//ѧ��
	strcpy_s(p2->scourse.cname, temp->scourse.cname);//�γ�����
	p2->scourse.score = temp->scourse.score;//�γ̳ɼ�
}



void Teacherwork::sortcourse() {

	Student* p = NULL;
	char which[50];//Ҫ�ҵĿγ�
	cout << "������Ҫ����Ŀγ̣�";
	cin >> which;
	if (p = tfindcourse(which)) {
		cout << "���ҵ�ѡ���˸��ſε�ѧ��" << endl;

		for (Student* pp = tshead->ssnext; pp != tsend; pp = pp->ssnext) {//�ӳɼ��ı����Ҷ�Ӧ�γ̵����֣��Ӷ��ҵ���ѧ���ɼ�
			if (!strcmp(pp->scourse.cname, which)) {//�ɼ��ı����ѧ��ѡ�޿γ̵����֣������ҵĿγ̵�����
				if (pp->scourse.score != -1) {//ȷ������-1��δ���Ե�

					for (Student* ppp = pp->ssnext; ppp != tsend; ppp = ppp->ssnext) {
						if (!strcmp(ppp->scourse.cname, which)) {
							if (ppp->scourse.score != -1) {

								if (ppp->scourse.score < pp->scourse.score) {//�����֮ǰ��С���򽻻�
									swap(ppp, pp);
								}
								//cout << "��ѡ���˸��ſγ̵�ѧ����" << ppp->ssnext->sname << "\t�ɼ���" <<  << endl;
							}
						}
					}

				}
			}
		}
		cout << "������ɣ�" << endl;
	}
	else {
		cout << "û���ҵ�ѡ���˸��ſε�ѧ��" << endl;
		int _getch(void);
		system("pause");
	}
}



void Teacherwork::countclass()//ͳ��ĳ�༶ѧ������ѧ���ĵ��Ƴɼ���
{
	Student* p = NULL;
	char which[50];//Ҫ�ҵİ༶
	cout << "������Ҫ�鿴�༶ͳ�Ƶİ༶�ţ�";
	cin >> which;
	if (p = tfindclasssname(which)) {
		cout << "���ҵ��ð༶" << endl;
		for (Student* pp = thead; pp->snext != tend; pp = pp->snext)//��ѧ���ı����Ұ༶
			if (!strcmp(pp->snext->sclass, which)) {//�ҵ��ð༶
				cout << "�ð༶��ѧ����" << pp->snext->sname << endl;
				double zong = 0;//���ڼ����ܷ�
				for (Student* ppp = tshead; ppp->ssnext != tsend; ppp = ppp->ssnext) {//�ӳɼ��ı����Ҷ�Ӧѧ�������֣��Ӷ��ҵ��ɼ�
					if (!strcmp(ppp->ssnext->sname, pp->snext->sname)) {//�ɼ��ı����ѧ�������֣�����ѧ���ı��ҵ�ѧ��������
						if (ppp->ssnext->scourse.score != -1) {//ȷ������-1��δ���Ե�
							cout << "\t\t�γ̣�" << ppp->ssnext->scourse.cname << "\t�ɼ���" << ppp->ssnext->scourse.score << endl;
							zong += ppp->ssnext->scourse.score;
						}
						else
							cout <<  "\t\t�γ̣�" << ppp->ssnext->scourse.cname << "\tδ�μӿ��ԣ��޳ɼ�" << endl;
					}
				}
				cout << "\t\t�ܷ�Ϊ��" << zong << "\n"<<endl;
				int _getch(void);
			}
	}
	else {
		cout << "û���ҵ��ð༶" << endl;
		int _getch(void);
		system("pause");
	}
}

void Teacherwork::countcourse()//ͳ��ĳ�γ̵�ѧ���ɼ����Լ�ƽ��ֵ������������
{
	Student* p = NULL;
	char which[50];//Ҫ�ҵĿγ�
	cout << "������Ҫ�鿴�Ŀγ�ͳ�ƣ�";
	cin >> which;
	double renshu = 0, zong = 0, jige = 0;
	if (p = tfindcourse(which)) {
		cout << "���ҵ�ѡ���˸��ſε�ѧ��" << endl;
		for (Student* ppp = tshead; ppp->ssnext != tsend; ppp = ppp->ssnext) {//�ӳɼ��ı����Ҷ�Ӧ�γ̵����֣��Ӷ��ҵ���ѧ���ɼ�
			if (!strcmp(ppp->ssnext->scourse.cname, which)) {//�ɼ��ı����ѧ��ѡ�޿γ̵����֣������ҵĿγ̵�����
				if (ppp->ssnext->scourse.score != -1) {//ȷ������-1��δ���Ե�
					renshu++;//��������һ
					cout << "��ѡ���˸��ſγ̵�ѧ����" << ppp->ssnext->sname << "\t�ɼ���" << ppp->ssnext->scourse.score << endl;
					zong += ppp->ssnext->scourse.score;
					if (ppp->ssnext->scourse.score >= 60)
						jige++;//����������һ
				}
				else
					cout << "��ѡ���˸��ſγ̵�ѧ����" << ppp->ssnext->sname << "\tδ�μӿ��ԣ��޳ɼ�" << endl;
			}
		}
		cout << "�μӿ��Ե���Ч������" << renshu << endl;
		cout << "ƽ���ɼ���" << zong / renshu << endl;
		cout << "�����ʣ�" << jige / renshu << endl;
	}
	else {
		cout << "û���ҵ�ѡ���˸��ſε�ѧ��" << endl;
		int _getch(void);
		system("pause");
	}

}