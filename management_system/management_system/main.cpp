/*
***********************************************************************
*  项目名称：通讯录管理系统
*  创建时间：2021/11/02
*  创建人：Sophon
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
#define MAX 1000
/*
***********************************************************************
*                   函数声明
***********************************************************************
*/
void PrintMenu();
void AddPerson(struct AddressBooks*);
void ShowPerson(struct AddressBooks*);

/*
***********************************************************************
*                   结构体定义
***********************************************************************
*/
//联系人结构体
struct Person
{
	std::string name;
	int gender;
	int age;
	std::string phone;
	std::string addr;

};
//通讯录结构体
struct AddressBooks
{
	struct Person personArray[MAX];
	int num;
};
/*
***********************************************************************
*                   主函数
***********************************************************************
*/
int main()
{
	//创建通讯录结构体变量
	AddressBooks abs;
	abs.num = 0;//初始化人数

	int select = 0;
	while (true)
	{
		PrintMenu();
		std::cin >> select;
		switch (select)
		{
		case 1:   //添加联系人
			AddPerson(&abs);
			break;
		case 2:   //显示联系人
			ShowPerson(&abs);
			break;
		case 3:	  //删除联系人
			break;
		case 4:	  //查找联系人
			break;
		case 5:   //修改联系人 
			break;
		case 6:   //清空联系人
			break;
		case 0:   //退出通讯录
			std::cout << "欢迎下次继续使用本系统" << std::endl;
			system("pause");
			break;
		default:
			std::cout << "错误！！！！！" << std::endl << "请重新输入" << std::endl;

			break;
		}
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
	//判断通讯录是否还有空间
	if (abs->num == MAX)
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