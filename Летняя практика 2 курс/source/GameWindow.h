#pragma once
#include <cliext/vector> 

namespace SlaSolDisplay {
	public ref class GameWindow {
		/****************Labels**************************/
		System::Windows::Forms::Label^  stepsLabel;
		System::Windows::Forms::Label^  levelLabel;
		System::Windows::Forms::Label^  clicksLeftLabel;
		System::Windows::Forms::Label^  scoreLabel;
		/****************Buttons************************/
		System::Windows::Forms::Button^  menuButton;
		/****************Table Layout*******************/
		cliext::vector<System::Object^> gameVector;
	protected:
		System::Windows::Forms::TableLayoutPanel^ gameField;
	public:
		GameWindow();

		/****************Labels*************************/
		void initStepsLabel();
		void initLevelLabel();
		void initClicksLeftLabel();
		void initScoreLabel();

		void setStepsLabel(int steps, bool visible);
		void setLevelLabel(int level, bool visible);
		void setClicksLeftLabel(int clicks, bool visible);
		void setScoreLabel(int scores, bool visible);
		/****************Buttons************************/
		void initMenuButton();
		/****************Table Layout*******************/
		void initGameField();
		void updateGameField(int row, int col);

		void showGameField();
		void hideGameField();

		void writeLabel(System::Windows::Forms::Label^, int);
		int changeColorOnRowColumn(System::Windows::Forms::Control^ pictureBox);
		void fillGameField(int countOfColors);
		bool isOneColor();
	};
}
