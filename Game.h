#pragma once
#include "player.h"


class GameLogic 
{
	private:
		const int width = 1722, height = 856; // window's background
		int selectedItemIndex = 0;
		Text text;
		Font font;
		Sprite sprite;
		bool gameOver = false;


	public:
		GameLogic();
		~GameLogic() {}
        void window2();
      
};