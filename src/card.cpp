#include "card.h"
#include <windows.h>
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


card::card() : number(0), type(BLACK)
{

}

card::card(int num, CARD_TYPE type_) : number(num), type(type_)
{

}

bool card::operator==(card const& other) const
{
    return number == other.number || type == other.type || type == BLACK || other.type == BLACK;

}


bool card::operator!=(card const& other) const
{
    return !(*this == other);
}


std::ostream & operator<<(std::ostream & out, card const & temp_card)
{

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (temp_card.type)
    {
    case BLACK:
    {
        SetConsoleTextAttribute(hConsole, 240);
        //out << " Fekete";
        break;
    }
    case RED:
    {
        SetConsoleTextAttribute(hConsole, 4);
        //out << " Piros";
        break;
    }
    case GREEN:
    {
        SetConsoleTextAttribute(hConsole, 10);
        //out << " Zold";
        break;
    }
    case BLUE:
    {
        SetConsoleTextAttribute(hConsole, 3);
        //out << " Kek";
        break;
    }
    case YELLOW:
    {
        SetConsoleTextAttribute(hConsole, 6);
        //out << " Sarga";
        break;
    }
    default:
        out << "N/A";
        break;
    }

    switch (temp_card.number)
    {
    case 10:
        out << " |+2 huzos| ";
        break;
    case 11:
        out << " |A kovetkezo jatekos kimarad| ";
        break;
    case 12:
        out << " |A kor megfordul| ";
        break;
    case 13:
        out << " |Valassz egy szin| ";
        break;
    case 14:
        out << " |Valassz egy szin es +4| ";
        break;
    default:
        out << " |"<<(int)temp_card.number<< "| ";
        break;
    }



    SetConsoleTextAttribute(hConsole, 7);
    return out;
}

void card::get_image()
{



    /*string null_card="┌─────────┐\n│ ██████╗ │\n│██╔══███╗│\n│██║   ██║│\n│██║  ███║│\n│╚██████╔╝│\n│ ╚═════╝ │\n└─────────┘\n";
    string one_card="┌─────────┐\n│   ██╗   │\n│  ███║   │\n│  ╚██║   │\n│   ██║   │\n│   ╚═╝   │\n│         │\n└─────────┘\n";
    string two_card="┌─────────┐\n│ ██████╗ │\n│ ╚════██╗│\n│  █████╔╝│\n│ ██╔═══╝ │\n│ ███████╗│\n│ ╚══════╝│\n└─────────┘\n";
    string three_card="┌─────────┐\n│ ██████╗ │\n│ ╚════██╗│\n│  █████╔╝│\n│  ╚═══██╗│\n│ ██████╔╝│\n│ ╚═════╝ │\n└─────────┘\n";
    string four_card="┌─────────┐\n│ ██╗  ██╗│\n│ ██║  ██║│\n│ ███████║│\n│ ╚════██║│\n│      ██║│\n│      ╚═╝│\n└─────────┘\n";
    string five_card="┌─────────┐\n│ ███████╗│\n│ ██╔════╝│\n│ ███████╗│\n│ ╚════██║│\n│ ███████║│\n│ ╚══════╝│\n└─────────┘\n";
    string six_card="┌─────────┐\n│ ██████╗ │\n│██╔════╝ │\n│███████╗ │\n│██╔═══██╗│\n│╚██████╔╝│\n│ ╚═════╝ │\n└─────────┘\n";
    string seven_card="┌─────────┐\n│ ███████╗│\n│ ╚════██║│\n│     ██╔╝│\n│    ██╔╝ │\n│    ██║  │\n│    ╚═╝  │\n└─────────┘\n";
    string eight_card="┌─────────┐\n│  █████╗ │\n│ ██╔══██╗│\n│ ╚█████╔╝│\n│ ██╔══██╗│\n│ ╚█████╔╝│\n│  ╚════╝ │\n└─────────┘\n";
    string nine_card="┌─────────┐\n│  █████╗ │\n│ ██╔══██╗│\n│ ╚██████║│\n│  ╚═══██║│\n│  █████╔╝│\n│  ╚════╝ │\n└─────────┘\n";
    string x_card="┌─────────┐\n│ ██████╗ │\n│██╔═████╗│\n│██║██╔██║│\n│████╔╝██║│\n│╚██████╔╝│\n│ ╚═════╝ │\n└─────────┘\n";
    string plustwo_card="┌─────────┐\n│ █       │\n│███ ████ │\n│ █     █ │\n│    ████ │\n│    █    │\n│    ████ │\n└─────────┘\n";
    string plusfour_card="┌─────────┐\n│ █       │\n│███ █  █ │\n│ █  █  █ │\n│    ████ │\n│       █ │\n│       █ │\n└─────────┘\n";
    string color_card="┌─────────┐\n│░░░░░░░░░│\n│░░░░░░░░░│\n│░░░UNO░░░│\n│░░░░░░░░░│\n│░░░░░░░░░│\n│░░░░░░░░░│\n└─────────┘\n";
    string reverse_card="┌─────────┐\n│ ██████╗ │\n│██╔═══██╗│\n│██║██╗██║│\n│██║██║██║│\n│╚█║████╔╝│\n│ ╚╝╚═══╝ │\n└─────────┘\n";*/


    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



    for(int i = 0 ; i<8; i++)
    {
        cout << " ";
        set_console_card_color();
        cout << get_image_row(i) <<'\n';
        SetConsoleTextAttribute(hConsole, 7);
    }
    cout << "\n";




}


