#include "Manager.h"
#include <regex>
using namespace std;

string TwoDecimal(double rm)
{
	string temp, amount;
	stringstream ss;
	ss << fixed << setprecision(2) << rm / 10;
	temp = ss.str();
	amount = "RM " + temp;
	return amount;
}

void displayCREDIT()
{
	cout << endl;
	cout << " \t\t CATEGORY OF CREDIT " << endl << endl;
	cout << " \t\t 1. WATER BILLS    " << endl;
	cout << " \t\t 2. UTILITY BILLS      " << endl;
	cout << " \t\t 3. MAINTENANCE FEES   " << endl;
	cout << " \t\t 4. OTHER FEES    " << endl << endl;
	
}

void displayDEBIT()
{
	cout << endl;
	cout << " \t\t CATEGORY OF DEBIT " << endl << endl;
	cout << " \t\t 1. BUDGET FROM UTeM " << endl;
	cout << " \t\t 2. SPONSORSHIP " << endl;
	cout << " \t\t 3. STUDENT FEES " << endl;
	cout << " \t\t 4. LAB RENTAL FEES " << endl << endl;

}

string Manager::displayFacultyID()
{
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	vector <string> ID;
	vector <int> number;
	cout << endl << "\t\t======================================================================================" << endl;
	cout << "\t\t\t\t\t\tFaculty ID " << endl;
	cout << "\t\t======================================================================================" << endl;
	int count = 1;
	do
	{
		cout << "\t\t  " << count << ". " << faculty->faculty_ID << "  ->  " << faculty->faculty_name << endl;
		number.push_back(count);
		ID.push_back(faculty->faculty_ID);
		
		faculty = faculty->next;
		if (faculty != NULL)
			count++;
	} while (faculty != NULL);
	cout << "\t\t======================================================================================" << endl << endl;

	string selection;
	int choice;
	for (int i = 0; i < count; i++)
	{
		if (i == count - 1) //last item
		{
			selection += to_string(i + 1);

		}
		else
		{
			selection += to_string(i + 1) + '/';
		}
	}
	bool test = false;
	do {
		cout << "\t\t Enter Faculty ID [" << selection << "]: ";
		cin >> choice;
		
		for (int i = 0; i < count; i++)
		{
		
			if (choice == number[i])
			{
				test = true;
				return ID[i];
			}
		}
		cout << "\t\t Please make sure you are entering " << selection << endl;
	} while (test == false);
	
	
}

void displayFacultyForReport()
{
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	vector <string> ID;
	vector <int> number;
	cout << endl << "\t\t======================================================================================" << endl;
	cout << "\t\t\t\t\t\tFaculty ID " << endl;
	cout << "\t\t======================================================================================" << endl;
	int count = 1;
	do
	{
		cout << "\t\t  " << count << ". " << faculty->faculty_ID << "  ->  " << faculty->faculty_name << endl;
		number.push_back(count);
		ID.push_back(faculty->faculty_ID);

		faculty = faculty->next;
		if (faculty != NULL)
			count++;
	} while (faculty != NULL);
	cout << "\t\t======================================================================================" << endl << endl;
}

bool gotspace(string x)
{

	bool n = false;
	for (auto i : x)
	{
		if (isspace(i))
			n = true;
	}
	if (n == true)
		return true;
	else
		return false;
}

bool checkEmail(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	bool test = regex_match(email, pattern);
	if (test == true)
	{

		return true;
	}
	else
		return false;
}

bool checkContact(string contact)
{

	if ((contact.size() == 10) || (contact.size() == 11))
	{
		for (auto i : contact)
		{
			if (isdigit(i) == 0)
			{
				return false;
			}
				
		}
		if (contact[0] == '0' && contact[1] == '1')
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
		
}

bool checkPassword(string password)
{
	if (password.size() <= 20 && password.size() >= 6) //size of password should be at Range: 6-20 characters
	{
		return true;
	}
	else
		return false;
}

bool checkDate(string date)
{
	if (date[4] == '-' && date[7] == '-')
	{
		
		if ((date[5] == '1' || date[5] == '0') && date[0] != '0' && (date[8] == '0' || date[8] == '1' || date[8] == '2' || date[8] == '3'))
		{
			if (date[5] == '1' && (date[6] == '0' || date[6] == '1' || date[6] == '2'))
			{
				return true;
			}
			else if (date[5] == '0')
			{
				return true;
			}
			
		}
	
	}
	return false;

}

void Manager:: testAddStaff(string adminID)
{
	cout << "\n\n\t\t==============================================" << endl;
	cout <<"\t\t\t\tAdd New Staff" << endl;
	cout << "\t\t==============================================" << endl << endl;
	Staff* staff = new Staff();
	FacultyManager facultymanager;
	Faculty* faculty = NULL;
	


	string facultyID = displayFacultyID();
	staff->faculty_ID = facultyID;

	cout << "\n\t\t Staff Name: ";
	getline(cin >> ws, staff->staff_name);

	bool checkE = false;
	bool checkSpace = false;
	do
	{
		cout << "\n\t\t Staff Email: ";
		getline(cin >> ws, staff->staff_email);
		checkE = checkEmail(staff->staff_email);
		checkSpace = gotspace(staff->staff_email);
	} while (checkE == false && checkSpace == false);

	bool checkN = false;
	do
	{
		cout << "\n\t\t Staff Contact(01XXXXXXXXX): ";
		getline(cin >> ws, staff->staff_contact);
		checkN = checkContact(staff->staff_contact);
		checkSpace = gotspace(staff->staff_contact);
		if (checkN == false && checkSpace == false)
		{
			cout << "\t\t Incorrect format for contact number !!! Please try again !!!" << endl;
		}
	} while (checkN == false && checkSpace == false);

	bool checkP = false;
	
	do
	{
		cout << "\n\t\t Staff Password: ";
		getline(cin >> ws, staff->staff_password);
		checkP = checkPassword(staff->staff_password);
		checkSpace = gotspace(staff->staff_password);
		if (checkP == false && checkSpace == false)
		{
			cout << "\t\t Incorrect format for password !!! Please try again !!!" << endl;
			cout << "\t\t Password should not greater than 20 characters and less than 6 characters !!!" << endl;
		}
	} while (checkP == false && checkSpace == false);




	StaffManager staffmanager;
	int status = staffmanager.addStaff(staff, adminID);
	if (status != 0)
	{
		cout << "\n\t\t Sucessfully added a new staff(" << staff->staff_name << ")" << endl;
	}
	else
		cout << "\n\t\t Failed !!!! Please try again!!!";
}

void Manager::testUpdateStaff()
{
	cout << "\n\n\t\t==============================================" << endl;
	cout << "\t\t\t\t  Update Staff" << endl;
	cout << "\t\t==============================================" << endl << endl;

	string staffID;
	double input = -1;
	bool valid = false;
	int Case = 0;
	StaffManager staffmanager;
	cout << "\n\t\t Enter Staff ID to update staff info: ";
	cin >> staffID;
	Staff* staff = staffmanager.getStaffID(staffID);
	if (staff != NULL)
	{
		cout << "\n\t\t [1] -> Update Faculty ID" << endl;
		cout << "\t\t [2] -> Update Staff Name" << endl;
		cout << "\t\t [3] -> Update Staff Email" << endl;
		cout << "\t\t [4] -> Update Staff Contact" << endl;
		cout << "\t\t [5] -> Update Staff Password" << endl;
		cout << "\t\t [6] -> Exit" << endl;
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
		case 1:
		{
			
			string facultyID = displayFacultyID();
			staff->faculty_ID = facultyID;
			break;
		}
		case 2:
		{
			cout << "\n\t\t Staff Name: ";
			getline(cin >> ws, staff->staff_name);
			break;
		}
		case 3:
		{
			bool checkE = false;
			bool checkSpace = false;
			do
			{
				cout << "\n\t\t Staff Email: ";
				getline(cin >> ws, staff->staff_email);
				checkE = checkEmail(staff->staff_email);
				checkSpace = gotspace(staff->staff_email);
				if (checkE == false || checkSpace == false)
				{
					cout << "\t\t Please input correct format of email !\n\n";
				}
			} while (checkE == false && checkSpace == false);
			break;
		}
		case 4:
		{
			bool checkN = false;
			bool checkSpace = false;
			do
			{
				cout << "\n\t\t Staff Contact(01XXXXXXXXX): ";
				getline(cin >> ws, staff->staff_contact);
				checkN = checkContact(staff->staff_contact);
				checkSpace = gotspace(staff->staff_contact);
				if (checkN == false && checkSpace == false)
				{
					cout << "\t\t Incorrect format for contact number !!! Please try again !!!" << endl;
				}
			} while (checkN == false && checkSpace == false);
			break;
		}
		case 5:
		{
			bool checkP = false;
			bool checkSpace = false;
			cout << endl << "\t\t Please take note that password should greater or equal than 6 characters and less than 21 characters" << endl;
			do
			{
				cout << "\n\t\t Staff Password: ";
				getline(cin >> ws, staff->staff_password);
				checkP = checkPassword(staff->staff_password);
				checkSpace = gotspace(staff->staff_password);
				if (checkP == false && checkSpace == false)
				{
					cout << "\t\t Incorrect format for password !!! Please try again !!!" << endl;
				}
			} while (checkP == false && checkSpace == false);
			break;
		}
		case 6:
		{
			break;
		}
		default:
		{
			std::cout << "\n\t\t Error!!! You are not entering 1, 2, 3, 4, 5 or 6 !!!" << std::endl << "**Please try again !!!" << std::endl;
			break;
		}
		}



		int status = staffmanager.updateStaff(Case, staff);
		if (status != 0)
			cout << "\n\t\t Sucessfully updated a staff(" << staff->staff_name << ")" << endl;
		else
			cout << "\n\t\t Failed !!! Please try again !!!" << endl;
	}
	else 
	{
		cout << "\n\t\t Staff with " << staffID << " not found!!!" << endl;
	}
	
}

string UpdateStaff(string facultyID, string staffName) // return staffID or return No  ( No staff found in the faculty)
{
	StaffManager staffmanager;
	Staff* staff = staffmanager.getStaff(facultyID);
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	vector <string> staffID, staffname;
	if (staff != NULL)
	{
		do {
			staffID.push_back(staff->staff_ID);
			staffname.push_back(staff->staff_name);
			staff = staff->next;
		} while (staff != NULL);
	}

	if (staffID.size() != 0) //got staff in the faculty
	{
		
		string selection;
		cout << "\n\n\t\t ======================================" << endl;
		cout << "\t\t\t\tList Of Staffs" << endl;
		cout << "\t\t ======================================" << endl;
		for (int i = 0; i < staffID.size(); i++)
		{
			cout << "\t\t " << i + 1 << ". " << staffID[i] << " -- " << staffname[i] << endl;
			if (i == staffID.size() - 1) //last item
			{
				selection += to_string(i + 1);
			}
			else
			{
				selection += to_string(i + 1) + '/';
			}
		}
		int option;
	
		if (staffID.size() > 1)
		{
			bool test = false;
			do {
				cout << endl << "\n\t\t Please choose other staff to replace " << staffName << "[" << selection << "]: ";
				cin >> option;
				if (option >= 1 && option <= staffID.size()) //within the range of option
				{
					cout << "\n\t\t You select " << staffname[option - 1] << " with ID " << staffID[option - 1] << " to replace " << staffName << endl;
					test = true;
					return staffID[option - 1];
				}
			} while (test == false);
		}
		return "LESSTHAN1";

	}
	else
	{
		cout << "\t\t No staff found in " << faculty->faculty_name << endl;
		return "NO";
	}
		
}

