#pragma once//防止头文件重复包含
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
	//构造函数
	WorkerManger();
	//展示菜单函数
	void ShowMenu();
	//退出功能
	void Exitsystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray;
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空 标志
	bool  m_FileEmpty;
	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工
	void Show_Emp();
	//删除职工
	void Del_Emp();
	//判断职工是否存在 如果存在返回职工所在数组中的位置  不存在返回-1
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//按照编号排序职工
	void Sort_Emp();
	//清空文件
	void Clean_File();
	//析构函数
	~WorkerManger();
};