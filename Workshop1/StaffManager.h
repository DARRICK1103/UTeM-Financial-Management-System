#include "Staff.h"
#include "DatabaseConnection.h"
#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H

class StaffManager {
public:
	std::string assignID();
	int addStaff(Staff* staff, std::string adminID);
	int updateStaff(int selection, Staff* staff);
	int deleteStaff(Staff* staff);
	
	Staff* getStaffID(std::string staff_ID);
	Staff* loginStaff(std::string staff_ID, std::string staff_password);
	Staff* getStaffs();

	Staff* getStaff(std::string facultyID);
};
#endif
