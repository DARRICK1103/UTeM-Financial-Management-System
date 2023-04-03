#include "FacultyManager.h"
void transform(sql::ResultSet* rs, Faculty* faculty)
{
	faculty->faculty_ID = rs->getString("faculty_ID");
	faculty->admin_ID = rs->getString("admin_ID");
	faculty->faculty_name = rs->getString("faculty_name");
	faculty->faculty_address = rs->getString("faculty_address");
	faculty->faculty_contact = rs->getString("faculty_contact");
	faculty->faculty_balance = rs->getDouble("faculty_balance");
}

std::string FacultyManager::assignID()
{
	try {
		std::string s, store, staffID;
		DatabaseConnection connect;
		

		sql::PreparedStatement* ps = connect.prepareStatement("SELECT MAX(faculty_ID) FROM faculty");
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next())
		{
			s = rs->getString("MAX(faculty_ID)");
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
		s = 'F' + std::string(3 - s.size(), '0') + s;  //Add leading zeroes 

		rs->close();
		ps->close();

		delete rs;
		delete ps;
		return s;
	}
	catch (...) { //Faculty is null
		std::string s = "F001";
		
		return s;
	}

	
}



int FacultyManager::updateFaculty(int selection, Faculty* faculty)
{
	DatabaseConnection connect;
	switch (selection)
	{
	case 1: //update faculty name
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Faculty SET faculty_name = ? WHERE faculty_ID = ?");
		ps->setString(1, faculty->faculty_name);
		ps->setString(2, faculty->faculty_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 2: //update faculty_address
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Faculty SET faculty_address = ? WHERE faculty_ID = ?");
		ps->setString(1, faculty->faculty_address);
		ps->setString(2, faculty->faculty_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 3: //update faculty contact
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Faculty SET faculty_contact = ? WHERE faculty_ID = ?");
		ps->setString(1, faculty->faculty_contact);
		ps->setString(2, faculty->faculty_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 4: //update faculty balance
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Faculty SET faculty_balance = ? WHERE faculty_ID = ?");
		ps->setDouble(1, faculty->faculty_balance);
		ps->setString(2, faculty->faculty_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	
	}

}

int FacultyManager::insertFaculty(Faculty* faculty)
{
	std::string s = assignID();
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("INSERT INTO Faculty (faculty_ID, admin_ID, faculty_name, faculty_address, faculty_contact, faculty_balance) VALUES (?, ?, ?, ?, ?, ?)");
	ps->setString(1, s);
	ps->setString(2, faculty->admin_ID);
	ps->setString(3, faculty->faculty_name);
	ps->setString(4, faculty->faculty_address);
	ps->setString(5, faculty->faculty_contact);
	ps->setDouble(6, faculty->faculty_balance);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int FacultyManager::deleteFaculty(Faculty* faculty)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("DELETE FROM Faculty where faculty_ID = ?");
	ps->setString(1, faculty->faculty_ID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

Faculty* FacultyManager::getFaculty(std::string faculty_ID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Faculty WHERE faculty_ID = ?");
	ps->setString(1, faculty_ID);

	sql::ResultSet* rs = ps->executeQuery();
	Faculty* faculty = NULL;
	if (rs->next())
	{
		faculty = new Faculty();
		transform(rs, faculty);
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return faculty;
}

Faculty* FacultyManager::getFaculty()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Faculty");
	sql::ResultSet* rs = ps->executeQuery();
	Faculty* faculty = NULL;
	Faculty* head = NULL;

	while (rs->next())
	{
		if (faculty == NULL)
		{
			faculty = new Faculty();
			head = faculty;
		}
		else
		{
			faculty->next = new Faculty();
			faculty = faculty->next;
		}

		transform(rs, faculty);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

