#pragma once
#include"PERSON.h"
#include<string>
using namespace std;
class Student : public PERSON {
private:
	int age;
	int insurance; //����
	int grade; //�꼶
	double avg; //ƽ���ɼ�

public:
	Student() = default;
	Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_);
	virtual void print();
	virtual void showStudent();
	virtual void showStudentR(double avg_);
};