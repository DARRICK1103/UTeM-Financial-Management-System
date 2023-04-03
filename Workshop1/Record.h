#include <string>
#ifndef RECORD_H
#define RECORD_H

class Record {
public:
	std::string record_ID, staff_ID, record_name, type, year;
	double total;
	Record* next;
};
#endif

