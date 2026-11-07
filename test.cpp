#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    srand(time(0));
    int catX = rand() % 20 + 1;
    int catY = rand() % 10 + 1;
    int guessX, guessY;
    int attempts = 0;
    bool caught = false;

    cout << "=== CATCH THE CAT ===\n";
    cout << "A cat is hiding on a 20x10 grid.\n";
    cout << "Guess its position (row 1-10, col 1-20).\n\n";

    while (!caught) {
        cout << "Attempt " << attempts + 1 << "\n";
        cout << "Enter row (1-10): ";
        cin >> guessY;
        cout << "Enter col (1-20): ";
        cin >> guessX;
        attempts++;

        if (guessX == catX && guessY == catY) {
            caught = true;
            cout << "\nMeow! You caught the cat!\n";
            cout << "Attempts taken: " << attempts << "\n";
        } else {
            cout << "The cat is not there. Try again!\n\n";
        }
    }

    cout << "\nGame Over!\n";
    return 0;
}