void Manager::testDeleteStaff()
{
	string selection;
	string staffID;
	StaffManager staffmanager;
	cout << "\n\n\t\t ======================================" << endl;
	cout << "\t\t\t  Delete Staff" << endl;
	cout << "\t\t ======================================" << endl;
	cout << "\n\t\t Enter Staff ID to delete staff info: ";
	cin >> staffID;
	Staff* staff = staffmanager.getStaffID(staffID);
	RecordManager recordmanager;
	if (staff != NULL)
	{
		do
		{
			do {
				cout << endl << "\t\t Are you sure you want to delete " << staff->staff_name << " with id " << staffID << " ? (Y/N): ";
				getline(cin >> ws, selection);

			} while (selection != "y" && selection != "Y" && selection != "n" && selection != "N");
			if (selection == "y" || selection == "Y")
			{
				bool checkGotRecord = recordmanager.findStaff(staffID); //check got transaction record
				if (checkGotRecord == true)
				{
					string update = UpdateStaff(staff->faculty_ID, staff->staff_name);
					FacultyManager facultymanager;
					Faculty* faculty = facultymanager.getFaculty(staff->faculty_ID);
					if (update == "NO")
					{
						cout << "\n\t\t No staff found in " << faculty->faculty_name << endl;
					}
					else if (update == "LESSTHAN1")
					{
						cout << "\n\t\t There is only one staff in the faculty " << endl;
						cout << "\t\t So, " << staff->staff_name << " cannot be deleted !" << endl;
					}
					else
					{
						int update1 = recordmanager.updateReplace(staffID, update); //replace deleted staff
						int status = staffmanager.deleteStaff(staff);
						if (status != 0)
							cout << "\n\t\t Sucessfully deleted a staff(" << staff->staff_name << ")" << endl;
						else
							cout << "\n\t\t Failed !!! Please try again !!!" << endl;
					}
			

				}
				else
				{
					int status = staffmanager.deleteStaff(staff);
					if (status != 0)
						cout << "\n\t\t Sucessfully deleted a staff(" << staff->staff_name << ")" << endl;
					else
						cout << "\n\t\t Failed !!! Please try again !!!" << endl;
				}
				
				break;
			}
			else if (selection == "n" || selection == "N")
			{
				break;
			}
			else
				cout << "\n\t\t Please enter (Y/N) to proceed !!!" << endl;
		} while (selection != "y" || selection != "Y");

		
	}
	else
		cout << "\n\t\t Staff with " << staffID << " not found!!!" << endl;
}

void Manager::testSearchStaff()
{
	cout << "\n\n\t\t ================================================================" << endl;
	cout << "\t\t\t\t\tSearch Staff" << endl;
	cout << "\t\t ==================================================================" << endl;
	string staffID;
	StaffManager staffmanager;
	cout << "\n\t\t Enter Staff ID to search staff info: ";
	cin >> staffID;
	Staff* staff = staffmanager.getStaffID(staffID);
	cout << endl << setw(5) << right << "Staff ID" << setw(10) << right << "Admin ID" << setw(13) << right << "Faculty ID" << setw(17) << right << "Staff Name" << setw(23) << right << "Staff Email" << setw(22) << right << "Staff Contact" << setw(22) << right <<"Staff Password" << endl;
	if (staff != NULL)
	{
		cout << setw(5) << right << staff->staff_ID << setw(10) << right << staff->admin_ID << setw(13) << right << staff->faculty_ID << setw(19) << right << staff->staff_name << setw(29) << right << staff->staff_email <<setw(16) << right << staff->staff_contact << setw(18) << right << staff->staff_password << endl << endl;
	}
	else
		cout << "\n\t\t" << staffID << " not found !!! Please try again !!!" << endl;
}

void Manager::viewAllStaff()
{
	StaffManager staffManager;
	Staff* staffs = staffManager.getStaffs();
	cout << "\n\n\t\t ================================================================" << endl;
	cout << "\t\t\t\t\tView All Staffs" << endl;
	cout << "\t\t ==================================================================\n\n" << endl;
	if (staffs != NULL)
	{
		Staff* staff = staffs;
		cout << endl << setw(5) << right << "Staff ID" << setw(10) << right << "Admin ID" << setw(13) << right << "Faculty ID" << setw(17) << right << "Staff Name" << setw(23) << right << "Staff Email" << setw(22) << right << "Staff Contact" << setw(22) << right << "Staff Password" << endl;
		do
		{
			cout << setw(5) << right << staff->staff_ID << setw(10) << right << staff->admin_ID << setw(13) << right << staff->faculty_ID << setw(19) << right << staff->staff_name << setw(29) << right << staff->staff_email << setw(16) << right << staff->staff_contact << setw(18) << right << staff->staff_password << endl;
		

			staff = staff->next;
		} while (staff != NULL);
		cout << endl << endl;
	}
	else
		std::cout << "\n\t\t No staff found" << std::endl;

}


void Manager::testAddFaculty(string adminID)
{
	system("CLS");
	Faculty* faculty = new Faculty();
	faculty->admin_ID = adminID;
	cout << "\n\n\t\t ======================================" << endl;
	cout << "\t\t         Insert New Faculty" << endl;
	cout << "\t\t ======================================" << endl << endl;
	cout << "\t\t Faculty Name: ";
	getline(cin >> ws, faculty->faculty_name);
	cout << "\n\t\t Faculty Address: ";
	getline(cin >> ws, faculty->faculty_address);
	
	bool checkN = false;
	bool checkSpace = false;
	do
	{
		cout << "\n\t\t Faculty Contact(01XXXXXXXXX): ";
		getline(cin >> ws, faculty->faculty_contact);
		checkN = checkContact(faculty->faculty_contact);
		checkSpace = gotspace(faculty->faculty_contact);
		if (checkN == false && checkSpace == false)
		{
			cout << "\t\t Incorrect format for contact number !!! Please try again !!!" << endl;
		}
	} while (checkN == false && checkSpace == false);

	faculty->faculty_balance = 0;
	FacultyManager facultymanager;
	int status = facultymanager.insertFaculty(faculty);
	if (status != 0)
	{
		cout << "\n\t\t Sucessfully added a new faculty(" << faculty->faculty_name << ")" << endl;
	}
	else
		cout << "\n\t\t Failed !!!! Please try again!!!";
}

void Manager::testUpdateFaculty()
{

	string facultyID;
	FacultyManager facultymanager;
	cout << "\n\n\t\t ======================================" << endl;
	cout << "\t\t          Update Faculty" << endl;
	cout << "\t\t ======================================" << endl;
	cout << "\n\t\t Enter Faculty ID to update faculty info: ";
	cin >> facultyID;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	if(faculty != NULL)
	{
		double input = -1;
		bool valid = false;
		int Case = 0;
		cout << "\n\t\t [1] -> Update Faculty Name" << endl;
		cout << "\t\t [2] -> Update Faculty Address" << endl;
		cout << "\t\t [3] -> Update Faculty Contact" << endl;
		cout << "\t\t [4] -> Exit" << endl;
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
		switch (Case)
		{
		case 1:
		{
			cout << "\n\t\t Faculty Name: ";
			getline(cin >> ws, faculty->faculty_name);
			break;
		}
		case 2:
		{
			cout << "\n\t\t Faculty Address: ";
			getline(cin >> ws, faculty->faculty_address);
			break;
		}
		case 3:
		{
			bool checkN = false;
			bool checkSpace = false;
			do
			{
				cout << "\n\t\t Faculty Contact(01XXXXXXXXX): ";
				getline(cin >> ws, faculty->faculty_contact);
				checkN = checkContact(faculty->faculty_contact);
				checkSpace = gotspace(faculty->faculty_contact);
				if (checkN == false && checkSpace == false)
				{
					cout << "\t\t Incorrect format for contact number !!! Please try again !!!" << endl;
				}
			} while (checkN == false && checkSpace == false);
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			std::cout << "\n\t\t Error!!! You are not entering 1, 2, 3 or 4 !!!" << std::endl << "**Please try again !!!" << std::endl;
			break;
		}
		}


		int status = facultymanager.updateFaculty(Case, faculty);
		if (status != 0)
			cout << "\n\t\t Sucessfully updated a faculty(" << faculty->faculty_name << ")" << endl;
		else
			cout << "\n\t\t Failed !!! Please try again !!!" << endl;
	}
	else
		cout << "\n\t\t Faculty with " << facultyID << " not found!!!" << endl;
}

void Manager::testDeleteFaculty()
{
	string selection;
	string facultyID;
	FacultyManager facultymanager;
	cout << "\n\n\t\t ======================================" << endl;
	cout << "\t\t          Delete Faculty" << endl;
	cout << "\t\t ======================================" << endl;
	cout << "\n\t\t Enter Faculty ID to delete faculty info: ";
	cin >> facultyID;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	if (faculty != NULL)
	{
		do
		{
			do {
				
				cout << "\n\t\t If you delete a faculty, it will automatically delete all of the staff and records for\n ";
				cout << "\t\t " << faculty->faculty_name << endl;
				cout << "\n\t\t Are you sure you want to delete \n"; 
				cout << "\t\t " << faculty->faculty_name << " ? (Y/N): ";
				getline(cin >> ws, selection);

			} while (selection != "y" && selection != "Y" && selection != "n" && selection != "N");

			if (selection == "y" or selection == "Y")
			{
				DetailManager detailmanager;
				RecordManager recordmanager;
				Record* records = recordmanager.getFac_Records(facultyID);
				
				if (records != NULL)
				{
					do
					{
						int status1 = detailmanager.deleteDetail(records->record_ID);
						int status2 = recordmanager.deleteRecord(records);
						records = records->next;

					} while (records != NULL);
				}
				
				StaffManager staffmanager;
				Staff* staff = staffmanager.getStaff(facultyID);
				if (staff != NULL)
				{
					do {
						int status3 = staffmanager.deleteStaff(staff);
						staff = staff->next;
					} while (staff != NULL);
				}
				
				int status = facultymanager.deleteFaculty(faculty);
				if (status != 0)
					cout << "\n\t\t Sucessfully deleted a faculty(" << faculty->faculty_name << ")" << endl;
				else
					cout << "\n\t\t Failed !!! Please try again !!!" << endl;
				break;
			}
			else if (selection == "n" or selection == "N")
			{
				break;
			}
			else
				cout << "\t\t Please enter (Y/N) to proceed !!!" << endl;
		} while (selection != "y" or selection != "Y");
		
	}
	else
		cout << "\n\t\t Faculty with " << facultyID << " not found!!!" << endl;
}

