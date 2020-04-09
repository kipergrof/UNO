#include "card.h"
#include "player.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <iostream>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <windows.h>
#include <conio.h>

using namespace std;


void player::set_name(string name_)
{
    name=name_;
}

string player::get_name()
{
    return name;
}

void player::get_hand_image(int card_id)
{

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //cout << "help";
    //string row = "┌─────────┐";

    //out << " Fekete";
    for  (int j = 0; j<8; j++ )
    {
        //cout << j;
        for (int i = 0; i < hand.size(); i++)
        {
            //cout << hand.size() << "   " << i;
            hand[i].set_console_card_color();
            //cout << j;
            if (card_id<i)
            {
                if (j==0)
                {
                    cout << "┌─";
                }
                else if (j==7)
                {
                    cout << "└─";
                }
                else
                {
                    cout << "│ ";
                }
            }
            else if (card_id>i)
            {
                if (j==0)
                {
                    cout << "─┐";
                }
                else if (j==7)
                {
                    cout << "─┘";
                }
                else
                {
                    cout << " │";
                }
            }
            else
            {
                cout<< " " << hand[i].get_image_row(j)<< " ";
            }
        }
        cout << '\n';
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void player::add_card(card temp_card)
{
    hand.push_back(temp_card);
}

void player::print_hand()
{

    for (size_t i = 0; i < hand.size(); i++)
    {
        cout << hand[i] << endl;
    }
}



card player::drop_card(unsigned pos)
{
    card temp_card;


    //if (pos <= hand.size())

    temp_card = hand[pos];

    hand.erase(hand.begin() + pos);

    return temp_card;

}


int player::get_size()
{
    int size = static_cast<int>(hand.size());
    return size;
}


card player::get_main_card(int card_id)
{
    return hand[card_id];
}
