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
	int id = 1;
};
struct STUDENT_DATA
{
	string studentFirstName;
	string studentLastName;
	int age;
	int studentIf = 0;
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

bool showUserMainMenu(USER_DATA* users, int& userCount, int& maxId)
{
	int choice;
	cout << setw(70) << "-------USER MENU-------" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(68) << "|1. Register A Student" << "|" << endl;
	cout << setw(55) << "|2. Exit" << setw(14) << "|" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(68) << "What is your choice?: ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Please enter a valid number!: "; cin >> choice;
	}
	switch (choice)
	{
	case 1:
		break;
	case 2:
		return false;
		break;
	}
	return true;
}

bool showAdminMenu(USER_DATA* users, int& userCount, int& maxId)
{
	system("color B");

	int choice;
	cout << setw(70) << "-------ADMIN MENU-------" << endl;
	cout << setw(60) << "1. Create User" << endl;
	cout << setw(66) << "2. Delete User by Id" << endl;
	cout << setw(64) << "3. Edit User by Id" << endl;
	cout << setw(79) << "4. Show all kid currently waiting" << endl;
	cout << setw(53) << "5. Exit" << endl;
	cout << setw(70) << "What is your choice?: ";
	cin >> choice;
	if (choice > 5 || choice < 1)
	{
		cout << "Please enter a valid number!: "; cin >> choice;
	}

	return true;

}

void showUserMenu(USER_DATA* users, int& userCount, int& maxId)
{
	bool showMenu;

	do
	{
		showMenu = showUserMainMenu(users, userCount, maxId);
	} while (showMenu);
	cout << endl;
}

void loginUser(USER_DATA* users, int& userCount, int& maxId)
{
	system("color B");

	string username;
	string pass;
	string adminUsername = "admin";
	string adminPass = "admin";
	bool isCorrect = false;

	cout << "Username: "; cin >> username;
	cout << "Password: "; cin >> pass;

	if (username == adminUsername && pass == adminPass)
	{
		cout << "Welcome, " << username << endl;
		showAdminMenu(users, userCount, maxId);
	}

	else
	{

		for (int i = 0; i < maxId; i++)
		{
			if (username == users[i].userName && pass == users[i].password)
			{
				isCorrect = true;
			}
		}

	}

	if (isCorrect == true)
	{
		cout << "Welcome, " << username << endl;
		showUserMenu(users, userCount, maxId);
	}
	else
	{
		cout << "The username or password you entered is incorrect."<<endl<<" Please, try again!" << endl<<endl;
		loginUser(users, userCount, maxId);
	}

}



bool showMainMenu(USER_DATA* users, int& userCount, int& maxId)
{
	int choice;
	cout << setw(70) << "-------LOGIN MENU-------" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(59) << "|1. Register" << setw(10) << "|" << endl;
	cout << setw(56) << "|2. Login" << setw(13) << "|" << endl;
	cout << setw(55) << "|3. Exit" << setw(14) << "|" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(68) << "What is your choice?: ";
	cin >> choice;
	if (choice > 3 || choice < 1)
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
	case 3:
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