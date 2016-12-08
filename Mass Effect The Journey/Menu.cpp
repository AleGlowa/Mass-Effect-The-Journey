#include "stdafx.h"
#include "Menu.h"

Menu::Menu(void)
{
	state = END;

	if (!music.openFromFile("menu_music.mp3"))
	{
		MessageBox(NULL, L"Music not found", L"ERROR", NULL);
		return;
	}

	if (!texture.loadFromFile("background.jpg"))
	{
		MessageBox(NULL, L"Image not found", L"ERROR", NULL);
		return;
	}

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
	sprite.setTexture(texture);
	music.setVolume(50);
	music.setLoop(true);
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
			// Wciœniêcie ESC lub przycisku X
			if (event.type == Event::Closed || event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				state = END;
			// Klikniêcie EXIT
			else if ((options[1].getFillColor() == Color::Yellow && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) || (Keyboard::isKeyPressed(Keyboard::Return) && options[1].getFillColor() == Color::Yellow))
				state = END;
			else if ((options[0].getFillColor() == Color::Yellow && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) || (Keyboard::isKeyPressed(Keyboard::Return) && options[0].getFillColor() == Color::Yellow))
			{
				music.stop();
				state = GAME;
			}
		}
		// 1 ! Zmiana koloru czcionki w zale¿noœci na jak¹ opcjê wskazuje mysz
		options[0].setFillColor(Color::Yellow);

		if (options[1].getGlobalBounds().contains(mouse))
		{
			options[1].setFillColor(Color::Yellow);
			options[0].setFillColor(Color::White);
		}

		

		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			options[1].setFillColor(Color::Yellow);
			options[0].setFillColor(Color::White);
		}
		else 
			options[1].setFillColor(Color::White);
		// 1 ! 
		window.clear();
		window.draw(sprite);
		music.play();
		window.draw(title);
		for (int i = 0; i < HOW_MANY; i++)
			window.draw(options[i]);

		window.display();
	}
}