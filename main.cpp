#include <iostream>
#include <unistd.h>

int tab[7][6];
int player = 1;
bool end = false;
int a = 0;

void check(int x)
{
    if (tab[x - 1][a] != 0 && a < 6)
    {
        a++;
        check(x);
    }
    else
    {
        tab[x - 1][a] = player;
        a = 0;
    }
}

void draw()
{
    for (int i = 0; i < 9; i++)
    {
        if (i < 2)
        {
            std::cout << "-";
        }
        else if (i > 7)
        {
            std::cout << i - 1 << "--" << std::endl;
        }
        else
        {
            std::cout << i - 1 << "----";
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tab[j][i] != 0)
            {
                std::cout << "| " << (tab[j][i] == 1 ? "X" : "O") << " |";
            }
            else
            {
                std::cout << "|   |";
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 35; i++)
    {
        std::cout << "=";
    }
    std::cout << std::endl;
}

bool win_check()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j + 3 < 7 && tab[j][i] == player && tab[j + 1][i] == player && tab[j + 2][i] == player && tab[j + 3][i] == player)
            {
                return true;
            }
            if (i + 3 < 6 && tab[j][i] == player && tab[j][i + 1] == player && tab[j][i + 2] == player && tab[j][i + 3] == player)
            {
                return true;
            }
            if (j + 3 < 7 && i + 3 < 6 && tab[j][i] == player && tab[j + 1][i + 1] == player && tab[j + 2][i + 2] == player && tab[j + 3][i + 3] == player)
            {
                return true;
            }
            if (j - 3 >= 0 && i + 3 < 6 && tab[j][i] == player && tab[j - 1][i + 1] == player && tab[j - 2][i + 2] == player && tab[j - 3][i + 3] == player)
            {
                return true;
            }
        }
    }
    return false;
}

void p_choice()
{
    int choice;
    while (!end)
    {
        std::cout << "PLAYER " << player << ": ";
        std::cin >> choice;
        if (choice > 0 && choice < 8)
        {
            check(choice);
            draw();
            if (win_check())
            {
                std::cout << "\nPLAYER " << player << " WINS!" << std::endl;
                end = true;
            }
            else
            {
                player = (player == 1) ? 2 : 1;
            }
        }
        else
        {
            std::cout << "WRONG CHOICE!" << std::endl;
        }
    }
}

int main()
{
    std::cout << "WELCOME IN CONNECT 4" << std::endl;
    sleep(1);
    draw();
    p_choice();
    return 0;
}
