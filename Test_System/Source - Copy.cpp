#include "Header.h"
//меню
void menu()
{
	cout << "\n1 - User\n";
	cout << "2 - Admin\n";
	cout << "0 - exit\n\n";
	cout << "Input your choice: ";
}

//Режим входа
void mode()
{
	cout << "\n1 - Login\n";
	cout << "2 - Registration\n";
	cout << "0 - exit\n\n";
	cout << "Input your choice: ";
}

//set name
void User::setName(const char* name)
{
	if (name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	else
		this->name = nullptr;
}

//set homeAddress
void User::setHomeAddress(const char* homeAddress)
{
	if (homeAddress)
	{
		this->homeAddress = new char[strlen(homeAddress) + 1];
		strcpy_s(this->homeAddress, strlen(homeAddress) + 1, homeAddress);
	}
	else
		this->homeAddress = nullptr;
}

//set phoneNumber
void User::setPhoneNumber(const char* phoneNumber)
{
	if (phoneNumber)
	{
		this->phoneNumber = new char[strlen(phoneNumber) + 1];
		strcpy_s(this->phoneNumber, strlen(phoneNumber) + 1, phoneNumber);
	}
	else
		this->phoneNumber = nullptr;
}

//set Login
void User::setLogin(const char* login)
{
	if (login)
	{
		this->login = new char[strlen(login) + 1];
		strcpy_s(this->login, strlen(login) + 1, login);
	}
	else
		this->login = nullptr;
}

//set password
void User::setPassword(const char* password)
{
	if (password)
	{
		this->password = new char[strlen(password) + 1];
		strcpy_s(this->password, strlen(password) + 1, password);
	}
	else
		this->password = nullptr;
}

//Для регистрации
void User::registration()
{
	cout << "\t\t\t\tRegistration!!!\n";
	string name, address, number, login, password;
	cin.ignore(32765, '\n');

	cout << "Input name: ";
	getline(cin, name);
	setName(name.c_str());
	ofstream file("Users/name.txt", ios::app);
	file << name + "\n";
	file.close();

	cout << "Input Adress: ";
	getline(cin, address);
	setHomeAddress(address.c_str());
	ofstream file1("Users/address.txt", ios::app);
	file1 << address + "\n";
	file1.close();

	cout << "Input Phone Number: ";
	getline(cin, number);
	setPhoneNumber(number.c_str());
	ofstream file2("Users/phoneNumber.txt", ios::app);
	file2 << number + "\n";
	file2.close();


	cout << "Input new Login: ";
	getline(cin, login);
	setLogin(login.c_str());
	ofstream file3("Users/login.txt", ios::app);
	file3 << login + "\n";
	file3.close();

	cout << "Input new Password: ";
	getline(cin, password);
	setPassword(password.c_str());
	ofstream file4("Users/password.txt", ios::app);
	file4 << password + "\n";
	file4.close();
}

//Для входа
void User::loginUser()
{
	cout << "\t\t\t\tLogin!!!\n";
	string Login, Password;
	cin.ignore(32765, '\n');

	cout << "Input login: ";
	getline(cin, Login);
	cout << "Input password: ";
	getline(cin, Password);

	ifstream fileLogin("Users/login.txt");
	ifstream filePassword("Users/password.txt");

	int i = 0;
	while (fileLogin && filePassword)
	{
		string _login, _password;
		getline(fileLogin, _login);
		getline(filePassword, _password);

		if (Login == _login, Password == _password)
		{
			cout << "Congurations! You Login!\n";
			int _score = maths();
			inputScore(_score);

		}
	}
	fileLogin.close();
	filePassword.close();
}

//Математика
int maths()
{
	int correct, answer;
	int k = 0;
	for (int i = 0; i < 5; i++)
	{
		int a = rand() % 100;
		int b = rand() % 100;
		correct = a + b;
		cout << a << " + " << b << " = ";
		cin >> answer;
		if (correct == answer)
		{
			k++;
			cout << "Correct!\n";
		}
		else
		{
			cout << "Incorrect\n";
		}
	}

	if (k > 8)
		cout << "Excellent! Your score: " << k << "/5!!!";
	else if(k >= 5 && k <= 8)
		cout << "Good! Your score: " << k << "/5!!!";
	else if(k >= 0 && k <=4)
		cout << "Bad! Your score: " << k << "/5!!!";

	return k;
}

//Запись оценок
void User::inputScore(int score)
{
	ofstream file("Admin/score.txt", ios::app);
	string _name = getName();
	cout << _name;
	//file << getName() << " - ";
	file << score;
	file << "/10\n";
	file.close();
}

//Для входа админа
void User::loginAdmin()
{
	cout << "\t\t\t\tLogin!!!\n";
	string Login, Password;
	cin.ignore(32765, '\n');

	cout << "Input login: ";
	getline(cin, Login);
	cout << "Input password: ";
	getline(cin, Password);

	if (Login == "Admin" && Password == "admin")
	{
		cout << "Congurations! You Login!\n";
	}
	else
		cout << "Don't correct login or password!\n";
}

//Показать все оценки для админа
void User::showMarks()
{
	cout << "\t\t\tMarks all user!\n";
	ifstream file("Admin/score.txt");
	while (file)
	{
		string line;
		getline(file, line);
		cout << line << "\n";
	}
}