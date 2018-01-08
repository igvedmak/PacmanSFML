#include "Painter.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
unsigned int size;


int mainMap(int argc, char *argv[])
{
	//sf::Music music;
	//if (!music.openFromFile("dingdingdong.ogg"))
	//	return -1; // error
	//music.play();
	//music.setLoop(true);
	if (std::ifstream("level.txt")) {
		std::ifstream file("level.txt"); //hold path
		std::string line; //string for every line
		getline(file, line);
		size = atoi(line.c_str());
		Painter{ "icons.jpg", "level.txt" , size }.run();// Start running the painter
	}
	else {
		cout << "input the size of the map: " << endl;
		cin >> size;
		Painter{ "icons.jpg", "level.txt" , size }.run();// Start running the painter
	}
	return EXIT_SUCCESS;
}
