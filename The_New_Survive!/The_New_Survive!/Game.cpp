#include "stdafx.h"
#include "Game.h"
#include "Light.h"
#include "GameObject.h"

void Game::Start() {

	if (state != Uninitialized)
		return;

	mainWindow.create(sf::VideoMode(1800, 795, 32), "Survive!");
	state = Playing;

	GameObject* House = new GameObject();
	House->Load("images/house.png");
	House->SetPosition(-52, -12);

	Light* light = new Light();

	ObjectManager.Add("Light", light);
	ObjectManager.Add("House", House);

	while (!IsExiting())
		GameLoop();
		

	mainWindow.close();	
}


bool Game::IsExiting() {
	if (state == Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop() {
	sf::Event currentEvent;
	mainWindow.pollEvent(currentEvent);

	switch (state) {
	case Game::Playing: {
		mainWindow.clear();

		ObjectManager.UpdateAll();
		ObjectManager.DrawAll(mainWindow);
		mainWindow.display();
		if (currentEvent.type == sf::Event::Closed)
			state = Game::Exiting;
		break;
	}
	}
}


Game::GameState Game::state = Uninitialized;
GameObjectManager Game::ObjectManager;