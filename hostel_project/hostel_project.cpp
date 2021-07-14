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
	int age = 0;
	int studentId = 1;
};

int getStudentById(STUDENT_DATA* students, int& studentCount, int id)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].studentId == id)
		{
			return i;
		}
	}
	return -1;
}

int getUserById(USER_DATA* users, int& userCount, int id)
{
	for (int i = 0; i < userCount; i++)
	{
		if (users[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

STUDENT_DATA getStudent(STUDENT_DATA* students, int& studentCount, int id) //returns the index of the student that is being searched
{
	int index = getStudentById(students, studentCount, id);
	return students[index];
}

USER_DATA getUser(USER_DATA* users, int& userCount, int id) //returns the index of the users that is being searched
{
	int index = getUserById(users, userCount, id);
	return users[index];
}

void updateStudent(STUDENT_DATA* students, int studentCount, int id, STUDENT_DATA newStudent) //overwrites the students data
{
	int index = getStudentById(students, studentCount, id);
	students[index] = newStudent;
}

void updateUser(USER_DATA* users, int userCount, int id, USER_DATA newUser) //overwrites the users data
{
	int index = getUserById(users, userCount, id);
	users[index] = newUser;
}

void showAllUsers(USER_DATA* users, int& maxId)//show all users currently registered
{
	for (int i = 0; i < maxId - 1; i++)
	{
		cout << "Id: " << users[i].id << " | Username: " << users[i].userName << " | Password: " << users[i].password << " | First Name:  " << users[i].parentFirstName << " | Last Name: " << users[i].parentLastName << endl;
	}
	cout << endl;
	cout << endl;
}

void showAllStudents(STUDENT_DATA* students, int& studentount, int& studentMaxId) //show all students currently registered
{
	for (int i = 0; i < studentMaxId - 1; i++)
	{
		cout << "Id: " << students[i].studentId << " | Student First Name: " << students[i].studentFirstName << " | Student Last Name: " << students[i].studentLastName << " | Student Address:  " << students[i].address << " | Student Age: " << students[i].age << endl;
	}
}

void editStudentById(STUDENT_DATA* students, int& studentCount, int& studentMaxId) //showing the edit user menu
{
	int id;
	cout << "Enter the id of the student you want to edit: "; cin >> id;
	STUDENT_DATA student = getStudent(students, studentCount, id);
	cout << "1. Student First Name" << endl;
	cout << "2. Student Last Name" << endl;
	cout << "3. Student Address" << endl;
	cout << "4. Student Age" << endl;
	int choice;
	cout << "Your choice: "; cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Student First Name: "; cin >> student.studentFirstName;
		updateStudent(students, studentCount, id, student);
		break;
	case 2:
		cout << "Student Last Name: "; cin >> student.studentLastName;
		updateStudent(students, studentCount, id, student);
		break;
	case 3:
		cout << "Student Address: "; cin >> student.address;
		updateStudent(students, studentCount, id, student);
		break;
	case 4:
		cout << "Student Age: "; cin >> student.age;
		updateStudent(students, studentCount, id, student);
		break;
	}
	cout << endl;
	system("CLS");
	cout << "Student edited successfully!" << endl;
}

void editUserById(USER_DATA* users, int& userCount, int& maxId) //the menu for editing the data under a given id
{
	int id;
	cout << "Enter the id of the user you want to edit: "; cin >> id;
	USER_DATA user = getUser(users, userCount, id);
	cout << "1. Username" << endl;
	cout << "2. Password" << endl;
	cout << "3. Parent First Name" << endl;
	cout << "4. Parent Last Name" << endl;
	int choice;
	cout << "Your choice: "; cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Username: "; cin >> user.userName;
		updateUser(users, userCount, id, user);
		break;
	case 2:
		cout << "Password: "; cin >> user.password;
		updateUser(users, userCount, id, user);
		break;
	case 3:
		cout << "Parent First Name: "; cin >> user.parentFirstName;
		updateUser(users, userCount, id, user);
		break;
	case 4:
		cout << "Parent Last Name: "; cin >> user.parentLastName;
		updateUser(users, userCount, id, user);
		break;
	}
	cout << endl;
	system("CLS");
	cout << "User edited successfully!" << endl;
}

void deleteUserById(USER_DATA* users, int& userCount, int id) //deletes the user under the given id
{
	int index = getUserById(users, userCount, id);
	for (int i = index; i < userCount; i++)
	{
		users[i] = users[i + 1];
		users[i].id--;
	}
	userCount--;
	cout << endl;
	system("CLS");
	cout << "User deleted successfully!" << endl;
}

void deleteUserMenu(USER_DATA* users, int& userCount, int& maxId) //takes the id that the admin entered
{
	int userId;
	cout << "Enter the Id of the user you want to delete: ";
	cin >> userId;
	deleteUserById(users, userCount, userId);
	maxId--;
}

void deleteStudentById(STUDENT_DATA* students, int& studentCount, int id) //deletes the student under the given id
{
	int index = getStudentById(students, studentCount, id);
	for (int i = index; i < studentCount; i++)
	{
		students[i] = students[i + 1];
		students[i].studentId--;
	}
	studentCount--;
	cout << endl;
	system("CLS");
	cout << "Student deleted successfully!" << endl;
}

void deleteStudentMenu(STUDENT_DATA* students, int& studentCount, int& studentMaxId) //takes the id that the admin entered
{
	int userId;
	cout << "Enter the Id of the student you want to delete: ";
	cin >> userId;
	deleteStudentById(students, studentCount, userId);
	studentMaxId--;
}

void createUser(USER_DATA* users, int& userCount, int& maxId, USER_DATA user) //updates the id of the users
{
	user.id = maxId++;
	users[userCount] = user;
	userCount++;
	system("CLS");
	cout << "User registered successfully!" << endl;
}

void createStudent(STUDENT_DATA* students, int& studentCount, int& studentMaxId, STUDENT_DATA student) //updates the id of the students
{
	student.studentId = studentMaxId++;
	students[studentCount] = student;
	studentCount++;
	system("CLS");
	cout << "Student registered successfully!" << endl;
}

void registerStudent(STUDENT_DATA* students, int& studentCount, int& studentMaxId) //registers the new students
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

bool checkUserName(USER_DATA* users, int& userCount, int& maxId, USER_DATA user) //checks if the username of the new user is already being used by other user 
{
	for (int i = 0; i < userCount; i++)
	{
		if (user.userName == users[i].userName)
		{
			return true;
			break;
		}
	}
	return false;
}

void userRegister(USER_DATA* users, int& userCount, int& maxId) //the fucntions that makes new accounts for the users
{
	USER_DATA user;
	cout << "Username: "; cin >> user.userName;
	if (checkUserName(users, userCount, maxId, user) == true)
	{
		cout << "The username you entered is already taken. Please enter a new username!" << endl;
		cout << endl;
		cout << endl;
		userRegister(users, userCount, maxId);
	}
	else
	{
		cout << endl;
		cout << "Password: "; cin >> user.password;
		cout << endl;
		cout << "Parent First Name: "; cin >> user.parentFirstName;
		cout << endl;
		cout << "Parent Last Name: "; cin >> user.parentLastName;
		cout << endl;

		createUser(users, userCount, maxId, user);
	}
}

bool showUserMainMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId) //the regular user menu with all available options for the regular user
{
	int choice;
	cout << setw(70) << "-------USER MENU-------" << endl;
	cout << setw(70) << "************************" << endl;
	cout << setw(68) << "|1. Register A Student" << setw(2) << "|" << endl;
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
		system("CLS");
		return false;
		break;
	}
	return true;
}

