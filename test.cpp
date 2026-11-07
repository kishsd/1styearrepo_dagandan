#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

int playerX, playerY;
int catX, catY;
int moves = 0;
bool gameOver = false;
bool caught = false;

void spawnCat() {
    catX = rand() % WIDTH;
    catY = rand() % HEIGHT;
}

void moveCat() {
    int dir = rand() % 4;
    int newX = catX;
    int newY = catY;

    if (dir == 0 && catX > 0) newX--;
    else if (dir == 1 && catX < WIDTH - 1) newX++;
    else if (dir == 2 && catY > 0) newY--;
    else if (dir == 3 && catY < HEIGHT - 1) newY++;

    catX = newX;
    catY = newY;
}

void draw() {
    system("cls");
    cout << "=== CATCH THE CAT ===\n";
    cout << "You are P, Cat is C. Catch the cat before it escapes!\n";
    cout << "Controls: W A S D to move | Q to quit\n";
    cout << "Moves: " << moves << "\n\n";

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == playerX && y == playerY) {
                cout << "P";
            } else if (x == catX && y == catY) {
                cout << "C";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        int newX = playerX;
        int newY = playerY;

        if (key == 'w' || key == 'W') newY--;
        else if (key == 's' || key == 'S') newY++;
        else if (key == 'a' || key == 'A') newX--;
        else if (key == 'd' || key == 'D') newX++;
        else if (key == 'q' || key == 'Q') { gameOver = true; return; }

        if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
            playerX = newX;
            playerY = newY;
            moves++;
        }
    }
}

void update() {
    moveCat();

    if (playerX == catX && playerY == catY) {
        caught = true;
        gameOver = true;
    }

    if (moves >= 50) {
        gameOver = true;
    }
}

int main() {
    srand(time(0));

    playerX = 0;
    playerY = 0;
    spawnCat();

    // Make sure cat doesn't spawn on player
    while (playerX == catX && playerY == catY) {
        spawnCat();
    }

    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(100);
    }

    system("cls");
    if (caught) {
        cout << "Meow! You caught the cat!\n";
    } else {
        cout << "The cat escaped!\n";
    }
    cout << "Moves taken: " << moves << "\n";
    return 0;
}
