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
	string address;
	int age;
	int studentId = 1;
};

void showAllUsers(USER_DATA* users, int& maxId)
{
	for (int i = 0; i < maxId-1; i++)
	{
		cout << "Id: " << users[i].id << "  Username: " << users[i].userName << "  Password: " << users[i].password << "  First Name:  " << users[i].parentFirstName << "  Last Name: " << users[i].parentLastName << endl;
		
	}
}

void createUser(USER_DATA* users, int& userCount, int& maxId, USER_DATA user)
{
	user.id = maxId++;
	users[userCount] = user;
	userCount++;

	cout << "Student registered successfully!" << endl;
}

void createStudent(STUDENT_DATA* students, int& studentCount, int& studentMaxId, STUDENT_DATA student)
{
	student.studentId = studentMaxId++;
	students[studentCount] = student;
	studentCount++;

	cout << "Student registered successfully!" << endl;
}

void registerStudent(STUDENT_DATA* students, int& studentCount, int& studentMaxId)
{
	STUDENT_DATA student;
	cout << "Student First Name: "; cin >> student.studentFirstName;
	cout << endl;
	cout << "Student Last Name: "; cin >> student.studentLastName;
	cout << endl;
	cout << "Student Address: "; cin >> student.address;
	cout << endl;
	cout << "Student Age: "; cin >> student.age;
	cout << endl;

	createStudent(students, studentCount, studentMaxId, student);
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

bool showUserMainMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId)
{
	int choice;
	cout << setw(70) << "-------USER MENU-------" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(68) << "|1. Register A Student" <<setw(2)<< "|" << endl;
	cout << setw(54) << "|2. Exit" << setw(16) << "|" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(68) << "What is your choice?: ";
	cin >> choice;
	cout << endl;
	cout << endl;
	if (choice > 2 || choice < 1)
	{
		cout << "Please enter a valid number!: "; cin >> choice;
	}
	switch (choice)
	{
	case 1:
		registerStudent(students, studentCount, studentMaxId);
		break;
	case 2:
		return false;
		break;
	}
	return true;
}

bool showAdminMainMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId)
{
	system("color B");

	int choice;
	cout << setw(70) << "-------ADMIN MENU-------" << endl;
	cout << setw(60) << "1. Create User" << endl;
	cout << setw(66) << "2. Delete User by Id" << endl;
	cout << setw(64) << "3. Edit User by Id" << endl;
	cout << setw(80) << "4. Show all kids currently waiting" << endl;
	cout << setw(74) << "5. Show all registered users" << endl;
	cout << setw(53) << "6. Exit" << endl;
	cout << setw(70) << "What is your choice?: ";
	cin >> choice;
	cout << endl;
	cout << endl;
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
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		showAllUsers(users, maxId);
		break;
	case 6:
		return false;
		break;
	}

	return true;

}

void showUserMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId)
{
	bool showMenu;

	do
	{
		showMenu = showUserMainMenu(users, userCount, maxId, students, studentCount, studentMaxId);
	} while (showMenu);
	cout << endl;
}

void showAdminMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId)
{
	bool showMenu;

	do
	{
		showMenu = showAdminMainMenu(users, userCount, maxId, students, studentCount, studentMaxId);
	} while (showMenu);
	cout << endl;
}

void loginUser(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId)
{
	system("color B");

	string username;
	string pass;
	string adminUsername = "admin";
	string adminPass = "admin";
	bool isCorrect = false;

	cout << "Username: "; cin >> username;
	cout << "Password: "; cin >> pass;

	if (username == "admin" && pass == "admin")
	{
		cout << "Welcome, " << username << endl;
		showAdminMenu(users, userCount, maxId, students, studentCount, studentMaxId);
		isCorrect = true;
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

		if (isCorrect == true)
		{
			cout << "Welcome, " << username << endl;
			showUserMenu(users, userCount, maxId, students, studentCount, studentMaxId);
		}

		else
		{
			cout << "The username or password you entered is incorrect." << endl << " Please, try again!" << endl << endl;
			loginUser(users, userCount, maxId, students, studentCount, studentMaxId);
		}
	}


}



bool showMainMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId)
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
		loginUser(users, userCount, maxId, students, studentCount, studentMaxId);
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
	STUDENT_DATA students[10];
	int studentMaxId = 1;
	int studentCount=0;

	do
	{
		showMenu = showMainMenu(users, userCount, maxId, students, studentCount, studentMaxId);
	} while (showMenu);
	cout << endl;

	cout << "Thank you for using our program!  :)" << endl;

}