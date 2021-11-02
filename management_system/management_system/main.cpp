/*
***********************************************************************
*  ��Ŀ���ƣ�ͨѶ¼����ϵͳ
*  ����ʱ�䣺2021/11/02
*  �����ˣ�Sophon
*********************************************************************** 
*/

/*
***********************************************************************
*                   ͷ�ļ�����
***********************************************************************
*/
#include<iostream>
#include<string>
/*
***********************************************************************
*                   �궨��
***********************************************************************
*/
#define MAX 1000
/*
***********************************************************************
*                   ��������
***********************************************************************
*/
void PrintMenu();
void AddPerson(struct AddressBooks*);
void ShowPerson(struct AddressBooks*);

/*
***********************************************************************
*                   �ṹ�嶨��
***********************************************************************
*/
//��ϵ�˽ṹ��
struct Person
{
	std::string name;
	int gender;
	int age;
	std::string phone;
	std::string addr;

};
//ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person personArray[MAX];
	int num;
};
/*
***********************************************************************
*                   ������
***********************************************************************
*/
int main()
{
	//����ͨѶ¼�ṹ�����
	AddressBooks abs;
	abs.num = 0;//��ʼ������

	int select = 0;
	while (true)
	{
		PrintMenu();
		std::cin >> select;
		switch (select)
		{
		case 1:   //�����ϵ��
			AddPerson(&abs);
			break;
		case 2:   //��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3:	  //ɾ����ϵ��
			break;
		case 4:	  //������ϵ��
			break;
		case 5:   //�޸���ϵ�� 
			break;
		case 6:   //�����ϵ��
			break;
		case 0:   //�˳�ͨѶ¼
			std::cout << "��ӭ�´μ���ʹ�ñ�ϵͳ" << std::endl;
			system("pause");
			break;
		default:
			std::cout << "���󣡣�������" << std::endl << "����������" << std::endl;

			break;
		}
	}
	return 0;
	system("pause");
}

/*
***********************************************************************
*                   �˵���ӡ����
***********************************************************************
*/
void PrintMenu()
{
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "***************               1:�����ϵ��              **********************" << std::endl;
	std::cout << "***************               2:��ʾ��ϵ��              **********************" << std::endl;
	std::cout << "***************               3:ɾ����ϵ��              **********************" << std::endl;
	std::cout << "***************               4:������ϵ��              **********************" << std::endl;
	std::cout << "***************               5:�޸���ϵ��              **********************" << std::endl;
	std::cout << "***************               6:�����ϵ��              **********************" << std::endl;
	std::cout << "***************               0:�˳�ͨѶ¼              **********************" << std::endl;
	std::cout << "******************************************************************************" << std::endl;
}

/*
***********************************************************************
*                   �����ϵ��
***********************************************************************
*/

void AddPerson(AddressBooks* abs)
{
	int temp = 1;
	//�ж�ͨѶ¼�Ƿ��пռ�
	if (abs->num == MAX)
	{
		std::cout << "ͨѶ¼�������޷����" << std::endl;
		return;
	}
	else
	{
		while (temp != 0)
		{
			//����
			std::cout << "��������ϵ������:";
			std::cin >> abs->personArray[abs->num].name;

			//�Ա�
			int sex = 0;
			std::cout << "��������ϵ���Ա�0����Ů��1�����У���";
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
					std::cout << "�����������������:" << std::endl;
				}
			}

			//��������
			int age;
			std::cout << "��������ϵ�����䣺";
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
					std::cout << "����������������룺";
				}
			}
			//����绰����
			std::string phone_number;
			std::cout << "��������ϵ�˵绰���룺";
			std::cin >> phone_number;
			abs->personArray[abs->num].phone = phone_number;

			//�����ַ
			std::string address;
			std::cout << "��������ϵ�˵�ַ��";
			std::cin >> address;
			abs->personArray[abs->num].addr = address;

			//��Ϣ����
			abs->num++;//��־�Ѿ������һλ��ϵ��
			std::cout << "��ӳɹ��������������ּ�����"<<std::endl;
			std::cout << "�˳�������0��";
			std::cin >> temp;
			std::cout << std::endl;
		}
	}
	system("pause");
	system("cls");//����

}
/*
***********************************************************************
*                   ��ʾ��ϵ��
***********************************************************************
*/
void ShowPerson(AddressBooks *abs)
{
	if (abs->num > 0)
	{
		for (int i = 0; i < abs->num; i++)
		{
			std::cout << "����:" << abs->personArray[i].name<<"\t\t"
				<< "�Ա�:" << (abs->personArray[i].gender==0? "Ů" : "��") <<"\t"
				<< "����:" << abs->personArray[i].age << "\t"
				<< "�绰����:" << abs->personArray[i].phone << "\t\t\t"
				<< "��ַ:" << abs->personArray[i].addr << "\t\t"
				<< std::endl;
		}
	}
	else
	{
		std::cout << "��ѯ����������Ϊ�գ�";
	}
	system("pause");
	system("cls");
}