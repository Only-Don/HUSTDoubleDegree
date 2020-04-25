#include"PERSON.h"
#include"Staff.h"
#include"Student.h"
#include"Prof.h"
#include<string>
#include<iostream>
using namespace std;
PERSON::PERSON(string name_, int id_)
{
	name = name_;
	id = id_;
	next = nullptr;
}

void PERSON::print()
{
	cout << "������" << name << endl;
	cout << "���֤�ţ�" << id << endl;
}

//������:����ͷ���
void PERSON::insert(PERSON* p)
{
	cout << "����ѧ������1����ʦ����2����ְ������3:" << endl;
	int num;
	cin >> num;

	string name_;
	int id_;
	int age_;
	int insurance_;
	int grade_;
	double avg_;
	double salary_;
	string interest_; //�о�����

	PERSON* t;

	switch (num)
	{
	case 1:
		//string name_, int id_, int age_, int insurance_, int grade_, double avg_
		cout << "������ѧ��������";
		cin >> name_;
		cout << "������ѧ�����֤��";
		cin >> id_;
		cout << "������ѧ�����䣺";
		cin >> age_;
		cout << "��������ᱣ�պţ�";
		cin >> insurance_;
		cout << "������ѧ���꼶��";
		cin >> grade_;
		cout << "������ѧ��ƽ���ɼ���";
		cin >> avg_;
		t = new Student{ name_,id_,age_,insurance_,grade_,avg_ };
		t->next = p->next;
		p->next = t;
		cout << "����ѧ���ɹ�!\n";
		break;
	case 2:
		cout << "��������ʦ������";
		cin >> name_;
		cout << "��������ʦ���֤��";
		cin >> id_;
		cout << "��������ʦ���䣺";
		cin >> age_;
		cout << "��������ᱣ�պţ�";
		cin >> insurance_;
		cout << "��������ʦ���ʣ�";
		cin >> salary_;
		cout << "��������ʦ�о�����";
		cin >> interest_;
		t = new Prof{ name_,id_,age_,insurance_,salary_,interest_ };
		t->next = p->next;
		p->next = t;
		cout << "������ʦ�ɹ�\n";
		break;
	case 3:
		cout << "������ְ��������";
		cin >> name_;
		cout << "������ְ�����֤��";
		cin >> id_;
		cout << "������ְ�����䣺";
		cin >> age_;
		cout << "��������ᱣ�պţ�";
		cin >> insurance_;
		cout << "������ְ�����ʣ�";
		cin >> salary_;
		t = new Staff{ name_,id_,age_,insurance_,salary_ };
		t->next = p->next;
		p->next = t;
		cout << "����ְ���ɹ�\n";
		break;
	}
}

//ɾ�����
void PERSON::del(PERSON* p)
{
	cout << "��������Ҫɾ����������";
	string name_;
	cin >> name_;
	bool flag = false;
	PERSON* t = p;
	p = p->next;
	while (p)
	{
		if (p->name == name_)
		{
			flag = true;
			break;
		}
		t = t->next;
		p = p->next;
	}
	if (flag == true)
	{
		t->next = t->next->next;
		delete p;
		cout << "�ɹ�ɾ���ý��\n";
	}
	else
	{
		cout << "�����ڸýڵ�\n";
	}
	
}

void PERSON::search()
{
	cout << "��������Ҫ�����˵�������";
	string name_;
	cin >> name_;
	bool flag = false;
//	PERSON* t = p;
	PERSON* p = this->next;
	while (p)
	{
		if (p->name == name_)
		{
			flag = true;
			break;
		}
	//	t = t->next;
		p = p->next;
	}
	if (flag == true)
	{
		p->print();
	}
	else
	{
		cout << "û�ҵ������\n";
	}
}

void PERSON::showStudent0()
{
	PERSON* p = this->next;
	while (p)
	{
		p->showStudent();
		p = p->next;
	}
}

void PERSON::showStudent()
{

}

void PERSON::showStudentR0(double avg_)
{
	PERSON* p = this->next;
	while (p)
	{
		p->showStudentR(avg_);
		p = p->next;
	}
}

void PERSON::showStudentR(double avg_)
{
	
}