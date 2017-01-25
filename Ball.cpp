//Created by Daniel May

#include "Ball.hpp"
#include <iostream>


//Consturctor initializes the base class and sets the x and y velocity to zero
//NOTE: The last parameter of the Enitity constructor adjusts the max paddleHieght
Ball::Ball(int xPos, int yPos, float paddleWidth, float paddleHieght, Color c, int collisionTop, int collisionBottom):
Entity(xPos, yPos, paddleWidth, paddleHieght, c, collisionTop, collisionBottom),
vx(0),
vy(0),
lastCollidePlayer(false)
{
	
}

//Destructor
Ball::~Ball()
{

}

//Function for movment and collision. takes the position of both paddles and their paddleHieght and paddleWidth
void Ball::move(Vector2f playerPos, Vector2f aiPos, int paddleHieght, int paddleWidth)
{

	//Move the rectangle based on the current velocity
	rect.move(vx,vy);

	//Create vector and use it to set the x and y position variables
	Vector2f pos=rect.getPosition();
	x=pos.x;
	y=pos.y;

	//Create a vector and set it equal to the size of the rectangle
	Vector2f size=rect.getSize();



	/*
	This part of the code checks collision with the bumpers
	*/


	//Check if it is outside of the y bounds
	if(y>posMax)
	{
		//If beyond the maximum y value
	
		//Set y equal to the maximum position
		y=posMax;

		//Set the rectangle position to the x and y (which equals posMax)
		rect.setPosition(x,y);		
		
		//Invert the y velocity
		vy=-vy;
	}
	//Otherwise check if the ball is less than the minimum position
	//NOTE: An else if can be used here because the ball could never be hitting both the max and min values
	else if(y<posMin)
	{
		//If beyond the minimum y value

		//Set y equal to the minimum position
		y=posMin;

		//Set the rectangle position to the x and y (which equals posMin)
		rect.setPosition(x,y);

		//Inver the y velocity
		vy=-vy;

	}




	/*
	This par of the code checks for collision with the paddle
	*/

	//Check and see it the player paddle was the las of the paddles to collide
	if(lastCollidePlayer==false)
	{	


		//Compute the vertical edges for the player paddle
		int xEdgeLeftPlayer=playerPos.x-size.x;
		int xEdgeRightPlayer=playerPos.x+paddleWidth;


		//Check if the ball is with in the vertical edges of the paddle
		if((x>xEdgeLeftPlayer) & (x<xEdgeRightPlayer) )
		{
			//Compute the horizontal edges for the player paddel
			int yEdgeTopPlayer=playerPos.y-size.y;
			int yEdgeBottomPlayer=playerPos.y+paddleHieght;

			//Check if the ball is with in the horizontal edges of the paddle
			if( (y>yEdgeTopPlayer) & (y<yEdgeBottomPlayer) )
			{

				/*
				Cncreace the x velocity and invert. One is added here since vx was negative (moveing to the left of the 				screen) but is now positive (moving to the right) and the numeric value is increaced by adding one.
				*/
				vx=(-vx)+1;


				//NOTE: these values need to be floating point so final division step 
			
				//Compute the player paddle y center
				float paddleCenter=playerPos.y+(paddleHieght/2);
			
				//Compute the y center of the ball
				float ballCenter=(size.y/2)+y;

				//find the difference between the two centers
				float dif=ballCenter-paddleCenter;
			
				//Increase the y velocity by the ratio of the difference between the centers over the max possible difference between the centers (the distance between the paddle center and the edge or paddleHieght/2). This is then multiplied by five (the value will now fall between 0 and 5 inclusive) and converted to an int. 
				vy+=int(5* (dif/ (paddleHieght/2) ) );
				
				//Flip the state of the variable 
				lastCollidePlayer=true;
	
			}

		}	

	}
	else
	{	
	
		//Compute the vertical edges of the ai paddle
		int xEdgeLeftAi=aiPos.x-size.x;
		int xEdgeRightAi=aiPos.x+paddleWidth;

		//Check if the ball is with in the vertical edges of the paddle
		if((x>xEdgeLeftAi) & ( x<xEdgeRightAi ) )
		{
			//Compute the horizontal edges of the ai paddle
			int yEdgeTopAi=aiPos.y-size.y;
			int yEdgeBottomAi=aiPos.y+paddleHieght;
		
			
			//Check if the ball is with in the horizontal edges of the paddle
			if( (y>yEdgeTopAi) & (y<yEdgeBottomAi) )
			{

				/*
				Increace the x velocity and invert. One is subtracted here since vx was positive (moveing to the right of 					the screen) but is now negative (moving to the left) and the numeric value is increaced by subtracting one.
				*/
				vx=(-vx)-1;

				//NOTE: These values need to be floating point so final division step 
			
				//Compute the player paddle y center
				float paddleCenter=(paddleHieght/2)+aiPos.y;
				
				//Compute the y center of the ball
				float ballCenter=(size.y/2)+y;

				//Find the difference between the two centers
				float dif=ballCenter-paddleCenter;
				
				//Increase the y velocity by the ratio of the difference between the centers over the max possible difference between the centers (the distance between the paddle center and the edge or paddleHieght/2). This is then multiplied by five (the value will now fall between 0 and 5 inclusive) and converted to an int. 
				vy+=int(3* (dif/ (paddleHieght/2) ) );

				//Flip the state of the variable
				lastCollidePlayer=false;
			}

		}
	}

}

//Set the x and y velocities to the inputs 
void Ball::setVelocity(int xInput, int yInput)
{

	vx=xInput;

	vy=yInput;

}


//Reset the position variables to the values that they had initially and set lastCollidePlayer to false so that the ball can collide with the paddle upon reset. 
void Ball::reset()
{
	lastCollidePlayer=false;

	x=xStart;
	y=yStart;

	rect.setPosition(x,y);

}