void Manager::testSearchFaculty()
{
	string facultyID;
	FacultyManager facultymanager;
	cout << "\n\n\t\t ======================================" << endl;
	cout << "\t\t          Search Faculty" << endl;
	cout << "\t\t ======================================" << endl;
	cout << "\n\t\t Enter Faculty ID to search faculty info: ";
	cin >> facultyID;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	int num = 1;
	if (faculty != NULL)
	{
		cout << setw(5) << "\n\n----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "*" << num << "*" << endl;
		cout << "* * * *  " << endl;
		cout << setw(5) << "Faculty ID      - " << faculty->faculty_ID << endl;
		cout << setw(5) << "Faculty Name    - " << faculty->faculty_name << endl;
		cout << setw(5) << "Faculty Address - " << faculty->faculty_address << endl;
		cout << setw(5) << "Faculty Contact - " << faculty->faculty_contact << endl;
		cout << setw(5) << "Faculty Current Balance - " << TwoDecimal(faculty->faculty_balance) << endl;
		cout << setw(5) << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
		num++;
	}
	else
		cout << "\n\t\t " << facultyID << " not found !!! Please try again !!!" << endl;
}

void Manager::viewAllFaculty()
{
	FacultyManager facultymanager;
	Faculty* faculties = facultymanager.getFaculty();

	if (faculties != NULL)
	{
		cout << "\n\n\t\t ======================================" << endl;
		cout << "\t\t          View All Faculty" << endl;
		cout << "\t\t ======================================" << endl << endl;

		int num = 1;
		Faculty* faculty = faculties;
		do
		{
			cout << setw(5) << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "*  " << num << "  *" << endl;
			cout << "* * * *  " << endl;
			cout << setw(5) << "Faculty ID      - " << faculty->faculty_ID << endl;
			cout << setw(5) << "Faculty Name    - " << faculty->faculty_name << endl;
			cout << setw(5) << "Faculty Address - " << faculty->faculty_address << endl;
			cout << setw(5) << "Faculty Contact - " << faculty->faculty_contact << endl;
			cout << setw(5) << "Faculty Current Balance - " << TwoDecimal(faculty->faculty_balance) << endl;
			cout << setw(5) << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
			num++;

			faculty = faculty->next;
		} while (faculty != NULL);
		cout << endl << endl;
	}
	else
	{
		cout << "\n\t\t No faculty found" << std::endl;
	}
	

}

double Manager::FacultyBalance(string facultyID)
{
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	return faculty->faculty_balance;
}

void Manager::testAddRecord(string staffID)
{
	system("CLS");
	StaffManager staffmanager;
	Staff* staff = staffmanager.getStaffID(staffID);

	Record* record = new Record();
	RecordManager recordmanager;
	record->record_ID = recordmanager.assignID();
	record->staff_ID = staffID;

	int res1 = 0, res2 = 0;
	bool test = false;
	string Type;
	cout << "\t\t ======================================" << endl;
	cout << "\t\t     Insert New Transaction Record" << endl;
	cout << "\t\t ======================================" << endl << endl;


	double input = -1;
	bool valid = false;
	int Case = 0;

	do
	{
		cout << "\t\t CREDIT - 1\tDEBIT - 2\n\n" << "\t\t Type [1/2]: " << flush;
		cin >> input;
		if ((cin.good()) && ((input == 1) || (input == 2)))
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
			cout << "\t\t Invalid!! Please make sure that you input correct format of type !!!" << endl << endl;
		}
	} while (!valid);
	Case = input;
	if (Case == 1)
	{
		record->type = "CREDIT";
	}
	else // Case = 2
	{
		record->type = "DEBIT";
	}

	string selection;


	if (record->type == "CREDIT")
	{
		displayCREDIT();
		bool test = false;
		do {

			cout << "\t\t Select 1-4 for " << record->type << endl << endl;
			cout << "\t\t Record Category [1/2/3/4]: ";
			getline(cin >> ws, selection);

			char select;
			if (selection.size() != 1)
			{
				select = 'a';
			}
			else
			{
				select = selection[0];
			}



			switch (select)
			{
			case '1':
			{
				record->record_name = "WATER BILLS";
				cout << "\t\t You selected 1 -> WATER BILLS (CREDIT) " << endl;
				test = true;

				break;
			}
			case '2':
			{
				record->record_name = "UTILITY BILLS";
				cout << "\t\t You selected 2 -> UTILITY BILLS (CREDIT) " << endl;
				test = true;

				break;
			}
			case '3':
			{
				record->record_name = "MAINTENANCE FEES";
				cout << "\t\t You selected 3 -> MAINTENANCE FEES (CREDIT) " << endl;
				test = true;

				break;
			}
			case '4':
			{
				record->record_name = "OTHER FEES";
				cout << "\t\t You selected 4 -> OTHER FEES (CREDIT) " << endl;
				test = true;

				break;
			}
			default:
			{
				cout << "\t\t Error !!! You are not entering 1, 2, 3, or 4" << endl;
				break;
			}
			}
		} while (test == false);

	}
	else //debit
	{
		bool test = false;
		do {
			displayDEBIT();
			cout << "\t\t Select 1-4 for the type of " << record->type << endl;
			cout << "\t\t Record Name: ";
			cin >> selection;

			char select;
			if (selection.size() != 1)
			{
				select = 'a';
			}
			else
			{
				select = selection[0];
			}



			switch (select)
			{
			case '1':
			{
				record->record_name = "BUDGET FROM UTeM";
				cout << "\t\t You selected 1 -> BUDGET FROM UTeM (DEBIT) " << endl;
				test = true;
				break;
			}
			case '2':
			{
				record->record_name = "SPONSORSHIP";
				cout << "\t\t You selected 2 -> SPONSORSHIP (DEBIT) " << endl;
				test = true;
				break;
			}
			case '3':
			{
				record->record_name = "STUDENT FEES";
				cout << "\t\t You selected 3 -> STUDENT FEES (DEBIT) " << endl;
				test = true;
				break;
			}
			case '4':
			{
				record->record_name = "LAB RENTAL FEES";
				cout << "\t\t You selected 4 -> LAB RENTAL FEES (DEBIT) " << endl;
				test = true;
				break;
			}
			default:
			{
				cout << "\t\t Error !!! You are not entering 1, 2, 3, or 4" << endl;
				break;
			}
			}
		} while (test == false);
	}


	int status1 = recordmanager.insertRecord(record);
	if (status1 != 0) //successfully insert a record
	{
		//Add detail
		cout << "\t\t Please enter record's detail" << endl;
		cout << "\t\t =========================================" << endl << endl;
		bool test = testAddDetail(record->record_ID);
		string detailID = record->record_ID;
		detailID[0] = 'D';
		DetailManager detailmanager;
		Detail* detail = detailmanager.getDetail(detailID);

		if (test == true) //successfully inserted a detail
		{
			FacultyManager facultymanager;
			Faculty* faculty = facultymanager.getFaculty(staff->faculty_ID);

			double curr_balance = faculty->faculty_balance;

			double total = (detail->price) * (detail->quantity);



			if (curr_balance > total && record->type == "CREDIT")
			{
				faculty->faculty_balance = curr_balance - total;
				int status = facultymanager.updateFaculty(4, faculty);
				cout << "\t\t Sucessfully added a new record(" << record->record_ID << ")" << endl;
			}
			else if (record->type == "DEBIT")
			{
				faculty->faculty_balance = curr_balance + total;
				int status = facultymanager.updateFaculty(4, faculty);
				cout << "\t\t Sucessfully added a new record(" << record->record_ID << ")" << endl;
			}
			else
			{
				int status = recordmanager.deleteRecord(record);
				if (status != 0)
				{
					cout << "\n\t\t Since " << faculty->faculty_name << " do not have enough balance, this transaction record cannot be executed !!" << endl;
				}
				else
				{
					cout << "\n\t\t Record " << record->record_ID << " does not exist !!" << endl;

				}

			}

		}
		else // Detail is not inserted
		{
			cout << "\t\t Detail is not inserted. Please try again !!!" << endl;
			int status = recordmanager.deleteRecord(record);
		}
	}
	else //Record is not inserted
	{
		cout << "\t\t Failed !!!! Please try again!!!";
	}
}