bool showAdminMainMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId) //the admin menu with all available options for the admin
{
	system("color B");

	int choice;
	cout << setw(70) << "-------ADMIN MENU-------" << endl;
	cout << setw(71) << "**************************" << endl;
	cout << setw(61) << "|1. Create User" << setw(9) << "|" << endl;
	cout << setw(67) << "|2. Delete User by Id" << setw(3) << "|" << endl;
	cout << setw(65) << "|3. Edit User by Id" << setw(5) << "|" << endl;
	cout << setw(64) << "|4. Create Student" << setw(6) << "|" << endl;
	cout << setw(64) << "|5. Delete Student" << setw(6) << "|" << endl;
	cout << setw(62) << "|6. Edit Student" << setw(8) << "|" << endl;
	cout << setw(67) << "|7. Show all students" << setw(3) << "|" << endl;
	cout << setw(64) << "|8. Show all users" << setw(6) << "|" << endl;
	cout << setw(54) << "|9. Exit" << setw(16) << "|" << endl;
	cout << setw(71) << "**************************" << endl;
	cout << setw(68) << "What is your choice?: ";
	cin >> choice;
	cout << endl;
	cout << endl;
	if (choice > 9 || choice < 1)
	{
		cout << "Please enter a valid number!: "; cin >> choice;
	}
	switch (choice)
	{
	case 1:
		system("CLS");
		userRegister(users, userCount, maxId);

		break;
	case 2:
		system("CLS");
		deleteUserMenu(users, userCount, maxId);

		break;
	case 3:
		system("CLS");
		editUserById(users, userCount, maxId);

		break;
	case 4:
		system("CLS");
		registerStudent(students, studentCount, studentMaxId);

		break;
	case 5:
		system("CLS");
		deleteStudentMenu(students, studentCount, studentMaxId);

		break;
	case 6:
		system("CLS");
		editStudentById(students, studentCount, studentMaxId);

		break;
	case 7:
		system("CLS");
		showAllStudents(students, studentCount, studentMaxId);

		break;
	case 8:
		system("CLS");
		showAllUsers(users, maxId);

		break;
	case 9:
		system("CLS");
		return false;
		break;
	}

	return true;

}

void showUserMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId) //the loop that keeps the admin menu showing up
{
	bool showMenu;

	do
	{
		showMenu = showUserMainMenu(users, userCount, maxId, students, studentCount, studentMaxId);
	} while (showMenu);
	cout << endl;
}

void showAdminMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId) //the loop that keeps the admin menu showing up
{
	bool showMenu;

	do
	{
		showMenu = showAdminMainMenu(users, userCount, maxId, students, studentCount, studentMaxId);
	} while (showMenu);
	cout << endl;
}

void loginUser(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId) //checks if the entered data is for admin or regular user
{
	system("color B");

	string username;
	string pass;
	bool isCorrect = false;

	cout << "Username: "; cin >> username;
	cout << "Password: "; cin >> pass;

	if (username == "admin" && pass == "admin")
	{
		cout << "Welcome, " << username << '!' << endl;
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
			cout << "Welcome, " << username << '!' << endl;
			showUserMenu(users, userCount, maxId, students, studentCount, studentMaxId);
		}

		else
		{
			cout << "The username or password you entered is incorrect." << endl << " Please, try again!" << endl << endl;
			loginUser(users, userCount, maxId, students, studentCount, studentMaxId);
		}
	}


}

bool showMainMenu(USER_DATA* users, int& userCount, int& maxId, STUDENT_DATA* students, int& studentCount, int& studentMaxId) //show the main menu where the users register or log in to their accounts
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
	int studentCount = 0;

	do
	{
		showMenu = showMainMenu(users, userCount, maxId, students, studentCount, studentMaxId);
	} while (showMenu);
	cout << endl;

	cout << "Thank you for using our program!  :)" << endl;

}