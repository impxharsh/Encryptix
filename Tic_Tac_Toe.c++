#include <iostream>
using namespace std;

void printboard(char a[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != 'X' && a[i][j] != 'O') {
                cout << " " << i * 3 + j + 1 << " ";
            } else {
                cout << " " << a[i][j] << " ";
            }
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
}

int winner_check(char a[][3]) {
    for (int i = 0; i < 3; i++) {
        if ((a[i][0] == 'X' && a[i][1] == 'X' && a[i][2] == 'X') || 
            (a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X')) {
            return 1;
        } else if ((a[i][0] == 'O' && a[i][1] == 'O' && a[i][2] == 'O') || 
                   (a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O')) {
            return -1;
        }
    }

    if ((a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X') || 
        (a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X')) {
        return 1;
    } else if ((a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O') || 
               (a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O')) {
        return -1;
    }

    return 0;
}

void resetBoard(char a[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = ' ';
        }
    }
}

int main() {
    char a[3][3];
    int x, y, count = 1, turn = 1, n;

    cout << "The corresponding numbers represent the box positions\n";
    resetBoard(a);
    printboard(a);

    while (true) {
        while (count < 10) {
            cout << "Enter the position (1-9) where you want to put " 
                 << ((count % 2 != 0) ? "X" : "O") << ": ";
            int pos;
            cin >> pos;
            x = (pos - 1) / 3 + 1;
            y = (pos - 1) % 3 + 1;

            while (pos < 1 || pos > 9 || a[x-1][y-1] != ' ') {
                cout << "Invalid input or space is already occupied, please enter again: ";
                cin >> pos;
                x = (pos - 1) / 3 + 1;
                y = (pos - 1) % 3 + 1;
            }

            a[x-1][y-1] = (count % 2 != 0) ? 'X' : 'O';
            count++;
            printboard(a);

            int win = winner_check(a);
            if (win == 1) {
                cout << "Winner is X!\n";
                break;
            } else if (win == -1) {
                cout << "Winner is O!\n";
                break;
            }
        }

        if (count >= 10 && winner_check(a) == 0) {
            cout << "It's a Draw!\n";
        }

        cout << "Do you want to play again? Press 1 for Yes, 2 for No\n";
        cin >> n;

        if (n == 1) {
            count = 1;
            turn = 1;
            resetBoard(a);
            printboard(a);
        } else {
            break;
        }
    }

    return 0;
}