void Manager::testUpdateRecord(string staffID)
{
	string recordID;
	RecordManager recordmanager;
	cout << "\t\t ======================================" << endl;
	cout << "\t\t      Update Transaction Record" << endl;
	cout << "\t\t ======================================" << endl << endl;
	cout << "\n\t\t Enter Record ID to update record info: ";
	cin >> recordID;
	string facultyID = recordmanager.getFacultyID(recordID);
	Record* record = recordmanager.getRecord(recordID);
	double Transaction = 0;
	StaffManager staffmanager;
	Staff* staff = staffmanager.getStaffID(staffID);
	char selection = '0';
	string Type;
	bool update = true;



	if (record != NULL)
	{
		bool check = recordmanager.findRecord(staff->faculty_ID, recordID); //check Record belongs to which faculty
		if (check == true)
		{
			
			FacultyManager facultymanager;
			Faculty* faculty = facultymanager.getFaculty(facultyID);
			double curr_balance = faculty->faculty_balance;
			string detailID = recordID;
			detailID[0] = 'D';
			DetailManager detailmanager;
			Detail* detail = detailmanager.getDetail(detailID);
			cout << "\t\t [1] -> Update Type And Record Name" << endl;
			cout << "\t\t [2] -> Update Description" << endl;
			cout << "\t\t [3] -> Update Quantity" << endl;
			cout << "\t\t [4] -> Update Price Per Unit (RM)" << endl;
			cout << "\t\t [5] -> Update Date" << endl;
			cout << "\t\t [6] -> Exit" << endl;
			cout << "\t\t Enter Your Option [1/2/3/4/5/6]: ";
			cin >> selection;

			switch (selection)
			{

			case '1': //type and name
			{
				double amount = faculty->faculty_balance;
				bool isCredit;
				if (record->type == "CREDIT")
				{
					isCredit = true;
				}
				else
					isCredit = false;

				double input = -1;
				bool valid = false;
				int Case = 0;

				do
				{
					cout << "\t\t CREDIT - 1\tDEBIT - 2\n\n" << "\t\t Type [1/2]: " << flush;
					cin >> input;
					if ((cin.good()) && ((input == 1) || (input == 2)))
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
						cout << "\t\t Invalid!! Please make sure that you input correct format of type !!!" << endl << endl;
					}
				} while (!valid);
				Case = input;
				if (Case == 1)
				{
					record->type = "CREDIT";
				}
				else // Case = 2
				{
					record->type = "DEBIT";
				}

				string selection;


				if (record->type == "CREDIT")
				{
					bool test = false;
					do {
						displayCREDIT();
						cout << "\t\t Select 1-4 for " << record->type << endl;
						cout << "\t\t Record Name: ";
						cin >> selection;

						char select;
						if (selection.size() != 1)
						{
							select = 'a';
						}
						else
						{
							select = selection[0];
						}



						switch (select)
						{
						case '1':
						{
							record->record_name = "WATER BILLS";
							cout << "\t\t You selected 1 -> WATER BILLS (CREDIT) " << endl;
							test = true;
							break;
						}
						case '2':
						{
							record->record_name = "UTILITY BILLS";
							cout << "\t\t You selected 2 -> UTILITY BILLS (CREDIT) " << endl;
							test = true;
							break;
						}
						case '3':
						{
							record->record_name = "MAINTENANCE FEES";
							cout << "\t\t You selected 3 -> MAINTENANCE FEES (CREDIT) " << endl;
							test = true;
							break;
						}
						case '4':
						{
							record->record_name = "OTHER FEES";
							cout << "\t\t You selected 4 -> OTHER FEES (CREDIT) " << endl;
							test = true;
							break;
						}
						default:
						{
							cout << "\t\t Error !!! You are not entering 1, 2, 3, or 4" << endl;
							break;
						}
						}
					} while (test == false);

					if (isCredit == false) //Originally is debit but now is credit
					{
						amount -= (record->total) * 2;
					}


					faculty->faculty_balance = amount;
				}
				else //debit
				{
					bool test = false;
					do {
						displayDEBIT();
						cout << "\t\t Select 1-4 for the type of " << record->type << endl;
						cout << "\t\t Record Name: ";
						cin >> selection;
						char select;
						if (selection.size() != 1)
						{
							select = 'a';
						}
						else
						{
							select = selection[0];
						}
					


						switch (select)
						{
						case '1':
						{
							record->record_name = "BUDGET FROM UTeM";
							cout << "\t\t You selected 1 -> BUDGET FROM UTeM (DEBIT) " << endl;
							test = true;
							break;
						}
						case '2':
						{
							record->record_name = "SPONSORSHIP";
							cout << "\t\t You selected 2 -> SPONSORSHIP (DEBIT) " << endl;
							test = true;
							break;
						}
						case '3':
						{
							record->record_name = "STUDENT FEES";
							cout << "\t\t You selected 3 -> STUDENT FEES (DEBIT) " << endl;
							test = true;
							break;
						}
						case '4':
						{
							record->record_name = "LAB RENTAL FEES";
							cout << "\t\t You selected 4 -> LAB RENTAL FEES (DEBIT) " << endl;
							test = true;
							break;
						}
						default:
						{
							cout << "\t\t Error !!! You are not entering 1, 2, 3, or 4" << endl;
							break;
						}
						}
					} while (test == false);
					if (isCredit == true) //Originally is credit but now is debit
					{
						amount += (record->total) * 2;
					}

					faculty->faculty_balance = amount;
				}
				break;
			}
			case '2':
			{
				cout << "\t\t Description: ";
				getline(cin >> ws, detail->description);
				break;
			}
			case '3':
			{
				int q = 0;
				do {
					cout << "\t\t Quantity: ";
					cin >> q;
					if (q == 0)
					{
						cout << "\t\t Invalid!!! The current quantity is 0 !!! Please try again !!!" << endl;
					}
				} while (q == 0);
				detail->quantity = q;
				double total = record->total;
				double amount = (detail->quantity) * (detail->price);
				Transaction = amount;

				if (record->type == "CREDIT")
				{
					curr_balance += total;
					if (curr_balance > amount)
					{
						faculty->faculty_balance = curr_balance - amount;
						record->total = (detail->quantity) * (detail->price);

					}
					else //exceeding faculty's balance
					{
						update = false;
					}
				}
				else //debit
				{
					curr_balance -= total;
					faculty->faculty_balance = curr_balance + amount;
					record->total = (detail->quantity) * (detail->price);
				}

				break;
			}
			case '4':
			{
				int p = 0;

				while (cout << "\t\t Price for one unit: RM " && !(cin >> p)) {
					cin.clear(); //clear bad input flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
					cout << "\t\t Invalid input !!! Please re-enter.\n";
				}
				detail->price = p;
				double total = record->total;
				double amount = (detail->quantity) * (detail->price);
				Transaction = amount;

				if (record->type == "CREDIT")
				{
					curr_balance += total;
					if (curr_balance > amount)
					{
						faculty->faculty_balance = curr_balance - amount;
						record->total = (detail->quantity) * (detail->price);
					}
					else //exceeding faculty's balance
					{
						update = false;
					}
				}
				else //debit
				{
					curr_balance -= total;
					faculty->faculty_balance = curr_balance + amount;
					record->total = (detail->quantity) * (detail->price);

				}
				break;
			}
			case '5':
			{
				string date;


				bool testDate;
				do {
					cout << "\t\t Date(YYYY-MM-DD): ";
					getline(cin >> ws, date);
					testDate = checkDate(date);
					if (testDate == false)
					{
						cout << "\t\t Invalid input !!! Please re-enter.\n\n";
					}
				} while (testDate == false);
				detail->date = date;
				break;
			}
			case '6':
			{
				break;
			}
			default:
			{
				std::cout << "\t\t Error!!! You are not entering 1, 2, 3, 4, 5 or 6 !!!" << std::endl << "**Please try again !!!" << std::endl;
				break;
			}
			}
			if (selection == '1') //type and name
			{
				int status1 = recordmanager.updateRecord(1, record);
				int status2 = facultymanager.updateFaculty(4, faculty);
				if (status1 != 0)
				{
					cout << "\t\t Sucessfully updated a record(" << record->record_name << ")" << endl;
				}
				else
					cout << "\t\t Same record type and record name. Record is not updated." << endl;
				if (status2 != 0)
				{
					cout << "\t\t Sucessfully updated a faculty balance(RM " << faculty->faculty_balance << ")" << endl;
				}
				else
					cout << "\t\t Faculty Balance remains the same." << endl;
			}
			else
			{
				if (selection == '3' || selection == '4') //price and quantity
				{
					int choice = 0;
					if (selection == '3')
						choice = 4;
					else
						choice = 5;
					if (update == true)
					{
						int status1 = recordmanager.updateRecord(2, record);
						int status2 = detailmanager.updateDetail(choice, detail);
						int status3 = facultymanager.updateFaculty(4, faculty);
						if (status1 != 0)
							cout << "\t\t Sucessfully updated a record(" << record->record_name << ")" << endl;
						else
							cout << "\t\t Total Price remains the same." << endl;
						if (status2 != 0)
							cout << "\t\t Sucessfully updated a detail(" << record->record_name << ")" << endl;
						else
							cout << "\t\t Same detail. Detail is not updated." << endl;
						if (status3 != 0)
							cout << "\t\t Sucessfully updated a faculty(" << record->record_name << ")" << endl;
						else
							cout << "\t\t Same faculty. Faculty is not updated." << endl;
					}
					else
					{
						cout << "\t\t Transaction's amount(RM " << Transaction << ") exceeds faculty's current balance(RM " << faculty->faculty_balance << "). Update function is not executed!!" << endl;
					}


				}
				else if (selection == '2') // description
				{
					int status = detailmanager.updateDetail(3, detail);
					if (status != 0)
						cout << "\t\t Sucessfully updated a record(" << record->record_name << ")" << endl;
					else
						cout << "\t\t Same description. Description is not updated." << endl;
				}
				else if (selection == '5') // date
				{
					int status = detailmanager.updateDetail(6, detail);
					if (status != 0)
						cout << "\t\t Sucessfully updated a record(" << record->record_name << ")" << endl;
					else
						cout << "\t\t Same date inserted. Date is not updated." << endl;
				}


			}
		}
		else //record not belonging to the faculty
		{
		cout << "\n\t\t You are not allowed to view other faculty's records!\n\n";
		}
		
	}
	else
		cout << "\n\t\t Record with " << recordID << " not found!!!\n" << endl;
}

void Manager::testDeleteRecord(string staffID)
{
	string recordID;
	RecordManager recordmanager;
	FacultyManager facultymanager;
	cout << "\t\t ======================================" << endl;
	cout << "\t\t      Delete Transaction Record" << endl;
	cout << "\t\t ======================================" << endl << endl;
	cout << "\t\t Enter Record ID to delete record info: ";
	cin >> recordID;
	string selection;
	Record* record = recordmanager.getRecord(recordID);
	string facultyID = recordmanager.getFacultyID(recordID);
	string detailID = recordID;

	detailID[0] = 'D';
	if (record != NULL)
	{
		StaffManager staffmanager;
		Staff* staff = staffmanager.getStaffID(staffID);
		bool checkDelete = recordmanager.findRecord(staff->faculty_ID, recordID);

		if (checkDelete == true)
		{
			double total = record->total;
			Faculty* faculty = facultymanager.getFaculty(facultyID);
			do
			{
				do {
					cout << endl << "\t\t Are you sure you want to delete " << record->record_name << " with id " << recordID << " ? (Y/N): ";
					getline(cin >> ws, selection);

				} while (selection != "y" && selection != "Y" && selection != "n" && selection != "N");
				if (selection == "y" || selection == "Y")
				{
					if (record->type == "CREDIT")
					{
						faculty->faculty_balance += total;
					}
					else //debit
					{
						faculty->faculty_balance -= total;
					}


					DetailManager detailmanager;
					int status1 = detailmanager.deleteDetail(record->record_ID);
					int status2 = recordmanager.deleteRecord(record);
					int status3 = facultymanager.updateFaculty(4, faculty);
					if (status1 != 0 && status2 != 0 && status3 != 0)
						cout << "\n\t\t Sucessfully deleted a record(" << record->record_name << ")" << endl;
					else
						cout << "\n\t\t Failed !!! Please try again !!!" << endl;
					break;
				}
				else if (selection == "n" or selection == "N")
				{
					break;
				}
				else
					cout << "\t\t Please enter (Y/N) to proceed !!!" << endl;
			} while (selection != "y" or selection != "Y");
		}
		else
		{
			cout << "\n\t\t You are not allowed to delete other faculty's records!\n" << endl;
		}
		

	}
	else
		cout << "\n\t\t Record with " << recordID << " not found!!!\n" << endl;
}

void Manager::testSearchRecord(string facultyID)
{
	string recordID;
	RecordManager recordmanager;
	cout << "\t\t ======================================" << endl;
	cout << "\t\t      Search Transaction Record" << endl;
	cout << "\t\t ======================================" << endl << endl;
	cout << "\t\t Enter Record ID to search record info: ";
	cin >> recordID;
	Record* record = recordmanager.getRecord(recordID);
	string faculty_ID = recordmanager.getFacultyID(recordID);
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(faculty_ID);
	if (record != NULL)
	{
		if (faculty_ID != facultyID)
		{

			cout << "\n ** This transaction record can only be viewed by the staff in " << faculty->faculty_name << endl << endl;
		}
		else
		{
			string detailID = recordID;
			detailID[0] = 'D'; //change to detailID
			DetailManager detailmanager;
			Detail* detail = detailmanager.getDetail(detailID);
			cout << endl << setw(5) << right << "Record ID" << setw(10) << right << "Staff ID" << setw(13) << right << "Faculty ID" << setw(17) << right << "Record Name" << setw(15) << right << "Type" << setw(15) << right << "Total" << setw(15) << right << "Date" << endl << endl;

			cout << setw(5) << right << record->record_ID << setw(11) << right << record->staff_ID << setw(10) << right << faculty_ID << setw(23) << right << record->record_name << setw(15) << right << record->type << setw(15) << right << TwoDecimal(record->total) << setw(15) << right << detail->date << endl << endl;
		}

	}
	else
	{
		cout << "\n\t\t " << recordID << " not found !!! Please try again !!!\n" << endl;
	}
}

