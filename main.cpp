#include <iostream>
#include <cstdio>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <windows.h>
#include <conio.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;


void load_main_menu(card played_card,player jatekos,int card_id);


void choose_color(int color_id)
{
    //system("cls");

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "válassz színt :\n\n";
    for (int i = 1; i<5; i++)
    {
        if (i==color_id)
        {
            cout << " >";
        }
        else
            cout << "  ";
        switch (i)
        {
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
            break;
        }
        cout <<  "██████";
        SetConsoleTextAttribute(hConsole, 7);

    }
    cout << endl<<endl;
//    for {}
}

void draw_card(player &jatekos,int db,deck &main_deck)
{
    card drawed_card;
    for (int i = 0; i < db; i++)
    {
        drawed_card = main_deck.draw();
        jatekos.add_card(drawed_card);

    }
    //jatekos.print_hand();

}

int next_player(int player_id)
{

    player_id=player_id+1;
    if (player_id>1)
    {
        player_id=0;
    }
    return player_id;
}

void rulez(player *jatekos,int card_id,int *player_id,deck &main_deck,card &played_card)
{
    card temp_card =played_card;
    int color_id=1;
    int keyinput=0;
    player temp_jatekos = jatekos[*player_id];
    played_card=jatekos[*player_id].drop_card(card_id);
    cout << "\nLap lerakás: " << played_card << endl;
    switch (played_card.number)
    {
    case 10: //+2
    {
        //next_player(player_id);
        draw_card(jatekos[next_player(*player_id)],2,main_deck);
        cout << jatekos[next_player(*player_id)].get_name() << " húz két lapot\n";
        break;
    }

    case 11: //kimaradas
    {
        *player_id=next_player(*player_id);
        cout << jatekos[*player_id].get_name() << " kimarad egy körből\n";
        break;
    }
    case 12:
        //cout << " |A kor megfordul| ";
        break;
    case 13:
    {
        load_main_menu(temp_card,temp_jatekos,card_id);
        choose_color(color_id);
        while(keyinput!=13)
        {

            switch((keyinput=getch()))
            {
            case KEY_LEFT:
            {
                color_id--;
                if (color_id<1)
                    color_id=3;
                load_main_menu(temp_card,temp_jatekos,card_id);
                choose_color(color_id);
                break;
            }
            case KEY_RIGHT:
            {
                color_id++;
                if (color_id==5)
                    color_id=1;
                load_main_menu(temp_card,temp_jatekos,card_id);
                choose_color(color_id);
                break;
            }
            default:
                break;
            }
        }

        played_card.set_color((CARD_TYPE)color_id);
        break;
    }
    case 14:
    {
        load_main_menu(temp_card,temp_jatekos,card_id);
        choose_color(color_id);
        while(keyinput!=13)
        {

            switch((keyinput=getch()))
            {
            case KEY_LEFT:
            {
                color_id--;
                if (color_id<0)
                    color_id=3;
                load_main_menu(temp_card,temp_jatekos,card_id);
                choose_color(color_id);
                break;
            }
            case KEY_RIGHT:
            {
                color_id++;
                if (color_id==4)
                    color_id=0;
                load_main_menu(temp_card,temp_jatekos,card_id);
                choose_color(color_id);
                break;
            }
            default:
                break;
            }
        }
        played_card.set_color((CARD_TYPE)color_id);
        draw_card(jatekos[next_player(*player_id)],4,main_deck);
        cout << jatekos[next_player(*player_id)].get_name() << " húz négy lapot\n";
        break;
    }
    default:
        //cout << " | ";
        break;
    }



    if(jatekos[*player_id].get_size() == 1)
        cout << "UNO";
    while (_getch()!=13);
    *player_id=next_player(*player_id);

}

void load_main_menu(card played_card,player jatekos,int card_id)
{

    system("cls");
    cout << "\n Legfelső kártya :\n\n" ;
    played_card.get_image();
    cout << "\n kártyáid ("<< jatekos.get_size() <<"):" <<"\n\n" ;
    jatekos.get_hand_image(card_id);


}

void loading()
{
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".\n";
    Sleep(500);
}

