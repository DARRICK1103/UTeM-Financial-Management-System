#include "StaffManager.h"

void transform(sql::ResultSet* rs, Staff* staff)
{
	staff->staff_ID = rs->getString("staff_id");
	staff->admin_ID = rs->getString("admin_id");
	staff->faculty_ID = rs->getString("faculty_id");
	staff->staff_name = rs->getString("staff_name");
	staff->staff_email = rs->getString("staff_email");
	staff->staff_contact = rs->getString("staff_contact"); 
	staff->staff_password = rs->getString("staff_password");
}

std::string StaffManager::assignID()
{
	try {
		std::string s, store, staffID;
		DatabaseConnection connect;
		sql::PreparedStatement* ps = connect.prepareStatement("SELECT staff_ID FROM Staff ORDER BY staff_ID ASC");

		sql::ResultSet* rs = ps->executeQuery();
		rs->afterLast();
		//cout << rs->getString("staff_ID") << endl;
		if (rs->previous())
		{
			s = rs->getString("staff_ID");
		}
		for (int i = 1; i < 5; i++) //R0001 ->0001  => 1
		{
			if (s[i] != 0)
			{
				store += s[i];
			}
		}

		int num = stoi(store);
		num++; //2 = size = 1
		s = std::to_string(num); //change datatype int to string
		s = 'S' + std::string(4 - s.size(), '0') + s;  //Add leading zeroes 

		return s;
	}
	catch (...) {
		std::string s = "S0001";
		return s;
	}

	
}

int StaffManager::addStaff(Staff* staff, std::string adminID)
{
	
	std::string s = assignID();
	
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("INSERT INTO Staff (staff_ID, admin_ID, faculty_ID, staff_name, staff_email, staff_contact, staff_password) VALUES (?, ?, ?, ?, ?, ?, ? )");
	ps->setString(1, s);
	ps->setString(2, adminID);
	ps->setString(3, staff->faculty_ID);
	ps->setString(4, staff->staff_name);
	ps->setString(5, staff->staff_email);
	ps->setString(6, staff->staff_contact);
	ps->setString(7, staff->staff_password);

	int status = ps->executeUpdate();
	
	ps->close();
	delete ps;
	return status;

}

int StaffManager::updateStaff(int selection, Staff* staff)
{
	DatabaseConnection connect;
	switch (selection)
	{
	case 1: //update faculty_ID
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Staff SET faculty_ID = ? WHERE staff_ID = ?");
		ps->setString(1, staff->faculty_ID);
		ps->setString(2, staff->staff_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 2: //update staff_name
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Staff SET staff_name = ? WHERE staff_ID = ?");
		ps->setString(1, staff->staff_name);
		ps->setString(2, staff->staff_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 3: //update staff_email
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Staff SET staff_email = ? WHERE staff_ID = ?");
		ps->setString(1, staff->staff_email);
		ps->setString(2, staff->staff_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 4: //update staff_contact
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Staff SET staff_contact = ? WHERE staff_ID = ?");
		ps->setString(1, staff->staff_contact);
		ps->setString(2, staff->staff_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 5: //update staff_password
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Staff SET staff_password = ? WHERE staff_ID = ?");
		ps->setString(1, staff->staff_password);
		ps->setString(2, staff->staff_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	}
	
	

	

}

int StaffManager::deleteStaff(Staff* staff)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("DELETE FROM Staff WHERE staff_ID = ?");
	ps->setString(1, staff->staff_ID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}



Staff* StaffManager::getStaffID(std::string staff_ID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Staff WHERE staff_ID = ?");
	ps->setString(1, staff_ID);

	sql::ResultSet* rs = ps->executeQuery();
	Staff* staff = NULL;
	if (rs->next())
	{
		staff = new Staff();
		transform(rs, staff);
		 
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return staff;
}

Staff* StaffManager::loginStaff(std::string staff_ID, std::string staff_password)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Staff WHERE staff_ID = ? AND staff_password = ?");
	ps->setString(1, staff_ID);
	ps->setString(2, staff_password);
	sql::ResultSet* rs = ps->executeQuery();
	Staff* staff = NULL;
	if (rs->next())
	{
		staff = new Staff();
		transform(rs, staff);

	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return staff;
}

Staff* StaffManager::getStaffs()
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Staff");
	sql::ResultSet* rs = ps->executeQuery();
	Staff* staff = NULL;
	Staff* head = NULL;

	while (rs->next())
	{
		if (staff == NULL)
		{
			staff = new Staff();
			head = staff;
		}
		else
		{
			staff->next = new Staff();
			staff = staff->next;
		}

		transform(rs, staff);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}

Staff* StaffManager::getStaff(std::string facultyID)
{
	DatabaseConnection dbConn;
	sql::PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Staff WHERE faculty_ID = ?");
	ps->setString(1, facultyID);
	sql::ResultSet* rs = ps->executeQuery();
	Staff* staff = NULL;
	Staff* head = NULL;

	while (rs->next())
	{
		if (staff == NULL)
		{
			staff = new Staff();
			head = staff;
		}
		else
		{
			staff->next = new Staff();
			staff = staff->next;
		}

		transform(rs, staff);
	}

	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return head;
}