void Manager::viewAllRecords()
{
	RecordManager recordManager;
	Record* records = recordManager.getRecord();
	cout << "\t\t ======================================" << endl;
	cout << "\t\t    View All Transaction Record" << endl;
	cout << "\t\t ======================================" << endl << endl;
	if (records != NULL)
	{
		Record* record = records;
		
		cout << endl << setw(5) << right << "Record ID" << setw(10) << right << "Staff ID" << setw(13) << right << "Faculty ID" << setw(17) << right << "Record Name" << setw(23) << right <<"Type" << setw(15) <<right << "Total" << setw(21) <<right << "Date" << endl << endl;
		do
		{
			string detailID = record->record_ID;
			detailID[0] = 'D'; //change to detailID
			DetailManager detailmanager;
			Detail* detail = detailmanager.getDetail(detailID);
			string facultyID = recordManager.getFacultyID(record->record_ID);
			if (detail == NULL)
			{
				cout << setw(5) << right << record->record_ID << setw(11) << right << record->staff_ID << setw(10) << right << facultyID << setw(27) << right << record->record_name << setw(19) <<right << record->type << setw(13)  << right << TwoDecimal(record->total)  <<  setw(20) << right << "-" << endl << endl;
			}
			else
			{
				cout << setw(5) << right << record->record_ID << setw(11) << right << record->staff_ID << setw(10) << right << facultyID << setw(27) << right << record->record_name << setw(19) << right << record->type << setw(13) << right << TwoDecimal(record->total) << setw(20) << right << detail->date << endl << endl;

			}

			record = record->next;
		} while (record != NULL);
		cout << endl << endl;
	}
	else
		std::cout << "\n\t\t No records found" << std::endl;

}

void Manager::viewRecordByFaculty(string facultyID)
{
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	RecordManager recordManager;
	Record* records = recordManager.getFac_Records(facultyID);
	if (records != NULL)
	{
		Record* record = records;
		cout << setw(20) << faculty->faculty_name;
		//cout << endl << setw(5) << right << "Record ID" << setw(10) << right << "Staff ID" << setw(13) << right << "Faculty ID" << setw(17) << right <<"Record Name" << setw(23) << right << "Type" << setw(15) << right << "Total" << setw(21) <<  right << "Date" << endl;
		cout << endl << setw(5) << right << "Record ID" << setw(10) << right << "Staff ID" << setw(13) << right << "Faculty ID" << setw(17) << right << "Record Name" << setw(15) << right << "Type" << setw(15) << right << "Total" << setw(15) << right << "Date" << endl << endl;

		do
		{
			string detailID = record->record_ID;
			detailID[0] = 'D'; //change to detailID
			DetailManager detailmanager;
			Detail* detail = detailmanager.getDetail(detailID);
			string facultyID = recordManager.getFacultyID(record->record_ID);
			if (detail == NULL)
			{
				cout << setw(5) << right << record->record_ID << setw(11) << right << record->staff_ID << setw(10) <<  right << facultyID << setw(27) << right << record->record_name << setw(19) << right << record->type << setw(13) << right << TwoDecimal(record->total) << setw(20) << right << "-" << endl << endl;
			}
			else
			{
				//cout << setw(5) << right << record->record_ID << setw(11) << right << record->staff_ID << setw(10) << right << facultyID << setw(27) << right << record->record_name << setw(19) << right << record->type << setw(13) << right << TwoDecimal(record->total) << setw(20) << right << detail->date << endl << endl;
				cout << setw(5) << right << record->record_ID << setw(11) << right << record->staff_ID << setw(10) << right << facultyID << setw(23) << right << record->record_name << setw(15) << right << record->type << setw(15) << right << TwoDecimal(record->total) << setw(15) << right << detail->date << endl << endl;
			
			}

			record = record->next;
		} while (record != NULL);
		cout << endl << endl;
	}
	else
		std::cout << "\n\t\t No records found" << std::endl;

}

string setDate()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int date[3] = { newtime.tm_year + 1900, newtime.tm_mon + 1, newtime.tm_mday };
	
	//year = newtime.tm_year + 1900;
	//month = newtime.tm_mon + 1;
	//day = newtime.tm_mday;
	string s;
	s = to_string(date[0]) + "-" + to_string(date[1]) + "-" + to_string(date[2]);
	return s;
}

bool Manager::testAddDetail(string recordID)
{
	Detail* detail = new Detail();

	cout << "\t\t Description: ";
	getline(cin >> ws, detail->description);

	int q = 0;

	while (cout << "\n\t\t Quantity: " && !(cin >> q)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "\t\t Invalid input !!! Please re-enter.\n";
	}
	detail->quantity = q;

	int p = 0;

	while (cout << "\n\t\t Price for one unit: RM " && !(cin >> p)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "\t\t Invalid input !!! Please re-enter.\n";
	}
	detail->price = p;

	detail->date = setDate();

	

	DetailManager detailmanager;
	int status1 = detailmanager.insertDetail(detail, recordID);
	int status2 = detailmanager.insertTotal(detail, recordID);
	if (status1 != 0 && status2 != 0)
	{
		RecordManager recordmanager;
		Record* record = recordmanager.getRecord(recordID);
	
		cout << "\n\t\t The total for this transaction record is RM " << record->total << endl;
		return true;
	}
	else
	{
		cout << "\n\t\t Failed !!!! Please try again!!!";
		return false;
	}
		
}

bool Manager::loginStaff(string staffID, string password)
{

	StaffManager staffmanager;
	Staff* staff = staffmanager.loginStaff(staffID, password);
	
	if (staff != NULL)
	{
		
		return true;
	}
	else
	{
		cout <<  endl << endl <<"\t\t No staff found!!! Please try again\n\n" << endl;
		return false;
	}
}

bool Manager::loginAdmin(string adminID, string password)
{

	AdminManager adminmanager;
	Admin* admin = adminmanager.loginAdmin(adminID, password);
	if (admin != NULL)
	{
		return true;
	}
	else
	{
		cout << endl << endl << "\t\t No admin found!!! Please try again\n\n" << endl;
		return false;
	}
}

string stars(int num)
{
	string s;
	
	for (int i = 0; i < num; i++)
	{
		s += '*';
	}

	return s;
}

void changeColor(int desiredColor) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

bool myComparison(const pair<int, double>& a, const pair<int, double>& b) // sort the vector in decending order
{
	return a.second > b.second;
}


void Manager::findMostSpend(string facultyID, int selection) //Spending report by faculty (credit)    selection 1 - bar chart   selection 2 - total spending
{
	system("CLS");
	RecordManager recordmanager;

	Record* WaterBills = recordmanager.findSpends("WATER BILLS", facultyID);
	double TotalWater = 0;
	if (WaterBills != NULL)
	{
		do
		{
			TotalWater += WaterBills->total;

			WaterBills = WaterBills->next;
		} while (WaterBills != NULL);
	}

	//TO FIND TOTAL OF UTILITY BILLS
	Record* UtilityBills = recordmanager.findSpends("UTILITY BILLS", facultyID);
	double TotalUtility = 0;
	if (UtilityBills != NULL)
	{
		do
		{
			TotalUtility += UtilityBills->total;

			UtilityBills = UtilityBills->next;
		} while (UtilityBills != NULL);
	}

	//TO FIND TOTAL OF MAINTENANCE FEES
	Record* MFees = recordmanager.findSpends("MAINTENANCE FEES", facultyID);
	double TotalM = 0;
	if (MFees != NULL)
	{
		do
		{
			TotalM += MFees->total;

			MFees = MFees->next;
		} while (MFees != NULL);
	}

	//TO FIND TOTAL OF OTHER FEES
	Record* OtherF = recordmanager.findSpends("OTHER FEES", facultyID);
	double TotalOther = 0;
	if (OtherF != NULL)
	{
		do
		{
			TotalOther += OtherF->total;

			OtherF = OtherF->next;
		} while (OtherF != NULL);
	}

	double TotalSpend = TotalWater + TotalUtility + TotalM + TotalOther;

	//For water bills
	int water = (TotalWater*100) / TotalSpend;

	//For utility bills
	int utility = (TotalUtility*100) / TotalSpend;

	//For Maintenance Fees
	int maintenance = (TotalM*100) / TotalSpend;

	//For Other Fees
	int other = (TotalOther*100) / TotalSpend;


	
	string waterStars = stars(water);
	string utilityStars = stars(utility);
	string maintenanceStars = stars(maintenance);
	string otherStars = stars(other);

	vector <pair<int, double>> v;
	v.push_back(make_pair(1, TotalWater)); // Water Bills
	v.push_back(make_pair(2, TotalUtility));  // Utility Bills
	v.push_back(make_pair(3, TotalM));   // Maintenance Fees
	v.push_back(make_pair(4, TotalOther));  //Other Fees
	sort(v.begin(), v.end(), myComparison);
	

	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	switch (selection)
	{
	case 1:
	{
		cout << endl << "\t\t PERCENTAGE OF THE TOTAL COSTS IN THE " << faculty->faculty_name << endl;
		cout << "========================================================================================================================\n";
		cout << "                   0                                                                                                 100\n";
		//cout << "\n\t\t\t0\t\t\t\t\t100\n";
		cout << "========================================================================================================================\n";
		for (auto i : v)
		{
			if (i.first == 1) //Water Bills
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(3); cout << "WATER BILLS"; changeColor(7); cout << "    |"; changeColor(3); cout << waterStars << endl; changeColor(7);
				cout << "|                  |"; changeColor(3); cout << waterStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
			else if (i.first == 2) //Utility Bills
			{
				cout << "|                  |		" << endl;
				cout << "|  "; changeColor(2); cout << "UTILITY BILLS"; changeColor(7); cout << "   |"; changeColor(2); cout << utilityStars << endl; changeColor(7);
				cout << "|                  |"; changeColor(2); cout << utilityStars << endl;  changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
			else if (i.first == 3)  // Maintenance Fees
			{
				cout << "|                  |		" << endl;
				cout << "| "; changeColor(1); cout << "MAINTENANCE FEES"; changeColor(7); cout << " |"; changeColor(1); cout << maintenanceStars << endl; changeColor(7);
				cout << "|                  |"; changeColor(1); cout << maintenanceStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
			else if (i.first == 4)  // Other Fees
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(12); cout << "OTHER FEES"; changeColor(7); cout << "     |"; changeColor(12); cout << otherStars << endl; changeColor(7);
				cout << "|                  |"; changeColor(12); cout << otherStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
		}

		break;
	}
	case 2:
	{
		cout << endl << endl << "TOTAL COSTS ON EACH CATEGORY IN " << faculty->faculty_name << endl << endl;
		cout << "========================================================================================" << endl;
		for (auto i : v)
		{
			if (i.first == 1)  //Water Bills
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(3); cout << "WATER BILLS"; changeColor(7); cout << "    |" << "\t "; changeColor(3); cout << TwoDecimal(TotalWater) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================" << endl;
			}
			else if (i.first == 2) //Utility Bills
			{
				cout << "|                  |		" << endl;
				cout << "|  "; changeColor(2); cout << "UTILITY BILLS"; changeColor(7); cout << "   |" << "\t "; changeColor(2); cout << TwoDecimal(TotalUtility) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================" << endl;
			}
			else if (i.first == 3) //Maintenance Bills
			{
				cout << "|                  |		" << endl;
				cout << "| "; changeColor(1); cout << "MAINTENANCE FEES"; changeColor(7); cout << " |" << "\t "; changeColor(1); cout << TwoDecimal(TotalM) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================" << endl;
			}
			else if (i.first == 4) //Other Fees
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(12); cout << "OTHER FEES"; changeColor(7); cout << "     |" << "\t "; changeColor(12); cout << TwoDecimal(TotalOther) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================" << endl;
			}
		}
		
		cout << "========================================================================================" << endl;
		cout << "|                  |		" << endl;
		cout << "|  "; cout << "TOTAL CREDIT"; cout << "    |" << "\t "; cout << TwoDecimal(TotalSpend) << endl; 
		cout << "|                  |" << endl;
		cout << "========================================================================================" << endl;
		cout << "========================================================================================" << endl << endl;
		break;
	}

	}
	

}

