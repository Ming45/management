#pragma once
#include<iostream>
#include <fstream>//���ļ��йص��������������
#include<sstream>///C++���Ĵ�������
#include<string>
#include<cmath>
using namespace std;

class Course {
public:
	char cname[50];//�γ�����
	char cid[50];//�γ̱��
	double credit;//ѧ��
	int ctime;//ѧʱ
	bool bixuanxiu;//��ѡ�����ʣ�1������ޣ�0����ѡ�ޣ�
	double score;//�ɼ�

	Course* cnext;////���ڱ�ĶԿγ̶���Ĵ���

	void showcourse();//��ʾ�γ�

	void inputcourse();//��ſγ�

	void readcourse(istream& in);//��ȡ�γ��ı�

};
class Major {
public:
	char mname[50];//רҵ����
	char mid[50];//רҵ���
	char bimajor[50];//���޿�
	double majorcredit;//רҵѧ��Ҫ��
};
class Student {//ѧ��ģ�飬     ���ݳ�Ա����ʾ����ţ���ȡ
public:
	char sname[50];//ѧ������
	char sid[50];//ѧ��ѧ��
	char sclass[50];//�༶
	char major[50];//רҵ
	Course scourse;//ѡ�޵Ŀγ�

	Student* snext;//���ڱ�Ķ�ѧ������Ĵ���
	Student* ssnext;//���ڱ�Ķ�ѧ���ɼ�����Ĵ���

	void showstudent();//��ʾѧ��
	void showscore();//��ʾ�ɼ�
	void inputscore();//��ųɼ�
	void inputstudent();//�����ѧ��

	void sinputcourse();//ѡ����ӿγ�

	void readscore(istream& in);//��ȡ�ɼ��ı��е�����
	void readstudent(istream& in);//��ȡѧ���ı��е�����

};
class Studentwork {//ѧ������ģ�飬   �����������ı�������
public:

	//Student() = default;//���캯��
	~Studentwork();//�������� ,ɾȥָ������


	Student* shead, * send;//��ѧ���Ĵ���  (����ѧ���ı�)

	Student* sshead, * ssend;//��ѧ���ɼ��Ĵ���  (����ɼ��ı�)

	Course* schead, * scend;//ѧ���Կγ̵Ĵ���  (����γ��ı�)

	ifstream instudent;//���ڶ�ѧ���ı����������
	ofstream outstudent;

	ifstream inscore;//���ڶԳɼ��ı����������
	ofstream outscore;

	ifstream incourse;//���ڶԿγ��ı����������
	ofstream outcourse;

	int panduan[4] = { 0 };//�����ж��Ƿ�������ı���������λ�����־λ��1��������ˣ�������������ʱѡ���Ƿ�ɾ��

	void getscoretxt();//¼��ѧ���ɼ��ı��Ľ��й���    ���ж�λ�ĵ�һλ��
	void savescoretxt();//�Ը��ĺ�ĳɼ��ı�����

	void getstudenttxt();//¼��ѧ���ı��Ľ��й���    ���ж�λ�ĵڶ�λ��
	void savestudenttxt();//�Ը��ĺ��ѧ���ı�����

	void getcoursetxt();//¼��γ��ı��Ľ��й���    ���ж�λ�ĵ���λ��
	void savecoursetxt();//�Ը��ĺ�Ŀγ��ı�����


	void getcoursecredit();//��ʾĳѧ�������пγ̵�ѧ���Լ�����ѧ��,����ѡ��

	void getstudentscore();//��ʾĳѧ�������пγ̳ɼ�


	void showallcourse();//��ʾ���пγ̼�ѧ�֣���ѧ��ѡ��
	void choosecourse();//ѧ��ѡ�����Ҫѡ�޵Ŀε�ѧ���ɼ��ı����ɼ�Ϊ-1

	void sremovecourse();//ѧ����ѡ�ε��ɼ��ı�

	Course* sfindcname(char* name);//�ɿγ������ҿγ�
	Course* sfindcid(char* id);//�ɿγ̱����ҿγ�

	Student* sfindsname(char* name);//��ѧ����������
	Student* sfindsid(char* id);//��ѧ��ѧ������
};

class Teacher {
public:
	char tname[50];//��ʦ����
	char tid[50];//��ʦ���
	Course tcourse;//���ڵĿγ�
	Teacher* tnext;//�����Խ�ʦ����Ĳ���

	void showteacher();//��ʾ��ʦ

	void showteachercourse();//��ʾ��ʦ���ڵĿγ�

	void inputteacher();//�����ӽ�ʦ

	void readteacher(istream& in);//��ȡ��ʦ�ı��е�����
};
class Teacherwork {
public:

	Teacherwork() = default;//���캯��
	~Teacherwork();//�������� ,ɾȥ��̬�ڴ��tshead, tsend��ssnext,thead, tend��snext��ָ

	int panduan[4] = { 0 };//�����ж��Ƿ�������ı���������λ�����־λ��1��������ˣ�������������ʱѡ���Ƿ�ɾ��

