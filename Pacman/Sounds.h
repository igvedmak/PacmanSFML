#pragma once
#include "Constants.h"
class Sounds
{
public:
	Sounds();
	~Sounds();
	sf::SoundBuffer buffer;
	sf::Sound buttom;
	sf::SoundBuffer buffer1;
	sf::Sound welcome;
	sf::SoundBuffer buffer2;
	sf::Sound bye;
	sf::Music Background;
	bool muted = false;
};

