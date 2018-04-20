#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
using namespace std;

int boardsize = 6;
char temp[10][10];
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
        } else {
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
                cout << " " << (char)temp[i + 1][j];

            }
            cout << " |" << endl;
        }
        printrow();

    }
    void anticlock() {
        for (int x = 0; x * 2 < boardsize; x++)
        {
            for (int y = x; y < boardsize - x - 1; y++)
            {

                int t = temp[x + 1][y];
                temp[x + 1][y] = temp[y + 1][boardsize - 1 - x];
                temp[y + 1][boardsize - x - 1] = temp[boardsize - x][boardsize - 1 - y];
                temp[boardsize - x][boardsize - 1 - y] = temp[boardsize - y][x];
                temp[boardsize - y][x] = t;
            }
        }
    }
    void dropblocks(int a, char c, char d, int& dp1, int& dp2) {
        int t = 0;
        board board;
        dp1 = 0, dp2 = 0;
        //if (boardsize == 6) {
        for (int i = 0; i < boardsize; i++) {
            temp[0][a] = c;
            temp[0][a + 1] = d;
            if (temp[i + 1][a] == 0 && temp[i + 1][a + 1] == 0)
            {
                temp[i + 1][a] = temp[i][a];
                temp[i + 1][a + 1] = temp[i][a + 1];
                temp[i][a] = t;
                temp[i][a + 1] = t;
                temp[0][a] = 0;
                temp[0][a + 1] = 0;
                dp1 += 1;
                dp2 += 1;
                system("cls");
                board.printArray();
                system("pause");
            } else if (temp[i + 1][a] == 0)
            {
                temp[i + 1][a] = temp[i][a];
                temp[i][a] = t;
                temp[0][a] = 0;
                temp[0][a + 1] = 0;
                dp1 += 1;
                system("cls");
                board.printArray();
            } else if (temp[i + 1][a + 1] == 0) {
                temp[i + 1][a + 1] = temp[i][a + 1];
                temp[i][a + 1] = t;
                temp[0][a] = 0;
                temp[0][a + 1] = 0;
                system("cls");
                dp2 += 1;
                board.printArray();
            }

        }



    }

    void mergeblock(int a, char c, char d, int dp1, int dp2) {

        int mercounter = 0, vert = 0, left = 0, right = 0, lp = 0, rp = 0, mp = 0;//mergecounters
        bool stop = false;
        cout << dp1 << " " << dp2;


        mercounter = 0, vert = 0, left = 0, right = 0, lp = 0, rp = 0, mp = 0;
        if (temp[dp1][a] == temp[dp1 + 1][a] && temp[dp1][a] != 0) {
            mp += 1;
            if (temp[dp1][a] == temp[dp1][a - 1] && temp[dp1][a] != 0)
                lp = mp;
            if (temp[dp1][a] == temp[dp1][a + 1] && temp[dp1][a] != 0)
                rp = mp;
            if (temp[dp1][a] == temp[dp1 + 2][a] && temp[dp1][a] != 0)
                vert += 1;
            vert += 1;

        }
        if (temp[dp1][a] == temp[dp1 + rp][a + 1] && temp[dp1][a] != 0) {
            if (temp[dp1][a] == temp[dp1 + rp][a + 2] && temp[dp1][a] != 0)
                right += 1;
            right += 1;
        }
        if (temp[dp1][a] == temp[dp1 + lp][a - 1] && temp[dp1][a] != 0) {
            if (temp[dp1][a] == temp[dp1 + lp][a - 2] && temp[dp1][a] != 0)
                left += 1;
            left += 1;
        }
        mercounter = left + right + vert;
        if (mercounter >= 2)

        {
            cout << mercounter;
            for (int i = 0; i <= right; i++) {
                if (rp != mp)
                    temp[dp1 + rp][a + i] = 0;
            }
            for (int i = 1; i <= left; i++)
                if (lp != mp)
                    temp[dp1 + lp][a - i] = 0;
            for (int i = 0; i <= vert; i++) {
                if (mp = 0 && left >= 1)
                    temp[dp1][a] = 0;
                else temp[dp1 + i][a] = 0;
            }
        }


        mercounter = 0, vert = 0, left = 0, right = 0, lp = 0, rp = 0, mp = 0;
        a += 1;
        if (temp[dp2][a] == temp[dp2 + 1][a] && temp[dp2][a] != 0) {
            mp += 1;
            if (temp[dp2][a] == temp[dp2][a - 1] && temp[dp2][a] != 0)
                lp = mp;
            if (temp[dp2][a] == temp[dp2][a + 1] && temp[dp2][a] != 0)
                rp = mp;
            if (temp[dp2][a] == temp[dp2 + 2][a] && temp[dp2][a] != 0)
                vert += 1;
            vert += 1;

        }
        if (temp[dp2][a] == temp[dp2 + rp][a + 1] && temp[dp2][a] != 0) {
            if (temp[dp2][a] == temp[dp2 + rp][a + 2] && temp[dp2][a] != 0)
                right += 1;
            right += 1;
        }
        if (temp[dp2][a] == temp[dp2 + lp][a - 1] && temp[dp2][a] != 0) {
            if (temp[dp2][a] == temp[dp2 + lp][a - 2] && temp[dp2][a] != 0)
                left += 1;
            left += 1;
        }
        mercounter = left + right + vert;
        if (mercounter >= 2)

        {
            cout << mercounter;
            for (int i = 0; i <= right; i++) {
                if (rp != mp)
                    temp[dp2 + rp][a + i] = 0;
            }
            for (int i = 1; i <= left; i++)
                if (lp != mp)
                    temp[dp2 + lp][a - i] = 0;
            for (int i = 0; i <= vert; i++) {
                if (mp = 0 && left >= 1)
                    temp[dp2][a] = 0;
                else temp[dp2 + i][a] = 0;
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
void StartGame()
{
    char a = 0, b = 0, input;
    char i[5];
    int convert = 0;
    int dp1 = 0, dp2 = 0; //droppoints
    cout << endl;
    cout << "StartGame" << endl;
    system("cls");
    board board;
    block leftblock, rightblock;
    int dbcount = 0, iserror = 0;
    do {
        a = leftblock.gen();
        b = rightblock.gen();
        board.printArray();

        cin >> i;
        input = i[5];
        do {
            dbcount = 0;
            iserror = 0;
            for (int counter = 0; i[counter] != '\0'; counter++) {
                if (i[counter] >= '0' && i[counter] <= '9')
                {
                    dbcount++;
                    continue;
                } else if (i[counter] == 'r')
                    break;
                else if (i[counter] == 'R')
                    break;
                else
                    iserror = 1;
                continue;
            }
            if (dbcount > 1 || iserror) {
                cout << "Out of range please input again\n";
                cin >> i;
            }
        } while (dbcount > 1 || iserror);

        for (int counter = 0; i[counter] != '\0'; counter++) {
            if (i[counter] >= '0' && i[counter] < '9' + 1) {
                convert = i[counter] - '0';
                system("cls");
                cout << convert;
                if (convert < boardsize - 1) {
                    board.dropblocks(convert, a, b, dp1, dp2);
                    board.mergeblock(convert, a, b, dp1, dp2);
                    break;
                } else
                {
                    board.printArray();
                    cout << "Invaild Input!\n";
                    continue;
                }
            } else if (i[counter] == 'R'||i[counter] == 'r') {
                board.anticlock();
                system("cls");
                board.printArray();
                break;
            }
        }
    } while (input != 'Quit');
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
            cout << "Option (1 - 2) only!"; break;
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
    cout << "vvv Drop position and corresponding NUMBERs will show like this vvv" << endl;
    cout << "     v v v v v v  INPUT THIS NUMBERS!!" << endl;
    cout << "     0 1 2 3 4 5 " << endl;
    cout << "   +-------------+" << endl;
    cout << " A |             |" << endl;
    cout << " B |             |" << endl;
    cout << " C |             |" << endl;
    cout << " D |             |" << endl;
    cout << " E |             |" << endl;
    cout << " F |             |" << endl;
    cout << "   +-------------+" << endl;
    cout << "You should input ALL you command in ONE time." << endl;
    cout << "e.g. 'rrr4', 'R3', '5'" << endl << endl;
    cout << setw(50) << "GOOD LUCK, HAVE FUN." << endl;
}
void Credits()
{
    //Insert Credits code here
    cout << "~~~~~~~Credits~~~~~~~~" << endl;
    cout << "~~~~~~Group members:~~~~~~" << endl;
    cout << "Wong Ka Wai-17167572     Wong Cho Lam-17169147A" << endl;
    cout << "Lee Ka Lok-17065440A       Chan Chung Yan-17073402A" << endl;
    cout << "Hsieh Cheng Hsun-17024850A   Lee Chin Fung-17109777A" << endl;
    cout << "  " << endl;
    cout << "      Class : CCN2042 Computer Programming      " << endl;
    cout << "  " << endl;
    cout << "      Tutoial group 202   Group 7      " << endl;


}

int exit() {
    char check = 'd';
    while (check != 'Y' || check != 'N' || check != 'y' || check != 'n') {
        cout << "Are you sure you want to leave?(Y/N)" << endl;
        cin >> check;
        if (check == 'Y' || check == 'y') {
            return 1;
        } else if (check == 'N' || check == 'n') {
            return 0;
        } else {
            cout << "Please input Y/y or N/n only!";
        }
    }
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
            case 5: if (!exit()) choice = 1; break;
            default:
                cout << "Option (1-5) only!" << endl;
                break;
        }
    } while (choice != 5);
    cout << "Good bye." << endl;
    return 0;
}
