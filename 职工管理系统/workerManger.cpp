#include<iostream>
#include"workerManger.h"
using namespace std;

WorkerManger::WorkerManger() 
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open()) 
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileEmpty = true;
		return;
	}
	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileEmpty = true;
		return;
	}
	//3.文件存在 并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据 存到数组中
	this->init_Emp();

	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< " 姓名：" << this->m_EmpArray[i]->m_Name
			<< " 部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}  */
}
void WorkerManger::ShowMenu() 
{
	cout << "*********************************" << endl;
	cout << "*******欢迎使用职工管理系统!*******" << endl;
	cout << "********* 0.退出管理程序 *********" << endl;
	cout << "********* 1.增加职工信息 *********" << endl;
	cout << "********* 2.显示职工信息 *********" << endl;
	cout << "********* 3.删除离职员工 *********" << endl;
	cout << "********* 4.修改职工信息 *********" << endl;
	cout << "********* 5.查找职工信息 *********" << endl;
	cout << "********* 6.按照编号排序 *********" << endl;
	cout << "********* 7.清空所有文档 *********" << endl;
	cout << "*********************************" << endl;
	cout << endl;

}

void WorkerManger::Exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}
void WorkerManger::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newsize = this->m_EmpNum + addNum;//新空间人数=原来记录人数+新增人数
		//开辟新空间
		Worker** newspace = new Worker * [this->m_EmpNum + addNum];//第一个*访问数组首地址 第二个*访问数组
		//将原来空间下数据 拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manger(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工职责 ，保存到数组中
			newspace[this->m_EmpNum + i] = worker;
		}
		  //释放原有空间
		delete[] this->m_EmpArray;

		//更新新空间的指向
		this->m_EmpArray = newspace;

		//更新新的职工人数
		this->m_EmpNum = newsize;

		//更新职工不为空标志
		this->m_FileEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;

		//保存数据到文件中
		this->save();

	}
		else
		{
			cout << "输入数据有误" << endl;
		}
	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");
}
void WorkerManger::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//将每个人的数据写入文件
	for (int i = 0; i < this->m_EmpNum; i++) 
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}
int WorkerManger:: get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);// 打开文件 读
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) 
	{
		//统计人数变量
		num++;
	}
	return num;
}
void WorkerManger::init_Emp() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);// 打开文件 读
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) //普通员工
		{
			worker = new Employee(id, name, dId);
		}
		if (dId == 2) //经理
		{
			worker = new Manger(id, name, dId);
		}
		else //老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;//维护数组
		index++;
	}
	//关闭文件
	ifs.close();
}
void WorkerManger::Show_Emp() 
{
	//判断文件是否为空
	if (this->m_FileEmpty) 
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else 
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//删除职工
void WorkerManger::Del_Emp()
{
	if (this->m_FileEmpty) 
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1) //说明职工存在，并且要删掉index位置上的职工
		{
			//数据前移
			for(int i=index;i<this->m_EmpNum-1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//判断职工是否存在 如果存在返回职工所在数组中的位置  不存在返回-1
int WorkerManger::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) 
	{
		if (this->m_EmpArray[i]->m_Id == id) 
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index; 
}
void WorkerManger::Mod_Emp() 
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else 
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret !=-1)
		{
			//查找到编号职工
			delete this->m_EmpArray[ret];//将原来数据清空
			int newid = 0;
			string newname = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新姓名：" << endl;
			cin >> newname;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newid ,newname, 1);
				break;
			case 2:
				worker = new Manger(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 3);
				break;
			default:
				break;
			}

			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else 
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
void WorkerManger::Find_Emp() 
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else 
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else 
			{
				cout << "查找失败！查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//加入判断是否查到的标志
			bool flag = false;//默认未找到
			for (int i = 0; i < m_EmpNum; i++) 
			{
				if (this->m_EmpArray[i]->m_Name == name) 
				{
					cout << "查找成功，职工编号为：" 
						<< this->m_EmpArray[i]->m_Id 
						<< "号职工信息如下：" << endl;

					flag = true;

					//调用显示信息函数
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) 
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
void WorkerManger::Sort_Emp() 
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;

		//按任意键后清屏
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax=i;//声明最小值 或 最大值下标
			for (int j = i+1; j < m_EmpNum; j++) 
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id) 
					{
						minOrmax = j;
					}
				}
				else //降序
				{
					if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}

			}
			//判断一开始认定 最小值或最大值 是不是计算的最小值最大值 如果不是 交换下标
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "排序成功！排序后的结果为：" << endl;
		this->save();//排序后结果保存到文件中
		this->Show_Emp();//展示所有职工
	}
}
void WorkerManger::Clean_File() 
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL) 
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
WorkerManger::~WorkerManger() 
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	 }
}
