#pragma once
#include "SFML\Graphics.hpp"
#include <SFML/Audio.hpp>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
#include <memory>
#define MAX_NUMBER_OF_ITEMS 5
using std::cin;
using std::cout;
using std::endl;

enum places
{
	PLAY_PLACE,
	MAP_MAKER,
	SCORE_BOARD,
	EXIT,
	MUTE,
	FAIL = -1,
	ADDHIGH = 60,
	ADDLOW = 35
};
class Constants
{
public:
	Constants();
	~Constants();
};

