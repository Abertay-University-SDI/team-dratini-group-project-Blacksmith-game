#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects

	gobsmith.setPosition(100, 100);
	gobsmith.setRadius(20);
	gobsmith.setFillColor(sf::Color::Green);



}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		gobsmith.move(gobDirection * gobSpeed * dt,0 );
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		gobsmith.move(-gobDirection * gobSpeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		gobsmith.move(0,-gobDirection * gobSpeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		gobsmith.move(0,gobDirection * gobSpeed * dt);
	}



}

// Update game objects
void Level::update(float dt)
{
	gobPos = gobsmith.getPosition();


	

	if (gobPos.x + gobsmith.getGlobalBounds().width > window->getSize().x)
	{
		gobsmith.setPosition(window->getSize().x -40, gobPos.y);
	}

	else if (gobPos.x < 0)
	{
		gobsmith.setPosition(0, gobPos.y);
	}

	else if (gobPos.y + gobsmith.getGlobalBounds().height > window->getSize().y)
	{
		gobsmith.setPosition(gobPos.x, window->getSize().y -40);
	}

	else if (gobPos.y < 0)
	{
		gobsmith.setPosition(gobPos.x, 0);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(gobsmith);

	endDraw();
}

