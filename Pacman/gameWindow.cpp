#include "gameWindow.h"
#include "Game/StateManager.h"
#include "Game\MenuState.h"
#include "Menu.h"
#include "Game\ScoreState.h"
unsigned int sizeRow;
unsigned int sizeCol;
gameWindow::gameWindow() : window(sf::VideoMode(650, 650), "work")
{
	menu = std::make_unique<Menu>((float)window.getSize().x, (float)window.getSize().y);
	sound = std::make_unique<Sounds>();
	backgroundPic.loadFromFile("pacmoon.jpg", sf::IntRect(0, 0, 650, 650));
	/*
	buffer.loadFromFile("buttom.ogg");
	buttom.setBuffer(buffer);
	buffer1.loadFromFile("welcome.ogg");
	welcome.setBuffer(buffer1);
	buffer2.loadFromFile("bye.wav");
	bye.setBuffer(buffer2);
	music.openFromFile("Background_sound.ogg");
	music.play();
	music.setLoop(true);*/
	background.setTexture(backgroundPic);
}


gameWindow::~gameWindow()
{
}

void gameWindow::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
				/*
			case::sf::Event::Resized:
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
				break;*/
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu->MoveUp();
					sound->buttom.play();
					//buttom.play();
					break;

				case sf::Keyboard::Down:
					menu->MoveDown();
					sound->buttom.play();
					//buttom.play();
					break;
				case sf::Keyboard::Return: // enter key
					sound->welcome.play();
					//welcome.play();
					makeChoose();
					break;
				}
			case sf::Event::MouseButtonReleased:
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left:
					menu->getSelection(window.getPosition().x, window.getPosition().y, sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
					if (menu->saveChoose >= PLAY_PLACE && menu->saveChoose <= MUTE)
					{
						sound->welcome.play();
						//welcome.play();
						makeChoose();
					}	
					break;
				}
				case sf::Event::MouseMoved:
					if(!(menu->getSelection(window.getPosition().x, window.getPosition().y, sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
						sound->buttom.play();
						//buttom.play();
					break;
			}
		}
		window.clear();
		window.draw(background);
		menu->draw(window);
		window.display();
	}
}

void gameWindow::makeChoose()
{
	StateManager app;
	switch (menu->getPlace())
	{
	case PLAY_PLACE:
		app.pushTop(new MenuState);
		app.gameRun();
		break;
	case MAP_MAKER:
		if (std::ifstream("level.txt")) {
			std::ifstream file("level.txt"); //hold path
			std::string line; //string for every line
			getline(file, line);
			sizeRow = atoi(line.c_str());
			getline(file, line);
			sizeCol = atoi(line.c_str());
			Painter{ "Map/icons.jpg", "level.txt" , sizeRow, sizeCol }.run();// Start running the painter
		}
		else {
			cout << "input the size of row of the map: " << endl;
			cin >> sizeRow;
			cout << "input the size of col of the map: " << endl;
			cin >> sizeCol;
			Painter{ "Map/icons.jpg", "level.txt" , sizeRow, sizeCol }.run();// Start running the painter
		}
		break;
	case SCORE_BOARD:
		break;
	case EXIT:
		sound->bye.play();
		//bye.play();
		window.close();
		break;
	case MUTE:
		if (!sound->muted)
		{
			sound->Background.pause();
			//music.pause();
			sound->muted = true;
			//muted = true;
		}
		else
		{
			sound->Background.play();
			sound->Background.setLoop(true);
			sound->muted = false;
		}
		break;
	}
}
