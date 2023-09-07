// ConsoleApplication44.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>	
using namespace std;

class Student
{
	char* name;
	char* email;
	int age;
public:
	Student()
	{
		cout << "Constructor by def.\n";
		name = nullptr;
		email = nullptr;
		age = 0;
	}
	Student(const char* n, const char* _email, int a)// Oleg 20
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);
		email = new char[strlen(_email) + 1];
		strcpy_s(email, strlen(_email) + 1, _email);	
		age = a;
		cout << "Constructor 3 params\n";
	}
	void Input()
	{
		char buff[20];
		char SecondBuff[35];	
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cout << "Enter email: ";
		cin >> SecondBuff;	
		if (email != nullptr) 
		{
			cout << "Delete -> " << email << "... \n";	
			delete[] email;	
		}
		email = new char[strlen(SecondBuff) + 1];
		strcpy_s(email, strlen(SecondBuff) + 1, SecondBuff);	

		cout << "Enter age: ";
		cin >> age;
	}
	char* GetName()
	{
		char BuffName[20];
		cout << "Enter name: ";
		cin >> BuffName;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[] name;
		}
		name = new char[strlen(BuffName) + 1];
		strcpy_s(name, strlen(BuffName) + 1, BuffName);

		return name;
	}
	char* GetEmail()
	{
		char BufferEmail[40];
		cout << "Enter email: ";	
		cin >> BufferEmail;
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[] email;
		}
		email = new char[strlen(BufferEmail) + 1];
		strcpy_s(email, strlen(BufferEmail) + 1, BufferEmail);

		return email;	
	}
	int GetAge()
	{
		int NewAge;
		cout << "Enter age: ";
		cin >> NewAge;
		age = NewAge;

		return age;
	}
	void SetName()	
	{
		char buff[20];
		cout << "Enter name: ";	
		cin >> buff;	
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[] name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
	}
	void  SetEmail()
	{
		char buff[20];
		cout << "Enter email: ";
		cin >> buff;	
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";	
			delete[] email;
		}
		email = new char[strlen(buff) + 1];	
		strcpy_s(email, strlen(buff) + 1, buff);	
	}	
	void SetAge()		
	{
		int newAge;	
		cout << "Enter age: ";	
		cin >> newAge;	
		age = newAge;	
	}	
	void Print()
	{
		cout << "Name: " << name << "\tEmail: " << email << "\tAge: " << age << endl;		
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта !!!!
		delete[] email;	
		cout << "Destructor\n";
	}

	/* добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * удаление выделенной динамической памяти в деструкторе.
	*/

};

int main()
{
	Student obj1("Alexandr", "alexandr.unit@gmai.com", 18);		
	char* buffName;
	char* buffEmail;
	int newAge;
	obj1.Input();	
	obj1.Print();
	cout << "---------" << endl;
	cout << "Getter: " << endl;	
	buffName = obj1.GetName();
	cout << "Name: " << buffName << endl;	
	buffEmail = obj1.GetEmail();
	cout << "Email: " << buffEmail << endl;	
	newAge = obj1.GetAge();
	cout << "Number: " << newAge << endl;
	cout << "---------" << endl;
	cout << "Setter: " << endl;	
	obj1.SetName();
	obj1.SetEmail();
	obj1.SetAge();	
	obj1.Print();	

}	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
