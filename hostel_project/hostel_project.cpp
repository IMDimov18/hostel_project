#include <iostream>
#include <string>
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
	int studentAge=0;
	int id=1;
};

void createUser(USER_DATA* users, int& userCount, int& maxId, USER_DATA user)
{
	user.id = maxId++;
	users[userCount] = user;
	userCount++;
}

void userRegister(USER_DATA* users,int& userCount, int& maxId)
{
	USER_DATA user;
	cout << "Username: "; cin >> user.userName ;
	cout << endl;
	cout << "Password: "; cin >> user.password;
	cout << endl;
	cout << "Parent First Name: "; cin >> user.parentFirstName;
	cout << endl;
	cout << "Parent Last Name: "; cin >> user.parentLastName;
	cout << endl;
	
	createUser(users, userCount, maxId, user);
}



bool showMainMenu(USER_DATA* users, int& userCount, int& maxId)
{
	int choice;
	cout << "-------USER MENU-------" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "6. Exit" << endl;
	cout << "What is your choice?: ";
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
	int userCount=0;
	int maxId = 1;
	bool showMenu;
	
	do
	{
		showMenu = showMainMenu(users, userCount, maxId);
	} while (showMenu);
	cout << endl;

	cout << "Thank you for using our program!" << endl;
}