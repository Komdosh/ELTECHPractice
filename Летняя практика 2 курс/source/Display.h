#pragma once
#include <cliext\vector>
#include "GameWindow.h"
#include "LevelMenu.h"
#include "MainMenu.h"

namespace SlaSol {
	ref class mainWindow;
}

namespace SlaSolDisplay {
	public ref class Display : public GameWindow {
		//GameWindow gameWindow;
		LevelMenu levelMenu;
		MainMenu mainMenu;

	public:
		static SlaSol::mainWindow^ mainWindow;
		Display();

		static void addControl(System::Windows::Forms::Control^);

		void showMainMenu();
		void hideMainMenu();
		void showLevelMenu();
		void hideLevelMenu();
		void showLevelSetMenu();
		void hideLevelSetMenu();
		void showGameField();
		void hideGameField();

		int getFieldSizeFromLevelMenuDomain();
		int getCountOfColorsFromLevelMenuDomain();

		static void setVisibleVector(cliext::vector<System::Object^> vector, bool value);
	};
}