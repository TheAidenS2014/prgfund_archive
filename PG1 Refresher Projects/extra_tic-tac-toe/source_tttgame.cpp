//
// Written by TheAidenS2014
// Code last modified 9/2/2024
// Project rebuilt 9/10/2024
// 
// Endless two player
// tic-tac-toe on the
// terminal, with a lot of
// flair and some
// customization.
//

using namespace std;
#include <iostream>

const int GAMEBOARD_SIZE = 3; // square grid
const char P1_MARKER = 'X',
P2_MARKER = 'O';
char gameboard_array[GAMEBOARD_SIZE][GAMEBOARD_SIZE]{};

bool gameloop_active = true;
int gameloop_turns = 1,
player_current = 1; // 1 & 2
string player_move;

static void clearGameboard()
{
	for (int index_x = 0; index_x < GAMEBOARD_SIZE; index_x++)
	{
		for (int index_y = 0; index_y < GAMEBOARD_SIZE; index_y++)
		{
			gameboard_array[index_x][index_y] = ' '; // initializes each array position with blanks
		}
	}
}

static void drawGameboard()
{
	cout << "    1   2   3 " << endl;
	cout << endl;
	cout << "A   " << gameboard_array[0][0] << " | " << gameboard_array[0][1] << " | " << gameboard_array[0][2] << " " << endl;
	cout << "   ---|---|---" << endl;
	cout << "B   " << gameboard_array[1][0] << " | " << gameboard_array[1][1] << " | " << gameboard_array[1][2] << " " << endl;
	cout << "   ---|---|---" << endl;
	cout << "C   " << gameboard_array[2][0] << " | " << gameboard_array[2][1] << " | " << gameboard_array[2][2] << " " << endl;

	/*cout << endl;
	cout << " # | # | # " << endl;
	cout << "---|---|---" << endl;
	cout << " # | # | # " << endl;
	cout << "---|---|---" << endl;
	cout << " # | # | # " << endl;*/
}

static int updateGameboard(string action, int player)
{
	// translate user input
	char letter = tolower(action[0]);
	int index_x = (int)action[1] - '0';
	int index_y = -1;
	// convert letter to number (ex: b3 -> 13)
	if (letter == 'a') { index_y = 0; }
	if (letter == 'b') { index_y = 1; }
	if (letter == 'c') { index_y = 2; }

	// check if indexes are within bounds
	if (index_x > GAMEBOARD_SIZE || index_x < 0)
		return 1; // bad x value; retry [EXIT]
	if (index_y > GAMEBOARD_SIZE || index_y < 0)
		return 2; // bad y value; retry [EXIT]

	// check if spot is available
	if (gameboard_array[index_y][index_x - 1] == P1_MARKER && player == 2 || gameboard_array[index_y][index_x - 1] == P2_MARKER && player == 1)
		return 3; // spot is taken; retry [EXIT]
	if (gameboard_array[index_y][index_x - 1] == P1_MARKER && player == 1 || gameboard_array[index_y][index_x - 1] == P2_MARKER && player == 2)
		return 3; // already used this spot; retry [EXIT]

	// if all is good, then apply move to array
	if (player == 1)
		gameboard_array[index_y][index_x - 1] = P1_MARKER;
	else
		gameboard_array[index_y][index_x - 1] = P2_MARKER;

	return 0; // no issues; continue [EXIT]
}