void Manager::findMostIncome(string facultyID, int selection)
{
	system("CLS");
	RecordManager recordmanager;

	Record* Budget = recordmanager.findSpends("BUDGET FROM UTeM", facultyID);
	double TotalBudget = 0;
	if (Budget != NULL)
	{
		do
		{
			TotalBudget += Budget->total;

			Budget = Budget->next;
		} while (Budget != NULL);
	}

	//TO FIND TOTAL OF Sponsorship
	Record* Sponsor = recordmanager.findSpends("SPONSORSHIP", facultyID);
	double TotalSponsor = 0;
	if (Sponsor != NULL)
	{
		do
		{
			TotalSponsor += Sponsor->total;

			Sponsor = Sponsor->next;
		} while (Sponsor != NULL);
	}

	//TO FIND TOTAL OF Students Fees
	Record* SFees = recordmanager.findSpends("STUDENT FEES", facultyID);
	double TotalS = 0;
	if (SFees != NULL)
	{
		do
		{
			TotalS += SFees->total;

			SFees = SFees->next;
		} while (SFees != NULL);
	}

	//TO FIND TOTAL OF LAB RENTAL FEES
	Record* Lab = recordmanager.findSpends("LAB RENTAL FEES", facultyID);
	double TotalLab = 0;
	if (Lab != NULL)
	{
		do
		{
			TotalLab += Lab->total;

			Lab = Lab->next;
		} while (Lab != NULL);
	}

	double TotalIncome = TotalBudget + TotalSponsor + TotalS + TotalLab;

	//For budget
	int budget = (TotalBudget * 100) / TotalIncome;

	//For sponsorship
	int sponsor = (TotalSponsor * 100) / TotalIncome;

	//For Students Fees
	int student = (TotalS * 100) / TotalIncome;

	//For Lab Rental Fees
	int lab = (TotalLab * 100) / TotalIncome;

	vector <pair<int, double>> v;
	v.push_back(make_pair(1, TotalBudget)); // Budget
	v.push_back(make_pair(2, TotalSponsor));  // Sponsorship
	v.push_back(make_pair(3, TotalS));   // Student Fees
	v.push_back(make_pair(4, TotalLab));  // Lab Rental
	sort(v.begin(), v.end(), myComparison);

	string budgetStars = stars(budget);
	string sponsorStars = stars(sponsor);
	string studentStars = stars(student);
	string labStars = stars(lab);

	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	switch (selection) {
	case 1:
	{
		cout << endl << "\t\t PERCENTAGE OF THE TOTAL INCOME IN THE " << faculty->faculty_name << endl;
		cout << "========================================================================================================================" << endl;
		cout << "                   0                                                                                                 100" << endl;
		cout << "========================================================================================================================" << endl;
		for (auto i : v)
		{
			if (i.first == 1)
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(10); cout << "BUDGET FROM"; changeColor(7); cout << "    |"; changeColor(10); cout << budgetStars << endl; changeColor(7);
				cout << "|       "; changeColor(10); cout << "UTeM"; changeColor(7);  cout << "       |"; changeColor(10); cout << budgetStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
			else if (i.first == 2)
			{
				cout << "|                  |		" << endl;
				cout << "|    "; changeColor(14); cout << "SPONSORSHIP"; changeColor(7); cout << "   |"; changeColor(14); cout << sponsorStars << endl; changeColor(7);
				cout << "|                  |"; changeColor(14); cout << sponsorStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
			else if (i.first == 3)
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(11); cout << "STUDENT FEES"; changeColor(7); cout << "   |"; changeColor(11); cout << studentStars << endl; changeColor(7);
				cout << "|                  |"; changeColor(11); cout << studentStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
			else if (i.first == 4)
			{
				cout << "|                  |		" << endl;
				cout << "|    "; changeColor(13); cout << "LAB RENTAL"; changeColor(7); cout << "    |"; changeColor(13); cout << labStars << endl; changeColor(7);
				cout << "|       "; changeColor(13); cout << "FEES"; changeColor(7); cout << "       |"; changeColor(13); cout << labStars << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "========================================================================================================================" << endl;
			}
		}
	
		break;
	}
	case 2:
	{
			cout << endl << endl << "TOTAL INCOME ON EACH CATEGORY IN " << faculty->faculty_name << endl << endl;
	cout << "========================================================================================" << endl;
	for (auto i : v)
	{
		if (i.first == 1)
		{
			cout << "|                  |		" << endl;
			cout << "| "; changeColor(10); cout << "BUDGET FROM UTeM"; changeColor(7); cout << " |" << "\t "; changeColor(10); cout << TwoDecimal(TotalBudget) << endl; changeColor(7);
			cout << "|                  |" << endl;
			cout << "========================================================================================" << endl;
		}
		else if (i.first == 2)
		{
			cout << "|                  |		" << endl;
			cout << "|   "; changeColor(14); cout << "SPONSORSHIP"; changeColor(7); cout << "    |" << "\t "; changeColor(14); cout << TwoDecimal(TotalSponsor) << endl; changeColor(7);
			cout << "|                  |" << endl;
			cout << "========================================================================================" << endl;
		}
		else if (i.first == 3)
		{
			cout << "|                  |		" << endl;
			cout << "|   "; changeColor(11); cout << "STUDENT FEES"; changeColor(7); cout << "   |"; changeColor(11); cout << "\t " << TwoDecimal(TotalS) << endl; changeColor(7);
			cout << "|                  |" << endl;
			cout << "========================================================================================" << endl;
		}
		else if (i.first == 4)
		{
			cout << "|                  |		" << endl;
			cout << "| "; changeColor(13); cout << "LAB RENTAL FEES"; changeColor(7); cout << "  |"; changeColor(13); cout << "\t " << TwoDecimal(TotalLab) << endl; changeColor(7);
			cout << "|                  |" << endl;
			cout << "========================================================================================" << endl;
		}
	}
	
	cout << "========================================================================================" << endl;
	cout << "|                  |		" << endl;
	cout << "|  "; cout << "TOTAL INCOME";  cout << "    |";  cout << "\t " << TwoDecimal(TotalIncome) << endl; 
	cout << "|                  |" << endl;
	cout << "========================================================================================" << endl;
	cout << "========================================================================================" << endl << endl;
	break;
	}
	}

}

void Manager::debit(int selection)
{
	system("CLS");
	RecordManager recordmanager;
	string type = "DEBIT";
	FacultyManager facultymanager;

	Faculty* faculties = facultymanager.getFaculty();
	int TotalFaculty = 0;
	if (faculties != NULL)
	{
		do
		{
			TotalFaculty += 1;

			faculties = faculties->next;
		} while (faculties != NULL);
	}

	Faculty* faculty = facultymanager.getFaculty();
	vector <double> total(TotalFaculty, 0);
	int count = 0;
	if (faculty != NULL)
	{
		do
		{
			Record* record = recordmanager.findSpend(type, faculty->faculty_ID);
			if (record != NULL)
			{
				vector <double> Total;
				do {
					Total.push_back(record->total);
					record = record->next;
				} while (record != NULL);

				total[count] = accumulate(Total.begin(), Total.end(), 0); // sum up debit total
				count++;
			}
			

			faculty = faculty->next;
		} while (faculty != NULL);
		

	}

	vector <string> star;
	vector <int> percentage;

	double TotalDebit = accumulate(total.begin(), total.end(), 0); //TotalDebit = total debit in all faculty

	


	for (int i = 0; i < TotalFaculty; i++)
	{
		percentage.push_back((total[i] * 100) / TotalDebit); // calculate the percentage for each faculty
		star.push_back(stars(percentage[i])); // store * in the star
	}

	
	switch (selection) {
	case 1:
	{
		displayFacultyForReport();
		cout << endl << "\t\t\t\t PERCENTAGE OF THE TOTAL INCOME AMONG THE " << TotalFaculty << " FACULTIES" << endl;
		cout << "=======================================================================================================================\n";
		cout << "                   0                                                                                                 100\n";
		cout << "=======================================================================================================================\n";

		Faculty* facultynow = facultymanager.getFaculty();

		for (int i = 0; i < TotalFaculty; i++)
		{
			int colorCode = i + 1;
			if (colorCode >= 7)
			{
				colorCode += 2;
			}

			cout << "|                  |		" << endl;
			cout << "|   "; changeColor(colorCode); cout << facultynow->faculty_ID; changeColor(7); cout << "           |"; changeColor(colorCode); cout << star[i] << endl; changeColor(7);
			cout << "|                  |"; changeColor(colorCode); cout << star[i] << endl; changeColor(7);
			cout << "|                  |" << endl;
			cout << "=======================================================================================================================\n";
			facultynow = facultynow->next;
			if (facultynow == NULL)
				break;
		}
		break;
	}
	case 2:
	{
		Faculty* faculty_amount = facultymanager.getFaculty();
		cout << endl << endl << "\t\t\tTOTAL INCOME ON EACH CATEGORY AMONG THE " << TotalFaculty << " FACULTIES" << endl << endl;
		cout << "========================================================================================================================" << endl;
		for (int i = 0; i < TotalFaculty; i++)
		{
			int colorCode = i + 1;
			if (colorCode >= 7)
			{
				colorCode += 2;
			}
			cout << "|  " << setw(75) << right << "  |" << endl;
			cout << "| "; changeColor(colorCode); cout << setw(75) << left << faculty_amount->faculty_name; changeColor(7); cout << "|"; changeColor(colorCode); cout << setw(20) << right << TwoDecimal(total[i]) << endl; changeColor(7);
			cout << "|  " << setw(75) << right << "  |" << endl;
			cout << "|  " << setw(75) << right << "  |" << endl;
			cout << "========================================================================================================================" << endl;
			faculty_amount = faculty_amount->next;
			if (faculty_amount == NULL)
				break;
			
		}
		break;
	}
	}
	
}

void Manager::credit(int selection)
{
	system("CLS");
	RecordManager recordmanager;
	string type = "CREDIT";
	FacultyManager facultymanager;

	Faculty* faculties = facultymanager.getFaculty();
	int TotalFaculty = 0;
	if (faculties != NULL)
	{
		do
		{
			TotalFaculty += 1;

			faculties = faculties->next;
		} while (faculties != NULL);
	}

	Faculty* faculty = facultymanager.getFaculty();
	vector <double> total(TotalFaculty, 0);
	int count = 0;
	if (faculty != NULL)
	{
		do
		{
			Record* record = recordmanager.findSpend(type, faculty->faculty_ID);
			if (record != NULL)
			{
				vector <double> Total;
				
				do {
					Total.push_back(record->total);
					record = record->next;
				} while (record != NULL);

				total[count] = accumulate(Total.begin(), Total.end(), 0); // sum up credit total
				count++;
			}
			

			faculty = faculty->next;
		} while (faculty != NULL);


	}
	


	vector <string> star;
	vector <int> percentage;

	double TotalCredit = accumulate(total.begin(), total.end(), 0); //TotalCredit = total debit in all faculty




	for (int i = 0; i < TotalFaculty; i++)
	{
		percentage.push_back((total[i] * 100) / TotalCredit); // calculate the percentage for each faculty
		star.push_back(stars(percentage[i])); // store * in the star
	}

	switch (selection) {
	case 1:
	{
		displayFacultyForReport();
		cout << endl << "\t\t\t\t PERCENTAGE OF THE TOTAL SPENDING AMONG THE " << TotalFaculty << " FACULTIES" << endl;
		cout << "========================================================================================================================\n";
		cout << "                   0                                                                                                 100\n";
		cout << "========================================================================================================================\n";

		Faculty* facultynow = facultymanager.getFaculty();

		for (int i = 0; i < TotalFaculty; i++)
		{
			int colorCode = i + 1;
			if (colorCode >= 7)
			{
				colorCode += 2;
			}
			cout << "|                  |		" << endl;
			cout << "|   "; changeColor(colorCode); cout << facultynow->faculty_ID; changeColor(7); cout << "           |"; changeColor(colorCode); cout << star[i] << endl; changeColor(7);
			cout << "|                  |"; changeColor(colorCode); cout << star[i] << endl; changeColor(7);
			cout << "|                  |" << endl;
			cout << "========================================================================================================================\n";
			facultynow = facultynow->next;
			if (facultynow == NULL)
				break;
		}
		break;
	}
	case 2:
	{
		Faculty* faculty_amount = facultymanager.getFaculty();
		cout << endl << endl << "\t\t\tTOTAL SPENDING ON EACH CATEGORY AMONG THE " << TotalFaculty << " FACULTIES" << endl << endl;
		cout << "========================================================================================================================" << endl;
		for (int i = 0; i < TotalFaculty; i++)
		{
			int colorCode = i + 1;
			if (colorCode >= 7)
			{
				colorCode += 2;
			}
			cout << "|  " << setw(75) << right << "  |" << endl;
			cout << "| "; changeColor(colorCode); cout << setw(75) << left << faculty_amount->faculty_name; changeColor(7); cout << "|"; changeColor(colorCode); cout << setw(20) << right << TwoDecimal(total[i]) << endl; changeColor(7);
			cout << "|  " << setw(75) << right << "  |" << endl;
			cout << "|  " << setw(75) << right << "  |" << endl;
			cout << "========================================================================================================================" << endl;
			faculty_amount = faculty_amount->next;
			if (faculty_amount == NULL)
				break;
		}
		break;
	}
	}

}

bool Add(string type)
{
	if (type == "CREDIT")
		return false;
	else
		return true;
}

void Manager::yearAndFaculty(string year, string facultyID)
{
	system("CLS");
	RecordManager recordmanager;
	Record* getTotal = recordmanager.getRecord_Year(year, facultyID);
	double total_credit = 0, total_debit = 0;
	if (getTotal != NULL)
	{
		do {
			
			bool test = Add(getTotal->type);
			if (test == true) // debit
			{
				total_debit += getTotal->total;
			}
			else
			{
				total_credit = getTotal->total;
			}
			

			getTotal = getTotal->next;
		} while (getTotal != NULL);
	}

	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty(facultyID);
	cout << endl << "\t TOTAL CREDIT AND TOTAL DEBIT IN " << faculty->faculty_name << " IN " << year << endl;
	cout << "===================================================================================================" << endl;
	cout << "|	CATEGORY	   |	  TOTAL CREDIT	  |	  TOTAL DEBIT	  |	   NET BALANCE	  |" << endl;
	cout << "===================================================================================================" << endl;
	cout << "|	  AMOUNT	   |" << "\t  " << right << TwoDecimal(total_credit) << "\t  |" << "\t  " << right << TwoDecimal(total_debit) << "\t  |" << "\t  " << right << TwoDecimal(total_debit - total_credit) << "\t  |" << endl;
	cout << "===================================================================================================" << endl;
	

}

void Manager::ReportGeneration4(string year)
{


	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	string Name = "Annual_Report_By_Faculty_";
	string text = ".txt";
	string ReportName = Name + year + text;
	fstream my_file;
	my_file.open(ReportName, ios::out);
	if (!my_file) {
		cout << "\n\t\t Annual report file failed to be generated !\n\n";
	}
	else {
		cout << "\n\t\t Annual report file successfully generated !\n\n";

		if (faculty != NULL)
		{


			my_file << endl << "\t TOTAL CREDIT AND TOTAL DEBIT IN " << year << endl;
			do {

				RecordManager recordmanager;
				Record* getTotal = recordmanager.getRecord_Year(year, faculty->faculty_ID);
				double total_credit = 0, total_debit = 0;
				if (getTotal != NULL)
				{
					do {

						bool test = Add(getTotal->type);
						if (test == true) // debit
						{
							total_debit += getTotal->total;
						}
						else
						{
							total_credit = getTotal->total;
						}


						getTotal = getTotal->next;
					} while (getTotal != NULL);
				}


				my_file << endl << faculty->faculty_name << endl;
				my_file << "===================================================================================================" << endl;
				my_file << "|	CATEGORY	   |	  TOTAL CREDIT	  |	  TOTAL DEBIT	  |	   NET BALANCE	  |" << endl;
				my_file << "===================================================================================================" << endl;
				my_file << "|	  AMOUNT	   |" << "\t  " << right << TwoDecimal(total_credit) << "\t  |" << "\t  " << right << TwoDecimal(total_debit) << "\t  |" << "\t  " << right << TwoDecimal(total_debit + total_credit) << "\t  |" << endl;
				my_file << "===================================================================================================" << endl << endl << endl << endl;
				faculty = faculty->next;
			} while (faculty != NULL);


		}
		my_file.close();
	}




}

void Manager::ReportUTeM(string year, int selection)
{
	
	RecordManager recordmanager;
	FacultyManager facultymanager;
	double TotalBudget = 0, TotalSponsor = 0, TotalStudent = 0, TotalLab = 0, TotalWater = 0, TotalUtility = 0, TotalMaintenance = 0, TotalOther = 0;
	Faculty* faculty = facultymanager.getFaculty();
	int total_faculty = 0;
	if (faculty != NULL)
	{
		
		do {
			Record* record = recordmanager.getRecord_Year(year, faculty->faculty_ID);
			if (record != NULL)
			{
				do {

					if (record->record_name == "BUDGET FROM UTeM")
					{
						TotalBudget += record->total;
					}
					else if (record->record_name == "SPONSORSHIP")
					{
						TotalSponsor += record->total;
					}
					else if (record->record_name == "STUDENT FEES")
					{
						TotalStudent += record->total;
					}
					else if (record->record_name == "LAB RENTAL FEES")
					{
						TotalLab += record->total;
					}
					else if (record->record_name == "WATER BILLS")
					{
						TotalWater += record->total;
					}
					else if (record->record_name == "UTILITY BILLS")
					{
						TotalUtility += record->total;
					}
					else if (record->record_name == "MAINTENANCE FEES")
					{
						TotalMaintenance += record->total;
					}
					else if (record->record_name == "OTHER FEES")
					{
						TotalOther += record->total;
					}
					record = record->next;

				} while (record != NULL);
			}
			total_faculty++;
			faculty = faculty->next;
		} while (faculty != NULL);
	}

	double TotalCredit = TotalWater + TotalUtility + TotalMaintenance + TotalOther;
	double TotalDebit = TotalBudget + TotalSponsor + TotalStudent + TotalLab;

	vector <pair<int, double>> v;
	v.push_back(make_pair(1, TotalBudget)); // Budget
	v.push_back(make_pair(2, TotalSponsor));  // Sponsorship
	v.push_back(make_pair(3, TotalStudent));   // Student Fees
	v.push_back(make_pair(4, TotalLab));  // Lab Rental
	v.push_back(make_pair(5, TotalWater)); // Water Bills
	v.push_back(make_pair(6, TotalUtility));  // Utility Bills
	v.push_back(make_pair(7, TotalMaintenance));   // Maintenance Fees
	v.push_back(make_pair(8, TotalOther));  // Other Fees
	sort(v.begin(), v.end(), myComparison);
	switch (selection) {
	case 1:
	{
		system("CLS");
		cout << endl << endl << "TOTAL COSTS ON EACH CATEGORY AMONG THE " << total_faculty << " FACULTIES IN " << year << endl << endl;
		cout << "========================================================================================" << endl;
		for (auto i : v)
		{
			if (i.first == 5)
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(3); cout << "WATER BILLS"; changeColor(7); cout << "    |" << "\t "; changeColor(3); cout << TwoDecimal(TotalWater) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "=========================================================================================" << endl;
			}
			else if (i.first == 6)
			{
				cout << "|                  |		" << endl;
				cout << "|  "; changeColor(2); cout << "UTILITY BILLS"; changeColor(7); cout << "   |" << "\t "; changeColor(2); cout << TwoDecimal(TotalUtility) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "==========================================================================================" << endl;
			}
			else if (i.first == 7)
			{
				cout << "|                  |		" << endl;
				cout << "| "; changeColor(1); cout << "MAINTENANCE FEES"; changeColor(7); cout << " |" << "\t "; changeColor(1); cout << TwoDecimal(TotalMaintenance) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "==========================================================================================" << endl;
			}
			else if (i.first == 8)
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(12); cout << "OTHER FEES"; changeColor(7); cout << "     |" << "\t "; changeColor(12); cout << TwoDecimal(TotalOther) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "===========================================================================================" << endl;
			}
		}

		cout << "===========================================================================================" << endl;
		cout << "|                  |		" << endl;
		cout << "|  "; cout << "TOTAL CREDIT"; cout << "    |" << "\t "; cout << TwoDecimal(TotalCredit) << endl;
		cout << "|                  |" << endl;
		cout << "===========================================================================================" << endl;
		cout << "===========================================================================================" << endl << endl;
		break;
	}
	case 2:
	{
		system("CLS");
		cout << endl << endl << "TOTAL INCOME ON EACH CATEGORY AMONG THE " << total_faculty << " FACULTIES IN " << year << endl << endl;
		cout << "========================================================================================" << endl;
		for (auto i : v)
		{
			if (i.first == 1)
			{
				cout << "|                  |		" << endl;
				cout << "| "; changeColor(10); cout << "BUDGET FROM UTeM"; changeColor(7); cout << " |" << "\t "; changeColor(10); cout << TwoDecimal(TotalBudget) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "=========================================================================================" << endl;
			}
			else if (i.first == 2)
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(14); cout << "SPONSORSHIP"; changeColor(7); cout << "    |" << "\t "; changeColor(14); cout << TwoDecimal(TotalSponsor) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "==========================================================================================" << endl;
			}
			else if (i.first == 3)
			{
				cout << "|                  |		" << endl;
				cout << "|   "; changeColor(11); cout << "STUDENT FEES"; changeColor(7); cout << "   |"; changeColor(11); cout << "\t " << TwoDecimal(TotalStudent) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "==========================================================================================" << endl;
			}
			else if (i.first == 4)
			{
				cout << "|                  |		" << endl;
				cout << "| "; changeColor(13); cout << "LAB RENTAL FEES"; changeColor(7); cout << "  |"; changeColor(13); cout << "\t " << TwoDecimal(TotalLab) << endl; changeColor(7);
				cout << "|                  |" << endl;
				cout << "===========================================================================================" << endl;
			}
		}
		
		cout << "===========================================================================================" << endl;
		cout << "|                  |		" << endl;
		cout << "|  "; cout << "TOTAL DEBIT";  cout << "     |";  cout << "\t " << TwoDecimal(TotalDebit) << endl;
		cout << "|                  |" << endl;
		cout << "===========================================================================================" << endl;
		cout << "===========================================================================================" << endl << endl;
		break;
	}
	case 3:
	{
		string Name = "Annual_Report_In_";
		string text = ".txt";
		string ReportName = Name + year + text;
		fstream my_file;
		my_file.open(ReportName, ios::out);
		if (!my_file) {
			cout << "\n\t\t Annual report file failed to be generated !\n\n";
		}
		else
		{
			cout << "\n\t\t Annual report file successfully generated !\n\n";

			my_file << endl << endl << "TOTAL COSTS ON EACH CATEGORY AMONG THE " << total_faculty << " FACULTIES IN " << year << endl << endl;
			my_file << "========================================================================================" << endl;
			for (auto i : v)
			{
				if (i.first == 5)
				{
					my_file << "|                  |		" << endl;
					my_file << "|   "; changeColor(3); my_file << "WATER BILLS"; changeColor(7); my_file << "    |" << "\t "; changeColor(3); my_file << TwoDecimal(TotalWater) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "=========================================================================================" << endl;
				}
				else if (i.first == 6)
				{
					my_file << "|                  |		" << endl;
					my_file << "|  "; changeColor(2); my_file << "UTILITY BILLS"; changeColor(7); my_file << "   |" << "\t "; changeColor(2); my_file << TwoDecimal(TotalUtility) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "==========================================================================================" << endl;
				}
				else if (i.first == 7)
				{
					my_file << "|                  |		" << endl;
					my_file << "| "; changeColor(1); my_file << "MAINTENANCE FEES"; changeColor(7); my_file << " |" << "\t "; changeColor(1); my_file << TwoDecimal(TotalMaintenance) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "==========================================================================================" << endl;
				}
				else if (i.first == 8)
				{
					my_file << "|                  |		" << endl;
					my_file << "|   "; changeColor(12); my_file << "OTHER FEES"; changeColor(7); my_file << "     |" << "\t "; changeColor(12); my_file << TwoDecimal(TotalOther) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "===========================================================================================" << endl;
				}
			}

			my_file << "===========================================================================================" << endl;
			my_file << "|                  |		" << endl;
			my_file << "|  "; my_file << "TOTAL CREDIT"; my_file << "    |" << "\t "; my_file << TwoDecimal(TotalCredit) << endl;
			my_file << "|                  |" << endl;
			my_file << "===========================================================================================" << endl;
			my_file << "===========================================================================================" << endl << endl;


			my_file << endl << endl << "TOTAL INCOME ON EACH CATEGORY AMONG THE " << total_faculty << " FACULTIES IN " << year << endl << endl;
			my_file << "========================================================================================" << endl;
			for (auto i : v)
			{
				if (i.first == 1)
				{
					my_file << "|                  |		" << endl;
					my_file << "| "; changeColor(10); my_file << "BUDGET FROM UTeM"; changeColor(7); my_file << " |" << "\t "; changeColor(10); my_file << TwoDecimal(TotalBudget) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "=========================================================================================" << endl;
				}
				else if (i.first == 2)
				{
					my_file << "|                  |		" << endl;
					my_file << "|   "; changeColor(14); my_file << "SPONSORSHIP"; changeColor(7); my_file << "    |" << "\t "; changeColor(14); my_file << TwoDecimal(TotalSponsor) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "==========================================================================================" << endl;
				}
				else if (i.first == 3)
				{
					my_file << "|                  |		" << endl;
					my_file << "|   "; changeColor(11); my_file << "STUDENT FEES"; changeColor(7); my_file << "   |"; changeColor(11); my_file << "\t " << TwoDecimal(TotalStudent) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "==========================================================================================" << endl;
				}
				else if (i.first == 4)
				{
					my_file << "|                  |		" << endl;
					my_file << "| "; changeColor(13); my_file << "LAB RENTAL FEES"; changeColor(7); my_file << "  |"; changeColor(13); my_file << "\t " << TwoDecimal(TotalLab) << endl; changeColor(7);
					my_file << "|                  |" << endl;
					my_file << "===========================================================================================" << endl;
				}
			}

			my_file << "===========================================================================================" << endl;
			my_file << "|                  |		" << endl;
			my_file << "|  "; my_file << "TOTAL DEBIT";  my_file << "     |";  my_file << "\t " << TwoDecimal(TotalDebit) << endl;
			my_file << "|                  |" << endl;
			my_file << "===========================================================================================" << endl;
			my_file << "===========================================================================================" << endl << endl;
		}
	}


		}
			


		
}

