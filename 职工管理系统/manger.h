#pragma once
#include<iostream>
#include"worker.h"
using namespace std;


class Manger :public Worker 
{
public:
	//���캯��
	Manger(int id, string name, int dId);//���Գ�ʼ��
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getDeptName();


};