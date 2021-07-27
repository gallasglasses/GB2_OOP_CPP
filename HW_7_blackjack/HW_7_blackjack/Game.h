#pragma once
#include "House.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>

class Game
{
private:

	Deck gameDeck;
	House gameHandHouse;
	std::vector<Player> vGamePlayers;

public:
	Game(std::vector<std::string>& vNamePlayers);
	void Play();
	void Print();
	~Game();
};