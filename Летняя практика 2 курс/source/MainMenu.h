#pragma once
#include <cliext\vector>

namespace SlaSolDisplay {
	public ref class MainMenu {
		/****************Buttons************************/
		System::Windows::Forms::Button^  campaignButton;
		System::Windows::Forms::Button^  settedGameButton;
		System::Windows::Forms::Button^  randomGameButton;
		System::Windows::Forms::Button^  quitButton;

		cliext::vector<System::Object^> mainMenuVector;
	public:
		MainMenu();

		/****************Buttons************************/
		void initCampaignButton();
		void initChooseGameButton();
		void initRandomGameButton();
		void initQuitButton();

		void show();
		void hide();
	};
}