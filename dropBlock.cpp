#include <iostream>
#include <iomanip>

using namespace std;

int boardsize = 6;

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

//function used for print board
void board() {
	cout << endl;

	//print 0 1 2 3 4 ...
	cout << "   ";
	for (int i = 0; i < boardsize; i++) {
		cout << " " << i;
	}
	cout << endl;

	//print 1st +--------+
	printrow();

	//print A B C D and | |
	for (int i = 0; i < boardsize; i++) {
		char k='A';
		(int)k;
		k=k+i;
		cout << (char)k << " |";

		for (int i = 0; i < (boardsize * 2 + 1); i++) {
			cout << " ";
		}
		cout << "|" << endl;
	}
	//print 2nd +--------+
	printrow();
}

void StartGame()
{
	// Insert StartGame code here
	cout << endl;
	cout << "StartGame" << endl; //test only, del after finishing the code
	board();

	//Board size code
    

}

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
	cout << "Instructions:" << endl; //test only, del after finishing the code
	cout << "Use keyboard to play this EXCITING and INTERESTING drop block game" << endl;
	cout << "Input 'r' or 'R' to rotate the blocks, each rotation can change the segment 90° clockwise." << endl;
	cout << "You can input 'r' up to 3 times, which means at most you can rotate the segment 270°" << endl;
	cout << "Input the NUMBER key to change the drop position" << endl;
	cout << "↓↓↓Drop position and corresponding NUMBERs will show like this↓↓↓" << endl;
	cout <<"     ↓ ↓ ↓ ↓ ↓ ↓  INPUT THIS NUMBERS!!" << endl;
	cout <<"     0 1 2 3 4 5 " << endl;
	cout <<"   +-------------+" << endl;
	cout <<" A |             |" << endl;
	cout <<" B |             |" << endl;
	cout <<" C |             |" << endl;
	cout <<" D |             |" << endl;
	cout <<" E |             |" << endl;
	cout <<" F |             |" << endl;
	cout <<"   +-------------+" << endl;
	cout << "You should input ALL you command in ONE time." << endl;
	cout << "e.g. 'rrr4', 'R3', '5'" << endl << endl;
	cout << setw(50) << "GOOD LUCK, HAVE FUN." << endl;

}

void Credits()
{
	//Insert Credits code here
	cout<<"~~~~~~~Credits~~~~~~~~"<<endl;
    	cout<<"~~~~~~Group members:~~~~~~"<<endl;
    	cout<<"Wong Ka Wai-17167572     Wong Cho Lam-17169147A"<<endl;
    	cout<<"Lee Ka Lok-17065440A       Chan Chung Yan-17073402A"<<endl;
    	cout<<"Hsieh Cheng Hsun-17024850A   Lee Chin Fung-17109777A"<<endl;
    	cout<<"  "<<endl;
    	cout<<"      Class : CCN2042 Computer Programming      "<<endl;
    	cout<<"  "<<endl;
    	cout<<"      Tutoial group 202   Group 7      "<<endl;

}

void exit() {
	char check = 'd';
    	while (check != 'Y' || check != 'N' || check != 'y' || check != 'n') {
		cout << "Are you sure you want to leave?(Y/N)" << endl;
        	cin >> check;
        	if (check == 'Y' || check == 'y') {
            		exit(0);;
        	}
        	else if (check == 'N' || check == 'n') {
        	    	break;
        	}
        	else {
            	cout << "Please input Y/y or N/n only!";
        	}
    	}

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
		case 5: exit(); break;

		default:
			cout << "Option (1-5) only!" << endl;
			break;
		}
	} while (choice != 5);

	
	return 0;
}
