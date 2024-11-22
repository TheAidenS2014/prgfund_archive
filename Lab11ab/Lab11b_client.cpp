//
// Written by TheAidenS2014
// Last modified 10/23/2024
//
// Lab11b: "Grandchild class (extension of Lab11a)"
// Defines three objects which are descendants
// of the `Store` class, one of which is a
// descendant of `PhysicalStore`, then displays
// their contents to the terminal with tables.
//
// Contains code ripped straight from Lab11a
//

#include "Lab11_StoreDetails.h"
#include <iostream>
#include <iomanip>
using namespace std;

class GroceryStore : public PhysicalStore
{
	bool hasProduce = false;
	bool isChain = false;

public:
	GroceryStore() = delete;
	GroceryStore(std::string user_brand, double user_revenue, std::string user_address, bool user_wifi, bool user_produce, bool user_chain)
	: PhysicalStore::PhysicalStore(user_brand, user_revenue, user_address, user_wifi)
	{
		hasProduce = user_produce;
		isChain = user_chain;
	}

	void setProduceBool(bool user_produce) { hasProduce = user_produce; }
	void setChainBool(bool user_chain) { isChain = user_chain; }

	bool getProduceBool() const { return hasProduce; }
	bool getChainBool() const { return isChain; }

	void printDetails() const
	{
		PhysicalStore::printDetails();
		std::cout << "   " << std::setw(10) << std::boolalpha << hasProduce
				  << std::setw(8) << std::boolalpha << isChain;
	}
};

int main()
{
	// define stores
	PhysicalStore shop_Target("Target", 1000000, "7003 S Broadway Ave, Tyler, TX 75703", true);
	WebStore shop_Etsy("Etsy", 1500000, "www.etsy.com", false);
	GroceryStore shop_Brkshr("Brookshires", 500000, "2020 Roseland Blvd, Tyler, TX 75701", true, true, true);

	// display physical store
	cout << "PHYSICAL STORES:\n";
	cout << setw(15) << std::left << "Brand" << setw(15) << "Revenue";
	cout << setw(40) << "Address" << setw(5) << boolalpha << "Wifi?";
	cout << "\n----------------------------------------------------------------------------\n";
	shop_Target.printDetails();
	cout << "\n\n";

	// display web store
	cout << "DIGITAL STORES:\n";
	cout << setw(15) << std::left << "Brand" << setw(15) << "Revenue";
	cout << setw(15) << "URL" << setw(5) << boolalpha << "Drones?";
	cout << "\n----------------------------------------------------\n";
	shop_Etsy.printDetails();
	cout << "\n\n";

	// display grocery store
	cout << "GROCERY STORES:\n";
	cout << setw(15) << std::left << "Brand" << setw(15) << "Revenue";
	cout << setw(40) << "Address" << setw(8) << boolalpha << "Wifi";
	cout << boolalpha << setw(10) << "Produce" << setw(8) << "Chain";
	cout << "\n----------------------------------------------------------------------------------------------\n";
	shop_Brkshr.printDetails();

	// NOTE: not the most legible table code,
	//		 but it works all the same.

	cout << "\n";
	return 0; // finish [PRG EXIT]
}