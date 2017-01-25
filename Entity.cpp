//Created by Daniel May

#include "Entity.hpp"

Entity::Entity(int xPos, int yPos, float width, float hieght, Color c, int maxHieght, int minHieght): x(xPos), y(yPos), xStart(xPos), yStart(yPos), rect(Vector2f(width,hieght))
{
	
	//Calculate and set the position of the rectangle and set the color

	posMax=maxHieght-hieght;

	posMin=minHieght;

	rect.setFillColor(c);

	rect.setPosition(x,y);

}

//Function to return the rectangel by reference
RectangleShape& Entity::returnDrawable()
{
	//this value is retuned by reference
	return rect;

}

//Function to return the position as a sfml Vector2f
Vector2f Entity::returnPosition()
{
	Vector2f vec(x,y);

	return vec;
}

Entity::~Entity()
{

}

//Function to return the position of the rectangle to the initial value given to the constructor
void Entity::reset()
{
	x=xStart;
	y=yStart;

	rect.setPosition(x,y);
}


