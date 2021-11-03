/*
***********************************************************************
*  项目名称：通讯录管理系统
*  创建时间：2021/11/02
*  创建人：Sophon
* 可优化的点 
			1：添加一个插入数据的函数，现有函数添加联系人的部分功能，分离开后方便其他函数调用
*		    2：添加一个打印单一联系人的函数
*			3：添加文件读取和存储功能
*			4：添加联系人不需要输入全部内容，设置必须填写项和非必须项
*           5：完善程序的逻辑
*********************************************************************** 
*/

/*
***********************************************************************
*                   头文件声明
***********************************************************************
*/
#include<iostream>
#include<string>
/*
***********************************************************************
*                   宏定义
***********************************************************************
*/
#define MAX 1000//该通讯录最多存储的人数
/*
***********************************************************************
*                   函数声明
***********************************************************************
*/
void PrintMenu();
void AddPerson(struct AddressBooks*);			//添加联系人
void ShowPerson(struct AddressBooks*);			//显示所以联系人
void DeletePerson(struct AddressBooks*);		//删除联系人
int isExist(struct AddressBooks*, std::string); //检查联系人是否存在
void SearchPerson(struct AddressBooks*);		//查找联系人
void ModifyPerson(struct AddressBooks*);		//修改联系人
void CleanPerson(struct AddressBooks*);			//清除所有联系人

/*
***********************************************************************
*                   结构体定义
***********************************************************************
*/
//联系人结构体
struct Person
{
	std::string name; //姓名
	int gender;       //性别
	int age;          //年龄
	std::string phone;//电话号码
	std::string addr; //地址

};
//通讯录结构体
struct AddressBooks
{
	struct Person personArray[MAX];//联系人
	int num;                       //联系人个数
};
/*
***********************************************************************
*                   主函数
***********************************************************************
*/
int main()
{
	AddressBooks abs;	//创建通讯录结构体变量
	abs.num = 0;        //初始化人数

	int select = 0;     //初始化选择命令
	while (true)
	{
		PrintMenu();    //打印系统菜单界面
		std::cin >> select;   //输入选择命令
		switch (select)       //switch，选择功能 
		{
		case 1:    //添加联系人
			AddPerson(&abs);
			break;
		case 2:    //显示联系人
			ShowPerson(&abs);
			break;
		case 3:	   //删除联系人
			DeletePerson(&abs);
			break;
		case 4:	   //查找联系人
			SearchPerson(&abs);
			break;
		case 5:    //修改联系人 
			ModifyPerson(&abs);
			break;
		case 6:    //清空联系人
			CleanPerson(&abs);
			break;
		case 0:   //退出通讯录
			std::cout << "欢迎下次继续使用本系统" << std::endl;
			system("pause");

			break;
		default:
			std::cout << "错误！！！！！" << std::endl << "请重新输入" << std::endl;
			break;
		}
		//break;
	}
	return 0;
	system("pause");
}

/*
***********************************************************************
*                   菜单打印函数
***********************************************************************
*/
void PrintMenu()
{
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "***************               1:添加联系人              **********************" << std::endl;
	std::cout << "***************               2:显示联系人              **********************" << std::endl;
	std::cout << "***************               3:删除联系人              **********************" << std::endl;
	std::cout << "***************               4:查找联系人              **********************" << std::endl;
	std::cout << "***************               5:修改联系人              **********************" << std::endl;
	std::cout << "***************               6:读取联系人              **********************" << std::endl;
	std::cout << "***************               6:存储联系人              **********************" << std::endl;
	std::cout << "***************               6:清空联系人              **********************" << std::endl;
	std::cout << "***************               0:退出通讯录              **********************" << std::endl;
	std::cout << "******************************************************************************" << std::endl;
}

/*
***********************************************************************
*                   添加联系人
***********************************************************************
*/

void AddPerson(AddressBooks* abs)
{
	int temp = 1;
	if (abs->num == MAX)	//判断通讯录是否还有空间
	{
		std::cout << "通讯录已满，无法添加" << std::endl;
		return;
	}
	else
	{
		while (temp != 0)
		{
			//姓名
			std::cout << "请输入联系人姓名:";
			std::cin >> abs->personArray[abs->num].name;

			//性别
			int sex = 0;
			std::cout << "请输入联系人性别（0代表女，1代表男）：";
			while (true)
			{
				std::cin >> sex;

				if (sex == 1 || sex == 0)
				{
					abs->personArray[abs->num].gender = sex;
					break;
				}
				else
				{
					std::cout << "输入错误，请重新输入:" << std::endl;
				}
			}

			//输入年龄
			int age;
			std::cout << "请输入联系人年龄：";
			while (true)
			{
				std::cin >> age;
				if (age >= 0 && age <= 100)
				{
					abs->personArray[abs->num].age = age;
					break;
				}
				else
				{
					std::cout << "输入错误，请重新输入：";
				}
			}
			//输入电话号码
			std::string phone_number;
			std::cout << "请输入联系人电话号码：";
			std::cin >> phone_number;
			abs->personArray[abs->num].phone = phone_number;

			//输入地址
			std::string address;
			std::cout << "请输入联系人地址：";
			std::cin >> address;
			abs->personArray[abs->num].addr = address;

			//信息处理
			abs->num++;//标志已经添加了一位联系人
			std::cout << "添加成功，输入任意数字继续！"<<std::endl;
			std::cout << "退出请输入0：";
			std::cin >> temp;
			std::cout << std::endl;
		}
	}
	system("pause");
	system("cls");//清屏

}
/*
***********************************************************************
*                   显示联系人
***********************************************************************
*/
void ShowPerson(AddressBooks *abs)
{
	if (abs->num > 0)
	{
		for (int i = 0; i < abs->num; i++)
		{
			std::cout << "姓名:" << abs->personArray[i].name<<"\t\t"
				<< "性别:" << (abs->personArray[i].gender==0? "女" : "男") <<"\t"
				<< "年龄:" << abs->personArray[i].age << "\t"
				<< "电话号码:" << abs->personArray[i].phone << "\t\t\t"
				<< "地址:" << abs->personArray[i].addr << "\t\t"
				<< std::endl;
		}
	}
	else
	{
		std::cout << "查询结束，数据为空！";
	}
	system("pause");
	system("cls");
}

