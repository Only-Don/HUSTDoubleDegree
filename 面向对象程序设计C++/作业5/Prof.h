#pragma once
#include<string>
#include"PERSON.h"
using namespace std;
class Prof :public PERSON {
private:
	int age;
	int insurance; //����
	double salary;
	string interest; //�о�����

public:
	Prof() = default;
	Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_);
	virtual void print();
};