#pragma once
#include <SFML\Graphics.hpp>
enum ITEM {
	SAVE,
	CLEAR,
	ERASE,
	PACMAN,
	ENEMY,
	COOKIE,
	WALL,
	RED,
	GREEN,
	BLUE
};
class ConstantsMap
{
protected:
	const int ICON_SIZE = 64;// Texture size	
	const float TOP_SPACE = 2;// space in the top
	const float BOTTEM_SPACE = 2;// space in the bottem
public:
	ConstantsMap();
	~ConstantsMap();
};

