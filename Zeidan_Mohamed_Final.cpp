#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

//function prototypes
void fillBoard(char board[3][3]);
void displayBoard(char board[3][3]);
char playerWin(char board[3][3]);
bool playerTie(char board[3][3]);

struct Player
{
	string name;
	char xo;
	int lose = 0;
	int win = 0;
	int tie = 0;
};

int main()
{
	//create the two players
	Player player1, player2;
	Player tom;
	tom.xo = 'o';
	tom.name = "Tom";
	string name1;
	string name2;
	char choice = 'x';
	char board[3][3];
	int row, col;
	char win;
	int selection = 0;
	int startChoice = 1;
	char playAgain = 0;
	char continueDecision;
	int firstStart;
	int playersChoice;

	cout << "Welcome to the first ever Tic Tac Toe game!\n\n";

	cout << "1. Play with 2 players,\n";
	cout << "2. Play against a bot.\n";
	cin >> playersChoice;

	if (playersChoice == 2)
	{
		cout << "\nEnter your name: ";
		cin.ignore();
		getline(cin, name1);
		player1.name = name1;
		cout << "\nHello " << name1 << ", you will be versing Tom the bot.\n";

		cout << "Please choose one of the options below.\n";
		cout << "1. Play game\n2. Show game stats\n3. Quit\n";
		cin >> startChoice;

		while (startChoice != 1 && startChoice != 2 && startChoice != 3)
		{
			cout << "Please choose a valid option: ";
			cin >> startChoice;
		}

		if (startChoice == 2)
		{
			//player 1
			cout << endl << player1.name;
			cout << "\n--------------\n";
			cout << setw(3) << fixed << "Wins: " << player1.win << endl;
			cout << setw(3) << fixed << "Losses: " << player1.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player1.tie << endl << endl;

			cout << "Tom" << endl;
			cout << "--------------\n";
			cout << setw(3) << fixed << "Wins: " << player2.win << endl;
			cout << setw(3) << fixed << "Losses: " << player2.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player2.tie << endl << endl;

			cout << "Would you like to start the game? (y or n): ";
			cin >> continueDecision;

			if (continueDecision == 'n' || continueDecision == 'N')
			{
				cout << "\nThat's too bad... Come again!\n\n";
				exit(0);
			}

			while (continueDecision != 'y' && continueDecision != 'Y' && continueDecision != 'n' && continueDecision != 'N')
			{
				cout << "Please choose a valid option: ";
				cin >> continueDecision;
			}
		}

		else if (startChoice == 3)
		{
			cout << "\nThat's too bad... Come again!\n\n";
			exit(0);
		}

		if (startChoice == 1 || continueDecision == 'y' || continueDecision == 'Y')
		{
			//Display what symbol is picked
			cout << endl << player1.name << ", which character would you like to be your symbol? Tom will use \"o\" as his symbol: ";
			cin >> choice;
			cin.ignore();

			while (choice == '*' || choice == 'o')
			{
				cout << "You cannot use that one. Pick another symbol: ";
				cin >> choice;
			}

		};

		player1.xo = choice;


		do
		{
			//call in the function to make the board a bunch of *
			fillBoard(board);

			//display the board
			displayBoard(board);

			//create a variable called turn and make it = player 1 for now
			Player turn = player1;

			//start the game


		pickSpot:

			if (turn.name == player1.name)
			{
				cout << endl << player1.name << " (" << player1.xo << "), it's your turn. (row# column#): ";
				cin >> row;
				cin >> col;

				board[row - 1][col - 1] = player1.xo;

			}

			else if (turn.name == "Tom")
			{
				//first row
				if (board[0][1] == board[0][2] && board[0][0] == '*')
					board[0][0] = tom.xo;
				else if (board[0][0] == board[0][2] && board[0][1] == '*')
					board[0][1] = tom.xo;
				else if (board[0][0] == board[0][1] && board[0][2] == '*')
					board[0][2] = tom.xo;

				//second row
				else if (board[1][1] == board[1][2] && board[1][0] == '*')
					board[1][0] = tom.xo;
				else if (board[1][0] == board[1][2] && board[1][1] == '*')
					board[1][1] = tom.xo;
				else if (board[1][0] == board[1][1] && board[1][2] == '*')
					board[1][2] = tom.xo;

				//third row
				else if (board[2][1] == board[2][2] && board[2][0] == '*')
					board[2][0] = tom.xo;
				else if (board[2][0] == board[2][2] && board[2][1] == '*')
					board[2][1] = tom.xo;
				else if (board[2][0] == board[2][1] && board[2][2] == '*')
					board[2][2] = tom.xo;

				//vertical
				//first col
				else if (board[1][0] == board[2][0] && board[0][0] == '*')
					board[0][0] = tom.xo;
				else if (board[0][0] == board[2][0] && board[1][0] == '*')
					board[1][0] = tom.xo;
				else if (board[0][0] == board[1][0] && board[2][0] == '*')
					board[2][0] = tom.xo;

				//second col
				else if (board[1][1] == board[2][1] && board[0][1] == '*')
					board[0][1] = tom.xo;
				else if (board[0][1] == board[2][1] && board[1][1] == '*')
					board[1][1] = tom.xo;
				else if (board[0][1] == board[1][1] && board[2][1] == '*')
					board[2][1] = tom.xo;

				//third col
				else if (board[1][2] == board[2][2] && board[0][2] == '*')
					board[0][2] = tom.xo;
				else if (board[0][2] == board[2][2] && board[1][2] == '*')
					board[1][2] = tom.xo;
				else if (board[0][2] == board[1][2] && board[2][2] == '*')
					board[2][2] = tom.xo;

				//diagnol 
				else if (board[1][1] == board[2][2] && board[0][0] == '*')
					board[0][0] = tom.xo;
				else if (board[0][0] == board[2][2] && board[1][1] == '*')
					board[1][1] = tom.xo;
				else if (board[0][0] == board[1][1] && board[2][2] == '*')
					board[2][2] = tom.xo;

				//second diagnol
				else if (board[1][1] == board[0][2] && board[2][0] == '*')
					board[2][0] = tom.xo;
				else if (board[2][0] == board[0][2] && board[1][1] == '*')
					board[1][1] = tom.xo;
				else if (board[2][0] == board[1][1] && board[0][2] == '*')
					board[0][2] = tom.xo;

				//if no win, pick mid
				else if (board[1][1] == '*')
					board[1][1] = tom.xo;

				cout << "\nTom has chosen\n";
			}


			//re-display the new board with the new choice
			displayBoard(board);
			cout << endl;

			//check for win
			win = playerWin(board);

			if (win != '*')
			{
				if (win == player1.xo)
				{
					cout << "Congratulations " << player1.name << ", you have won!\n";

					//record the result on a table
					player1.win += 1;
					tom.lose += 1;

					break;
				}
				else if (playerTie(board))
				{
					cout << "Uh oh... It's a tie!\n";

					//record the result on a table
					tom.win += 1;

					break;
				}
				else
				{
					cout << "Tom has beaten you!\n";

					//record the result on a table
					tom.win += 1;
					player1.lose += 1;

					break;
				}
			}

			//check for tie
			else if (playerTie(board))
			{
				cout << "Uh oh... It's a tie!\n";

				//record the result on a table
				player1.tie += 1;
				tom.tie += 1;

				break;
			}

			//if its not a tie win or loss, then continue the game
			else
			{
				if (turn.name == player1.name)
					turn = tom;

				else
					turn = player1;
				goto pickSpot;
			}
			cout << turn.name;

			if (board[row - 1][col - 1] != '*')
			{
				cout << "This spot has already been picked or is invalid!" << endl;
				goto pickSpot;
			}
			else board[row][col] = turn.xo;

			//output the results after game
			cout << endl << player1.name;
			cout << "\n--------------\n";
			cout << setw(3) << fixed << "Wins: " << player1.win << endl;
			cout << setw(3) << fixed << "Losses: " << player1.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player1.tie << endl << endl;

			cout << "Tom" << endl;
			cout << "--------------\n";
			cout << setw(3) << fixed << "Wins: " << player2.win << endl;
			cout << setw(3) << fixed << "Losses: " << player2.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player2.tie << endl << endl;

			cout << "Would you like to start the game? (y or n): ";
			cin >> playAgain;

			if (playAgain == 'n' || playAgain == 'N')
			{
				cout << "\nThat's too bad... Come again!\n\n";
				exit(0);
			}

			while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
			{
				cout << "Please choose a valid option: ";
				cin >> playAgain;
			}

			//this clears the screem and restarts
			//This clears the screen and restarts
			if (selection == 2)
			{
				//player 1
				cout << endl << player1.name << endl;
				cout << "--------------\n";
				cout << setw(3) << fixed << "Wins: " << player1.win << endl;
				cout << setw(3) << fixed << "Losses: " << player1.lose << endl;
				cout << setw(3) << fixed << "Ties: " << player1.tie << endl << endl;

				cout << "Tom" << endl;
				cout << "--------------\n";
				cout << setw(3) << fixed << "Wins: " << player2.win << endl;
				cout << setw(3) << fixed << "Losses: " << player2.lose << endl;
				cout << setw(3) << fixed << "Ties: " << player2.tie << endl << endl;

				cout << "Would you like to play again? (y or n)";
				cin >> continueDecision;

				if (continueDecision != 'y' && continueDecision != 'Y' && continueDecision != 'N' && continueDecision != 'n')
				{
					cout << "Please choose a valid option: ";
					cin >> continueDecision;

					if (continueDecision == 'n' || continueDecision == 'N')
					{
						cout << "That's too bad... Come again!";
						exit(0);
					}
				}
			}

			else if (playAgain == 'y' || playAgain == 'Y')
			{
				system("CLS");
			}

			else if (playAgain == 'n' || playAgain == 'N')
			{
				cout << "\nThat's too bad... Come again!\n\n";
				exit(0);
			}
		} while (playAgain != 'n' || playAgain != 'N');
	}

	//-----------------------------------------------------------------------------------

	if (playersChoice == 1)
	{
		cout << "\nEnter the name for player 1: ";
		cin.ignore();
		getline(cin, name1);
		player1.name = name1;
		cout << endl << "Enter the name for player 2: ";
		getline(cin, name2);
		player2.name = name2;


		cout << "\nPlease choose one of the options below.\n";
		cout << "1. Play game\n2. Show game stats\n3. Quit\n";
		cin >> startChoice;

		while (startChoice != 1 && startChoice != 2 && startChoice != 3)
		{
			cout << "Please choose a valid option: ";
			cin >> startChoice;
		}

		if (startChoice == 2)
		{
			//player 1
			cout << endl << player1.name;
			cout << "\n--------------\n";
			cout << setw(3) << fixed << "Wins: " << player1.win << endl;
			cout << setw(3) << fixed << "Losses: " << player1.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player1.tie << endl << endl;

			cout << player2.name << endl;
			cout << "--------------\n";
			cout << setw(3) << fixed << "Wins: " << player2.win << endl;
			cout << setw(3) << fixed << "Losses: " << player2.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player2.tie << endl << endl;

			cout << "Would you like to start the game? (y or n): ";
			cin >> continueDecision;

			if (continueDecision == 'n' || continueDecision == 'N')
			{
				cout << "\nThat's too bad... Come again!\n\n";
				exit(0);
			}



			while (continueDecision != 'n' && continueDecision != 'N' && continueDecision != 'y' && continueDecision != 'Y')
			{
				cout << "Please choose a valid option: ";
				cin >> continueDecision;

				if (continueDecision == 'n' || continueDecision == 'N')
				{
					cout << "\nThat's too bad... Come again!\n\n";
					exit(0);
				}
			}
		}

		else if (startChoice == 3)
		{
			cout << "\nThat's too bad... Come again!\n\n";
			exit(0);
		}

		while (startChoice == 1 || continueDecision == 'y' || continueDecision == 'Y')
		{
			//Display what symbol is picked
			cout << endl << player1.name << ", which character would you like to be your symbol?: ";
			cin >> choice;
			cin.ignore();

			while (choice == '*')
			{
				cout << "You cannot use that one. Pick another symbol: ";
				cin >> choice;
			}

			break;
		} while (choice == '*' || choice == player1.xo);

		//player1.name = name;
		player1.xo = choice;

		while (startChoice == 1 || continueDecision == 'y' || continueDecision == 'Y')
		{
			cout << endl << player2.name << ", which character would you like to be your symbol?: ";
			cin >> choice;
			cin.ignore();

			while (choice == '*' || choice == player1.xo)
			{
				cout << "You cannot use that one. Pick another symbol: ";
				cin >> choice;
			}

			break;
		} while (choice == '*' || choice == player1.xo);

		player2.xo = choice;

		do
		{
			//call in the function to make the board a bunch of *
			fillBoard(board);

			//display the board
			displayBoard(board);

			srand(time(NULL));

			startChoice = rand() % 2;


			//create a variable called turn and make it = player 1 for now
			Player turn = player1;

			//start the game
			while (true)
			{

			pickSpot1:

				cout << endl << turn.name << ", it's your turn. (row# column#): ";
				cin >> row;
				cin >> col;

				//When they put in a value, it goes by 1,2,3 rather than 0,1,2
				row -= 1; col -= 1;

				if (board[row][col] != '*')
				{
					cout << "This spot has already been picked or is invalid!" << endl;
					goto pickSpot1;
				}
				else board[row][col] = turn.xo;

				//re-display the new board with the new choice
				displayBoard(board);
				cout << endl;

				//check for win
				win = playerWin(board);

				if (win != '*')
				{
					if (win == player1.xo)
					{
						cout << "Congratulations " << player1.name << ", you have won!\n";

						//record the result on a table
						player1.win += 1;
						player2.lose += 1;

						break;
					}
					else
					{
						cout << "Congratulations " << player2.name << ", you have won!\n";

						//record the result on a table
						player2.win += 1;
						player1.lose += 1;

						break;
					}
				}

				//check for a tie
				else if (playerTie(board))
				{
					cout << "Uh oh... It's a tie!\n";

					//record the result on a table
					player1.tie += 1;
					player2.tie += 1;

					break;
				}

				//if its not tie win or loss, then continue the game 
				else
				{
					if (turn.name == player1.name)
						turn = player2;

					else
						turn = player1;
				}
			}

			//Output the results after game
			cout << endl << player1.name << endl;
			cout << "--------------\n";
			cout << setw(3) << fixed << "Wins: " << player1.win << endl;
			cout << setw(3) << fixed << "Losses: " << player1.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player1.tie << endl << endl;

			cout << player2.name << endl;
			cout << "--------------\n";
			cout << setw(3) << fixed << "Wins: " << player2.win << endl;
			cout << setw(3) << fixed << "Losses: " << player2.lose << endl;
			cout << setw(3) << fixed << "Ties: " << player2.tie << endl << endl;

			cout << "Would you like to play again? (y or n): ";
			cin >> playAgain;

			while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'N' && playAgain != 'n')
			{
				cout << "Please choose a valid option: ";
				cin >> playAgain;
			}

			//This shows the game scores
			if (selection == 2)
			{
				//player 1
				cout << endl << player1.name << endl;
				cout << "--------------\n";
				cout << setw(3) << fixed << "Wins: " << player1.win << endl;
				cout << setw(3) << fixed << "Losses: " << player1.lose << endl;
				cout << setw(3) << fixed << "Ties: " << player1.tie << endl << endl;

				cout << "Tom" << endl;
				cout << "--------------\n";
				cout << setw(3) << fixed << "Wins: " << player2.win << endl;
				cout << setw(3) << fixed << "Losses: " << player2.lose << endl;
				cout << setw(3) << fixed << "Ties: " << player2.tie << endl << endl;

				cout << "Would you like to play again? (y or n)";
				cin >> continueDecision;

				if (continueDecision != 'y' && continueDecision != 'Y' && continueDecision != 'N' && continueDecision != 'n')
				{
					cout << "Please choose a valid option: ";
					cin >> continueDecision;
				}
			}

			//This clears the screen and restarts
			else if (playAgain == 'y' || playAgain == 'Y')
			{
				system("CLS");
			}

			else if (playAgain == 'n' || playAgain == 'N')
			{
				cout << "\nThat's too bad... Come again!\n\n";
				exit(0);
			}

		} while (playAgain != 'n' || playAgain != 'N');
	}
}

//First, fill the tictactoe board with symbols and then display the board
void fillBoard(char board[3][3])
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = '*';
		}
	}
}

void displayBoard(char board[3][3])
{
	cout << endl;

	cout << " |  1|  2|  3|\n";
	for (int x = 0; x < 3; x++)
	{
		cout << "--------------\n";
		cout << (x + 1) << "|";
		for (int y = 0; y < 3; y++)
		{
			cout << setw(3) << right;
			cout << board[x][y] << "|";
		}
		cout << endl;
	}
}

//Now, create function for if the player has won
char playerWin(char board[3][3])
{
	//check rows if all 3 are same and not empty
	for (int x = 0; x < 3; x++)
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][0] != '*')
			return board[x][0];
	}

	//chk columns if all 3 are same and not empty
	for (int y = 0; y < 3; y++)
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[0][y] != '*')
			return board[0][y];
	}

	//chk diagnol on left
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '*')
		return board[0][0];

	//chk second diagnol on left --> /
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '*')
		return board[0][2];

	//no one wins
	return '*';
}

//create function for if the player ties
//to check if game is a tie, must use bool
bool playerTie(char board[3][3])
{
	//a tie only happens when all the positions are filled
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			if (board[x][y] == '*')
				return false;

	return true;
}
