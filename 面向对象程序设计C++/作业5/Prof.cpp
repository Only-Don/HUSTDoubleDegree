#include"Prof.h"
#include<string>
#include<iostream>
#include"PERSON.h"
using namespace std;
Prof::Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_) :
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, salary{ salary_ }, interest{ interest_ }
{

}

void Prof::print()
{
	//��ӡ���������䡢��ᱣ�պš����ʺ��о�����
	cout << "������" << name << endl;
	cout << "���䣺" << age << endl;
	cout << "��ᱣ�պţ�" << insurance << endl;
	cout << "���ʣ�" << salary << endl;
	cout << "�о�����" << interest << endl;
}