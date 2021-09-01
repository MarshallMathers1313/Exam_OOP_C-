#include "FileManager.h"

//Создание файла
void File::createFile(const char* name)
{
	if (name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		ofstream outputFile(name);
		outputFile.close();
	}
	else
		this->name = nullptr;
}

//Запись в файл
void File::outputFile(string line)
{
	ofstream outputFile(name);
	outputFile << line;
	outputFile.close();
}

//Запись в конец существующего файла
void File::outputEndFile(string line)
{
	ofstream outputFile(name, ios::app);
	outputFile << line;
	outputFile.close();
}

//Чтение из файла
void File::showFile()
{
	ifstream inputFile(name);
	while (inputFile)
	{
		string line;
		getline(inputFile, line);
		cout << line << endl;
	}
}

//Удаление файла
void File::deleteFile()
{
	remove(name);
}

//Вывод размер файла
void File::sizeFile()
{
	ifstream sizeFile(name, ios::ate);
	int size = sizeFile.tellg();
	cout << "Size: " << size <<" bytes!"<< endl;
}


//Вывод инф. о файле
void File::infoFile()
{
	cout << "Information about file: " << name << endl;
	sizeFile();
}

//Изменение имя файла
void File::changeName(string oldName, string newName)
{
	rename(oldName.c_str(), newName.c_str());
}

//Перемещение файла
void File::moveFile(string oldName, string newName)
{
	rename(oldName.c_str(), newName.c_str());
}

//Копирование файла
void File::cFile(string firstFile, string secondFile)
{
	ifstream copFile(name);
	ofstream coFile(secondFile);
	while (copFile)
	{
		string line;
		getline(copFile, line);
		coFile << line << "\n";
	}
	copFile.close();
	coFile.close();
}



//Создание папки
void Folder::createFolder(const char* name)
{
	if (name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		_mkdir(name);
	}
	else
		this->name = nullptr;
}

//Удаление папки
void Folder::deleteFolder(string name)
{
	filesystem::remove_all(name);
}

//Изменение имя папки
void Folder::changeNameFolder(string oldName, string newName)
{
	rename(oldName.c_str(), newName.c_str());
}

//Перемещение папки
void Folder::moveFolder(string oldName, string newName)
{
	copyFolder(oldName, newName);
	deleteFolder(oldName);
}

//Копирование папки
void Folder::copyFolder(string oldName, string newName)
{
	string path;
	int size = oldName.length();
	for (int i = oldName.length(); i > 0; i--)
	{
		if (oldName[i] == '\\')
			break;
		path += oldName[i];
	}
	cout << path << endl;
	string path2;
	for (int i = size-1; i > 0; i--)
	{
		path2 += path[i];
	}

	path = newName + "/" + path2 + "/";
	cout << "NewName:" << newName <<"!"<< endl;
	cout << "path2:" << path2 <<"!"<< endl;
	cout << "path:" << path <<"!"<< endl;
	filesystem::create_directory(path);
	filesystem::copy(oldName, path);
}

//Размер папки
void Folder::sizeFolder(string name)
{
	int size = 0;
	for (const auto& entry : filesystem::directory_iterator(name))
		size += entry.file_size();
	cout << "Size Folder: " << size << endl;
}

//Поиск файла
void search(string name)
{
	//ofstream file(search(name));
}

//Меню
void menu()
{
	cout << "\n1 - Show Local Disk\n";
	cout << "2 - Create folder or file\n";
	cout << "3 - Delete folder or file\n";
	cout << "4 - Rename folder or file\n";
	cout << "5 - Copy folder or file\n";
	cout << "6 - Move folder or file\n";
	cout << "7 - Size folder or file\n";
	cout << "8 - Search folder or file\n";
	cout << "0 - exit\n\n";
	cout << "Input your number: ";
}