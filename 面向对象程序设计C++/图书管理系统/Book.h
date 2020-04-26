#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book {
public:
	string name;
	string isbn;
	double price;
	string author;
	int id;
	bool isBorrow;//�Ƿ񱻽���

	Book() = default;
	Book(string name_, string isbn_, double price_, string author_,int id_);
	
	void setName(string name_);
	string getName();
	
	void setIsbn(string isbn_);
	string getIsbn();

	void setPrice(double price_);
	double getPrice();

	void setAuthor(string author_);
	string getAuthor();

	void setId(int id_);
	int getId();

	void setIsBorrow(bool flag);
	bool getIsBorrow();

	//�����鼮��Ϣ
	void writeData();

	~Book();
};
