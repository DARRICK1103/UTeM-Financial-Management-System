#include "DatabaseConnection.h"
#include "Record.h"
#include "DetailManager.h"
#include "Detail.h"
#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

class RecordManager {
public:
	std::string assignID();

	int updateRecord(int selection, Record* record);
	int updateReplace(std::string deleteStaffID, std::string staffID);
	int insertRecord(Record* record);
	int deleteRecord(Record* record);
	
	Record* findSpend(std::string type, std::string facultyID);
	Record* findSpends(std::string recordName, std::string facultyID); //find spend on each category specifically

	Record* getRecord(std::string record_ID);
	Record* getRecord();
	Record* getFac_Records(std::string facultyID);

	std::string getFacultyID(std::string recordID);

	bool findStaff(std::string staffID);

	Record* getRecord_Name(std::string name);
	Record* getRecord_Year(std::string year, std::string facultyID);
	Record* checkYear(std::string year);
	Record* Get3Years();
	Record* getRecord_TypeAndYear(std::string year, std::string facultyID, std::string type);

	bool findRecord(std::string facultyID, std::string recordID);
};
#endif

