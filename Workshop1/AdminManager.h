#include "Admin.h"
#include "DatabaseConnection.h"
#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

class AdminManager {
public:
	std::string assignID();
	int addAdmin(Admin* admin);
	int updateAdmin(int selection, Admin* admin);
	int deleteAdmin(Admin* admin);
	Admin* getAdmin(std::string admin_ID);
	Admin* loginAdmin(std::string admin_ID, std::string admin_password);
	int numOfStaff(Admin* admin);
};
#endif