vector <double> Manager::Credit(string year) // In a particular year, all faculty, type = credit
{
	
	RecordManager recordmanager;
	FacultyManager facultymanager;
	Faculty* countFac = facultymanager.getFaculty(); 
	int num = 0;
	if (countFac != NULL)
	{
		do {
			num++;
			countFac = countFac->next;
		} while (countFac != NULL);
	}
	vector <double> credit(num, 0);
	Faculty* faculty = facultymanager.getFaculty();
	int count = 0;
	if (faculty != NULL)
	{
		do {
			Record* record = recordmanager.getRecord_TypeAndYear(year, faculty->faculty_ID, "CREDIT");
			if (record != NULL)
			{
				do {

					credit[count] += record->total;
					
					record = record->next;
					
				} while (record != NULL);
			}
	
			count++; //count position of current faculty
			faculty = faculty->next;
		} while (faculty != NULL);
	}


	return credit;

}

vector <double> Manager::Debit(string year) // In a particular year, all faculty, type = debit
{

	RecordManager recordmanager;
	FacultyManager facultymanager;
	Faculty* countFac = facultymanager.getFaculty();
	int num = 0;
	if (countFac != NULL)
	{
		do {
			num++;
			countFac = countFac->next;
		} while (countFac != NULL);
	}
	vector <double> debit(num, 0);
	Faculty* faculty = facultymanager.getFaculty();
	int count = 0;
	if (faculty != NULL)
	{
		do {
			Record* record = recordmanager.getRecord_TypeAndYear(year, faculty->faculty_ID, "DEBIT");
			if (record != NULL)
			{
				do {

					debit[count] += record->total;
					record = record->next;
					
				} while (record != NULL);
			}
			count++; //count position of current faculty
			faculty = faculty->next;
		} while (faculty != NULL);
	}

	return debit;
}

