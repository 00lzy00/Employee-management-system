#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;
class WorkerManger 
{
public:
	//���캯��
	WorkerManger();
	//չʾ�˵�����
	void ShowMenu();
	//�˳�����
	void Exitsystem();
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray;
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool  m_FileEmpty;
	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ��  �����ڷ���-1
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//���ձ������ְ��
	void Sort_Emp();
	//����ļ�
	void Clean_File();
	//��������
	~WorkerManger();
};