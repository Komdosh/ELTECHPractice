#pragma once
#include "Game.h"

namespace SlaSolGame {
	class SettedGame : public Game {
	public:
		SettedGame() : Game() {}
		SettedGame(int iBeginNumber, int iModForRandColor, int iModForRandFieldSize);
		SettedGame(int iFieldSize, int iColors);

		void start();
		void end(System::Object^ sender);
		void win();
		void loose();
	};
}