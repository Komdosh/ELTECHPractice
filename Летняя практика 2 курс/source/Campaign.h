#pragma once
#include "Game.h"

#define MAXLEVEL 15

namespace SlaSolGame {
	class Campaign : public Game {
		int level;
		int maxLevel;
		int campaignFieldSize[MAXLEVEL] = { 2, 3, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8 };
		int campaignColors[MAXLEVEL] = { 1, 2, 2, 3, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3 };
	public:
		Campaign() : Game(), level(0), maxLevel(MAXLEVEL - 1) {};
		~Campaign();

		int getLevel();
		void setLevel(int value);
		void incLevel();
		int getFieldSizeByLevel(int level);
		int getCountColorByLevel(int level);
		int getMaxLevel();

		void start();
		void end(System::Object^ sender);
		void win();
		void loose();
	};
}