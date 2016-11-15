#include "waalmart.h"

int main(int argc, char **argv) {
	Waalmart waalmart;
	//waalmart.readFile();

	waalmart.read_price();


	while (waalmart.price_of_item != -100) {

		if (waalmart.price_of_item == -99) {
			waalmart.rollback();
			waalmart.display_billing_amount();
			waalmart.read_price();

		} else {
			if (waalmart.isValidRoommates()) {
				waalmart.saveData();
				waalmart.devide_price(waalmart.price_of_item,waalmart.roommates);
				waalmart.display_billing_amount();
				waalmart.read_price();
			} else {
				std::cout << "Please enter valid roommate ID's" << std::endl;
				waalmart.read_price();
			}
		}

	}

	return 0;
}

