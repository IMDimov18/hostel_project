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

void insertData(USER_DATA* us,int& userCount, int& maxId)
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
	cout << "Address: "; cin >> user.address;
	cout << endl;
	cout << "Student First Name: "; cin >> user.studentFirstName;
	cout << endl;
	cout << "Student Last Name: "; cin >> user.studentLastName;
	cout << endl;
	cout << "Student Age: "; cin >> user.studentAge;
}

bool showMainMenu(USER_DATA* users, int& userCount, int& maxId)
{
	int choice;
	cout << "-------USER MENU-------" << endl;
	cout << "1. Create order" << endl;
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
		insertData(users, userCount, maxId);
		break;
	case 6:
		return false;
		break;
	}
	return false;
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