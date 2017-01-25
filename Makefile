#Created by Daniel May

CC=g++

WARNINGS=-Wall -Wextra 

SFML_LIB_PATH=-L /usr/lib/x86_64-linux-gnu

SFML_INCLUDE_PATH=-I /usr/include/SFML

LIBS=-l sfml-graphics -l sfml-window -l sfml-system

all: pong

pong: main.o renderList/renderList.o Entity.o Player.o Ball.o Ai.o ScoreBoard.o
	
	$(CC) main.o renderList/renderList.o Entity.o Player.o Ball.o Ai.o ScoreBoard.o -o pong $(SFML_LIB_PATH) $(LIBS) $(SFML_INCLUDE_PATH) $(WARNINGS)

main.o: main.cpp
	
	$(CC) -c main.cpp -o main.o $(SFML_INCLUDE_PATH) $(WARNINGS)

renderList/renderList.o: renderList/renderList.cpp 

	$(CC) -c renderList/renderList.cpp -o renderList/renderList.o $(SFML_INCLUDE_PATH) $(WARNINGS)

Entity.o: Entity.cpp

	$(CC) -c Entity.cpp -o Entity.o $(SFML_INCLUDE_PATH) $(WARNINGS) 	

Player.o: Player.cpp
	$(CC) -c Player.cpp -o Player.o $(SFML_INCLUDE_PATH) $(WARNINGS)

Ball.o: Ball.cpp
	$(CC) -c Ball.cpp -o Ball.o $(SFML_INCLUDE_PATH) $(WARNINGS)

Ai.o: Ai.cpp
	$(CC) -c Ai.cpp -o Ai.o $(SFML_INCLUDE_PATH) $(WARNINGS)

ScoreBoard.o: ScoreBoard.cpp
	$(CC) -c ScoreBoard.cpp -o ScoreBoard.o $(SFML_INCLUDE_PATH) $(WARNINGS)

