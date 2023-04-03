
#include <iostream>
#include <string>
#include "Manager.h"
#include <conio.h>
using namespace std;
using std::system;



void firstpage()
{
	system("CLS");
	cout << endl << "\t\t**************************************************************" << endl << endl;
	cout << "\t\t Welcome to Financial Management System(FMS)" << endl;
	cout << "\t\t FMS helps to manage your financial system effictively" << endl << endl;
	cout << "\t\t**************************************************************" << endl << endl;
	cout << "\t\t                1 -> Login							  " << endl;
	cout << "\t\t                2 -> Exit								  " << endl;
	cout << "\t\t															  " << endl;
	cout << "\t\t**************************************************************" << endl;
}

boolean WelcomeAdmin(string adminID)
{
	system("CLS");
	AdminManager adminmanager;
	Admin* admin = adminmanager.getAdmin(adminID);

	
	cout << "\t\t.-----------------------------------------------------------------." << endl;
	cout << "\t\t|                             Welcome                             |" << endl;
	cout << "\t\t.-----------------------------------------------------------------." << endl << endl;
	cout << setw(55) << right << admin->admin_name << setw(10) << right << endl << endl;

	bool test = false;
	do {
		cout << "\n\n\t\t Do you want to proceed with Admin Function ? (Y/N)  ";
		string ans;
		getline(cin >> ws, ans);
		if (ans == "Y" || ans == "y")
		{
			return true;
		}
		else if (ans == "N" || ans == "n")
		{
			return false;
		}
		else
		{
			cout << "\t\t Please select Y/N only ! " << endl;
			test = false;
		}

	} while (test == false);


}

void adminFaculty(string adminID)
{
	
	Manager manager;
	double input = -1;
	bool valid = false;
	int con = 0;
	do {
		system("CLS");
		cout << endl << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t\t\t    Faculty Management" << endl << endl;
		cout << endl << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t                1 -> Insert A New Faculty							  " << endl;
		cout << "\t\t                2 -> Update A Faculty Inforamtion						  " << endl;
		cout << "\t\t                3 -> Delete A Faculty							  " << endl;
		cout << "\t\t                4 -> Search For A Faculty							  " << endl;
		cout << "\t\t                5 -> View All Faculty							  " << endl;
		cout << "\t\t                6 -> Exit						  " << endl << endl;
		cout << "\t\t**************************************************************" << endl << endl;
		do
		{
			cout << endl << "\t\t Enter your option [1/2/3/4/5/6]: " << flush;
			cin >> input;
			if ((cin.good()) && (input >= 1) && (input <= 6))
			{
				//everything went well, we'll get out of the loop and return the value
				valid = true;
			}
			else
			{
				//something went wrong, we reset the buffer's state to good
				cin.clear();
				//and empty it
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\t\t Invalid input; please re-enter." << endl << endl;
			}
		} while (!valid);
		con = input;
		switch (con)
		{
		case 1:
		{
			system("CLS");
			manager.testAddFaculty(adminID);
			system("pause");
			break;
		}
		case 2:
		{
			system("CLS");
			manager.testUpdateFaculty();
			system("pause");
			break;
		}
		case 3:
		{
			system("CLS");
			manager.testDeleteFaculty();
			system("pause");
			break;
		}
		case 4: //Serach for a faculty
		{
			system("CLS");
			manager.testSearchFaculty();
			system("pause");
			break;
		}
		case 5: //view all faculty
		{
			system("CLS");
			manager.viewAllFaculty();
			system("pause");
			break;
		}
		case 6: //exit
		{
			break;
		}
		}
	} while (con != 6);
}

