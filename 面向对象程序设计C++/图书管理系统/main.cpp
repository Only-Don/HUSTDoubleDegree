#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<filesystem>
#include"Book.h"
#include<vector>
using namespace std;
int id;

void login(); //��ʼ��¼����
void addBook(); //���һ����
void deleteBook(); //ɾ��һ����
void Exit(); //�˳�����
void findBook(); //����һ����
void setInfo(); //�����鼮����Ϣ
void showData(); //��ʾȫ���鼮��Ϣ

//��ʼ��¼����
void login()
{
	system("cls");
	cout << setw(70) << "��ӭ����ͼ�����ϵͳ\n";
	cout << "��ѡ����Ҫ���Ĳ�����\n";
	cout << "0.�˳�ϵͳ\n";
	cout << "1.�鿴ϵͳ�������鼮\n";
	cout << "2.��ϵͳ�����һ����\n";
	cout << "3.��ϵͳ��ɾ��һ����\n";
	cout << "4.�����鼮��Ϣ\n";
	cout << "5.�����鼮\n";
}

//��ʾ�鼮��Ϣ
void showData()
{
	system("cls");
	vector<Book> v;
	ifstream fin("./book.txt");
	if (fin.fail())
	{
		cout << "���ļ�ʧ��\n";
		cin.get();
		cin.get();
		return;
	}

	string name;
	string isbn;
	double price;
	string author;
	int id_;
	bool flag;
	
	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_;
		fin >> flag;

		Book book{ name,isbn,price,author,id_ };
		book.setIsBorrow(flag);

		v.push_back(book);
	}
	cout << "һ��" << id << "����\n";
	cout << "ID��"
		<< setw(20) << "ͼ������"
		<< setw(20) << "ISBN��"
		<< setw(20) << "�鼮�۸�"
		<< setw(20) << "�鼮����"
		<< setw(20) << "�Ƿ񱻽���" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].id
			<< setw(20) << v[i].name
			<< setw(20) << v[i].isbn
			<< setw(20) << v[i].price
			<< setw(20) << v[i].author;

		if (v[i].isBorrow == true)
		{
			cout << setw(20) << "���" << endl;
		}
		else
		{
			cout << setw(20) << "�ɽ�" << endl;
		}
	}
	cin.get();
	cin.get();
}

//���ͼ��
void addBook()
{
	system("cls");
	string name;
	string isbn;
	double price;
	string author;
	cout << "������������";
	cin >> name;
	cout << "�������鼮��ISBN�ţ�";
	cin >> isbn;
	cout << "�������鼮�ļ۸�:";
	cin >> price;
	cout << "�������鼮������:";
	cin >> author;
	id++;
	Book book{ name,isbn,price,author,id };
	//����ID
	ofstream fout("./ID.txt", ios::out);
	fout << id;
	fout.close();

	book.writeData();
}

//ɾ��ͼ��
void deleteBook()
{
	system("cls");
	int id_;
	cout << "����������Ҫɾ����ͼ��id:";
	cin >> id_;
	ifstream fin("./book.txt");

	vector<Book> v;

	string name;
	string isbn;
	double price;
	string author;
	int id_read;
	bool isBorrow_;

	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_read;
		fin >> isBorrow_;
		Book book{ name,isbn,price,author,id_read };
		book.setIsBorrow(isBorrow_);

		if (id_ == id_read)
		{
			continue;
		}
		else
		{
			v.push_back(book);
		}		
	}
	fin.close();

	//����ID
	id--;
	ofstream fout1("./ID.txt", ios::out);
	fout1 << id;
	fout1.close();

	ofstream fout("./book.txt", ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << " " << v[i].name << " "
			<< v[i].isbn << " "
			<< v[i].price << " "
			<< v[i].author << " "
			<< i+1 << " "
			<< v[i].isBorrow;
	}
	fout.close();
}

