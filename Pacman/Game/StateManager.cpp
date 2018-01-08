#include "StateManager.h"
#include "State.h"

StateManager::StateManager()
{
	mWindow.create(sf::VideoMode(650, 650),"Pacman",sf::Style::Close|sf::Style::Titlebar);
	mWindow.setFramerateLimit(60);//60 fps max
	mFont.loadFromFile("Endless Wall.ttf");
	mPack.Font = &mFont;
	mPack.Manager = this;
	mPack.Window = &mWindow;
}

StateManager::~StateManager()
{
	popTop(mStates.size());
	clearStacks();
}

void StateManager::popTop(int amount)
{
	amount = std::min(amount, static_cast<int>(mStates.size()));
	for(int i=0; i < amount ;++i)
	{
		mClear.push(mStates.top());
		mStates.pop();
	}
}

void StateManager::leaveBottom(int amount)
{
	popTop(mStates.size() - amount);
}

void StateManager::pushTop(State * state)
{
	mStates.push(state);
}

void StateManager::gameRun()
{
	while(!mStates.empty())
	{
		mStates.top()->run(mPack);
		clearStacks();
	}
}

void StateManager::clearStacks()
{
	while(!mClear.empty())
	{
		delete mClear.top();
		mClear.pop();
	}
}
