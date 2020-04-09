/* Pakli tartalma:
	19 kék kártya: 0-9;
	19 zöld kártya: 0-9;
	19 piros kártya: 0-9;
	19 sárga kártya: 0-9
	„8 Húzz kettőt!” kártya: 2 kék, 2 zöld, 2 piros, 2 sárga
	„8 Fordulj! kártya”: 2 kék, 2 zöld, 2 piros, 2 sárga
	„8 Ugorj!” kártya: 2 kék, 2 zöld, 2 piros, 2 sárga
	„4 Színválasztó” kártya;
	„4 Húzz négyet! Színválasztó” kártya
*/


/*
01234 =  "szín" és a szín
0 = "szín"
1 = piros
2 = zöld
3 = kék
4 = sárga
*/




#define DECK_SIZE 108

#include "deck.h"
#include "card.h"
#include <iostream>
#include <cstdlib>
#include  <ctime>
#include <windows.h>
using namespace std;

deck::deck()
{
    ptr_deck = new card[DECK_SIZE];
    size = 0;


}

void deck::create()
{


    for (int num = 0; num <=14; num++)
    {
        if (num <= 12)
        {
            for (int col = RED; col <= YELLOW; col++)
            {

                for (int x=0 ; x<(num==0?1:2); x++)
                {
                    ptr_deck[size].number = num;
                    ptr_deck[size].type = static_cast<CARD_TYPE>(col);
                    size++;
                }
            }
        }
        else
        {
            for (int x=0; x<4; x++)
            {
                ptr_deck[size].number = num;
                ptr_deck[size].type = static_cast<CARD_TYPE>(BLACK);
                size++;

            }

        }

    }

}



void deck::shuffle()
{
      cout << "Pakli keverése";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".\n";
    Sleep(500);

    srand((unsigned int)time(NULL));
    int pos;
    int round = (rand() % 5) + 1;
    card temp_card;
    for(int j= 0; j<round; j++)
    {
        for (int i = 0; i < size; i++)
        {
            {
                do
                {
                    pos = rand() % size;
                }
                while(i==pos);
                temp_card = ptr_deck[pos];
                ptr_deck[pos]= ptr_deck[i];
                ptr_deck[i] = temp_card;
            }
        }
    }
    cout << "Pakli megkeverve!\n";

}
card deck::draw()
{
    card temp_card = ptr_deck[size - 1];
    size--;
    return temp_card;
}


int deck::add_card(card temp_card)
{
    if (size < DECK_SIZE)
    {
        ptr_deck[size] = temp_card;
        size++;
        return 0;
    }
    else
        return -1;
}


void deck::print_deck()
{
    for (int i = 0; i < size; i++)
    {
        cout << i << ":\t" << ptr_deck[i]<< "\n";
    }
}

void deck::copy(const deck & other)
{
    size = other.size;
    ptr_deck = new card[size];
    for (int i = 0; i < size; i++)
    {
        ptr_deck[i] = other.ptr_deck[i];
    }
}


int deck::get_size()
{
    return size;
}


