#include"mymanage.h"

void Course::readcourse(istream& in) {//��ȡ�γ��ı�

	in >> cid >> cname >> credit;
}

void Course::showcourse() {//��ʾ�γ�
	cout << cid << "\t" << cname << "\t\t" << credit << endl;
}

void Course::inputcourse() {//��ſγ�
	cout << "������γ̱�ţ�"; cin >> cid;
	cout << "������γ����ƣ�"; cin >> cname;
	cout << "������γ�ѧ�֣�"; cin >> credit;
}
