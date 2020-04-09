#ifndef _CARD_H_
#define _CARD_H_

#include <ostream>
#include <windows.h>
#include <iostream>
#include <string>


enum CARD_TYPE { BLACK, RED, GREEN, BLUE, YELLOW };


class card
{
public:
	int number; // 0-9 a számok, "húzz kettőt", "ugorj", "fordulj!", "színválasztó", "színválasztás húzz négyet"
	CARD_TYPE type; // 5 szín: színtelen, zöld, kék, sárga, piros

	//Egyenlőség operátor
	// Ekkor lerakható a kártya a körben
	bool operator==(card const& other) const;

	// Egyenlőtlenség operátor
	bool operator!=(card const& other) const;


	card();

	card(int num, CARD_TYPE col);
	void get_image();
	std::string get_image_row(int row);
	void set_color(CARD_TYPE color);
	int get_value();
	void set_console_card_color();
};

std::ostream& operator<<(std::ostream& out, card const& temp_card);


#endif // _CARD_H_

