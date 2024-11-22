//
// Written by TheAidenS2014
// Last modified 10/23/2024
//
// Lab11a: "Subclasses of a Store class"
// Defines four objects which are descendants
// of the `Store` class then displays their
// contents to the terminal in two tables.
//

#include "Lab11_StoreDetails.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// define stores
	PhysicalStore shop_BarnsNoble("Barnes & Noble", 500000, "4916 S Broadway Ave, Tyler, TX 75703", true);
	PhysicalStore shop_Target("Target", 1000000, "7003 S Broadway Ave, Tyler, TX 75703", true);
	WebStore shop_Etsy ("Etsy", 1500000, "www.etsy.com", false);
	WebStore shop_Amazon ("Amazon", 1000000000, "www.amazon.com", true);

	// display physical stores
	cout << "PHYSICAL STORES:\n";
	cout << setw(15) << std::left << "Brand" << setw(15) << "Revenue";
	cout << setw(40) << "Address" << setw(5) << boolalpha << "Wifi";
	cout << "\n----------------------------------------------------------------------------\n";
	shop_BarnsNoble.printDetails();
	cout << "\n";
	shop_Target.printDetails();
	
	cout << "\n\n";

	// display web stores
	cout << "DIGITAL STORES:\n";
	cout << setw(15) << std::left << "Brand" << setw(15) << "Revenue";
	cout << setw(15) << "URL" << setw(5) << boolalpha << "Drones";
	cout << "\n----------------------------------------------------\n";
	shop_Etsy.printDetails();
	cout << "\n";
	shop_Amazon.printDetails();
	
	// NOTE: not the most legible table code,
	//		 but it works all the same.

	cout << "\n";
	return 0; // finish [PRG EXIT]
}