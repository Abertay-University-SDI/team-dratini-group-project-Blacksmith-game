#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

	sf::CircleShape gobsmith;
	sf::CircleShape knobold;

	float returnGobSpeed()
	{
		return gobSpeed;
	}

	void setGobSpeed(float myGobSpeed)
	{
		gobSpeed = myGobSpeed;
	}

	float returnKnobSpeed()
	{
		return knobSpeed;
	}

	void setKnobSpeed(float myKnobSpeed)
	{
		knobSpeed = myKnobSpeed;
	}

	int returnGobDirection()
	{
		return gobDirection;
	}

	void setGobDirection(int myGobDirection)
	{
		gobDirection = myGobDirection;
	}

	int returnKnobDiretion()
	{
		return knobDirection;
	}

	void setKnobDirection(int myKnobDirection)
	{
		knobDirection = myKnobDirection;
	}


private:
	float gobSpeed = 400;
	float knobSpeed = 400;
	int gobDirection = 1;
	int knobDirection = 1;
	sf::Vector2f gobPos;
	sf::Vector2f knobPos;



	// Default functions for rendering to the screen.
	

	// Default variables for level class.
	
};