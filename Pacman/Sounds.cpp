#include "Sounds.h"



Sounds::Sounds()
{
	buffer.loadFromFile("buttom.ogg");
	buttom.setBuffer(buffer);
	buffer1.loadFromFile("welcome.ogg");
	welcome.setBuffer(buffer1);
	buffer2.loadFromFile("bye.wav");
	bye.setBuffer(buffer2);
	Background.openFromFile("Background_sound.ogg");
	Background.play();
	Background.setLoop(true);
}


Sounds::~Sounds()
{
}
