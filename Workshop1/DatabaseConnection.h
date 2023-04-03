#include <mysql/jdbc.h>
#include <string>

#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

class DatabaseConnection {
private:
	
	sql::Connection* connection;
public:
	DatabaseConnection();
	~DatabaseConnection();
	sql::PreparedStatement* prepareStatement(std::string query);
};
#endif