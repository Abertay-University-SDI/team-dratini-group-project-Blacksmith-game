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

	knobold.setPosition(600,600);
	knobold.setRadius(20);
	knobold.setFillColor(sf::Color::Red);


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

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		knobold.move(knobDirection * knobSpeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		knobold.move(-knobDirection * knobSpeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		knobold.move(0, -knobDirection * knobSpeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		knobold.move(0, knobDirection * knobSpeed * dt);
	}



}

// Update game objects
void Level::update(float dt)
{
	gobPos = gobsmith.getPosition();
	knobPos = knobold.getPosition();


	

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

	if (knobPos.x + knobold.getGlobalBounds().width > window->getSize().x)
	{
		knobold.setPosition(window->getSize().x - 40, knobPos.y);
	}

	else if (knobPos.x < 0)
	{
		knobold.setPosition(0, knobPos.y);
	}

	else if (knobPos.y + knobold.getGlobalBounds().height > window->getSize().y)
	{
		knobold.setPosition(knobPos.x, window->getSize().y - 40);
	}

	else if (knobPos.y < 0)
	{
		knobold.setPosition(knobPos.x, 0);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(gobsmith);
	window->draw(knobold);

	endDraw();
}

