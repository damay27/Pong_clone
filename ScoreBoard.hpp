//Created by Daniel May


#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Graphics.hpp"
#include <vector>

using namespace sf;
using namespace std;

class ScoreBoard
{

	private:
	//Create vectors of rectangles for the player and ai scoreboards
	vector<RectangleShape> playerBoard;
	vector<RectangleShape> aiBoard;

	//Color variables for each state 
	Color on, off;

	//Variables to hold the score
	int playerScore, aiScore;


	public:

	//Declare member functions and constructor/destructor
	
	ScoreBoard(int size, Color onColor, Color offColor, int offsetX, int offsetY, int windowSizeX);

	~ScoreBoard();

	vector<Drawable*> returnDrawables();

	void reset();

	bool incrementPlayer();

	bool incrementAi();

	

};

#endif
