#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>

using namespace std;
using namespace sf;

class Menu
{
public:
	Menu(void);
	//~Menu(void);

	void runMenu();
protected:
	enum GAME_STATE {MENU, GAME, GAME_OVER, END};
	GAME_STATE state;
private:
	Font font;

	void menu();
};