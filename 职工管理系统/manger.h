#pragma once
#include<iostream>
#include"worker.h"
using namespace std;


class Manger :public Worker 
{
public:
	//构造函数
	Manger(int id, string name, int dId);//属性初始化
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位名称
	virtual string getDeptName();


};