static int winCheck()
{
	// straight across (player 1)
	if (gameboard_array[0][0] == P1_MARKER && gameboard_array[0][1] == P1_MARKER && gameboard_array[0][2] == P1_MARKER
		|| gameboard_array[1][0] == P1_MARKER && gameboard_array[1][1] == P1_MARKER && gameboard_array[1][2] == P1_MARKER
		|| gameboard_array[2][0] == P1_MARKER && gameboard_array[2][1] == P1_MARKER && gameboard_array[2][2] == P1_MARKER)
		return 1; // p1 wins! [EXIT]
	// straight down (player 1)
	if (gameboard_array[0][0] == P1_MARKER && gameboard_array[1][0] == P1_MARKER && gameboard_array[2][0] == P1_MARKER
		|| gameboard_array[0][1] == P1_MARKER && gameboard_array[1][1] == P1_MARKER && gameboard_array[2][1] == P1_MARKER
		|| gameboard_array[0][2] == P1_MARKER && gameboard_array[1][2] == P1_MARKER && gameboard_array[2][2] == P1_MARKER)
		return 1; // p1 wins! [EXIT]
	// diagonal (player 1)
	if (gameboard_array[0][0] == P1_MARKER && gameboard_array[1][1] == P1_MARKER && gameboard_array[2][2] == P1_MARKER
		|| gameboard_array[0][2] == P1_MARKER && gameboard_array[1][1] == P1_MARKER && gameboard_array[2][0] == P1_MARKER)
		return 1;  // p1 wins! [EXIT]

	// straight across (player 2)
	if (gameboard_array[0][0] == P2_MARKER && gameboard_array[0][1] == P2_MARKER && gameboard_array[0][2] == P2_MARKER
		|| gameboard_array[1][0] == P2_MARKER && gameboard_array[1][1] == P2_MARKER && gameboard_array[1][2] == P2_MARKER
		|| gameboard_array[2][0] == P2_MARKER && gameboard_array[2][1] == P2_MARKER && gameboard_array[2][2] == P2_MARKER)
		return 2;  // p2 wins! [EXIT]
	// straight down (player 2)
	if (gameboard_array[0][0] == P2_MARKER && gameboard_array[1][0] == P2_MARKER && gameboard_array[2][0] == P2_MARKER
		|| gameboard_array[0][1] == P2_MARKER && gameboard_array[1][1] == P2_MARKER && gameboard_array[2][1] == P2_MARKER
		|| gameboard_array[0][2] == P2_MARKER && gameboard_array[1][2] == P2_MARKER && gameboard_array[2][2] == P2_MARKER)
		return 2; // p2 wins! [EXIT]
	// diagonal (player 2)
	if (gameboard_array[0][0] == P2_MARKER && gameboard_array[1][1] == P2_MARKER && gameboard_array[2][2] == P2_MARKER
		|| gameboard_array[0][2] == P2_MARKER && gameboard_array[1][1] == P2_MARKER && gameboard_array[2][0] == P2_MARKER)
		return 2; // p2 wins! [EXIT]

	if (gameloop_turns >= 9)
		return 3; // cat's game! [EXIT]

	return 0; // no one is winning yet [EXIT]
}

int main()
{
	clearGameboard();

	while (gameloop_active == true)
	{
		drawGameboard();

		cout << "\nPLAYER #" << player_current << "\nInput your move (EX: A1):\n> ";
		cin >> player_move;

		int turn_results = updateGameboard(player_move, player_current); // store results in a variable as to not repeat updateGameboard
		if (winCheck() == 0) // turn ended
		{
			if (turn_results == 0) // no one is winning yet
			{
				if (player_current == 1)
					player_current++; // -> p2
				else
					player_current--; // -> p1

				gameloop_turns++;
			}
			else if (turn_results == 1 || turn_results == 2)
			{
				cout << "=== Not a real location Try again! ===" << endl;
				system("PAUSE");
			}
			else if (turn_results == 3)
			{
				cout << "=== Spot is already taken. Try again! ===" << endl;
				system("PAUSE");
			}

			system("CLS");
		}
		else
		{
			// game is finished!
			system("CLS");
			drawGameboard();

			// display game results
			cout << "\n=== ";
			if (winCheck() == 1)
			{
				cout << "Player #1 wins!";
				player_current = 1; // winner starts next round
			}
			else if (winCheck() == 2)
			{
				cout << "Player #2 wins!";
				player_current = 2; // winner starts next round
			}
			else
				cout << "Cat's game! No one wins!";
			cout << " ===" << endl;

			// clear game for next round
			system("PAUSE");
			system("CLS");
			gameloop_turns = 1;
			clearGameboard();
		}
	}

	return 0;
}

// © 2024 TheAidenS2014