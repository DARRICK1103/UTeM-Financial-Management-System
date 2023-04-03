#include "RecordManager.h"

void transform(sql::ResultSet* rs, Record* record)
{
	record->record_ID = rs->getString("record_ID");
	record->staff_ID = rs->getString("staff_ID");
	record->record_name = rs->getString("record_name");
	record->type = rs->getString("type");
	record->total = rs->getDouble("total");
}

std::string RecordManager::assignID()
{
	try {
		std::string s, store, recordID;
		DatabaseConnection connect;
		sql::PreparedStatement* ps = connect.prepareStatement("SELECT MAX(record_ID) FROM Transaction_Record");
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next())
		{
			s = rs->getString("MAX(record_ID)");
		}
		
		for (int i = 1; i < 5; i++)
		{
			if (s[i] != 0)
			{
				store += s[i];
			}
		}

		int num = stoi(store);
		num++;
		s = std::to_string(num); //change datatype int to string
		s = 'R' + std::string(4 - s.size(), '0') + s;  //Add leading zeroes 

		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return s;

	}
	catch (...) { // No record ID found
		std::string s = "R0001";
		return s;
	}

}


int RecordManager::updateRecord(int selection, Record* record)
{
	DatabaseConnection connect;

	switch (selection)
	{
	case 1: //update record_name and type
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Transaction_Record SET record_name = ?, type = ? WHERE record_ID = ?");
		ps->setString(1, record->record_name);
		ps->setString(2, record->type);
		ps->setString(3, record->record_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 2: //update total
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Transaction_Record SET total = ? WHERE record_ID = ?");
		ps->setDouble(1, record->total);
		ps->setString(2, record->record_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	

	
	}
}

int RecordManager::updateReplace(std::string deleteStaffID, std::string staffID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Transaction_Record SET staff_ID = ? WHERE staff_ID = ?");
	ps->setString(1, staffID);
	ps->setString(2, deleteStaffID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int RecordManager::insertRecord(Record* record)
{
	
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("INSERT INTO Transaction_Record(record_ID, staff_ID, record_name, type) VALUES(? , ? , ? , ? )");
	ps->setString(1, record->record_ID);   
	ps->setString(2, record->staff_ID);
	ps->setString(3, record->record_name);
	ps->setString(4, record->type);
	
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int RecordManager::deleteRecord(Record* record)
{
	DetailManager detailmanager;
	int s = detailmanager.deleteDetail(record->record_ID);
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("DELETE FROM Transaction_Record where record_ID = ?");
	ps->setString(1, record->record_ID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

Record* linked(sql::ResultSet* rs)
{
	Record* record = NULL;
	Record* head = NULL;
	while (rs->next())
	{
		if (record == NULL)
		{
			record = new Record();
			head = record;
		}
		else
		{
			record->next = new Record();
			record = record->next;
		}

		transform(rs, record);
	}
	return head;
}


Record* RecordManager::getRecord(std::string record_ID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Transaction_Record WHERE record_ID = ?");
	ps->setString(1, record_ID);

	sql::ResultSet* rs = ps->executeQuery();
	Record* record = NULL;
	if (rs->next())
	{
		record = new Record();
		transform(rs, record);
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return record;
}


Record* RecordManager::getRecord()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Transaction_Record");
	sql::ResultSet* rs = ps->executeQuery();

	Record* head = linked(rs);


	rs->close();
	ps->close();

	delete rs;
	delete ps;
	return head;
}
	
std::string RecordManager::getFacultyID(std::string recordID)
{
	std::string s;
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT f.faculty_ID FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID INNER JOIN record_detail AS d ON r.record_ID = d.record_ID WHERE r.record_ID = ?");


	ps->setString(1, recordID);
	sql::ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		s = rs->getString("faculty_ID");
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;
	return s;
}

Record* RecordManager::getFac_Records(std::string facultyID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID WHERE f.faculty_ID = ?");


	ps->setString(1, facultyID);
	sql::ResultSet* rs = ps->executeQuery();
	Record* head = linked(rs);

	rs->close();
	ps->close();

	delete rs;
	delete ps;
	return head;

}

bool RecordManager::findStaff(std::string staffID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM transaction_record WHERE staff_ID = ?");


	ps->setString(1, staffID);
	sql::ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		return true;
	}


	rs->close();
	ps->close();

	delete rs;
	delete ps;
	return false;
}

Record* RecordManager::findSpend(std::string type, std::string facultyID) //using type and facultyID
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID WHERE f.faculty_ID = ? AND r.type = ?");
	ps->setString(1, facultyID);
	ps->setString(2, type);
	sql::ResultSet* rs = ps->executeQuery();
	Record* head = linked(rs);

	rs->close();
	ps->close();

	delete rs;
	delete ps;
	return head;
}

Record* RecordManager::findSpends(std::string recordName, std::string facultyID)
{
	try {
		DatabaseConnection connect;
		sql::PreparedStatement* ps = connect.prepareStatement("SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID WHERE f.faculty_ID = ? AND r.record_name = ?");
		ps->setString(1, facultyID);
		ps->setString(2, recordName);
		sql::ResultSet* rs = ps->executeQuery();
		Record* head = linked(rs);

		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return head;
	}
	catch (...) {// no record found
		Record* head = NULL;
		return head;
	}
	
}

Record* RecordManager::getRecord_Name(std::string name)
{
	try {
		DatabaseConnection connect;
		sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Transaction_Record where record_name = ?");
		ps->setString(1, name);
		sql::ResultSet* rs = ps->executeQuery();

		Record* head = linked(rs);

		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return head;
	}
	catch (...) {// no record found
		Record* head = NULL;
		return head;
	}
}

Record* RecordManager::getRecord_Year(std::string year, std::string facultyID)
{
	try {
		std::string Year = "\"" + year + "%\""; //  Example: Year = "2019%"
		DatabaseConnection connect;
		std::string sql1 = "SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID INNER JOIN record_detail AS d ON r.record_ID = d.record_ID WHERE f.faculty_ID = ? AND d.transaction_date like ";
		std::string sqlstatement = sql1 + Year;
		sql::PreparedStatement* ps = connect.prepareStatement(sqlstatement);
		ps->setString(1, facultyID);
		sql::ResultSet* rs = ps->executeQuery();
		
		Record* head = linked(rs);
		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return head;
	}
	catch (...) {// no record found
		Record* head = NULL;
		return head;
	}
}

Record* RecordManager::checkYear(std::string year)
{
	
	try {
		std::string Year = "\"" + year + "%\""; //  Example: Year = "2019%"
		DatabaseConnection connect;
		std::string sql1 = "SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN record_detail AS d ON r.record_ID = d.record_ID WHERE d.transaction_date like ";
		std::string sqlstatement = sql1 + Year;
		sql::PreparedStatement* ps = connect.prepareStatement(sqlstatement);
		sql::ResultSet* rs = ps->executeQuery();

		Record* head = linked(rs);
		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return head;
	}
	catch (...) {// no record found
		Record* head = NULL;
		return head;
	}
}

Record* RecordManager::Get3Years() //find the lastes 3 years in transaction record
{
	try {
		
		DatabaseConnection connect;
		sql::PreparedStatement* ps = connect.prepareStatement("SELECT DISTINCT year(transaction_date) FROM `record_detail` ORDER BY transaction_date DESC LIMIT 3");
		sql::ResultSet* rs = ps->executeQuery();

		Record* record = NULL;
		Record* head = NULL;
		while (rs->next())
		{
			if (record == NULL)
			{
				record = new Record();
				head = record;
			}
			else
			{
				record->next = new Record();
				record = record->next;
			}

			record->year = rs->getString("year(transaction_date)");
		}

		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return head;
	}
	catch (...) {// no record found
		Record* head = NULL;
		return head;
	}
}

Record* RecordManager::getRecord_TypeAndYear(std::string year, std::string facultyID, std::string type)
{
	try {
		std::string Year = "\"" + year + "%\""; //  Example: Year = "2019%"
		DatabaseConnection connect;
		
		std::string sql1 = "SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID INNER JOIN record_detail AS d ON r.record_ID = d.record_ID WHERE f.faculty_ID = ? AND d.transaction_date like ";
	
		std::string sql2 = " AND r.type = ?";
		std::string sqlstatement = sql1 + Year + sql2;
	
		sql::PreparedStatement* ps = connect.prepareStatement(sqlstatement);
		

		ps->setString(1, facultyID);
		ps->setString(2, type);
		sql::ResultSet* rs = ps->executeQuery();

		Record* head = linked(rs);
		rs->close();
		ps->close();
	
		delete rs;
		delete ps;
		return head;
	}
	catch (...) {// no record found
		Record* head = NULL;
		return head;
	}
}

bool RecordManager::findRecord(std::string facultyID, std::string recordID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT r.record_ID, r.staff_ID, r.record_name, r.type, r.total FROM transaction_record r INNER JOIN staff AS s ON r.staff_ID = s.staff_ID INNER JOIN faculty f ON f.faculty_ID = s.faculty_ID WHERE f.faculty_ID = ? AND r.record_ID = ?");


	ps->setString(1, facultyID);
	ps->setString(2, recordID);
	sql::ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		return true;
	}


	rs->close();
	ps->close();

	delete rs;
	delete ps;
	return false;
}