string card::get_image_row(int row)
{

    string cards_images[15][8] =
    {
        {"┌─────────┐","│ ██████╗ │","│██╔══███╗│","│██║   ██║│","│██║  ███║│","│╚██████╔╝│","│ ╚═════╝ │","└─────────┘"},
        {"┌─────────┐","│   ██╗   │","│  ███║   │","│  ╚██║   │","│   ██║   │","│   ██║   │","│   ╚═╝   │","└─────────┘"},
        {"┌─────────┐","│ ██████╗ │","│ ╚════██╗│","│  █████╔╝│","│ ██╔═══╝ │","│ ███████╗│","│ ╚══════╝│","└─────────┘"},
        {"┌─────────┐","│ ██████╗ │","│ ╚════██╗│","│  █████╔╝│","│  ╚═══██╗│","│ ██████╔╝│","│ ╚═════╝ │","└─────────┘"},
        {"┌─────────┐","│ ██╗  ██╗│","│ ██║  ██║│","│ ███████║│","│ ╚════██║│","│      ██║│","│      ╚═╝│","└─────────┘"},
        {"┌─────────┐","│ ███████╗│","│ ██╔════╝│","│ ███████╗│","│ ╚════██║│","│ ███████║│","│ ╚══════╝│","└─────────┘"},
        {"┌─────────┐","│ ██████╗ │","│██╔════╝ │","│███████╗ │","│██╔═══██╗│","│╚██████╔╝│","│ ╚═════╝ │","└─────────┘"},
        {"┌─────────┐","│ ███████╗│","│ ╚════██║│","│     ██╔╝│","│    ██╔╝ │","│    ██║  │","│    ╚═╝  │","└─────────┘"},
        {"┌─────────┐","│  █████╗ │","│ ██╔══██╗│","│ ╚█████╔╝│","│ ██╔══██╗│","│ ╚█████╔╝│","│  ╚════╝ │","└─────────┘"},
        {"┌─────────┐","│  █████╗ │","│ ██╔══██╗│","│ ╚██████║│","│  ╚═══██║│","│  █████╔╝│","│  ╚════╝ │","└─────────┘"},
        {"┌─────────┐","│ █╗      │","│███╗████ │","│╚█╔╝   █ │","│ ╚╝ ████ │","│    █    │","│    ████ │","└─────────┘"},
        {"┌─────────┐","│ ██████╗ │","│██╔═████╗│","│██║██╔██║│","│████╔╝██║│","│╚██████╔╝│","│ ╚═════╝ │","└─────────┘"},
        {"┌─────────┐","│ ██████╗ │","│██╔═══██╗│","│██║██╗██║│","│██║██║██║│","│╚█║████╔╝│","│ ╚╝╚═══╝ │","└─────────┘"},
        {"┌─────────┐","│░░░░░░░░░│","│░░░░░░░░░│","│░░░UNO░░░│","│░░░░░░░░░│","│░░░░░░░░░│","│░░░░░░░░░│","└─────────┘"},
        {"┌─────────┐","│ █╗      │","│███╗█╗ █╗│","│╚█╔╝█║ █║│","│ ╚╝ ████║│","│    ╚══█║│","│       ╚╝│","└─────────┘"},
    };

   // cout << cards_images[number][row].size();
    return cards_images[number][row];
}

void card::set_color(CARD_TYPE color){
    type=color;
}
int card::get_value(){
    return number;
}

void card::set_console_card_color()

{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (type)
    {
    case BLACK:
    {
        SetConsoleTextAttribute(hConsole, 15);
        //out << " Fekete";
        break;
    }
    case RED:
    {
        SetConsoleTextAttribute(hConsole, 79);
        //out << " Piros";
        break;
    }
    case GREEN:
    {
        SetConsoleTextAttribute(hConsole, 32);
        //out << " Zold";
        break;
    }
    case BLUE:
    {
        SetConsoleTextAttribute(hConsole, 31);
        //out << " Kek";
        break;
    }
    case YELLOW:
    {
        SetConsoleTextAttribute(hConsole, 96);
        //out << " Sarga";
        break;
    }
    default:
        cout << "N/A";
        break;
    }
}
