//
// Written by TheAidenS2014
// Last modified 10/23/2024
// Header file for "Lab11ab"
//

#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using std::string;

class Store
{
	string brand = "TBD";
	double revenue = 0.0;

public:
	Store() = delete;
	Store(string user_brand, double user_revenue)
	{
		brand = user_brand;
		revenue = user_revenue;
	}

	void setBrand(string user_brand)
	{
		brand = user_brand;
	}
	void setRevenue(double user_revenue)
	{
		revenue = user_revenue;
	}

	string getBrand() const
	{
		return brand;
	}
	double getRevenue() const
	{
		return revenue;
	}

	void printDetails() const
	{
		std::cout << std::setw(15) << std::left << brand
		   << "$" << std::setw(14) << std::fixed << std::setprecision(2) << revenue;
	}
};

class WebStore : public Store
{
	string webAddress = "TBD";
	bool hasDroneDelivery = false;

public:
	WebStore() = delete;
	WebStore(string user_brand, double user_revenue, string user_url, bool user_drones) : Store::Store(user_brand, user_revenue)
	{
		webAddress = user_url;
		hasDroneDelivery = user_drones;
	}

	void setWebAddress(string user_url)
	{
		webAddress = user_url;
	}
	void setDroneDelivery(bool user_drones)
	{
		hasDroneDelivery = user_drones;
	}

	string getWebAddress() const
	{
		return webAddress;
	}
	bool getDroneDelivery() const
	{
		return hasDroneDelivery;
	}

	void printDetails() const
	{
		Store::printDetails();
		std::cout << std::setw(15) << webAddress
				  << std::setw(5) << std::boolalpha << hasDroneDelivery;
	}
};

class PhysicalStore : public Store
{
	string physicalAddress = "TBD";
	bool hasWifi = false;

public:
	PhysicalStore() = delete;
	PhysicalStore(string user_brand, double user_revenue, string user_address, bool user_wifi) : Store::Store(user_brand, user_revenue)
	{
		physicalAddress = user_address;
		hasWifi = user_wifi;
	}

	void setPhysicalAddress(string user_address)
	{
		physicalAddress = user_address;
	}
	void setWifiAccess(bool user_wifi)
	{
		hasWifi = user_wifi;
	}

	string getPhysicalAddress() const
	{
		return physicalAddress;
	}
	bool getWifiAccess() const
	{
		return hasWifi;
	}

	void printDetails() const
	{
		Store::printDetails();
		std::cout << std::setw(40) << physicalAddress
				  << std::setw(5) << std::boolalpha << hasWifi;
	}
};