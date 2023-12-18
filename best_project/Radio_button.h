#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Radio_button
{
	class Button
	{
	public:
		Button(){
			disactive_button.loadFromFile("img\\Radio.png");
			disactive_button.setSmooth(true);

			button_sprite.setTexture(disactive_button);
		}
		~Button() {
		
		}

		void set_textures(string _static, string _active)
		{
			disactive_button.loadFromFile(_static);
			active_button.loadFromFile(_active);
			disactive_button.setSmooth(true);
			active_button.setSmooth(true);
		}

		void set_position(float x, float y) {
			this -> x = x;
			this->y = y;
			button_sprite.setPosition(x, y);
		}

		void set_size(float Widht, float height) {
			this->Widht = Widht;
			this->Height = height;

			this->button_sprite.setScale(
				Widht / active_button.getSize().x,
				height / active_button.getSize().y
			);
		}

		void set_active() {
			is_active = true;
			button_sprite.setTexture(active_button);
		}
		void set_disactive() {
			is_active = false;
			button_sprite.setTexture(disactive_button);
		}

		bool is_hover(RenderWindow* window) {
			IntRect rect(button_sprite.getPosition().x, button_sprite.getPosition().y, Widht, Height);



			if (rect.contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
				return true;
			}
			else {
				return false;
			}
		}

		void render(RenderWindow* window) {
			if (is_active) {
				button_sprite.setTexture(active_button);
			}
			else
			{
				button_sprite.setTexture(disactive_button);
			}

			window->draw(button_sprite);
		}

		bool _is_active() {
			return is_active;
		}

	private:
		float x=0, y=0;
		float Widht=0, Height=0;

		Texture active_button;
		Texture disactive_button;

		Sprite button_sprite;

		bool is_active=false;
	};

public:
	Radio_button(int coutn_of_buttons);
	~Radio_button();

	Button* get_button(int id) {
		return &buttons[id];
	}

	void set_button_active(int id) {
		for (int i = 0; i < count_of_buttons; i++) {
			if (i == id) {
				buttons[i].set_active();
			}
			else
			{
				buttons[i].set_disactive();
			}
		}
	}

	void set_buttons_size(float width, float height) {
		for (int i = 0; i < count_of_buttons; i++)
		{
			buttons[i].set_size(width, height);
		}
	}

	void render_all(RenderWindow*window) {
		for (int i = 0; i < count_of_buttons; i++)
		{
			buttons[i].render(window);
		}
	}

	int get_active_button() {
		for (int i = 0; i < count_of_buttons; i++) {
			if (buttons[i]._is_active()) {
				return i;
			}
		}
		return -1;
	}

private:
	Button* buttons;

	int count_of_buttons;
};

Radio_button::Radio_button(int count_of_buttons)
{
	this->count_of_buttons = count_of_buttons;

	buttons = new Button[count_of_buttons];

	for (int i = 0; i < count_of_buttons; i++) {
		 buttons[i].set_textures("img\\Radio.png", "img\\RadioON.png");
	}
}

Radio_button::~Radio_button()
{
}