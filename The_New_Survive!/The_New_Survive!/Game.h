#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "gameObjectManager.h"



class Game {
public:
	void Start();
	const static GameObjectManager& GetGameObjectManager();

private:
	bool IsExiting();
	void GameLoop();
	sf::Sprite house;
	sf::Clock clock;
	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };
	static GameObjectManager ObjectManager;

	static GameState state;
	sf::RenderWindow mainWindow; 
};