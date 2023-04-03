#include "Faculty.h"
#include "DatabaseConnection.h"
#ifndef FACULTYMANAGER_H
#define FACULTYMANAGER_H

class FacultyManager {
public:
	std::string assignID();
	int updateFaculty(int selection, Faculty* faculty);
	int insertFaculty(Faculty* faculty);
	int deleteFaculty(Faculty* faculty);
	Faculty* getFaculty(std::string faculty_ID);
	Faculty* getFaculty();
};
#endif

