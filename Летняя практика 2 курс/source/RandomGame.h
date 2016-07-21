#pragma once
#include "SettedGame.h"

namespace SlaSolGame {
	class RandomGame : public SettedGame {
	public:
		RandomGame() : SettedGame() {};

		void start();
	};
}