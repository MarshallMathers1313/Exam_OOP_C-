#include "Header.h"
int main()
{
	int key, choice;
	do
	{
		menu();
		cin >> key;
		switch (key)
		{
		case 1:
			mode();
			cin >> choice;
			if (choice == 1)
			{
				User user;
				user.loginUser();
				int score = maths();
				user.inputScore(score);
			}
			else if (choice == 2)
			{
				User user;
				user.registration();
				user.loginUser();
				int score = maths();
				user.inputScore(score);
			}
			break;
		case 2:
			cout << "\t\t\tLogin!!!\n";
			cin >> choice;
			if (choice == 1)
			{
				User user;
				user.loginAdmin();
				user.showMarks();
			}
			break;
		default:
			break;
		}
	} while (key != 0);
	return 0;
}