int main()
{
    setlocale(LC_ALL, "hu_HU.utf8");

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /*for (int i = 0; i<=254;i++){
            SetConsoleTextAttribute(hConsole, i);
        cout << i<<'\n';
    };*/



    deck main_deck;
    card drawed_card;
    card played_card;
    string temp_string ;
    int keyinput;
    player jatekos[2];

    int player_id = 0;
    int card_id = 0;
    // cout << card;
    //printf("%c",temp_string[0]);
    cout <<"Adja meg az eslő játékos nevét: ";
    cin >>  temp_string;
    jatekos[0].set_name(temp_string);
    do
    {
        cout << "\nAdja meg a második játékos nevét: ";
        cin >>  temp_string;
        if (jatekos[0].get_name()==temp_string)
        {
            SetConsoleTextAttribute(hConsole, 64);
            cout << " !A két játékos neve nem egyezhet meg! \n\n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    while(jatekos[0].get_name()==temp_string);
    jatekos[1].set_name(temp_string);



    main_deck.create();
    //main_deck.print_deck();
    main_deck.shuffle();
    //main_deck.print_deck();



    cout << "Lapok kiosztása";
    loading();

    for (int i = 0; i < 7; i++)
    {
        drawed_card = main_deck.draw();
        jatekos[0].add_card(drawed_card);
        drawed_card = main_deck.draw();
        jatekos[1].add_card(drawed_card);
    }



    cout << "Lapok kiosztva!\n";

    do
    {
        drawed_card = main_deck.draw();
        if (drawed_card.type == BLACK)
        {
            cout << "A " <<  drawed_card << " lappal nem lehet kezdeni.\n lap visszatétele,újrakeverés majd húzás.\n\n";
            main_deck.add_card(drawed_card);
            main_deck.shuffle();
        }
    }
    while(drawed_card.type == BLACK);
    played_card = drawed_card;
    cout << "\n kezdőkártya :\n\n" ;
    played_card.get_image();

    //jatekos1.print_hand();
    //jatekos2.print_hand();
    //main_deck.print_deck();
    cout <<  "A játék megkezdéséhez nyomj egy entert!\n";
    while (_getch()!=13);

    do
    {
        system("cls");
        cout  << jatekos[player_id].get_name() << " következik, " << jatekos[player_id].get_name() <<" nyomj egy entert!\n";
        while (_getch()!=13);
        card_id=0;
        load_main_menu(played_card,jatekos[player_id],card_id);
        //cout << main_deck.get_size();


        do
        {
            keyinput=0;
            while(keyinput!=13 && keyinput!=KEY_DOWN)
            {

                switch((keyinput=getch()))
                {
                case KEY_LEFT:
                {
                    card_id--;
                    if (card_id<0)
                        card_id=jatekos[player_id].get_size()-1;
                    load_main_menu(played_card,jatekos[player_id],card_id);
                    break;
                }
                case KEY_RIGHT:
                {
                    card_id++;
                    if (jatekos[player_id].get_size()==card_id)
                        card_id=0;
                    load_main_menu(played_card,jatekos[player_id],card_id);
                    break;
                }
                case KEY_DOWN:
                {
                    draw_card(jatekos[player_id],1,main_deck);
                    break;
                }
                default:
                    break;
                }
            }
            if (jatekos[player_id].get_main_card(card_id)!=played_card )
                cout <<"hibas lap";
        }
        while(jatekos[player_id].get_main_card(card_id)!=played_card && keyinput!=KEY_DOWN);
        if(keyinput!=KEY_DOWN)
        {
            rulez(jatekos,card_id,&player_id,main_deck,played_card);
        }
        else
        {
            load_main_menu(played_card,jatekos[player_id],jatekos[player_id].get_size()-1);
            cout << "A huzott kartya: " << jatekos[player_id].get_main_card(jatekos[player_id].get_size()-1);
            player_id=next_player(player_id);

            while (_getch()!=13);
        }
        //while (_getch()!=13);

        //while (_getch()!=13);
    }
    while(jatekos[0].get_size()!=0 && jatekos[1].get_size()!=0 );






    return 0;
}
