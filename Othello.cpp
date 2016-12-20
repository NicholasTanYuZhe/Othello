/**********|**********|**********|
 Program: Othello.cpp Course: Bachelor Of Computer Science (Hons)
 Year: 2015/16 Trimester 1
 Name: Nicholas Tan Yu Zhe
 ID: 1142701655
 Email: nicholas.290696@gmail.com
 Phone: 016-7768182 **********|**********|**********/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;

void BoolContinue ( int& p, int& q, bool BoolP1, bool BoolP2, bool BoolQ1, bool BoolQ2, bool BoolP1Q1, bool BoolP1Q2, bool BoolP2Q1, bool BoolP2Q2 )
{
	if ( BoolP1 || BoolP1Q1 || BoolP1Q2 )
		p -= 1;
	else if ( BoolP2 || BoolP2Q1 || BoolP2Q2 )
		p += 1;
	if ( BoolQ1 || BoolP1Q1 || BoolP2Q1 )
		q -= 1;
	else if ( BoolQ2 || BoolP1Q2 || BoolP2Q2 )
		q += 1;
}

void BoolFalse ( int& p, int& q, bool BoolP1, bool BoolP2, bool BoolQ1, bool BoolQ2, bool BoolP1Q1, bool BoolP1Q2, bool BoolP2Q1, bool BoolP2Q2 )
{
	if ( BoolP1 || BoolP1Q1 || BoolP1Q2 )
		p = 0;
	else if ( BoolP2 || BoolP2Q1 || BoolP2Q2 )
		p = 9;
	if ( BoolQ1 || BoolP1Q1 || BoolP2Q1 )
		q = 0;
	else if ( BoolQ2 || BoolP1Q2 || BoolP2Q2 )
		q = 9;
}

void BoolChecking ( int p, int q, bool& BoolP1, bool& BoolP2, bool& BoolQ1, bool& BoolQ2, bool& BoolP1Q1, bool& BoolP1Q2, bool& BoolP2Q1, bool& BoolP2Q2 )
{
	if ( p == 0 )
	{
		BoolP1 = false;
		BoolP1Q1 = false;
		BoolP1Q2 = false;
	}
	else if ( p == 9 )
	{
		BoolP2 = false;
		BoolP2Q1 = false;
		BoolP2Q2 = false;
	}
	if ( q == 0 )
	{
		BoolQ1 = false;
		BoolP1Q1 = false;
		BoolP2Q1 = false;
	}
	else if ( q == 9 )
	{
		BoolQ2 = false;
		BoolP1Q2 = false;
		BoolP2Q2 = false;
	}
}

