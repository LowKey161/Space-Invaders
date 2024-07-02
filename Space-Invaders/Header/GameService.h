#pragma once
#include "ServiceLocator.h"
#include <SFML/Graphics.hpp>

class GameService
{
private:

	ServiceLocator* service_locator;
	sf::RenderWindow* game_window;


	void initialize();
	void initializeVariables();
	void destroy();

public:
	GameService();
	~GameService();

	void ignite();
	void update();
	void render();
	bool isRunning();

};