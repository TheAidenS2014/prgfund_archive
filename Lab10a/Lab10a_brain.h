//
// Written by TheAidenS2014
// Last modified 10/2/2024
// Header file for Lab10a: "Inventory class"
//

#pragma once
#include <string>
using std::string;

// Contains the name, price, and amount of stock
// Stored in that order as a `string`, `double`, and `int`
class Inventory
{
private:
	string itemName;
	double itemPrice;
	int unitsAvailable;

public:
	// constructors
	Inventory()
	{
		itemName = "TBD";
		itemPrice = 0.00;
		unitsAvailable = 0;
	}
	Inventory(string user_item_name, double user_item_price, int user_item_count)
	{
		itemName = user_item_name;
		itemPrice = user_item_price;
		unitsAvailable = user_item_count;
	}

	// setters
	void setItemName(string user_item_name)
	{
		itemName = user_item_name;
	}
	void setItemPrice(double user_item_price)
	{
		itemPrice = user_item_price;
	}
	void setUnitsAvailable(int user_item_count)
	{
		unitsAvailable = user_item_count;
	}

	// getters
	string getItemName() const
	{
		return itemName;
	}
	double getItemPrice() const
	{
		return itemPrice;
	}
	int getUnitsAvailable() const
	{
		return unitsAvailable;
	}

	// multiplies units and price together
	double calculateTotalValue()
	{
		// `this` refers to the supplied `Inventory` item
		return (this->unitsAvailable * this->itemPrice);
	}
};

// © 2024 TheAidenS2014