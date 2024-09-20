//
// Written by TheAidenS2014
// Code last modified 9/9/2024
// Project rebuilt 9/10/2024
//
// Random sandwich order
// generator using vector
// arrays.
//

using namespace std;
#include <iostream>
#include <random>
#include <vector>

vector<string> ingredientList_meats = { "beef", "turkey", "chicken", "ham" };
vector<string> ingredientList_sauces = { "ketchup", "mustard", "bbq sauce", "steak sauce", "mayo", "hot sauce" };
vector<string> ingredientList_cheeses = { "cheddar", "american", "parmesan", "swiss", "colby jack", "mozzerella" };
vector<string> ingredientList_toppings = { "tomatoes", "bacon", "onions", "lettuce", "mushrooms", "roasted vegetables" };

string choice_meats, choice_sauces, choice_cheeses, choice_toppings;
char user_satisfaction = ' ', user_refresh = ' ';
int user_returns = 0; // keeps track of how many order returns

int main()
{
	while (user_satisfaction != 'Y')
	{
		if (user_returns < 3) // return limit
		{
			srand(time(0)); // NOTE: refreshes every second, so fast loops may result in the same items again

			// if user requested a replacement or if first deciding sandwich ingredients
			// then generate ingredients from vector arrays and store in their designated variables
			if (user_refresh == 'M' || user_refresh == ' ')
				choice_meats = ingredientList_meats[rand() % ingredientList_meats.size()];
			if (user_refresh == 'S' || user_refresh == ' ')
				choice_sauces = ingredientList_sauces[rand() % ingredientList_sauces.size()];
			if (user_refresh == 'C' || user_refresh == ' ')
				choice_cheeses = ingredientList_cheeses[rand() % ingredientList_cheeses.size()];
			if (user_refresh == 'T' || user_refresh == ' ')
				choice_toppings = ingredientList_toppings[rand() % ingredientList_toppings.size()];

			// display order, request user answer
			cout << "Your order today is a " << choice_meats << " sandwich with " << choice_sauces << ", " << choice_cheeses << " cheese, and " << choice_toppings << ".\n";
			cout << "Does this sound toothsome? (\"Y\" or \"N\")\n> ";
			cin >> user_satisfaction;
			user_satisfaction = toupper(user_satisfaction);

			// user didn't like the sandwich ;(
			if (user_satisfaction == 'N')
			{
				// store replacement request for next loop
				cout << "What do you not like? (\"M\" for meats, \"S\" for sauces, \"C\" for cheeses, or \"T\" for toppings.)\n> ";
				cin >> user_refresh;
				user_refresh = toupper(user_refresh);
				cout << "We'll fix that right away! Fresh sandwhich coming up!" << endl;
				user_returns++;
			}

			cout << endl; // spacer
		}
		else
		{
			// too many returns; reject request
			cout << "...actually scratch that; you're costing us too much. Decide before you order next time." << endl;
			user_satisfaction = 'Y';
		}
	}

	// sandwich has been accepted
	cout << "Alright! That'll be $10.19. Cash or card?" << endl;
	return 0; // finish! [EXIT PROGRAM]
}

// © 2024 TheAidenS2014