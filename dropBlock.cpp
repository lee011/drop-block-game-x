#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <string>
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
	void ChangeBoardSize()
	{
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
				cout << " " << (char)game[i+1][j];
			}
			cout << " |" << endl;
		}
		printrow();
		
	}
	void rotate() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10/2; j++) {
				
				game[i][j] = game[rows - 1 - j][i];
			
			}
		}
		
	};
	void dropblocks(int a, char c, char d) {
		
		
			int temp = 0;
			for (int i = 0; i < boardsize; i++) {
				game[i][a] = c;
				game[i][a + 1] = d;
				if (game[i + 1][a] == 0 && game[i + 1][a + 1] == 0)
				{
					game[i + 1][a] = game[i][a];
					game[i + 1][a + 1] = game[i][a + 1];
					game[i][a] = temp;
					game[i][a + 1] = temp;
					system("cls");
					printArray();
					system("pause");
				}
				else if (game[i + 1][a] == 0)
				{
					game[i + 1][a] = game[i][a];
					game[i][a] = temp;
					system("cls");
					printArray();
				}
				else if (game[i + 1][a + 1] == 0) {
					game[i + 1][a + 1] = game[i][a + 1];
					game[i][a + 1] = temp;
					system("cls");
					printArray();
				}

			}
		
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
	char gen() {
		
		r = 1 + rand() % 4;
		switch (r) {
		case 1: r = 'X'; cout << r; break;
		case 2: r = 'O'; cout << r; break;
		case 3: r = '#'; cout << r; break;
		case 4: r = '$'; cout << r; break;

		default:
			cout << "System error" << endl;
			break;
		}
		return r;
	}
private:
	char r = 0;
};


void StartGame()
{
	char a = 0, b = 0;
	char i[5];
	int convert = 0;
	cout << endl;
	cout << "StartGame" << endl;
	system("cls");
	board board;
	block leftblock, rightblock;
	int errcount = 0;

	do {
		a = leftblock.gen();
		b = rightblock.gen();
		board.printArray();

		cin >> i;
		

		do {
			errcount = 0;
			for (int counter = 0; i[counter] != '\0'; counter++) {
				if (i[counter] >= '0' && i[counter] <= '9' )
						errcount++;
			}
			if (errcount > 1) {
				cout << "Out of range please input again\n";
				cin >> i;
			}

		} while (errcount > 1);

				for (int counter = 0; i[counter] != '\0'; counter++) {
					if (i[counter] >= '0' && i[counter] < '0' + boardsize) {
						convert = i[counter] - '0';
						system("cls");
						board.dropblocks(convert, a, b);
						break;
					}
					else if (i[counter] == 'r' || i[counter] == 'R') {
						board.rotate();
						break;
					}
				}

			} while (game[0][0] == 0);
		}
	



void Settings()
{
	// Code for setting
	int choice;
	board board;
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
	case 1: board.ChangeBoardSize(); break;
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
	srand(time(0));

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