void adminStaff(string adminID)
{
	
	AdminManager adminmanager;
	Manager manager;
	Admin* admin = adminmanager.getAdmin(adminID);
	double input = -1;
	bool valid = false;
	int con = 0;
	do {
		system("CLS");
		cout << endl << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t\t\t    Staff Management" << endl << endl;

		cout << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t                1 -> Add A New Staff						  " << endl;
		cout << "\t\t                2 -> Update A Staff Information							  " << endl;
		cout << "\t\t                3 -> Search For A Staff							  " << endl;
		cout << "\t\t                4 -> View All Staff Information							  " << endl;
		cout << "\t\t                5 -> Delete A Staff							  " << endl;
		cout << "\t\t                6 -> Exit						  " << endl;
		cout << "\n\t\t**************************************************************" << endl << endl;
		
		do
		{
			cout << endl << "\t\t Enter your option [1/2/3/4/5/6]: " << flush;
			cin >> input;
			if ((cin.good())&& (input >= 1) && (input <= 6))
			{
				//everything went well, we'll get out of the loop and return the value
				valid = true;
			}
			else
			{
				//something went wrong, we reset the buffer's state to good
				cin.clear();
				//and empty it
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\t\t Invalid input; please re-enter." << endl << endl;
			}
		} while (!valid);
		con = input;

		switch (con)
		{
		case 1:
		{
			system("CLS");
			manager.testAddStaff(adminID);
			system("pause");
			
			break;
		}
		case 2:
		{
			system("CLS");
			manager.testUpdateStaff();
			system("pause");
			break;
		}
		case 3: //search 
		{
			system("CLS");
			manager.testSearchStaff();
			system("pause");
			break;
		}
		case 4: //view all staff
		{
			system("CLS");
			manager.viewAllStaff();
			system("pause");
			break;
		}
		case 5: //delete
		{
			system("CLS");
			manager.testDeleteStaff();
			system("pause");
			break;
		}
		case 6:
		{
			break;
		}
		}
	} while (con != 6);
	system("CLS");
}

void adminFunction(string adminID)
{

	AdminManager adminmanager;
	Admin* admin = adminmanager.getAdmin(adminID);

	double input = -1;
	bool valid = false;
	int Case = 0;
	bool welcome = WelcomeAdmin(adminID);
	if (welcome == true)
	{
		do {
			system("CLS");
			cout << "\t\t**********************************************************************" << endl << endl;
			cout << "\t\t**			 Admin Function				   **" << endl << endl;
			//cout << "\t\t\t\t\tWelcome, " << admin->admin_name << " !\n\n";
			cout << "\t\t**********************************************************************" << endl << endl;
			cout << "\t\t                1 -> Faculty Management						  " << endl;
			cout << "\t\t                2 -> Staff Management							  " << endl;
			cout << "\t\t                3 -> Exit						  " << endl << endl;
			cout << "\t\t**********************************************************************" << endl << endl;
			do
			{
				cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
				cin >> input;
				if ((cin.good()) && (input >= 1) && (input <= 3))
				{
					//everything went well, we'll get out of the loop and return the value
					valid = true;
				}
				else
				{
					//something went wrong, we reset the buffer's state to good
					cin.clear();
					//and empty it
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\t\t Invalid input; please re-enter." << endl << endl;
				}
			} while (!valid);
			Case = input;
			switch (Case)
			{
			case 1:
			{
				system("CLS");
				adminFaculty(admin->admin_ID);
				break;
			}
			case 2:
			{
				system("CLS");
				adminStaff(admin->admin_ID);
				break;
			}
			case 3: //Exit
			{

				break;
			}
			default:
			{
				cout << "\t\t You are not entering 1, 2 or 3 to exit!!!" << endl;
			}
			}
		} while (Case != 3);
		system("CLS");
	}

	
}

void adminLogin()
{
	system("CLS");
	Manager manager;
	string adminID;
	cout << endl << "\t\t\t  Financial Management System(FMS)" << endl;
	cout << endl << "\t\t**************************************************************" << endl << endl;
	cout << "\t\t\t\t    Admin Login" << endl << endl;
	cout << "\t\t**************************************************************" << endl << endl << endl;

	cout << "\t\t\t Enter your admin ID: ";
	getline(cin >> ws, adminID);
	cout << endl << "\t\t\t Enter your password: ";

	char password[100];

	int index = 0;
	while (1)
	{
		char ch;
		ch = _getch();
		if (ch == 8)               // if backspace
		{
			if (index != 0)
			{
				cout << char(8) << " " << char(8);
				index--;
			}
		}
		else if (ch == '\r')        // enter then break;
		{
			password[index] = '\0';
			cout << endl;
			break;
		}
		else
		{
			cout << "*";
			password[index++] = ch;
		}
	}
	
	bool success = manager.loginAdmin(adminID, password);
	if (success == true)
	{
		adminFunction(adminID);
	}
	system("pause");
}

