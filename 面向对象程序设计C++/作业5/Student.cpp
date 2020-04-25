#include<string>
#include<iostream>
#include"Student.h"
#include"PERSON.h"
using namespace std;

Student::Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_) :
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, grade{ grade_ }, avg{ avg_ }
{

}

void Student::print()
{
	//���������塢��ᱣ�պš��꼶��ƽ���ɼ�
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "�꼶��" << grade << endl;
	cout << "ƽ���ɼ���" << avg << endl;
}

void Student::showStudent()
{
	//���������塢��ᱣ�պš��꼶��ƽ���ɼ�
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "�꼶��" << grade << endl;
	cout << "ƽ���ɼ���" << avg << endl;
}

//���Ʒ���
void Student::showStudentR(double avg_)
{
	if (avg > avg_)
	{
		//���������塢��ᱣ�պš��꼶��ƽ���ɼ�
		cout << "������" << name << endl;
		cout << "���䣺" << age << endl;
		cout << "��ᱣ�պţ�" << insurance << endl;
		cout << "�꼶��" << grade << endl;
		cout << "ƽ���ɼ���" << avg << endl;
	}
}