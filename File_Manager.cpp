#include "FileManager.h"
int main()
{
	Disk disk1("C");
	Disk disk2("D");
	int key;
	int choice;
	string name;
	do
	{
		menu();
		cin >> key;

		switch (key)
		{
		case 1:
			cin.ignore(32765, '\n');
			cout << "Input directory's name: ";
			getline(cin, name);
			for (const auto& entry : filesystem::directory_iterator(name))
				cout << entry.path() << endl;
			break;
		case 2:
			cout << "\tWhat do you want:\n";
			cout << "\t1 - Create folder or 2 - Create file?\n";
			cout << "Your choice: ";
			cin >> choice;
			if (choice == 1)
			{
				cin.ignore(32765, '\n');
				cout << "Input new folder name: ";
				getline(cin, name);
				Folder folder(name.c_str());
			}
			else if (choice == 2)
			{
				cin.ignore(32765, '\n');
				cout << "Input new file name: ";
				getline(cin, name);
				File file(name.c_str());
			}
			break;
		case 3:
			cout << "\tWhat do you want:\n";
			cout << "\t1 - Delete folder or 2 - Delete file\n";
			cout << "Yout choice: ";
			cin >> choice;
			if (choice == 1)
			{
				cin.ignore(32765, '\n');
				cout << "Input delete folder name: ";
				getline(cin, name);
				Folder folder(name.c_str());
				folder.deleteFolder(name);
			}
			else if (choice == 2)
			{
				cin.ignore(32765, '\n');
				cout << "Input delete file name: ";
				getline(cin, name);
				File file(name.c_str());
				file.deleteFile();
			}

			break;
		case 4:
			cout << "\tWhat do you want:\n";
			cout << "\t1 - Rename folder or 2 - Rename file\n";
			cout << "Yout choice: ";
			cin >> choice;
			if (choice == 1)
			{
				cin.ignore(32765, '\n');
				cout << "Input rename folder name: ";
				getline(cin, name);
				string newName;
				cout << "Input new folder name: ";
				getline(cin, newName);
				Folder folder(name.c_str());
				folder.changeNameFolder(name, newName);
			}
			else if (choice == 2)
			{
				cin.ignore(32765, '\n');
				cout << "Input rename file name: ";
				getline(cin, name);
				string newName;
				cout << "Input new file name: ";
				getline(cin, newName);
				File file(name.c_str());
				file.changeName(name, newName);
			}
			break;
		case 5:
			cout << "\tWhat do you want:\n";
			cout << "\t1 - Copy folder or 2 - Copy file\n";
			cout << "Yout choice: ";
			cin >> choice;
			if (choice == 1)
			{
				cin.ignore(32765, '\n');
				cout << "Input copy folder name: ";
				getline(cin, name);
				cout << "Input where copy folder name: ";
				string newName;
				getline(cin, newName);
				Folder folder;
				folder.copyFolder(name, newName);
			}
			else if (choice == 2)
			{
				cin.ignore(32765, '\n');
				cout << "Input copy file name: ";
				getline(cin, name);
				cout << "Input where copy file name: ";
				string newName;
				getline(cin, newName);
				File file(name.c_str());
				file.cFile(name, newName);
			}
			break;
		case 6:
			cout << "\tWhat do you want:\n";
			cout << "\t1 - Move folder or 2 - Move file\n";
			cout << "Yout choice: ";
			cin >> choice;

			if (choice == 1)
			{
				cin.ignore(32765, '\n');
				cout << "Input rename folder name: ";
				getline(cin, name);
				string newName;
				cout << "Input new folder name: ";
				getline(cin, newName);
				Folder folder;
				folder.moveFolder(name, newName);
			}

			else if (choice == 2)
			{
				cin.ignore(32765, '\n');
				cout << "Input rename file name: ";
				getline(cin, name);
				string newName;
				cout << "Input new file name: ";
				getline(cin, newName);
				File file;
				file.moveFile(name, newName);
			}
			break;
		case 7:
			cout << "\tWhat do you want:\n";
			cout << "\t1 - Move folder or 2 - Move file\n";
			cout << "Yout choice: ";
			cin >> choice;
			if (choice == 1)
			{
				cin.ignore(32765, '\n');
				cout << "Input directory's name: ";
				getline(cin, name);
				Folder folder;
				folder.sizeFolder(name);
			}
			else if (choice == 2)
			{
				cin.ignore(32765, '\n');
				cout << "Input file's name: ";
				getline(cin, name);
				File file(name.c_str());
				file.sizeFile();
			}
			break;
		case 8:
			break;
		default:
			break;
		}
	} while (key != 0);

	return 0;
}