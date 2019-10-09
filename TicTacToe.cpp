/*	Author: Bryan Lopez; COP 3331 Dr. T Neal.
	Purpose: This program simulates the tic tac toe game.
		 the program checks for user input. Checks if the entries
		 are out of bounds, rotates between player turns, 
		 prints out who the winner is and takes into account a tie scenario
*/

#include <iostream>
#include <array>

using namespace std;

//FUNCTION DECLARATIONS 
void print_map();
bool check_forWinner(array<array<char, 3>, 3> map, int num_of_turns);

//global array to store the input
array<array<char, 3>, 3> map = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' } };

//start of the program 
int main()
{
	//variables used for the program. row and column initialize the arrays to the first element
	//number of turns keeps track of how many turns go by and to check for a tie, finally loop
	//control is in charge of the loop 

	cout << "Coding Project\n";


	int row = 0, column = 0, number_of_turns = 1; 
	bool loop_control = false;

	//print the header of the program
	cout << "Welcome to Tic Tac Toe\n" << endl;
	print_map(); //function to print the map

	int whos_turn = 1; // variable to cycle between X and O 
	while (!loop_control) {
		//modulus calculation checks for even or odd and thats how it chooses the turns
		if ((whos_turn % 2) < 1) {
			// this portion takes user input and decrements the values to make sure the array starts at [0][0]
			// we know to the program the first element is 0,0 yet for the user its 1,1 
			cout << "\nO's turn\n";
			cout << "Pick a row (1, 2, 3): ";
			cin >> row;
			cout << "Pick a column (1, 2, 3): ";
			cin >> column;
			cout << endl;
			row--;
			column--;
			try {
				//try statement to catch a possible out of bounds access on the arrray
				if (row >= 3 || column >= 3) {
					throw 9999;
				}
				if (map[row][column] == 'X' || map[row][column] == 'O') { //if the row is already taken do this
					cout << "Invalid row. Try again" << endl;
					continue;
				}
				map[row][column] = 'O';
				whos_turn++; //increase value to change control to X or O
				print_map();
				number_of_turns++; //keep track of number of turns
				loop_control = check_forWinner(map, number_of_turns); //check for winner function that returns the loop control varable
			}
			catch (int x)
			{
				cout << "ERROR: " << x << " Invalid row, out of bounds entry. Try again" << endl;
				//error printed in case out of bounds is an issue
			}
		}
		else {
			// this portion takes user input and decrements the values to make sure the array starts at [0][0]
			// we know to the program the first element is 0,0 yet for the user its 1,1 
			cout << "\nX's turn\n";
			cout << "Pick a row (1, 2, 3): ";
			cin >> row;
			cout << "Pick a column (1, 2, 3): ";
			cin >> column;
			cout << endl;
			row--;
			column--;
			try {
				//try statement to catch a possible out of bounds access on the arrray
				if (row >= 3 || column >= 3) {
					throw 9999;
				}
				if (map[row][column] == 'O' || map[row][column] == 'X') { //if the row is already taken do this
					cout << "Invalid row. Try again" << endl;
					continue;
				}
				map[row][column] = 'X';
				whos_turn++; //increase value to change control to X or O
				print_map();
				number_of_turns++;  //keep track of number of turns
				loop_control = check_forWinner(map, number_of_turns); //check for winner function that returns the loop control varable
			}
			catch (int x)
			{
				cout << "ERROR: " << x << " Invalid row, out of bounds entry. Try again" << endl;
				//error printed in case out of bounds is an issue
			}

		}
	}
	cout << "\nGame over!\n\n";
	//end of the program 
	return 0;
}

//FUNCTION DEFINITIONS 

//This function prints the matrix map onto the console
void print_map() {
	
	for (int i = 0; i < 3; i++) {
		cout << "+---+---+---+" << endl;
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout << map[i][j] << " | ";
		}
		cout << endl;
	}
	cout << "+---+---+---+" << endl;

}

//this function checks for the winner on the array based on all the different coordinates of the matrix 
//returns true to finding a winner. the true statement will break the loop in the main section of the program
//I know this is not the most efficient way but due to time constraint this portion of the program will fulfill the requirements
bool check_forWinner(array<array<char, 3>, 3> map, int number_of_turns) {
	//Check for X as a winner
	if (map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[0][0] == 'X' && map[1][0] == 'X' && map[2][0] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[0][1] == 'X' && map[1][1] == 'X' && map[2][1] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[0][2] == 'X' && map[1][2] == 'X' && map[2][2] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}
	else if (map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X')
	{
		cout << "\nX wins!\n";
		return true;
	}//Check for O in any possible winning scenario
	if (map[0][0] == 'O' && map[0][1] == 'O' && map[0][2] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[0][0] == 'O' && map[1][0] == 'O' && map[2][0] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[0][1] == 'O' && map[1][1] == 'O' && map[2][1] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[0][2] == 'O' && map[1][2] == 'O' && map[2][2] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[1][0] == 'O' && map[1][1] == 'O' && map[1][2] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[2][0] == 'O' && map[2][1] == 'O' && map[2][2] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O')
	{
		cout << "\nO wins!\n";
		return true;
	}
	else if (number_of_turns == 10) {
		cout << "\nIts a tie.\n";
		return true;
	}
	else
		return false;
	//return false if none of the above is true to continue to play the game
}

