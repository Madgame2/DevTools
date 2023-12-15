#pragma once
#define shadow_present 1/15
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
using namespace std;

class Menu
{
	class menu_buttons
	{
	public:
		menu_buttons(string path,string active_button) {
			button_texture.loadFromFile(path);
			button_is_active_texture.loadFromFile(active_button);
			button_is_active_texture.setSmooth(true);
			button_texture.setSmooth(true);

			button_sprite.setTexture(button_texture);

			font.loadFromFile("Kadwa-Bold.ttf");
			button_text.setFont(font);
			button_text.setFillColor(Color(128, 128, 128));

			button_zone.setFillColor(Color::White);
		}
		
		void set_position(float x, float y) {
			this->x = x;
			this->y = y;

			button_sprite.setPosition(x, y);
		}

		void render_button(RenderWindow* window) {
			window->draw(button_sprite);
		}
		void render_button_text(RenderWindow* window) {
			window->draw(button_text);
		}
		void render_button_zone(RenderWindow* window) {
			window->draw(button_zone);
		}

		void set_size(float WIDTH, float HEIGHT) {
			this->WIDTH = WIDTH;
			this->HEIGHT = HEIGHT;

			button_sprite.setScale(
				WIDTH / button_texture.getSize().x,
				HEIGHT / button_texture.getSize().y
			);

			cout << button_texture.getSize().x * button_sprite.getScale().x;
		}

		float get_x_position() {
			return x;
		}
		float get_y_position() {
			return y;
		}
		float get_off_set() {
			return off_set;
		}
		float get_button_width() {
			return WIDTH;
		}
		float get_button_height() {
			return HEIGHT;
		}

		void set_text(String str) {
			button_text.setString(str);
		}

		void set_text_size(int size) {
			font_size = size;
			button_text.setCharacterSize(size);
		}

		void set_text_position(float x, float y) {
			button_text.setOrigin(0, font_size*3 / 5);
			button_text.setPosition(x,y);
		}

		void move_text(float x, float y) {
			button_text.move(x, y);
		}

		bool is_hover(RenderWindow* window) {
			IntRect rect
			(
				button_zone.getPosition().x,
				button_zone.getPosition().y,
				button_zone.getSize().x,
				button_zone.getSize().y
			);
			if (rect.contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
				return true;
			}
			else
			{
				return false;
			}
		}

		void set_buttn_zone_size(float x, float y) {
			button_zone.setSize(Vector2f(x,y));
		}

		void set_button_zone_position(float x, float y) {
			button_zone.setPosition(x, y);
		}

		void move_button_zone(float x,float y) {
			button_zone.move(x, y);
		}

		void set_text_color(Color new_color) {
			button_text.setFillColor(new_color);
		}

		void button_set_hover() {
			button_sprite.setTexture(button_is_active_texture);
			button_text.setFillColor(Color(144,76,255));
			//button_zone.setFillColor(Color(249, 244, 255));

		}
		void button_set_active() {
			button_sprite.setTexture(button_is_active_texture);
			button_text.setFillColor(Color(144, 76, 255));
			button_zone.setFillColor(Color(249, 244, 255));
		}
		void button_set_disactive() {
			button_sprite.setTexture(button_texture);
			button_text.setFillColor(Color(128, 128, 128));
			button_zone.setFillColor(Color(255,255,255));
		}

		void set_active(bool active) {
			this->is_active = active;
		}

		bool get_active() {
			return is_active;
		}

	private:
		float x=0, y=0, WIDTH=0, HEIGHT=0 ,off_set=10;
		float font_size;

		bool is_active = false;

		Texture button_texture;
		Texture button_is_active_texture;
		Sprite button_sprite;

		Font font;
		Text button_text;

		RectangleShape button_zone;
	};




public:
	Menu(float WIDTH, float HEIGHT, float visible_part);
	~Menu();

	void render(RenderWindow* window) {

		window->draw(menu_sprite);

		RectangleShape buttons_zone;

		buttons_zone.setFillColor(Color(255, 255, 255));

		for (int i = 0; i < 6; i++) {
			buttons[i].render_button_zone(window);

			if (buttons[i].is_hover(window))
			{
				buttons[i].set_text_color(Color(128, 0, 128));
				buttons[i].button_set_hover();
			}
			else
			{
				buttons[i].set_text_color(Color(128, 128, 128));
				buttons[i].button_set_disactive();
			}

			if (buttons[i].get_active()) {
				buttons[i].button_set_active();
				buttons_zone.setFillColor(Color(249, 244, 255));
			}

			buttons[i].render_button_text(window);

			buttons_zone.setSize(Vector2f(buttons[i].get_button_width()-1, buttons[i].get_button_height()));
			buttons_zone.setPosition(buttons[i].get_x_position(), buttons[i].get_y_position());
			window->draw(buttons_zone);
			buttons_zone.setFillColor(Color(255, 255, 255));
		}
		for (int i = 0; i < 6; i++) {

			 if (buttons[i].is_hover(window))
			{
				buttons[i].set_text_color(Color(128, 0, 128));
				buttons[i].button_set_hover();
			}
			else
			{
				buttons[i].set_text_color(Color(128, 128, 128));
				buttons[i].button_set_disactive();
			}

			if (buttons[i].get_active()) {
				buttons[i].button_set_active();
				buttons_zone.setFillColor(Color(249, 244, 255));
			}
			buttons[i].render_button(window);
		}
	}


