//Created by Daniel May

#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <Graphics.hpp>

using namespace std;
using namespace sf;

class Entity
{

	protected:
	
	//Coordinate data stored in pixels
	int x, y, posMax, posMin, xStart, yStart;
	
	RectangleShape rect;



	public:

	//Declare member functions and constructor/destructor

	Entity(int xPos, int yPos, float width, float hieght, Color c, int maxHieght, int minHieght);

	~Entity();

	Vector2f returnPosition();

	RectangleShape& returnDrawable();

	const Transform& returnTransform();
	
	virtual void reset();

};

#endif
