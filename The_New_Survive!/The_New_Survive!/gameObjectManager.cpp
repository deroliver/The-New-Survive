#include "stdafx.h"
#include "GameObjectManager.h"
#include <memory>
#include "Game.h"

GameObjectManager::GameObjectManager() {
	//clock.restart();
}

GameObjectManager::~GameObjectManager() {
	
}

void GameObjectManager::Add(std::string name, GameObject* gameObject) {
	Objects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name) {
	std::map<std::string, GameObject*>::iterator results = Objects.find(name);
	if (results != Objects.end()) {
		delete results->second;
		 Objects.erase(results);
	}
}

GameObject* GameObjectManager::Get(std::string name) const {
	std::map<std::string, GameObject*>::const_iterator results = Objects.find(name);
	if (results == Objects.end())
		return NULL;
	return results->second;
}

int GameObjectManager::GetObjectCount() const {
	return Objects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow) {
	std::map<std::string, GameObject*>::const_iterator itr = Objects.begin();
	while (itr != Objects.end()) {
		itr->second->Draw(renderWindow);
		itr++;
	}
}

void GameObjectManager::UpdateAll() {
	std::map<std::string, GameObject*>::const_iterator itr = Objects.begin();

	while (itr != Objects.end()) {
		itr->second->Update(clock.restart().asSeconds());
		itr++;
	}

}