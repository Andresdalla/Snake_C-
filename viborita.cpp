#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fx, fy, score;
int tailX[100], tailY[100];
int nTail;
enum direcc {
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
            if ((j == 0))
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
                bool printed = false;
                for(int k = 0;k < nTail; k++)
                {
                    if((tailX[k] == j) && (tailY[k] == i)){
                        cout << "o";
                        printed = true;
                    }
                }
                if(!printed){
                    cout << " ";
                }

            }
            if (j == width - 1)
            {
                cout << "#";
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
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prevX2,prevY2;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1;i < nTail; i++)
    {
        prevX2 = tailX[i];
        prevY2 = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevX2;
        prevY = prevY2;
  
    }
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
    if (x >= width)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width - 1;
    }
    if (y >= width)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 1;
    }
    for(int i = 0; i < nTail; i++)
    {
        if((tailX[i] == x) && (tailY[i] == y))
        {
            gameOver = true;
        }
    }
    if((x == fx) && (y == fy))
    {
        nTail++;
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
        Sleep(120);
    }
    return 0;
}