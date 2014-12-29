#pragma once
#include <string>
#include "GameObject.h"

class GameObjectManager {
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, GameObject* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	GameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& window);
	void UpdateAll();

private:
	std::map<std::string, GameObject*> Objects;
	sf::Clock clock;

	struct GameObjectDeallocator {
		void operator()(const std::pair<std::string, GameObject*>& p) const {
			delete p.second;
		}
	};

};