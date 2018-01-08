#pragma once
#include "Constants.h"

class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow & window);
	void MoveUp();
	void MoveDown();
	bool getSelection(int indexXwindow, int indexYwindow , int indexXmouse, int indexYmouse);
	int getPlace();
	void moveIt(int saveChoose, int whatSelected, int & selectedItemIndex);
	places checkPlace(int indexXwindow, int indexYwindow, int indexXmouse, int indexYmouse);
	bool samePlace = false;
	int saveChoose = 0;
private:
	int selectedItemIndex;	
	int whatSelected = 0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

