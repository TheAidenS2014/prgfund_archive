//
// Written by TheAidenS2014
// Last modified 10/2/2024
// 
// Lab10a: "Inventory class"
// Displays the information of
// a pair of `Inventory` items
// using an external dependency.
//

#include <iostream>
#include <iomanip>
#include "Lab10a_brain.h"
using std::cout; using std::setw;
using std::left; using std::endl;
using std::fixed; using std::setprecision;

static void displayItem(std::string name, double price, int amount, double value)
{
	cout << left << fixed << setprecision(2)
			  << setw(20) << name
		<< "$" << setw(9) << price
			  << setw(10) << amount
		<< "$" << setw(9) << value
						  << endl;
}

int main()
{
	// define `Inventory` item 1
	// - "create then define" method
	Inventory supplyOfShoes;
	supplyOfShoes.setItemName("Nike");
	supplyOfShoes.setItemPrice(79.92); // https://t.ly/zsBBv
	supplyOfShoes.setUnitsAvailable(200);

	// define `Inventory` item 2
	// - "all at once" method
	Inventory supplyOfSocks{ "Fruit of the Loom", 11.99, 175 }; // https://t.ly/xWyUf

	// display details of all items
	cout << left << setw(20) << "Brand" << setw(10) << "Price" << setw(10) << "Stock" << setw(10) << "Value" << endl;
	cout << "--------------------------------------------------\n";
	displayItem(supplyOfShoes.getItemName(), supplyOfShoes.getItemPrice(), supplyOfShoes.getUnitsAvailable(), supplyOfShoes.calculateTotalValue());
	displayItem(supplyOfSocks.getItemName(), supplyOfSocks.getItemPrice(), supplyOfSocks.getUnitsAvailable(), supplyOfSocks.calculateTotalValue());
	cout << "--------------------------------------------------\n";

	return 0; // [EXIT PRG]
}

// © 2024 TheAidenS2014