//�����鼮
void findBook()
{
	system("cls");
	cout << "������Ҫ���ҵ��鼮������:";
	string name_;
	cin >> name_;

	ifstream fin("./book.txt");
	if (fin.fail())
	{
		cout << "���ļ�ʧ��\n";
		cin.get();
		cin.get();
		return;
	}

	vector<Book> v;

	string name;
	string isbn;
	double price;
	string author;
	int id_read;
	bool isBorrow_;

	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_read;
		fin >> isBorrow_;
		Book book{ name,isbn,price,author,id_read };
		book.setIsBorrow(isBorrow_);
		if (name == name_)
		{
			v.push_back(book);
		}
	}
	if (v.size() == 0)
	{
		cout << "û���ҵ��Ȿ��\n";
	}
	else
	{
		cout << "һ��" << v.size() << "����\n";
		cout << "ID��"
			<< setw(20) << "ͼ������"
			<< setw(20) << "ISBN��"
			<< setw(20) << "�鼮�۸�"
			<< setw(20) << "�鼮����"
			<< setw(20) << "�Ƿ񱻽���" << endl;

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].id
				<< setw(20) << v[i].name
				<< setw(20) << v[i].isbn
				<< setw(20) << v[i].price
				<< setw(20) << v[i].author;
			if (v[i].isBorrow == false)
			{
				cout << setw(20) << "�ɽ�\n";
			}
			else
			{
				cout << setw(20) << "���\n";
			}
		}
	}
	cin.get();
	cin.get();
}


//����ͼ����Ϣ
void setInfo()
{
	system("cls");
	int id_;
	cout << "��������Ҫ�޸ĵ����id:";
	cin >> id_;
	cout << "��ѡ����Ҫ�޸ĵ���Ϣ��\n";
	cout << "1.�޸�����\n";
	cout << "2.�޸�ISBN��\n";
	cout << "3.�޸ļ۸�\n";
	cout << "4.�޸�����\n";
	cout << "5.�޸Ľ���״̬\n";
	int choose;
	cin >> choose;

	ifstream fin("./book.txt");

	vector<Book> v;

	string name;
	string isbn;
	double price;
	string author;
	int id_read;
	bool isBorrow_;

	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_read;
		fin >> isBorrow_;
		Book book{ name,isbn,price,author,id_read };
		book.setIsBorrow(isBorrow_);
		if (id_read == id_)
		{
			cout << "��������Ҫ�ı������:";
			switch (choose)
			{
				case 1:
					cin >> name;
					book.setName(name);
					break;
				case 2:
					cin >> isbn;
					book.setIsbn(isbn);
					break;
				case 3:
					cin >> price;
					book.setPrice(price);
					break;
				case 4:
					cin >> author;
					book.setAuthor(author);
					break;
				case 5:
					cout << "(����0Ϊ�ɽ裬1Ϊ���)";
					bool flag;
					cin >> flag;
					book.setIsBorrow(flag);
					break;
			}
		}
		v.push_back(book);
	}
	fin.close();

	ofstream fout("./book.txt", ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << " " << v[i].name << " "
			<< v[i].isbn << " "
			<< v[i].price << " "
			<< v[i].author << " "
			<< i + 1 << " "
			<< v[i].isBorrow;
	}
	fout.close();
}

void Exit()
{
	system("cls");
	cout << "��ӭ�ٴ�ʹ�ñ�ϵͳ\n";
	exit(0);
}

int main()
{
	ifstream fin("./ID.txt", ios::in);
	fin >> id;
	fin.close();
	int choose;
	while (true)
	{
		login();
		cin >> choose;
		switch (choose)
		{
			case 0:
				Exit();
				break;
			case 1:
				showData();
				break;
			case 2:
				addBook();
				break;
			case 3:
				deleteBook();
				break;
			case 4:
				setInfo();
				break;
			case 5:
				findBook();
				break;
		}
	}
	return 0;
}
