//
// TheAidenS2014
// Last modified 4/18/2024
//
// A terminal app that translates
// user-inputted English strings
// into Pig Latin strings using
// only two functions.
//

using namespace std;
#include <iostream>
#include <string>

// global variables
string userInput;
string translatedInput;

// functions
bool isVowel(char letter)
{
	letter = tolower(letter);

	switch (letter)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return true;  // is a vowel
		default:
			return false; // isn't a vowel
	}
}
string pigLatinString(string word, int position)
{
	if (position == word.length())
		// if `word` has no vowels, `position` will be after the last letter of `word`
		// however, the furthest `position` can legally be is one less then the length of `word`
		// as such, we can force these situations to meet the first condition
		position = 0;

	word.append("-");
	if (position == 0)
		// if word starts with a vowel
		word.append("way");								// add "way" to complete pig latin translation
	else
	{
		// if word doesn't begin with a vowel
		string word_snippet = word.substr(0, position); // save the letters before the vowel to `word_snippet`
		word.erase(0, position);						// remove said letters from `word`
		word.append(word_snippet);						// add `word_snippet` to `word` (after the dash)
		word.append("ay");								// add "ay" to complete pig latin translation
	}

	return word;
}

// primary script
int main()
{
	// main() exclusive variables
	string sentence_cache;
	string word_cache;
	int vowel_spot = 0;
	int word_spot = 0;

	cout << "Please input an English word or phrase:\n> ";
	getline(cin, userInput);
	sentence_cache = userInput;

	if (userInput.back() == '!' || userInput.back() == '?' || userInput.back() == '.')
		// removes ending punctuation (if any)
		sentence_cache.erase(sentence_cache.length() - 1);

	while (sentence_cache.length() != 0)
	{
		// word scanner
		for (int loop = 0; !isspace(sentence_cache[loop]) && loop < sentence_cache.length(); loop++)
			// scans each position the sentence for a space, exiting upon finding one (or reaching the end) and saving it's position
			word_spot++;

		// extracts the scanned word from the string
		word_cache = sentence_cache.substr(0, word_spot);
		sentence_cache.erase(0, word_spot);
		if (sentence_cache.empty() == false) // removes the space left behind (unless at the end)
			sentence_cache.erase(0, 1);

		// vowel scanner
		for (int loop = 0; isVowel(word_cache[loop]) != true && loop < word_cache.length(); loop++)
			// scans each position the word for a vowel, exiting upon finding one (or reaching the end) and saving it's position
			vowel_spot++;

		// appends the translated word to a seperate string
		translatedInput.append(pigLatinString(word_cache, vowel_spot));
		translatedInput.append(" ");

		// clear scanners for next loop
		vowel_spot = 0;
		word_spot = 0;
	}

	translatedInput.erase(translatedInput.length() - 1); // removes the extra space at the end
	if (userInput.back() == '!' || userInput.back() == '?' || userInput.back() == '.')
		// restores ending punctuation (if any)
		translatedInput = translatedInput + userInput.back();

	cout << "\nGuess what? That in Pig Latin is:\n> " << translatedInput << endl;

	return 0; // finish! [EXIT]
}

// © 2024 TheAidenS2014