#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct USER_DATA
{
	string userName;
	string password;
	string parentFirstName;
	string parentLastName;
	string address;
	string studentFirstName;
	string studentLastName;
	int studentAge = 0;
	int id = 1;
};

void createUser(USER_DATA* users, int& userCount, int& maxId, USER_DATA user)
{
	user.id = maxId++;
	users[userCount] = user;
	userCount++;
}

void userRegister(USER_DATA* users, int& userCount, int& maxId)
{
	USER_DATA user;
	cout << "Username: "; cin >> user.userName;
	cout << endl;
	cout << "Password: "; cin >> user.password;
	cout << endl;
	cout << "Parent First Name: "; cin >> user.parentFirstName;
	cout << endl;
	cout << "Parent Last Name: "; cin >> user.parentLastName;
	cout << endl;

	createUser(users, userCount, maxId, user);
}

void loginUser(USER_DATA* users, int& userCount, int& maxId)
{
	string username;
	string pass;

	cout << "Username: "; cin >> username;
	cout << "Password: "; cin >> pass;

	for (int i = 0; i < maxId; i++)
	{
		if (username == users[i].userName && pass == users[i].password)
		{
			cout << "Welcome!" << endl;
			break;
		}
	}

	cout << "The username or password you entered is incorrect.\n Please try again!\n";
}

bool showAdminMenu(USER_DATA* users, int& userCount, int& maxId)
{
	int choice;
	cout <<
}


bool showMainMenu(USER_DATA* users, int& userCount, int& maxId)
{
	int choice;
	cout << setw(70) << "-------LOGIN MENU-------" << endl;
	cout << setw(59) << "1. Register" << endl;
	cout << setw(56) << "2. Login" << endl;
	cout << setw(55) << "6. Exit" << endl;
	cout << setw(70) << "What is your choice?: ";
	cin >> choice;
	if (choice > 6 || choice < 1)
	{
		cout << "Please enter a valid number!: "; cin >> choice;
	}
	switch (choice)
	{
	case 1:
		userRegister(users, userCount, maxId);
		break;
	case 2:
		loginUser(users, userCount, maxId);
		break;
	case 6:
		return false;
		break;
	}
	return true;
}


int main()
{
	system("CLS");
	system("color B");
	USER_DATA users[10];
	int userCount = 0;
	int maxId = 1;
	bool showMenu;

	do
	{
		showMenu = showMainMenu(users, userCount, maxId);
	} while (showMenu);
	cout << endl;

	cout << "Thank you for using our program!  :)" << endl;

}