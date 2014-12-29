#include "stdafx.h"
#include "Light.h"


Light::Light() {
	Load("images/Light.png");
	SetPosition(900, 255);
	SetScale(.9, .93);
	SetOrigin(GetTexture().getSize().x / 2, GetTexture().getSize().y - GetTexture().getSize().y);
	switchFrame = 100;
	frameSpeed = 200;
	frameCounter = 0;
	direction = true;
}

void Light::Update(float elapsedTime) {
	if (direction) {
		Rotate(-4000 * elapsedTime);
		if (GetRotation() < 330 && GetRotation() > 30)
			direction = false;
			
	}
	
	else if (!direction) {
		Rotate(4000 * elapsedTime);
		if (GetRotation() > 30 && GetRotation() < 330)
				direction = true;
	}
}


