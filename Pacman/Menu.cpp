#include "Menu.h"
using std::cout;


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Endless Wall.ttf"))
		cout << "error";

	menu[PLAY_PLACE].setFont(font);
	menu[PLAY_PLACE].setColor(sf::Color::Green);
	menu[PLAY_PLACE].setString("Play");
	menu[PLAY_PLACE].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[MAP_MAKER].setFont(font);
	menu[MAP_MAKER].setColor(sf::Color::White);
	menu[MAP_MAKER].setString("MapMaker");
	menu[MAP_MAKER].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[SCORE_BOARD].setFont(font);
	menu[SCORE_BOARD].setColor(sf::Color::White);
	menu[SCORE_BOARD].setString("ScoreBoard");
	menu[SCORE_BOARD].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[EXIT].setFont(font);
	menu[EXIT].setColor(sf::Color::White);
	menu[EXIT].setString("Exit");
	menu[EXIT].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
	selectedItemIndex = PLAY_PLACE;

	menu[MUTE].setFont(font);
	menu[MUTE].setColor(sf::Color::White);
	menu[MUTE].setString("Mute");
	menu[MUTE].setPosition(sf::Vector2f(0, 0));
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		window.draw(menu[i]);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
	saveChoose = selectedItemIndex;
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
	saveChoose = selectedItemIndex;
}

bool Menu::getSelection(int indexXwindow, int indexYwindow, int indexXmouse, int indexYmouse)
{
	whatSelected = checkPlace(indexXwindow, indexYwindow, indexXmouse, indexYmouse);
	if (whatSelected == saveChoose || whatSelected == -1)
		return true;
	else
		samePlace = false;
	switch (whatSelected)
	{
	case PLAY_PLACE:
		moveIt(saveChoose, whatSelected, selectedItemIndex);
		break;
	case MAP_MAKER:
		moveIt(saveChoose, whatSelected, selectedItemIndex);
		break;
	case SCORE_BOARD:
		moveIt(saveChoose, whatSelected, selectedItemIndex);
		break;
	case EXIT:
		moveIt(saveChoose, whatSelected, selectedItemIndex);
		break;
	case MUTE:
		moveIt(saveChoose, whatSelected, selectedItemIndex);
		break;
	}
	saveChoose = selectedItemIndex;
	return samePlace;
}

int Menu::getPlace()
{
	return saveChoose;
}

void Menu::moveIt(int saveChoose, int whatSelected, int & selectedItemIndex)
{
	if (saveChoose > whatSelected || saveChoose < whatSelected)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex = whatSelected;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

places Menu::checkPlace(int indexXwindow, int indexYwindow, int indexXmouse, int indexYmouse)
{
	if (indexXmouse - indexXwindow > menu[PLAY_PLACE].getPosition().x)
	{
		if (indexXmouse - indexXwindow < 390 && indexYmouse - indexYwindow > (menu[PLAY_PLACE].getPosition().y + ADDLOW) && indexYmouse - indexYwindow < (menu[PLAY_PLACE].getPosition().y + ADDHIGH))
			return PLAY_PLACE;
		if (indexXmouse - indexXwindow < 470 && indexYmouse - indexYwindow > (menu[MAP_MAKER].getPosition().y + ADDLOW) && indexYmouse - indexYwindow < (menu[MAP_MAKER].getPosition().y + ADDHIGH))
			return MAP_MAKER;
		if (indexXmouse - indexXwindow < 500 && indexYmouse - indexYwindow > (menu[SCORE_BOARD].getPosition().y + ADDLOW) && indexYmouse - indexYwindow < (menu[SCORE_BOARD].getPosition().y + ADDHIGH))
			return SCORE_BOARD;
		if (indexXmouse - indexXwindow < 380 && indexYmouse - indexYwindow > (menu[EXIT].getPosition().y + ADDLOW) && indexYmouse - indexYwindow < (menu[EXIT].getPosition().y + ADDHIGH))
			return EXIT;
	}
	if (indexXmouse - indexXwindow >= 0 && indexXmouse - indexXwindow < 70 && indexYmouse - indexYwindow >= 0 && indexYmouse - indexYwindow < 70)
		return MUTE;
	return FAIL;
}
