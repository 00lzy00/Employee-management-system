#include<iostream>
#include"manger.h"
using namespace std;
Manger::Manger(int id, string name, int dId)
{
	this->m_Id = id;//this�ɼӿɲ���
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾ������Ϣ
void Manger::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·��������ͨԱ��" << endl;

}
// ��ȡ��λ����
string Manger::getDeptName()
{
	return string("����");
}