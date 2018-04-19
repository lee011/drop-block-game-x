#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

int boardsize = 6;
char temp[6][6], temp1[7][7], temp2[8][8], temp3[9][9], temp4[10][10];
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
				if (boardsize == 6)
					cout << " " << (char)temp[i][j];
				else if (boardsize == 7)
					cout << " " << (char)temp1[i][j];
				else if (boardsize == 8)
					cout << " " << (char)temp2[i][j];
				else if (boardsize == 9)
					cout << " " << (char)temp3[i][j];
				else if (boardsize == 10)
					cout << " " << (char)temp4[i][j];
			}
			cout << " |" << endl;
		}
		printrow();

	}
	void antirotate() {
		if (boardsize == 6) {
			for (int x = 0; x < boardsize / 2; x++)
			{
				for (int y = x; y < boardsize-x-1; y++)
				{
					int t = temp[x][y];
					temp[x][y] = temp[y][boardsize-1-x];
					temp[y][boardsize-1-x] = temp[boardsize-1-x][boardsize-1-y];
					temp[boardsize-1-x][boardsize-1-y] = temp[boardsize-1-y][x];
					temp[boardsize-1-y][x] = t;
				}
			}
		}
		else if (boardsize == 7) {
			for (int x = 0; x < boardsize / 2; x++)
			{
				for (int y = x; y < boardsize-x-1; y++)
				{
					int t = temp1[x][y];
					temp1[x][y] = temp1[y][boardsize-1-x];
					temp1[y][boardsize-1-x] = temp1[boardsize-1-x][boardsize-1-y];
					temp1[boardsize-1-x][boardsize-1-y] = temp1[boardsize-1-y][x];
					temp1[boardsize-1-y][x] = t;
				}
			}
		
		}
		else if (boardsize == 8) {
			for (int x = 0; x < boardsize / 2; x++)
			{
				for (int y = x; y < boardsize - x - 1; y++)
				{
					int t = temp2[x][y];
					temp2[x][y] = temp2[y][boardsize - 1 - x];
					temp2[y][boardsize - 1 - x] = temp2[boardsize - 1 - x][boardsize - 1 - y];
					temp2[boardsize - 1 - x][boardsize - 1 - y] = temp2[boardsize - 1 - y][x];
					temp2[boardsize - 1 - y][x] = t;
				}
			}

		}
		else if (boardsize == 9) {
			for (int x = 0; x < boardsize / 2; x++)
			{
				for (int y = x; y < boardsize - x - 1; y++)
				{
					int t = temp3[x][y];
					temp3[x][y] = temp3[y][boardsize - 1 - x];
					temp3[y][boardsize - 1 - x] = temp3[boardsize - 1 - x][boardsize - 1 - y];
					temp3[boardsize - 1 - x][boardsize - 1 - y] = temp3[boardsize - 1 - y][x];
					temp3[boardsize - 1 - y][x] = t;
				}
			}

		}
		else if (boardsize == 10) {
			for (int x = 0; x < boardsize / 2; x++)
			{
				for (int y = x; y < boardsize - x - 1; y++)
				{
					int t = temp4[x][y];
					temp4[x][y] = temp4[y][boardsize - 1 - x];
					temp4[y][boardsize - 1 - x] = temp4[boardsize - 1 - x][boardsize - 1 - y];
					temp4[boardsize - 1 - x][boardsize - 1 - y] = temp4[boardsize - 1 - y][x];
					temp4[boardsize - 1 - y][x] = t;
				}
			}

		}

	}
	void rotate() {
		antirotate();
		antirotate();
		antirotate();
	}
	void dropblocks(int a, char c, char d) {
	int t = 0;
	board board;
	if (boardsize == 6) {
		for (int i = 0; i < boardsize - 1; i++) {
			temp[i][a] = c;
			temp[i][a + 1] = d;
			if (temp[i + 1][a] == 0 && temp[i + 1][a + 1] == 0)
			{
				temp[i + 1][a] = temp[i][a];
				temp[i + 1][a + 1] = temp[i][a + 1];
				temp[i][a] = t;
				temp[i][a + 1] = t;
				system("cls");
				board.printArray();
				system("pause");
			}
			else if (temp[i + 1][a] == 0)
			{
				temp[i + 1][a] = temp[i][a];
				temp[i][a] = t;
				system("cls");
				board.printArray();
			}
			else if (temp[i + 1][a + 1] == 0) {
				temp[i + 1][a + 1] = temp[i][a + 1];
				temp[i][a + 1] = t;
				system("cls");
				board.printArray();
			}

		}
	}
	else if (boardsize == 7) {
		for (int i = 0; i < boardsize - 1; i++) {
			temp1[i][a] = c;
			temp1[i][a + 1] = d;
			if (temp1[i + 1][a] == 0 && temp1[i + 1][a + 1] == 0)
			{
				temp1[i + 1][a] = temp1[i][a];
				temp1[i + 1][a + 1] = temp1[i][a + 1];
				temp1[i][a] = t;
				temp1[i][a + 1] = t;
				system("cls");
				board.printArray();
				system("pause");
			}
			else if (temp1[i + 1][a] == 0)
			{
				temp1[i + 1][a] = temp1[i][a];
				temp1[i][a] = t;
				system("cls");
				board.printArray();
			}
			else if (temp1[i + 1][a + 1] == 0) {
				temp1[i + 1][a + 1] = temp1[i][a + 1];
				temp1[i][a + 1] = t;
				system("cls");
				board.printArray();
			}

		}
	}
	else if (boardsize == 8) {
		for (int i = 0; i < boardsize - 1; i++) {
			temp2[i][a] = c;
			temp2[i][a + 1] = d;
			if (temp2[i + 1][a] == 0 && temp2[i + 1][a + 1] == 0)
			{
				temp2[i + 1][a] = temp2[i][a];
				temp2[i + 1][a + 1] = temp2[i][a + 1];
				temp2[i][a] = t;
				temp2[i][a + 1] = t;
				system("cls");
				board.printArray();
				system("pause");
			}
			else if (temp2[i + 1][a] == 0)
			{
				temp2[i + 1][a] = temp2[i][a];
				temp2[i][a] = t;
				system("cls");
				board.printArray();
			}
			else if (temp2[i + 1][a + 1] == 0) {
				temp2[i + 1][a + 1] = temp2[i][a + 1];
				temp2[i][a + 1] = t;
				system("cls");
				board.printArray();
			}

		}
	}
	else if (boardsize == 9) {
		for (int i = 0; i < boardsize - 1; i++) {
			temp3[i][a] = c;
			temp3[i][a + 1] = d;
			if (temp3[i + 1][a] == 0 && temp3[i + 1][a + 1] == 0)
			{
				temp3[i + 1][a] = temp3[i][a];
				temp3[i + 1][a + 1] = temp3[i][a + 1];
				temp3[i][a] = t;
				temp3[i][a + 1] = t;
				system("cls");
				board.printArray();
				system("pause");
			}
			else if (temp3[i + 1][a] == 0)
			{
				temp3[i + 1][a] = temp3[i][a];
				temp3[i][a] = t;
				system("cls");
				board.printArray();
			}
			else if (temp3[i + 1][a + 1] == 0) {
				temp3[i + 1][a + 1] = temp3[i][a + 1];
				temp3[i][a + 1] = t;
				system("cls");
				board.printArray();
			}

		}
	}
	else if (boardsize == 10) {
		for (int i = 0; i < boardsize - 1; i++) {
			temp4[i][a] = c;
			temp4[i][a + 1] = d;
			if (temp4[i + 1][a] == 0 && temp4[i + 1][a + 1] == 0)
			{
				temp4[i + 1][a] = temp4[i][a];
				temp4[i + 1][a + 1] = temp4[i][a + 1];
				temp4[i][a] = t;
				temp4[i][a + 1] = t;
				system("cls");
				board.printArray();
				system("pause");
			}
			else if (temp4[i + 1][a] == 0)
			{
				temp4[i + 1][a] = temp4[i][a];
				temp4[i][a] = t;
				system("cls");
				board.printArray();
			}
			else if (temp4[i + 1][a + 1] == 0) {
				temp4[i + 1][a + 1] = temp4[i][a + 1];
				temp4[i][a + 1] = t;
				system("cls");
				board.printArray();
			}

		}
	}
}
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

