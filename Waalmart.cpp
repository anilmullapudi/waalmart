#include "waalmart.h"

Waalmart::Waalmart() {
	total_bill = 0.0;
	price_of_item = 0.0;
	default_roommates_size = readFile();

}

Waalmart::~Waalmart() {

}

std::string IntToString(int number) {
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

void Waalmart::read_price() {

	price_of_item = 0.0;
	roommates = "";

	std::cout << "Welcome to Waalmart App" << std::endl;
	std::cout << "enter price of item or -99:rollback -100:quit" << std::endl;
	std::cin >> price_of_item;

	if(price_of_item == -99) {
		return; //user is requesting rollback, Do not display options to choose roommates
	}

	std::string space = " ";
	std::string dispaly_names;

	for (std::map<int, std::string>::iterator it = names_map.begin();
			it != names_map.end(); ++it) {
		dispaly_names = dispaly_names + space + IntToString(it->first) + "-" + it->second + ",";
	}
	dispaly_names.pop_back();

	std::cout << "Enter roomate id's " << dispaly_names << std::endl;
	std::cout << "a-all\n";

	std::cout << std::endl;
	std::cin >> roommates;
}

void Waalmart::devide_price(float price, std::string roommateIDs) {

	int size = roommateIDs.size();
	int roommate_ID = 0;

	total_bill = total_bill + price;
	float devided_price = price / size;
	for (int i = 0; i < size; i++) {
		roommate_ID = roommateIDs[i] - '0';
		add_bill_to_individual(roommate_ID, devided_price);
	}

}

bool Waalmart::isValidRoommates() {
	int size = roommates.size();

	if (size > default_roommates_size || size <= 0) {
		std::cout << "Please enter valid roommate members";
		return false;
	}

	if (roommates == "a") {
		roommates = "";
		for (std::map<int, std::string>::iterator it = names_map.begin(); it != names_map.end(); ++it) {
			roommates = roommates + IntToString(it->first);
		}
		return true;
	}

	int roommate_ID;
	for (std::string::size_type i = 0; i < roommates.size(); i++) {
		roommate_ID = roommates[i] - '0';
		std::vector<int>::iterator it;

		it = find(roommate_IDS.begin(), roommate_IDS.end(), roommate_ID);
		if (it != roommate_IDS.end()) {
			//std::cout << "Valid roommate " << *it << '\n';
		} else {
			//std::cout << "Invalid roommate " << *it << '\n';
			return false;
		}
	}
	return true;
}

void Waalmart::add_bill_to_individual(int roomateID, float price) {
	float newpirce = itemized_billing_map.at(roomateID) + price;
	if(newpirce < 0) {
		newpirce = 0.0;
	}
	itemized_billing_map[roomateID] = newpirce;
}

void Waalmart::display_billing_amount() {
	//int width = getMaxNamewidth();
	std::cout << "Total waalmart bill amount is: " << total_bill << std::endl;

	for (std::map<int, std::string>::iterator it = names_map.begin(); it != names_map.end(); ++it) {
		std::cout <<it->second<<" bill amount:: " << itemized_billing_map.at(it->first)<< std::endl;
	}
}

int Waalmart::getMaxNamewidth() {
	return 0;
}

void Waalmart::saveData() {
	all_prices.push_back(price_of_item);
	roommate_sharings.push_back(roommates);
}

void Waalmart::rollback() {
	//std::cout<<"all_prices.size():"<<all_prices.size()<<std::endl;
	//std::cout<<"roommate_sharings.size():"<<roommate_sharings.size()<<std::endl;
	if (all_prices.size() > 0 && roommate_sharings.size() > 0) {
		float previous_price = all_prices.back();
		std::string previsou_roommates = roommate_sharings.back();
		previous_price *= -1;
		devide_price(previous_price, previsou_roommates);
		all_prices.pop_back();
		roommate_sharings.pop_back();
	} else {
		std::cout<<"There are no items to rollback.."<<std::endl;
	}
}

std::string trim(const std::string &s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isspace(*it))
		it++;

	std::string::const_reverse_iterator rit = s.rbegin();
	while (rit.base() != it && isspace(*rit))
		rit++;

	return std::string(it, rit.base());
}

int Waalmart::readFile() {

	std::string filepath = "conf//Names.txt";

	std::string name;
	std::ifstream namesfile(filepath.c_str());

	int i=0;
	if (namesfile.is_open()) {
		while (getline(namesfile, name)) {
			//std::cout << name << std::endl;
			++i;
			names_map[i] = trim(name);
			itemized_billing_map[i] = 0.0; //initializing default prize for each user and their id's
			roommate_IDS.push_back(i);
		}
		namesfile.close();
	}

	return i;
}

