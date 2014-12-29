#pragma once
#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"



class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Update(float elapsedTime);
	

	virtual void SetPosition(float x, float y);
	virtual void SetScale(float x, float y);
	virtual void Rotate(float r);
	virtual void SetOrigin(float x, float y);
	
	virtual sf::Vector2f GetPosition() const;
	virtual float GetWidth() const;
	virtual float GetHeight() const;
	virtual int GetRotation() const;

	virtual sf::Rect<float> GetBoundingRect() const;
	virtual bool IsLoaded() const;

protected:
	sf::Sprite& GetSprite();
	sf::Texture& GetTexture();

private:
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;


};