#include "mymanage.h"

void Teacher::showteacher() {//��ʾ��ʦ
	cout << tid << "\t" << tname << endl;
}

void Teacher::showteachercourse() {//��ʾ��ʦ���ڵĿγ�

	//cout <<  "ѧ��:"<< "\t����:" << "\tѡ�޿γ�:" << "\t\t�γ̳ɼ�:" << endl;
	cout << tid << "\t" << tname << "\t" << tcourse.cname << endl;
}

void Teacher::inputteacher() {//�����ӽ�ʦ
	cout << "�������ʦ��������"; cin >> tname;
	cout << "�������ʦ�ı�ţ�"; cin >> tid;
	cout << "�������ʦ���ڵĿγ̣�"; cin >> tcourse.cname;
}

void Teacher::readteacher(istream& in) {//��ȡ��ʦ�ı�

	in >> tid >> tname >> tcourse.cname ;

}
