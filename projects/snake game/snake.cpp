/*
note :- I will try to keep the code simple !!

Below given some functionalities of this game:
The snake is represented with a 0(zero)symbol.
The fruit is represented with an *(asterisk)symbol.
The snake can move in any direction according to the user with the help of the keyboard(W, A, S, D keys).
When the snake eats a fruit the score will increase by 10 points.
The fruit will generate automatically within the boundaries.
Whenever the snake will touch the boundary the game is over.


Below given some function we are going to use in this game:
user-defined functions
Boundary(): This function creates the boundary in which the game will be played.
Position_fruit(): This function will set the position of the fruit within the boundary.
Remote_control(): This function will take the input from the keyboard.
Movement_logic(): This function will set the movement of the snake.

pre-defined functions
 # kbhit() : This function in C is used to determine if a key has been pressed or not.
To use this function in a program include the header file <conio.h.>
If a key has been pressed, then it returns a non-zero value otherwise it returns zero.

 # rand() : The rand() function is declared in stdlib.h.
It returns a random integer value every time it is called.


so for the above funtions we will include' below  header files
# include<stdio.h>
# include<conio.h>
# include<stdlib.h>
*/
#include <stdio.h>  // this include printf and scanf
#include <conio.h>  // this include cls
#include <stdlib.h> //
#include <time.h>   // used for rand() function & to add time delay
#include <math.h>   // arithmatic logic
#include <windows.h>
// used to access the Win32 API functions and easy for user to use the in-built functionality

// variables used
// we are declaring in global
int height = 30,
    width = 30, gameover = 0, score, x, y, fruit_x, fruit_y;
int count;
int totalTail;
int tail_x[100], tail_y[100];

void Position_fruit() // this function is use to setup the the fruit inside the box
{
    srand(time(NULL));
    x = height / 2;
    y = width / 2;
    score = 0;
start:
    fruit_x = 1 + rand() % height;
    fruit_y = 1 + rand() % width;

    if (fruit_x <= 0 || fruit_y <= 0 || fruit_x == x || fruit_y == y || fruit_x > height || fruit_y > width)
    {
        goto start;
    }
}

void Boundary()
{
    system("cls"); // This function is used to clear the screen after each run.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) // This condition is for creating the box
            {
                printf("+");
            }
            else if (i == x && j == y)
            {
                printf("@");
            }
            else if (fruit_x == i && fruit_y == j)
            {
                printf("X");
            }
            else
            {
                int count1 = 0;
                for (int k = 0; k < totalTail; k++)
                {
                    if (tail_x[k] == i && tail_y[k] == j)
                    {
                        printf("o"); // This will add the previous head as a tail.
                        count1 = 1;
                    }
                }
                if (count1 == 0)
                {
                    printf(" "); // this will insert a space inside the box
                }
            }
        }
        printf("\n");
    }
    printf("Score: %d", score);
}

void Remote_control()
{ // This program will take input from user.
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            count = 1;
            break;
        case 's':
            count = 2;
            break;
        case 'a':
            count = 3;
            break;
        case 'd':
            count = 4;
            break;
        case 'x':
            break;
        }
    }
}
void Movement_logic()
{
    int prev_x = tail_x[0];
    int prev_y = tail_y[0];

    int prev_2x, prev_2y;

    tail_x[0] = x;
    tail_y[0] = y;

    for (int i = 1; i < totalTail; i++)
    {
        prev_2x = tail_x[i];
        prev_2y = tail_y[i];

        tail_x[i] = prev_x;
        tail_y[i] = prev_y;

        prev_x = prev_2x;
        prev_y = prev_2y;
    }

    switch (count)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    }
    if (count == 1 || count == 2)
    {
        Sleep(25);
    }
    for (int i = 0; i < totalTail; i++)
    {
        if (tail_x[i] == x && tail_y[i] == y)
        {
            gameover = 1;
        }
    }
    if (x > width - 1 || y > height - 1 || x < 0 || y < 0)
    {
        gameover = 1;
    }
    if (x == fruit_x && y == fruit_y)
    {
        score += 1;
        totalTail++;

    label2:
        fruit_x = rand() % height;
        fruit_y = rand() % width;

        if (fruit_x <= 0 || fruit_y <= 0 || fruit_x == x || fruit_y > width)
        {
            goto label2;
        }
    }
}

void loading_function(int p, int q)
{
    COORD coord;
    coord.X = p; // your X cord
    coord.Y = q; // your Y cord
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    system("cls");
    loading_function(70, 10);
    system("color 02");
    printf("Ready to play snake game in c.\n");
    printf("\n\n\n\n\nPress any key to continue...\n");
    getch();
    {
        system("cls");
        int p, q;
        loading_function(70, 10);
        system("color 02");
        printf("Loading...");
        loading_function(65, 13);
        for (p = 1; p <= 20; p++)
        {
            for (q = 0; q <= 200000000; q++)
                ;
            {
                printf("%c", 177);
            }
        }
    }
    system("cls");
    loading_function(70, 10);
    printf("Lets go.\n\n\n\nPress any key to play the game. ");
    getch();
    system("cls");

    Position_fruit();

    while (gameover != 1)
    {
        Boundary();
        Movement_logic();
        Remote_control();
        Sleep(30);
    }
    return 0;
}
