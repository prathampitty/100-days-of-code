#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define clrscr() system("cls");
#define getch() kbhit()

using namespace std;

void draw_line(int n, char ch);
void board();
void gamescore(char name1[], char name2[], int p1, int p2);
void play_dice(int &score);

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
    system("pause");
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

    int player1 = 0, player2 = 0, lastposition;
    char player1name[80], player2name[80];
    clrscr();
    // system("color 02");
    srand(time(NULL));
    draw_line(50, '=');
    cout << "\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
    draw_line(50, '=');
    cout << "\n\n\nEnter Name of player 1 :";
    gets(player1name);
    cout << "\n\n\nEnter Name of player 2 :";
    gets(player2name);
    while (player1 <= 100 && player2 <= 100)
    {
        board();
        gamescore(player1name, player2name, player1, player2);
        cout << "\n\n--->" << player1name << " Now your Turn >> Press any key to play ";
        getch();
        lastposition = player1;
        play_dice(player1);

        if (player1 < lastposition)
            cout << "\n\aOops!! Snake found !! You are at postion " << player1 << "\n";

        else if (player1 > lastposition + 6)
            cout << "\nGreat!! you got a ladder !! You are at position " << player1;
        cout << "\n\n--->" << player2name << " Now your Turn >> Press any key to play ";

        getch();
        lastposition = player2;
        play_dice(player2);

        if (player2 < lastposition)
            cout << "\n\naOops!! Snake found !! You are at position " << player2 << "\n";

        else if (player2 > lastposition + 6)
            cout << "\n\nGreat!! you got a ladder !! You are at position " << player2 << "\n";
        getch();
    }

    clrscr();
    cout << "\n\n\n";
    draw_line(50, '+');
    cout << "\n\n\t\tRESULT\n\n";
    draw_line(50, '+');
    cout << endl;
    gamescore(player1name, player2name, player1, player2);
    cout << "\n\n\n";

    if (player1 >= player2)
        cout << player1name << " !! You are the winner of the game\n\n";
    else
        cout << player2name << " !! You are the winner of the game\n\n";
    draw_line(50, '+');
    getch();
}

void draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
}

void board()
{
    clrscr();
    cout << "\n\n";
    draw_line(50, '-');
    cout << "\n\t\tSNAKE AT POSITION\n";
    draw_line(50, '-');
    cout << "\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to  1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to  7\n\tFrom 52 to 11\n\tFrom 48 to  9\n\tFrom 46 to  5\n\tFrom 44 to 22\n\n";
    draw_line(50, '-');
    cout << "\n\t\t LADDER AT POSITION\n";
    draw_line(50, '-');
    cout << "\n\tFrom  8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
    draw_line(50, '-');
    cout << endl;
}

void gamescore(char name1[], char name2[], int p1, int p2)
{
    cout << "\n";
    draw_line(50, '~');
    cout << "\n\t\tGAME STATUS\n";
    draw_line(50, '~');
    cout << "\n\t--->" << name1 << " is at position " << p1 << endl;
    cout << "\t--->" << name2 << " is at position " << p2 << endl;
    draw_line(50, '_');
    cout << endl;
}

void play_dice(int &score)
{
    int dice;
    dice = (rand() % 6) + 1;
    cout << "\nYou got " << dice << " Point !! ";
    score = score + dice;
    cout << "Now you are at position " << score;
    switch (score)
    {
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 50:
        score = 91;
        break;
    case 54:
        score = 93;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
    }
    cin.get();
}