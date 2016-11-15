/*
 * billing.h
 *
 *  Created on: Nov 10, 2016
 *      Author: anil
 */

#ifndef WAALMART_H_
#define WAALMART_H_
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <istream>
#include <fstream>
#include <sstream>

class Waalmart {
	private:
		float total_bill;
		std::map<int,float> itemized_billing_map;
		std::vector<int> roommate_IDS;
	public:
		std::vector<float> all_prices;
		std::vector<std::string> roommate_sharings;
		std::map<int,std::string> names_map;
		int default_roommates_size;
		float price_of_item;
		std::string roommates;
		Waalmart();
		~Waalmart();
		void read_price();
		void devide_price(float price, std::string roommates);
		void add_bill_to_individual(int roommateID, const float price);
		void display_billing_amount();
		bool isValidRoommates();
		int getMaxNamewidth();
		void saveData();
		void rollback();
		int readFile();//return number of roommaes from the file
};




#endif /* WAALMART_H_ */
