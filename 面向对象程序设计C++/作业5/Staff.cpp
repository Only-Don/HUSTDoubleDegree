#include<string>
#include<iostream>
#include"Staff.h"
#include"PERSON.h"
using namespace std;

Staff::Staff(string name_, int id_, int age_, int insurance_, double salary_) :
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, salary{ salary_ }
{

}

void Staff::print()
{
	//��ӡ���������䡢��ᱣ�պź͹���
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "���ʣ�" << salary << endl;
}