void Direction ( char Board[9][9], int i, int j, int Indicator, int Flipping, string C_Player )
{
	int p, q, y, D_Counter = 0;
	char a = 'O', b = 'X';
	while ( D_Counter < 8 )
	{
		bool BoolP1 = false, BoolP2 = false, BoolQ1 = false, BoolQ2 = false, BoolP1Q1 = false, BoolP1Q2 = false, BoolP2Q1 = false, BoolP2Q2 = false;
		if ( Flipping == 1 )
			y = 1;
		if ( Indicator == 1 )
			y = 2;
		if ( C_Player == "X" )
		{
			a = 'X';
			b = 'O';
		}
		switch ( D_Counter )
		{
			// up
			case 0:	p = i - 1;
						q = j;
						if ( p > 0 )
							BoolP1 = true;
						break;
			// down
			case 1:	p = i + 1;
						q = j;
						if ( p < 9 )
							BoolP2 = true;
						break;
			// left
			case 2:	p = i;
						q = j - 1;
						if ( q > 0 )
							BoolQ1 = true;
						break;
			// right
			case 3:	p = i;
						q = j + 1;
						if ( q < 9 )
							BoolQ2 = true;
						break;
			// top left
			case 4:	p = i - 1;
						q = j - 1;
						if ( p > 0 && q > 0 )
							BoolP1Q1 = true;
						break;
			// top right
			case 5:	p = i - 1;
						q = j + 1;
						if ( p > 0 && q < 9 )
							BoolP1Q2 = true;
						break;
			// bottom left
			case 6:	p = i + 1;
						q = j - 1;
						if ( p < 9 && q > 0 )
							BoolP2Q1 = true;
						break;
			// bottom right
			case 7:	p = i + 1;
						q = j + 1;
						if ( p < 9 && q < 9 )
							BoolP2Q2 = true;
						break;
		}
		if ( ( BoolP1 || BoolP2 || BoolQ1 || BoolQ2 || BoolP1Q1 || BoolP1Q2 || BoolP2Q1 || BoolP2Q2 ) && Board[p][q] == b )
		{
			BoolContinue ( p, q, BoolP1, BoolP2, BoolQ1, BoolQ2, BoolP1Q1, BoolP1Q2, BoolP2Q1, BoolP2Q2 ); // To plus or minus to the corresponding side of the directions
			BoolChecking ( p, q, BoolP1, BoolP2, BoolQ1, BoolQ2, BoolP1Q1, BoolP1Q2, BoolP2Q1, BoolP2Q2 ); // To check whether the p or q have over the side of the board
			while ( BoolP1 || BoolP2 || BoolQ1 || BoolQ2 || BoolP1Q1 || BoolP1Q2 || BoolP2Q1 || BoolP2Q2 )
			{
				if ( Board[p][q] == ' ' || Board[p][q] == '*' )
					BoolFalse ( p, q, BoolP1, BoolP2, BoolQ1, BoolQ2, BoolP1Q1, BoolP1Q2, BoolP2Q1, BoolP2Q2 ); // To quit the loop
				else if ( Board[p][q] == b )
				{
					BoolContinue ( p, q, BoolP1, BoolP2, BoolQ1, BoolQ2, BoolP1Q1, BoolP1Q2, BoolP2Q1, BoolP2Q2 );
					y += 1;
				}
				else if ( Board[p][q] == a )
				{
					while ( y > 0 )
					{
						if ( BoolP1 || BoolP1Q1 || BoolP1Q2 )
							p += 1;
						else if ( BoolP2 || BoolP2Q1 || BoolP2Q2 )
							p -= 1;
						if ( BoolQ1 || BoolP1Q1 || BoolP2Q1 )
							q += 1;
						else if ( BoolQ2 || BoolP1Q2 || BoolP2Q2 )
							q -= 1;
						y -= 1;
						if ( Flipping == 1 )
							Board[p][q] = a;
					}
					if ( Indicator == 1 )
						Board[p][q] = '*';
					BoolFalse ( p, q, BoolP1, BoolP2, BoolQ1, BoolQ2, BoolP1Q1, BoolP1Q2, BoolP2Q1, BoolP2Q2 );
				}
				BoolChecking ( p, q, BoolP1, BoolP2, BoolQ1, BoolQ2, BoolP1Q1, BoolP1Q2, BoolP2Q1, BoolP2Q2 );
			}
		}
		D_Counter += 1;
	}
}

void ClearIndicator ( char Board[9][9] )
{
	for ( int i = 1; i < 9; i++ )
		for ( int j = 1; j < 9; j++ )
			if ( Board[i][j] == '*' )
				Board[i][j] = ' ';
}

void CheckSide ( int Round, string& C_Player )
{
	int Player = ( Round % 2 );
	if ( Player == 0 )
		C_Player = "O";
	else if ( Player == 1 )
		C_Player = "X";
}

void Super1 ( char Board[9][9], int& Round, int& Error )
{
	for ( int i = 1; i < 9; i++ )
		for ( int j = 1; j < 9; j++ )
			if ( Board[i][j] == 'O' ) // To calculate the number of 'O' in the board
				Board[i][j] = 'X';
			else if ( Board[i][j] == 'X' ) // To calculate the number of 'X' in the board
				Board[i][j] = 'O';
	Round += 1;
	Error = 1;
}

void Super23 ( string& Command, int& Input )
{
	Input = 1;
	cout << "Please type in a coordinate you wish to place your marker." << endl;
	cout << "==> ";
	getline( cin, Command );
}

