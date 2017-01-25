//Created by Daniel May

#include "Ai.hpp"
#include <cmath>
#include <iostream>



//Define the constructor. All input values are passed to the parent constructor
Ai::Ai(int xPos, int yPos, float width, float hieght, Color c, int collisionTop, int collisionBottom): Entity(xPos, yPos, width, hieght, c, collisionTop, collisionBottom)
{
	
}

//Define the destructor
Ai::~Ai()
{

}

//Define the move function
void Ai::move(Vector2f ballPos, int ballHieght)
{	
	//Get the size of the paddle from the rectangle object inherited from Enity
	Vector2f size=rect.getSize();

	//Compute the location of the y center of the paddle in world space
	int paddleCenter=y+(size.y/2);

	//Compute the location of the y center of the paddle in world space
	int ballCenter=ballPos.y+(ballHieght/2);

	/*
	If the ball is ball center is bellow the paddle center
	(paddleCenter-ballCenter)<0) and is more than 1/3 of the 
	total paddle length away from the center abs(paddleCenter-
	ballCenter)>(.35*size.y)
	*/
	if( ( (paddleCenter-ballCenter)<0 ) & ( abs(paddleCenter-ballCenter)> (.3*size.y) ) )
	{
		
		//Move the rectangle 7 pixles which moves it down the screen
		rect.move(0,7);
		//Adjust the value of y
		y+=7;
		//Check if it is excceding the the max y position
		if(y>posMax)
		{
			//If so reset y to the max position
			y=posMax;
			//And move the rectangle to the max y position
			rect.setPosition(x,posMax);
		}

	}
	/*
	If the ball is ball center is above the paddle center
	(paddleCenter-ballCenter)>0) and is more than 1/3 of the 
	total paddle length away from the center abs(paddleCenter-
	ballCenter)>(.35*size.y)
	*/
	else if( ( (paddleCenter-ballCenter)>0 ) & ( abs(paddleCenter-ballCenter)> (.3*size.y) ) )
	{ 
		//Move the rectangle -7 pixels which moves it up the
		//screen
		rect.move(0,-7);

		//Adjust value of y
		y-=7;

		//Check if it is excceding the min y position
		if(y<posMin)
		{

			//If so reset y to the min position
			y=posMin;
			//And move the rectangle to the min y position
			rect.setPosition(x,posMin);
		}

	}

}



