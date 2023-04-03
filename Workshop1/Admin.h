#include <string>
#ifndef ADMIN_H
#define ADMIN_H

class Admin
{
public:
	std::string admin_ID, admin_name, admin_email, admin_contact, admin_password;
	Admin* next;
};
#endif