void transaction(string staffID)
{
	system("CLS");
	Manager manager;
	double input = -1;
	bool valid = false;
	int con = 0;
	StaffManager staffmanager;
	Staff* staff = staffmanager.getStaffID(staffID);
	
	FacultyManager facultymanager;
	
	do {
		system("CLS");
		Faculty* faculty = facultymanager.getFaculty(staff->faculty_ID);
		cout << endl << "\t\t**************************************************************" << endl;
		cout << "\t\t\t" << faculty->faculty_name << endl;
		cout << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t**************************************************************" << endl;
		cout << "\t\t\t\tCurrent Balance: RM " << faculty->faculty_balance << endl;
		cout << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t             1 -> Insert New Transaction Record							  " << endl;
		cout << "\t\t             2 -> Update A Transaction Record							  " << endl;
		cout << "\t\t             3 -> Delete A Transaction Record							  " << endl;
		cout << "\t\t             4 -> Search For A Transaction Record" << endl;
		cout << "\t\t             5 -> View All Transaction Record							  " << endl;
		cout << "\t\t             6 -> Exit						  " << endl << endl;
		cout << "\t\t**************************************************************" << endl << endl;
		
		do
		{
			cout << endl << "\t\t Enter your option [1/2/3/4/5/6]: " << flush;
			cin >> input;
			if ((cin.good()) && (input >= 1) && (input <= 6))
			{
				//everything went well, we'll get out of the loop and return the value
				valid = true;
			}
			else
			{
				//something went wrong, we reset the buffer's state to good
				cin.clear();
				//and empty it
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\t\t Invalid input; please re-enter." << endl << endl;
			}
		} while (!valid);
		con = input;

		switch (con)
		{
		case 1:
		{
			system("CLS");
			manager.testAddRecord(staffID);
			system("pause");
			break;
		}
		case 2:
		{
			system("CLS");
			manager.testUpdateRecord(staffID);
			system("pause");
			break;
		}
		case 3:
		{
			system("CLS");
			manager.testDeleteRecord(staffID);
			system("pause");
			break;
		}
		case 4: //Serach for record
		{
			system("CLS");
			manager.testSearchRecord(faculty->faculty_ID);
			system("pause");
			break;
		}
		case 5: //view all records
		{
			system("CLS");
			manager.viewRecordByFaculty(faculty->faculty_ID);
			system("pause");
			break;
		}
		case  6: //exit
		{
			system("CLS");
			break;
		}
		}
	} while (con != 6);
}

string Year()
{
	string year;
	bool test = false;
	do {
		cout << endl << "\t\t Enter year: ";
		getline(cin >> ws, year);
		if (year.size() != 4)
		{
			test = false;
			cout << "\t\t Please make sure you type the format of year correctly (YYYY) " << endl << endl;
		}
		else 
			test = true;
	} while (test == false);
	
	return year;
}

int SelectSpend(string facultyName)
{
	system("CLS");
	cout << endl << endl << "\t\t=================================================" << endl;
	cout  << "\t\t\t\tSpending Report" << endl;
	cout << "\t\t=================================================" << endl << endl;
	cout << "\t\t1 -> Bar Chart"<< endl;
	cout << "\t\t2 -> Total Costs On Each Credit Category" << endl;
	cout << "\t\t3 -> Exit" << endl << endl;

	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;

}

int SelectIncome(string facultyName)
{
	system("CLS");
	cout << endl << endl << "\t\t=================================================" << endl;
	cout << "\t\t\t\tIncome Generation" << endl;
	cout << "\t\t=================================================" << endl << endl;
	cout << "\t\t1 -> Bar Chart" << endl;
	cout << "\t\t2 -> Total Income On Each Debit Category" << endl;
	cout << "\t\t3 -> Exit" << endl << endl;

	
	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;


}

