#include "AdminManager.h"

void transform(sql::ResultSet* rs, Admin* admin)
{
	admin->admin_ID = rs->getString("admin_ID");
	admin->admin_name = rs->getString("admin_name");
	admin->admin_email = rs->getString("admin_email");
	admin->admin_contact = rs->getString("admin_contact");
	admin->admin_password = rs->getString("admin_password");
}

std::string AdminManager::assignID()
{
	try {
		std::string s, store, adminID;
		DatabaseConnection connect;
		sql::PreparedStatement* ps = connect.prepareStatement("SELECT admin_ID FROM Admin ORDER BY admin_ID ASC");

		sql::ResultSet* rs = ps->executeQuery();
		rs->afterLast();
		//cout << rs->getString("admin_ID") << endl;
		if (rs->previous())
		{
			s = rs->getString("admin_ID");
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
		s = 'A' + std::string(4 - s.size(), '0') + s;  //Add leading zeroes 

		return s;
	}
	catch (...) {
		std::string s = "A0001";
		return s;
	}
	
}

int AdminManager::addAdmin(Admin* admin)
{
	std::string s = assignID();
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("INSERT INTO Admin (admin_ID, admin_name, admin_email, admin_contact, admin_password VALUES (?, ?, ?, ?, ?)");
	ps->setString(1, s);
	ps->setString(2, admin->admin_name);
	ps->setString(3, admin->admin_email);
	ps->setString(4, admin->admin_contact);
	ps->setString(5, admin->admin_password);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int AdminManager::deleteAdmin(Admin* admin)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("DELETE FROM Admin where admin_ID = ?");
	ps->setString(1, admin->admin_ID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int AdminManager::updateAdmin(int selection, Admin* admin)
{
	DatabaseConnection connect;
	switch (selection)
	{
	case 1: //update admin_name
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Admin SET admin_name = ? where admin_ID = ?");
		ps->setString(1, admin->admin_name);
		ps->setString(2, admin->admin_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 2: //update admin_email
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Admin SET admin_email = ? where admin_ID = ?");
		ps->setString(1, admin->admin_email);
		ps->setString(2, admin->admin_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 3: //update admin_contact
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Admin SET admin_contact = ? where admin_ID = ?");
		ps->setString(1, admin->admin_contact);
		ps->setString(2, admin->admin_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 4: //update admin_password
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Admin SET admin_password = ? where admin_ID = ?");
		ps->setString(1, admin->admin_password);
		ps->setString(2, admin->admin_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	}
	
}

Admin* AdminManager::getAdmin(std::string admin_ID)
{

	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Admin WHERE admin_ID = ?");
	ps->setString(1, admin_ID);

	sql::ResultSet* rs = ps->executeQuery();
	Admin* admin = NULL;
	if (rs->next())
	{
		admin = new Admin();
		transform(rs, admin);
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return admin;
}

Admin* AdminManager::loginAdmin(std::string admin_ID, std::string admin_password)
{	
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Admin WHERE admin_ID = ? AND admin_password = ?");
	ps->setString(1, admin_ID);
	ps->setString(2, admin_password);

	sql::ResultSet* rs = ps->executeQuery();
	Admin* admin = NULL;
	if (rs->next())
	{
		admin = new Admin();
		transform(rs, admin);

	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return admin;
}

int AdminManager::numOfStaff(Admin* admin)
{
	int numOfRows = 0;
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Staff where admin_ID = ? ORDER BY staff_ID DESC");
	ps->setString(1, admin->admin_ID);
	sql::ResultSet* rs = ps->executeQuery();
	rs->afterLast();
	while (rs->previous())
	{
		std::cout << rs->getString("staff_ID") << "  ->  " << rs->getString("staff_name") << "  ||   ";
		
		numOfRows++;
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;
	
	return numOfRows;
}