#include<iostream>
#include"workerManger.h"
//#include"employee.h"
//#include"worker.h"
//#include"manger.h"
//#include"boss.h"
using namespace std;


int main() 
{
	//测试代码
	/*Worker* worker = NULL;
	worker = new Employee(1,"张三",1);
	worker->showInfo();
	delete worker;

	worker = new Manger(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;*/
	//实例化管理者对象
	WorkerManger wm;
	int choice=0;//用来存储用户选项
	while (true)
	{
		//调用展示菜单成员函数
		wm.ShowMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;  //接受用户的选项

		switch (choice) 
		{
		case 0:
			wm.Exitsystem();
			break;
		case 1: //添加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
				break; 
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		case 7: //清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}

	}


	system("pause");
	return 0;
}