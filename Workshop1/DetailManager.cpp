#include "DetailManager.h"

void transform(sql::ResultSet* rs, Detail* detail)
{
	detail->detail_ID = rs->getString("detail_ID");
	detail->record_ID = rs->getString("record_ID");
	detail->description = rs->getString("description");
	detail->quantity = rs->getInt("quantity");
	detail->price = rs->getDouble("price");
	detail->date = rs->getString("transaction_date");
}

std::string DetailManager::assignID(std::string recordID)
{
	std::string s = recordID;
	s[0] = 'D';
	return s;
}

int DetailManager::updateDetail (int selection, Detail* detail)
{
	DatabaseConnection connect;
	switch (selection)
	{
	case 3: //update description
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Record_Detail SET description = ? WHERE detail_ID = ?");
		ps->setString(1, detail->description);
		ps->setString(2, detail->detail_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 4: //update quantity
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Record_Detail SET quantity = ? WHERE detail_ID = ?");
		ps->setInt(1, detail->quantity);
		ps->setString(2, detail->detail_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 5: //update price
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Record_Detail SET price = ? WHERE detail_ID = ?");
		ps->setDouble(1, detail->price);
		ps->setString(2, detail->detail_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	case 6: //update date
	{
		sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Record_Detail SET transaction_date = ? WHERE detail_ID = ?");
		ps->setString(1, detail->date);
		ps->setString(2, detail->detail_ID);
		int status = ps->executeUpdate();
		ps->close();
		delete ps;
		return status;
	}
	
	}


	
}

int DetailManager::insertTotal(Detail* detail, std::string recordID)
{
	double total = (detail->quantity) * (detail->price);
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("UPDATE Transaction_Record SET total = ? WHERE record_ID = ?");
	ps->setDouble(1, total);
	ps->setString(2, recordID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int DetailManager::insertDetail(Detail* detail, std::string recordID)
{
	std::string s = assignID(recordID);
	
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("INSERT INTO Record_Detail (detail_ID, record_ID, description, quantity, price, transaction_date) VALUES(? , ? , ? , ? , ? , ?)");
	ps->setString(1, s);	
	ps->setString(2,recordID);
	ps->setString(3, detail->description);
	ps->setInt(4, detail->quantity);
	ps->setDouble(5, detail->price);
	ps->setString(6, detail->date);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

int DetailManager::deleteDetail(std::string recordID)
{
	std::string detailID = recordID;
	detailID[0] = 'D';
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("DELETE FROM Record_Detail where detail_ID = ?");
	ps->setString(1, detailID);
	int status = ps->executeUpdate();
	ps->close();
	delete ps;
	return status;
}

Detail* DetailManager::getDetail(std::string detail_ID)
{
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT * FROM Record_Detail WHERE detail_ID = ?");
	ps->setString(1, detail_ID);

	sql::ResultSet* rs = ps->executeQuery();
	Detail* detail = NULL;
	if (rs->next())
	{
		detail = new Detail();
		transform(rs, detail);
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return detail;
}

int DetailManager::numOfYear()
{
	int num = 0;
	DatabaseConnection connect;
	sql::PreparedStatement* ps = connect.prepareStatement("SELECT COUNT(DISTINCT(Year(transaction_date))) FROM record_detail");
	sql::ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		num = rs->getInt("COUNT(DISTINCT(Year(transaction_date)))");
	}
	rs->close();
	ps->close();

	delete rs;
	delete ps;

	return num;
}