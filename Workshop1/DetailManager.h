#include "DatabaseConnection.h"
#include "Detail.h"
#ifndef DETAILMANAGER_H
#define DETAILMANAGER_H

class DetailManager {
public:
	std::string assignID(std::string recordID);
	int updateDetail(int selection, Detail* detail);
	int insertDetail(Detail* detail, std::string recordID);
	int insertTotal(Detail* detail, std::string recordID); //total = quantity*price -> add total to table transaction_record
	int deleteDetail(std::string recordID);
	Detail* getDetail(std::string detail_ID);
	
	int numOfYear();
};
#endif