class game {
public:
void StartGame()
{
	char a = 0, b = 0,input;
	char i[5];
	int convert = 0 ;
	cout << endl;
	cout << "StartGame" << endl;
	system("cls");
	board board;
	block leftblock, rightblock;
	int dbcount = 0,errcount=0;
	do {
		a = leftblock.gen();
		b = rightblock.gen();
		board.printArray();

		cin >> i;
		input = i[5];
		do {
			dbcount= 0;
			for (int counter = 0; i[counter] != '\0'; counter++) {
				if (i[counter] >= '0' && i[counter] <= '9')
				{
					dbcount++;
					continue;
				}
				else if (i[counter] == 'r')
				break;
				else if (i[counter] == 'R')
				break;
				else 
					errcount++;
					continue;
				}
			if (dbcount > 1|| errcount >= 1) {
				cout << "Out of range please input again\n";
				cin >> i;
			}
		} while (dbcount > 1);

				for (int counter = 0; i[counter] != '\0'; counter++) {
					if (i[counter] >= '0' && i[counter] < '0' + boardsize) {
						convert = i[counter] - '0';
						system("cls");
						board.dropblocks(convert, a, b);
						break;
					}
					else if (i[counter] == 'r') {
						board.rotate();
						system("cls");
						board.printArray();
						break;
					}
					else if (i[counter] == 'R') {
						board.antirotate();
						system("cls");
						board.printArray();
						break;
					}
				}
	} while (i[5] =='Quit');
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
	{case 1: board.ChangeBoardSize(); break;
	case 2: break;
	default:
		cout << "Option (1 - 2) only!";break;
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
private:
};

int main() {
	int choice;
	game dbgame;
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
		case 1: dbgame.StartGame(); break;
		case 2: dbgame.Settings(); break;
		case 3: dbgame.Instructions(); break;
		case 4: dbgame.Credits(); break;
		case 5: break;
		default:
			cout << "Option (1-5) only!" << endl;
			break;}
	} while (choice != 5);
	dbgame.exit();
	return 0;
}
