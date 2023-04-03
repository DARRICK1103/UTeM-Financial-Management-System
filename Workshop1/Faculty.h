#include <string>
#ifndef FACULTY_H
#define FACULTY_H

class Faculty {
public:
	std::string faculty_ID, admin_ID, faculty_name, faculty_address, faculty_contact;
	double faculty_balance;
	Faculty* next;
};
#endif
