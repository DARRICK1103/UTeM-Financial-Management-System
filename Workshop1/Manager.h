#include "AdminManager.h"
#include "StaffManager.h"
#include "FacultyManager.h"
#include "RecordManager.h"
#include "DetailManager.h"
#include <ctime>
#include <iomanip>
#include <vector>
#include <numeric>
#include <string>
#include <sstream>
#define NOMINMAX
#include <windows.h> 
#include <algorithm>
#include <fstream>
#ifndef MANAGER_H
#define MANAGER_H

class Manager
{
public:
	
	void testAddStaff(std::string adminID);
	void testUpdateStaff();
	void testDeleteStaff();
	void testSearchStaff();
	void viewAllStaff();

	std::string displayFacultyID();
	void testAddFaculty(std::string adminID);
	void testUpdateFaculty();
	void testDeleteFaculty();
	void testSearchFaculty();
	void viewAllFaculty();

	void testAddRecord(std::string staffID);
	void testUpdateRecord(std::string staffID); //can update detail too
	void testDeleteRecord(std::string staffID); //at the same time, it deletes detail also
	void testSearchRecord(std::string facultyID);
	void viewAllRecords();

	void viewRecordByFaculty(std::string facultyID);
	
	double FacultyBalance(std::string facultyID);
	
	bool testAddDetail(std::string recordID);
	

	bool loginStaff(std::string staffID, std::string password);
	bool loginAdmin(std::string adminID, std::string password);

	void findMostSpend(std::string facultyID, int selection);
	void findMostIncome(std::string facultyID, int selection);

	void credit(int selection);
	void debit(int selection);

	void yearAndFaculty(std::string year, std::string facultyID);
	void ReportGeneration4(std::string year);

	void ReportUTeM(std::string year, int selection);

	std::vector <double> Credit(std::string year);
	std::vector <double> Debit(std::string year);
	
	std::vector <std::string> Latest3Year();

	void Latest3YearsCredit();
	void Latest3YearsDebit();
};
#endif