	float get_visible_part() {
		return visible_part;
	}

	bool is_hover(RenderWindow* window) {
		IntRect rect(0,
			0,
			menu_sprite.getLocalBounds().width * menu_sprite.getScale().x + menu_sprite.getPosition().x,
			menu_sprite.getLocalBounds().height * menu_sprite.getScale().y);
		if (rect.contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
			return true;
		}
		else
		{
			return false;
		}

	}

	void collaps() {
		if (menu_sprite.getPosition().x > -1 * WIDTH +visible_part) {
			menu_sprite.move(-1 * speed, 0);
			for (int i = 0; i < 6; i++) {
				buttons[i].move_text(-1 * speed, 0);
				buttons[i].move_button_zone(-1 * speed, 0);
			}
		}
	}

	void expand() {
		if (menu_sprite.getPosition().x < 0) {
			menu_sprite.move(speed, 0);
			for (int i = 0; i < 6; i++) {
				buttons[i].move_text(speed, 0);
				buttons[i].move_button_zone(speed, 0);
			}
		}
	}

	void set_button_zone(float count) {
		button_zone_off_set = count;
	}

	void set_buttons_settings(float WIDTH,float HEIGHT,float off_set) {

		buttons[0].set_position(0, button_zone_off_set);
		buttons[0].set_size(WIDTH, HEIGHT);
		set_button_zone_settings(0);

		for (int i = 1; i < 6; i++) {
			buttons[i].set_position(0, buttons[i - 1].get_y_position() + HEIGHT + off_set);
			buttons[i].set_size(WIDTH, HEIGHT);
			set_button_zone_settings(i);
		}
	}

	void set_button_text_settings(int size, float  off_set) {
		for (int i = 0; i < 6; i++)
		{
			buttons[i].set_text_size(size);
			buttons[i].set_text_position(buttons[i].get_x_position() + buttons[i].get_button_width() + off_set,buttons[i].get_y_position()+buttons[i].get_button_height()/2);
			buttons[i].set_text("Button ");
			buttons[i].move_text(-1 * WIDTH + visible_part, 0);
			set_button_zone_settings(i);
		}
	}

	menu_buttons *getButton(int id) {
		return &buttons[id];
	}

	void set_active(int id) {
		for (int i=0; i < 6; i++) {
			if (i == id) {
				buttons[i].set_active(true);
			}
			else
			{
				buttons[i].set_active(false);
			}
		}
	}

private:

	void set_button_zone_settings(int i) {
		buttons[i].set_buttn_zone_size(WIDTH, buttons[i].get_button_height());
		buttons[i].set_button_zone_position(buttons[i].get_x_position(), buttons[i].get_y_position());
		buttons[i].move_button_zone(-1 * WIDTH + visible_part-1, 0);
	}

	float WIDTH, HEIGHT;

	float visible_part=0;

	float speed = 15;

	float button_zone_off_set = 10;

	Texture menu_texture;
	Sprite menu_sprite;

	menu_buttons buttons[6]{
		menu_buttons("img\\1.png","img\\1HOVER.png"),
		menu_buttons("img\\2.png","img\\2HOVER.png"),
		menu_buttons("img\\3.png","img\\3HOVER.png"),
		menu_buttons("img\\4.png","img\\4HOVER.png"),
		menu_buttons("img\\5.png","img\\5HOVER.png"),
		menu_buttons("img\\6.png","img\\6HOVER.png")
	};
};

Menu::Menu(float WIDTH,float HEIGHT,float visible_part)
{
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->visible_part = visible_part;

	menu_texture.loadFromFile("img\\full_menu.png");
	menu_texture.setSmooth(true);

	menu_sprite.setTexture(menu_texture);
	menu_sprite.setScale(
		(WIDTH+WIDTH*shadow_present) / menu_texture.getSize().x,
		HEIGHT/menu_texture.getSize().y
	);

	menu_sprite.setPosition(-1 * WIDTH + visible_part, 0);
}

Menu::~Menu()
{
}