int OverviewOnCreditAndDebit()
{
	system("CLS");
	cout << endl << endl << "\t\t\t==========================================" << endl;
	cout << "\t\t\tOverview On Total Credit And Debit in UTeM" << endl;
	cout  << "\t\t\t==========================================" << endl << endl;
	cout << "\t\t\t1 -> Total Credit " << endl;
	cout << "\t\t\t2 -> Total Debit" << endl;
	cout << "\t\t\t3 -> Exit" << endl << endl;

	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;

}

int CreditAllFac()
{
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	int num_of_fac = 0;
	if (faculty != NULL)
	{
		
		do {
			num_of_fac++;
			faculty = faculty->next;
		} while (faculty != NULL);
	}

	system("CLS");
	cout << endl << endl << "\t\t=================================================" << endl;
	cout << "\t\t\t\tSpending Report" << endl;
	cout << "\t\t=================================================" << endl << endl;
	cout << "\t\t1 -> Bar Chart On Percentage Of The Total Spending Among The " << num_of_fac << " Faculties" << endl;
	cout << "\t\t2 -> Total Spending On Each Credit Category Among The " << num_of_fac << " Faculties" << endl;
	cout << "\t\t3 -> Exit" << endl << endl;

	
	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;
}

int DebitAllFac()
{
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	int num_of_fac = 0;
	if (faculty != NULL)
	{

		do {
			num_of_fac++;
			faculty = faculty->next;
		} while (faculty != NULL);
	}


	system("CLS");
	cout << endl << endl << "\t\t=================================================" << endl;
	cout << "\t\t\t\tIncome Generation" << endl;
	cout << "\t\t=================================================" << endl << endl;
	cout << "\t\t1 -> Bar Chart On Percentage Of The Total Income Among The " << num_of_fac << " Faculties" << endl;
	cout << "\t\t2 -> Total Spending On Each Debit Category Among The " << num_of_fac << " Faculties" << endl;
	cout << "\t\t3 -> Exit" << endl << endl;


	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;
}

int Report6()
{
	system("CLS");
	cout << endl << endl << "\t\t=================================================" << endl;
	cout << "\t\t\t\tAnnual Report" << endl;
	cout << "\t\t=================================================" << endl << endl;
	cout << "\t\t1 -> Annual Report In A Particular Year" << endl;
	cout << "\t\t2 -> Comparison Between All The Faculties " << endl;
	cout << "\t\t3 -> Exit" << endl << endl;


	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;
}

int Report6_1()
{
	system("CLS");
	cout << endl << endl << "\t\t=================================================" << endl;
	cout << "\t\t\t\tAnnual Report" << endl;
	cout << "\t\t=================================================" << endl << endl;
	cout << "\t\t1 -> Total Costs On Each Category Among All The Faculties " << endl;
	cout << "\t\t2 -> Total Income On Each Category Among All The Faculties " << endl;
	cout << "\t\t3 -> Report Generation On Costs And Income " << endl;
	cout << "\t\t4 -> Exit" << endl << endl;

	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3/4]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 4))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;
}

int Report6_2()
{
	system("CLS");
	cout << endl << endl << "\t\t================================================" << endl;
	cout << "\t\t\t\tAnnual Report" << endl;
	cout << "\t\t================================================" << endl << endl;
	cout << "\t\t1 -> Total Credit " << endl;
	cout << "\t\t2 -> Total Debit " << endl;
	cout << "\t\t3 -> Exit" << endl << endl;

	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;
}

int Report4()
{
	system("CLS");
	cout << endl << endl << "\t\t================================================" << endl;
	cout << "\t\t\tAnnual Report By Faculty" << endl;
	cout << "\t\t================================================" << endl << endl;
	cout << "\t\t1 -> Faculty Report" << endl;
	cout << "\t\t2 -> Annual Report Generation " << endl;
	cout << "\t\t3 -> Exit" << endl << endl;

	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
		cin >> input;
		if ((cin.good()) && (input >= 1) && (input <= 3))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Invalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	return Case;
}

