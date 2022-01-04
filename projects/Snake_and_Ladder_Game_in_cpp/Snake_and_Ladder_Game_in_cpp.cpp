#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#define clrscr() system("cls");
#define getch() kbhit()

using namespace std;

void draw_line(int n, char ch);
void board();
void gamescore(char name1[], char name2[], int p1, int p2);
void play_dice(int &score);

int main()
{
    int player1 = 0, player2 = 0, lastposition;
    char player1name[80], player2name[80];
    clrscr();
    srand(time(NULL));
    draw_line(50, '=');
    cout << "nnnnttSNAKE LADDER GAMEnnnn";
    draw_line(50, '=');
    cout << "nnnEnter Name of player 1 :";
    gets(player1name);
    cout << "nnnEnter Name of player 2 :";
    gets(player2name);
    while (player1 <= 100 && player2 <= 100)
    {
        board();
        gamescore(player1name, player2name, player1, player2);
        cout << "nn--->" << player1name << " Now your Turn >> Press any key to play ";
        getch();
        lastposition = player1;
        play_dice(player1);

        if (player1 < lastposition)
            cout << "naOops!! Snake found !! You are at postion " << player1 << "n";

        else if (player1 > lastposition + 6)
            cout << "nGreat!! you got a ladder !! You are at position " << player1;
        cout << "nn--->" << player2name << " Now your Turn >> Press any key to play ";

        getch();
        lastposition = player2;
        play_dice(player2);

        if (player2 < lastposition)
            cout << "nnaOops!! Snake found !! You are at position " << player2 << "n";

        else if (player2 > lastposition + 6)
            cout << "nnGreat!! you got a ladder !! You are at position " << player2 << "n";
        getch();
    }

    clrscr();
    cout << "nnn";
    draw_line(50, '+');
    cout << "nnttRESULTnn";
    draw_line(50, '+');
    cout << endl;
    gamescore(player1name, player2name, player1, player2);
    cout << "nnn";

    if (player1 >= player2)
        cout << player1name << " !! You are the winner of the gamenn";
    else
        cout << player2name << " !! You are the winner of the gamenn";
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
    cout << "nn";
    draw_line(50, '-');
    cout << "nttSNAKE AT POSITIONn";
    draw_line(50, '-');
    cout << "ntFrom 98 to 28 ntFrom 95 to 24ntFrom 92 to 51ntFrom 83 to 19ntFrom 73 to  1ntFrom 69 to 33ntFrom 64 to 36ntFrom 59 to 17ntFrom 55 to  7ntFrom 52 to 11ntFrom 48 to  9ntFrom 46 to  5ntFrom 44 to 22nn";
    draw_line(50, '-');
    cout << "ntt LADDER AT POSITIONn";
    draw_line(50, '-');
    cout << "ntFrom  8 to 26ntFrom 21 to 82ntFrom 43 to 77ntFrom 50 to 91ntFrom 62 to 96ntFrom 66 to 87ntFrom 80 to 100n";
    draw_line(50, '-');
    cout << endl;
}

void gamescore(char name1[], char name2[], int p1, int p2)
{
    cout << "n";
    draw_line(50, '~');
    cout << "nttGAME STATUSn";
    draw_line(50, '~');
    cout << "nt--->" << name1 << " is at position " << p1 << endl;
    cout << "t--->" << name2 << " is at position " << p2 << endl;
    draw_line(50, '_');
    cout << endl;
}

void play_dice(int &score)
{
    int dice;
    dice = (rand() % 6) + 1;
    cout << "nYou got " << dice << " Point !! ";
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