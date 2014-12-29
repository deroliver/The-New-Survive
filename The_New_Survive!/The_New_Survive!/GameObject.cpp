#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject() {
	_isLoaded = false;
}

GameObject::~GameObject() {

}

void GameObject::Load(std::string filename) {
	if (_image.loadFromFile(filename) == false){
		_filename = "";
		_isLoaded = false;
	}

	else {
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void GameObject::Draw(sf::RenderWindow& window) {
	if (_isLoaded)
		window.draw(_sprite);
}

void GameObject::Update(float elapsedTime)
{
}

sf::Vector2f GameObject::GetPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

int GameObject::GetRotation() const {
	return static_cast<int>(_sprite.getRotation());
}

void GameObject::SetPosition(float x, float y) {
	if (_isLoaded)
		_sprite.setPosition(x, y);
}

void GameObject::SetScale(float x, float y) {
	if (_isLoaded)
		_sprite.setScale(x, y);
}

void GameObject::Rotate(float r) {
	_sprite.rotate(r);
}

void GameObject::SetOrigin(float x, float y) {
	_sprite.setOrigin(x, y);
}

sf::Sprite& GameObject::GetSprite()
{
	return _sprite;
}

sf::Texture& GameObject::GetTexture() {
	return _image;
}

bool GameObject::IsLoaded() const
{
	return _isLoaded;
}


float GameObject::GetHeight() const {
	return _sprite.getLocalBounds().height;
}

float GameObject::GetWidth() const {
	return _sprite.getLocalBounds().width;
}

sf::Rect<float> GameObject::GetBoundingRect() const
{
	return _sprite.getGlobalBounds();
}