void Report()
{
	
	Manager manager;
	double input = -1;
	bool valid = false;
	int Case = 0;
	RecordManager recordmanager;
	Record* record = recordmanager.getRecord();
	if (record != NULL)
	{
		do {
			system("CLS");
			cout << endl << endl << "\t\t**************************************************************" << endl << endl;
			cout << "\t\t**                    Statistic Report			   **" << endl << endl;
			cout << "\t\t**************************************************************" << endl << endl;
			cout << "\t\t                1 -> Spending Report By Faculty		  " << endl;
			cout << "\t\t                2 -> Income Generation By Faculty	  " << endl;
			cout << "\t\t                3 -> Overview On Total Credit And Debit " << endl;
			cout << "\t\t                4 -> Annual Report By Faculty	  " << endl;
			cout << "\t\t                5 -> Annual Report UTeM	  " << endl;
			cout << "\t\t                6 -> Exit						  " << endl << endl;
			cout << "\t\t**************************************************************" << endl << endl;
			
			do
			{
				cout << endl << "\t\t Enter your option [1/2/3/4/5/6]: " << flush;
				cin >> input;
				if ((cin.good()) && (input >= 1) && (input <= 6))
				{
					//everything went well, we'll get out of the loop and return the value
					valid = true;
				}
				else
				{
					//something went wrong, we reset the buffer's state to good
					cin.clear();
					//and empty it
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\t\t Invalid input; please re-enter." << endl << endl;
				}
			} while (!valid);
			Case = input;

			switch (Case)
			{
			case 1: // Total Credit In A Fac
			{
				system("CLS");
				cout << endl << "\t\t======================================================================================" << endl;
				cout << "\t\t\t\t\tSpending Report By Faculty " << endl;
				cout << "\t\t======================================================================================" << endl << endl;
				string facultyID = manager.displayFacultyID();
				FacultyManager facultymanager;
				Faculty* faculty = facultymanager.getFaculty(facultyID);
				int selection = SelectSpend(faculty->faculty_name);
				if (selection == 1 || selection == 2)
				{
					manager.findMostSpend(facultyID, selection);
					system("pause");
				}
				
				break;
			}
			case 2: // Total Debit In A Fac
			{
				system("CLS");
				cout << endl << "\t\t======================================================================================" << endl;
				cout << "\t\t\t\t\tIncome Generation By Faculty " << endl;
				cout << "\t\t======================================================================================" << endl << endl;
				string facultyID = manager.displayFacultyID();
				FacultyManager facultymanager;
				Faculty* faculty = facultymanager.getFaculty(facultyID);
				int selection = SelectIncome(faculty->faculty_name);
				if (selection == 1 || selection == 2)
				{
					manager.findMostIncome(facultyID, selection);
					system("pause");
				}
			
				break;
			}
			case 3: //Total Credit All Fac
			{
				system("CLS");
				int option = OverviewOnCreditAndDebit();
				if (option == 1)
				{
					int selection = CreditAllFac();
					if (selection == 1 || selection == 2)
					{
						manager.credit(selection);
						system("pause");
					}
				}
				else if (option == 2)
				{
					int selection = DebitAllFac();
					if (selection == 1 || selection == 2)
					{
						manager.debit(selection);
						system("pause");
					}
				}
				
				
				break;
			}
			case 4:
			{
				system("CLS");
				cout << endl << "\t\t======================================================================================" << endl;
				cout << "\t\t\t\t\\ttAnnual Report By Faculty" << endl;
				cout << "\t\t======================================================================================" << endl << endl;
				int option = Report4();
				if (option == 1)
				{
					string facultyID = manager.displayFacultyID();

					if (facultyID != "NO")
					{
						string year = Year();
						RecordManager recordmanager;
						Record* record = recordmanager.checkYear(year);
						if (record != NULL)
						{
							manager.yearAndFaculty(year, facultyID);
							system("pause");
						}
						else
						{
							cout << "No record found in " << year << endl;
						}
					}
				}
				else if (option == 2)
				{
					string year = Year();
					manager.ReportGeneration4(year);
					system("pause");
				}
				
				
				break;
			}
			case 5:
			{
				system("CLS");
				char selection = Report6();
				if (selection == 1) //Anual Report In A Selected Year
				{
					int select1 = Report6_1();
					if (select1 == 1 || select1 == 2 || select1 == 3)
					{
						string year = Year();
						RecordManager recordmanager;
						Record* record = recordmanager.checkYear(year);
						if (record != NULL)
						{
							manager.ReportUTeM(year, select1);
							system("pause");
						}
						else
						{
							cout << "\t\t No record found in " << year << endl;
						}
					}
					// if select1 = 3, exit
				}
				else if (selection == 2)
				{
					DetailManager detailmanager;
					int numOfYear = detailmanager.numOfYear();
					if (numOfYear >= 3)
					{
						int select2 = Report6_2();
						if (select2 == 1)
						{
							manager.Latest3YearsCredit();
							system("pause");
						}
						else if (select2 == 2)
						{
							manager.Latest3YearsDebit();
							system("pause");
						}
					}
					else if (numOfYear != 0)
					{
						cout << "\n\t\t Since there are only " << numOfYear << "-years records, camparison between 3 years cannot be performed." << endl;
						system("pause");
					}
					else // numOfYear = 0
					{
						cout << "\n\t\t No records found.\n";
						system("pause");
					}
					
					
				}
				
				break;
			}
			case 6: //exit
			{
				system("CLS");
				break;
			}
			default:
			{
				cout << "\t\tYou are not entering 1, 2, 3, 4, 5 or 6 to exit!!!" << endl;
			}
			}
		} while (Case != 6);
	}
	else
		cout << "\t\tThe transaction record is empty ! Please insert at least a record " << endl;
	
}

