/*
***********************************************************************
*  ��Ŀ���ƣ�ͨѶ¼����ϵͳ
*  ����ʱ�䣺2021/11/02
*  �����ˣ�Sophon
* ���Ż��ĵ� 
			1�����һ���������ݵĺ��������к��������ϵ�˵Ĳ��ֹ��ܣ����뿪�󷽱�������������
*		    2�����һ����ӡ��һ��ϵ�˵ĺ���
*			3������ļ���ȡ�ʹ洢����
*			4�������ϵ�˲���Ҫ����ȫ�����ݣ����ñ�����д��ͷǱ�����
*           5�����Ƴ�����߼�
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
#define MAX 1000//��ͨѶ¼���洢������
/*
***********************************************************************
*                   ��������
***********************************************************************
*/
void PrintMenu();
void AddPerson(struct AddressBooks*);			//�����ϵ��
void ShowPerson(struct AddressBooks*);			//��ʾ������ϵ��
void DeletePerson(struct AddressBooks*);		//ɾ����ϵ��
int isExist(struct AddressBooks*, std::string); //�����ϵ���Ƿ����
void SearchPerson(struct AddressBooks*);		//������ϵ��
void ModifyPerson(struct AddressBooks*);		//�޸���ϵ��
void CleanPerson(struct AddressBooks*);			//���������ϵ��

/*
***********************************************************************
*                   �ṹ�嶨��
***********************************************************************
*/
//��ϵ�˽ṹ��
struct Person
{
	std::string name; //����
	int gender;       //�Ա�
	int age;          //����
	std::string phone;//�绰����
	std::string addr; //��ַ

};
//ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person personArray[MAX];//��ϵ��
	int num;                       //��ϵ�˸���
};
/*
***********************************************************************
*                   ������
***********************************************************************
*/
int main()
{
	AddressBooks abs;	//����ͨѶ¼�ṹ�����
	abs.num = 0;        //��ʼ������

	int select = 0;     //��ʼ��ѡ������
	while (true)
	{
		PrintMenu();    //��ӡϵͳ�˵�����
		std::cin >> select;   //����ѡ������
		switch (select)       //switch��ѡ���� 
		{
		case 1:    //�����ϵ��
			AddPerson(&abs);
			break;
		case 2:    //��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3:	   //ɾ����ϵ��
			DeletePerson(&abs);
			break;
		case 4:	   //������ϵ��
			SearchPerson(&abs);
			break;
		case 5:    //�޸���ϵ�� 
			ModifyPerson(&abs);
			break;
		case 6:    //�����ϵ��
			CleanPerson(&abs);
			break;
		case 0:   //�˳�ͨѶ¼
			std::cout << "��ӭ�´μ���ʹ�ñ�ϵͳ" << std::endl;
			system("pause");

			break;
		default:
			std::cout << "���󣡣�������" << std::endl << "����������" << std::endl;
			break;
		}
		//break;
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
	std::cout << "***************               6:��ȡ��ϵ��              **********************" << std::endl;
	std::cout << "***************               6:�洢��ϵ��              **********************" << std::endl;
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
	if (abs->num == MAX)	//�ж�ͨѶ¼�Ƿ��пռ�
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

/*
***********************************************************************
*                       �����ϵ���Ƿ����
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
*                       ɾ����ϵ��
***********************************************************************
*/
void DeletePerson(AddressBooks* abs)
{
	std::string name;
	int temp = 1;
	while (temp != 0)
	{
		std::cout << "������Ҫɾ����ϵ�˵�������";
		std::cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1)
		{
			for (int i = ret; i < abs->num; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];

			}
			abs->num--;
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else
		{
			std::cout << "���޴���!!!" << std::endl;
		}
		std::cout << "�����������ּ�����" << std::endl;
		std::cout << "�˳�����������0��";
		std::cin >> temp;
	}
	system("pause");
	system("cls");
	
}

/*
***********************************************************************
*                       ������ϵ��
***********************************************************************
*/
void SearchPerson(AddressBooks* abs)
{
	std::string name;
	int temp = 1;
	while (temp != 0)
	{
		std::cout << "������Ҫ������ϵ�˵�������";
		std::cin >> name;
		int ret = isExist(abs, name);//�����abs���Ѿ���ָ���ˣ����Բ���ȡ��ַ
		if (ret != -1)
		{
			std::cout << "������" << abs->personArray[ret].name << "\t"
				<< "�Ա�:" << abs->personArray[ret].gender << "\t"
				<< "����:" << abs->personArray[ret].age << "\t"
				<< "�绰����:" << abs->personArray[ret].phone << "\t"
				<< "��ַ:" << abs->personArray[ret].addr << "\t"
				<< std::endl;
		}
		else
		{
			std::cout << "���޴���!!!" << std::endl;
		}
		std::cout << "�����������ּ���:" << std::endl;
		std::cout << "�˳�����������0��";
		std::cin >> temp;
	}
	system("pause");
	system("cls");


}

/*
***********************************************************************
*                       �޸���ϵ��
***********************************************************************
*/
void ModifyPerson(AddressBooks* abs)
{
	std::cout << "������Ҫ�޸���ϵ�˵�����:";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		std::cout << "������" << abs->personArray[ret].name << "\t"
			<< "�Ա�:" << abs->personArray[ret].gender << "\t"
			<< "����:" << abs->personArray[ret].age << "\t"
			<< "�绰����:" << abs->personArray[ret].phone << "\t"
			<< "��ַ:" << abs->personArray[ret].addr << "\t"
			<< std::endl;
		std::cout << "�������޸ĺ������(����-1����)��";
		std::cin >> name;
		abs->personArray[ret].name = name;
		std::cout << "������Ҫ�޸ĵ��Ա�(0����Ů  1������ )��";
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
			std::cout<<"�����������������:";
		}
		std::cout << "���������䣺";
		int age = 0;
		std::cin >> age;
		abs->personArray[ret].age = age;
		std::cout << "������绰���룺";
		std::string phone;
		std::cin >> phone;
		abs->personArray[ret].phone = phone;
		std::cout << "�������ַ";
		std::string  address;
		std::cin >> address;
		abs->personArray[ret].addr = address;

	}
	else
	{
		std::cout << "������󣬸���ϵ�˲�����";
	}

}
/*
***********************************************************************
*                       �����ϵ��
***********************************************************************
*/
void CleanPerson(AddressBooks* abs)
{
	std::cout << "ȷ��Ҫ�����ϵ����"<<std::endl;
	std::string temp ;
	std::cout << "ȷ�������ϵ��������\"iamsure\" ";
	std::cin >> temp;
	if (temp == "iamsure")
	{
		abs->num = 0;
		std::cout << "ͨѶ¼�Ѿ����"<<std::endl;
	}
	else
	{
		std::cout << "������󣡣�����"<<std::endl;
	}


}
