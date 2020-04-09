#ifndef PLAYER_H
#define PLAYER_H

#include "player.h"
#include <vector>
using namespace std;


class player
{
	public:
		player()
		{}
		~player()
		{}
		void set_name(string name_);
		string get_name();
		void get_hand_image(int card_id);
		void add_card(card temp_card);
		void print_hand();
		card drop_card(unsigned pos);
		int get_size();
		card get_main_card(int card_id);


	private:

        string name;
		vector <card> hand;

};


#endif
