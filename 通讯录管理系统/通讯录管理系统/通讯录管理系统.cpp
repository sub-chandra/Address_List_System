#include <iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#define MAX 1000
using namespace std;
//显示菜单界面
void showMenu()
{
	cout << "□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□                                □□□" << endl;
	cout << "□□□  1、Add      a      Contact    □□□" << endl;
	cout << "□□□  2、Showing  the    Contect    □□□" << endl;
	cout << "□□□  3、Delete   a      Contect    □□□" << endl;
	cout << "□□□  4、Look     up     Contect    □□□" << endl;
	cout << "□□□  5、Modify   the    Contects   □□□" << endl;
	cout << "□□□  6、Empty    the    Contects   □□□" << endl;
	cout << "□□□  7、Logout   the    Contacts   □□□" << endl;
	cout << "□□□                                □□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□" << endl;
}
struct Person //联系人
{
	string m_name;//姓名
	int m_Sex;//性别
	int m_Age;//年龄
	string m_phone;//电话
	string m_Addr;//地址
};

struct AddressBooks//通讯录结构体
{
	Person peoArr[MAX];
	int m_Size;
};
//添加联系人
void addPerson(AddressBooks* abs)
{
	//从文件中读取
	ofstream ofs;
	ofs.open("通讯录管理系统.txt", ios::out);
	//判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "NOT ENOUGH SPACE" << endl;
		return;
	}
	else
	{
		string name;
		cout << "Please input a name:" << endl;
		cin >> name;
		ofs << name<<"\t";
		abs->peoArr[abs->m_Size].m_name = name;
		int sex;
		while (true)
		{
			cout << "Please input the sex: " << endl << "1——man" << endl << "2——woman" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
		    {
				abs->peoArr[abs->m_Size].m_Sex = sex;
				ofs << sex<<"\t";
			    break;
		     }
		    else
		    {
				cout << "The selection is wrong.     You can only input \"1\" or \"2\" " << endl;
		    }
		}
		int age;
		cout << "Please input the age:" << endl;
		cin >> age;
		ofs << age << "\t";
		abs->peoArr[abs->m_Size].m_Age = age;
		string phonum;
		
		cout << "Please input the phone number:"<<endl;
		cin >> phonum;
		abs->peoArr[abs->m_Size].m_phone = phonum;
		ofs << phonum << "\t";
		string adr;
		cout << "Please input the address:" << endl;
		cin >> adr;
		ofs << adr << "\t";
		abs->peoArr[abs->m_Size].m_Addr = adr;
		abs->m_Size++;
		ofs << adr << "\t";
		ofs.close();
		cout << "Added Successfully" << endl;
		_getch();
	}
}
//显示联系人
void showPerson(AddressBooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "The Record is Empty." << endl;
		_getch();
		system("pause");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "NAME:  " << abs->peoArr[i].m_name << "\t";
			cout << "SEX:   " << (abs->peoArr[i].m_Sex == 1 ?  "MAN":"WOMAN" ) << "\t";
			cout << "AGE:   " <<  abs->peoArr[i].m_Age  << "\t";
			cout << "PHONE:   " << abs->peoArr[i].m_phone << "\t";
			cout << "ADDRESS:   " << abs->peoArr[i].m_Addr << endl;
		}
	}
	_getch();
	system("cls");
}
//检测联系人存在
int idfExist(AddressBooks* abs)
{
	string name;
	cin >> name;
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->peoArr[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void deletePerson(AddressBooks* abs)
{
	cout << "Please input the name which you want to delete: " << endl;
	int ret=idfExist(abs);
	if (ret!=-1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->peoArr[i].m_name = abs->peoArr[i + 1].m_name;
			abs->peoArr[i].m_Age = abs->peoArr[i + 1].m_Age;
			abs->peoArr[i].m_Sex = abs->peoArr[i + 1].m_Sex;
			abs->peoArr[i].m_phone = abs->peoArr[i + 1].m_phone;
			abs->peoArr[i].m_Addr= abs->peoArr[i + 1].m_Addr;
		}
		abs->m_Size--;
		cout << "Delete Sucessfully" << endl;
		_getch();
		system("cls");
	}
	else
	{
		cout << "The name isn't in the contectbooks!" << endl;
		_getch();
		system("cls");
	}
}
//查找联系人
void lookUpPeoson(AddressBooks* abs)
{
	cout << "Please input the name you want to look up: ";
	int ret = idfExist(abs);
	if (ret != -1)
	{
		cout << "NAME:  " << abs->peoArr[ret].m_name << "\t";
		cout << "SEX:   " << (abs->peoArr[ret].m_Sex == 1 ? "MAN" : "WOMAN") << "\t";
		cout << "AGE:   " << abs->peoArr[ret].m_Age << "\t";
		cout << "PHONE:   " << abs->peoArr[ret].m_phone << "\t";
		cout << "ADDRESS:   " << abs->peoArr[ret].m_Addr << endl;
		_getch();
		system("cls");
	}
	else
	{
		cout << "The name isn't in the contectbooks!" << endl;
		_getch();
		system("cls");
	}
}
//修改联系人
void modifyPeoson(AddressBooks* abs)
{
	cout << "Please input the name you want to modify: ";
	int i=idfExist(abs);
	if (i != -1)
	{
		cout << "NAME:  " << abs->peoArr[i].m_name << "\t";
		cout << "SEX:   " << (abs->peoArr[i].m_Sex == 1 ? "MAN" : "WOMAN") << "\t";
		cout << "AGE:   " << abs->peoArr[i].m_Age << "\t";
		cout << "PHONE:   " << abs->peoArr[i].m_phone << "\t";
		cout << "ADDRESS:   " << abs->peoArr[i].m_Addr << endl;
		string name;
		cout << "Please input a name:" << endl;
		cin >> name;
		abs->peoArr[i].m_name = name;
		int sex;
		while (true)
		{
			cout << "Please input the sex: " << endl << "1——man" << endl << "2——woman" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->peoArr[i].m_Sex = sex;
				break;
			}
			else
			{
				cout << "The selection is wrong.     You can input \"1\" or \"2\" only." << endl;
			}
		}
		int age;
		cout << "Please input the age:" << endl;
		cin >> age;
		abs->peoArr[i].m_Age = age;
		string phonum;
		cout << "Please input the phone number:" << endl;
		cin >> phonum;
		abs->peoArr[i].m_phone = phonum;
		string adr;
		cout << "Please input the address:" << endl;
		cin >> adr;
		abs->peoArr[i].m_Addr = adr;
		cout << "Modify Successfully" << endl;
		_getch();
		system("cls");
	}
	else
	{
		cout << "The name isn't in the contectbooks!" << endl;
		_getch();
		system("cls");
	}
}
//清空联系人
void cleanUpPeoson(AddressBooks* abs)
{
	char par;
	cout << "ARE you sure to empty the contects ?     (Y/N)" << endl;
	cin >> par;
	if (par =='Y')
	{
		abs->m_Size = 0;
		cout << "The contects have been clean up." << endl;
		_getch();
		system("cls");
	}
	else
	{
		return;
	}
}
int main()
{
	system("color 03");//系统颜色
	int select = 0;
	AddressBooks abs;
	abs.m_Size = 0;
	while (true)
	{
		showMenu();//调用菜单
		cout << "Please chose the function button:";
		cin >> select;
		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs);
			break;
		case 2:  //显示联系人
			showPerson(&abs);
			break;
		case 3:  //删除联系人
			deletePerson(&abs);
			break;
		case 4:  //查找联系人
			lookUpPeoson(&abs);
			break;
		case 5:  //修改联系人
			modifyPeoson(&abs);
			break;
		case 6:  //清空联系人
			cleanUpPeoson(&abs);
			break;
		case 7:  //退出通讯录
			cout << "THE SYSTEM HAS LOGOUT" << endl;
			return 0;
			break;
		default :
			cout << "UNDERKNOW SELECTION" << endl<<"Pease input a function again.(1、2、3...)";
			Sleep(1000);
		}
		system("cls");
	}
	system("pause");
	return 0;
}