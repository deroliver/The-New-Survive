#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"


class Light : public GameObject {
public:
	Light();
	void Update(float elapsedTime);

	float frameCounter;  
	float switchFrame;
	float frameSpeed;
	bool direction;
};