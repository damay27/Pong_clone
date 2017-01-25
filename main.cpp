//Created by Daniel May

#include <Graphics.hpp>
#include <System.hpp>
#include "renderList/renderList.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Ai.hpp"
#include "ScoreBoard.hpp"


#define PADDLE_WIDTH 30
#define PADDLE_HIEGHT 120
#define BUMPER_THICKNESS 40
#define BALL_SIZE 30


using namespace sf;
using namespace std;


int main()
{

	
	//Create window
	RenderWindow window(VideoMode::getDesktopMode(),"Pong");

	//Create render list
	renderList drawList(window);

	//Create vector to hold the window size
	Vector2u windowSize=window.getSize();

	//Define colors 
	Color white(255,255,255), black(0,0,0);


	//Compute paddle positions
	int playerPaddleY=(windowSize.y/2)-(PADDLE_HIEGHT/2);
	int playerPaddleX=PADDLE_WIDTH;

	


	//Create the player object and add it to drawList
	Player player(playerPaddleX,playerPaddleY,PADDLE_WIDTH,PADDLE_HIEGHT,white,windowSize.y-BUMPER_THICKNESS,BUMPER_THICKNESS);

	drawList.addObject(player.returnDrawable());



	//Create the top bumper, set its position, and add it to drawList
	RectangleShape topBumper(Vector2f(windowSize.x,BUMPER_THICKNESS));
	
	topBumper.setPosition(0,0);
	
	drawList.addObject(topBumper);

	
	//Create the lower bumper, set its position, and add it to drawList
	RectangleShape lowerBumper(Vector2f(windowSize.x,BUMPER_THICKNESS));
	
	lowerBumper.setPosition(0,windowSize.y-BUMPER_THICKNESS);
	
	drawList.addObject(lowerBumper);

	//Compute the balls starting position
	int ballY=(windowSize.y/2)-(BALL_SIZE/2);
	int ballX=windowSize.x/2;
	
	//Create the ball, set its initial velocity, and add it to drawList
	Ball ball(ballX,ballY,BALL_SIZE,BALL_SIZE,white,windowSize.y-BUMPER_THICKNESS,BUMPER_THICKNESS);
	
	ball.setVelocity(-3,0);

	drawList.addObject(ball.returnDrawable());



	//Compute the position of the Ai paddle
	int aiPaddleX=windowSize.x-(2*PADDLE_WIDTH);
	int aiPaddleY=(windowSize.y/2)-(PADDLE_HIEGHT/2);

	//Create the ai paddle and add it to drawList	
	Ai ai(aiPaddleX,aiPaddleY,PADDLE_WIDTH,PADDLE_HIEGHT,white,windowSize.y-BUMPER_THICKNESS,BUMPER_THICKNESS);

	drawList.addObject(ai.returnDrawable());


	//Compute the position of the upper left corner of the score board
	int scoreBoardX=BALL_SIZE;
	int scoreBoardY=(BUMPER_THICKNESS/2)-(BALL_SIZE/2);

	//Create the score board and add it to drawList
	ScoreBoard scoreBoard(BALL_SIZE,black,white,scoreBoardX,scoreBoardY,windowSize.x);

	drawList.addList(scoreBoard.returnDrawables());

	//Create a clock object 
	Clock timer;

	while(window.isOpen())
	{

		//Create an event, and use it to poll all window events and determine if the widnows has been closed
		Event e;

		while(window.pollEvent(e))
		{
			if(e.type==Event::Closed)
			{
				window.close();
			}
		}
		
		//This block of code hadles user input and player movement and should only be run every 10 milliseconds
		if(timer.getElapsedTime().asMilliseconds()>=10)
		{
			//Run movement functions for player, ai, and ball
			player.move();
			ball.move(player.returnPosition(), ai.returnPosition(), PADDLE_HIEGHT, PADDLE_WIDTH);
			ai.move(ball.returnPosition(),BALL_SIZE);
			
			//Determine if the ball's origin has passed the left edge of the screen
			if( (ball.returnPosition().x<(0-BALL_SIZE)) )
			{
				//Reset the position and velocity of the ball
				ball.reset();
				ball.setVelocity(-3,0);


				//Increment the ai score and determine based on the functions return type if the ai has won
				if(scoreBoard.incrementAi())
				{

					//Reset player and ai, then render everything so the changes are visible
					player.reset();
					ai.reset();
					drawList.render(black);
					
					//Reset the score board these changes will not be displayed until the next draw call
					scoreBoard.reset();
					
					//Restart timer and delay 1000ms. In this case both dealy loops will run, giving and longer pause
					timer.restart();
					while(timer.getElapsedTime().asMilliseconds()<1000)
					{

					}

				}
				else
				{
					//If the ai did not win than only render the objects
					drawList.render(black);
				}

				//Restart the timer and 1000ms
				timer.restart();
				while(timer.getElapsedTime().asMilliseconds()<1000)
				{

				}

			}



			//determine if the ball has passed the right edge of the screen
			if( (ball.returnPosition().x>windowSize.x) )
			{
				
				//Reset the position and velocity of the ball
				ball.reset();
				ball.setVelocity(-3,0);

				////Increment the player score and determine based on the functions return type if the player has won
				if(scoreBoard.incrementPlayer())
				{
					//Reset player and ai, then render everything so the changes are visible
					player.reset();
					ai.reset();
					drawList.render(black);					

					//Reset the score board these changes will not be displayed until the next draw call
					scoreBoard.reset();

					//Restart timer and delay 1000ms. In this case both dealy loops will run, giving and longer pause
					timer.restart();
					while(timer.getElapsedTime().asMilliseconds()<1000)
					{

					}

				}
				else
				{
					//If the player did not win than only render the objects
					drawList.render(black);
				}

				//Restart the timer and wait 2000 milliseconds before moving on
				timer.restart();
				while(timer.getElapsedTime().asMilliseconds()<1000)
				{

				}

			}

			//Restart the timer
			timer.restart();

		}

		//Render all the objects on a black background
		drawList.render(black);

		

	}
	

}
