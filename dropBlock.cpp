#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int boardsize = 6;
const int rows = 10;
const int columns = 10;
char game[rows][columns] = {0};

void WelcomeMessage()
{
	// show welcome message
	cout << "________                        __________.__                 __       ________                       " << endl;
	cout << "\\______ \\_______  ____ ______   \\______   \\  |   ____   ____ |  | __  /  _____/_____    _____   ____  " << endl;
	cout << " |    |  \\_  __ \\/  _ \\\\____ \\   |    |  _/  |  /  _ \\_/ ___\\|  |/ / /   \\  ___\\__  \\  /     \\_/ __ \\ " << endl;
	cout << " |    `   \\  | \\(  <_> )  |_> >  |    |   \\  |_(  <_> )  \\___|    <  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ " << endl;
	cout << "/_______  /__|   \\____/|   __/   |______  /____/\\____/ \\___  >__|_ \\  \\______  (____  /__|_|  /\\___  >" << endl;
	cout << "        \\/             |__|             \\/                 \\/     \\/         \\/     \\/      \\/     \\/ " << endl;
	cout << endl;
	cout << setw(78) << " +-------------+ +---+ +-------+ +---------+ +-------+" << endl;
	cout << setw(78) << " |W e l c o m e| |t o| |D r o p| |B l o c k| |G a m e|" << endl;
	cout << setw(78) << " +-------------+ +---+ +-------+ +---------+ +-------+" << endl;
}


class board {
public:
	//function used for printing +------+
	void printrow() {
		cout << "  ";
		int count = 0;
		for (int i = 0; i < 2; i++) {
			cout << "+";
			if (count < 1) {
				for (int i = 0; i < (boardsize * 2 + 1); i++)
					cout << "-";
			}
			count++;
		}
		cout << endl;
	}
	void printArray() {
		printboard();
		printrow();
		for (int i = 0; i < boardsize; i++) {

			char k = 'A';
			k += i;
			cout << (char)k << " |";
			for (int j = 0; j < boardsize; j++) {
				cout << " " << (char)game[i][j];
			}
			cout << " |" << endl;
		}
		printrow();
		
	}
	void dropblocks(int a, char c) {
		for (int i = 0; i < boardsize; i++) {
			if (i == boardsize - 1)
			{
				game[i][a] = c;
				break;
			}
			if (game[i][a] == 0)
				continue;
			else if (game[i][a] != 0)
				game[i-1][a] = c;
			
		}
		printArray();
		};
	void printboard() {

		cout << endl;
		
		//print 0 1 2 3 4 ...
		cout << "   ";
		for (int i = 0; i < boardsize; i++) {
			cout << " " << i;
		}
		cout << endl;
	}
private:
	
};
class block {
public:
	char generate() {
		srand(time(0));
		r = 1 + rand() % 4;
		switch (r) {
		case 1: r = 'X'; cout << "X"; break;
		case 2: r = 'O'; cout << "O"; break;
		case 3: r = '#'; cout << "#"; break;
		case 4: r = '$'; cout << "$"; break;

		default:
			cout << "System error" << endl;
			break;
		}
		return r;
	}

private:
	int r;
};
void rotate() {
	for (int i = 0; i<columns; i++) {
		for (int j = 0; j<rows; j++) {
			game[i][j] = game[rows - 1 - j][i];
		}
	}
	;
}

void StartGame()
{
	char a, b;
	cout << endl;
	cout << "StartGame" << endl;
	system("cls");
	board board;
	block leftblock, rightblock;
	a=leftblock.generate();
	b=rightblock.generate();
	cout << endl;
	board.printArray();
	int i;
	cin >> i;
	system("cls");
	board.dropblocks(i, a);
	board.dropblocks(i, b);
	system("pause");
}
//function used for print board

void ChangeBoardSize()
{
	//code
	int num = 0;
	cout << "----------------------------------------------" << endl;
	cout << "[1] Change Board Size" << endl; //test only, del after finishing the code
	cout << "You can change board size here." << endl;
	cout << "Please enter a size(6-10): ";
	cin >> num;
	if (num >= 6 && num <= 10)
	{
		boardsize = num;
		cout << "You have changed the Board Size to " << boardsize << endl;
		cout << "----------------------------------------------" << endl;
	}
	else {
		cout << "You can only enter 6-10! " << endl;
		cout << "----------------------------------------------" << endl;
		ChangeBoardSize();
	}
}

void Settings()
{
	// Code for setting
	int choice;
	cout << endl << endl;
	cout << "*** Settings Menu ***" << endl;
	cout << "[1] Change Board Size" << endl;
	cout << "[2] Return to Game Menu" << endl;
	cout << "*********************" << endl;
	cout << "Option (1 - 2): ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1: ChangeBoardSize(); break;
	case 2: break;
	default:
		cout << "Option (1 - 2) only!";
		break;
	}


}

void Instructions()
{
	// Insert instructions code here
	cout << "Instructions" << endl; //test only, del after finishing the code

}

void Credits()
{
	//Insert Credits code here
	cout << "Credits" << endl; //test only, del after finishing the code

}

void exit() {
	//Insert exit code here
	cout << "exit";

}

int main() {
	int choice;

	WelcomeMessage();

	do { //Back to menu after choice option
		cout << endl;
		cout << "*** Game Menu ***" << endl;
		cout << "[1] Start Game" << endl;
		cout << "[2] Settings" << endl;
		cout << "[3] Instructions" << endl;
		cout << "[4] Credits" << endl;
		cout << "[5] Exit" << endl;
		cout << "*****************" << endl;
		cout << "Option (1 - 5): ";
		cin >> choice;

		switch (choice) {
		case 1: StartGame(); break;
		case 2: Settings(); break;
		case 3: Instructions(); break;
		case 4: Credits(); break;
		case 5: break;

		default:
			cout << "Option (1-5) only!" << endl;
			break;
		}
	} while (choice != 5);

	exit();
	return 0;
}