boolean WelcomeStaff(string staffID)
{
	system("CLS");
	StaffManager staffmanager;
	Staff* staff = staffmanager.getStaffID(staffID);
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(staff->faculty_ID);
	cout << "\t\t.-----------------------------------------------------------------." << endl;
	cout << "\t\t|                             Welcome                             |" << endl;
	cout << "\t\t.-----------------------------------------------------------------." << endl << endl;
	cout  << setw(55) << right << staff->staff_name << setw(10) << right  << endl << endl;
	cout << setw(35) << right << "Staff from " << faculty->faculty_name << endl;
	bool test = false;
	do {
		cout << "\n\n\t\t Do you want to proceed with Staff Function ? (Y/N)  ";
		string ans;
		getline(cin >> ws, ans);
		if (ans == "Y" || ans == "y")
		{
			return true;
		}
		else if (ans == "N" || ans == "n")
		{
			return false;
		}
		else
		{
			cout << "\t\t Please select Y/N only ! " << endl;
			test = false;
		}

	} while (test == false);
	

}

void staffFunction(string staffID)
{

	StaffManager staffmanager;
	Staff* staff = staffmanager.getStaffID(staffID);

	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(staff->faculty_ID);

	double input = -1;
	bool valid = false;
	int Case = 0;
	bool welcome = WelcomeStaff(staffID);
	if (welcome == true)
	{
		do {
			system("CLS");
			cout << "\t\t**********************************************************************" << endl << endl;
			cout << "\t\t**			Staff Function				    **" << endl << endl;
			//cout << "\t\t\t\tWelcome, " << staff->staff_name << " !\n\n"; cout << "\t\tYou Are A Staff From " << faculty->faculty_name << endl << endl;
			cout << "\t\t**********************************************************************" << endl << endl;
			cout << "\t\t                1 -> Transaction Record						  " << endl;
			cout << "\t\t                2 -> Report							  " << endl;
			cout << "\t\t                3 -> Exit						  " << endl << endl;
			cout << "\t\t**********************************************************************" << endl << endl;
			do
			{
				cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
				cin >> input;
				if ((cin.good()) && (input >= 1) && (input <= 3))
				{
					//everything went well, we'll get out of the loop and return the value
					valid = true;
				}
				else
				{
					//something went wrong, we reset the buffer's state to good
					cin.clear();
					//and empty it
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\t\t Invalid input; please re-enter." << endl << endl;
				}
			} while (!valid);
			Case = input;
			switch (Case)
			{
			case 1:
			{
				system("CLS");
				transaction(staffID);
				break;
			}
			case 2: //Report
			{
				system("CLS");
				Report();
				break;
			}
			case 3: //exit
			{
				break;
			}
			default:
			{
				cout << "\t\t You are not entering 1, 2 or 3 to exit!!!" << endl;
			}
			}
		} while (Case != 3);
		system("CLS");
	}


	
}

