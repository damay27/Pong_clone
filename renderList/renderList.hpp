//Created by Daniel May

#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class renderList
{
	//Member variables
	private:

	//A reference to the window where everything will be drawn
	RenderWindow &window;

	//Vector to store all objects to be drawn
	vector<Drawable*> list;
	

	public:
	
	//Declare member functions and constructor/destructor
	
	renderList(sf::RenderWindow& win);
	~renderList();

	
	void addObject(Drawable& drawable);
	void addList(vector<Drawable*> drawableList);
	
	void removeObject(Drawable& drawable);
	void removeList(vector<Drawable*> drawableList);

	void removeAll();
	
	void render(Color background);

};

#endif
