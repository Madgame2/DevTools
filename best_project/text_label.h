#pragma once
#include<string>
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class textLabel

{
public:
	textLabel(int x, int y, float WIDTH, float height, string defolt_string);
	~textLabel();

	void render(RenderWindow* window)
	{

		background.loadFromFile("img\\inputhover.jpg");
		background.setSmooth(true);

		label.setTexture(background);
		label.setPosition(x, y);
		label.setScale(WIDTH / 256, height / 74);

		text_label.setPosition(x + 10, y + height / 8);

		
			visible_string = Build_visible_string();

			text_label.setString(visible_string);

		window->draw(label);
		window->draw(text_label);
	}

	void writing_data(Event event) {	

		if (is_active) {
			if (event.type == Event::TextEntered) {

				switch (event.key.code)
				{
				case 8: //backspace

					if (global_position > 0) {

						full_string.erase(global_position-1, 1);
						right_position--;
						global_position--;
						if (left_position != 0) {
							left_position--;
						}
					}

					break;
				case 13: //enter
					
					is_active = false;

					break;

				case Keyboard::Left:
					cout << "left is presed" << endl;
					break;

				default:

					full_string.insert(global_position, event.text.unicode);
					global_position++;
					right_position++;

					break;
				}

				cout << "left - " << left_position << " right - " << right_position << " global_position - " << global_position << endl;
			}

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				cout << "left" << endl;
				if (global_position != 0) {
					if (global_position == left_position) {
						global_position--;
						left_position--;
					}
					else
					{
						global_position--;
					}
				}
				cout << "left - " << left_position << " right - " << right_position << " global_position - " << global_position << endl;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)){
				cout << "right" << endl;

				if (global_position < right_position) {
					global_position++;
				}
				if (global_position == right_position && right_position != full_string.getSize()) {
					global_position++;
					right_position++;
				}
				cout << "left - " << left_position << " right - " << right_position << " global_position - " << global_position << endl;

			}

		}
	}

	bool is_hover(RenderWindow* window) {
		IntRect rect(label.getPosition().x,
			label.getPosition().y,
			label.getLocalBounds().width * label.getScale().x,
			label.getLocalBounds().height * label.getScale().y);
		if (rect.contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
			cout << "hover" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	void set_active() {
		is_active = true;
	}
	void set_disactive() {
		is_active = false;
	}

	String get_data() {
		return full_string;
	}

	void set_data(String str) {
		full_string = str;
	}

private:

	void clear_string()
	{
		if (text_label.getGlobalBounds().width + 40 >= WIDTH) {
			if (left_position == global_position) {
				right_position--;

			}
			else if (right_position == global_position)
			{
				left_position++;
			}
			else
			{
				right_position--;
			}

		}

	}

	String Build_visible_string() {

		String visible_string;

		clear_string();

		if (animation_timer.getElapsedTime().asMilliseconds() > 500) {
			if (sumbol == ' ') {
				sumbol = '|';
			}
			else
			{
				sumbol = ' ';
			}
			animation_timer.restart();
		}

		visible_string = full_string.substring(left_position, right_position - left_position);

		if (is_active) {

			if (global_position <= right_position - left_position) {
				visible_string.insert(global_position - left_position, sumbol);
			}
			else
			{
				visible_string.insert(global_position - left_position, sumbol);
			}
		}

		return visible_string;
	}

	int x, y,postion=0;
	float WIDTH,height;

	Text text_label;

	String full_string;
	String visible_string;

	Font font;
	bool is_active = false;

	Texture background;
	Sprite label;

	int left_position=0,right_position=0,global_position=0;

	Clock animation_timer;
	char sumbol = ' ';
};	

textLabel::textLabel(int x, int y, float WIDTH, float height, string defolt_string)
{
	this->x = x;
	this->y = y;
	this->WIDTH = WIDTH;
	this->height = height;

	font.loadFromFile("arialmt.ttf");
	text_label.setFillColor(Color::Black);
	text_label.setCharacterSize(30);
	text_label.setString(defolt_string);
	text_label.setFont(font);

	label.setScale(2, 1);
}

textLabel::~textLabel()
{

}