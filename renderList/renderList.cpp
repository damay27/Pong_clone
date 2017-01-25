//Created by Daniel May

#include "renderList.hpp"


//Constructor assigns window refernece
renderList::renderList(sf::RenderWindow &win):window(win)
{

}

renderList::~renderList()
{

}


void renderList::addObject(Drawable& drawable)
{
	//Push back the address of the object being added
	list.push_back(&drawable);

}

//Insert the new vector of drawables into the list
void renderList::addList(vector<Drawable*> drawableList)
{

	list.insert(list.end(),drawableList.begin(),drawableList.end());
}


//Search through the list by address in order to find and remove an object
void renderList::removeObject(Drawable& drawable)
{
	for(unsigned int i=0; i<list.size(); i++)
	{
		if(&drawable==list[i])
		{
			list.erase(list.begin()+i);
		
			break;
		}
	}
}

//This function does the same things as the above function just multiple times
//NOTE: The entire list must be searched because there is nothing saying that the objects to be removed are one after another 
void renderList::removeList(vector<Drawable*> drawableList)
{

	for(unsigned int i=0; i<drawableList.size(); i++)
	{
		removeObject(*drawableList[i]);
	}

}

//Remove all items from the vector
void renderList::removeAll()
{
	list.clear();
}

//Draw each of the items in the list and display them in the window
void renderList::render(Color background)
{
	window.clear(background);
	
	for(unsigned int i=0; i<list.size(); i++)
	{	
		window.draw(*list[i]);
	}
	
	
	
	window.display();
}




