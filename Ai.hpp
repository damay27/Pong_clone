//Created by Daniel May

#ifndef AI_H
#define AI_H

#include "Entity.hpp"
#include "Graphics.hpp"

using namespace sf;
using namespace std;

//Define a class to handle the computer controlled paddle that inherits from Entity
class Ai: public Entity
{
	public:

	//Declare constructor
	Ai(int xPos, int yPos, float width, float hieght, Color c, int collisionTop, int collisionBottom);

	//Declare constructor
	~Ai();

	//Declare function to control paddle movment that takes the position of the ball and its dimensions
	void move(Vector2f ballPos, int ballHieght);

	

};


#endif