int main ()
{
    // Initialize variables
	int A_Counter, Continue = 0, Error, Error_1, Error_2, Flipping, Indicator, Input, i, j, k, m, O_Score, Round, V_Counter, X_Score;
	int O_Super1, O_Super2, O_TSuper2, O_Super3, O_TSuper3, X_Super1, X_Super2, X_Super3, X_TSuper2, X_TSuper3;
    string Command, C_Player, Selection = "0", Victory;
    char Board[9][9], n, z;
	bool C_Victory;
    
    // Return to selection list
    while ( Selection == "0" )
    {
		if ( Continue == 0 ) // To check whether is the player want to continue from the last game
		{
			// Start banner
			cout << "|---------------------------------------------------------------------------|" << endl;
			cout << "|                                                                           |" << endl;
			cout << "|                                  OTHELLO                                  |" << endl;
			cout << "|                                                                           |" << endl;
			cout << "|---------------------------------------------------------------------------|" << endl << endl;
			
			// Selection list
			cout << "Please choose the following list:" << endl << endl;
			cout << "1. New Game" << endl;
			cout << "2. Load Game" << endl;
			cout << "3. Help" << endl;
			cout << "4. Quit" << endl;
			cout << "==> ";
			getline( cin, Selection );
			cout << endl;
			
			// Test for invalid input
			if ( Selection != "1" && Selection != "2" && Selection != "3" && Selection != "4" )
			{
				cout << "You have type in an invalid input." << endl;
				system("pause"); // system("pause") is for Windows and system("read") is for Macintosh
				Selection = "0";
				cout << endl << endl;
			}
		}
		else
		{
			Continue = 0;
			Selection = "1";
		}
		
        // If statement for the selection list
        if ( Selection == "4" ) // Selection for Quit
            return 0;
        if ( Selection == "3" ) // Selection for Help
        {
			cout << "                               Introduction" << endl << endl;
            cout << "1. Othello is a board game played on an 8x8 board using pieces that are O on one" << endl;
            cout << "   side and X on the other." << endl;
            cout << "2. Player with X side will move first." << endl;
            cout << "3. Players will take turns to place the pieces on the board with their side." << endl;
            cout << "4. Player will capture their opponent side by making the opponent side in between" << endl;
            cout << "   the player's side." << endl;
            cout << "5. The game ends when neither player has a possible move." << endl;
            cout << "6. The player who has the most side is the winner!" << endl << endl;
			cout << "                               Gameplay" << endl << endl;
			cout << "1. Player can only place their marker on the * indicator on the board." << endl; 
			cout << "2. When the program is started, player can type in menu to go back to the menu" << endl; 
			cout << "   selection." << endl;
			cout << "3. Player can also type in save a.txt to save the program to the file name a.txt." << endl;
			cout << "4. When player type in next player, it will skip the turn of the player and pass" << endl;
			cout << "   the round to the opponent." << endl;
			cout << "5. Player can place a coordinate for example f 4." << endl;
			cout << "   Player can input from a - h and 8 - 1." << endl;
			cout << "6. Player can type in super1, super2 or super3 to use the super power for" << endl;
			cout << "   only one time." << endl;
			cout << "7. super1 is the ability to switch all the X markers to O markers and" << endl;
			cout << "   O markers to X markers." << endl;
			cout << "8. super2 is the ability to simply place a marker without any restriction." << endl;
			cout << "9. super3 is the ability to place 2 markers consecutively on the board but" << endl;
			cout << "   this superpower can only use after the third round which mean at least" << endl;
			cout << "   player and the opponent have place a marker on the board before both" << endl;
			cout << "   of them can use super3." << endl << endl;
            Selection = "0";
            system("pause"); // system("pause") is for Windows and system("read") is for Macintosh
            cout << endl << endl;
        }
		if ( Selection == "2" ) // Selection for Load Game
		{
			ifstream loadfile( "a.txt" ); // Save the file to a.txt
			if ( loadfile.good() ) // Check does the file exist or not
			{
				for ( i = 1; i < 9; i++ ) // Loop to read the file to array
					for ( j = 1; j < 9; j++ )
						loadfile.get(Board[i][j]);
				loadfile >> Round; // Reading the file to variable Round
				loadfile >> O_Super1; // Reading the file to variable O_Super1
				loadfile >> O_Super2; // Reading the file to variable O_Super2
				loadfile >> O_TSuper2; // Reading the file to variable O_TSuper2
				loadfile >> O_Super3; // Reading the file to variable O_Super3
				loadfile >> O_TSuper3; // Reading the file to variable O_TSuper3
				loadfile >> X_Super1; // Reading the file to variable X_Super1
				loadfile >> X_Super2; // Reading the file to variable X_Super2
				loadfile >> X_TSuper2; // Reading the file to variable X_Tuper2
				loadfile >> X_Super3; // Reading the file to variable X_Super3
				loadfile >> X_TSuper3; // Reading the file to variable X_TSuper3
				loadfile.close();
				cout << "Game successfully loaded. Please enjoy!" << endl;
				system("pause");
				Selection = "5";
			}
			else
			{
				cout << "File does not exist!" << endl;
				cout << "Please make sure the a.txt file is located with this program." << endl;
				system("pause");
				Selection = "0";
			}
		}
		if ( Selection == "1" ) // Selection for New Game
        {
			O_Super1 = 0; // To initialize the super power variables
			O_Super2 = 0;
			O_Super3 = 0;
			X_Super1 = 0;
			X_Super2 = 0;
			X_Super3 = 0;
			O_TSuper2 = 0;
			X_TSuper2 = 0;
			O_TSuper3 = 0;
			X_TSuper3 = 0;
			// Initialize the board
			for ( i = 1; i < 9; i ++ )
				for ( j = 1; j < 9; j++ )
					Board[i][j] = ' ';
            // Setting up the initial placement of sides
            Board[4][4] = 'O';
            Board[4][5] = 'X';
            Board[5][4] = 'X';
            Board[5][5] = 'O';
			Round = 1;
			C_Victory = false;
			Selection = "5";
        }
		if ( Selection == "5" ) // Selection for Start Game
		{
            //Looping part of the game
            while ( Round > 0 )
            {
				// Clear the * indicator on the board
				ClearIndicator ( Board );
				// Initialize variable score and calculate scoreboard
				O_Score = 0;
				X_Score = 0;
				for ( i = 1; i < 9; i++ )
					for ( j = 1; j < 9; j++ )
						if ( Board[i][j] == 'O' ) // To calculate the number of 'O' in the board
							O_Score += 1;
						else if ( Board[i][j] == 'X' ) // To calculate the number of 'X' in the board
							X_Score += 1;
				
				// To know whether the current round is which side's turn
				CheckSide ( Round, C_Player );
				Indicator = 1;
				for ( i = 1; i < 9; i++ )
					for ( j = 1; j < 9; j++ )
						if ( Board[i][j] == ' ' ) // Only scan for black spaces on the board
							Direction ( Board, i, j, Indicator, Flipping, C_Player ); // To place indicator on the board for user to place the marker
				Indicator = 0;
				Error = 0;
				while ( Error == 0 ) // To check whether the both input of (p,q) are valid input
				{
					cout << "    a   b   c   d   e   f   g   h" << endl;
					k = 8;
					for ( i = 1; i < 9; i++ ) // Set the number of row
					{
						cout << "  |";
						for ( j = 1; j < 9; j++ ) // Set the number of '---+'
						{
							if ( j < 8 )
								cout << "---+";
							else if ( j == 8 ) // Set the last column as '---|'
								cout << "---|";
						}
						cout << endl;
						cout << k << " |"; // variable k is for the side of the board numbering
						for ( j = 1; j < 9; j++ ) // Set the number of '   |'
							cout << " " << Board[i][j] << " |";
						cout << " " << k;
						cout << endl;
						k -= 1;
					}
					cout << "  |";
					for ( j = 1; j < 9; j++ ) // Set for the last line of the board
					{
						if ( j < 8 )
							cout << "---+";
						else if ( j == 8 )
							cout << "---|";
					}
					cout << endl;
					cout << "    a   b   c   d   e   f   g   h" << endl << endl;
					cout << "Score : O = " << O_Score << "   X = " << X_Score << endl;
					// Check for victory
					k = 0;
					for ( i = 1; i < 9; i++ )
						for ( j = 1; j < 9; j++ )
							if ( Board[i][j] == '*' )
								k += 1;
					if ( k == 0 )
					{
						ClearIndicator ( Board ); // To clear indicator in the board
						Round += 1;
						CheckSide ( Round, C_Player ); // To check which turn are the player now
						Indicator = 1;
						for ( i = 1; i < 9; i++ )
							for ( j = 1; j < 9; j++ )
								if ( Board[i][j] == ' ' ) // Only scan for black spaces on the board
									Direction ( Board, i, j, Indicator, Flipping, C_Player ); // To place indicator on the board for user to place the marker
						Indicator = 0;
						k = 0;
						for ( i = 1; i < 9; i++ )
							for ( j = 1; j < 9; j++ )
								if ( Board[i][j] == '*' )
									k += 1;
						ClearIndicator ( Board );
						Round -= 1;
						CheckSide ( Round, C_Player );
						if ( k == 0 )
							C_Victory = true; // To go straight to victory part
						else
						{
							cout << "Current Player : " << C_Player << endl << endl;
							cout << "You can only key in next player as you do not have any move left." << endl;
							cout << "==> ";
							getline( cin, Command );
							if ( Command == "next player" )
							{
								Round += 1;
								Error = 1;
							}
							else
							{
								cout << "Please type in next player to pass the round to opponent." << endl;
								system("pause");
							}
						}
					}
					else
					{
						cout << "Current Player : " << C_Player << endl << endl;
						cout << "Please type in the number of your selection or the coordinate." << endl;
						cout << "|--------------------------------------|" << endl;
						cout << "| next player     menu      save a.txt |" << endl;
						cout << "| super1     super2     super3     f 4 |" << endl;
						cout << "|--------------------------------------|" << endl;
						cout << "==> ";
						getline( cin, Command ); // To get the input from the user
						Input = 1; // To go in the Error checking part
						
						if ( Command == "next player" )
						{
							Round += 1;
							Error = 1;
							Input = 0;
							cout << endl;
						}
						else if ( Command == "menu" )
						{
							Selection = "0";
							Round = 0;
							Error = 1;
							Input = 0;
							cout << endl;
						}
						else if ( Command == "save a.txt" )
						{
							ofstream savefile( "a.txt" ); // Save the game to a.txt file
							for ( i = 1; i < 9; i++ ) // Loop to save value of array to file
								for ( j = 1; j < 9; j++ )
									savefile << Board[i][j];
							savefile << "\n" << Round; // Save the variable Round to file
							savefile << "\n" << O_Super1; // Save the variable O_Super1 to file
							savefile << "\n" << O_Super2; // Save the variable O_Super2 to file
							savefile << "\n" << O_TSuper2; // Save the variable O_TSuper2 to file
							savefile << "\n" << O_Super3; // Save the variable O_Super3 to file
							savefile << "\n" << O_TSuper3; // Save the variable O_TSuper3 to file
							savefile << "\n" << X_Super1; // Save the variable X_Super1 to file
							savefile << "\n" << X_Super2; // Save the variable X_Super2 to file
							savefile << "\n" << X_TSuper2; // Save the variable X_TSuper2 to file
							savefile << "\n" << X_Super3; // Save the variable X_Super3 to file
							savefile << "\n" << X_TSuper3; // Save the variable X_TSuper3 to file
							savefile.close();
							cout << endl << "Game saved to a.txt!" << endl;
							Input = 0;
							system("pause");
							cout << endl;
						}
						else if ( Command == "super1" )
						{
							if ( C_Player == "O" )
							{
								if ( O_Super1 == 0 )
								{
									O_Super1 = 1;
									Super1 ( Board, Round, Error );
								}
								else
								{
									cout << "You have already used super1." << endl;
									system("pause");
								}
							}
							else
							{
								if ( X_Super1 == 0 )
								{
									X_Super1 = 1;
									Super1 ( Board, Round, Error );
								}
								else
								{
									cout << "You have already used super1." << endl;
									system("pause");
								}
							}
							Input = 0;
						}
						else if ( Command == "super2" )
						{
							if ( C_Player == "O" )
							{
								if ( O_Super2 == 0 || O_TSuper2 != 0 )
								{
									O_Super2 = 1;
									O_TSuper2 = 1;
									Super23 ( Command, Input );
								}
								else
								{
									cout << "You have already used super2." << endl;
									system("pause");
									Input = 0;
								}
							}
							else
							{
								if ( X_Super2 == 0 || X_TSuper2 != 0 )
								{
									X_Super2 = 1;
									X_TSuper2 = 1;
									Super23 ( Command, Input );
								}
								else
								{
									cout << "You have already used super2." << endl;
									system("pause");
									Input = 0;
								}
							}
						}
						else if ( Command == "super3" )
						{
							if ( Round > 2 )
							{
								if ( C_Player == "O" )
								{
									if ( O_Super3 == 0 || O_TSuper3 != 0 )
									{
										O_Super3 = 1;
										O_TSuper3 = 1;
										Super23 ( Command, Input );
									}
									else
									{
										cout << "You have already used super3." << endl;
										system("pause");
										Input = 0;
									}
								}
								else
								{
									if ( X_Super3 == 0 || X_TSuper3 != 0 )
									{
										X_Super3 = 1;
										X_TSuper3 = 1;
										Super23 ( Command, Input );
									}
									else
									{
										cout << "You have already used super3." << endl;
										system("pause");
										Input = 0;
									}
								}
							}
							else
							{	
								cout << "This is just round " << Round << " and have not reach round 3. Thus, super3 is disable." << endl;
								system("pause");
								Input = 0;
							}
						}
						if ( Input == 1 )
						{
							// Int Error_1 and Error_2 to test invalid input
							Error_1 = 0;
							Error_2 = 0;
							n = 0;
							m = 0;
							cout << endl;
							
							// To split the coordinate of the user input
							istringstream ss( Command );
							ss >> n >> m;
							
							// Setting up alphabet loop and number of loop to change alphabet to number
							z = 'a';
							A_Counter = 1;
							j = 0;
							while ( j == 0 )
							{
								if ( A_Counter < 8 )
								{
									while ( z < 'i' )
									{
										if ( z == n )
										{
											z = 'i';
											j = A_Counter; // Convert the alphabet order to numerical order for the listing
											Error_1 = 1;
										}
										else
										{
											z += 1;
											A_Counter += 1;
										}
									}
								}
								else
									j = 1;
							}
							
							// To change the number to match array number
							i = 9 - m;
							
							// Test for valid input
							if ( i > 0 && i < 9 )
								Error_2 = 1;
							
							// Making sure both part of the input (p,q) are true
							if ( Error_1 == 1 && Error_2 == 1 )
							{
								if ( ( X_Super2 != 1 || X_TSuper2 != 1 ) && ( O_Super2 != 1 || O_TSuper2 != 1 ) )
								{
									// Test the coordinate have been used or not
									if ( Board[i][j] == 'X' || Board[i][j] == 'O' )
									{
										cout << "This coordinate has been used." << endl;
										system("pause");
										cout << endl;
									}
									else if ( Board[i][j] != '*' )
									{
										cout << "You can only place on * indicator." << endl;
										system("pause");
										cout << endl;
									}
									else
										Flipping = 1;
								}
								else
									Flipping = 1;
								if ( Flipping == 1 )
								{
									// Set the current side to the coordinate
									if ( ( X_Super3 == 1 && X_TSuper3 == 1 ) || ( O_Super3 == 1 && O_TSuper3 == 1 ) )
									{
										Round -= 1;
										O_TSuper3 = 0;
										X_TSuper3 = 0;
									}
									Round += 1;
									if ( C_Player == "X" )
										Board[i][j] = 'X';
									else
										Board[i][j] = 'O';
									// Test all 8 directions
									Direction ( Board, i, j, Indicator, Flipping, C_Player );
								}
								Flipping = 0;
								Error = 1;
								X_TSuper2 = 0;
								O_TSuper2 = 0;
							}
							else
							{
								cout << "Please type in a valid input." << endl;
								system("pause");
								cout << endl;
							}
						}
					}
					if ( C_Victory ) // To check whether it is victory or not
					{
						Round = 0;
						Error = 1;
						V_Counter = 1;
						if ( X_Score > O_Score )
						{
							cout << endl << "Victory! ";
							cout << "X side has won the game!" << endl;
							cout << "Congratulation to the winning side!" << endl;
						}
						else if ( O_Score > X_Score )
						{
							cout << endl << "Victory! ";
							cout << "O side has won the game!" << endl;
							cout << "Congratulation to the winning side!" << endl;
						}
						else
							cout << endl << "This game is a tie!" << endl;
						while ( V_Counter == 1 )
						{
							cout << "Do you still want to play the game? ( Y/N )" << endl;
							cout << "==> ";
							getline ( cin, Victory );
							if ( Victory == "Y" || Victory == "y" )
							{
								Continue = 1;
								V_Counter = 0;
							}
							else if ( Victory == "N" || Victory == "n" )
								V_Counter = 0;
						}
						Selection = "0";
					}
				}
			}
        }
    }
}