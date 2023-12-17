#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fx, fy, score;
enum direcc
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
direcc dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");
    // primera linea del tablero
    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((j == 0) || (j == width - 1))
            {
                cout << "#";
            }
            if ((j == x) && (i == y))
            {
                cout << "O";
            }
            else if ((j == fx) && (i == fy))
            {
                cout << "@";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // ultima linea del tablero

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit() != 0)
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if ((x < 0) || (x > height) || (y < 0) || (y > width))
    {
        gameOver = true;
    }
    if((x == fx) && (y == fy))
    {
        score += 10;
        fx = rand() % width;
        fy = rand() % height;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        _sleep(120);
    }
    return 0;
}