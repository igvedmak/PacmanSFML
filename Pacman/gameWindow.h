#pragma once
#include "Constants.h"
#include "Menu.h"
#include "Map/Painter.h"
#include "Sounds.h"
class gameWindow
{
public:
	gameWindow();
	~gameWindow();
	void run();
	void makeChoose();
private:
	sf::RenderWindow window;
	sf::Texture backgroundPic;
	/*
	sf::SoundBuffer buffer;
	sf::Sound buttom;
	sf::SoundBuffer buffer1;
	sf::Sound welcome;
	sf::SoundBuffer buffer2;
	sf::Sound bye;
	sf::Music music;*/
	sf::Sprite background;
	std::unique_ptr<Menu> menu;
	//bool muted = false;
	std::unique_ptr<Sounds> sound;
};

