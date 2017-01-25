//Created by Daniel May

#ifndef BALL_H
#define BALL_H
#include "Entity.hpp"


class Ball: public Entity
{
	private:
	
	//Variables to store the current velocity of ball
	int vx, vy;

	//Variable to track which paddle was hit last
	bool lastCollidePlayer;

	public:

	//Declare member functions and constructor/destructor

	Ball(int xPos, int yPos, float width, float hieght, Color c, int collisionTop, int collisionBottom);
	
	~Ball();

	void move(Vector2f playerPos, Vector2f aiPos, int hieght, int width);
	
	void setVelocity(int xInput, int yInput);
	
	void reset();

};

#endif
