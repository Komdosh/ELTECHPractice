#pragma once
#include <cliext\vector>

namespace SlaSolDisplay {
	public ref class LevelSetMenu {
		/****************Labels**************************/
		System::Windows::Forms::Label^  helpLabelColors;
		System::Windows::Forms::Label^  helpLabelFieldSize;
		/****************Buttons*************************/
	private:System::Windows::Forms::Button^  startSettedGameButton;

	protected:
		System::Windows::Forms::Button^  mainMenuButton;
		/****************Domains*************************/
		System::Windows::Forms::DomainUpDown^  domainColorsCount;
		System::Windows::Forms::DomainUpDown^  domainFieldSize;
		cliext::vector<System::Object^> levelSetMenuVector;
	public:
		LevelSetMenu();

		/****************Labels**************************/
		void initHelpLabelColors();
		void initHelpLabelFieldSize();
		/****************Domains*************************/
		void initDomainColorsCount();
		void initDomainFieldSize();
		/****************Buttons*************************/
		void initStartSettedGameButton();
		void initMainMenuButton();
	};

	public ref class LevelMenu : public LevelSetMenu {
		/****************Buttons*************************/
		System::Windows::Forms::Button^  lightLevelButton;
		System::Windows::Forms::Button^  middleLevelButton;
		System::Windows::Forms::Button^  hardLevelButton;
		System::Windows::Forms::Button^  setGameButton;

		cliext::vector<System::Object^> levelMenuVector;
	public:
		LevelMenu();

		/****************Buttons*************************/
		void initLightLevelButton();
		void initMiddleLevelButton();
		void initHardLevelButton();
		void initSetGameButton();

		int getFieldSizeFromDomain();
		int getCountOfColorsFromDomain();

		void show();
		void hide();
		void showLevelSetMenu();
		void hideLevelSetMenu();
	};
}