/*
***********************************************************************
*                       检测联系人是否存在
***********************************************************************
*/
int isExist(AddressBooks* abs, std::string name)
{
	for (int i = 0; i < abs->num; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i;
		}

	}
	return -1;
}
/*
***********************************************************************
*                       删除联系人
***********************************************************************
*/
void DeletePerson(AddressBooks* abs)
{
	std::string name;
	int temp = 1;
	while (temp != 0)
	{
		std::cout << "请输入要删除联系人的姓名：";
		std::cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1)
		{
			for (int i = ret; i < abs->num; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];

			}
			abs->num--;
			std::cout << "删除成功" << std::endl;
		}
		else
		{
			std::cout << "查无此人!!!" << std::endl;
		}
		std::cout << "输入任意数字继续：" << std::endl;
		std::cout << "退出请输入数字0：";
		std::cin >> temp;
	}
	system("pause");
	system("cls");
	
}

/*
***********************************************************************
*                       查找联系人
***********************************************************************
*/
void SearchPerson(AddressBooks* abs)
{
	std::string name;
	int temp = 1;
	while (temp != 0)
	{
		std::cout << "请输入要查找联系人的姓名：";
		std::cin >> name;
		int ret = isExist(abs, name);//这里的abs是已经是指针了，所以不用取地址
		if (ret != -1)
		{
			std::cout << "姓名：" << abs->personArray[ret].name << "\t"
				<< "性别:" << abs->personArray[ret].gender << "\t"
				<< "年龄:" << abs->personArray[ret].age << "\t"
				<< "电话号码:" << abs->personArray[ret].phone << "\t"
				<< "地址:" << abs->personArray[ret].addr << "\t"
				<< std::endl;
		}
		else
		{
			std::cout << "查无此人!!!" << std::endl;
		}
		std::cout << "输入任意数字继续:" << std::endl;
		std::cout << "退出请输入数字0：";
		std::cin >> temp;
	}
	system("pause");
	system("cls");


}

/*
***********************************************************************
*                       修改联系人
***********************************************************************
*/
void ModifyPerson(AddressBooks* abs)
{
	std::cout << "请输入要修改联系人的姓名:";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		std::cout << "姓名：" << abs->personArray[ret].name << "\t"
			<< "性别:" << abs->personArray[ret].gender << "\t"
			<< "年龄:" << abs->personArray[ret].age << "\t"
			<< "电话号码:" << abs->personArray[ret].phone << "\t"
			<< "地址:" << abs->personArray[ret].addr << "\t"
			<< std::endl;
		std::cout << "请输入修改后的姓名(输入-1跳过)：";
		std::cin >> name;
		abs->personArray[ret].name = name;
		std::cout << "请输入要修改的性别(0代表女  1代表男 )：";
		int gender;
		std::cin >> gender;
		while (true)
		{
			std::cin >> gender;
			if (gender == 0 || gender == 1)
			{
				abs->personArray[ret].gender = gender;
				break;
			}
			std::cout<<"输入错误请重新输入:";
		}
		std::cout << "请输入年龄：";
		int age = 0;
		std::cin >> age;
		abs->personArray[ret].age = age;
		std::cout << "请输入电话号码：";
		std::string phone;
		std::cin >> phone;
		abs->personArray[ret].phone = phone;
		std::cout << "请输入地址";
		std::string  address;
		std::cin >> address;
		abs->personArray[ret].addr = address;

	}
	else
	{
		std::cout << "输入错误，该联系人不存在";
	}

}
/*
***********************************************************************
*                       清空联系人
***********************************************************************
*/
void CleanPerson(AddressBooks* abs)
{
	std::cout << "确定要清空联系人吗？"<<std::endl;
	std::string temp ;
	std::cout << "确定清空联系人请输入\"iamsure\" ";
	std::cin >> temp;
	if (temp == "iamsure")
	{
		abs->num = 0;
		std::cout << "通讯录已经清空"<<std::endl;
	}
	else
	{
		std::cout << "输入错误！！！！"<<std::endl;
	}


}
