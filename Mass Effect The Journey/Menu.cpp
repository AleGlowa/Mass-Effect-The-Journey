#include "stdafx.h"
#include "Menu.h"

Menu::Menu(void)
{
	state = END;

	if (!font.loadFromFile("me123.ttf"))
	{
		MessageBox(NULL, L"Font not found", L"ERROR", NULL);
		return;
	}

	state = MENU;
}

void Menu::runMenu()
{
	while (state != END)
	{
		switch (state)
		{
		case GAME_STATE::MENU:
			menu();
			break;
		case GAME_STATE::GAME:
			//
			break;
		}
	}
}

void Menu::menu()
{
	RenderWindow window(VideoMode(900, 600), "Mass Effect The Journey");
	Text title("Mass Effect The Journey", font, 40);
	title.setStyle(Text::Bold);
	title.setPosition(900 / 2 - title.getGlobalBounds().width / 2, 20);

	const int HOW_MANY = 2;
	Text options[HOW_MANY];
	string str[] = { "Play", "Exit" };
	
	for (int i = 0; i < HOW_MANY; i++)
	{
		options[i].setFont(font);
		options[i].setCharacterSize(40);
		options[i].setString(str[i]);
		options[i].setPosition(900 / 2 - options[i].getGlobalBounds().width / 2, 250 + i * 120);
	}

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			// Wci�ni�cie ESC lub przycisku X
			if (event.type == Event::Closed || event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				state = END;
			// Klikni�cie EXIT
			else if (options[1].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
				state = END;
			else if (options[0].getGlobalBounds().contains(mouse) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
				state = GAME;
		}

		for (int i = 0; i < HOW_MANY; i++) {
			if (options[i].getGlobalBounds().contains(mouse))
				options[i].setFillColor(Color::Yellow);
			else options[i].setFillColor(Color::White);
		}

		window.clear();
		window.draw(title);
		for (int i = 0; i < HOW_MANY; i++)
			window.draw(options[i]);

		window.display();
	}
}