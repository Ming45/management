#include"mymanage.h"

void Student::showstudent() {//��ʾѧ��
	cout << sid << "\t" << sname << endl;
}

void Student::showscore() {//��ʾѧ���ɼ�

	//cout <<  "ѧ��:"<< "\t����:" << "\tѡ�޿γ�:" << "\t\t�γ̳ɼ�:" << endl;
	cout << sid << "\t" << sname << "\t" << scourse.cname << "\t\t" << scourse.score << endl;
}

void Student::inputscore() {
	cout << "������ѧ����������"; cin >> sname;
	cout << "������ѧ����ѧ�ţ�"; cin >> sid;
	cout << "������ѧ��ѡ�޵Ŀγ̣�"; cin >> scourse.cname;
	cout << "������ѧ���γ̵ĳɼ���"; cin >> scourse.score;

}

void Student::inputstudent() {//���ѧ��
	cout << "������ѧ����������"; cin >> sname;
	cout << "������ѧ����ѧ�ţ�"; cin >> sid;
	cout << "������ѧ���İ༶��"; cin >> sclass;
	cout << "������ѧ����רҵ��"; cin >> major;
}

void Student::sinputcourse() {
	cout << "�������Լ���������"; cin >> sname;
	cout << "�������Լ���ѧ�ţ�"; cin >> sid;
	cout << "������ѧ��ѡ�޵Ŀγ̣�"; cin >> scourse.cname;

	scourse.score=-1;//�ɼ���Ϊ-1
	//	cout << "������ѧ������ɼ���"; cin >> phy;
	//	sum = math + phy + eng;
}

void Student::readscore(istream& in) {//��ȡ�ɼ��ı�

	in >> sid >> sname >> scourse.cname >> scourse.score;

}
void Student::readstudent(istream& in) {//��ȡѧ���ı�

	in >> sid >> sname >> sclass >> major;
}
