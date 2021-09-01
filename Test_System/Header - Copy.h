#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Класс Тестируемый
class User
{
	//ФИО
	char* name;
	//Домашний адрес
	char* homeAddress;
	//Телефон
	char* phoneNumber;
	//Login
	char* login;
	//Password
	char* password;
	
public:
	//Конструктор
	User(const char* name = nullptr, const char* homeAddress = nullptr,
		const char* phoneNumber = nullptr, const char* login = nullptr,
		const char* password = nullptr)
	{
		cout << "User Constructor: " << this << endl;
		setName(name); setHomeAddress(homeAddress); 
		setPhoneNumber(phoneNumber); setLogin(login); setPassword(password);
	}

	//Деструктор
	~User()
	{
		cout << "User Destructor: " << this << endl;
		delete[] name;
		delete[] homeAddress;
		delete[] phoneNumber;
		delete[] login;
		delete[] password;
	}

	//set name
	void setName(const char* name);

	//set homeAddress
	void setHomeAddress(const char* homeAddress);

	//set phoneNumber
	void setPhoneNumber(const char* phoneNumber);

	//set login
	void setLogin(const char* login);

	//set password
	void setPassword(const char* password);

	//Для регистрации
	void registration();

	//Для входа
	void loginUser();

	//Для входа админа
	void loginAdmin();

	//Показать все оценки для админа
	void showMarks();

	//Запись оценок
	void inputScore(int score);

	//getName
	const char* getName()
	{
		return name;
	}
};

//Меню
void menu();
//Режим входа
void mode();
//Математика
int maths();