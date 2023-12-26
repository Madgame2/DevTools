#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Button
{
public:
	Button(string path_to_static,string path_to_active);
	~Button();

	void set_position(float x, float y) {
		this -> x = x;
		this->y = y;

		button_sprite.setPosition(x, y);
	}

	void set_size(float Widht, float height) {
		WIDTH = Widht;
		HEIGHT = height;

		button_sprite.setScale(
			Widht/button_sprite.getTexture()->getSize().x,
			height / button_sprite.getTexture()->getSize().y
		);
	}

	bool is_hover(RenderWindow* window) {
		IntRect rect(x, y, WIDTH, HEIGHT);
		if (rect.contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
			return true;
		}
		else {
			return false;
		}
	}

	void set_active() {

		is_active = true;
		button_sprite.setTexture(active_button);
		timer.restart();
	}

	void set_disactive() {
		is_active = false;
		button_sprite.setTexture(static_button);
	}
	
	void render(RenderWindow* window) {
		if (!switch_mode) {
			if (timer.getElapsedTime().asMilliseconds() > 100) {
				set_disactive();
			}
		}

		window->draw(button_sprite);
	}

	void set_swictch_mode(bool is_active) {
		switch_mode = is_active;
	}

	bool isActive() {
		return is_active;
	}

private:
	Texture static_button;
	Texture active_button;

	Sprite button_sprite;

	float WIDTH, HEIGHT;
	float x, y;

	bool is_active = false;
	bool switch_mode = false;

	Clock timer;
};

Button::Button(string path_to_static, string path_to_active)
{
	static_button.loadFromFile(path_to_static);
	active_button.loadFromFile(path_to_active);

	static_button.setSmooth(true);
	active_button.setSmooth(true);

	set_disactive();

	WIDTH = static_button.getSize().x;
	HEIGHT = static_button.getSize().y;
}

Button::~Button()
{
}