void staffLogin()
{
	system("CLS");
	Manager manager;
	string staffID;
	
	cout << endl <<"\t\t\t  Financial Management System(FMS)" << endl;
	cout << endl << "\t\t**************************************************************" << endl << endl;
	cout << "\t\t\t\t    Staff Login" << endl << endl;
	cout << "\t\t**************************************************************" << endl << endl << endl;
	
	cout << "\t\t\tEnter your staff ID: ";
	getline(cin >> ws, staffID);
	cout << endl << "\t\t\tEnter your password: ";

	char password[100];
	
	int index = 0;
	while (1)
	{
		char ch;
		ch = _getch();
		if (ch == 8)               // if backspace
		{
			if (index != 0)
			{
				cout << char(8) << " " << char(8);
				index--;
			}
		}
		else if (ch == '\r')        // enter then break;
		{
			password[index] = '\0';
			cout << endl;
			break;
		}
		else
		{
			cout << "*";
			password[index++] = ch;
		}
	}

	bool success = manager.loginStaff(staffID, password);
	if (success == true)
	{
		staffFunction(staffID); //display staff's functions
	}
	system("pause");

}

void login()
{
	
	double input = -1;
	bool valid = false;
	int Case = 0;

	Manager manager;
	do
	{
		system("CLS");
		cout << endl << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t\t\t\tLOGIN PAGE" << endl << endl;
		cout << "\t\t**************************************************************" << endl << endl;
		cout << "\t\t                1 -> Admin Login							  " << endl;
		cout << "\t\t                2 -> Staff Login						  " << endl;
		cout << "\t\t                3 -> Exit	" << endl << endl;
		cout << "\t\t**************************************************************" << endl << endl;
		
		do
		{
			cout << endl << "\t\t Enter your option [1/2/3]: " << flush;
			cin >> input;
			if ((cin.good()) && (input >= 1) && (input <= 3))
			{
				//everything went well, we'll get out of the loop and return the value
				valid = true;
			}
			else
			{
				//something went wrong, we reset the buffer's state to good
				cin.clear();
				//and empty it
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\t\t Invalid input; please re-enter." << endl << endl;
			}
		} while (!valid);
		Case = input;
		
		if (Case == 1)
		{
			adminLogin();
		}
		else if (Case == 2)
		{
			staffLogin();
		}
		else if (Case == 3)
		{
			//go back to firstpage()
		}
	
	} while (Case != 3);
	
}

int main()
{
	Manager manager;

	double input = -1;
	bool valid = false;
	int Case = 0;

	
	do
	{
		firstpage();
		cout << endl << "\t\tEnter your option [1/2]: " << flush;
		cin >> input;
		if ((cin.good()) && (input == 1) || (input == 2))
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			cin.clear();
			//and empty it
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\tInvalid input; please re-enter." << endl << endl;
		}
	} while (!valid);
	Case = input;
	cout << Case << endl;
	if (Case == 1) //Login
	{
		login();
		system("CLS");
		cout << endl << endl << "\n\n==================================================================================================\n"; cout << "\t\t\t\tThanks For Using FMS !!" << endl; cout << "==================================================================================================\n\n\n";
		system("pause");
	}
	else if (Case == 2) //Exit
	{
		system("cls");
		cout << endl << endl << "\n\n==================================================================================================\n"; cout << "\t\t\t\tThanks For Using FMS !!" << endl; cout << "==================================================================================================\n\n\n";
		system("pause");
	}
	
	
	
	return 0;
}


