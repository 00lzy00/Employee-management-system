#include<iostream>
#include"boss.h"
using namespace std;
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;//this�ɼӿɲ���
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;

}
// ��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}