	Student* tshead, * tsend;//��ʦ��ѧ���ɼ�����Ĵ���  (����ɼ��ı�)

	Student* thead, * tend;//��ʦ��ѧ������Ĵ���  (����ѧ���ı�)

	Teacher* tthead, * ttend;//��ʦ�Խ�ʦ����Ĵ���  (�����ʦ�ı�)����ȡ�Լ����ڵĿγ̣�


	ifstream inscore;//���ڶԳɼ��ı����������
	ofstream outscore;

	ifstream instudent;//���ڶ�ѧ���ı����������
	ofstream outstudent;

	ifstream inteacher;//���ڶԽ�ʦ�ı����������
	ofstream outteacher;

	void getscoretxt();//¼��ѧ���ɼ��ı��Ľ��й���
	void savescoretxt();//�Ը��ĺ�ĳɼ��ı�����

	void getstudenttxt();//¼��ѧ���ı��Ľ��й���
	void savestudenttxt();//�Ը��ĺ��ѧ���ı�����

	void getteachertxt();//¼���ʦ�ı��Ľ��й���
	void saveteachertxt();//�Ը��ĺ�Ľ�ʦ�ı�����


	void showallstudent();//��ȡ��ʾ����ѧ��
	void showstudentscore();//��ѧ�����ֻ�ѧ�Ŷ�ȡ��ʾĿ��ѧ�����пγ̳ɼ��Լ��ܷ�
	void showcoursestudent();//����ĳ�ſγ̳ɼ�����ָ���������ڵ�ѧ������

	void addscore();//���¼��ѧ���ɼ�

	void modifyscore();//��ѧ�����ֻ�ѧ�������޸�ѧ������ĳ�γɼ�

	int LC();//ͳ�������¼����

	void countclass();//ͳ��ĳ�༶ѧ������ѧ���ĵ��Ƴɼ�
	void countcourse();//ͳ��ĳ�γ̵�ѧ���ɼ����Լ�ƽ��ֵ����׼�������
	void swap(Student*, Student*);//��������ʱ�Ľ���
	void sortcourse();//ĳ�γ̵�ѧ���ɼ���С��������


	Student* tfindsname(char* name);//��ʦ��ѧ����������
	Student* tfindsid(char* id);//��ʦ��ѧ��ѧ������

	Student* tfindcnamesname(char* name,double high,double low);//��ʦ�ɿγ����֣�,�ɼ����ֵ���ɼ����ֵ   ��ѧ������
	Student* tfindcidsid(char* id,  double high, double low);//��ʦ�ɿγ����֣�,�ɼ����ֵ���ɼ����ֵ   ��ѧ������

	Student* tfindclasssname(char* name);//��ʦ�ɽ��ұ������

	Student* tfindcourse(char* name);//��ʦ�ɿγ�������ѡ���˵�ѧ��

};

class Manage{
public:

	Manage() = default;//���캯��
	~Manage();//�������� ,ɾȥ��̬�ڴ��ָ����ָ

	int panduan[4] = { 0 };//�����ж��Ƿ�������ı���������λ�����־λ��1��������ˣ�������������ʱѡ���Ƿ�ɾ��

	Course* mchead, * mcend;//ϵͳ�Կγ̶���Ĵ���  (����γ��ı�)

	Student* mshead, * msend;//ϵͳ��ѧ������Ĵ���  (����ѧ���ı�)

	Teacher* mthead, * mtend;//ϵͳ�Խ�ʦ����Ĵ���  (�����ʦ�ı�)


	ifstream incourse;//���ڶԿγ��ı����������
	ofstream outcourse;

	ifstream instudent;//���ڶ�ѧ���ı����������
	ofstream outstudent;

	ifstream inteacher;//���ڶԽ�ʦ�ı����������
	ofstream outteacher;

	void getcoursetxt();//¼��γ��ı��Ľ��й���
	void savecoursetxt();//�Ը��ĺ�Ŀγ��ı�����

	void getstudenttxt();//¼��ѧ���ı��Ľ��й���
	void savestudenttxt();//�Ը��ĺ��ѧ���ı�����

	void getteachertxt();//¼���ʦ�ı��Ľ��й���
	void saveteachertxt();//�Ը��ĺ�Ľ�ʦ�ı�����

	void addstudent();//���¼��ѧ��
	void addteacher();//���¼���ʦ
	void addcourse();//���¼��γ�

	void mremovestudent();//��ѧ������ɾȥѧ����Ϣ
	void mremoveteacher();//�ɽ�ʦ����ɾȥ��ʦ��Ϣ
	void mremovecourse();//�ɿγ�����ɾȥ�γ���Ϣ

	Student* mfindsname(char* name);//��ѧ��������ѧ��
	Teacher* mfindtname(char* name);//�ɽ�ʦ�����ҽ�ʦ
	Course* mfindcname(char* name);//�ɿγ������ҿγ�
};
