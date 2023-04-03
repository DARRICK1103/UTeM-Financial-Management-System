#include <string>
#ifndef DETAIL_H
#define DETAIL_H

class Detail {
public:
	std::string detail_ID, record_ID, description, date;
	int quantity;
	double price;
	Detail* next;
};
#endif