vector <string> Manager::Latest3Year()
{
	vector <string> Years;
	RecordManager recordmanager;
	Record* records = recordmanager.Get3Years();
	if (records != NULL)
	{
		do {
			Years.push_back(records->year);
			records = records->next;
		} while (records != NULL);
	}
	return Years;
}

void Manager::Latest3YearsCredit()
{
	system("cls");
	vector <string> Years = Latest3Year();
	vector <double> Year1 = Credit(Years[2]);
	vector <double> Year2 = Credit(Years[1]);
	vector <double> Year3 = Credit(Years[0]);
	
	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	cout << "\t\t\tTOTAL SPENDING ON EACH FACULTY IN " << Years[2] << ", " << Years[1] << " AND " << Years[0] << endl;
	cout << "============================================================================================================" << endl;
	cout << "|      Year      |" << setw(15)  << right << Years[2] << setw(15) << right << "|" << setw(15) << right << Years[1] << setw(15) << right << "|" << setw(15) << right << Years[0] << setw(15) << right << "|" << endl;
	cout << "============================================================================================================" << endl;
	int count = 0;
	do {
		int colorCode = count + 1;
		if (colorCode >= 7)
		{
			colorCode += 2;
		}
		cout << "|      "; changeColor(colorCode); cout << faculty->faculty_ID; changeColor(7); cout << setw(7) << "|"; changeColor(colorCode); cout << setw(15) << right << TwoDecimal(Year1[count]); changeColor(7); cout << setw(15) << right << "|"; changeColor(colorCode); cout << setw(15) << right << TwoDecimal(Year2[count]); changeColor(7); cout << setw(15) << right << "|"; changeColor(colorCode); cout << setw(15) << right << TwoDecimal(Year3[count]); changeColor(7); cout << setw(15) << right << "|" << endl;
		cout << "============================================================================================================" << endl;
		faculty = faculty->next;
		count++;
	} while (faculty != NULL);

}

void Manager::Latest3YearsDebit()
{
	system("cls");
	vector <string> Years = Latest3Year();
	vector <double> Year1 = Debit(Years[2]);
	vector <double> Year2 = Debit(Years[1]);
	vector <double> Year3 = Debit(Years[0]);

	FacultyManager facultymanager;
	Faculty* faculty = facultymanager.getFaculty();
	cout << "\t\t\tTOTAL INCOME ON EACH FACULTY IN " << Years[2] << ", " << Years[1] << " AND " << Years[0] << endl;
	cout << "============================================================================================================" << endl;
	cout << "|      Year      |" << setw(15) << right << Years[2] << setw(15) << right << "|" << setw(15) << right << Years[1] << setw(15) << right << "|" << setw(15) << right << Years[0] << setw(15) << right << "|" << endl;
	cout << "============================================================================================================" << endl;
	int count = 0;
	do {
		int colorCode = count + 1;
		if (colorCode >= 7)
		{
			colorCode += 2;
		}
		cout << "|      "; changeColor(colorCode); cout << faculty->faculty_ID; changeColor(7); cout << setw(7) << "|"; changeColor(colorCode); cout << setw(15) << right << TwoDecimal(Year1[count]); changeColor(7); cout << setw(15) << right << "|"; changeColor(colorCode); cout << setw(15) << right << TwoDecimal(Year2[count]); changeColor(7); cout << setw(15) << right << "|"; changeColor(colorCode); cout << setw(15) << right << TwoDecimal(Year3[count]); changeColor(7); cout << setw(15) << right << "|" << endl;
		cout << "============================================================================================================" << endl;
		faculty = faculty->next;
		count++;
	} while (faculty != NULL);
}