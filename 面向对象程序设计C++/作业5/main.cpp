/*�������ҵ���� �� 7�µ�2�� ��c07_02���Ļ����ϣ�����һЩ���ܡ�
��1����Ϣ��ѯ   ���磬���֤�ţ����������ȣ�������Ӧ����Ա�Ƿ���ڡ��������ڣ�����ʾδ�ҵ���
������ʾ����Ա��������Ϣ��
��2��ɾ�����ҵ�ĳһ�����  �� 
��3��ֻ��ʾ�����е�ѧ������Ϣ��������Ա����Ϣ����ʾ 
��4�����������ҳ��ֳ�����ĳ������ֵ��ѧ��������ʾ������  ע�⣬Ϊ��ʵ����Ӧ�Ĺ��ܣ����޸Ļ�������ݳ�Ա��
*/

#include<iostream>
#include<string>
#include"PERSON.h"
#include"Prof.h"
#include"Staff.h"
#include"Student.h"
using namespace std;

int main()
{
	//7.2 test
	PERSON* p = new PERSON(); //����ͷ���
	//����4����
	p->insert(p);
	p->insert(p);
	p->insert(p);
	p->insert(p);
	//����,��һ�����ڵģ��ٲ�һ�������ڵ�
	p->search();
	p->search();
	//ɾ��һ����
	p->del(p);
	//��ʾѧ����Ϣ
	p->showStudent0();
	//��ʾ�ض�ѧ����Ϣ,����60�־����
	p->showStudentR0(60);
	return 0;
}
