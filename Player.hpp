//Created by Daniel May

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

//Class to handle the players paddle that inherits from Entity
class Player: public Entity
{

	//All member variables are inherited from Entity	

	public:
	
	//Declare member functions and constructor/destructor
	 
	Player(int xPos, int yPos, float width, float hieght, Color c, int collisionTop, int collisionBottom);

	~Player();

	void move();

};

#endif
