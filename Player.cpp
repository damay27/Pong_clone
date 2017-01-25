//Created by Daniel May

#include "Player.hpp"
#include <System.hpp>


using namespace sf;



//Constructor passes all inputs to the base class
Player::Player(int xPos, int yPos, float width, float hieght, Color c, int collisionTop, int collisionBottom): Entity(xPos, yPos, width, hieght, c, collisionTop, collisionBottom)
{

}




//Function to controle the players paddle movement
void Player::move()
{

	
	//Remember that sfml has a coordinate system with the y axis inverted
	

	//If the user has pressed the up arrow key
	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		//Decrease y by seven. This moves the position up 7 pixels
		y-=7;

		//Check and see if y is less than the minimum allowed position
		if(y<posMin)
		{
			//If so set y to the minimum position
			y=posMin;
		}
	}	
	//Else check and see if the user has pressed the down arrow key
	else if(Keyboard::isKeyPressed(Keyboard::Down))
	{
		//Increase the y value by 7. This moves the position down 7 pixels
		y+=7;

		//Check and see if y is greater than the maximum allowed position
		if(y>posMax)
		{
			//If so set y to the maximum allowed position
			y=posMax;
		}
	}

	//Set the position of the rectangle to x and y
	rect.setPosition(x,y);

}


//destructor
Player::~Player()
{

}
