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
	enum GAME_STATE {MENU, GAME, PAUSE, GAME_OVER, END};
	GAME_STATE state;
private:
	Font font;
	//int selected_item_index = 0;

	void menu();
};