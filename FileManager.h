#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>//mkdir
#include <Windows.h>
#include <filesystem>
using namespace std;
//Класс файл
class File
{
	char* name;
public:
	//Конструктор
	File(const char* name = nullptr)
		:name{name? new char[strlen(name)+1]: nullptr}
	{
		cout << "File Constructor: " << this << endl;
		if (name)
		{
			strcpy_s(this->name, strlen(name) + 1, name);
			ofstream outputFile(name);
			outputFile.close();
		}
	}

	//Деструктор
	~File()
	{
		cout << "File Destructor: " << this << endl;
		delete[] name;
	}

	//Создание файла
	void createFile(const char* name = nullptr);

	//Запись в файл
	void outputFile(string line);

	//Запись в конец существующего файла
	void outputEndFile(string line);

	//Чтение из файла
	void showFile();

	//Удаление файла
	void deleteFile();

	//Вывод размер файла
	void sizeFile();

	//Вывод инф. о файле
	void infoFile();

	//Изменение имя файла
	void changeName(string oldName, string newName);

	//Перемещение файла
	void moveFile(string oldName, string newName);

	//Копирование файла
	void cFile(string firstFile, string secondFile);
};

//Класс папка
class Folder
{
	char* name;
public:
	//Конструктор
	Folder(const char* name = nullptr)
		:name{ name ? new char[strlen(name) + 1] : nullptr }
	{
		cout << "Folder Constructor: " << this << endl;
		if (name)
		{
			strcpy_s(this->name, strlen(name) + 1, name);
			_mkdir(name);
		}
		else
			this->name = nullptr;
	}

	//Деструктор
	~Folder()
	{
		cout << "Folder Destructor: " << this << endl;
		delete[] name;
	}

	//Создание папки
	void createFolder(const char* name);

	//Удаление папки
	void deleteFolder(string name);
	
	//Изменение имя папки
	void changeNameFolder(string oldName, string newName);

	//Перемещение папки
	void moveFolder(string oldName, string newName);

	//Копирование папки
	void copyFolder(string oldName, string newName);

	//Размер папки
	void sizeFolder(string name);
};

//Класс Локальный диск
class Disk
{
	char* name;

public:
	//Конструктор
	Disk(const char* name = nullptr)
		:name{name ? new char[strlen(name) + 1] : nullptr}
	{
		cout << "Disk Constructor: " << this << endl;
		if (name)
		{
			strcpy_s(this->name, strlen(name) + 1, name);
			_mkdir(name);
		}
	}

	//Деструктор
	~Disk()
	{
		cout << "Disk Destructor: " << this << endl;
		delete[] name;
	}

};

//Меню
void menu();

//Поиск файла
void search(string name);